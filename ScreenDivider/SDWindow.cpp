#include "StdAfx.h"
#include "SDWindow.h"

CSDWindow::CSDWindow(void)
{
	SetRectEmpty();
}

CSDWindow::CSDWindow(int l, int t, int r, int b)
{
	SetRect(l, t, r, b);
}

CSDWindow::CSDWindow(POINT topLeft, POINT bottomRight)
{
	SetRect(topLeft, bottomRight);
}

CSDWindow::CSDWindow(POINT point, SIZE size)
{
	CRect rectTemp(point, size);

	CopyRect(rectTemp);
}

CSDWindow::~CSDWindow(void)
{

}

BOOL CSDWindow::IsCursorInTitlebar(const CPoint &cursor)
{
	CPoint ptTopLeft;
	ptTopLeft = TopLeft();

	// Check is in titlebar
	if ((ptTopLeft.x <= cursor.x && cursor.x <= ptTopLeft.x + Width()) &&
		(ptTopLeft.y <= cursor.y && cursor.y <= ptTopLeft.y + SIZE_TITLEBAR))
	{
		return TRUE;
	}

	return FALSE;
}