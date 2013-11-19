#pragma once
#include "SDWindow.h"

class CSDForm
{
public:
	CSDForm(void);
	CSDForm::CSDForm(CSDWindow screen);
	~CSDForm(void);

private:
	CSDWindow m_screen;
	CList<CSDWindow> m_lstSDWindow;

public:
	VOID RemoveSDWindow(POSITION pos);
	POSITION AddSDWindow(CSDWindow &newSDWindow);
	POSITION AddSDWindow(int l, int t, int r, int b);
	POSITION AddSDWindow(POINT topLeft, POINT bottomRight);
	POSITION AddSDWindow(POINT point, SIZE size);
	CSDWindow *GetSDWindow(const CPoint& cursor);
	CSDWindow *GetSDWindow(POSITION pos);
};