//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <time.h>
#include "Els.h"
#include "ProjFrm.h"
#include "GrpFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "ProjFrm.h"
extern TFProj *ff;
int Kol_vo = 0;
bool DelSvjaz=false;
//---------------------------------------------------------------------------
Mod_Summator::Mod_Summator(CElement * Sender):CElement()
{
	Mn_Summator = Sender;
	ID_ELEM = ID_SUMMATOR1;
	In = NULL;
   In2 = NULL;
   Out = NULL;
	Y_out = 0;
	Invers1 = false;
	Invers2 = false;
	Invers3 = false;
	Output = NULL;
	Input = NULL;
	Input2 = NULL;
	Kol_vo++;
}
//---------------------------------------------------------------------------
void Mod_Summator::VICHISLENIE(int index, int end, long double DT)
{
   CElement::VICHISLENIE(index, end, DT);
   Mn_Summator->VICHISLENIE(index, end, DT);
	if(index == 0)
 	{
 		//Y_out = 0;
 		if(Out) {delete []Out; Out = NULL;}
 		if(In) {delete []In; In = NULL;}
 		if(In2) {delete []In2; In2 = NULL;}
 		Out = new complex <long double>[end];
 		In = new complex <long double>[end];
 		In2 = new complex <long double>[end];
 	}
	if(Input != NULL)
		switch(Input->ID_ELEM)
 		{
 			case ID_IN: In[index] = ((CIn*)Input)->Y_out; break;
 			case ID_STDELEMENT: In[index] = ((CStdElement*)Input)->Y_out; break;
 			case ID_UNIT: In[index] = ((CUnit*)Input)->Y_out; break;
 			case ID_UZEL: In[index] = ((CUzel*)Input)->Y_out; break;
 			case ID_SUMMATOR1: In[index] = ((Mod_Summator*)Input)->Y_out; break;
 			default: In[index] = 0; break;
 		}
	else
   	In[index] = 0;
	if(Input2 != NULL)
		switch(Input2->ID_ELEM)
 		{
 			case ID_IN: In2[index] = ((CIn*)Input2)->Y_out; break;
 			case ID_STDELEMENT: In2[index] = ((CStdElement*)Input2)->Y_out; break;
 			case ID_UZEL: In2[index] = ((CUzel*)Input2)->Y_out; break;
 			case ID_UNIT: In2[index] = ((CUnit*)Input2)->Y_out; break;
 			case ID_SUMMATOR1: In2[index] = ((Mod_Summator*)Input2)->Y_out; break;
 			default: In2[index] = 0; break;
 		}
	else
   	In2[index] = 0;
	if(Invers1) In[index] = -In[index];
	if(Invers2) In2[index] = -In2[index];
	Out[index] = In[index] + In2[index];
   if(Invers3) Out[index] = -Out[index];
	Y_out = Out[index];
}
//---------------------------------------------------------------------------
void Mod_Summator::DelLink(void *LinkPtr)
{
   if(((CLink*)LinkPtr)->InEl == Input)
   	Input = NULL;
   if(((CLink*)LinkPtr)->InEl == Input2)
   	Input2 = NULL;
   if(((CLink*)LinkPtr)->OutEl == Output)
   	Output = NULL;
}
void Mod_Summator::DelInfo(void)
{
 		Y_out = 0;
 		if(Out){delete []Out; Out = NULL;}
 		if(In){delete []In; In = NULL;}
 		if(In){delete []In2; In2 = NULL;}

}

