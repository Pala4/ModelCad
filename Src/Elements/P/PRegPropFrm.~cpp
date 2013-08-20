//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PRegPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFPProp::TFPProp(TComponent* Owner):TForm(Owner)
{
	ResultOk = false;
   LC1->Hint = "C1 = Kp (Kp - коэффициент регулирования)";
}
//---------------------------------------------------------------------------
void __fastcall TFPProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFPProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EC1;
   	C1 = StrToFloat(EC1->Text);
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
void __fastcall TFPProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
   Close();
}
//---------------------------------------------------------------------------
