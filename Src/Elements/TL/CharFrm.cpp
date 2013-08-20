//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CharFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFChar::TFChar(TComponent *Owner)
	               :TForm(Owner)
{
   ResultOk = false;
   CharGroup = 0;
   CharTIndex = 0;
   CharFIndex = 0;
   T1 = 0.0;
   T2 = 100.0;
   DT = 0.01;
   W1 = 0.0;
   W2 = 100.0;
   DW = 0.01;
	ShowChar = NULL;
   RGTemp->Hint = "Переходная характеристика: реакция на единичное ступенчатое воздействие 1(t)\n";
   RGTemp->Hint += "Весовая характеристика: реакция на единичный импульс s(t)";
   LTempWidth->Hint = "Рассматриваемый интервал времени";
   LDT->Hint = "Значение интервала разбиения";
   RGFreq->Hint = "АЧХ: амплитудная частотная характеристика\n";
   RGFreq->Hint += "ЛАЧХ: логарифмическая амплитудная частотная характеристика\n";
   RGFreq->Hint += "ФЧХ: фазовая частотная характеристика\n";
   RGFreq->Hint += "ЛФЧХ: логарифмическая фазовая частотная характеристика\n";
   RGFreq->Hint += "АФЧХ: амплитудная фазовая частотная характеристика\n";
   RGFreq->Hint += "НПЧХ: нуль-полюсная частотная характеристика";
   LFreqWidth->Hint = "Рассматриваемый интервал частот";
   LDW->Hint = "Значение интервала разбиения";
   BtShow->Hint = "Отобразить выбранную характеристику";
}
//---------------------------------------------------------------------------
void __fastcall TFChar::EKeyPress(TObject *Sender, char &Key)
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
void __fastcall TFChar::BtShowClick(TObject *Sender)
{
   if(ShowChar)
   {
   	if(ET1->Text == "") ET1->Text = "0";
   	if(ET2->Text == "") ET2->Text = "0";
   	if(EDT->Text == "") EDT->Text = FloatToStr(0.01);
      if(StrToFloat(EDT->Text) == 0) EDT->Text = FloatToStr(0.01);
   	if(EW1->Text == "") EW1->Text = "0";
   	if(EW2->Text == "") EW2->Text = "0";
   	if(EDW->Text == "") EDW->Text = FloatToStr(0.01);
      if(StrToFloat(EDW->Text) == 0) EDW->Text = FloatToStr(0.01);
		switch(PCChars->ActivePageIndex)
   	{
      	case 0:
   			switch(RGTemp->ItemIndex)
   			{
         		case 0: CharTIndex = 0; break;
         		case 1: CharTIndex = 1; break;
   			}
            T1 = StrToFloat(ET1->Text);
            T2 = StrToFloat(ET2->Text);
            DT = StrToFloat(EDT->Text);
				ShowChar(CharTIndex, T1, T2, DT);
      	break;
      	case 1:
   			switch(RGFreq->ItemIndex)
   			{
         		case 0: CharFIndex = 2; break;
         		case 1: CharFIndex = 3; break;
         		case 2: CharFIndex = 4; break;
         		case 3: CharFIndex = 5; break;
         		case 4: CharFIndex = 6; break;
         		case 5: CharFIndex = 7; break;
   			}
            W1 = StrToFloat(EW1->Text);
            W2 = StrToFloat(EW2->Text);
            DW = StrToFloat(EDW->Text);
				ShowChar(CharFIndex, W1, W2, DW);
      	break;
   	}
   }
}
//---------------------------------------------------------------------------
void __fastcall TFChar::BtOkClick(TObject *Sender)
{
  	if(ET1->Text == "") ET1->Text = "0";
  	if(ET2->Text == "") ET2->Text = "0";
  	if(EDT->Text == "") EDT->Text = FloatToStr(0.01);
   if(StrToFloat(EDT->Text) == 0) EDT->Text = FloatToStr(0.01);
  	if(EW1->Text == "") EW1->Text = "0";
  	if(EW2->Text == "") EW2->Text = "0";
 	if(EDW->Text == "") EDW->Text = FloatToStr(0.01);
   if(StrToFloat(EDW->Text) == 0) EDW->Text = FloatToStr(0.01);
   TEdit *Ex;
   try
   {
      Ex = ET1;
   	T1 = StrToFloat(ET1->Text);
      Ex = ET2;
   	T2 = StrToFloat(ET2->Text);
      Ex = EDT;
   	DT = StrToFloat(EDT->Text);
      Ex = EW1;
   	W1 = StrToFloat(EW1->Text);
      Ex = EW2;
   	W2 = StrToFloat(EW2->Text);
      Ex = EDW;
   	DW = StrToFloat(EDW->Text);
   }
   catch(...)
   {
      Application->MessageBoxA("Неверный формат числа", "Floating Poitn Error",
                               MB_OK | MB_ICONERROR);
      Ex->SetFocus();
   	return;
   }
   CharGroup = PCChars->ActivePageIndex;
   CharTIndex = RGTemp->ItemIndex;
   CharFIndex = RGFreq->ItemIndex;
	ResultOk = true;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFChar::BtCancelClick(TObject *Sender)
{
	ResultOk = false;
	Close();
}
//---------------------------------------------------------------------------
