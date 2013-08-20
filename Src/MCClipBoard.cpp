//---------------------------------------------------------------------------
#include "MCClipBoard.h"
//---------------------------------------------------------------------------
CClipBoard::CClipBoard(void)
{
}
//---------------------------------------------------------------------------
void CClipBoard::RegisterFormat(LPSTR FormatName, UINT &Format)
{
	if(!FormatName) {Format = 0; return;}
	Format = RegisterClipboardFormat(FormatName);
}
//---------------------------------------------------------------------------
bool CClipBoard::CheckFormat(UINT Format)
{
	return IsClipboardFormatAvailable(Format);
}
//---------------------------------------------------------------------------
bool CClipBoard::Open(HWND hwnd)
{
	return OpenClipboard(hwnd);
}
//---------------------------------------------------------------------------
bool CClipBoard::Empty(void)
{
	return EmptyClipboard();
}
//---------------------------------------------------------------------------
bool CClipBoard::SetData(int Format, HANDLE Data)
{
	return SetClipboardData(Format, Data);
}
//---------------------------------------------------------------------------
bool CClipBoard::SetTextData(int Format, LPSTR Data)
{
   DWORD DataLen = strlen(Data);
   HGLOBAL hgMem = GlobalAlloc(GHND, DataLen + 1);
   if(!hgMem) return false;
   LPSTR MemAddr = (LPSTR)GlobalLock(hgMem);
   if(!(DWORD)MemAddr) return false;
   strcpy(MemAddr, Data);
   GlobalUnlock(hgMem);
	return SetData(Format, hgMem);
}
//---------------------------------------------------------------------------
bool CClipBoard::SetDCData(int Format, HDC Data, DWORD X, DWORD Y, DWORD Width, DWORD Height)
{
   HBITMAP hbmCB = CreateCompatibleBitmap(Data, Width, Height);
   HDC CBDC = CreateCompatibleDC(Data);
   SelectObject(CBDC, hbmCB);
   BitBlt(CBDC, 0, 0, Width, Height, Data, X, Y, SRCCOPY);
	bool Result = SetData(Format, hbmCB);
   DeleteDC(CBDC);
   DeleteObject(hbmCB);
   return Result;
}
//---------------------------------------------------------------------------
bool CClipBoard::Close(void)
{
	return CloseClipboard();
}
//---------------------------------------------------------------------------
CClipBoard::~CClipBoard(void)
{
}
//---------------------------------------------------------------------------
