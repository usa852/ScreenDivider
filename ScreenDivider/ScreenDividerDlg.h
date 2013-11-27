
// ScreenDividerDlg.h : header file
//

#pragma once


// CScreenDividerDlg dialog
class CScreenDividerDlg : public CDialogEx
{
// Construction
public:
	CScreenDividerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SCREENDIVIDER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	NOTIFYICONDATA m_nid;

protected:
	// Generated message map functions
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();	
	afx_msg LRESULT OnTrayNotification(WPARAM wParam, LPARAM lParam);
public:
	virtual BOOL DestroyWindow();
	afx_msg void OnTraymenuQuit();
	afx_msg void OnTraymenuEditor();
	afx_msg void OnTraymenuSettings();
};
