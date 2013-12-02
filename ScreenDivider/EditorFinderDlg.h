#pragma once

// CFinderDlg 대화 상자입니다.

class CEditorFinderDlg : public CFlatDialogEx
{
	DECLARE_DYNAMIC(CEditorFinderDlg)

public:
	CEditorFinderDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEditorFinderDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EDITOR_FINDER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// Child controls
	CBitmapButton m_btnFinder;

// Member variables
	int m_Y;
	int m_X;
	int m_WIDTH;
	int m_HEIGHT;

// Message handlres
public:
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
};
