// EditorTransDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorTransDlg.h"
#include "afxdialogex.h"


// CEditorTransDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEditorTransDlg, CFlatDialogEx)

CEditorTransDlg::CEditorTransDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CEditorTransDlg::IDD, pParent)
{

}

CEditorTransDlg::~CEditorTransDlg()
{
}

void CEditorTransDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditorTransDlg, CFlatDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CEditorTransDlg �޽��� ó�����Դϴ�.


BOOL CEditorTransDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


HBRUSH CEditorTransDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFlatDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
		break;
	}

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}
