//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FreePropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFFreeProp::TFFreeProp(TComponent *Owner)
                      :TForm(Owner)
{
	LFormula->Hint = "��������� ������� (x - ������� ������):\n";
   LFormula->Hint += "sin(x) - �����; arcsin(x) - ��������; cos(x) - �������; arccos(x) - ����������;\n";
   LFormula->Hint += "tg(x) - �������; arctg(x) - ����������; ctg(x) - ���������; arcctg(x) - ������������;\n";
   LFormula->Hint += "ln(x) - ����������� ��������; log2(x) - �������� �� ��������� 2; lg(x) - ���������� ��������;\n";
   LFormula->Hint += "root(x) - ���������� ������\n";
   LFormula->Hint += "��������� ��������: +;-;*;/;^";
}
//---------------------------------------------------------------------------
