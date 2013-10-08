
// ScreenDivider.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CScreenDividerApp:
// See ScreenDivider.cpp for the implementation of this class
//

class CScreenDividerApp : public CWinApp
{
public:
	CScreenDividerApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CScreenDividerApp theApp;