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

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMove(int x, int y);
	afx_msg void Button_New();
	afx_msg void Button_Open();
	afx_msg void Button_Save();
	afx_msg void Button_Save_As();
	afx_msg void Button_End();

private:
	CSDForm *m_pSDForm;
public:
	afx_msg void OnBnClickedButton7();
};
