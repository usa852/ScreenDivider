// EditorToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorToolDlg.h"
#include "afxdialogex.h"
#include "EditorDlg.h"

// CEditorToolDlg dialog

IMPLEMENT_DYNAMIC(CEditorToolDlg, CFlatDialogEx)

CEditorToolDlg::CEditorToolDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CEditorToolDlg::IDD, pParent)
{

}

CEditorToolDlg::~CEditorToolDlg()
{
}

void CEditorToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_btnNew);
	DDX_Control(pDX, IDC_BUTTON_OPEN, m_btnOpen);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_btnSave);
	DDX_Control(pDX, IDC_BUTTON_SAVEAS, m_btnSaveas);
	DDX_Control(pDX, IDC_BUTTON_FINDER, m_btnFinder);
	DDX_Control(pDX, IDC_BUTTON_TRANS, m_btnTrans);
	DDX_Control(pDX, IDC_BUTTON_END, m_btnEnd);
}

// CEditorToolDlg message handlersBEGIN_MESSAGE_MAP(CEditorToolDlg, CFlatDialogEx)
BEGIN_MESSAGE_MAP(CEditorToolDlg, CFlatDialogEx)
	ON_WM_MOVE()
	ON_BN_CLICKED(IDC_BUTTON_NEW, &CEditorToolDlg::OnBnClickedButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CEditorToolDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CEditorToolDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SAVEAS, &CEditorToolDlg::OnBnClickedButtonSaveas)
	ON_BN_CLICKED(IDC_BUTTON_END, &CEditorToolDlg::OnBnClickedButtonEnd)
END_MESSAGE_MAP()


void CEditorToolDlg::OnMove(int x, int y)
{
	CFlatDialogEx::OnMove(x, y);

	Invalidate();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CEditorToolDlg::OnBnClickedButtonNew()
{
	// TODO: Add your control notification handler code here
	int ret;
	ret = AfxMessageBox(L"Do you want to save changes?",MB_YESNOCANCEL);

	switch (ret)
	{
	case IDYES:OnBnClickedButtonSave();
		break;
	case IDNO:
		// Init sdForm
		break;
	case IDCANCEL:
		break;
	}
}

void CEditorToolDlg::OnBnClickedButtonOpen()
{
	// TODO: Add your control notification handler code here
	TCHAR strFilter[] = { TEXT("ScreenDivider form file (*.sdf)|*.sdf||") };
	CFileDialog dlg(TRUE, TEXT(".sdf"), NULL, 0, strFilter);

	if( dlg.DoModal() == IDOK )
	{
		CString strFileName;
		strFileName = dlg.GetPathName();

		if (m_pSDForm)
		{
			m_pSDForm->LoadFromFile((TCHAR*)(LPCTSTR)strFileName);
		}
		else
		{
			// Process error
		}
	}
}


void CEditorToolDlg::OnBnClickedButtonSave()
{
	// TODO: Add your control notification handler code here
	TCHAR strFilter[] = { TEXT("ScreenDivider form file (*.sdf)|*.sdf||") };
	CFileDialog dlg(FALSE, TEXT("leeju.sdf"), NULL, 0, strFilter);

	if( dlg.DoModal() == IDOK )
	{
		CString strFileName;
		strFileName = dlg.GetPathName();

		if (m_pSDForm)
		{
			m_pSDForm->LoadFromFile((TCHAR*)(LPCTSTR)strFileName);
		}
		else
		{
			// Process error
		}
	}
}


void CEditorToolDlg::OnBnClickedButtonSaveas()
{
	// TODO: Add your control notification handler code here
	TCHAR strFilter[] = { TEXT("ScreenDivider form file (*.sdf)|*.sdf||") };
	CFileDialog dlg(FALSE, TEXT(".sdf"), NULL, 0, strFilter);

	if( dlg.DoModal() == IDOK )
	{
		CString strFileName;
		strFileName = dlg.GetPathName();

		if (m_pSDForm)
		{
			m_pSDForm->LoadFromFile((TCHAR*)(LPCTSTR)strFileName);
		}
		else
		{
			// Process error
		}
	}
}


void CEditorToolDlg::OnBnClickedButtonEnd()
{
	// TODO: Add your control notification handler code here
	GetParent()->SendMessage(WM_CLOSE, 0, 0);
}


BOOL CEditorToolDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	/* Set bitmap to buttons */
	m_btnNew.LoadBitmaps
		(
			IDB_BITMAP_NEW,
			IDB_BITMAP_NEW_HOVER,
			IDB_BITMAP_NEW_SEL,
			0U,
			IDB_BITMAP_NEW_DISABLED
		);
	m_btnNew.SizeToContent();
	m_btnOpen.LoadBitmaps
		(
			IDB_BITMAP_OPEN,
			IDB_BITMAP_OPEN_HOVER,
			IDB_BITMAP_OPEN_SEL,
			0U,
			IDB_BITMAP_OPEN_DISABLED
		);
	m_btnOpen.SizeToContent();
	m_btnSave.LoadBitmaps
		(
			IDB_BITMAP_SAVE,
			IDB_BITMAP_SAVE_HOVER,
			IDB_BITMAP_SAVE_SEL,
			0U,
			IDB_BITMAP_SAVE_DISABLED
		);
	m_btnSave.SizeToContent();
	m_btnSaveas.LoadBitmaps
		(
			IDB_BITMAP_SAVEAS,
			IDB_BITMAP_SAVEAS_HOVER,
			IDB_BITMAP_SAVEAS_SEL,
			0U,
			IDB_BITMAP_SAVEAS_DISABLED
		);
	m_btnSaveas.SizeToContent();

	m_btnFinder.LoadBitmaps
		(
			IDB_BITMAP_FINDER,
			IDB_BITMAP_FINDER_HOVER,
			IDB_BITMAP_FINDER_SEL,
			0U,
			IDB_BITMAP_FINDER_DISABLED
		);
	m_btnFinder.SizeToContent();
	m_btnTrans.LoadBitmaps
		(
			IDB_BITMAP_TRANS,
			IDB_BITMAP_TRANS_HOVER,
			IDB_BITMAP_TRANS_SEL,
			0U,
			IDB_BITMAP_TRANS_DISABLED
		);
	m_btnTrans.SizeToContent();

	m_btnEnd.LoadBitmaps
		(
			IDB_BITMAP_END,
			IDB_BITMAP_END_HOVER,
			IDB_BITMAP_END_SEL,
			0U,
			IDB_BITMAP_END_DISABLED
		);
	m_btnEnd.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
