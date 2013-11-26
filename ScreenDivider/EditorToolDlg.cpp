// EditorToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorToolDlg.h"
#include "afxdialogex.h"


// CEditorToolDlg dialog

IMPLEMENT_DYNAMIC(CEditorToolDlg, CFlatDialogEx)

CEditorToolDlg::CEditorToolDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CEditorToolDlg::IDD, pParent)
{

}

CEditorToolDlg::~CEditorToolDlg()
{
}

void CEditorToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditorToolDlg, CFlatDialogEx)
END_MESSAGE_MAP()


// CEditorToolDlg message handlers
