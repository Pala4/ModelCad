//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCZ.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CZ::CZ(void):CStdElement()
{
   ID_OBJECT = ID_Z;
   Azn = 1;
   Bzn = 1;
   Az = new long double[Azn];
   Bz = new long double[Bzn];
   Az[0] = 1.0;
   Bz[0] = 1.0;
   ElName = "Дискретное передаточное звено";
   FZProp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CZ::SetData(void)
{
	FZProp = new TFZProp(Application);
   FZProp->Azn = Azn;
   FZProp->Bzn = Bzn;
   FZProp->EAz->Text = FZProp->ArrayToStr(Az, Azn);
   FZProp->EBz->Text = FZProp->ArrayToStr(Bz, Bzn);
   FZProp->ShowModal();
   if(FZProp->ResultOk)
   {
      Azn = FZProp->Azn;
      Bzn = FZProp->Bzn;
		if(Az){delete []Az; Az = NULL;}
		if(Bz){delete []Bz; Bz = NULL;}
   	Az = new long double[Azn];
   	Bz = new long double[Bzn];
      memcpy(Az, FZProp->Az, sizeof(long double)*Azn);
      memcpy(Bz, FZProp->Bz, sizeof(long double)*Bzn);
   }
   FZProp->Free();
}
//---------------------------------------------------------------------------
void CZ::FUNKCIJA(int index, int end, long double DT)
{
   long double A = 0.0;
   long double B = 0.0;
   for(DWORD ci = 0; ci < Bzn; ci++)
    	if(ci)
     		if(index - (long int)ci >= 0)
      		B += Bz[ci]*real(Out[index - ci]);
   for(DWORD ci = 0; ci < Azn; ci++)
      if(index - (long int)ci >= 0)
      	A += Az[ci]*real(In[index - ci]);
   Out[index] = (A - B)/Bz[0];
}
//------------------------------------------------------------------------
void __fastcall CZ::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &Azn, sizeof(DWORD));
   AddValue(Dump, DumpSize, &Bzn, sizeof(DWORD));
   AddValue(Dump, DumpSize, Az, sizeof(long double)*Azn);
   AddValue(Dump, DumpSize, Bz, sizeof(long double)*Bzn);
}
//------------------------------------------------------------------------
void __fastcall CZ::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &Azn, sizeof(DWORD));
   GetValue(Dump, DumpSize, &Bzn, sizeof(DWORD));
	if(Az){delete []Az; Az = NULL;}
	if(Bz){delete []Bz; Bz = NULL;}
   Az = new long double[Azn];
   Bz = new long double[Bzn];
   GetValue(Dump, DumpSize, Az, sizeof(long double)*Azn);
   GetValue(Dump, DumpSize, Bz, sizeof(long double)*Bzn);
}
//------------------------------------------------------------------------
CZ::~CZ(void)
{
	if(Az){delete []Az; Az = NULL;}
	if(Bz){delete []Bz; Bz = NULL;}
}
//---------------------------------------------------------------------------
