
// ScreenDividerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "ScreenDividerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
	ON_BN_CLICKED(IDC_BUTTON1, &CScreenDividerDlg::OnBnClickedButton1)
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

// Refresh dll's data
typedef BOOL (*PFN_REFRESHSDFORM)(TCHAR strSDFormPath[MAX_PATH]);
BOOL RefreshSDForm(TCHAR strSDFormPath[MAX_PATH])
{
	BOOL isSuccess = TRUE;

	// Load library to get address of procedure('RefreshSDForm()')
	HMODULE hModule;
#ifdef _X64
	hModule = LoadLibrary(L"ScreenDividerHk64.dll");
#else
	hModule = LoadLibrary(L"ScreenDividerHk32.dll");
#endif
	if (hModule == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Get address of 'RefreshSDForm()'
	PFN_REFRESHSDFORM RefreshSDForm = NULL;
	RefreshSDForm = (PFN_REFRESHSDFORM)GetProcAddress(hModule, "RefreshSDForm");
	if (RefreshSDForm == NULL)
	{
		isSuccess = FALSE;
		goto EXIT;
	}

	// Call RefreshSDForm() got top
	RefreshSDForm(strSDFormPath);

EXIT:
	if (hModule != NULL)
	{
		FreeLibrary(hModule);
	}

	return isSuccess;
}

void CScreenDividerDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	RefreshSDForm(L"D:\\sdForm.sdForm");
}
