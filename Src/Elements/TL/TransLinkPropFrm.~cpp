//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TransLinkPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
long double* TFTransLinkProp::StrToArray(AnsiString Str, AnsiString Separator, DWORD &Num)
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
__fastcall TFTransLinkProp::TFTransLinkProp(TComponent *Owner)
	                        :TForm(Owner)
{
	ResultOk = false;
   n = 0;
   m = 0;
   K = 1.0;
   CharGroup = 0;
   CharTIndex = 0;
   CharFIndex = 0;
   T1 = 0.0;
   T2 = 100.0;
   DT = 0.01;
   W1 = 0.0;
   W2 = 100.0;
   DW = 0.01;
   N = NULL;
   T = NULL;
   ShowChar = NULL;
   Apply = NULL;
   RGModelType->Hint = "Форма записи полиномов\nчислителя и знаменателя передаточной функции";
   RGAlgType->Hint = "Алгоритм расчёта передаточной функции";
   LNs->Hint = "Коэффициенты полинома числителя передаточной функции";
   LTs->Hint = "Коэффициенты полинома знаменателя передаточной функции";
   LTL->Hint = "Передаточная функция";
   LK->Hint = "Величина показывающая во сколько раз\nвыходной сигнал больше входного\n(установившееся значение переходного процесса)";
   BtChar->Hint = "Временные:\n";
   BtChar->Hint += "переходная h(t); весовая k(t)\n";
   BtChar->Hint += "Частотные:\n";
   BtChar->Hint += "АЧХ A(w); ЛАЧХ 20lg(A(w));\n";
   BtChar->Hint += "ФЧХ ф(w); ЛФЧХ lg(ф(w));\n";
   BtChar->Hint += "АФЧХ W(jw); НПЧХ P(jw)";
}
//---------------------------------------------------------------------------
AnsiString TFTransLinkProp::ArrayToStr(long double *Array, DWORD Num)
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
void __fastcall TFTransLinkProp::RGModelTypeClick(TObject *Sender)
{
	if(((TRadioGroup*)Sender)->ItemIndex == 0)
   	ImTLViewG->Visible = true;
   else
   	ImTLViewG->Visible = false;
   ImTLViewT->Visible = (!ImTLViewG->Visible);
   LTLMulK->Visible = ImTLViewT->Visible;
   LK->Visible = ImTLViewT->Visible;
   EK->Visible = ImTLViewT->Visible;
   if(EK->Visible) EK->Text = FloatToStr(K);
   if(Visible)
   {
   	BtApply->Enabled = true;
   	BtChar->Enabled = false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFTransLinkProp::RGAlgTypeClick(TObject *Sender)
{
	BtApply->Enabled = true;
	BtChar->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFTransLinkProp::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFTransLinkProp::EKKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFTransLinkProp::EChange(TObject *Sender)
{
   if(Visible)
   {
		BtApply->Enabled = true;
		BtChar->Enabled = false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFTransLinkProp::BtCharClick(TObject *Sender)
{
   FChar = new TFChar(Application);
   FChar->ShowChar =	ShowChar;
   FChar->PCChars->ActivePageIndex = CharGroup;
   FChar->RGTemp->ItemIndex = CharTIndex;
   FChar->RGFreq->ItemIndex = CharFIndex;
  	FChar->ET1->Text = FloatToStr(T1);
  	FChar->ET2->Text = FloatToStr(T2);
  	FChar->EDT->Text = FloatToStr(DT);
  	FChar->EW1->Text = FloatToStr(W1);
  	FChar->EW2->Text = FloatToStr(W2);
   FChar->EDW->Text = FloatToStr(DW);
	FChar->ShowModal();
   if(FChar->ResultOk)
   {
   	CharGroup = FChar->CharGroup;
      CharTIndex = FChar->CharTIndex;
      CharFIndex = FChar->CharFIndex;
      T1 = FChar->T1;
      T2 = FChar->T2;
      DT = FChar->DT;
      W1 = FChar->W1;
      W2 = FChar->W2;
      DW = FChar->DW;
   }
   FChar->Free();
}
//---------------------------------------------------------------------------
void __fastcall TFTransLinkProp::BtOkApplyClick(TObject *Sender)
{
   TEdit *Ex;
   try
   {
      Ex = ENs;
   	N = StrToArray(ENs->Text, " ", n);
      Ex = ETs;
   	T = StrToArray(ETs->Text, " ", m);
      if(EK->Visible) {Ex = EK; K = StrToFloat(EK->Text);}
   }
   catch(...)
   {
      Application->MessageBoxA("Неверный формат числа", "Floating Poitn Error",
                               MB_OK | MB_ICONERROR);
		if(N){N = (long double*)realloc(N, 0); N = NULL;}
		if(T){T = (long double*)realloc(T, 0); T = NULL;}
      Ex->SetFocus();
   	return;
   }
   if(Sender != BtApply)
   {
		ResultOk = true;
   	Close();
   }
   else
   {
   	if(Apply) Apply();
      BtApply->Enabled = false;
   	BtChar->Enabled = true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFTransLinkProp::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TFTransLinkProp::FormDestroy(TObject *Sender)
{
	if(N){N = (long double*)realloc(N, 0); N = NULL;}
	if(T){T = (long double*)realloc(T, 0); T = NULL;}
}
//---------------------------------------------------------------------------
