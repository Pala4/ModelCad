//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UBRelayFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFUBRelayProp::TFUBRelayProp(TComponent* Owner)
	                      :TForm(Owner)
{
	ResultOk = false;
   LB->Hint = "Диапазон изменений выходной величины,\nкоторый не ограничивается элементом";
   LdX->Hint = "Смещение графика нелинейности по оси абсцисс\nотносительно начала координат";
   LdY->Hint = "Смещение графика нелинейности по оси ординат\nотносительно начала координат";
}
//---------------------------------------------------------------------------
void __fastcall TFUBRelayProp::EBKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFUBRelayProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EB;
   	B = StrToFloat(EB->Text);
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
void __fastcall TFUBRelayProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
   Close();
}
//---------------------------------------------------------------------------
