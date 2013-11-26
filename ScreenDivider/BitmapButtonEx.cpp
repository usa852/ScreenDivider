#include "stdafx.h"
#include "ScreenDivider.h"
#include "BitmapButtonEx.h"

IMPLEMENT_DYNAMIC(CBitmapButtonEx, CBitmapButton)

CBitmapButtonEx::CBitmapButtonEx(void)
	: CBitmapButton()
{
}


CBitmapButtonEx::~CBitmapButtonEx(void)
{
}

BOOL CBitmapButtonEx::LoadBitmaps
(
	LPCTSTR lpszBitmapResource,
	LPCTSTR lpszBitmapResourceHover = NULL,
	LPCTSTR lpszBitmapResourceSel = NULL,
	LPCTSTR lpszBitmapResourceFocus = NULL,
	LPCTSTR lpszBitmapResourceDisabled = NULL
)
{
	m_bitmapHover.DeleteObject();

	if (lpszBitmapResourceHover != NULL)
	{
		m_bitmapHover.LoadBitmap(lpszBitmapResourceHover);
	}

	return CBitmapButton::LoadBitmaps
			(
				lpszBitmapResource,
				lpszBitmapResourceSel,
				lpszBitmapResourceFocus,
				lpszBitmapResourceDisabled
			);
}

BOOL CBitmapButtonEx::LoadBitmaps
(
	UINT nIDBitmapResource,
	UINT nIDBitmapResourceHover = 0,
	UINT nIDBitmapResourceSel = 0,
	UINT nIDBitmapResourceFocus = 0,
	UINT nIDBitmapResourceDisabled = 0
)
{
	m_bitmapHover.DeleteObject();

	if (nIDBitmapResourceHover != 0)
	{
		m_bitmapHover.LoadBitmap(MAKEINTRESOURCE(nIDBitmapResourceHover));
	}

	return CBitmapButton::LoadBitmaps
			(
				nIDBitmapResource,
				nIDBitmapResourceSel,
				nIDBitmapResourceFocus,
				nIDBitmapResourceDisabled
			);
}

BOOL CBitmapButtonEx::PreTranslateMessage(MSG* pMsg)
{
	switch (pMsg->message)
	{
		case WM_MOUSEMOVE:
		{
			CRect rectButton;
			GetWindowRect(rectButton);
			
			if (rectButton.PtInRect(pMsg->pt))
			{
				CBitmap* pBitmap = &m_bitmapHover;

				// draw the whole button
				CDC* pDC = GetDC();
				CDC memDC;
				memDC.CreateCompatibleDC(pDC);
				CBitmap* pOld = memDC.SelectObject(pBitmap);
				if (pOld == NULL)
					break;     // destructors will clean up

				CRect rect;
				GetClientRect(rect);
				pDC->BitBlt(0, 0, rect.Width(), rect.Height(),
					&memDC, 0, 0, SRCCOPY);
				memDC.SelectObject(pOld);

				SetCapture();
			}
			else
			{
				CBitmap* pBitmap = &m_bitmap;

				// draw the whole button
				CDC* pDC = GetDC();
				CDC memDC;
				memDC.CreateCompatibleDC(pDC);
				CBitmap* pOld = memDC.SelectObject(pBitmap);
				if (pOld == NULL)
					break;     // destructors will clean up

				CRect rect;
				GetClientRect(rect);
				pDC->BitBlt(0, 0, rect.Width(), rect.Height(),
					&memDC, 0, 0, SRCCOPY);
				memDC.SelectObject(pOld);

				ReleaseCapture();
			}
			break;
		}
	}

	return CBitmapButton::PreTranslateMessage(pMsg);
}

BEGIN_MESSAGE_MAP(CBitmapButtonEx, CBitmapButton)
END_MESSAGE_MAP()