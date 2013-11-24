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

	DECLARE_MESSAGE_MAP()
};
