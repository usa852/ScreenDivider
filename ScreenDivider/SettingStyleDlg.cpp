// SettingStyleDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingStyleDlg.h"
#include "afxdialogex.h"


// CSettingStyleDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSettingStyleDlg, CDialogEx)

CSettingStyleDlg::CSettingStyleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingStyleDlg::IDD, pParent)
{

}

CSettingStyleDlg::~CSettingStyleDlg()
{
}

void CSettingStyleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingStyleDlg, CDialogEx)
END_MESSAGE_MAP()


// CSettingStyleDlg 메시지 처리기입니다.


BOOL CSettingStyleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	// Fill background with white
	SetBackgroundColor(RGB(255, 255, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
