//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <math.h>

#include "PropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#define DEFAULT_FIELD_COLOR 0x00FFFFFF
#define DEFAULT_AXIS_COLOR 0x00000000
//---------------------------------------------------------------------------
void __fastcall TFProperty::SetAdvabced(TOnAdvanced AOnAdvanced)
{
	FOnAdvanced = AOnAdvanced;
   BtAdvanced->Enabled = (FOnAdvanced);
}
//---------------------------------------------------------------------------
__fastcall TFProperty::TFProperty(TComponent *Owner)
	                   : TForm(Owner)
{
   ResultOk = false;
   NumSers = -1;
   OnAdvanced = NULL;
   EAxColor->Text =
   	EAxColor->Text.sprintf("%X", DEFAULT_AXIS_COLOR);
	EFColor->Text =
   	EFColor->Text.sprintf("%X", DEFAULT_FIELD_COLOR);
   EFColor->OnKeyPress = EColorKeyPress;
   EAxColor->OnKeyPress = EColorKeyPress;
}
//---------------------------------------------------------------------------
void __fastcall TFProperty::EColorKeyPress(TObject *Sender, char &Key)
{
	Set  <char, 0, 255> Dig;
   Dig << '0' << '1' << '2' << '3' << '4';
   Dig << '5' << '6' << '7' << '8' << '9';
   Dig << 'A' << 'B' << 'C' << 'D' << 'E' << 'F';
   Dig << 'a' << 'b' << 'c' << 'd' << 'e' << 'f' << VK_BACK;
	if (!Dig.Contains(Key)) Key = 0;
}
//---------------------------------------------------------------------------
long  __fastcall TFProperty::StrHexToInt(AnsiString HexText, BYTE StartIndex)
{
   long result = 0;
   BYTE Dec;
	for(int ci = StartIndex; ci <= HexText.Length(); ci++)
   {
      switch(HexText[ci])
      {
         case 'a':
      	case 'A': Dec = 10; break;
         case 'b':
         case 'B': Dec = 11; break;
         case 'c':
         case 'C': Dec = 12; break;
         case 'd':
         case 'D': Dec = 13; break;
         case 'e':
         case 'E': Dec = 14; break;
         case 'f':
         case 'F': Dec = 15; break;
         default: Dec = BYTE(HexText[ci] - 48);
      }
      result += Dec*pow(16, HexText.Length()-ci);
   }
   return result;
}
//---------------------------------------------------------------------------
void __fastcall TFProperty::BtColorClick(TObject *Sender)
{
   if(Sender == BtFColor)
   	CDlgProp->Color = (TColor)StrHexToInt(EFColor->Text, 1);
   if(Sender == BtAxColor)
   	CDlgProp->Color = (TColor)StrHexToInt(EAxColor->Text, 1);
	CDlgProp->Execute();
   if(Sender == BtFColor)
   {
      EFColor->Clear();
  		EFColor->Text =
   		EFColor->Text.sprintf("%X", CDlgProp->Color);
   }
   if(Sender == BtAxColor)
   {
      EAxColor->Clear();
   	EAxColor->Text =
   		EAxColor->Text.sprintf("%X", CDlgProp->Color);
   }
}
//---------------------------------------------------------------------------
void __fastcall TFProperty::BtDefaultClick(TObject *Sender)
{
   if(Sender == BtFCDefault)
   {
      EFColor->Clear();
  		EFColor->Text =
   		EFColor->Text.sprintf("%X", DEFAULT_FIELD_COLOR);
   }
   if(Sender == BtAxCDefault)
   {
      EAxColor->Clear();
   	EAxColor->Text =
   		EAxColor->Text.sprintf("%X", DEFAULT_AXIS_COLOR);
   }
}
//---------------------------------------------------------------------------
void __fastcall TFProperty::BtAdvancedClick(TObject *Sender)
{
	if(FOnAdvanced) FOnAdvanced();
}
//---------------------------------------------------------------------------
void __fastcall TFProperty::CBxSaveSersClick(TObject *Sender)
{
	LNumSers->Enabled = CBxSaveSers->Checked;
   ENumSers->Enabled = CBxSaveSers->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFProperty::ENumSersKeyPress(TObject *Sender, char &Key)
{
   TEdit *E = dynamic_cast<TEdit*>(Sender);
   if(E)
   {
 		//if((Key == '.')||(Key == ',')) Key = DecimalSeparator;
 		if(!(isdigit(Key) || (Key == 8)||
         ((Key == '-') && (E->SelStart == 0))/*||
         ((Key == DecimalSeparator)&&
         (!strchr(E->Text.c_str(), DecimalSeparator)))*/))
      Key = 0;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFProperty::BtOKClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = ENumSers;
   	NumSers = StrToFloat(ENumSers->Text);
      if(NumSers < -1) NumSers = -1;
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
void __fastcall TFProperty::BtCancelClick(TObject *Sender)
{
   ResultOk = false;
	Close();
}
//---------------------------------------------------------------------------
