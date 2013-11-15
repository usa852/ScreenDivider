// FinderDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "FinderDlg.h"
#include "afxdialogex.h"


// CFinderDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFinderDlg, CDialogEx)

CFinderDlg::CFinderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFinderDlg::IDD, pParent)
{

}

CFinderDlg::~CFinderDlg()
{
}

void CFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFinderDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinderDlg 메시지 처리기입니다.
