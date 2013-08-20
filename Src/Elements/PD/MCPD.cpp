//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCPD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CPD::CPD(void):CStdElement()
{
   ID_OBJECT = ID_PD;
   C1 = 1.0;
   C2 = 0.0;
   ElName = "ПД-регулятор";
   FPDProp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CPD::SetData(void)
{
	FPDProp = new TFPDProp(Application);
   FPDProp->EC1->Text = FloatToStr(C1);
   FPDProp->EC2->Text = FloatToStr(C2);
   FPDProp->ShowModal();
   if(FPDProp->ResultOk)
   {
   	C1 = FPDProp->C1;
   	C2 = FPDProp->C2;
   }
   FPDProp->Free();
}
//---------------------------------------------------------------------------
void CPD::FUNKCIJA(int index, int end, long double DT)
{
   /*
	if(index == 0)
   	Out[index] = (C1 + C2/DT)*In[index];
   else
   	Out[index] = (C1 + C2/DT)*In[index] - C2/DT*In[index-1];
   */
	if(!index)
   	Out[index] = (C2/DT + C1)*In[index];
	if(index == 1)
   	Out[index] = (C2/DT + C1)*In[index] - (2.0*C2/DT + C1)*In[index-1] + Out[index - 1];
	if(index >= 2)
   	Out[index] = (C2/DT + C1)*In[index] - (2.0*C2/DT + C1)*In[index-1] + C2/DT*In[index - 2] + Out[index - 1];
}
//---------------------------------------------------------------------------
void __fastcall CPD::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &C1, sizeof(long double));
   AddValue(Dump, DumpSize, &C2, sizeof(long double));
}
//---------------------------------------------------------------------------
void __fastcall CPD::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &C1, sizeof(long double));
   GetValue(Dump, DumpSize, &C2, sizeof(long double));
}
//---------------------------------------------------------------------------
