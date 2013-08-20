//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCSys.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CSysInfo::CSysInfo(void)
{
	ScrWidth = 0;
   ScrHeight = 0;
   BPP = 0;
}
//---------------------------------------------------------------------------
void __fastcall CSysInfo::GetSysInfo(void)
{
	ScrWidth = GetSystemMetrics(SM_CXSCREEN);
   ScrHeight = GetSystemMetrics(SM_CYSCREEN);
   RECT rect;
   SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
   MaxWinWidth = rect.right - rect.left;
   MaxWinHeight = rect.bottom - rect.top;
   BPP = GetDeviceCaps(GetDesktopWindow(), BITSPIXEL);
}
//---------------------------------------------------------------------------
void __fastcall CSysInfo::Init(CBase *Parent)
{
	CObject::Init(Parent);
	GetSysInfo();
}
//---------------------------------------------------------------------------
void __fastcall CSysInfo::Done(void)
{
	ScrWidth = 0;
   ScrHeight = 0;
   BPP = 0;
   CObject::Done();
}
//---------------------------------------------------------------------------
