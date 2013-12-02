// EditorDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorDlg.h"
#include "afxdialogex.h"
#include <math.h>

// CEditorDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEditorDlg, CDialogEx)

	CEditorDlg::CEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditorDlg::IDD, pParent)
{

}

CEditorDlg::~CEditorDlg()
{
}

CArray<CEditorWindowDlg *> *CEditorDlg::GetVirtualWindows(void)
{
	return &m_arrPVirtualWindow;
}

void CEditorDlg::CreateVirtualWindows(CSDForm *pSDForm)
{
	
	DestroyVirtualWindows();

	int i = 1;
	while (TRUE)
	{
		CSDWindow curSDWindow;
		curSDWindow = pSDForm->GetSDWindow(i);

		if (curSDWindow.IsRectEmpty())
		{
			break;
		}
		
		// Create new virtual window
		CEditorWindowDlg *pDlgVirtualWindow;
		pDlgVirtualWindow = new CEditorWindowDlg();
		pDlgVirtualWindow->Create(IDD_EDITOR_WINDOW_DIALOG, (CWnd *)this);
		pDlgVirtualWindow->MoveWindow
			(
				curSDWindow.left,
				curSDWindow.top,
				curSDWindow.Width(),
				curSDWindow.Height()
			);
		pDlgVirtualWindow->ShowWindow(SW_SHOW);

		// Add to list
		m_arrPVirtualWindow.Add(pDlgVirtualWindow);

		i++;
	}
}

void CEditorDlg::DestroyVirtualWindows()
{
	// Remove existing virtual windows
	while (!m_arrPVirtualWindow.IsEmpty())
	{
		m_arrPVirtualWindow[0]->EndDialog(IDOK);
		m_arrPVirtualWindow.RemoveAt(0);
	}
}

void CEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditorDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CEditorDlg 메시지 처리기입니다.


void CEditorDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	m_start = point;
	m_isDown = true;
	
	CEditorWindowDlg *pDlgVirtualWindow;
	pDlgVirtualWindow = new CEditorWindowDlg();
	pDlgVirtualWindow->Create(IDD_EDITOR_WINDOW_DIALOG, (CWnd *)this);
	pDlgVirtualWindow->MoveWindow(point.x, point.y, 0, 0);
	pDlgVirtualWindow->ShowWindow(SW_SHOW);

	m_arrPVirtualWindow.Add(pDlgVirtualWindow);

	SetCapture();

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CEditorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_isDown = false;

	ReleaseCapture();

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CEditorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(m_isDown)
	{
		m_end = point;
		int x = min(m_start.x, m_end.x);
		int y = min(m_start.y, m_end.y);
		
		m_arrPVirtualWindow[m_arrPVirtualWindow.GetCount() - 1]->
			MoveWindow(x, y, abs(m_end.x-m_start.x), abs(m_end.y-m_start.y), TRUE);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

BOOL CEditorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_isDown = false;

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	// Get current dialog handle
	HWND hDlg = NULL;
	hDlg = GetSafeHwnd();

	// Set transparent
	SetTransparentWindow(hDlg, 128);
	
	// Get screen
	CWnd *pScreen;
	pScreen = GetDesktopWindow();

	CRect rectScreen;
	pScreen->GetWindowRect(rectScreen);

	// Resize to screen
	MoveWindow(rectScreen);

	// Show tool dialog
	m_pDlgEditorTool = new CEditorToolDlg();
	m_pDlgEditorTool->Create(IDD_EDITOR_TOOL_DIALOG, (CWnd *)this);
	m_pDlgEditorTool->ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}