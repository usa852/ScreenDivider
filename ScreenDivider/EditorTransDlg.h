#pragma once


// CEditorTransDlg 대화 상자입니다.

class CEditorTransDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorTransDlg)

public:
	CEditorTransDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEditorTransDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EDITOR_TRANS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// Message handlers
public:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
};
