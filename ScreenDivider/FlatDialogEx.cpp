#include "stdafx.h"
#include "ScreenDivider.h"
#include "FlatDialogEx.h"

IMPLEMENT_DYNAMIC(CFlatDialogEx, CDialogEx)

#define BORDER 1

#define IDC_BUTTON_MIN	(21000 + 0)
#define IDC_BUTTON_MAX	(21000 + 1)
#define IDC_BUTTON_EXIT	(21000 + 2)

CFlatDialogEx::CFlatDialogEx(UINT nIDTemplate, CWnd* pParent=NULL)
	: CDialogEx(nIDTemplate, pParent)
{
	SetBackgroundColor(RGB(255, 255, 255));

	m_pBtnMin = NULL;
	m_pBtnMax = NULL;
	m_pBtnExit = NULL;
}

CFlatDialogEx::CFlatDialogEx(LPCTSTR lpszTemplateName, CWnd* pParentWnd=NULL)
	: CDialogEx(lpszTemplateName, pParentWnd)
{
	SetBackgroundColor(RGB(255, 255, 255));

	m_pBtnMin = NULL;
	m_pBtnMax = NULL;
	m_pBtnExit = NULL;
}

CFlatDialogEx::CFlatDialogEx(void)
	: CDialogEx()
{
	SetBackgroundColor(RGB(255, 255, 255));

	m_pBtnMin = NULL;
	m_pBtnMax = NULL;
	m_pBtnExit = NULL;
}

BOOL CFlatDialogEx::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/* Create system buttons */
	// Get dialog's rect to repose the buttons
	CRect rectDialog;
	GetWindowRect(rectDialog);

	DWORD dwStyle = 0;

	/* Minimize button */
	m_pBtnMin = new CBitmapButtonEx();
	m_pBtnMin->Create
	(
		L"MIN",
		WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		CRect(0, 0, 0, 0),
		this,
		IDC_BUTTON_MIN
	);
	m_pBtnMin->LoadBitmaps
	(
		IDB_BITMAP_MIN,
		IDB_BITMAP_MIN_HOVER,
		IDB_BITMAP_MIN_SEL,
		0U,
		IDB_BITMAP_MIN_DISABLED
	);
	m_pBtnMin->SizeToContent();
	// Check this dialog has minimize system button
	dwStyle = m_pBtnMin->GetStyle();
	if (!(dwStyle & WS_MINIMIZEBOX))
	{
		m_pBtnMin->EnableWindow(FALSE);
	}

	/* Maxmize button */
	m_pBtnMax = new CBitmapButtonEx();
	m_pBtnMax->Create
	(
		L"MAX",
		WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		CRect(0, 0, 0, 0),
		this,
		IDC_BUTTON_MAX
	);
	m_pBtnMax->LoadBitmaps
	(
		IDB_BITMAP_MAX,
		IDB_BITMAP_MAX_HOVER,
		IDB_BITMAP_MAX_SEL,
		0U,
		IDB_BITMAP_MAX_DISABLED
	);
	m_pBtnMax->SizeToContent();
	// Check this dialog has maximize system button
	dwStyle = m_pBtnMax->GetStyle();
	if (!(dwStyle & WS_MAXIMIZEBOX))
	{
		m_pBtnMax->EnableWindow(FALSE);
	}

	/* Exit button */
	m_pBtnExit = new CBitmapButtonEx();
	m_pBtnExit->Create
	(
		L"EXIT",
		WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		CRect(0, 0, 0, 0),
		this,
		IDC_BUTTON_EXIT
	);
	m_pBtnExit->LoadBitmaps
	(
		IDB_BITMAP_EXIT,
		IDB_BITMAP_EXIT_HOVER,
		IDB_BITMAP_EXIT_SEL,
		0U,
		IDB_BITMAP_EXIT_DISABLED
	);
	m_pBtnExit->SizeToContent();
	// Exception exit button
	/*
	dwStyle = m_pBtnExit->GetStyle();
	if (!(dwStyle & WS_SYSMENU))
	{
		m_pBtnExit->EnableWindow(FALSE);
	}
	*/

	// Repose system buttons
	SendMessage(WM_SIZE);

	return FALSE;
}

