// EditorDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorDlg.h"
#include "afxdialogex.h"




// CEditorDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEditorDlg, CDialogEx)

	CEditorDlg::CEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditorDlg::IDD, pParent)
{

}

CEditorDlg::~CEditorDlg()
{
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
	

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CEditorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_isDown = false;
	form.AddSDWindow(m_start,m_end);
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CEditorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(m_isDown)
	{
		m_end = point;

		CDC *pDC;
		pDC = GetDC();
		pDC->Rectangle(m_start.x, m_start.y, m_end.x, m_end.y);
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

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
