//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "NUBRelayPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFNUBRelayProp::TFNUBRelayProp(TComponent* Owner)
	                       :TForm(Owner)
{
	ResultOk = false;
   LA->Hint = "�������� ��������� ������� ��������,\n������� �� �������������� ���������";
   LB->Hint = "�������� ��������� �������� ��������,\n������� �� �������������� ���������";
   LdX->Hint = "�������� ������� ������������ �� ��� �������\n������������ ������ ���������";
   LdY->Hint = "�������� ������� ������������ �� ��� �������\n������������ ������ ���������";
}
//---------------------------------------------------------------------------
void __fastcall TFNUBRelayProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFNUBRelayProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = EA;
   	A = StrToFloat(EA->Text);
      Ex = EB;
   	B = StrToFloat(EB->Text);
      Ex = EdX;
   	dX = StrToFloat(EdX->Text);
      Ex = EdY;
   	dY = StrToFloat(EdY->Text);
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
void __fastcall TFNUBRelayProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
   Close();
}
//---------------------------------------------------------------------------
