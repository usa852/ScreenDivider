#pragma once


// CSettingStyleDlg ��ȭ �����Դϴ�.

class CSettingStyleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingStyleDlg)

public:
	CSettingStyleDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSettingStyleDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SETTING_STYLE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// Member variables
private:
	unsigned int m_uiStyle;
	unsigned int m_uiColor;

// Member functions
public:
	virtual BOOL OnInitDialog();
	virtual void Serialize(CArchive& ar);

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedAeroStyle();
	afx_msg void OnBnClickedFlatStyle();
	afx_msg void OnBnClickedStyleRed();
	afx_msg void OnBnClickedStyleGreen();
	afx_msg void OnBnClickedStyleBlue();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
