#pragma once


// CFinderDlg 대화 상자입니다.

class CFinderDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFinderDlg)

public:
	CFinderDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFinderDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FINDER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
