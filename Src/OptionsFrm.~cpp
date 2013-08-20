//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <math.h>

#include "OptionsFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#define DEFAULT_FIELD_COLOR COLOR_BTNFACE
#define DEFAULT_GRID_COLOR 0x00000000
//---------------------------------------------------------------------------
__fastcall TFOptions::TFOptions(TComponent* Owner):TForm(Owner)
{
	EFieldColor->Text =
   	EFieldColor->Text.sprintf("%X", DEFAULT_FIELD_COLOR);
   EGridColor->Text =
   	EGridColor->Text.sprintf("%X", DEFAULT_GRID_COLOR);
   EFieldColor->OnKeyPress = EColorKeyPress;
   EGridColor->OnKeyPress = EColorKeyPress;
}
//---------------------------------------------------------------------------
void __fastcall TFOptions::EColorKeyPress(TObject *Sender, char &Key)
{
	Set  <char, 0, 255> Dig;
   Dig << '0' << '1' << '2' << '3' << '4';
   Dig << '5' << '6' << '7' << '8' << '9';
   Dig << 'A' << 'B' << 'C' << 'D' << 'E' << 'F';
   Dig << 'a' << 'b' << 'c' << 'd' << 'e' << 'f' << VK_BACK;
	if (!Dig.Contains(Key)) Key = 0;
}
//---------------------------------------------------------------------------
long TFOptions::StrHexToInt(AnsiString HexText, BYTE StartIndex)
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
void __fastcall TFOptions::BtChColorClick(TObject *Sender)
{
   if(Sender == BtChFieldColor)
   	CDlgView->Color = (TColor)StrHexToInt(EFieldColor->Text, 1);
   if(Sender == BtChGridColor)
   	CDlgView->Color = (TColor)StrHexToInt(EGridColor->Text, 1);
	CDlgView->Execute();
   if(Sender == BtChFieldColor)
   {
      EFieldColor->Clear();
  		EFieldColor->Text =
   		EFieldColor->Text.sprintf("%X", CDlgView->Color);
   }
   if(Sender == BtChGridColor)
   {
      EGridColor->Clear();
   	EGridColor->Text =
   		EGridColor->Text.sprintf("%X", CDlgView->Color);
   }
}
//---------------------------------------------------------------------------
void __fastcall TFOptions::BtDefaultClick(TObject *Sender)
{
   if(Sender == BtFCDefault)
   {
      EFieldColor->Clear();
  		EFieldColor->Text =
   		EFieldColor->Text.sprintf("%X", DEFAULT_FIELD_COLOR);
   }
   if(Sender == BtGCDefault)
   {
      EGridColor->Clear();
   	EGridColor->Text =
   		EGridColor->Text.sprintf("%X", DEFAULT_GRID_COLOR);
   }
}
//---------------------------------------------------------------------------
