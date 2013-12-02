// SettingStyleDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingStyleDlg.h"
#include "afxdialogex.h"


// CSettingStyleDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSettingStyleDlg, CDialogEx)

CSettingStyleDlg::CSettingStyleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingStyleDlg::IDD, pParent)
{

	m_uiStyle = 0;
	m_uiColor = 0;
}

CSettingStyleDlg::~CSettingStyleDlg()
{
}

void CSettingStyleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_AERO_STYLE, (int&)m_uiStyle);
	DDX_Radio(pDX, IDC_STYLE_RED, (int&)m_uiColor);
}


BEGIN_MESSAGE_MAP(CSettingStyleDlg, CDialogEx)
	ON_BN_CLICKED(IDC_AERO_STYLE, &CSettingStyleDlg::OnBnClickedAeroStyle)
	ON_BN_CLICKED(IDC_FLAT_STYLE, &CSettingStyleDlg::OnBnClickedFlatStyle)
	ON_BN_CLICKED(IDC_STYLE_RED, &CSettingStyleDlg::OnBnClickedStyleRed)
	ON_BN_CLICKED(IDC_STYLE_GREEN, &CSettingStyleDlg::OnBnClickedStyleGreen)
	ON_BN_CLICKED(IDC_STYLE_BLUE, &CSettingStyleDlg::OnBnClickedStyleBlue)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSettingStyleDlg �޽��� ó�����Դϴ�.


void CSettingStyleDlg::OnBnClickedAeroStyle()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSettingStyleDlg::OnBnClickedFlatStyle()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSettingStyleDlg::OnBnClickedStyleRed()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSettingStyleDlg::OnBnClickedStyleGreen()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSettingStyleDlg::OnBnClickedStyleBlue()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


BOOL CSettingStyleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(true);
	// TODO:  Add extra initialization here
	// For flat design, set background to white
	SetBackgroundColor(RGB(255, 255, 255));
	m_uiStyle = 0;
	m_uiColor = 0;

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSettingStyleDlg::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		UpdateData(true);
		ar << m_uiStyle << m_uiColor;
		UpdateData(false);
	}
	else
	{	// loading code
		UpdateData(true);
		ar >> m_uiStyle >> m_uiColor;
		UpdateData(false);
	}
}


void CSettingStyleDlg::OnLButtonDown(UINT nFlags, CPoint point)
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
