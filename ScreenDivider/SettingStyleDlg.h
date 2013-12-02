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

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAeroStyle();
	afx_msg void OnBnClickedFlatStyle();
	afx_msg void OnBnClickedStyleRed();
	afx_msg void OnBnClickedStyleGreen();
	afx_msg void OnBnClickedStyleBlue();
//	BOOL m_nb;
private:
	unsigned int m_uiStyle;
	unsigned int m_uiColor;
public:
	virtual BOOL OnInitDialog();
	virtual void Serialize(CArchive& ar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
