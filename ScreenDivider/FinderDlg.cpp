// FinderDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "FinderDlg.h"
#include "afxdialogex.h"


// CFinderDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFinderDlg, CFlatDialogEx)

CFinderDlg::CFinderDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CFinderDlg::IDD, pParent)
{
	m_Y = 0;
	m_X = 0;
	m_WIDTH = 0;
	m_HEIGHT = 0;
}

CFinderDlg::~CFinderDlg()
{
}

void CFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_FINDER, m_btnFinder);
	DDX_Text(pDX, IDC_STATIC_Y, m_Y);
	DDX_Text(pDX, IDC_STATIC_X, m_X);
	DDX_Text(pDX, IDC_STATIC_WIDTH, m_WIDTH);
	DDX_Text(pDX, IDC_STATIC_HEIGHT, m_HEIGHT);
}


BEGIN_MESSAGE_MAP(CFinderDlg, CFlatDialogEx)
END_MESSAGE_MAP()


// CFinderDlg 메시지 처리기입니다.
BOOL CFinderDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CButton *pButton;
	pButton = (CButton *)GetDlgItem(IDC_BUTTON_FINDER);
		
	CRect rectButton;
	pButton->GetWindowRect(rectButton);

	if (rectButton.PtInRect(pMsg->pt))
	{
		switch (pMsg->message)
		{
		case WM_LBUTTONDOWN:
			SetCursor(LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR_FINDER)));
			SetCapture();
			break;
		case WM_MOUSEMOVE:
			break;
		case WM_LBUTTONUP:
			break;
		}
	}

	return CFlatDialogEx::PreTranslateMessage(pMsg);
}

BOOL CFinderDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_btnFinder.LoadBitmaps(IDB_BITMAP_FINDER, IDB_BITMAP_FINDER, IDB_BITMAP_FINDER, IDB_BITMAP_FINDER);
	m_btnFinder.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}