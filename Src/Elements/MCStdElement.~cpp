//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCStdElement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
bool CStdElement::CheckOut(void)
{
	return (Out);
}
//---------------------------------------------------------------------------
CStdElement::CStdElement(void):CElement()
{
	Y_out = 0;
	InLink = NULL;
   OutLink = NULL;
   InEl = NULL;
   OutEl = NULL;
	Output = NULL;
	Input = NULL;
	In = NULL;
   Out = NULL;
	ID_ELEM = ID_STDELEMENT;
}
//---------------------------------------------------------------------------
void __fastcall CStdElement::ShowGrp(void)
{
   if(!Out) return;
   FGrp->Caption = GrpName + " " + ElName;
   FGrp->SetAxNames(AxXName, AxYName);
   long double *X = new long double[EndIndex];
   long double *Y = new long double[EndIndex];
   DWORD cj = 0;
   for(long double ci = 0; ci < T; ci += DT)
   {
   	X[cj] = ci;
   	Y[cj] = real(Out[cj]);
      cj++;
   }
   FGrp->AddSer(X, Y, EndIndex, ElName + ":Состояние");
   delete []X;
   delete []Y;
	FGrp->Show();
}
//---------------------------------------------------------------------------
BOOL __fastcall CStdElement::OrientBusy(T_ORIENT OR)
{
	if(InLink) if(InLink->OUT_OR == OR) return TRUE;
	if(OutLink) if(OutLink->IN_OR == OR) return TRUE;
   return FALSE;
}
//---------------------------------------------------------------------------
void CStdElement::VICHISLENIE(int index, int end, long double DT)
{
   CElement::VICHISLENIE(index, end, DT);
	if(index == 0)
 	{
 		Y_out = 0;
 		delete []Out; Out = NULL;
 		delete []In; In = NULL;
 		Out = new complex<long double>[end];
 		In = new complex<long double>[end];
   }
   In[index] = ((CElement*)Input)->Y_out;
	FUNKCIJA(index, end, DT);
	Y_out = Out[index];
}
//---------------------------------------------------------------------------
void __fastcall CStdElement::GetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::GetDump(Dump, DumpSize);
}
//---------------------------------------------------------------------------
void __fastcall CStdElement::SetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::SetDump(Dump, DumpSize);
}
//---------------------------------------------------------------------------
void CStdElement::DELETE_GRAFIC_MASSIV()
{
 	Y_out = 0;
 	delete []Out; Out = NULL;
 	delete []In; In = NULL;
}
//---------------------------------------------------------------------------
void CStdElement::DelLink(void *LinkPtr)
{
	if(LinkPtr == InLink)
   {
   	InLink = NULL;
		InEl = NULL;
		Input = NULL;
   }
	if(LinkPtr == OutLink)
   {
   	OutLink = NULL;
		OutEl = NULL;
		Output = NULL;
   }
}
//---------------------------------------------------------------------------
void CStdElement::DelInfo(void)
{
  		Y_out = 0;
 		if(Out){delete []Out; Out = NULL;}
 		if(In){delete []In; In = NULL;}
}
//---------------------------------------------------------------------------
CStdElement::~CStdElement(void)
{
	delete []In; In = NULL;
	delete []Out; Out = NULL;
	Input = NULL;
	Output = NULL;
	InEl = NULL;
	OutEl = NULL;
	InLink = NULL;
	OutLink = NULL;
}
//---------------------------------------------------------------------------
