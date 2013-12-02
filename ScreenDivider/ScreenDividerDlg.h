
// ScreenDividerDlg.h : header file
//

#pragma once
#include "EditorDlg.h"
#include "SettingDlg.h"
#include "AeroDlg.h"

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

// Child dialogs
private:
	CEditorDlg m_dlgEditor;
	CSettingDlg m_dlgSetting;
	CArray<CAeroDlg *> m_arrAeroDlg;

// Member variables
private:
	CString m_strSDFormPath;
	CSDForm m_sdForm;
	BOOL m_isHooked;

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();	
	afx_msg LRESULT OnTrayNotification(WPARAM wParam, LPARAM lParam);
	virtual BOOL DestroyWindow();
	afx_msg void OnTraymenuQuit();
	afx_msg void OnTraymenuEditor();
	afx_msg void OnTraymenuSettings();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnTraymenuOpen();
	afx_msg LRESULT OnSDCreateWindow(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSDDestroyWindow(WPARAM wParam, LPARAM lParam);
};
