//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PIDRegPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFPIDProp::TFPIDProp(TComponent *Owner):TForm(Owner)
{
	ResultOk = false;
   LC1->Hint = "C1 = Kp (Kp - коэффициент регулирования)";
   LC0->Hint = "C0 = Kp/Tи\n(Kp - коэффициент регулирования; Tи - время интегрирования)";
   LC2->Hint = "C2 = C1*Tд (Tд - время дифференцирования)";
}
//---------------------------------------------------------------------------
void __fastcall TFPIDProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFPIDProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EC1;
   	C1 = StrToFloat(EC1->Text);
      Ex = EC1;
   	C0 = StrToFloat(EC0->Text);
      Ex = EC1;
   	C2 = StrToFloat(EC2->Text);
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
void __fastcall TFPIDProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
   Close();
}
//---------------------------------------------------------------------------
