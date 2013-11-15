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
END_MESSAGE_MAP()


// CEditorDlg 메시지 처리기입니다.
