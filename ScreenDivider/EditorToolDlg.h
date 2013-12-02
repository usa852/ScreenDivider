#pragma once
#include "EditorFinderDlg.h"
#include "EditorTransDlg.h"

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

// Child dialogs
	CEditorFinderDlg *m_pDlgEditorFinder;
	CEditorTransDlg *m_pDlgEditorTrans;

// Child controls
	CBitmapButtonEx m_btnNew;
	CBitmapButtonEx m_btnOpen;
	CBitmapButtonEx m_btnSave;
	CBitmapButtonEx m_btnSaveas;
	CBitmapButtonEx m_btnFinder;
	CBitmapButtonEx m_btnTrans;
	CBitmapButtonEx m_btnEnd;

// Member variables
private:
	CSDForm *m_pSDForm;
	CString m_sSDFormPath;

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMove(int x, int y);
	afx_msg void OnBnClickedButtonNew();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonSaveas();
	afx_msg void OnBnClickedButtonEnd();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonFinder();
	afx_msg void OnBnClickedButtonTrans();
};