//---------------------------------------------------------------------------
void Mod_Summator::DELETE_GRAFIC_MASSIV()
{
 	Y_out = 0;
 	delete []Out; Out = NULL;
 	delete []In; In = NULL;
 	delete []In2; In2 = NULL;
}
//---------------------------------------------------------------------------
Mod_Summator::~Mod_Summator()
{
	Mn_Summator = NULL;
   Kol_vo--;
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
void __fastcall CSummator::GetInvers(CLink *Link, bool *Invers, bool OutOrient)
{
   if(Link)
   {
      if(OutOrient)
   		switch(Link->OUT_OR)
   		{
   			case OR_LEFT:
   				FSmProp->CBxLeftInvers->Enabled = true;
      			FSmProp->CBxLeftInvers->Checked = *Invers;
      		break;
   			case OR_TOP:
   				FSmProp->CBxTopInvers->Enabled = true;
      			FSmProp->CBxTopInvers->Checked = *Invers;
      		break;
   			case OR_RIGHT:
   				FSmProp->CBxRightInvers->Enabled = true;
      			FSmProp->CBxRightInvers->Checked = *Invers;
      		break;
   			case OR_BOTTOM:
   				FSmProp->CBxBottomInvers->Enabled = true;
      			FSmProp->CBxBottomInvers->Checked = *Invers;
      		break;
   		}
      else
   		switch(Link->IN_OR)
   		{
   			case OR_LEFT:
   				FSmProp->CBxLeftInvers->Enabled = true;
      			FSmProp->CBxLeftInvers->Checked = *Invers;
      		break;
   			case OR_TOP:
   				FSmProp->CBxTopInvers->Enabled = true;
      			FSmProp->CBxTopInvers->Checked = *Invers;
      		break;
   			case OR_RIGHT:
   				FSmProp->CBxRightInvers->Enabled = true;
      			FSmProp->CBxRightInvers->Checked = *Invers;
      		break;
   			case OR_BOTTOM:
   				FSmProp->CBxBottomInvers->Enabled = true;
      			FSmProp->CBxBottomInvers->Checked = *Invers;
      		break;
   		}
   }
}
//---------------------------------------------------------------------------
void __fastcall CSummator::SetInvers(CLink *Link, bool *Invers, bool OutOrient)
{
   if(Link)
   {
   	if(OutOrient)
      {
  			switch(Link->OUT_OR)
  			{
  				case OR_LEFT: *Invers = FSmProp->CBxLeftInvers->Checked; break;
  				case OR_TOP: *Invers = FSmProp->CBxTopInvers->Checked; break;
  				case OR_RIGHT: *Invers = FSmProp->CBxRightInvers->Checked; break;
  				case OR_BOTTOM: *Invers = FSmProp->CBxBottomInvers->Checked; break;
  			}
   		Link->InversOut = *Invers;
      	Link->InversOutPtr = Invers;
      }
      else
      {
  			switch(Link->IN_OR)
  			{
  				case OR_LEFT: *Invers = FSmProp->CBxLeftInvers->Checked; break;
  				case OR_TOP: *Invers = FSmProp->CBxTopInvers->Checked; break;
  				case OR_RIGHT: *Invers = FSmProp->CBxRightInvers->Checked; break;
  				case OR_BOTTOM: *Invers = FSmProp->CBxBottomInvers->Checked; break;
  			}
   		Link->InversIn = *Invers;
      	Link->InversInPtr = Invers;
      }
   }
}
//---------------------------------------------------------------------------
bool CSummator::CheckOut(void)
{
	return (Summator2->Out);
}
//---------------------------------------------------------------------------
CSummator::CSummator(void):CElement()
{
   ElName = "��������";  
	InLink1 = NULL;
   InLink2 = NULL;
   InLink3 = NULL;
   OutLink = NULL;
	InEl1 = NULL;
   InEl2 = NULL;
   InEl3 = NULL;
   OutEl = NULL;
	Summator1 = new Mod_Summator(this);
	Summator2 = new Mod_Summator(this);
	Summator1->Output = Summator2;
	Summator2->Input = Summator1;
   Summator1->Invers1 = false;
   Summator1->Invers2 = false;
   Summator2->Invers2 = false;
	InversIn1 = &Summator1->Invers1;
	InversIn2 = &Summator1->Invers2;
	InversIn3 = &Summator2->Invers2;
	InversOut = &Summator2->Invers3;
	ID_ELEM = ID_SUMMATOR;
	ID_OBJECT = ID_SUMMATOR;
}
//---------------------------------------------------------------------------
BOOL __fastcall CSummator::OrientBusy(T_ORIENT OR)
{
	if(InLink1)
   	if(InLink1->OUT_OR == OR) return TRUE;
	if(InLink2)
   	if(InLink2->OUT_OR == OR) return TRUE;
	if(InLink3)
   	if(InLink3->OUT_OR == OR) return TRUE;
	if(OutLink)
   	if(OutLink->IN_OR == OR) return TRUE;
   return FALSE;
}
//---------------------------------------------------------------------------
void __fastcall CSummator::SetData(void)
{
	FSmProp = new TFSmProp(Application);
   FSmProp->CBxLeftInvers->Enabled = false;
   FSmProp->CBxTopInvers->Enabled = false;
   FSmProp->CBxRightInvers->Enabled = false;
   FSmProp->CBxBottomInvers->Enabled = false;
   GetInvers(InLink1, InversIn1, true);
   GetInvers(InLink2, InversIn2, true);
   GetInvers(InLink3, InversIn3, true);
   GetInvers(OutLink, InversOut, false);
   FSmProp->ShowModal();
   if(FSmProp->Result)
   {
   	SetInvers(InLink1, InversIn1, true);
   	SetInvers(InLink2, InversIn2, true);
   	SetInvers(InLink3, InversIn3, true);
   	SetInvers(OutLink, InversOut, false);
   }
   FSmProp->Free();
}
//---------------------------------------------------------------------------
void __fastcall CSummator::ShowGrp(void)
{
   if(!Summator2->Out) return;
   FGrp->Caption = GrpName + " " + ElName;
   FGrp->SetAxNames(AxXName, AxYName);
   long double *X = new long double[EndIndex];
   long double *Y = new long double[EndIndex];
   DWORD cj = 0;
   for(long double ci = 0; ci < T; ci += DT)
   {
   	X[cj] = ci;
   	Y[cj] = real(Summator2->Out[cj]);
      cj++;
   }
   FGrp->AddSer(X, Y, EndIndex);
   delete []X;
   delete []Y;
	FGrp->Show();
}
//---------------------------------------------------------------------------
void CSummator::DelLink(void *LinkPtr)
{
	if(LinkPtr == InLink1)
   {
      Summator1->DelLink(InLink1);
      Summator2->DelLink(InLink1);
   	InLink1 = NULL;
      InEl1 = NULL;
   }
	if(LinkPtr == InLink2)
   {
      Summator1->DelLink(InLink2);
      Summator2->DelLink(InLink2);
   	InLink2 = NULL;
      InEl2 = NULL;
   }
	if(LinkPtr == InLink3)
   {
      Summator1->DelLink(InLink3);
      Summator2->DelLink(InLink3);
   	InLink3 = NULL;
      InEl3 = NULL;
   }
	if(LinkPtr == OutLink)
   {
      Summator1->DelLink(OutLink);
      Summator2->DelLink(OutLink);
   	OutLink = NULL;
      OutEl = NULL;
   }
}
//---------------------------------------------------------------------------
void __fastcall CSummator::GetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, InversIn1, sizeof(bool));
   AddValue(Dump, DumpSize, InversIn2, sizeof(bool));
   AddValue(Dump, DumpSize, InversIn3, sizeof(bool));
   AddValue(Dump, DumpSize, InversOut, sizeof(bool));
}
//---------------------------------------------------------------------------
void __fastcall CSummator::SetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &Summator1->Invers1, sizeof(bool));
   GetValue(Dump, DumpSize, &Summator1->Invers2, sizeof(bool));
   GetValue(Dump, DumpSize, &Summator2->Invers2, sizeof(bool));
   GetValue(Dump, DumpSize, &Summator2->Invers3, sizeof(bool));
}
//---------------------------------------------------------------------------
void CSummator::DelInfo(void)
{
	if(Summator1)Summator1->DelInfo();
   if(Summator2)Summator2->DelInfo();
}
//---------------------------------------------------------------------------
CSummator::~CSummator()
{
	InversIn1 = NULL;
   InversIn2 = NULL;
   InversIn3 = NULL;
   InversOut = NULL;
	delete Summator1; Summator1 = NULL;
	delete Summator2; Summator2 = NULL;
	InEl1 = NULL;
	InEl2 = NULL;
	InEl3 = NULL;
	OutEl = NULL;
	InLink1 = NULL;
	InLink2 = NULL;
	InLink3 = NULL;
	OutLink = NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CUzel::CUzel(CElement* Sender):CElement()
{
Mn_Uzel=Sender;
Mnogo_uzlov=true;
InOut=NULL; Y_out=0;
Output=NULL;
Input=NULL;
Output2=NULL;
ID_ELEM=ID_UZEL;
Kol_vo++;
}

CUzel::~CUzel()
{
delete [] InOut; InOut=NULL;
Output=NULL;
Input=NULL;
Output2=NULL;
Mn_Uzel=NULL;
Kol_vo--;
}

void CUzel::VICHISLENIE(int index, int end, long double DT)
{
   CElement::VICHISLENIE(index, end, DT);
   Mn_Uzel->VICHISLENIE(index, end, DT);
if(index==0)
 {
// Y_out=0;
 if(InOut) {delete [] InOut; InOut=NULL;}
 InOut= new complex <long double>[end];
}
switch(Input->ID_ELEM)  //�������� ������� �� �������� �������
 {
 case ID_IN: InOut[index] = ((CIn*)Input)->Y_out;
                break;
 case ID_STDELEMENT: InOut[index] = ((CStdElement*)Input)->Y_out;
                break;
 case ID_UNIT:InOut[index] = ((CUnit*)Input)->Y_out;
                break;
 case ID_UZEL:  InOut[index] = ((CUzel*)Input)->Y_out;
                break;
 case ID_SUMMATOR1: InOut[index] = ((Mod_Summator*)Input)->Y_out;
                break;
 default: InOut[index]=complex <long double>(0.0,0.0);
                break;
 }
Y_out=InOut[index];
//Ar_Model->Memo1->Lines->Add("����");
}
void CUzel::DelInfo(void)
{
 Y_out=0;
 if(InOut){delete [] InOut; InOut=NULL;}
}

//---------------------------------------------------------------------------
void CUzel::DELETE_GRAFIC_MASSIV()
{
 Y_out=0;
 delete [] InOut; InOut=NULL;
}
//-------------------------------------------------------------------
void CUzel::DelLink(void *LinkPtr, bool &DelIt)
{
   DelIt = false;
	if(((CLink*)LinkPtr)->InEl == Input)
   {
      Input = NULL;
      DelIt = true;
   }
	if(((CLink*)LinkPtr)->OutEl == Output)
   {
      Output = NULL;
      DelIt = true;
   }
	if(((CLink*)LinkPtr)->OutEl == Output2)
   {
      Output2 = NULL;
      DelIt = true;
   }
}
//-------------------------------------------------------------------
//---------------------------------------------------------------------------
bool CUnit::CheckOut(void)
{
	if(Kol_vo_Uzlov == 0) return (Out);
   return (Uzel[0]->InOut);
}
//-------------------------------------------------------------------
CUnit::CUnit(void):CElement()
{
   InLink = NULL;
	OutLinks = new TList;

   //
   InEl = NULL;
   OutEls = new TList;
   //
    Uzel=NULL; Input=NULL; Output=NULL;
    Kol_vo_Uzlov=0;
    Kol_vo_Out=0;
    Y_out=0;
   ElName = "����";
    In=NULL; Out=NULL;
	ID_ELEM = ID_UNIT;
	ID_OBJECT = ID_UNIT;
}
//-------------------------------------------------------------------
void __fastcall CUnit::AddOutLink(CLink *OutLink, CElement *OutEl)
{
ObrPer();
CElement *OutEl_output =OutEl;
if(OutEl_output->ID_ELEM==ID_SUMMATOR)
{
if ((((CSummator*)OutEl_output)->Summator1->Input==NULL)||
    (((CSummator*)OutEl_output)->Summator1->Input2==NULL))
    OutEl_output=((CSummator*)OutEl_output)->Summator1;
    else if(((CSummator*)OutEl_output)->Summator2->Input2==NULL)
    OutEl_output=((CSummator*)OutEl_output)->Summator2;
}


  OutLinks->Add(OutLink);
//   OutEls->Add(OutEl);
   OutEls->Add(OutEl);

   if(Output)
   {
        delete []Output;
        Output = NULL;
   }

   Kol_vo_Out = OutEls->Count;

   Output = new CElement*[Kol_vo_Out];

   for(int ci = 0; ci < Kol_vo_Out; ci++)
        Output[ci] = (CElement*)OutEls->Items[ci];
//   for(int ci = 0; ci < Kol_vo_Out; ci++)
//        Output[ci]->ID_ELEM;

//   Razbivka_Sum_Uzel();
OutEl_output=NULL;
}
//-------------------------------------------------------------------
BOOL __fastcall CUnit::CheckLink(CLink *Link)
{
	if(OutLinks->IndexOf(Link) == -1) return FALSE; else return TRUE;
}
//-------------------------------------------------------------------
BOOL __fastcall CUnit::OrientBusy(T_ORIENT OR)
{
   return FALSE;
}
//---------------------------------------------------------------------------
void __fastcall CUnit::ShowGrp(void)
{
	if(Kol_vo_Uzlov == 0)
   {
   	if(!Out) return;
   }
   else
   	if(!Uzel[0]->InOut) return;
   FGrp->Caption = GrpName + " " + ElName;
   FGrp->SetAxNames(AxXName, AxYName);
   long double *X = new long double[EndIndex];
   long double *Y = new long double[EndIndex];
   DWORD cj = 0;
   for(long double ci = 0; ci < T; ci += DT)
   {
   	X[cj] = ci;
		if(Kol_vo_Uzlov == 0)
   		Y[cj] = real(Out[cj]);
      else
      	Y[cj] = real(Uzel[0]->InOut[cj]);
      cj++;
   }
   FGrp->AddSer(X, Y, EndIndex);
   delete []X;
   delete []Y;
	FGrp->Show();
}
//-------------------------------------------------------------------
CUnit::~CUnit(void)
{
Input=NULL;
delete [] Output; Output=NULL;
OutLinks->Clear();
OutEls->Clear();
InLink = NULL;
Uzel=NULL; Input=NULL; Output=NULL;
delete [] In; In=NULL;
delete [] Out; Out=NULL;
}
//-------------------------------------------------------------------
void CUnit::Razbivka_Sum_Uzel()
{
for(int i = 0; i< Kol_vo_Uzlov;i++)
{
if((Kol_vo_Uzlov==1)&&(Kol_vo_Out==1))
{
if(Uzel[i]->Input!=NULL)
 {
  if(Uzel[i]->Input->ID_ELEM==ID_STDELEMENT)
   ((CStdElement*)Uzel[i]->Input)->Output=this;
  if(Uzel[i]->Input->ID_ELEM==ID_IN)
   ((CIn*)Uzel[i]->Input)->Output=this;
  if(Uzel[i]->Input->ID_ELEM==ID_UZEL)
   {
     if((((CUzel*)Uzel[i]->Input)->Output)!=NULL)
      {
       if((((CUzel*)Uzel[i]->Input)->Output)==Uzel[i])
        ((CUzel*)Uzel[i]->Input)->Output=this;
       else
        ((CUzel*)Uzel[i]->Input)->Output2=this;
      }
   }
  if(Uzel[i]->Input->ID_ELEM==ID_SUMMATOR1)
   ((Mod_Summator*)Uzel[i]->Input)->Output=this;
  if(Uzel[i]->Input->ID_ELEM==ID_UNIT)
   {

    for(int j = 0; j<((CUnit*)Uzel[i]->Input)->Kol_vo_Out;j++)
     {
      if(((CUnit*)Uzel[i]->Input)->Output[j]==Uzel[i])
        ((CUnit*)Uzel[i]->Input)->Output[j]=this;
     }
   }
 }

if(Uzel[i]->Output!=NULL)
 {
  if(Uzel[i]->Output->ID_ELEM==ID_STDELEMENT)
   ((CStdElement*)Uzel[i]->Output)->Input=this;
  if(Uzel[i]->Output->ID_ELEM==ID_OUT)
   ((COut*)Uzel[i]->Output)->Input=this;
  if(Uzel[i]->Output->ID_ELEM==ID_SUMMATOR1)
   {
     if((((Mod_Summator*)Uzel[i]->Output)->Input)!=NULL)
      {
       if((((Mod_Summator*)Uzel[i]->Output)->Input)==Uzel[i])
        ((Mod_Summator*)Uzel[i]->Output)->Input=this;
       else
        ((Mod_Summator*)Uzel[i]->Output)->Input2=this;
      }
   }
  if(Uzel[i]->Output->ID_ELEM==ID_UZEL)
   ((CUzel*)Uzel[i]->Output)->Input=this;
  if(Uzel[i]->Output->ID_ELEM==ID_UNIT)
   ((CUnit*)Uzel[i]->Output)->Input=this;
 }

if(Uzel[i]->Output2!=NULL)
 {
  if(Uzel[i]->Output2->ID_ELEM==ID_STDELEMENT)
    ((CStdElement*)Uzel[i]->Output2)->Input=this;
  if(Uzel[i]->Output2->ID_ELEM==ID_OUT)
   ((COut*)Uzel[i]->Output2)->Input=this;
  if(Uzel[i]->Output2->ID_ELEM==ID_SUMMATOR1)
   {
     if((((Mod_Summator*)Uzel[i]->Output2)->Input)!=NULL)
      {
       if((((Mod_Summator*)Uzel[i]->Output2)->Input)==Uzel[i])
        ((Mod_Summator*)Uzel[i]->Output2)->Input=this;
       else
        ((Mod_Summator*)Uzel[i]->Output2)->Input2=this;
      }
   }
  if(Uzel[i]->Output2->ID_ELEM==ID_UZEL)
   ((CUzel*)Uzel[i]->Output2)->Input=this;
  if(Uzel[i]->Output2->ID_ELEM==ID_UNIT)
   ((CUnit*)Uzel[i]->Output2)->Input=this;
 }
}
//Uzel[i]->Zapusk_Vsp_Destructor=false;
delete Uzel[i]; Uzel[i]=NULL;
}
delete []Uzel; Uzel=NULL;
if ((Kol_vo_Out>0) && (Input!=NULL))
{
 Kol_vo_Uzlov=Kol_vo_Out-1;
// Ar_Model->Memo1->Lines->Add(Kol_vo_Uzlov);
 if (Kol_vo_Uzlov>0)
 {
 Uzel= new CUzel* [Kol_vo_Uzlov];
 for(int i = 0; i<Kol_vo_Uzlov;i++)
  {
   Uzel[i]= new CUzel(this);
   if (i==0)
    {
     Uzel[i]->Input=Input;
     if(Input->ID_ELEM==ID_IN)
      ((CIn*)Input)->Output=Uzel[i];
     if(Input->ID_ELEM==ID_STDELEMENT)
      ((CStdElement*)Input)->Output=Uzel[i];
     if(Input->ID_ELEM==ID_UZEL)
      {
      if((((CUzel*)Input)->Output)==this)
      ((CUzel*)Input)->Output=Uzel[i];
      else
      ((CUzel*)Input)->Output2=Uzel[i];
      }
     if(Input->ID_ELEM==ID_UNIT)      //!!!!!!!!!!
      ((CUnit*)Input)->Svjaz_Out_s_In(this,Uzel[i]);
     if(Input->ID_ELEM==ID_SUMMATOR1)
      ((Mod_Summator*)Input)->Output=Uzel[i];
     if(Input->ID_ELEM==ID_SUMMATOR)
      ((CSummator*)Input)->Summator2->Output=Uzel[i];
     Uzel[i]->Output2=Output[i];   //----
     if(Output[i]->ID_ELEM==ID_STDELEMENT)
      ((CStdElement*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_OUT)
      ((COut*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_UZEL)
      ((CUzel*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_SUMMATOR1)
      {
      if((((Mod_Summator*)Output[i])->Input)==this)
       ((Mod_Summator*)Output[i])->Input=Uzel[i];
      else
       ((Mod_Summator*)Output[i])->Input2=Uzel[i];
      }
     if(Output[i]->ID_ELEM==ID_UNIT)
     ((CUnit*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_SUMMATOR)
      {
      if((((CSummator*)Output[i])->Summator1->Input)==this)
       ((CSummator*)Output[i])->Summator1->Input=Uzel[i];
      else if ((((CSummator*)Output[i])->Summator1->Input2)==this)
       ((CSummator*)Output[i])->Summator1->Input2=Uzel[i];
      else ((CSummator*)Output[i])->Summator2->Input2=Uzel[i];
      }

     if(Kol_vo_Uzlov==1)
      {
       Uzel[i]->Output=Output[Kol_vo_Uzlov];
       if(Uzel[i]->Output->ID_ELEM==ID_STDELEMENT)
       ((CStdElement*)Uzel[i]->Output)->Input=Uzel[i];
       if(Uzel[i]->Output->ID_ELEM==ID_OUT)
       ((COut*)Uzel[i]->Output)->Input=Uzel[i];
       if(Uzel[i]->Output->ID_ELEM==ID_UZEL)
       ((CUzel*)Uzel[i]->Output)->Input=Uzel[i];
       if(Uzel[i]->Output->ID_ELEM==ID_SUMMATOR1)
       {
        if((((Mod_Summator*)Uzel[i]->Output)->Input)==this)
         ((Mod_Summator*)Uzel[i]->Output)->Input=Uzel[i];
        else
         ((Mod_Summator*)Uzel[i]->Output)->Input2=Uzel[i];
       }
       if(Uzel[i]->Output->ID_ELEM==ID_UNIT)
        ((CUnit*)Uzel[i]->Output)->Input=Uzel[i];
       if(Uzel[i]->Output->ID_ELEM==ID_SUMMATOR)
        {
        if((((CSummator*)Uzel[i]->Output)->Summator1->Input)==this)
        ((CSummator*)Uzel[i]->Output)->Summator1->Input=Uzel[i];
        else if ((((CSummator*)Uzel[i]->Output)->Summator1->Input2)==this)
        ((CSummator*)Uzel[i]->Output)->Summator1->Input2=Uzel[i];
        else ((CSummator*)Uzel[i]->Output)->Summator2->Input2=Uzel[i];
        }
      }
    }
   else if((i>0)&&(i<Kol_vo_Uzlov-1))
    {
     Uzel[i]->Input = Uzel[i-1];
     Uzel[i-1]->Output=Uzel[i];
     Uzel[i]->Output2=Output[i];
     if(Output[i]->ID_ELEM==ID_STDELEMENT)
      ((CStdElement*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_OUT)
      ((COut*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_UZEL)
      ((CUzel*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_SUMMATOR1)
      {
      if((((Mod_Summator*)Output[i])->Input)==this)
       ((Mod_Summator*)Output[i])->Input=Uzel[i];
      else
       ((Mod_Summator*)Output[i])->Input2=Uzel[i];
      }
     if(Output[i]->ID_ELEM==ID_SUMMATOR)
      {
      if((((CSummator*)Output[i])->Summator1->Input)==this)
       ((CSummator*)Output[i])->Summator1->Input=Uzel[i];
      else if ((((CSummator*)Output[i])->Summator1->Input2)==this)
       ((CSummator*)Output[i])->Summator1->Input2=Uzel[i];
      else ((CSummator*)Output[i])->Summator2->Input2=Uzel[i];
      }
     if(Output[i]->ID_ELEM==ID_UNIT)
      ((CUnit*)Output[i])->Input=Uzel[i];
    }
   else if((i>0)&&(i==Kol_vo_Uzlov-1))
    {
     Uzel[i]->Input = Uzel[i-1];
     Uzel[i-1]->Output=Uzel[i];
     Uzel[i]->Output2=Output[i];
     if(Output[i]->ID_ELEM==ID_STDELEMENT)
      ((CStdElement*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_OUT)
      ((COut*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_UZEL)
      ((CUzel*)Output[i])->Input=Uzel[i];
     if(Output[i]->ID_ELEM==ID_SUMMATOR1)
      {
      if((((Mod_Summator*)Output[i])->Input)==this)
       ((Mod_Summator*)Output[i])->Input=Uzel[i];
      else
       ((Mod_Summator*)Output[i])->Input2=Uzel[i];
      }
     if(Output[i]->ID_ELEM==ID_SUMMATOR)
      {
      if((((CSummator*)Output[i])->Summator1->Input)==this)
       ((CSummator*)Output[i])->Summator1->Input=Uzel[i];
      else if ((((CSummator*)Output[i])->Summator1->Input2)==this)
       ((CSummator*)Output[i])->Summator1->Input2=Uzel[i];
      else ((CSummator*)Output[i])->Summator2->Input2=Uzel[i];
      }

     if(Output[i]->ID_ELEM==ID_UNIT)
      ((CUnit*)Output[i])->Input=Uzel[i];


     Uzel[i]->Output=Output[Kol_vo_Uzlov];
     if(Uzel[i]->Output->ID_ELEM==ID_STDELEMENT)
      ((CStdElement*)Uzel[i]->Output)->Input=Uzel[i];
     if(Uzel[i]->Output->ID_ELEM==ID_OUT)
      ((COut*)Uzel[i]->Output)->Input=Uzel[i];
     if(Uzel[i]->Output->ID_ELEM==ID_UZEL)
      ((CUzel*)Uzel[i]->Output)->Input=Uzel[i];
     if(Uzel[i]->Output->ID_ELEM==ID_SUMMATOR1)
      {
      if((((Mod_Summator*)Uzel[i]->Output)->Input)==this)
       ((Mod_Summator*)Uzel[i]->Output)->Input=Uzel[i];
      else
       ((Mod_Summator*)Uzel[i]->Output)->Input2=Uzel[i];
      }
     if(Uzel[i]->Output->ID_ELEM==ID_SUMMATOR)
      {
      if((((CSummator*)Uzel[i]->Output)->Summator1->Input)==this)
       ((CSummator*)Uzel[i]->Output)->Summator1->Input=Uzel[i];
      else if ((((CSummator*)Uzel[i]->Output)->Summator1->Input2)==this)
       ((CSummator*)Uzel[i]->Output)->Summator1->Input2=Uzel[i];
      else ((CSummator*)Uzel[i]->Output)->Summator2->Input2=Uzel[i];
      }
     if(Uzel[i]->Output->ID_ELEM==ID_UNIT)
      ((CUnit*)Uzel[i]->Output)->Input=Uzel[i];
    }
  }
 }
}
}
//-------------------------------------------------------------------
void CUnit::ObrPer(void)
{
for(int i = 0; i< Kol_vo_Uzlov;i++)
{
if(Uzel[i]->Input!=NULL)
 {
  if(Uzel[i]->Input->ID_ELEM==ID_STDELEMENT)
   ((CStdElement*)Uzel[i]->Input)->Output=this;
  if(Uzel[i]->Input->ID_ELEM==ID_IN)
   ((CIn*)Uzel[i]->Input)->Output=this;
  if(Uzel[i]->Input->ID_ELEM==ID_UZEL)
   {
     if((((CUzel*)Uzel[i]->Input)->Output)!=NULL)
      {
       if((((CUzel*)Uzel[i]->Input)->Output)==Uzel[i])
        ((CUzel*)Uzel[i]->Input)->Output=this;
       else
        ((CUzel*)Uzel[i]->Input)->Output2=this;
      }
   }
  if(Uzel[i]->Input->ID_ELEM==ID_SUMMATOR1)
   ((Mod_Summator*)Uzel[i]->Input)->Output=this;
  if(Uzel[i]->Input->ID_ELEM==ID_UNIT)
   {

    for(int j = 0; j<((CUnit*)Uzel[i]->Input)->Kol_vo_Out;j++)
     {
      if(((CUnit*)Uzel[i]->Input)->Output[j]==Uzel[i])
        ((CUnit*)Uzel[i]->Input)->Output[j]=this;
     }
   }
 }

if(Uzel[i]->Output!=NULL)
 {
  if(Uzel[i]->Output->ID_ELEM==ID_STDELEMENT)
   ((CStdElement*)Uzel[i]->Output)->Input=this;
  if(Uzel[i]->Output->ID_ELEM==ID_OUT)
   ((COut*)Uzel[i]->Output)->Input=this;
  if(Uzel[i]->Output->ID_ELEM==ID_SUMMATOR1)
   {
     if((((Mod_Summator*)Uzel[i]->Output)->Input)!=NULL)
      {
       if((((Mod_Summator*)Uzel[i]->Output)->Input)==Uzel[i])
        ((Mod_Summator*)Uzel[i]->Output)->Input=this;
       else
        ((Mod_Summator*)Uzel[i]->Output)->Input2=this;
      }
   }
  if(Uzel[i]->Output->ID_ELEM==ID_UZEL)
   ((CUzel*)Uzel[i]->Output)->Input=this;
  if(Uzel[i]->Output->ID_ELEM==ID_UNIT)
   ((CUnit*)Uzel[i]->Output)->Input=this;
 }

if(Uzel[i]->Output2!=NULL)
 {
  if(Uzel[i]->Output2->ID_ELEM==ID_STDELEMENT)
    ((CStdElement*)Uzel[i]->Output2)->Input=this;
  if(Uzel[i]->Output2->ID_ELEM==ID_OUT)
   ((COut*)Uzel[i]->Output2)->Input=this;
  if(Uzel[i]->Output2->ID_ELEM==ID_SUMMATOR1)
   {
     if((((Mod_Summator*)Uzel[i]->Output2)->Input)!=NULL)
      {
       if((((Mod_Summator*)Uzel[i]->Output2)->Input)==Uzel[i])
        ((Mod_Summator*)Uzel[i]->Output2)->Input=this;
       else
        ((Mod_Summator*)Uzel[i]->Output2)->Input2=this;
      }
   }
  if(Uzel[i]->Output2->ID_ELEM==ID_UZEL)
   ((CUzel*)Uzel[i]->Output2)->Input=this;
  if(Uzel[i]->Output2->ID_ELEM==ID_UNIT)
   ((CUnit*)Uzel[i]->Output2)->Input=this;
 }
delete Uzel[i]; Uzel[i]=NULL;
}
Kol_vo_Uzlov=0;
}
//-------------------------------------------------------------------
void CUnit::Svjaz_Out_s_In(  CElement *objekt, CUzel * uz)
{
for(int i = 0; i<Kol_vo_Out;i++)
 if(Output[i]==objekt)
  Output[i]=uz;
}
//-------------------------------------------------------------------
void CUnit::VICHISLENIE(int index, int end, long double DT)
{
   CElement::VICHISLENIE(index, end, DT);
if(index==0)
 {
// Y_out=0;
 if(Out) {delete [] Out; Out=NULL;}
 if(In) {delete [] In; In=NULL;}
 Out= new complex <long double>[end];
 In = new complex <long double>[end];
}
switch(Input->ID_ELEM)  //�������� ������� �� �������� �������
 {
 case ID_IN: In[index] = ((CIn*)Input)->Y_out;
                break;
 case ID_STDELEMENT: In[index] = ((CStdElement*)Input)->Y_out;
                break;
 case ID_UNIT: In[index] = ((CUnit*)Input)->Y_out;
                break;
 case ID_UZEL:  In[index] = ((CUzel*)Input)->Y_out;
                break;
 case ID_SUMMATOR1: In[index] = ((Mod_Summator*)Input)->Y_out;
                break;
 default: In[index]=complex <long double>(0.0,0.0);
                break;
 }
	Out[index]=In[index];
	Y_out=Out[index];
}
//-------------------------------------------------------------------
void CUnit::DELETE_GRAFIC_MASSIV()
{
 	Y_out=0;
 	delete []Out; Out = NULL;
 	delete []In; In = NULL;
}
void CUnit::DelInfo(void)
{
  Y_out=0;
 if(Out){delete [] Out; Out=NULL;}
 if(In){delete [] In; In=NULL;}
 if(Uzel)
 for(int i = 0; i< Kol_vo_Uzlov;i++)
  Uzel[i]->DelInfo();


}
//-------------------------------------------------------------------

void CUnit::DelLink(void *LinkPtr)
{
   if(InLink == LinkPtr)
   {
      ObrPer();
      if(Output)
        {
           delete []Output;
           Output = NULL;
        }
      InEl = NULL;
      Input = NULL;
      InLink = NULL;
      Output = new CElement*[Kol_vo_Out];
       for(int ci = 0; ci < Kol_vo_Out; ci++)
        Output[ci] = (CElement*)OutEls->Items[ci];
   }
   else
   {
   if(OutLinks->Count >= 2)
   {
        ObrPer();
        if(Output)
        {
         delete []Output;
         Output = NULL;
        }
        OutLinks->Remove(LinkPtr);
        OutEls->Remove(((CLink*)LinkPtr)->OutElSm);
        Kol_vo_Out--;
        Output = new CElement*[Kol_vo_Out];
       for(int ci = 0; ci < Kol_vo_Out; ci++)
        Output[ci] = (CElement*)OutEls->Items[ci];
        Razbivka_Sum_Uzel();
   }
   if(OutLinks->Count == 1)
   if(OutLinks->Items[0] == LinkPtr)
   {
      OutLinks->Items[0] = NULL;
      OutLinks->Clear();
   }
   }
}
//-------------------------------------------------------------------
//---------------------------------------------------------------------------
bool CIn::CheckOut(void)
{
	return (Out);
}
//-------------------------------------------------------------------
CIn::CIn(void):CElement()
{
	ID_ELEM = ID_IN;
   ID_OBJECT = ID_IN;
	Influence = CIn::iSingle;
   V1TA = 1.0;
   VLK = 1.0;
   VSinA = 1.0;
   VSinW = 0.0;
   VSinF = 0.0;
   VSA = 1.0;
   VSS = 1.0;
   VRA = 1.0;
   VRS = 1.0;
   VRandMW = 0.0;
   VRandD = 1.0;
   GradToRadians = M_PI/180.0;
   SawK = 0.0;
   VFFN = "";
   ElName = "����";
	OutLink = NULL;
   OutEl = NULL;
   Output = NULL;
	Out = NULL;
   Y_out = 0;
}
//-------------------------------------------------------------------
BOOL __fastcall CIn::OrientBusy(T_ORIENT OR)
{
	if(OutLink) if(OutLink->IN_OR == OR) return TRUE;
   return FALSE;
}
//-------------------------------------------------------------------
void CIn::VICHISLENIE(int index, int end, long double DT)
{
   CElement::VICHISLENIE(index, end, DT);
	if(index == 0)
 	{
// 		Y_out = 0;
                if(Out) {delete []Out; Out = NULL;}
 		Out = new complex<long double>[end];
 	}
	switch(Influence)
 	{
  		case CIn::iSingle: Out[index] = 1; break;
  		case CIn::iImpuls:
      {
         if(index == 0)
         	Out[index] = complex<long double>(1.0/DT, 0.0);
         else
         	Out[index] = 0;
      }
      break;
  		case CIn::iLine: Out[index] = (index - (long double)end/2.0)*DT*VLK; break;
      case CIn::iSinus:
      	Out[index] = VSinA*sin(VSinW*(long double)index*DT + VSinF*GradToRadians);
      break;
      case CIn::iSaw: Out[index] = complex<long double>(0.0, 0.0); break;
      case CIn::iRect: Out[index] = complex<long double>(0.0, 0.0); break;
      case CIn::iRand: Out[index] = RandG(VRandMW, VRandD); break;
      case CIn::iFile: Out[index] = complex<long double>(0.0, 0.0); break;
  		default: Out[index] = complex<long double>(0.0, 0.0); break;
  	}
	Y_out = Out[index];
}
//-------------------------------------------------------------------
void __fastcall CIn::SetData(void)
{
	FInProp = new TFInProp(Application);
	switch(Influence)
 	{
  		case CIn::iSingle: FInProp->RGInfluenceType->ItemIndex = 0; break;
  		case CIn::iImpuls: FInProp->RGInfluenceType->ItemIndex = 1; break;
  		case CIn::iLine: FInProp->RGInfluenceType->ItemIndex = 2; break;
  		case CIn::iSinus: FInProp->RGInfluenceType->ItemIndex = 3; break;
  		case CIn::iSaw: FInProp->RGInfluenceType->ItemIndex = 4; break;
  		case CIn::iRect: FInProp->RGInfluenceType->ItemIndex = 5; break;
  		case CIn::iRand: FInProp->RGInfluenceType->ItemIndex = 6; break;
  		case CIn::iFile: FInProp->RGInfluenceType->ItemIndex = 7; break;
   }
   FInProp->RGInfluenceTypeClick(FInProp->RGInfluenceType);
   FInProp->E1TA->Text = FloatToStr(V1TA);
   FInProp->ELK->Text = FloatToStr(VLK);
   if(GradToRadians == 1.0)
   	FInProp->RGSinCorner->ItemIndex = 1;
   else
   	FInProp->RGSinCorner->ItemIndex = 0;
   FInProp->ESinA->Text = FloatToStr(VSinA);
   FInProp->ESinW->Text = FloatToStr(VSinW);
   FInProp->ESinF->Text = FloatToStr(VSinF);
   FInProp->ESA->Text = FloatToStr(VSA);
   FInProp->ESS->Text = FloatToStr(VSS);
   FInProp->ERA->Text = FloatToStr(VRA);
   FInProp->ERS->Text = FloatToStr(VRS);
   FInProp->ERandMW->Text = FloatToStr(VRandMW);
   FInProp->ERandD->Text = FloatToStr(VRandD);
   FInProp->EFFN->Text = VFFN;
   FInProp->ShowModal();
   if(FInProp->ResultOk)
   {
		switch(FInProp->RGInfluenceType->ItemIndex)
 		{
  			case 0: Influence = CIn::iSingle; break;
  			case 1: Influence = CIn::iImpuls; break;
  			case 2: Influence = CIn::iLine; break;
  			case 3: Influence = CIn::iSinus; break;
  			case 4: Influence = CIn::iSaw; break;
  			case 5: Influence = CIn::iRect; break;
  			case 6: Influence = CIn::iRand; break;
  			case 7: Influence = CIn::iFile; break;
   	}
   	V1TA = FInProp->V1TA;
   	VLK = FInProp->VLK;
      if(FInProp->RGSinCorner->ItemIndex == 0)
   		GradToRadians = M_PI/180.0;
      else
   		GradToRadians = 1.0;
   	VSinA = FInProp->VSinA;
   	VSinW = FInProp->VSinW;
   	VSinF = FInProp->VSinF;
   	VSA = FInProp->VSA;
   	VSS = FInProp->VSS;
      if(!VSS) SawK = 0.0; else SawK = 2.0*VSA/VSS;
   	VRA = FInProp->VRA;
   	VRS = FInProp->VRS;
   	VRandMW = FInProp->VRandMW;
   	VRandD = FInProp->VRandD;
   	VFFN = FInProp->VFFN;
   }
   FInProp->Free();
}
//---------------------------------------------------------------------------
void __fastcall CIn::ShowGrp(void)
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
   FGrp->AddSer(X, Y, EndIndex);
   delete []X;
   delete []Y;
	FGrp->Show();
}
//-------------------------------------------------------------------
void CIn::DELETE_GRAFIC_MASSIV()
{
	Y_out = complex <long double>(0.0,0.0);
 	delete []Out;
   Out = NULL;
}
//-------------------------------------------------------------------
void CIn::DelLink(void *LinkPtr)
{
   if(LinkPtr == OutLink)
   {
		OutLink = NULL;
   	OutEl = NULL;
   	Output = NULL;
   }
}
//-------------------------------------------------------------------
void __fastcall CIn::GetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::GetDump(Dump, DumpSize);
   int Inf = (int)Influence;
   AddValue(Dump, DumpSize, &Inf, sizeof(int));
   AddValue(Dump, DumpSize, &V1TA, sizeof(long double));
   AddValue(Dump, DumpSize, &VLK, sizeof(long double));
   AddValue(Dump, DumpSize, &VSinA, sizeof(long double));
   AddValue(Dump, DumpSize, &VSinW, sizeof(long double));
   AddValue(Dump, DumpSize, &VSinF, sizeof(long double));
   AddValue(Dump, DumpSize, &VSA, sizeof(long double));
   AddValue(Dump, DumpSize, &VSS, sizeof(long double));
   AddValue(Dump, DumpSize, &VRA, sizeof(long double));
   AddValue(Dump, DumpSize, &VRS, sizeof(long double));
   AddValue(Dump, DumpSize, &VRandMW, sizeof(long double));
   AddValue(Dump, DumpSize, &VRandD, sizeof(long double));
   AddValue(Dump, DumpSize, &GradToRadians, sizeof(long double));
   AddValue(Dump, DumpSize, &SawK, sizeof(long double));
   int StrLen = VFFN.Length() + 1;
   AddValue(Dump, DumpSize, &StrLen, sizeof(int));
   AddValue(Dump, DumpSize, VFFN.c_str(), StrLen);
}
//-------------------------------------------------------------------
void __fastcall CIn::SetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::SetDump(Dump, DumpSize);
	int Inf = 0;
   GetValue(Dump, DumpSize, &Inf, sizeof(int));
   Influence = (TInfluence)Inf;
   GetValue(Dump, DumpSize, &V1TA, sizeof(long double));
   GetValue(Dump, DumpSize, &VLK, sizeof(long double));
   GetValue(Dump, DumpSize, &VSinA, sizeof(long double));
   GetValue(Dump, DumpSize, &VSinW, sizeof(long double));
   GetValue(Dump, DumpSize, &VSinF, sizeof(long double));
   GetValue(Dump, DumpSize, &VSA, sizeof(long double));
   GetValue(Dump, DumpSize, &VSS, sizeof(long double));
   GetValue(Dump, DumpSize, &VRA, sizeof(long double));
   GetValue(Dump, DumpSize, &VRS, sizeof(long double));
   GetValue(Dump, DumpSize, &VRandMW, sizeof(long double));
   GetValue(Dump, DumpSize, &VRandD, sizeof(long double));
   GetValue(Dump, DumpSize, &GradToRadians, sizeof(long double));
   GetValue(Dump, DumpSize, &SawK, sizeof(long double));
   int StrLen = 0;
   GetValue(Dump, DumpSize, &StrLen, sizeof(int));
   if(StrLen)
   {
   	LPSTR Str = new char[StrLen];
   	GetValue(Dump, DumpSize, Str, StrLen);
   	VFFN = Str;
   	delete []Str;
   }
   else VFFN = "";
}
void CIn::DelInfo(void)
{
 		Y_out = 0;
        if(Out){delete []Out;
      Out = NULL;}

}
//-------------------------------------------------------------------
CIn::~CIn()
{
	OutEl = NULL;
	Output = NULL;
	delete []Out;
   Out = NULL;
	Output = NULL;
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
CGaussNoise::CGaussNoise():CIn()
{
   ID_OBJECT = ID_GAUSSNOISE;
 	MathWaiting = 0.0;
 	Dispersion = 1.0;
   ElName = "���������� ���";
   FGaussNoiseProp = NULL;
}
//-------------------------------------------------------------------
void CGaussNoise::VICHISLENIE(int index, int end, long double DT)
{
   CElement::VICHISLENIE(index, end, DT);
	if(index == 0)
 	{
 		Y_out = 0;
 		delete []Out;
      Out = NULL;
 		Out = new complex<long double>[end];
 	}
	Out[index] = complex<long double>(RandG(MathWaiting, Dispersion), 0.0);
	Y_out = Out[index];
}
//-------------------------------------------------------------------
void __fastcall CGaussNoise::SetData(void)
{
	FGaussNoiseProp = new TFGaussNoiseProp(Application);
   FGaussNoiseProp->EMW->Text = FloatToStr(MathWaiting);
   FGaussNoiseProp->ED->Text = FloatToStr(Dispersion);
   FGaussNoiseProp->ShowModal();
   if(FGaussNoiseProp->ResultOk)
   {
   	MathWaiting = FGaussNoiseProp->MW;
   	Dispersion = FGaussNoiseProp->D;
   }
   FGaussNoiseProp->Free();
}
//-------------------------------------------------------------------
void __fastcall CGaussNoise::GetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::GetDump(Dump, DumpSize);
   AddValue(Dump, DumpSize, &MathWaiting, sizeof(long double));
   AddValue(Dump, DumpSize, &Dispersion, sizeof(long double));
}
//-------------------------------------------------------------------
void __fastcall CGaussNoise::SetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::SetDump(Dump, DumpSize);
   GetValue(Dump, DumpSize, &MathWaiting, sizeof(long double));
   GetValue(Dump, DumpSize, &Dispersion, sizeof(long double));
}
//-------------------------------------------------------------------
//---------------------------------------------------------------------------
bool COut::CheckOut(void)
{
	return (Y_GRAFIK);
}
//-------------------------------------------------------------------
COut::COut(void):CElement()
{
   ElName = "�����";
	InLink = NULL;
   InEl = NULL;
	Input = NULL;
   Y_GRAFIK = NULL;
	In = NULL;
	ID_ELEM = ID_OUT;
   ID_OBJECT = ID_OUT;
}
//---------------------------------------------------------------------------
void __fastcall COut::ShowGrp(void)
{
   if(!Y_GRAFIK) return;
   FGrp->Caption = GrpName + " " + ElName;
   FGrp->SetAxNames(AxXName, AxYName);
   long double *X = new long double[EndIndex];
   long double *Y = new long double[EndIndex];
   DWORD cj = 0;
   for(long double ci = 0; ci < T; ci += DT)
   {
   	X[cj] = ci;
   	Y[cj] = real(Y_GRAFIK[cj]);
      cj++;
   }
   FGrp->AddSer(X, Y, EndIndex);
   delete []X;
   delete []Y;
	FGrp->Show();
}
//-------------------------------------------------------------------
BOOL __fastcall COut::OrientBusy(T_ORIENT OR)
{
	if(InLink) if(InLink->OUT_OR == OR) return TRUE;
   return FALSE;
}
//---------------------------------------------------------------------------
void COut::VICHISLENIE(int index, int end, long double DT)
{
   CElement::VICHISLENIE(index, end, DT);
	if(index == 0)
 	{
 		if(In) {delete []In; In = NULL;}
 		if(Y_GRAFIK) {delete []Y_GRAFIK; Y_GRAFIK = NULL;}
 		In = new complex<long double>[end];
 		Y_GRAFIK = new complex<long double>[end];
 	}
	switch(Input->ID_ELEM)
 	{
 		case ID_IN: In[index] = ((CIn*)Input)->Y_out; break;
 		case ID_STDELEMENT: In[index] = ((CStdElement*)Input)->Y_out; break;
 		case ID_UNIT: In[index] = ((CUnit*)Input)->Y_out; break;
 		case ID_UZEL: In[index] = ((CUzel*)Input)->Y_out; break;
 		case ID_SUMMATOR1: In[index] = ((Mod_Summator*)Input)->Y_out; break;
 		default: In[index] = complex <long double>(0.0,0.0); break;
 	}
	Y_GRAFIK[index] = In[index];
}
//---------------------------------------------------------------------------
void COut::DELETE_GRAFIC_MASSIV()
{
 	delete []In; In = NULL;
 	delete []Y_GRAFIK; Y_GRAFIK = NULL;
}
//---------------------------------------------------------------------------
void COut::DelLink(void *LinkPtr)
{
   if(LinkPtr == InLink)
   {
		InLink = NULL;
   	InEl = NULL;
		Input = NULL;
   }
}
//---------------------------------------------------------------------------
void __fastcall COut::GetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::GetDump(Dump, DumpSize);
}
//---------------------------------------------------------------------------
void __fastcall COut::SetDump(void *&Dump, DWORD &DumpSize)
{
	CElement::SetDump(Dump, DumpSize);
}
//---------------------------------------------------------------------------
COut::~COut()
{
	delete []Y_GRAFIK; Y_GRAFIK = NULL;
	delete []In; In = NULL;
	Input = NULL;
	InEl = NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Massiv_DopSv::Massiv_DopSv(int n)
{
Konez_Mas=n;
Dop_Massiv= new CElement *[Konez_Mas];
for (int k=0; k<Konez_Mas; k++)
Dop_Massiv[k]=NULL;
pr=NULL;
}

Massiv_DopSv::~Massiv_DopSv()
{
for (int i=0; i<Konez_Mas; i++)
Dop_Massiv[i]=NULL;
delete []Dop_Massiv; Dop_Massiv=NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

Node_DopMas::Node_DopMas()
{
count_M=0;
End=NULL;
First=NULL;
Pnew=NULL;
Pold=NULL;
count_M=0;
}

Node_DopMas::~Node_DopMas()
{
Pnew=First;
while(Pnew!=NULL)
 {
 Pold=Pnew;
 Pnew=Pnew->pr;
 delete Pold; Pold=NULL;
 }
count_M=0;
}


void Node_DopMas::Add_DopMas(int N_znach)
{
if(First!=NULL)
Pnew=End;
if(count_M>0)
 {
 Pold=Pnew;
 Pnew=NULL;
 Pnew = new Massiv_DopSv(N_znach);
 Pold->pr=Pnew;
 End=Pnew;
 }
else {Pnew = new Massiv_DopSv(N_znach);
      First=Pnew; End=Pnew;}
count_M++;
}

void Node_DopMas::Add_Nachalo_Massiv(Node_DopMas* nachalo)
{
Node_DopMas* Vspomog_m = new Node_DopMas;
Pnew=First;
while(Pnew!=NULL)
 {
 Vspomog_m->Add_DopMas(Pnew->Konez_Mas);
 for(int i=0;i<Pnew->Konez_Mas;i++)
 Vspomog_m->Pnew->Dop_Massiv[i]=Pnew->Dop_Massiv[i];
 Pnew=Pnew->pr;
 }
this->~Node_DopMas();
count_M=0;
End=NULL;
First=NULL;
Pnew=NULL;
Pold=NULL;
count_M=0;
if(nachalo->First!=NULL)
 {
 nachalo->Pnew=nachalo->First;
 while(nachalo->Pnew!=NULL)
  {
  this->Add_DopMas(nachalo->Pnew->Konez_Mas);
   for(int i=0;i<nachalo->Pnew->Konez_Mas;i++)
   {
   this->Pnew->Dop_Massiv[i]=nachalo->Pnew->Dop_Massiv[i];
   }
   nachalo->Pnew=nachalo->Pnew->pr;
  }
 }

 if(Vspomog_m->First!=NULL)
 {
  Vspomog_m->Pnew=Vspomog_m->First;
  while(Vspomog_m->Pnew!=NULL)
   {
    this->Add_DopMas(Vspomog_m->Pnew->Konez_Mas);
    for(int i=0;i<Vspomog_m->Pnew->Konez_Mas;i++)
    {
     this->Pnew->Dop_Massiv[i]=Vspomog_m->Pnew->Dop_Massiv[i];
    }
    Vspomog_m->Pnew=Vspomog_m->Pnew->pr;
   }
 }
 delete Vspomog_m; Vspomog_m=NULL;
}

void Node_DopMas::Add_Konez_Masssiv(Node_DopMas* mas)
{

mas->Pnew=mas->First;
while(mas->Pnew!=NULL)
{
this->Add_DopMas(mas->Pnew->Konez_Mas);
    for(int i=0;i<mas->Pnew->Konez_Mas;i++)
    {
     this->Pnew->Dop_Massiv[i]=mas->Pnew->Dop_Massiv[i];
    }
mas->Pnew=mas->Pnew->pr;
}
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
CEls::CEls(void)
{
	CalcOrder = false;
   DT = 0.0;
	T = 0.0;
   DW = 0.0;
	W = 0.0;
   CountStep = 0;
   CurrentAdd = NULL;
   InElLnk = NULL;
	TLs = new TList;
	Sms = new TList;
	Us = new TList;
   Ls = new TList;
	Ins = new TList;
	Outs = new TList;

	Chislo_Up_Svjaz=0;
        Chislo_Dop_Svjaz=0;
        X_input=false, Y_output=false; //����� ����� ���� ��� �������� X � Y
	Dop_Svz=NULL;
	Error=NULL; // ��� ������ ���������������� ���������
	Error_NULL_Svz=NULL;ind_Up=NULL;
	Nachalo_count=0;
	Nachalo_Dvigenija=NULL;
	Obr_Sv=NULL;
	Per_Sv=NULL;
	Pob_Sv=NULL;
	Up_Svz=NULL;
	Up_Svz_Naidena=NULL;
	Vspom_Massiv = NULL;
	Kol_vo = 0;
}
//-------------------------------------------------------------------
void CEls::Add(T_ID ID_ELEM, int Left, int Top, int SX, int SY,
               void *ElDump, DWORD ElDumpSize)
{
   CStdElement *TL;
   CSummator *Sm;
   CUnit *U;
   CIn *In;
   COut *Out;
   Kol_vo++;
   switch(ID_ELEM)
   {
   	case ID_Z:
         TL = new CZ;
         TL->Create(lpDDraw, "IMZ", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                              SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
   	case ID_K:
         TL = new CK;
         TL->Create(lpDDraw, "IMK", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                              SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
   	case ID_1P:
         TL = new C1P;
         TL->Create(lpDDraw, "IM1P", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                              SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
   	case ID_FREE:
         TL = new CFree;
         TL->Create(lpDDraw, "IMFREE", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                              SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_SINUS:
         TL = new CSinus;
         TL->Create(lpDDraw, "IMSINUS", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_NOSENSE:
         TL = new CNoSense;
         TL->Create(lpDDraw, "IMNOSENSE", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_REST:
         TL = new CRest;
         ((CRest*)TL)->Create(lpDDraw, "IMREST", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                                SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_NOSENSEREST:
         TL = new CNoSenseRest;
         TL->Create(lpDDraw, "IMNOSENSEREST", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_LUFT:
         TL = new CLuft;
         TL->Create(lpDDraw, "IMLUFT", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_UBRELAY:
         TL = new CUBRelay;
         TL->Create(lpDDraw, "IMUBRELAY", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_NUBRELAY:
         TL = new CNUBRelay;
         TL->Create(lpDDraw, "IMNUBRELAY", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_P:
         TL = new CP;
         TL->Create(lpDDraw, "IMP", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_PD:
         TL = new CPD;
         TL->Create(lpDDraw, "IMPD", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_I:
         TL = new CI;
         TL->Create(lpDDraw, "IMI", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_PI:
         TL = new CPI;
         TL->Create(lpDDraw, "IMPI", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
      case ID_PID:
         TL = new CPID;
         TL->Create(lpDDraw, "IMPID", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         TLs->Add(TL);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)TL;
      break;
   	case ID_TRANSLINK:
      	TL = new CTransLink;
         TL->Create(lpDDraw, "IMTRANSLINK", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         if(ElDump)
         {
         	TL->SetDump(ElDump, ElDumpSize);
         }
         TLs->Add(TL);
         CurrentAdd = (CElement*)TL;
      break;
   	case ID_SUMMATOR:
      	Sm = new CSummator;
         Sm->Create(lpDDraw, "IMSUMMATOR", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         Sms->Add(Sm);
         if(ElDump)
         {
         	Sm->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)Sm;
      break;
   	case ID_UNIT:
      	U = new CUnit;
         U->Create(lpDDraw, "IMUNIT", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                   SX, SY);
         Us->Add(U);
         if(ElDump)
         {
         	U->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)U;
      break;
   	case ID_IN:
        Nachalo_count++;
      	In = new CIn;
         In->Create(lpDDraw, "IMIN", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         Ins->Add(In);
         if(ElDump)
         {
         	In->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)In;
         X_input=true;
      break;
      	case ID_GAUSSNOISE:
        Nachalo_count++;
      	In = new CGaussNoise;
         In->Create(lpDDraw, "IMGAUSSNOISE", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                    SX, SY);
         Ins->Add(In);
         if(ElDump)
         {
         	In->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)In;
         X_input=true;
      break;
   	case ID_OUT:
      	Out = new COut;
         Out->Create(lpDDraw, "IMOUT", Left, Top, ELEM_WIDTH, ELEM_HEIGHT,
                     SX, SY);
         Outs->Add(Out);
         if(ElDump)
         {
         	Out->SetDump(ElDump, ElDumpSize);
         }
         CurrentAdd = (CElement*)Out;
         Y_output=true;
      break;
   }
}
//-------------------------------------------------------------------
void CEls::AddLink(CElement *InEl, CElement *OutEl, T_ORIENT IN_OR, T_ORIENT OUT_OR)
{
	CElement *OutEl_output = OutEl;
	CLink *L = new CLink;
	if(OutEl_output->ID_ELEM == ID_SUMMATOR)
	{
		if((((CSummator*)OutEl_output)->Summator1->Input == NULL)||
         (((CSummator*)OutEl_output)->Summator1->Input2 == NULL))
         OutEl_output = ((CSummator*)OutEl_output)->Summator1;
    	else
      	if(((CSummator*)OutEl_output)->Summator2->Input2 == NULL)
    			OutEl_output = ((CSummator*)OutEl_output)->Summator2;
	}
	switch(InEl->ID_ELEM)
   {
   	case ID_STDELEMENT:
      	if(((CStdElement*)InEl)->OutLink)
         {
         	if(Application->MessageBox("������: ����� ��� ����������!\n�������� �?",
                                       "��������������",
                                       MB_YESNO | MB_ICONQUESTION) == IDYES)
            {
               Ls->Delete(Ls->IndexOf(((CStdElement*)InEl)->OutLink));
               delete ((CStdElement*)InEl)->OutLink;
            }
            else
            {
               delete L;
            	return;
            }
         }
      	((CStdElement*)InEl)->OutLink = L;
      	((CStdElement*)InEl)->OutEl = OutEl;
         ((CStdElement*)InEl)->Output = OutEl_output;
      break;
      case ID_SUMMATOR1:
         if(!((Mod_Summator*)InEl)->Output)
            ((Mod_Summator*)InEl)->Output = OutEl_output;
      break;
      case ID_SUMMATOR:
      	if(((CSummator*)InEl)->OutLink)
         {
         	if(Application->MessageBox("������: ����� ��� ����������!\n�������� �?",
                                       "��������������",
                                       MB_YESNO | MB_ICONQUESTION) == IDYES)
            {
               Ls->Delete(Ls->IndexOf(((CSummator*)InEl)->OutLink));
               delete ((CSummator*)InEl)->OutLink;
            }
            else
            {
               delete L;
            	return;
            }
         }
      	((CSummator*)InEl)->OutLink = L;
         if(*((CSummator*)InEl)->InversOut)
         {
         	L->InversIn = *((CSummator*)InEl)->InversOut;
            L->InversInPtr = ((CSummator*)InEl)->InversOut;
         }
         ((CSummator*)InEl)->OutEl = OutEl;
         ((CSummator*)InEl)->Summator2->Output = OutEl_output;
      break;
      case ID_UNIT:
      	((CUnit*)InEl)->AddOutLink(L, OutEl_output);
      break;
      case ID_IN:
      	if(((CIn*)InEl)->OutLink)
         {
         	if(Application->MessageBox("������: ����� ��� ����������!\n�������� �?",
                                       "��������������",
                                       MB_YESNO | MB_ICONQUESTION) == IDYES)
            {
               Ls->Delete(Ls->IndexOf(((CIn*)InEl)->OutLink));
               delete ((CIn*)InEl)->OutLink;
            }
            else
            {
               delete L;
            	return;
            }
         }
      	((CIn*)InEl)->OutLink = L;
      	((CIn*)InEl)->OutEl = OutEl;
         ((CIn*)InEl)->Output = OutEl_output;
      break;
      case ID_OUT:
      	Application->MessageBoxA("� ������� ����������� �����!", "������",
                                  MB_OK | MB_ICONERROR);
         delete L;
         return;
   }
   CElement *OE = OutEl_output;
   OutEl_output = InEl;
   if(InEl->ID_ELEM == ID_SUMMATOR)
   	OutEl_output = ((CSummator*)InEl)->Summator2;
   switch(OutEl->ID_ELEM)
   {
   	case ID_STDELEMENT:
      	if(((CStdElement*)OutEl)->InLink)
         {
         	if(Application->MessageBox("������: ����� ��� ����������!\n�������� �?",
                                       "��������������",
                                       MB_YESNO | MB_ICONQUESTION) == IDYES)
            {
               Ls->Delete(Ls->IndexOf(((CStdElement*)OutEl)->InLink));
               delete ((CStdElement*)OutEl)->InLink;
            }
            else
            {
               delete L;
               switch(InEl->ID_ELEM)
               {
               	case ID_STDELEMENT:
                  	((CStdElement*)InEl)->OutLink = NULL;
                  break;
                  case ID_SUMMATOR:
                  	((CSummator*)InEl)->OutLink = NULL;
                  break;
                  case ID_UNIT:
                  break;
                  case ID_IN:
                  	((CIn*)InEl)->OutLink = NULL;
                  break;
               }
            	return;
            }
         }
      	((CStdElement*)OutEl)->InLink = L;
      	((CStdElement*)OutEl)->InEl = InEl;
        ((CStdElement*)OutEl)->Input = OutEl_output;
      break;
      case ID_SUMMATOR:
      	if(!((CSummator*)OutEl)->InLink1)
         {
            ((CSummator*)OutEl)->InLink1 = L;
            if(*((CSummator*)OutEl)->InversIn1)
         	{
         		L->InversOut = *((CSummator*)OutEl)->InversIn1;
            	L->InversOutPtr = ((CSummator*)OutEl)->InversIn1;
         	}
            ((CSummator*)OutEl)->InEl1 = InEl;
            ((CSummator*)OutEl)->Summator1->Input = OutEl_output;
         }
         else
         	if(!((CSummator*)OutEl)->InLink2)
            {
            	((CSummator*)OutEl)->InLink2 = L;
            	if(*((CSummator*)OutEl)->InversIn2)
         		{
         			L->InversOut = *((CSummator*)OutEl)->InversIn2;
            		L->InversOutPtr = ((CSummator*)OutEl)->InversIn2;
         		}
            	((CSummator*)OutEl)->InEl2 = InEl;
                ((CSummator*)OutEl)->Summator1->Input2 = OutEl_output;
            }
         	else
         		if(!((CSummator*)OutEl)->InLink3)
               {
              		((CSummator*)OutEl)->InLink3 = L;
            		if(*((CSummator*)OutEl)->InversIn3)
         			{
         				L->InversOut = *((CSummator*)OutEl)->InversIn3;
            			L->InversOutPtr = ((CSummator*)OutEl)->InversIn3;
         			}
            		((CSummator*)OutEl)->InEl3 = InEl;
                  ((CSummator*)OutEl)->Summator2->Input2 = OutEl_output;
               }
               else
               {
         			if(Application->MessageBox("������: ����� ��� ����������!\n�������� �?",
                                       		"��������������",
                                             MB_YESNO | MB_ICONQUESTION) == IDYES)
            		{
            			Ls->Delete(Ls->IndexOf(((CSummator*)OutEl)->InLink3));
               		delete ((CSummator*)OutEl)->InLink3;
            		}
            		else
            		{
            			delete L;
               		switch(InEl->ID_ELEM)
               		{
               			case ID_STDELEMENT:
                  			((CStdElement*)InEl)->OutLink = NULL;
                  		break;
                  		case ID_SUMMATOR:
                  			((CSummator*)InEl)->OutLink = NULL;
                  		break;
                  		case ID_SUMMATOR1:
                 			break;
                  		case ID_UNIT:
                  		break;
                  		case ID_IN:
                  			((CIn*)InEl)->OutLink = NULL;
                  		break;
               		}
               		return;
            		}
              		((CSummator*)OutEl)->InLink3 = L;
              		((CSummator*)OutEl)->InEl3 = InEl;
                  ((CSummator*)OutEl)->Summator2->Input2 = OutEl_output;
               }
      break;
      case ID_SUMMATOR1:
      	if(!((Mod_Summator*)OutEl)->Input)
        		((Mod_Summator*)OutEl)->Input = OutEl_output;
        	else
           	if(!((Mod_Summator*)OutEl)->Input2)
              	((Mod_Summator*)OutEl)->Input2 = OutEl_output;
      break;
      case ID_UNIT:
      	if(((CUnit*)OutEl)->InLink)
         {
         	if(Application->MessageBox("������: ����� ��� ����������!\n�������� �?",
                                       "��������������",
                                       MB_YESNO | MB_ICONQUESTION) == IDYES)
            {
               Ls->Delete(Ls->IndexOf(((CUnit*)OutEl)->InLink));
               delete ((CUnit*)OutEl)->InLink;
            }
            else
            {
               delete L;
               switch(InEl->ID_ELEM)
               {
               	case ID_STDELEMENT:
                  	((CStdElement*)InEl)->OutLink = NULL;
                  break;
                  case ID_SUMMATOR:
                  	((CSummator*)InEl)->OutLink = NULL;
                  break;
                  case ID_UNIT:
                  break;
                  case ID_IN:
                  	((CIn*)InEl)->OutLink = NULL;
                  break;
               }
            	return;
            }
         }
      	((CUnit*)OutEl)->InLink = L;
      	((CUnit*)OutEl)->InEl = InEl;
        	((CUnit*)OutEl)->Input = OutEl_output;
      break;
      case ID_IN:
      	Application->MessageBoxA("� ������� ����������� ����!", "������",
                                  MB_OK | MB_ICONERROR);
         delete L;
         switch(InEl->ID_ELEM)
         {
         	case ID_STDELEMENT:
            	((CStdElement*)InEl)->OutLink = NULL;
            break;
         	case ID_SUMMATOR:
                 	((CSummator*)InEl)->OutLink = NULL;
            break;
            case ID_UNIT:
            break;
            case ID_IN:
            	((CIn*)InEl)->OutLink = NULL;
            break;
         }
        return;
      case ID_OUT:
      	if(((COut*)OutEl)->InLink)
         {
         	if(Application->MessageBox("������: ����� ��� ����������!\n�������� �?",
                                       "��������������",
                                       MB_YESNO | MB_ICONQUESTION) == IDYES)
            {
               Ls->Delete(Ls->IndexOf(((COut*)OutEl)->InLink));
               delete ((COut*)OutEl)->InLink;
            }
            else
            {
               delete L;
               switch(InEl->ID_ELEM)
               {
               	case ID_STDELEMENT:
                  	((CStdElement*)InEl)->OutLink = NULL;
                  break;
                  case ID_SUMMATOR:
                  	((CSummator*)InEl)->OutLink = NULL;
                  break;
                  case ID_UNIT:
                  break;
                  case ID_IN:
                  	((CIn*)InEl)->OutLink = NULL;
                  break;
               }
            	return;
            }
         }
      	((COut*)OutEl)->InLink = L;
      	((COut*)OutEl)->InEl = InEl;
        ((COut*)OutEl)->Input = OutEl_output;
      break;
   }
   L->SetSurf(lpDDS);
   L->InEl = InEl;
  	L->OutEl = OutEl;
  	L->OutElSm = OE;
   L->IN_OR = IN_OR;
   L->OUT_OR = OUT_OR;
   Ls->Add(L);
   if(InEl->ID_ELEM==ID_UNIT)
  ((CUnit*)InEl)->Razbivka_Sum_Uzel();
   if(OutEl->ID_ELEM==ID_UNIT)
   ((CUnit*)OutEl)->Razbivka_Sum_Uzel();
   OutEl_output=NULL;
}
//-------------------------------------------------------------------
void __fastcall CEls::Linking(CElement *El, T_ORIENT OR)
{
	if(!InElLnk && El)
   {
   	InElLnk = El;
      IN_OR = OR;
   }
   else
   {
   	if(InElLnk == El)
      {
      	Application->MessageBox("������: ����������� ���������� ������� � ����� �����!",
                                 "������������ ��������",
                                 MB_OK | MB_ICONERROR);

         InElLnk = NULL;
      }
      else
      {
      	if(OR != OR_BUSY && IN_OR != OR_BUSY)
   			AddLink(InElLnk, El, IN_OR, OR);
         InElLnk = NULL;
      }
   }
}
//-------------------------------------------------------------------
void CEls::Del(CElement *DelAddr)
{
   DelSvjaz=true;
   this->DELETE_SVJAZ();
   CLink *L;
   int NumUL;
   Kol_vo--;
   switch(DelAddr->ID_ELEM)
   {
   	case ID_STDELEMENT:
         if(((CStdElement*)DelAddr)->InEl)
        	if(((CStdElement*)DelAddr)->InEl->ID_ELEM==ID_UNIT)
          	{
           		((CUnit*)((CStdElement*)DelAddr)->InEl)->ObrPer();
          	}
         	if(((CStdElement*)DelAddr)->OutEl)
         		if(((CStdElement*)DelAddr)->OutEl->ID_ELEM==ID_UNIT)
          		{
           			((CUnit*)((CStdElement*)DelAddr)->OutEl)->ObrPer();
          		} 
         		TLs->Delete(TLs->IndexOf(DelAddr));
         		L = ((CStdElement*)DelAddr)->InLink;
         		if(L)
         		{
         			Ls->Delete(Ls->IndexOf(L));
            		delete L;
         		}
         		L = ((CStdElement*)DelAddr)->OutLink;
         		if(L)
         		{
            		Ls->Delete(Ls->IndexOf(L));
            		delete L;
         		}
         		delete (CStdElement*)DelAddr;
      break;
   	case ID_SUMMATOR:
         if(((CSummator*)DelAddr)->InEl1)
         if(((CSummator*)DelAddr)->InEl1->ID_ELEM==ID_UNIT)
          {
           ((CUnit*)((CSummator*)DelAddr)->InEl1)->ObrPer();
          }
         if(((CSummator*)DelAddr)->InEl2)
         if(((CSummator*)DelAddr)->InEl2->ID_ELEM==ID_UNIT)
          {
           ((CUnit*)((CSummator*)DelAddr)->InEl2)->ObrPer();
          }
         if(((CSummator*)DelAddr)->InEl3)
         if(((CSummator*)DelAddr)->InEl3->ID_ELEM==ID_UNIT)
          {
           ((CUnit*)((CSummator*)DelAddr)->InEl3)->ObrPer();
          }
         if(((CSummator*)DelAddr)->OutEl)
         if(((CSummator*)DelAddr)->OutEl->ID_ELEM==ID_UNIT)
          {
           ((CUnit*)((CSummator*)DelAddr)->OutEl)->ObrPer();
          }

         Sms->Delete(Sms->IndexOf(DelAddr));
         L = ((CSummator*)DelAddr)->InLink1;
         if(L)
         {
         	Ls->Delete(Ls->IndexOf(L));
            delete L;
         }
         L = ((CSummator*)DelAddr)->InLink2;
         if(L)
         {
         	Ls->Delete(Ls->IndexOf(L));
            delete L;
         }
         L = ((CSummator*)DelAddr)->InLink3;
         if(L)
         {
         	Ls->Delete(Ls->IndexOf(L));
            delete L;
         }
         L = ((CSummator*)DelAddr)->OutLink;
         if(L)
         {
         	Ls->Delete(Ls->IndexOf(L));
            delete L;
         }
         delete (CSummator*)DelAddr;
      break;
   	case ID_UNIT:
         if(((CUnit*)DelAddr)->InEl)
         if(((CUnit*)DelAddr)->InEl->ID_ELEM==ID_UNIT)
          {
           ((CUnit*)((CUnit*)DelAddr)->InEl)->ObrPer();
          }
         for(int ci = 0; ci < ((CUnit*)DelAddr)->OutEls->Count; ci++)
          if (((CElement*)((CUnit*)DelAddr)->OutEls->Items[ci])->ID_ELEM==ID_UNIT)
           ((CUnit*)((CUnit*)DelAddr)->OutEls->Items[ci])->ObrPer();
         ((CUnit*)DelAddr)->ObrPer();
         Us->Delete(Us->IndexOf(DelAddr));
         L = ((CUnit*)DelAddr)->InLink;
         if(L)
         {
            Ls->Delete(Ls->IndexOf(L));
            delete L;
         }
         NumUL = ((CUnit*)DelAddr)->OutLinks->Count;
        for(int ci = NumUL-1; ci >= 0; ci--)
         {
              if((CLink*)((CUnit*)DelAddr)->OutLinks->Items[ci])
               {
         	L = (CLink*)((CUnit*)DelAddr)->OutLinks->Items[ci];
         	if(L)
         	{
                Ls->Delete(Ls->IndexOf(L));
            	delete L;
         	}
         }
      }
      delete (CUnit*)DelAddr;
      break;
   	case ID_IN:
         Nachalo_count--;
         Ins->Delete(Ins->IndexOf(DelAddr));
         L = ((CIn*)DelAddr)->OutLink;
         if(L)
         {
            Ls->Delete(Ls->IndexOf(L));
            delete L;
         }

         delete (CIn*)DelAddr;
      break;
   	case ID_OUT:
         Outs->Delete(Outs->IndexOf(DelAddr));
         L = ((COut*)DelAddr)->InLink;
         if(L)
         {
            Ls->Delete(Ls->IndexOf(L));
            delete L;
         }
         delete (COut*)DelAddr;
      break;
   }
	L =NULL;
}
//-------------------------------------------------------------------
void CEls::Done(void)
{
   int ci;
   for(ci = 0; ci < Ls->Count; ci++)
   	if((CLink*)Ls->Items[ci]) delete (CLink*)Ls->Items[ci];
	Ls->Clear();
   for(ci = 0; ci < TLs->Count; ci++)
   {
       delete (CStdElement*)TLs->Items[ci];
   }
	TLs->Clear();
   for(ci = 0; ci < Sms->Count; ci++)
   {
       delete (CSummator*)Sms->Items[ci];
   }
	Sms->Clear();
   for(ci = 0; ci < Us->Count; ci++)
   {
       delete (CUnit*)Us->Items[ci];
   }
	Us->Clear();
   for(ci = 0; ci < Ins->Count; ci++)
   {
       delete (CIn*)Ins->Items[ci];
   }
	Ins->Clear();
   for(ci = 0; ci < Outs->Count; ci++)
   {
       delete (COut*)Outs->Items[ci];
   }
	Outs->Clear();
}
void CEls::DelSmInfo(void)
{

        if(Ins)
        for(int ci = 0; ci < Ins->Count; ci++)
                ((CIn*)Ins->Items[ci])->DelInfo();
        if(TLs)
        for(int ci = 0; ci < TLs->Count; ci++)
                ((CStdElement*)TLs->Items[ci])->DelInfo();
        if(Us)
        for(int ci = 0; ci < Us->Count; ci++)
                ((CUnit*)Us->Items[ci])->DelInfo();

        if(Sms)
        for(int ci = 0; ci < Sms->Count; ci++)
                ((CSummator*)Sms->Items[ci])->DelInfo();
}
//-------------------------------------------------------------------
CEls::~CEls(void)
{
   DELETE_SVJAZ();
	Done();
	Nachalo_Dvigenija = NULL;
}
//---------------------------------------------------------------------------
void  CEls::DELETE_SVJAZ()
{
	if (Up_Svz != NULL)
 	{
 		for(int j = 0; j < Chislo_Up_Svjaz; ++j)
 		{
 			delete []Up_Svz[j];
         Up_Svz[j] = NULL;
 		}
 		delete [] Up_Svz; Up_Svz=NULL;
 		delete [] ind_Up; ind_Up=NULL;
 		delete [] Error_NULL_Svz;Error_NULL_Svz=NULL;
 		delete [] Up_Svz_Naidena; Up_Svz_Naidena=NULL;
//
                 if(Dop_Svz!=NULL)
                 {
//                 for(int ci = 0; ci < Chislo_Dop_Svjaz; ci++) delete Dop_Svz[ci];
                 delete  [] Dop_Svz; Dop_Svz=NULL;
                 }
 		Chislo_Up_Svjaz=0;
      		Chislo_Dop_Svjaz=0;
 	}
}
//---------------------------------------------------------------------------
void CEls::Opredelenie_Up_Svz()
{
if((Y_output)&&(X_input))
{
this->DELETE_SVJAZ();

 ind_Up = new int [Nachalo_count];
 //ind_Up = (int*)realloc(ind_Up, Nachalo_count*sizeof(int));
 Up_Svz= new CElement **[Nachalo_count];
 Error_NULL_Svz = new bool [Nachalo_count];
 Up_Svz_Naidena = new bool [Nachalo_count];
 Dop_Svz= new Node_DopMas *[Nachalo_count];
 //Dop_Svz = (Node_DopMas**)realloc(Dop_Svz, Nachalo_count*sizeof(Node_DopMas*));
 for(int i=0;i<Nachalo_count; i++)
 {
  Chislo_Up_Svjaz=Nachalo_count;
  Chislo_Dop_Svjaz=Nachalo_count;
  Up_Svz[i]=NULL;
  Dop_Svz[i]=NULL;
  Error_NULL_Svz[i]=false;
  Up_Svz_Naidena[i]=false;
  Dop_Svz[i]=NULL;
  Error=NULL;
  this->Opredelenie_Up_Svjaz(Up_Svz[i], ind_Up[i], Error_NULL_Svz[i],
                             Up_Svz_Naidena[i], i, Dop_Svz[i]);
 }

//Memo1->Lines->Add(ind_Up[0]);

}
else
 {
 /*
 if(!X_input) ff->Memo1->Lines->Add("o���������� X");
  if(!Y_output) ff->Memo1->Lines->Add("o���������� Y");
  */
 }
}
//---------------------------------------------------------------------------
void CEls::Opredelenie_Up_Svjaz(CElement ** &Up_Svjaz, int& index_Up, bool& Error_NULL_Svjaz, bool& Up_Svjaz_Naidena, int index_Up_svz, Node_DopMas* & Dop_Svjaz)
{
if(Vspom_Massiv) {delete [] Vspom_Massiv;Vspom_Massiv=NULL;}
if(Up_Svjaz!=NULL)
{delete [] Up_Svjaz;Up_Svjaz=NULL;}
 	//Up_Svjaz = (CElement**)realloc(Up_Svjaz, 0);
index_Up=0;
Up_Svjaz_Naidena=false;
Error_NULL_Svjaz=false;
//CElement* Dvigenie = Nachalo_Dvig[index_Up_svz];
CElement* Dvigenie =(CElement*)Ins->Items[index_Up_svz];
int TRR=Kol_vo;
//ff->Memo1->Lines->Add("���-��" + IntToStr(TRR));
	Vspom_Massiv= new CElement *[TRR];
for(int i=0;i<TRR;i++)
Vspom_Massiv[i]=NULL;
bool istina=true;
index_Up=0;
while(istina)
{
Vspom_Massiv[index_Up]=Dvigenie;
index_Up++;
//ss_sv=ss_sv+Dvigenie->Identifikator;
switch(Dvigenie->ID_ELEM)
 {
 case ID_IN:
         if(((CIn*)Dvigenie)->Output!=NULL)
         {
         Dvigenie=((CIn*)Dvigenie)->Output;
         }
         else {Error_NULL_Svjaz=true;istina=false;}
         break;
 case ID_STDELEMENT:
         if(((CStdElement*)Dvigenie)->Output!=NULL)
         {
           if(((CStdElement*)Dvigenie)->Output==Error)
           {istina=false;
           //ff->Memo1->Lines->Add("����������������");
           }
           else
           Dvigenie=((CStdElement*)Dvigenie)->Output;
         }
         else {Error_NULL_Svjaz=true;istina=false;}
         break;
  case ID_UNIT:
         if(((CUnit*)Dvigenie)->Output!=NULL)
         {
           if(((CUnit*)Dvigenie)->Output[0]==Error)
           {istina=false;
           //ff->Memo1->Lines->Add("����������������");
           }
           else
           Dvigenie=((CUnit*)Dvigenie)->Output[0];
         }
         else {Error_NULL_Svjaz=true;istina=false;}
         break;

 case ID_OUT:       //���� ���� ������
         istina=false;
         Up_Svjaz_Naidena=true;
         break;
 case ID_SUMMATOR1:
         Error=Dvigenie;
         if(((Mod_Summator*)Dvigenie)->Output!=NULL)
         {Dvigenie=((Mod_Summator*)Dvigenie)->Output;
         }
         else {Error_NULL_Svjaz=true;istina=false;}
         break;
  case ID_UZEL:
          Error=NULL;
         {bool kk=false;
           CElement *Razvilka=Dvigenie;
           ((CUzel*)Dvigenie)->Output;
           ((CUzel*)Dvigenie)->Output2;
          if(((CUzel*)Dvigenie)->Output!=NULL)
           {
           Dvigenie=((CUzel*)Razvilka)->Output;
           if (Rekursija_Uzel(Up_Svjaz,index_Up,Dvigenie,index_Up,Error_NULL_Svjaz,Up_Svjaz_Naidena)) istina=false;
           else kk=true;
           }
          else {Error_NULL_Svjaz=true;istina=false;}
          if(kk)
           {
           if(((CUzel*)Razvilka)->Output2!=NULL)
           {Dvigenie=((CUzel*)Razvilka)->Output2;
           Rekursija_Uzel(Up_Svjaz,index_Up,Dvigenie,index_Up,Error_NULL_Svjaz,Up_Svjaz_Naidena); istina=false;}
           else {Error_NULL_Svjaz=true;istina=false;}
           }
         }
         break;

    default:
          break;
 }
}
 if(Up_Svjaz_Naidena)
 {
 	//ff->Memo1->Lines->Add("������� �����");
 	Up_Svjaz= new CElement *[index_Up];
 	//Up_Svjaz = (CElement**)realloc(Up_Svjaz, index_Up*sizeof(CElement*));
 	for (int i=0; i<index_Up; i++)
  	{
  		Up_Svjaz[i]=Vspom_Massiv[i];
  		Vspom_Massiv[i]=NULL;
 	 	delete Vspom_Massiv[i];Vspom_Massiv[i]=NULL;

  	}
 }
 else
 {
 	Up_Svjaz = NULL;
   index_Up = 0;
 }
 if(Vspom_Massiv) {delete []Vspom_Massiv; Vspom_Massiv=NULL;}
	Opredelenie_Pobochn_Svjaz(Up_Svjaz, index_Up,Error_NULL_Svjaz, Up_Svjaz_Naidena,index_Up_svz, Dop_Svjaz);
}
//---------------------------------------------------------------------------

bool CEls::Rekursija_Uzel(CElement ** &Up_Svjaz, int& index_Up, CElement *Dvigenie, int index2, bool& Error_NULL_Svjaz, bool& Up_Svjaz_Naidena)
{
bool istin1=true;
while(istin1)
{
if(Dvigenie!=NULL)
for (int i=0; i<index2; i++)
{
if (Vspom_Massiv[i]==Dvigenie)
return false;
}
else return false;
Vspom_Massiv[index2]=Dvigenie;
index2++;
switch(Dvigenie->ID_ELEM)
 {
 case ID_IN:
         if(((CIn*)Dvigenie)->Output!=NULL)
         {
         Dvigenie=((CIn*)Dvigenie)->Output;
         }
         else {Error_NULL_Svjaz=true;istin1=false;}
         break;
 case ID_STDELEMENT:
         if(((CStdElement*)Dvigenie)->Output!=NULL)
         {Dvigenie=((CStdElement*)Dvigenie)->Output;
         }
         else {Error_NULL_Svjaz=true;istin1=false;}
         break;
  case ID_UNIT:
         if(((CUnit*)Dvigenie)->Output!=NULL)
         {Dvigenie=((CUnit*)Dvigenie)->Output[0];
         }
         else {Error_NULL_Svjaz=true;istin1=false;}
         break;
 case ID_OUT:
         istin1=false;
         Up_Svjaz_Naidena=true;
         index_Up=index2;
         break;
 case ID_SUMMATOR1:
         if(((Mod_Summator*)Dvigenie)->Output!=NULL)
         {Dvigenie=((Mod_Summator*)Dvigenie)->Output;
         }
         else {Error_NULL_Svjaz=true;istin1=false;}
         break;
  case ID_UZEL:
         {bool kk=false;
           CElement *Razvilka=Dvigenie;
          if(((CUzel*)Dvigenie)->Output!=NULL)
           {
           Dvigenie=((CUzel*)Razvilka)->Output;
           if(Rekursija_Uzel(Up_Svjaz, index_Up,Dvigenie,index2,Error_NULL_Svjaz,Up_Svjaz_Naidena)) istin1=false;
           else kk=true;
           }
          else {Error_NULL_Svjaz=true;istin1=false;}
          if(kk)
           {
           if(((CUzel*)Razvilka)->Output2!=NULL)
            {Dvigenie=((CUzel*)Razvilka)->Output2;
            Rekursija_Uzel(Up_Svjaz, index_Up,Dvigenie,index2,Error_NULL_Svjaz,Up_Svjaz_Naidena); istin1=false;
            }
           else {Error_NULL_Svjaz=true;istin1=false;}
           }
         }
         break;
     default:
          break;
 }
}
if(Up_Svjaz_Naidena) return true;
else return false;
}

void CEls::RASCHET_SISTEM()
{
DelSmInfo();
	int Kol_index = int(T/DT) + 2;
for(int cout = 0.0; cout < Kol_index; cout++)
{
for(int j=0; j<Nachalo_count; j++)
 {
 if((Up_Svz_Naidena[j])&&(!Error_NULL_Svz[j]))
  {
    Dop_Svz[j]->Pnew=Dop_Svz[j]->First;
    for(int i=0; i<ind_Up[j]; i++)
    {
     if((Up_Svz[j][i]->ID_ELEM)==ID_UZEL)
      {
      while(Dop_Svz[j]->Pnew->Dop_Massiv[0]==Up_Svz[j][i])
       {
       for(int jj=0; jj<Dop_Svz[j]->Pnew->Konez_Mas; jj++)
        {
         Dop_Svz[j]->Pnew->Dop_Massiv[jj]->VICHISLENIE(cout, Kol_index, DT);
        }
       Dop_Svz[j]->Pnew=Dop_Svz[j]->Pnew->pr;
       if (Dop_Svz[j]->Pnew==NULL) break;
       }
      }
     else
      Up_Svz[j][i]->VICHISLENIE(cout, Kol_index, DT);
    }
   }
  }
 }
}

void CEls::RASCHET_SISTEM_STEP()
{
	int Kol_index = T/DT + 2;
	if(CountStep >= Kol_index) return;
for(int j=0; j<Nachalo_count; j++)
 {
 if((Up_Svz_Naidena[j])&&(!Error_NULL_Svz[j]))
  {
    Dop_Svz[j]->Pnew=Dop_Svz[j]->First;
    for(int i=0; i<ind_Up[j]; i++)
    {
     if((Up_Svz[j][i]->ID_ELEM)==ID_UZEL)
      {
      while(Dop_Svz[j]->Pnew->Dop_Massiv[0]==Up_Svz[j][i])
       {
       for(int jj=0; jj<Dop_Svz[j]->Pnew->Konez_Mas; jj++)
        {
         Dop_Svz[j]->Pnew->Dop_Massiv[jj]->VICHISLENIE(CountStep, Kol_index, DT);
        }
       Dop_Svz[j]->Pnew=Dop_Svz[j]->Pnew->pr;
       if (Dop_Svz[j]->Pnew==NULL) break;
       }
      }
     else
      Up_Svz[j][i]->VICHISLENIE(CountStep, Kol_index, DT);
    }
   }
  }
CountStep++;
// }
}
//---------------------------------------------------------------------------
void CEls::Opredelenie_Pobochn_Svjaz(CElement ** &Up_Svjaz, int& index_Up, bool& Error_NULL_Svjaz, bool& Up_Svjaz_Naidena, int index_Up_svz,Node_DopMas* & Dop_Svjaz)
{
Error_NULL_Svjaz=false;
//Kol_voDop_Sv=0;
delete Dop_Svjaz; Dop_Svjaz=NULL;
if(Up_Svjaz_Naidena)
 {//��������������� ������
 int Max_Ob=Kol_vo;
 Vspom_Massiv= new CElement *[Max_Ob];
 for(int i=0;i<Max_Ob;i++)
 Vspom_Massiv[i]=NULL;
 Dop_Svjaz=new Node_DopMas;
// Dop_Svz[index_Up_svz]=new Node_DopMas;
 for(int i=0;i<index_Up; i++) //�������� �� �����
  {
  if(Error_NULL_Svjaz) break;
  if(Up_Svjaz[i]->ID_ELEM==ID_UZEL)  //������ ����������� �������� ������
   {
    Vspom_Massiv[0]=Up_Svjaz[i];
    if ((((CUzel*)Up_Svjaz[i])->Output)==Up_Svjaz[i+1])// ������ ���� �� �������� �����
     {
      if((((CUzel*)Up_Svjaz[i])->Output2)!=NULL)
       {
        Obr_Sv=new Node_DopMas;
        Per_Sv=new Node_DopMas;
        Pob_Sv=new Node_DopMas;
        Rekursija_Pobochn(Up_Svjaz,index_Up,(((CUzel*)Up_Svjaz[i])->Output2),i, 1, Error_NULL_Svjaz, Up_Svjaz_Naidena);
        Dop_Svjaz->Add_Konez_Masssiv(Pob_Sv);
        Dop_Svjaz->Add_Konez_Masssiv(Obr_Sv);
        Dop_Svjaz->Add_Konez_Masssiv(Per_Sv);
        delete Pob_Sv; Pob_Sv=NULL;
        delete Per_Sv; Per_Sv=NULL;
        delete Obr_Sv; Obr_Sv=NULL;
       }
      else
      Error_NULL_Svjaz=true;
     }
    else
     if ((((CUzel*)Up_Svjaz[i])->Output2)==Up_Svjaz[i+1])
     {
      if((((CUzel*)Up_Svjaz[i])->Output)!=NULL)
       {
        Obr_Sv=new Node_DopMas;
        Per_Sv=new Node_DopMas;
        Pob_Sv=new Node_DopMas;
        Rekursija_Pobochn(Up_Svjaz,index_Up,(((CUzel*)Up_Svjaz[i])->Output),i, 1,Error_NULL_Svjaz, Up_Svjaz_Naidena);
        Dop_Svjaz->Add_Konez_Masssiv(Pob_Sv);
        Dop_Svjaz->Add_Konez_Masssiv(Obr_Sv);
        Dop_Svjaz->Add_Konez_Masssiv(Per_Sv);
        delete Pob_Sv; Pob_Sv=NULL;
        delete Per_Sv; Per_Sv=NULL;
        delete Obr_Sv; Obr_Sv=NULL;
       }
      else
      Error_NULL_Svjaz=true;
     }
     //if(Error_NULL_Svjaz)
    //ff->Memo1->Lines->Add("��������");
   else
    {
//    ff->Memo1->Lines->Add(IntToStr(Kol_voDop_Sv)+"hhh");
       if(Dop_Svjaz!=NULL)
        {
         Dop_Svjaz->Pnew=Dop_Svjaz->First;
          AnsiString str="";
          while(Dop_Svjaz->Pnew!=NULL)
           {
            str="";
            for(int ii=0;ii<Dop_Svjaz->Pnew->Konez_Mas;ii++)
             {
//              str=str+Dop_Svjaz->Pnew->Dop_Massiv[ii]->Identifikator;
             }
            //ff->Memo1->Lines->Add("ffgfg"+str);
            Dop_Svjaz->Pnew=Dop_Svjaz->Pnew->pr;
           }
        }
    }
   }
  }
 for(int i=0;i<Max_Ob;i++)
 Vspom_Massiv[i]=NULL;
 delete [] Vspom_Massiv; Vspom_Massiv=NULL;
 }
}

//---------------------------------------------------------------------------
bool CEls::Rekursija_Pobochn(CElement ** &Up_Svjaz, int& index_Up, CElement *dvigen, int do_ind, int index_mas, bool& Error_NULL_Svjaz, bool& Up_Svjaz_Naidena)
{
bool istin2=true;
if(!Error_NULL_Svjaz)
{
//����������� ���� ����������� �����
while(istin2)
 {
  Vspom_Massiv[index_mas]=dvigen;
  for(int i=0;i<index_Up; i++)
   if(dvigen==Up_Svjaz[i])
                {
  if(CalcOrder) // c �����������
    {
                 if (i>do_ind)
                   {
                    Per_Sv->Add_DopMas(index_mas+1);
                    for(int j=0;j<Per_Sv->Pnew->Konez_Mas; j++)
                     Per_Sv->Pnew->Dop_Massiv[j]=Vspom_Massiv[j];
                    }
                   else
                    {

                     int sssch=1;
                     Obr_Sv->Add_DopMas(index_mas+do_ind-i+1);
                      for(int j=0;j<(index_mas+1); j++)
                      {
                       Obr_Sv->Pnew->Dop_Massiv[j]=Vspom_Massiv[j];
                      }
                      for(int j=index_mas+1;j<=(index_mas+do_ind-i); j++)
                      {
                       Obr_Sv->Pnew->Dop_Massiv[j]=Up_Svjaz[i+sssch];
                       sssch++;
                      }
                    }
      }//
      else //��� ����������
      {
                    Per_Sv->Add_DopMas(index_mas+1);
                    for(int j=0;j<Per_Sv->Pnew->Konez_Mas; j++)
                    Per_Sv->Pnew->Dop_Massiv[j]=Vspom_Massiv[j];
      }
                   istin2=false; break;

                }

   switch(dvigen->ID_ELEM)
    {
     case ID_STDELEMENT:
          if(((CStdElement*)dvigen)->Output!=NULL)
           dvigen=((CStdElement*)dvigen)->Output;
           else {istin2=false; Error_NULL_Svjaz=true;}
          break;
     case ID_UNIT:
           if(((CUnit*)dvigen)->Output!=NULL)
           dvigen=((CUnit*)dvigen)->Output[0];
           else {istin2=false; Error_NULL_Svjaz=true;}
         break;


     case ID_OUT:
          if(dvigen!=Up_Svjaz[index_Up-1])
           { Per_Sv->Add_DopMas(index_mas+1);
             for(int j=0;j<Per_Sv->Pnew->Konez_Mas; j++)
             {
             Per_Sv->Pnew->Dop_Massiv[j]=Vspom_Massiv[j];
             }
//             Kol_voDop_Sv++;
             istin2=false;
           }
          break;
    case ID_UZEL:
          {
           CElement *Razvilka = dvigen;
           if(((CUzel*)Razvilka)->Output!=NULL)
           {
           dvigen=((CUzel*)Razvilka)->Output;
           Rekursija_Pobochn(Up_Svjaz,index_Up,dvigen,do_ind, index_mas+1, Error_NULL_Svjaz, Up_Svjaz_Naidena);
           }
           else {Error_NULL_Svjaz=true;}
           if(!Error_NULL_Svjaz)
           if(((CUzel*)Razvilka)->Output2!=NULL)
           {
           dvigen=((CUzel*)Razvilka)->Output2;
           Rekursija_Pobochn(Up_Svjaz,index_Up,dvigen,do_ind, index_mas+1, Error_NULL_Svjaz, Up_Svjaz_Naidena);
           }
           else {Error_NULL_Svjaz=true;}
           Razvilka=NULL;istin2=false;
          }
          break;
    case ID_SUMMATOR1:
          {
           bool Sum_Naiden=false; // ��� ����������� ��������� ��������� � ��� �����
           for(int j=0;j<index_mas-1; j++)
            if(Vspom_Massiv[j]==dvigen) Sum_Naiden=true;
             if(Sum_Naiden)
             {

                 Pob_Sv->Add_DopMas(index_mas+1);
                 for(int j=0;j<Pob_Sv->Pnew->Konez_Mas; j++)
                 Pob_Sv->Pnew->Dop_Massiv[j]=Vspom_Massiv[j];
                 //Kol_voDop_Sv++;
                 istin2=false; break;
             }
             else
             {
               if(((Mod_Summator*)dvigen)->Output!=NULL)
                dvigen=((Mod_Summator*)dvigen)->Output;
               else {istin2=false; Error_NULL_Svjaz=true;}
             }
          }
          break;
     default:
          break;
    }
 index_mas++;
 }
}
return Error_NULL_Svjaz;
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
