#pragma once


// CEditorWindowDlg ��ȭ �����Դϴ�.

class CEditorWindowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorWindowDlg)

public:
	CEditorWindowDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditorWindowDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EDITOR_WINDOW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	HWND hDlg;
};
