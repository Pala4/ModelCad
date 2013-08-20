//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCUBRelay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CUBRelay::CUBRelay(void):CStdElement()
{
   ID_OBJECT = ID_UBRELAY;
   B = 1.0;
   dX = 0.0;
   dY = 0.0;
   ElName = "Однозначное реле";
   FUBRelayProp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CUBRelay::SetData(void)
{
	FUBRelayProp = new TFUBRelayProp(Application);
   FUBRelayProp->EB->Text = FloatToStr(B);
   FUBRelayProp->EdX->Text = FloatToStr(dX);
   FUBRelayProp->EdY->Text = FloatToStr(dY);
   FUBRelayProp->ShowModal();
   if(FUBRelayProp->ResultOk)
   {
   	B = FUBRelayProp->B;
   	dX = FUBRelayProp->dX;
   	dY = FUBRelayProp->dY;
   }
   FUBRelayProp->Free();
}
//---------------------------------------------------------------------------
void CUBRelay::FUNKCIJA(int index, int end, long double DT)
{
   long double X = real(In[index]) - dX;
   if(X > 0) Out[index] = B/2.0;
   if(X == 0)
   {
   	if(index == 0)
      	Out[index] = 0;
      else
      {
      	long double OldX = real(In[index - 1]);
         if(OldX < 0) Out[index] = B/2.0;
         if(OldX > 0) Out[index] = -B/2.0;
      }
   }
   if(X < 0) Out[index] = -B/2.0;
   Out[index] += dY;
}
//---------------------------------------------------------------------------
void __fastcall CUBRelay::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &B, sizeof(long double));
   AddValue(Dump, DumpSize, &dX, sizeof(long double));
   AddValue(Dump, DumpSize, &dY, sizeof(long double));
}
//---------------------------------------------------------------------------
void __fastcall CUBRelay::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &B, sizeof(long double));
   GetValue(Dump, DumpSize, &dX, sizeof(long double));
   GetValue(Dump, DumpSize, &dY, sizeof(long double));
}
//---------------------------------------------------------------------------
