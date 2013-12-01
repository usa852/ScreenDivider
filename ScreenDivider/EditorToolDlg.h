#pragma once
#include "afxwin.h"


// CEditorToolDlg dialog

class CEditorToolDlg : public CFlatDialogEx
{
	DECLARE_DYNAMIC(CEditorToolDlg)

public:
	CEditorToolDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CEditorToolDlg();

// Dialog Data
	enum { IDD = IDD_EDITOR_TOOL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

private:
	CSDForm *m_pSDForm;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMove(int x, int y);
	afx_msg void OnBnClickedButtonNew();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonSaveas();
	afx_msg void OnBnClickedButtonEnd();
	CBitmapButtonEx m_btnNew;
	CBitmapButtonEx m_btnOpen;
	CBitmapButtonEx m_btnSave;
	CBitmapButtonEx m_btnSaveas;
	CBitmapButtonEx m_btnFinder;
	CBitmapButtonEx m_btnTrans;
	CBitmapButtonEx m_btnEnd;
	virtual BOOL OnInitDialog();

private:
	CString m_sSDFormPath;
};
