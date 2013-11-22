// SettingDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingDlg.h"
#include "afxdialogex.h"
#include "SettingGeneralDlg.h"
#include "SettingStyleDlg.h"


// CSettingDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSettingDlg, CDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingDlg::IDD, pParent)
{
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SETTINGS, m_List);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SETTINGS, &CSettingDlg::OnLvnItemchangedListSettings)
END_MESSAGE_MAP()


// CSettingDlg 메시지 처리기입니다.
BOOL CSettingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_List.InsertItem(0, L"General");
	m_List.InsertItem(1, L"Style");

	m_pDlgGeneral = new CSettingGeneralDlg();
	m_pDlgGeneral->Create(IDD_SETTING_GENERAL_DIALOG, (CWnd *)this);
	m_pDlgGeneral->MoveWindow(135, 15, 369, 283);
	m_pDlgGeneral->ShowWindow(SW_SHOW);

	m_pDlgStyle = new CSettingStyleDlg();
	m_pDlgStyle->Create(IDD_SETTING_STYLE_DIALOG, (CWnd *)this);
	m_pDlgStyle->MoveWindow(135, 15, 369, 283);
	m_pDlgStyle->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CSettingDlg::OnLvnItemchangedListSettings(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_pDlgGeneral->ShowWindow(SW_HIDE);
	m_pDlgStyle->ShowWindow(SW_HIDE);

	switch (m_List.GetHotItem())
	{
	case 0:
		m_pDlgGeneral->ShowWindow(SW_SHOW);
		break;
	case 1:
		m_pDlgStyle->ShowWindow(SW_SHOW);
		break;
	}

	UpdateData(FALSE);
	*pResult = 0;
}
