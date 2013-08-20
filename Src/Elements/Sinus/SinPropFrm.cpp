//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SinPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFSinProp::TFSinProp(TComponent* Owner)
	                  :TForm(Owner)
{
	ResultOk = false;
   LA->Hint = "Амплитуда колебаний синусоиды";
   LW->Hint = "Частота колебаний синусоиды";
   LF->Hint = "Фазовый сдвиг колебаний синусоиды";
   LdX->Hint = "Смещение графика нелинейности по оси абсцисс\nотносительно начала координат";
   LdY->Hint = "Смещение графика нелинейности по оси ординат\nотносительно начала координат";
}
//---------------------------------------------------------------------------
void __fastcall TFSinProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFSinProp::RGCornerClick(TObject *Sender)
{
	if(((TRadioGroup*)Sender)->ItemIndex == 0)
   	LF->Caption = "Фаза (град.):";
   else
   	LF->Caption = "Фаза (рад.):";
}
//---------------------------------------------------------------------------
void __fastcall TFSinProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EA;
   	A = StrToFloat(EA->Text);
      Ex = EW;
   	W = StrToFloat(EW->Text);
      Ex = EF;
   	F = StrToFloat(EF->Text);
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
void __fastcall TFSinProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
	Close();
}
//---------------------------------------------------------------------------
