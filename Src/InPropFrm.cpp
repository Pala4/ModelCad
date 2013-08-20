//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "InPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TFInProp::ShowImage(int Index)
{
   if(ImCurVisible) ImCurVisible->Visible = false;
   switch(Index)
   {
   	case 0: Im1T->Visible = true; ImCurVisible = Im1T; break;
   	case 1: Im1D->Visible = true; ImCurVisible = Im1D; break;
   	case 2: ImLine->Visible = true; ImCurVisible = ImLine; break;
   	case 3: ImSin->Visible = true; ImCurVisible = ImSin; break;
   	case 4: ImSaw->Visible = true; ImCurVisible = ImSaw; break;
   	case 5: ImRect->Visible = true; ImCurVisible = ImRect; break;
   	case 6: ImRandom->Visible = true; ImCurVisible = ImRandom; break;
   }
}
//---------------------------------------------------------------------------
__fastcall TFInProp::TFInProp(TComponent *Owner):TForm(Owner)
{
	ResultOk = false;
   V1TA = 1.0;
   VSinA = 1.0;
   VSinW = 0.0;
   VSinF = 0.0;
   VSA = 1.0;
   VSS = 1.0;
   VRA = 1.0;
   VRS = 1.0;
   VRandMW = 0.0;
   VRandD = 1.0;
   VFFN = "";
   ImCurVisible = NULL;
   ShowImage(0);
}
//---------------------------------------------------------------------------
void __fastcall TFInProp::RGInfluenceTypeClick(TObject *Sender)
{
	PCInProp->ActivePageIndex = ((TRadioGroup*)Sender)->ItemIndex;
   ShowImage(((TRadioGroup*)Sender)->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TFInProp::EKeyPress(TObject *Sender, char &Key)
{
   TEdit *E = dynamic_cast<TEdit*>(Sender);
   if(E)
   {
 		if((Key == '.')||(Key == ',')) Key = DecimalSeparator;
 		if(!(isdigit(Key) || (Key == 8)||
         ((Key == '-') && (E->SelStart == 0))||
         ((Key == DecimalSeparator)&&
         (!strchr(E->Text.c_str(), DecimalSeparator)))))
      Key = 0;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFInProp::RGSinCornerClick(TObject *Sender)
{
	if(((TRadioGroup*)Sender)->ItemIndex == 0)
   	LSinF->Caption = "Фаза F (град.):";
   else
   	LSinF->Caption = "Фаза F (рад.):";
}
//---------------------------------------------------------------------------
void __fastcall TFInProp::BtFFNClick(TObject *Sender)
{
  	if(OpDlgFN->Execute()) EFFN->Text = OpDlgFN->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TFInProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
   	switch(RGInfluenceType->ItemIndex)
      {
      	case 0:
            Ex = E1TA;
            if(E1TA->Text == "") E1TA->Text = 0;
         	V1TA = StrToFloat(E1TA->Text);
         break;
      	case 2:
            Ex = ELK;
            if(ELK->Text == "") ELK->Text = 0;
         	VLK = StrToFloat(ELK->Text);
         break;
      	case 3:
            Ex = ESinA;
            if(ESinA->Text == "") ESinA->Text = 0;
         	VSinA = StrToFloat(ESinA->Text);
            Ex = ESinW;
            if(ESinW->Text == "") ESinW->Text = 0;
         	VSinW = StrToFloat(ESinW->Text);
            Ex = ESinF;
            if(ESinF->Text == "") ESinF->Text = 0;
         	VSinF = StrToFloat(ESinF->Text);
         break;
      	case 4:
            Ex = ESA;
            if(ESA->Text == "") ESA->Text = 0;
         	VSA = StrToFloat(ESA->Text);
            Ex = ESS;
            if(ESS->Text == "") ESS->Text = 0;
         	VSS = StrToFloat(ESS->Text);
         break;
      	case 5:
            Ex = ERA;
            if(ERA->Text == "") ERA->Text = 0;
         	VRA = StrToFloat(ERA->Text);
            Ex = ERS;
            if(ERS->Text == "") ERS->Text = 0;
         	VRS = StrToFloat(ERS->Text);
         break;
      	case 6:
            Ex = ERandMW;
            if(ERandMW->Text == "") ERandMW->Text = 0;
         	VRandMW = StrToFloat(ERandMW->Text);
            Ex = ERandD;
            if(ERandD->Text == "") ERandD->Text = 0;
         	VRandD = StrToFloat(ERandD->Text);
         break;
      	case 7:
         	VFFN = EFFN->Text;
            if(VFFN != "")
            	if(!FileExists(VFFN))
            	{
      				Application->MessageBoxA("Файл с таким именем не существует",
                                           "File I/O Error",
                                           MB_OK | MB_ICONERROR);
      				EFFN->SetFocus();
   					return;
            	}
         break;
      }
   }
   catch(...)
   {
      Application->MessageBoxA("Неверный формат числа", "Floating Poitn Error",
                               MB_OK | MB_ICONERROR);
      Ex->SetFocus();
   	return;
   }
	ResultOk = true;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFInProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
	Close();
}
//---------------------------------------------------------------------------
