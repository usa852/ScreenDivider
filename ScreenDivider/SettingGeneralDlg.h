#pragma once


// CSettingGeneralDlg 대화 상자입니다.

class CSettingGeneralDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingGeneralDlg)

public:
	CSettingGeneralDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSettingGeneralDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SETTING_GENERAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// Member variables
public:
	unsigned int m_uiResizeForm;
	BOOL m_bStartAuto;

// Member functions
public:
	virtual BOOL OnInitDialog();
	virtual void Serialize(CArchive& ar);

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
