//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_VvodPerFunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
//#pragma link "EditLetNum"
//#pragma link "EditLetNum"
//#pragma link "EditLetNum"
#pragma resource "*.dfm"
TForm_PerFunc *Form_PerFunc;

//---------------------------------------------------------------------------
__fastcall TForm_PerFunc::TForm_PerFunc(TComponent* Owner)
        : TForm(Owner)
{
//CSE_znach->Value=0;
/*LB_A->Items->Add("A"+FloatToStr(0)+" = 0");
LB_A->ItemIndex=0;
LB_B->Items->Add("B"+FloatToStr(0)+" = 0");
LB_B->ItemIndex=0;
Edit1->Text=0;
Edit_B->Text=0;
count_An=1;
//A_i=NULL;
A_i=new double[1]; A_i[0]=0;
B_i=new double[1];B_i[0]=0;
Label2->Caption="B"+FloatToStr(LB_B->ItemIndex)+" =";
//Edit1->Text=A_i[LB_A->ItemIndex];
//Label1->Caption="A"+FloatToStr(LB_A->ItemIndex)+" =";

//LB_A->SetFocus();
/*Edit1->Text=A_i[LB_A->ItemIndex];
Label1->Caption="A"+FloatToStr(LB_A->ItemIndex)+" =";
Edit1->SetFocus();*/
Edit1->OnKeyDown = Edit1KeyDown;
Edit_B->OnKeyDown = Edit_BKeyDown;
zapusk=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm_PerFunc::BB_AddClick(TObject *Sender)
{
LB_A->Items->Clear();
LB_B->Items->Clear();
AnsiString A="A";
AnsiString B="B";
bool istina=false;
if(this->CB_Tkoff->Checked)
{
 count_An=CSE_znach->Value-1;
 if(count_An>=0) istina=true;
// E_KofUsil->Visible=true;
// Label5->Visible=true;
A="t";
B="T";
}
else
{
 count_An=CSE_znach->Value;
 if(count_An>0) istina=true;
// E_KofUsil->Visible=false;
// Label5->Visible=false;
}
delete []A_i; A_i=NULL;
delete []B_i; B_i=NULL;
if(istina)
{
Edit1->Text=0;
Edit_B->Text=0;
A_i=new double[count_An+1];
B_i=new double[count_An+1];
for(int i=0; i<count_An+1;i++)
{
A_i[i]=0;
B_i[i]=0;
LB_A->Items->Add(A+FloatToStr(i)+" = 0");
LB_B->Items->Add(B+FloatToStr(i)+" = 0");
}
LB_A->Items->Strings[0];
LB_A->ItemIndex=0;
LB_B->Items->Strings[0];
LB_B->ItemIndex=0;
CSE_znach->Value=1;
}
//Add_Kof();
LB_AClick(Sender);
Label2->Caption=B+FloatToStr(LB_B->ItemIndex)+" =";
}
//---------------------------------------------------------------------------
void __fastcall TForm_PerFunc::LB_AClick(TObject *Sender)
{
AnsiString A="A";
if(this->CB_Tkoff->Checked) A="t";

Edit1->SelectAll();
if (A_i!=NULL)
{
Edit1->Text=A_i[LB_A->ItemIndex];
Label1->Caption=A+FloatToStr(LB_A->ItemIndex)+" =";
Edit1->SetFocus();
}
}
//---------------------------------------------------------------------------




void __fastcall TForm_PerFunc::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
AnsiString A="A";
if(this->CB_Tkoff->Checked) A="t";
if ((Key== VK_RETURN) ||(Key== VK_UP) || (Key== VK_DOWN) && (A_i!=NULL))
{
A_i[LB_A->ItemIndex]=StrToFloat(Edit1->Text);
LB_A->Items->Strings[LB_A->ItemIndex]=A
+FloatToStr(LB_A->ItemIndex)+" = "+Edit1->Text;
}
if ((Key== VK_RETURN)||(Key== VK_DOWN) && (A_i!=NULL))
{
if(LB_A->ItemIndex==(count_An)) LB_A->ItemIndex=0;
else LB_A->ItemIndex=LB_A->ItemIndex+1;
LB_AClick(Sender);
}
if ((Key== VK_UP) && (A_i!=NULL))
{
if(LB_A->ItemIndex==0) LB_A->ItemIndex=count_An;
else LB_A->ItemIndex=LB_A->ItemIndex-1;
LB_AClick(Sender);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm_PerFunc::FormActivate(TObject *Sender)
{
CB_Tkoff->Checked=TT_kof;
K=1.;
AnsiString B="B";
if(this->CB_Tkoff->Checked)
{
 B="T";
zapusk=true;
// E_KofUsil->Visible=true;
// Label5->Visible=true;
}
else zapusk=false;
Ok=false;
Label2->Caption=B+FloatToStr(LB_B->ItemIndex)+" =";
Edit_B->Text=B_i[LB_B->ItemIndex];
LB_AClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_PerFunc::LB_BClick(TObject *Sender)
{
Edit_B->SelectAll();
AnsiString B="B";
if(this->CB_Tkoff->Checked) B="T";
if (B_i!=NULL)
{
Edit_B->Text=B_i[LB_B->ItemIndex];
Label2->Caption=B+FloatToStr(LB_B->ItemIndex)+" =";
Edit_B->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm_PerFunc::Edit_BKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
AnsiString B="B";
if(this->CB_Tkoff->Checked) B="T";
if ((Key== VK_RETURN) ||(Key== VK_UP) || (Key== VK_DOWN) && (A_i!=NULL))
{
B_i[LB_B->ItemIndex]=StrToFloat(Edit_B->Text);
LB_B->Items->Strings[LB_B->ItemIndex]=B
+FloatToStr(LB_B->ItemIndex)+" = "+Edit_B->Text;
}
if ((Key== VK_RETURN)||(Key== VK_DOWN) && (B_i!=NULL))
{
if(LB_B->ItemIndex==(count_An)) LB_B->ItemIndex=0;
else LB_B->ItemIndex=LB_B->ItemIndex+1;
LB_BClick(Sender);
}
if ((Key== VK_UP) && (B_i!=NULL))
{
if(LB_B->ItemIndex==0) LB_B->ItemIndex=count_An;
else LB_B->ItemIndex=LB_B->ItemIndex-1;
LB_BClick(Sender);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm_PerFunc::FormDestroy(TObject *Sender)
{
delete [] A_i;
A_i=NULL;
delete [] B_i;
B_i=NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm_PerFunc::BB_OkClick(TObject *Sender)
{
Ok=true;
K=StrToFloat(E_KofUsil->Text);
Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm_PerFunc::CSE_znachKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key== VK_RETURN)
{
if((CSE_znach->Value>=1)&&(CSE_znach->Value<=50))
BB_AddClick(Sender);
else {CSE_znach->Value=1;BB_AddClick(Sender);}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm_PerFunc::CSE_znachClick(TObject *Sender)
{
CSE_znach->Value=1;
CSE_znach->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TForm_PerFunc::Edit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if ((Key== VK_DOWN) || (Key== VK_RETURN)
|| (Key== VK_UP)) Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TForm_PerFunc::Edit_BKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if ((Key== VK_DOWN) || (Key== VK_RETURN)
|| (Key== VK_UP)) Edit_B->SelectAll();
}
//---------------------------------------------------------------------------


void __fastcall TForm_PerFunc::BB_CancelClick(TObject *Sender)
{
Ok=false;
Close();
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------



void __fastcall TForm_PerFunc::CB_TkoffClick(TObject *Sender)
{
if(!zapusk) BB_AddClick(Sender);
zapusk=false;
}
//---------------------------------------------------------------------------

