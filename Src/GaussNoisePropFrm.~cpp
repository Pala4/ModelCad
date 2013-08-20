//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GaussNoisePropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFGaussNoiseProp::TFGaussNoiseProp(TComponent *Owner):TForm(Owner)
{
	ResultOk = false;
   LMW->Hint = "Среднее арифметическое всех значений\nслучайной последовательности";
   LD->Hint = "Разброс значений случайной последовательности\nотносительно математического ожидания";
}
//---------------------------------------------------------------------------
void __fastcall TFGaussNoiseProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFGaussNoiseProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EMW;
   	MW = StrToFloat(EMW->Text);
      Ex = ED;
   	D = StrToFloat(ED->Text);
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
void __fastcall TFGaussNoiseProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
	Close();
}
//---------------------------------------------------------------------------
