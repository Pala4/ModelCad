//---------------------------------------------------------------------------
#ifndef MCClipBoardH
#define MCClipBoardH

#include <windows.h>
//---------------------------------------------------------------------------
class CClipBoard
{
public:
	CClipBoard(void);
   void RegisterFormat(LPSTR FormatName, UINT &Format);
   bool CheckFormat(UINT Format);
   bool Open(HWND hwnd);
   bool Empty(void);
   bool SetData(int Format, LPVOID Data);
   bool SetTextData(int Format, LPSTR Data);
   bool SetDCData(int Format, HDC Data, DWORD X, DWORD Y, DWORD Width, DWORD Height);
   bool Close(void);
   virtual ~CClipBoard(void);
};
//---------------------------------------------------------------------------
#endif
