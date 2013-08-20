//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "KPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFKProp::TFKProp(TComponent* Owner)
	                :TForm(Owner)
{
	ResultOk = false;
   LK->Hint = "Величина показывающая во сколько раз\nвыходной сигнал больше входного";
}
//---------------------------------------------------------------------------
void __fastcall TFKProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFKProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EK;
   	K = StrToFloat(EK->Text);
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
void __fastcall TFKProp::BtCancelClick(TObject *Sender)
{
   ResultOk = false;
	Close();
}
//---------------------------------------------------------------------------
