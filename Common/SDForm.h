#pragma once
#include "SDWindow.h"

class CSDForm
	: CObject
{
	DECLARE_SERIAL(CSDForm)

public:
	CSDForm(void);
	CSDForm::CSDForm(CSDWindow screen);
	~CSDForm(void);

private:
	CList<CSDWindow> m_lstSDWindow;

public:
	void Serialize(CArchive& ar);
	BOOL LoadFromFile(TCHAR strSDFormPath[MAX_PATH]);
	BOOL SaveToFile(TCHAR strSDFormPath[MAX_PATH]);
	VOID RemoveSDWindow(POSITION pos);
	POSITION AddSDWindow(CSDWindow &newSDWindow);
	POSITION AddSDWindow(int l, int t, int r, int b);
	POSITION AddSDWindow(POINT topLeft, POINT bottomRight);
	POSITION AddSDWindow(POINT point, SIZE size);
	CSDWindow *GetSDWindow(const CPoint& cursor);
	CSDWindow *GetSDWindow(POSITION pos);
};