// SettingGeneralDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingGeneralDlg.h"
#include "afxdialogex.h"


// CSettingGeneralDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSettingGeneralDlg, CDialogEx)

CSettingGeneralDlg::CSettingGeneralDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingGeneralDlg::IDD, pParent)
{

}

CSettingGeneralDlg::~CSettingGeneralDlg()
{
}

void CSettingGeneralDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingGeneralDlg, CDialogEx)
END_MESSAGE_MAP()


// CSettingGeneralDlg 메시지 처리기입니다.


BOOL CSettingGeneralDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	// Fill background with white
	SetBackgroundColor(RGB(255, 255, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
