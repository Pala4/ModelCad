//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCLuft.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CLuft::CLuft(void):CStdElement()
{
   ID_OBJECT = ID_LUFT;
   A = 1.0;
   K = 1.0;
   dX = 0.0;
   dY = 0.0;
   ElName = "ֻ‏פע";
   FLuftProp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CLuft::SetData(void)
{
	FLuftProp = new TFLuftProp(Application);
   FLuftProp->EA->Text = FloatToStr(A);
   FLuftProp->EK->Text = FloatToStr(K);
   FLuftProp->EdX->Text = FloatToStr(dX);
   FLuftProp->EdY->Text = FloatToStr(dY);
   FLuftProp->ShowModal();
   if(FLuftProp->ResultOk)
   {
   	A = FLuftProp->A;
   	K = FLuftProp->K;
   	dX = FLuftProp->dX;
   	dY = FLuftProp->dY;
   }
   FLuftProp->Free();
}
//---------------------------------------------------------------------------
void CLuft::FUNKCIJA(int index, int end, long double DT)
{
   long double a = fabs(A/2.0);
   long double X = real(In[index]) - dX;
   long double OldX;
  	if(index == 0) OldX = X; else OldX = real(In[index - 1]);
   if(fabs(K*X - real(Out[index])) < K*a)
   {
   	if(index == 0) Out[index] = 0; else Out[index] = Out[index - 1];
   }
   else
   {
      if(X >= OldX) Out[index] = K*(X - a);
      if(X < OldX) Out[index] = K*(X + a);
   }
   Out[index] += dY;
}
//---------------------------------------------------------------------------
void __fastcall CLuft::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &A, sizeof(long double));
   AddValue(Dump, DumpSize, &K, sizeof(long double));
   AddValue(Dump, DumpSize, &dX, sizeof(long double));
   AddValue(Dump, DumpSize, &dY, sizeof(long double));
}
//---------------------------------------------------------------------------
void __fastcall CLuft::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &A, sizeof(long double));
   GetValue(Dump, DumpSize, &K, sizeof(long double));
   GetValue(Dump, DumpSize, &dX, sizeof(long double));
   GetValue(Dump, DumpSize, &dY, sizeof(long double));
}
//---------------------------------------------------------------------------
