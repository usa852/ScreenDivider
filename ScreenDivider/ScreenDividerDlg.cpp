
// ScreenDividerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "ScreenDividerDlg.h"
#include "afxdialogex.h"
#include "EditorDlg.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define UID_TRAY 0
#define TM_NOTIFICATION (WM_APP + 1)

// CScreenDividerDlg dialog.




CScreenDividerDlg::CScreenDividerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenDividerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScreenDividerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CScreenDividerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(TM_NOTIFICATION, OnTrayNotification)
	ON_COMMAND(ID_TRAYMENU_QUIT, &CScreenDividerDlg::OnTraymenuQuit)
	ON_COMMAND(ID_TRAYMENU_EDITOR, &CScreenDividerDlg::OnTraymenuEditor)
	ON_COMMAND(ID_TRAYMENU_SETTINGS, &CScreenDividerDlg::OnTraymenuSettings)
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()


// CScreenDividerDlg message handlers

BOOL CScreenDividerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Create tray icon
	ZeroMemory(&m_nid, sizeof(m_nid));
	m_nid.cbSize = sizeof(NOTIFYICONDATA);
	m_nid.hWnd = GetSafeHwnd();
	m_nid.uID = UID_TRAY;
	m_nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	m_nid.uCallbackMessage = TM_NOTIFICATION;
	m_nid.hIcon = m_hIcon;
	lstrcpy(m_nid.szTip, L"ScreenDivider");
	Shell_NotifyIcon(NIM_ADD, &m_nid);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CScreenDividerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CScreenDividerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CScreenDividerDlg::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	switch (lParam)
	{
	case WM_RBUTTONDOWN:
		CPoint point;
		GetCursorPos(&point);

		CMenu menuTray;
		menuTray.LoadMenu(IDR_MENU_TRAY);

		CMenu *pFirstMenu;
		pFirstMenu = menuTray.GetSubMenu(0);
		pFirstMenu->TrackPopupMenu
		(
			TPM_LEFTALIGN | TPM_RIGHTBUTTON,
			point.x, point.y,
			AfxGetMainWnd()
		);
		break;
	}

	return TRUE;
}

BOOL CScreenDividerDlg::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	// Destroy tray icon
	Shell_NotifyIcon(NIM_DELETE, &m_nid);

	return CDialogEx::DestroyWindow();
}

void CScreenDividerDlg::OnTraymenuQuit()
{
	// TODO: Add your command handler code here
	EndDialog(IDCANCEL);
}


void CScreenDividerDlg::OnTraymenuEditor()
{
	// TODO: Add your command handler code here
	CEditorDlg *pDlgEditor;
	pDlgEditor = new CEditorDlg();
	pDlgEditor->Create(IDD_EDITOR_DIALOG, this);
	pDlgEditor->ShowWindow(SW_SHOW);
}

void CScreenDividerDlg::OnTraymenuSettings()
{
	// TODO: Add your command handler code here
	CSettingDlg *pDlgSetting;
	pDlgSetting = new CSettingDlg();
	pDlgSetting->Create(IDD_SETTING_DIALOG, this);
	pDlgSetting->ShowWindow(SW_SHOW);
}


void CScreenDividerDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanging(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// Hide this dialog
	// Because of this dialog is main dialog,
	// ShowWindow() function is not performed.
	lpwndpos->flags &= ~SWP_SHOWWINDOW;
}
