#pragma once

// CFinderDlg ��ȭ �����Դϴ�.

class CEditorFinderDlg : public CFlatDialogEx
{
	DECLARE_DYNAMIC(CEditorFinderDlg)

public:
	CEditorFinderDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditorFinderDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EDITOR_FINDER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// Child controls
	CBitmapButton m_btnFinder;

// Member variables
	int m_Y;
	int m_X;
	int m_WIDTH;
	int m_HEIGHT;
	BOOL m_isMouseDown;

// Message handlres
public:
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
};
