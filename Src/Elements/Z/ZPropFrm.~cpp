//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ZPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
long double* TFZProp::StrToArray(AnsiString Str, AnsiString Separator, DWORD &Num)
{
   Num = 0;
   long double *Array = NULL;
	for(int ci = 1; ci <= Str.Length(); ci++)
   {
   	if(isdigit(Str[ci]) || Str[ci] == '-')
      {
      	int cj = ci;
         AnsiString Digit = "";
         do
         {
            Digit += Str[cj];
            cj++;
            if(cj > Str.Length()) break;
         }while(Str[cj] != ' ');
         Num++;
         Array = (long double*)realloc(Array, sizeof(long double)*Num);
         Array[Num - 1] = StrToFloat(Digit);
         ci = cj;
      }
   }
   return Array;
}
//---------------------------------------------------------------------------
__fastcall TFZProp::TFZProp(TComponent *Owner)
	                        :TForm(Owner)
{
	ResultOk = false;
   Azn = 0;
   Bzn = 0;
   Az = NULL;
   Bz = NULL;
   LAz->Hint = "Коэффициенты полинома числителя дискретной передаточной функции";
   LBz->Hint = "Коэффициенты полинома знаменателя дискретной передаточной функции";
   LZ->Hint = "Дискретная передаточная функция";
}
//---------------------------------------------------------------------------
AnsiString TFZProp::ArrayToStr(long double *Array, DWORD Num)
{
	AnsiString Str = "";
	if(!Num) return (Str = 0);
   for(DWORD ci = 0; ci < Num; ci++)
   {
   	if(ci) Str += ' ';
      Str += FloatToStr(Array[ci]);
   }
   return Str;
}
//---------------------------------------------------------------------------
void __fastcall TFZProp::EKeyPress(TObject *Sender, char &Key)
{
	if((Key == '.')||(Key == ',')) Key = DecimalSeparator;
	Set  <char, 0, 255> Dig;
   Dig << '0' << '1' << '2' << '3' << '4';
   Dig << '5' << '6' << '7' << '8' << '9' << '-';
   Dig << VK_BACK << VK_DELETE << VK_SPACE;
   Dig << DecimalSeparator;
	if (!Dig.Contains(Key)) Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFZProp::BtOkClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
   	if(EAz->Text == "") EAz->Text = "0";
   	if(EBz->Text == "") EBz->Text = FloatToStr(1.0);
      Ex = EAz;
   	Az = StrToArray(EAz->Text, " ", Azn);
      Ex = EBz;
   	Bz = StrToArray(EBz->Text, " ", Bzn);
      if(Bzn)
      	if(Bz[0] == 0)
         {
      		Application->MessageBoxA("Bz0 не должен быть равным 0", "Floating Poitn Error",
                                     MB_OK | MB_ICONERROR);
				if(Az){Az = (long double*)realloc(Az, 0); Az = NULL; Azn = 0;}
				if(Bz){Bz = (long double*)realloc(Bz, 0); Bz = NULL; Bzn = 0;}
      		Ex->SetFocus();
   			return;
         }
   }
   catch(...)
   {
      Application->MessageBoxA("Неверный формат числа", "Floating Poitn Error",
                               MB_OK | MB_ICONERROR);
		if(Az){Az = (long double*)realloc(Az, 0); Az = NULL; Azn = 0;}
		if(Bz){Bz = (long double*)realloc(Bz, 0); Bz = NULL; Bzn = 0;}
      Ex->SetFocus();
   	return;
   }
   ResultOk = true;
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TFZProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TFZProp::FormDestroy(TObject *Sender)
{
	if(Az){Az = (long double*)realloc(Az, 0); Az = NULL;}
	if(Bz){Bz = (long double*)realloc(Bz, 0); Bz = NULL;}
}
//---------------------------------------------------------------------------
