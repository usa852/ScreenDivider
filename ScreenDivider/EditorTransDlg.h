#pragma once


// CEditorTransDlg ��ȭ �����Դϴ�.

class CEditorTransDlg : public CFlatDialogEx
{
	DECLARE_DYNAMIC(CEditorTransDlg)

public:
	CEditorTransDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditorTransDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EDITOR_TRANS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
