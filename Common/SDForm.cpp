#include "../ScreenDivider/stdafx.h"
#include "../ScreenDividerHk/stdafx.h"
#include "SDForm.h"

CSDForm::CSDForm(void)
{
	BOOL ret;

	// Get desktop handle
	HWND hWnd;
	hWnd = GetDesktopWindow();

	// Get desktop size
	ret = GetWindowRect(hWnd, &m_screen);
}

CSDForm::CSDForm(CSDWindow screen)
{
	m_screen = screen;
}

CSDForm::~CSDForm(void)
{
	// Remove all sdwindows
	m_lstSDWindow.RemoveAll();
}

POSITION CSDForm::AddSDWindow(CSDWindow &newSDWindow)
{
	POSITION posAdded;
	posAdded = m_lstSDWindow.AddTail(newSDWindow);

	return posAdded;
}

POSITION CSDForm::AddSDWindow(int l, int t, int r, int b)
{
	CSDWindow newSDWindow(l, t, r, b);

	POSITION posAdded;
	posAdded = m_lstSDWindow.AddTail(newSDWindow);

	return posAdded;
}

POSITION CSDForm::AddSDWindow(POINT topLeft, POINT bottomRight)
{
	CSDWindow newSDWindow(topLeft, bottomRight);

	POSITION posAdded;
	posAdded = m_lstSDWindow.AddTail(newSDWindow);

	return posAdded;
}

POSITION CSDForm::AddSDWindow(POINT point, SIZE size)
{
	CSDWindow newSDWindow(point, size);

	POSITION posAdded;
	posAdded = m_lstSDWindow.AddTail(newSDWindow);

	return posAdded;
}

VOID CSDForm::RemoveSDWindow(POSITION pos)
{
	// Check valid pos
	ASSERT(m_lstSDWindow.GetAt(pos));

	// Remove sdwindow from pos
	m_lstSDWindow.RemoveAt(pos);
}

CSDWindow *CSDForm::GetSDWindow(const CPoint& cursor)
{
	// Set current position to head
	CSDWindow &curSDWindow = m_lstSDWindow.GetHead();

	// Loop all sdwindow
	while (curSDWindow != m_lstSDWindow.GetTail())
	{
		if (curSDWindow.IsCursorInTitlebar(cursor))
		{
			return &curSDWindow;
		}
	}

	return NULL;
}

CSDWindow *CSDForm::GetSDWindow(POSITION pos)
{
	// Check valid pos
	ASSERT(m_lstSDWindow.GetAt(pos));

	// Get sdwindow from pos
	CSDWindow &curSDWindow = m_lstSDWindow.GetAt(pos);

	return &curSDWindow;
}