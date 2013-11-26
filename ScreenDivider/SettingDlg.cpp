// SettingDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingDlg.h"
#include "afxdialogex.h"
#include "SettingGeneralDlg.h"
#include "SettingStyleDlg.h"


// CSettingDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSettingDlg, CFlatDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CSettingDlg::IDD, pParent)
{
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SETTINGS, m_List);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CFlatDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SETTINGS, &CSettingDlg::OnLvnItemchangedListSettings)
	ON_BN_CLICKED(IDCLOSE, &CSettingDlg::OnBnClickedClose)
	ON_BN_CLICKED(IDC_DEFAULT, &CSettingDlg::OnBnClickedDefault)
	ON_BN_CLICKED(IDC_SAVE, &CSettingDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// CSettingDlg 메시지 처리기입니다.
BOOL CSettingDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_List.InsertItem(0, L"General");
	m_List.InsertItem(1, L"Style");

	m_pDlgGeneral = new CSettingGeneralDlg();
	m_pDlgGeneral->Create(IDD_SETTING_GENERAL_DIALOG, (CWnd *)this);
	m_pDlgGeneral->MoveWindow(135, 29, 279, 195);
	m_pDlgGeneral->ShowWindow(SW_SHOW);

	m_pDlgStyle = new CSettingStyleDlg();
	m_pDlgStyle->Create(IDD_SETTING_STYLE_DIALOG, (CWnd *)this);
	m_pDlgStyle->MoveWindow(135, 29, 279, 195);
	m_pDlgStyle->ShowWindow(SW_HIDE);

	CFile file(_T("Setting.dat"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	Serialize(ar);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CSettingDlg::OnLvnItemchangedListSettings(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notifiation handler code here
	UpdateData(TRUE);

	switch (m_List.GetHotItem())
	{
	case 0:
		m_pDlgGeneral->ShowWindow(SW_SHOW);
		m_pDlgStyle->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_pDlgGeneral->ShowWindow(SW_HIDE);
		m_pDlgStyle->ShowWindow(SW_SHOW);
		break;
	}

	UpdateData(FALSE);
	*pResult = 0;
}




void CSettingDlg::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		UpdateData(true);
		m_pDlgGeneral->Serialize(ar);
		m_pDlgStyle->Serialize(ar);
		UpdateData(false);
	}
	else
	{	// loading code
		m_pDlgGeneral->Serialize(ar);
		m_pDlgStyle->Serialize(ar);
	}
}

void CSettingDlg::OnBnClickedClose()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(IDCANCEL);
}


void CSettingDlg::OnBnClickedDefault()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	m_pDlgGeneral->OnInitDialog();
	m_pDlgStyle->OnInitDialog();
	UpdateData(false);
}


void CSettingDlg::OnBnClickedSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFile file(_T("Setting.dat"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	Serialize(ar);
}
