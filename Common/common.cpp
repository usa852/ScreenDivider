#include "../ScreenDivider/stdafx.h"
#include "../ScreenDividerHk/stdafx.h"
#include "common.h"

BOOL SetTransparentWindow(HWND hWnd, BYTE bAlpha)
{
	/*
		Before make window to transparency,
		we should set WS_EX_LAYERED extension style
	*/
	// Get old extension style
	LONG oldExStyle;
	oldExStyle = GetWindowLong(hWnd, GWL_EXSTYLE);

	// Set new extension style that oldExStyle | WS_EX_LAYERED
	SetWindowLong(hWnd, GWL_EXSTYLE, oldExStyle | WS_EX_LAYERED);

	// Set transparent window
	BOOL ret;
	ret = SetLayeredWindowAttributes(hWnd, 0, bAlpha, LWA_ALPHA);

	return ret;
}