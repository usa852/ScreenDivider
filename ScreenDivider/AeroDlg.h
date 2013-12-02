#pragma once


// CAeroDlg dialog

class CAeroDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAeroDlg)

public:
	CAeroDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAeroDlg();

// Dialog Data
	enum { IDD = IDD_AERO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Member variables
private:
	CRect m_rectWindow;
	CPoint m_ptCursor;

// Member functions
public:
	void ShowWindowWithEffect(POINT ptCursor, CRect rectWindow, DWORD dwTime);

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
