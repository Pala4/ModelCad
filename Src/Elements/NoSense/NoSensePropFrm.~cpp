//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "NoSensePropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFNoSenseProp::TFNoSenseProp(TComponent* Owner)
	                      :TForm(Owner)
{
	ResultOk = false;
   LA->Hint = "Диапазон изменений входной величины,\nкоторый не воспринимается элементом";
   LK->Hint = "Величина показывающая во сколько раз\nвыходной сигнал больше входного";
   LdX->Hint = "Смещение графика нелинейности по оси абсцисс\nотносительно начала координат";
   LdY->Hint = "Смещение графика нелинейности по оси ординат\nотносительно начала координат";
}
//---------------------------------------------------------------------------
void __fastcall TFNoSenseProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFNoSenseProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EA;
   	A = StrToFloat(EA->Text);
      Ex = EK;
   	K = StrToFloat(EK->Text);
      Ex = EdX;
   	dX = StrToFloat(EdX->Text);
      Ex = EdY;
   	dY = StrToFloat(EdY->Text);
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
void __fastcall TFNoSenseProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
   Close();
}
//---------------------------------------------------------------------------
