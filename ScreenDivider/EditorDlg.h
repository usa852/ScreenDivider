#pragma once
#include "EditorToolDlg.h"
#include "EditorWindowDlg.h"

// CEditorDlg ��ȭ �����Դϴ�.

class CEditorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorDlg)

public:
	CEditorDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditorDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EDITOR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
	void ShowVirtualWindows();
	void HideVirtualWindows();
	void DestroyVirtualWindows();

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
};