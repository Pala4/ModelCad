//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCNoSense.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CNoSense::CNoSense(void):CStdElement()
{
   ID_OBJECT = ID_NOSENSE;
   A = 1.0;
   K = 1.0;
   dX = 0.0;
   dY = 0.0;
   ElName = "Нечувствительность";
   FNoSenseProp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CNoSense::SetData(void)
{
	FNoSenseProp = new TFNoSenseProp(Application);
   FNoSenseProp->EA->Text = FloatToStr(A);
   FNoSenseProp->EK->Text = FloatToStr(K);
   FNoSenseProp->EdX->Text = FloatToStr(dX);
   FNoSenseProp->EdY->Text = FloatToStr(dY);
   FNoSenseProp->ShowModal();
   if(FNoSenseProp->ResultOk)
   {
   	A = FNoSenseProp->A;
   	K = FNoSenseProp->K;
   	dX = FNoSenseProp->dX;
   	dY = FNoSenseProp->dY;
   }
   FNoSenseProp->Free();
}
//---------------------------------------------------------------------------
void CNoSense::FUNKCIJA(int index, int end, long double DT)
{
   long double a = fabs(A/2.0);
   long double X = real(In[index]) - dX;
	if(fabs(X) <= a) Out[index] = 0.0;
   if(X <= -a) Out[index] = K*(X + a);
   if(X >= a) Out[index] = K*(X - a);
   Out[index] += dY;
}
//---------------------------------------------------------------------------
void __fastcall CNoSense::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &A, sizeof(long double));
   AddValue(Dump, DumpSize, &K, sizeof(long double));
   AddValue(Dump, DumpSize, &dX, sizeof(long double));
   AddValue(Dump, DumpSize, &dY, sizeof(long double));
}
//---------------------------------------------------------------------------
void __fastcall CNoSense::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &A, sizeof(long double));
   GetValue(Dump, DumpSize, &K, sizeof(long double));
   GetValue(Dump, DumpSize, &dX, sizeof(long double));
   GetValue(Dump, DumpSize, &dY, sizeof(long double));
}
//---------------------------------------------------------------------------
