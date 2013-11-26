#pragma once
#include "atltypes.h"

#define SIZE_TITLEBAR 30

class CSDWindow :
	public CRect
{
public:
	CSDWindow(void);
	CSDWindow(int l, int t, int r, int b);
	CSDWindow(POINT topLeft, POINT bottomRight);
	CSDWindow(POINT point, SIZE size);
	~CSDWindow(void);

public:
	BOOL IsCursorInTitlebar(const CPoint &cursor);
};

