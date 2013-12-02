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

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

public:
	void ShowWindowWithEffect(POINT ptCursor, CRect rectWindow, DWORD dwTime);

	// For effect timer
private:
	CRect m_rectWindow;
	CPoint m_ptCursor;
};
