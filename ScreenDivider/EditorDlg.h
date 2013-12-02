#pragma once
#include "EditorToolDlg.h"
#include "EditorWindowDlg.h"

// CEditorDlg 대화 상자입니다.

class CEditorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorDlg)

public:
	CEditorDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEditorDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EDITOR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// Child dialogs
private:
	CEditorToolDlg *m_pDlgEditorTool;
	CArray<CEditorWindowDlg *> m_arrPVirtualWindow;

// Member variables
private:
	CPoint m_start,m_end;
	bool m_isDown;

// Member functions
public:
	CArray<CEditorWindowDlg *> *GetVirtualWindows(void);
	void CreateVirtualWindows(CSDForm *pSDForm);
	void DestroyVirtualWindows();

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
};