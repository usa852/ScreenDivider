// AeroDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "AeroDlg.h"
#include "afxdialogex.h"
#include <dwmapi.h>

#pragma comment(lib, "Dwmapi.lib")

#define ID_TIMER_SHOWEFFECT 10
#define MAX_TIMERCOUNT 10

// CAeroDlg dialog

IMPLEMENT_DYNAMIC(CAeroDlg, CDialogEx)

CAeroDlg::CAeroDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAeroDlg::IDD, pParent)
{

}

CAeroDlg::~CAeroDlg()
{
}

void CAeroDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAeroDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CAeroDlg message handlers


BOOL CAeroDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*
		Setting aero effect
	*/
	HRESULT hr;

	// Get aero dialog's window handle
	HWND hDlg;
	hDlg = GetSafeHwnd();

	// Temporarily enable SYSMENU and ENABLE for debugging
#ifdef _DEBUG
	LONG oldStyle;
	oldStyle = GetWindowLong(hDlg, GWL_STYLE);

	LONG newStyle;
	newStyle = oldStyle;
	newStyle |= WS_SYSMENU;		// Add
	newStyle &= ~WS_DISABLED;	// Subtract
	SetWindowLongPtr(hDlg, GWL_STYLE, newStyle);
#endif

	// Set transparent attribute to show more clearly
	SetTransparentWindow(hDlg, 128);

	// Extend client area of applying aero effect to maximize
	MARGINS margins;
	margins.cxLeftWidth		= ~0x0;
	margins.cxRightWidth	= ~0x0;
	margins.cyBottomHeight	= ~0x0;
	margins.cyTopHeight		= ~0x0;
	hr = DwmExtendFrameIntoClientArea(hDlg, &margins);
	if (!SUCCEEDED(hr))
	{
		// Error handling
	}
	
	// Set aero effect
	DWM_BLURBEHIND bb = {0, };
	bb.dwFlags = DWM_BB_ENABLE;
	bb.fEnable = true;
	hr = DwmEnableBlurBehindWindow(hDlg, &bb);
	if (!SUCCEEDED(hr))
	{
		// Error handling
	}

	return TRUE;
}

void CAeroDlg::ShowWindowWithEffect(POINT ptCursor, CRect rectWindow, DWORD dwTime)
{
	// Move initial position and show this
	MoveWindow(ptCursor.x, ptCursor.y, 0, 0);
	ShowWindow(SW_SHOW);

	// Set member variables for saving data
	m_ptCursor = ptCursor;
	m_rectWindow = rectWindow;

	// If original timer is activating, kill that
	KillTimer(ID_TIMER_SHOWEFFECT);

	// Start new timer
	SetTimer(ID_TIMER_SHOWEFFECT, dwTime / MAX_TIMERCOUNT, NULL);
}


void CAeroDlg::OnPaint()
{
	// device context for painting
	CPaintDC dc(this);

	// Chroma-key of SetTransparentWindow() function is WHITE, 
	// so the background color should be WHITE.
	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(rect, RGB(0,0,0));
}

void CAeroDlg::OnTimer(UINT_PTR nIDEvent)
{
	static DWORD cntEffectTimer = 0;

	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case ID_TIMER_SHOWEFFECT:
		// If effect is complete,
		// set static position and size and initialize
		if (MAX_TIMERCOUNT <= cntEffectTimer)
		{
			MoveWindow
			(
				m_rectWindow.left,
				m_rectWindow.top,
				m_rectWindow.Width(),
				m_rectWindow.Height()
			);

			cntEffectTimer = 0;
			KillTimer(ID_TIMER_SHOWEFFECT);
			break;
		}

		/*
			-----------------
			|       ^       |
			|       ^       |
			|<<<<<<<o>>>>>>>|
			|       ~       |
			|       ~       |
			-----------------

			o : cursor
			< : left
			> : right
			^ : up
			~ : down
		*/

		// Calculate offset size
		double leftOffset = 0.0f;
		double rightOffset = 0.0f;
		double upOffset = 0.0f;
		double downOffset = 0.0f;
		leftOffset = ((double)(m_ptCursor.x - m_rectWindow.left)) / MAX_TIMERCOUNT;
		rightOffset = (double)(m_rectWindow.right - m_ptCursor.x) / MAX_TIMERCOUNT;
		upOffset = ((double)(m_ptCursor.y - m_rectWindow.top)) / MAX_TIMERCOUNT;
		downOffset = ((double)(m_rectWindow.bottom - m_ptCursor.y)) / MAX_TIMERCOUNT;

		// Move and size slowly
		MoveWindow
			(
				(int)(m_ptCursor.x - (leftOffset * cntEffectTimer)),
				(int)(m_ptCursor.y - (upOffset * cntEffectTimer)),
				(int)((leftOffset + rightOffset) * cntEffectTimer),
				(int)((upOffset + downOffset) * cntEffectTimer)
			);

		// Add count to terminate moving and sizing
		cntEffectTimer++;
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}