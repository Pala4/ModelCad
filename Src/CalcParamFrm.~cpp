//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CalcParamFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFCalcParam::TFCalcParam(TComponent *Owner)
	                    :TForm(Owner)
{
   ResultOk = false;
	DT = 0.0;
   T = 0.0;
   DW = 0.0;
   W = 0.0;
}
//---------------------------------------------------------------------------
void __fastcall TFCalcParam::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFCalcParam::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EDT;
   	DT = StrToFloat(EDT->Text);
      Ex = ET;
   	T = StrToFloat(ET->Text);
      Ex = EDW;
   	DW = StrToFloat(EDW->Text);
      Ex = EW;
   	W = StrToFloat(EW->Text);
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
void __fastcall TFCalcParam::BtCancelClick(TObject *Sender)
{
   ResultOk = false;
	Close();
}
//---------------------------------------------------------------------------
