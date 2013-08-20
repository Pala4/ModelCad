//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PIRegPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFPIProp::TFPIProp(TComponent *Owner):TForm(Owner)
{
	ResultOk = false;
   LC1->Hint = "C1 = Kp (Kp - ����������� �������������)";
   LC0->Hint = "C0 = Kp/T�\n(Kp - ����������� �������������; T� - ����� ��������������)";
}
//---------------------------------------------------------------------------
void __fastcall TFPIProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFPIProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EC1;
   	C1 = StrToFloat(EC1->Text);
      Ex = EC0;
   	C0 = StrToFloat(EC0->Text);
   }
   catch(...)
   {
      Application->MessageBoxA("�������� ������ �����", "Floating Poitn Error",
                               MB_OK | MB_ICONERROR);
      Ex->SetFocus();
   	return;
   }
	ResultOk = true;
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TFPIProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
   Close();
}
//---------------------------------------------------------------------------
