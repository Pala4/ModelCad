//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCPID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CPID::CPID(void):CStdElement()
{
   ID_OBJECT = ID_PID;
   C1 = 1.0;
   C0 = 0.0;
   C2 = 0.0;
   ElName = "ПИД-регулятор";
   FPIDProp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CPID::SetData(void)
{
	FPIDProp = new TFPIDProp(Application);
   FPIDProp->EC1->Text = FloatToStr(C1);
   FPIDProp->EC0->Text = FloatToStr(C0);
   FPIDProp->EC2->Text = FloatToStr(C2);
   FPIDProp->ShowModal();
   if(FPIDProp->ResultOk)
   {
      C1 = FPIDProp->C1;
      C0 = FPIDProp->C0;
      C2 = FPIDProp->C2;
   }
   FPIDProp->Free();
}
//---------------------------------------------------------------------------
void CPID::FUNKCIJA(int index, int end, long double DT)
{
	/*	if(index == 0)
   	Out[index] = (C2/DT + C1)*In[index]+C0*DT*In[index]/complex <long double>(2.0,0.0);
   else
   	Out[index] = C2/DT*(In[index]-In[index-1])+C1*In[index]+Out[index-1]+C0*DT/complex <long double>(2.0,0.0)*(In[index]+In[index-1]);

        long double S0 = C1 + C2/DT;
        long double S1 = C0*DT - C1 - 2*C0/DT;
        long double S2 = C2/DT;
        if(index == 0)
           Out[index] = -S0*In[index];
        if(index == 1)
           Out[index] = Out[index - 1] - S0*In[index] - S1*In[index - 1];
        if(index > 1)
           Out[index] = Out[index - 1] - S0*In[index] - S1*In[index - 1] - S2*In[index - 2];
   */
	if(!index)
   	Out[index] = (C2/DT + C1)*In[index];
	if(index == 1)
   	Out[index] = (C2/DT + C1)*In[index] - (-C0*DT + 2.0*C2/DT + C1)*In[index-1] + Out[index - 1];
	if(index >= 2)
   	Out[index] = (C2/DT + C1)*In[index] - (-C0*DT + 2.0*C2/DT + C1)*In[index-1] + C2/DT*In[index - 2] + Out[index - 1];
}
//---------------------------------------------------------------------------
void __fastcall CPID::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &C1, sizeof(long double));
   AddValue(Dump, DumpSize, &C0, sizeof(long double));
   AddValue(Dump, DumpSize, &C2, sizeof(long double));
}
//---------------------------------------------------------------------------
void __fastcall CPID::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &C1, sizeof(long double));
   GetValue(Dump, DumpSize, &C0, sizeof(long double));
   GetValue(Dump, DumpSize, &C2, sizeof(long double));
}
//---------------------------------------------------------------------------
