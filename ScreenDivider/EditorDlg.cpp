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
	, m_isMouseDown(false)
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
	m_pointStart = point;
	m_isMouseDown = TRUE;

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CEditorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_isMouseDown = FALSE;

	CDialogEx::OnLButtonUp(nFlags, point);
}

void CEditorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_isMouseDown)
	{
		InvalidateRect(NULL,TRUE);
		UpdateWindow();
		CClientDC dc(this); // device context for painting
		dc.Rectangle(m_pointStart.x, m_pointStart.y
					, point.x, point.y);
	}

	CDialogEx::OnMouseMove(nFlags, point);
}