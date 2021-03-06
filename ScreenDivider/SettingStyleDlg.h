#pragma once


// CSettingStyleDlg 대화 상자입니다.

class CSettingStyleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingStyleDlg)

public:
	CSettingStyleDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSettingStyleDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SETTING_STYLE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
