//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MC1P.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
C1P::C1P(void):CStdElement()
{
   N = 1.0;
   K = 1.0;
   ElName = "Интегрирующее звено";
   F1PProp = NULL;
   YN_1 =NULL;
   ID_OBJECT = ID_1P;
}
//---------------------------------------------------------------------------
void __fastcall C1P::SetData(void)
{
   F1PProp = new TF1PProp(Application);
   F1PProp->EN->Text = FloatToStr(N);
   F1PProp->EK->Text = FloatToStr(K);
   F1PProp->ShowModal();
   if(F1PProp->ResultOk)
   {
   	N = F1PProp->N;
   	K = F1PProp->K;
   }
   F1PProp->Free();
}
//---------------------------------------------------------------------------
void C1P::FUNKCIJA(int index, int end, long double DT)
{
	for(int i = 0; i < N; i++)
   {
      if(!i && !index)
      {
      	delete []YN_1;
         YN_1 = NULL;
         YN_1 = new complex <long double>[N];
      }
      if(index == 0)
      	Out[index] = DT*In[index];
      else
      	Out[index] = DT*In[index] + YN_1[i];
      YN_1[i] = Out[index];
      In[index] = Out[index];
   }
}
//---------------------------------------------------------------------------
void __fastcall C1P::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &N, sizeof(long double));
   AddValue(Dump, DumpSize, &K, sizeof(long double));
}
//---------------------------------------------------------------------------
void __fastcall C1P::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &N, sizeof(long double));
   GetValue(Dump, DumpSize, &K, sizeof(long double));
}
//---------------------------------------------------------------------------
C1P::~C1P()
{
	delete []YN_1;
   YN_1 = NULL;
}
//---------------------------------------------------------------------------
