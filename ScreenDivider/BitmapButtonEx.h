#pragma once

class CBitmapButtonEx :
	public CBitmapButton
{
	DECLARE_DYNAMIC(CBitmapButtonEx)

public:
	CBitmapButtonEx(void);
	~CBitmapButtonEx(void);

	BOOL LoadBitmaps
	(
		LPCTSTR lpszBitmapResource,
		LPCTSTR lpszBitmapResourceHover,
		LPCTSTR lpszBitmapResourceSel,
		LPCTSTR lpszBitmapResourceFocus,
		LPCTSTR lpszBitmapResourceDisabled
	);
	BOOL LoadBitmaps
	(
		UINT nIDBitmapResource,
		UINT nIDBitmapResourceHover,
		UINT nIDBitmapResourceSel,
		UINT nIDBitmapResourceFocus,
		UINT nIDBitmapResourceDisabled
	);

	BOOL PreTranslateMessage(MSG* pMsg);

// Member variables
private:
	CBitmap m_bitmapHover;

// Message handlers
	DECLARE_MESSAGE_MAP()
};

