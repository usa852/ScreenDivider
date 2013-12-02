// FinderDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorFinderDlg.h"
#include "afxdialogex.h"
#include "EditorDlg.h"


// CFinderDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEditorFinderDlg, CFlatDialogEx)

CEditorFinderDlg::CEditorFinderDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CEditorFinderDlg::IDD, pParent)
{
	m_Y = 0;
	m_X = 0;
	m_WIDTH = 0;
	m_HEIGHT = 0;
	m_isMouseDown = FALSE;
}

CEditorFinderDlg::~CEditorFinderDlg()
{
}

void CEditorFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_FINDER, m_btnFinder);
	DDX_Text(pDX, IDC_STATIC_Y, m_Y);
	DDX_Text(pDX, IDC_STATIC_X, m_X);
	DDX_Text(pDX, IDC_STATIC_WIDTH, m_WIDTH);
	DDX_Text(pDX, IDC_STATIC_HEIGHT, m_HEIGHT);
}


BEGIN_MESSAGE_MAP(CEditorFinderDlg, CFlatDialogEx)
END_MESSAGE_MAP()


// CFinderDlg 메시지 처리기입니다.
BOOL CEditorFinderDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CRect rectButton;
	m_btnFinder.GetWindowRect(rectButton);

	if (rectButton.PtInRect(pMsg->pt))
	{
		switch (pMsg->message)
		{
		case WM_LBUTTONDOWN:
			{
			// Hide dialogs that unneed to use finder
			CEditorDlg *pDlgEditor;
			pDlgEditor = (CEditorDlg *)(GetParent()->GetParent());
			pDlgEditor->HideVirtualWindows();
			pDlgEditor->ShowWindow(SW_HIDE);

			// Change cursor and sustain receving message
			SetCursor(LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR_FINDER)));
			SetCapture();

			m_isMouseDown = TRUE;
			}
			break;
		}
	}
	else
	{
		switch (pMsg->message)
		{
		case WM_MOUSEMOVE:
			if (m_isMouseDown)
			{
				CPoint ptCursor;
				GetCursorPos(&ptCursor);

				CWnd *pWndFinded;
				pWndFinded = WindowFromPoint(ptCursor);

				CRect rectWindow;
				pWndFinded->GetWindowRect(rectWindow);

				UpdateData(TRUE);
				m_X = rectWindow.left;
				m_Y = rectWindow.top;
				m_WIDTH = rectWindow.Width();
				m_HEIGHT = rectWindow.Height();
				UpdateData(FALSE);
			}
			break;
		case WM_LBUTTONUP:
			{
				if (m_isMouseDown)
				{
				// Show dialogs that unneed to use finder
				CEditorDlg *pDlgEditor;
				pDlgEditor = (CEditorDlg *)(GetParent()->GetParent());
				pDlgEditor->ShowVirtualWindows();
				pDlgEditor->ShowWindow(SW_SHOW);

				// Put receiving message
				ReleaseCapture();

				m_isMouseDown = FALSE;
				}
			}
			break;
		}
	}

	return CFlatDialogEx::PreTranslateMessage(pMsg);
}

BOOL CEditorFinderDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_btnFinder.LoadBitmaps
		(
			IDB_BITMAP_FINDER_ICON,
			IDB_BITMAP_FINDER_ICON_SEL,
			IDB_BITMAP_FINDER_ICON,
			IDB_BITMAP_FINDER_ICON_DISABLED
		);
	m_btnFinder.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
