// ScreenDividerHk.h : main header file for the ScreenDividerHk DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CScreenDividerHkApp
// See ScreenDividerHk.cpp for the implementation of this class
//

class CScreenDividerHkApp : public CWinApp
{
public:
	CScreenDividerHkApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
