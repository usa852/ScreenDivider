#pragma once


// CSettingGeneralDlg ��ȭ �����Դϴ�.

class CSettingGeneralDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingGeneralDlg)

public:
	CSettingGeneralDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSettingGeneralDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SETTING_GENERAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
