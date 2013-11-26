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


BOOL CSettingGeneralDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(true);
	// TODO:  Add extra initialization here
	// For flat design, set background to white
	SetBackgroundColor(RGB(255, 255, 255));
	m_uiResizeForm = 0;
	m_bStartAuto = 0;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSettingGeneralDlg::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		UpdateData(true);
		ar << m_uiResizeForm << m_bStartAuto;
		UpdateData(false);
	}
	else
	{	// loading code
		UpdateData(true);
		ar >> m_uiResizeForm >> m_bStartAuto;
		UpdateData(false);
	}
}
