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
END_MESSAGE_MAP()


// CSettingStyleDlg 메시지 처리기입니다.


void CSettingStyleDlg::OnBnClickedAeroStyle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSettingStyleDlg::OnBnClickedFlatStyle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSettingStyleDlg::OnBnClickedStyleRed()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSettingStyleDlg::OnBnClickedStyleGreen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSettingStyleDlg::OnBnClickedStyleBlue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