BOOL CFlatDialogEx::OnCommand(WPARAM wParam, LPARAM lParam)
{
	CDialogEx::OnCommand(wParam, lParam);

	switch (LOWORD(wParam))
	{
	case IDC_BUTTON_MIN:
		ShowWindow(SW_MINIMIZE);

		return TRUE;
		break;
	case IDC_BUTTON_MAX:
		ShowWindow(SW_MAXIMIZE);

		return TRUE;
		break;
	case IDC_BUTTON_EXIT:
		EndDialog(IDCANCEL);

		return TRUE;
		break;
	}

	return FALSE;
}

BEGIN_MESSAGE_MAP(CFlatDialogEx, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_NCCALCSIZE()
END_MESSAGE_MAP()

void CFlatDialogEx::OnPaint()
{
	CDialogEx::OnPaint();

	/* Draw border */
	// Get device context
	CDC *pDC = NULL;
	pDC = GetDC();

	// Get window rect and repose
	CRect rect;
	GetWindowRect(rect);
	rect.MoveToXY(0, 0);

	// Fill with transparent
	CBrush *pOldBrush = NULL;
	pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);

	// Set border color
	CPen *pOldPen = NULL;
	CPen newPen;
	newPen.CreatePen(0, BORDER, RGB(156, 154, 156));	// Gray
	pOldPen = (CPen *)pDC->SelectObject(newPen);

	// Draw border
	pDC->Rectangle(rect);

	// Redraw system buttons
	m_pBtnMin->Invalidate();
	m_pBtnMax->Invalidate();
	m_pBtnExit->Invalidate();

	// Reset brush and pen
	//pDC->SelectObject(pOldBrush);
	//pDC->SelectObject(pOldPen);
}

void CFlatDialogEx::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	/* Repose the system buttons */
	// Get dialog's rect to repose the buttons
	CRect rectDialog;
	GetWindowRect(rectDialog);

	// Get button's rect to repose the button
	if (m_pBtnMin != NULL)
	{
		CRect rectBtnMin;
		m_pBtnMin->GetWindowRect(rectBtnMin);

		// Repose the button
		m_pBtnMin->MoveWindow
					(
						rectDialog.Width() - (rectBtnMin.Width() * 3) - BORDER,
						BORDER,
						rectBtnMin.Width(),
						rectBtnMin.Height()
					);
	}

	// Get button's rect to repose the button
	if (m_pBtnMax != NULL)
	{
		CRect rectBtnMax;
		m_pBtnMax->GetWindowRect(rectBtnMax);

		// Repose the button
		m_pBtnMax->MoveWindow
					(
						rectDialog.Width() - (rectBtnMax.Width() * 2) - BORDER,
						BORDER,
						rectBtnMax.Width(),
						rectBtnMax.Height()
					);
	}

	if (m_pBtnExit != NULL)
	{
		// Get button's rect to repose the button
		CRect rectBtnExit;
		m_pBtnExit->GetWindowRect(rectBtnExit);

		// Repose the button
		m_pBtnExit->MoveWindow
					(
						rectDialog.Width() - (rectBtnExit.Width() * 1) - BORDER,
						BORDER,
						rectBtnExit.Width(),
						rectBtnExit.Height()
					);
	}
}

void CFlatDialogEx::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	CDialogEx::OnNcCalcSize(bCalcValidRects, lpncsp);

	lpncsp->rgrc[0].left -= GetSystemMetrics(SM_CXFIXEDFRAME);
	lpncsp->rgrc[0].top -= GetSystemMetrics(SM_CYFIXEDFRAME) + GetSystemMetrics(SM_CYCAPTION);
	lpncsp->rgrc[0].right += GetSystemMetrics(SM_CXFIXEDFRAME);
	lpncsp->rgrc[0].bottom += GetSystemMetrics(SM_CYFIXEDFRAME);

	MoveWindow
	(
		lpncsp->rgrc[0].left, lpncsp->rgrc[0].top,
		lpncsp->rgrc[0].right - lpncsp->rgrc[0].left - 
			(GetSystemMetrics(SM_CXFIXEDFRAME) * 2),
		lpncsp->rgrc[0].bottom - lpncsp->rgrc[0].top -
			(GetSystemMetrics(SM_CYFIXEDFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION))
	);
}

void CFlatDialogEx::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDown(nFlags, point);

	SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
}

CFlatDialogEx::~CFlatDialogEx(void)
{
}