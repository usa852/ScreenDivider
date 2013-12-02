// SettingDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingDlg.h"
#include "afxdialogex.h"


// CSettingDlg ��ȭ �����Դϴ�.

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


// CSettingDlg �޽��� ó�����Դϴ�.
BOOL CSettingDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
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
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(IDCANCEL);
}


void CSettingDlg::OnBnClickedDefault()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	m_pDlgGeneral->OnInitDialog();
	m_pDlgStyle->OnInitDialog();
	UpdateData(false);
}


void CSettingDlg::OnBnClickedSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pDlgGeneral->UpdateData(TRUE);
	
	// Open registry key
	HKEY hKey;
	LONG regOpen;
	regOpen = RegCreateKeyEx
			(
				HKEY_CURRENT_USER,
				L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
				0L,
				NULL,
				REG_OPTION_NON_VOLATILE,
				KEY_ALL_ACCESS,
				NULL,
				&hKey,
				NULL
			);

	// Add or delete key
	if (regOpen == ERROR_SUCCESS)
	{
		if (m_pDlgGeneral->m_bStartAuto)
		{
			if (regOpen == ERROR_SUCCESS)
			{
				// Get app path
				TCHAR szPath[MAX_PATH] = {0, };
				DWORD lenPath;
				lenPath = GetModuleFileName(AfxGetInstanceHandle(), szPath, MAX_PATH);

				// Set value
				LONG regSet;
				regSet = RegSetValueEx
					(
						hKey,
						L"ScreenDivider",
						0,
						REG_SZ,
						(LPBYTE)szPath,
						MAX_PATH	/* If terminated NULL, OS auto split data */
					);

				if (regSet != ERROR_SUCCESS)
				{
					AfxMessageBox
						(
							L"Can't register auto start program\n"
							L"Please retry later",
							MB_OK | MB_ICONSTOP
						);
				}
			}
		}
		else
		{
			LONG regDelete;
			regDelete = RegDeleteValue(hKey, L"ScreenDivider");
		}
	}
	else
	{
		AfxMessageBox
			(
				L"Can't register auto start program\n"
				L"Please retry later",
				MB_OK | MB_ICONSTOP
			);
	}

	// Close hKey
	RegCloseKey(hKey);

	m_pDlgGeneral->UpdateData(FALSE);

	CFile file(_T("Setting.dat"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	Serialize(ar);
}
