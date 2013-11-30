#include "../ScreenDivider/stdafx.h"
#include "../ScreenDividerHk/stdafx.h"
#include "SDForm.h"

IMPLEMENT_SERIAL(CSDForm, CObject, 1)

CSDForm::CSDForm(void)
{
	// Get desktop handle
	HWND hWnd = NULL;
	hWnd = GetDesktopWindow();

	// Get desktop size
	CSDWindow screen;
	GetWindowRect(hWnd, &screen);

	// Add screen rect to m_arrSDWindow's first item
	m_arrSDWindow.Add(screen);
}

CSDForm::CSDForm(CSDWindow screen)
{
	m_arrSDWindow.Add(screen);
}

CSDForm::~CSDForm(void)
{
	// Remove all sdwindows
	m_arrSDWindow.RemoveAll();
}

void CSDForm::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	m_arrSDWindow.Serialize(ar);
}

BOOL CSDForm::LoadFromFile(TCHAR strSDFormPath[MAX_PATH])
{
	BOOL isSuccess = TRUE;
	BOOL ret;

	// Before load data, remove all data
	m_arrSDWindow.RemoveAll();

	// Open file
	CFile fileSDForm;
	ret = fileSDForm.Open(strSDFormPath, CFile::modeRead);
	if (ret == 0)
	{
		isSuccess = FALSE;
		return isSuccess;
	}

	// Create archive object
	CArchive arSDForm(&fileSDForm, CArchive::load);

	// Serialization
	Serialize(arSDForm);

	// Close the archive and file
	arSDForm.Close();
	fileSDForm.Close();

	return isSuccess;
}

BOOL CSDForm::SaveToFile(TCHAR strSDFormPath[MAX_PATH])
{
	BOOL isSuccess = TRUE;
	BOOL ret;

	// Open file
	CFile fileSDForm;
	ret = fileSDForm.Open(strSDFormPath, CFile::modeCreate | CFile::modeWrite);
	if (ret == 0)
	{
		isSuccess = FALSE;
		return isSuccess;
	}

	// Create archive object
	CArchive arSDForm(&fileSDForm, CArchive::store);

	// Serialization
	Serialize(arSDForm);

	// Close the archive and file
	arSDForm.Close();
	fileSDForm.Close();

	return isSuccess;
}

INT_PTR CSDForm::AddSDWindow(CSDWindow &newSDWindow)
{
	return m_arrSDWindow.Add(newSDWindow);
}

INT_PTR CSDForm::AddSDWindow(int l, int t, int r, int b)
{
	CSDWindow newSDWindow(l, t, r, b);
	return m_arrSDWindow.Add(newSDWindow);
}

INT_PTR CSDForm::AddSDWindow(POINT topLeft, POINT bottomRight)
{
	CSDWindow newSDWindow(topLeft, bottomRight);
	return m_arrSDWindow.Add(newSDWindow);
}

INT_PTR CSDForm::AddSDWindow(POINT point, SIZE size)
{
	CSDWindow newSDWindow(point, size);
	return m_arrSDWindow.Add(newSDWindow);
}

VOID CSDForm::RemoveSDWindow(int idx)
{
	// Check valid index
	if (m_arrSDWindow.GetCount() <= idx)
	{
		return ;
	}

	// Remove sdwindow from pos
	m_arrSDWindow.RemoveAt(idx);
}

CSDWindow CSDForm::GetSDWindow(const CPoint& cursor)
{
	CSDWindow curSDWindow;

	// Loop all sdwindow
	int i;
	for (i=0 ; i<m_arrSDWindow.GetCount() ; i++)
	{
		CSDWindow curSDWindow;
		curSDWindow = m_arrSDWindow[i];
		if (curSDWindow.IsCursorInTitlebar(cursor))
		{
			return curSDWindow;
		}
	}

	return curSDWindow;
}

CSDWindow CSDForm::GetSDWindow(int idx)
{
	CSDWindow curSDWindow;

	// Check valid index
	if (m_arrSDWindow.GetCount() <= idx)
	{
		return curSDWindow;
	}

	// Set current position to head
	curSDWindow = m_arrSDWindow[idx];

	return curSDWindow;
}