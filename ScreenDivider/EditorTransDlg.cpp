// EditorTransDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorTransDlg.h"
#include "afxdialogex.h"


// CEditorTransDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEditorTransDlg, CFlatDialogEx)

CEditorTransDlg::CEditorTransDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CEditorTransDlg::IDD, pParent)
{

}

CEditorTransDlg::~CEditorTransDlg()
{
}

void CEditorTransDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditorTransDlg, CFlatDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CEditorTransDlg 메시지 처리기입니다.


BOOL CEditorTransDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


HBRUSH CEditorTransDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFlatDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
		break;
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
