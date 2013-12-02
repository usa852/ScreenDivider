// SettingGeneralDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingGeneralDlg.h"
#include "afxdialogex.h"


// CSettingGeneralDlg ��ȭ �����Դϴ�.

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
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSettingGeneralDlg �޽��� ó�����Դϴ�.


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


void CSettingGeneralDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// Get client rect to calc parent window's point
	CRect rectClient;
	GetClientRect(&rectClient);

	// Calc parent window's point
	CPoint ptParent(point);
	ptParent.x += rectClient.left;
	ptParent.y += rectClient.top;

	// Send to parent
	GetParent()->SendMessage(WM_LBUTTONDOWN, nFlags, (LPARAM)(&ptParent));

	CDialogEx::OnLButtonDown(nFlags, point);
}
