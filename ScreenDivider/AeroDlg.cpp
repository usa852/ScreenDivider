// AeroDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "AeroDlg.h"
#include "afxdialogex.h"
#include <dwmapi.h>

#pragma comment(lib, "Dwmapi.lib")

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
