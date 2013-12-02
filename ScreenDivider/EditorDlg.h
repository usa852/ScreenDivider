#pragma once
#include "../Common/SDForm.h"
#include "../Common/common.h"
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

private:
	CEditorToolDlg *m_pDlgEditorTool;
	CPoint m_start,m_end;
	bool m_isDown;
	CArray<CEditorWindowDlg *> m_arrPVirtualWindow;

public:
	CArray<CEditorWindowDlg *> *GetVirtualWindows(void);
	void CreateVirtualWindows(CSDForm *pSDForm);
	void DestroyVirtualWindows();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
};