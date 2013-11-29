// EditorWindowDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorWindowDlg.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// CEditorWindowDlg 메시지 처리기입니다.


void CEditorWindowDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonDown(nFlags, point);
	SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	//PostMessage(WM_NCLBUTTONDOWN, HTCAPTION,MAKEWPARAM(point.x,point.y));
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
