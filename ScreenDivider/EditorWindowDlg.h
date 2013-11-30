#pragma once


// CEditorWindowDlg 대화 상자입니다.

class CEditorWindowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorWindowDlg)

public:
	CEditorWindowDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEditorWindowDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EDITOR_WINDOW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	HWND hDlg;
};
