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

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	HWND hDlg;
};
