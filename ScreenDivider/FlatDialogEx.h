#pragma once

class CFlatDialogEx :
	public CDialogEx
{
	DECLARE_DYNAMIC(CFlatDialogEx)

public:
	CFlatDialogEx(void);
	CFlatDialogEx(UINT nIDTemplate, CWnd* pParent);
	CFlatDialogEx(LPCTSTR lpszTemplateName, CWnd* pParentWnd);
	~CFlatDialogEx(void);

// Member variables
private:
	CBitmapButtonEx *m_pBtnMin;
	CBitmapButtonEx *m_pBtnMax;
	CBitmapButtonEx *m_pBtnExit;

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	BOOL OnInitDialog();
	BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
};