#pragma once
#include "SettingGeneralDlg.h"
#include "SettingStyleDlg.h"

// CSettingDlg ��ȭ �����Դϴ�.

class CSettingDlg : public CFlatDialogEx
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSettingDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SETTING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// Child dialogs
private:
	CSettingStyleDlg *m_pDlgStyle;
	CSettingGeneralDlg *m_pDlgGeneral;

// Child controls
private:
	CListCtrl m_List;

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedListSettings(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void Serialize(CArchive& ar);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedDefault();
	afx_msg void OnBnClickedSave();
};
