#pragma once


// CEditorTransDlg ��ȭ �����Դϴ�.

class CEditorTransDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorTransDlg)

public:
	CEditorTransDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditorTransDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EDITOR_TRANS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
