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

	DECLARE_MESSAGE_MAP()
private:
	unsigned int m_uiResizeForm;
public:
	BOOL m_bStartAuto;
};
