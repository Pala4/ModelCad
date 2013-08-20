//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCPI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CPI::CPI(void):CStdElement()
{
   ID_OBJECT = ID_PI;
   C1 = 1.0;
   C0 = 0.0;
   ElName = "ПИ-регулятор";
   FPIProp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CPI::SetData(void)
{
	FPIProp = new TFPIProp(Application);
   FPIProp->EC1->Text = FloatToStr(C1);
   FPIProp->EC0->Text = FloatToStr(C0);
   FPIProp->ShowModal();
   if(FPIProp->ResultOk)
   {
      C1 = FPIProp->C1;
      C0 = FPIProp->C0;
   }
   FPIProp->Free();
}
//---------------------------------------------------------------------------
void CPI::FUNKCIJA(int index, int end, long double DT)
{
/*
	if(index == 0)
   	Out[index] = C1*In[index]+C0*DT*In[index]/complex<long double>(2.0,0.0);
   else
   	Out[index] = C1*In[index]+Out[index-1]+C0*DT/complex<long double>(2.0,0.0)*(In[index]+In[index-1]);
*/
	if(!index)
   	Out[index] = C1*In[index];
   else
   	Out[index] = C1*In[index] + (C0*DT - C1)*In[index - 1] + Out[index - 1];
}
//---------------------------------------------------------------------------
void __fastcall CPI::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &C1, sizeof(long double));
   AddValue(Dump, DumpSize, &C0, sizeof(long double));
}
//---------------------------------------------------------------------------
void __fastcall CPI::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &C1, sizeof(long double));
   GetValue(Dump, DumpSize, &C0, sizeof(long double));
}
//---------------------------------------------------------------------------
