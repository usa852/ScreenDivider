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

	m_uiResizeForm = 0;
}

CSettingGeneralDlg::~CSettingGeneralDlg()
{
}

void CSettingGeneralDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_ABSOLUTE_RESIZE, (int&)m_uiResizeForm);
	DDX_Check(pDX, IDC_START_AUTO, m_bStartAuto);
}


BEGIN_MESSAGE_MAP(CSettingGeneralDlg, CDialogEx)
END_MESSAGE_MAP()


// CSettingGeneralDlg 메시지 처리기입니다.
