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
