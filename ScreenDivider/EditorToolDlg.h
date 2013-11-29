#pragma once


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
};
