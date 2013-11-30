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
	CArray<CSDWindow> m_arrSDWindow;

public:
	void Serialize(CArchive& ar);
	BOOL LoadFromFile(TCHAR strSDFormPath[MAX_PATH]);
	BOOL SaveToFile(TCHAR strSDFormPath[MAX_PATH]);
	VOID RemoveSDWindow(int idx);
	INT_PTR AddSDWindow(CSDWindow &newSDWindow);
	INT_PTR AddSDWindow(int l, int t, int r, int b);
	INT_PTR AddSDWindow(POINT topLeft, POINT bottomRight);
	INT_PTR AddSDWindow(POINT point, SIZE size);
	CSDWindow GetSDWindow(const CPoint& cursor);
	CSDWindow GetSDWindow(int idx);
};