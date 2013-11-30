// EditorWindowDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorWindowDlg.h"
#include "afxdialogex.h"
#include <dwmapi.h>

#pragma comment(lib, "Dwmapi.lib")

// CEditorWindowDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEditorWindowDlg, CDialogEx)

CEditorWindowDlg::CEditorWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditorWindowDlg::IDD, pParent)
{

}

CEditorWindowDlg::~CEditorWindowDlg()
{
}

void CEditorWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditorWindowDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
//	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CEditorWindowDlg 메시지 처리기입니다.


void CEditorWindowDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonDown(nFlags, point);
	SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	//PostMessage(WM_NCLBUTTONDOWN, HTCAPTION,MAKEWPARAM(point.x,point.y));
}

BOOL CEditorWindowDlg::OnInitDialog()
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
	//SetTransparentWindow(hDlg, 128);

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

void CEditorWindowDlg::OnPaint()
{
	// device context for painting
	CPaintDC dc(this);

	// Chroma-key of SetTransparentWindow() function is WHITE, 
	// so the background color should be WHITE.
	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(rect, RGB(0,0,0));
}


//void CEditorWindowDlg::OnSize(UINT nType, int cx, int cy)
//{
//	CDialogEx::OnSize(nType, cx, cy);
//	
//	
//	if(hDlg = GetSafeHwnd())
//		{
//			hDlg.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOZORDER);
//		}
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//}
