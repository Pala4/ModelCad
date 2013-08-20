//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCFree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------
long double __fastcall CFree::Interpretator(double IX)
{
	AnsiString MainStr, TmpStr;
	TOPS OPERATION;
	FirstTime = 1;
	int skLeft = 1, skRight = 100;
	int calc = 0;
	MainStr = Clean(MFormula);
	MainStr = "(" + AnsiUpperCase(MainStr) + ")";
	InsertX(MainStr, IX);
	TmpStr = MainStr;
	while((TmpStr != "END") && !WASERR)
	{
		TmpStr = GetSkobki(MainStr, skLeft, skRight);
		if(TmpStr == "END") break;
		FirstTime = 0;
		while(!WASERR&&UnarOps(TmpStr, opSIN)){}
		while(!WASERR&&UnarOps(TmpStr, opARCSIN)){}
		while(!WASERR&&UnarOps(TmpStr, opCOS)){}
		while(!WASERR&&UnarOps(TmpStr, opARCCOS)){}
		while(!WASERR&&UnarOps(TmpStr, opTAN)){}
		while(!WASERR&&UnarOps(TmpStr, opARCTAN)){}
		while(!WASERR&&UnarOps(TmpStr, opCOTAN)){}
		while(!WASERR&&UnarOps(TmpStr, opARCCOTAN)){}
		while(!WASERR&&UnarOps(TmpStr, opLN)){}
		while(!WASERR&&UnarOps(TmpStr, opLOG2)){}
		while(!WASERR&&UnarOps(TmpStr, opLOG10)){}
		while(!WASERR&&UnarOps(TmpStr, opROOT)){}
		while(!WASERR&&BinarOps(TmpStr, opPOW, TmpStr.Pos('^'))){}
		calc++;
		while(calc && !WASERR)
		{
        	calc = LeftMul(TmpStr, OPERATION);
        	if(calc) BinarOps(TmpStr, OPERATION, calc);

		}
		calc++;
		while(calc && !WASERR)
		{
        	calc = LeftPlus(TmpStr, OPERATION);
        	if(calc) BinarOps(TmpStr, OPERATION, calc);
		}
		MainStr.Delete(skLeft, skRight - skLeft + 1);
		MainStr.Insert(TmpStr, skLeft);
	}
	if(WASERR) return 0;
	ReplaceSign(MainStr, '|');
	return StrToFloat(MainStr);
}
//---------------------------------------------------------------------------
void __fastcall CFree::ErrMsg(const char *ErrStr)
{
	Application->MessageBox(ErrStr, "Внимание!", MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
AnsiString __fastcall CFree::Clean(AnsiString &AStr)
{
	AnsiString RezStr;
	int i;
	i = AStr.Pos(" ");
	while(i)
	{
		AStr.Delete(i, 1);
		i = AStr.Pos(" ");
	}
	RezStr = AStr;
	return RezStr;
}
//---------------------------------------------------------------------------
int __fastcall CFree::BinarOps(AnsiString &TmpStr, TOPS OPERA, int posOp)
{
	WASERR = (TERR)OPERA;
	AnsiString RezStr;
	AnsiString op1Str = "", op2Str = "";
	int wLeft = 1, wRight = 100;
	double op1, op2, TmpRez;
   if(posOp)
   {
   	op2 = SeekRight(TmpStr, posOp + 1, wRight);
      op1 = SeekLeft(TmpStr, posOp, wLeft);
      switch(OPERA)
      {
      	case opMUL: TmpRez = op1*op2; break;
         case opDIV: TmpRez = op1/op2; break;
         case opPLUS: TmpRez = op1 + op2; break;
         case opMINUS: TmpRez = op1 - op2; break;
         case opPOW: TmpRez = pow(op1, op2);
      }
      RezStr = FloatToStr(TmpRez);
      if(RezStr.Pos("NAN")) return 0;
      ReplaceSign(RezStr, '-');
      TmpStr.Delete(wLeft, wRight - wLeft + 1);
      TmpStr.Insert(RezStr, wLeft);
   }
	WASERR = erNO;
	return posOp;
}
//---------------------------------------------------------------------------
void __fastcall CFree::InsertX(AnsiString &Str, double &iks)
{
	AnsiString XStr = FloatToStr(iks);
	int i = 1;
	while(i)
	{
		i = Str.Pos("X");
		if(i)
      {
        	Str.Delete(i, 1);
        	Str.Insert(XStr, i);
      }
	}
	i++;
	XStr = "2,718281828459";
	while(i)
	{
		i = Str.Pos("E");
		if(i)
      {
        	Str.Delete(i, 1);
        	Str.Insert(XStr, i);
      }
	}
	i++;
	XStr = "3,141592653589";
	while(i)
	{
		i = Str.Pos("P");
		if(i)
      {
        	Str.Delete(i, 1);
        	Str.Insert(XStr, i);
      }
	}
}
//---------------------------------------------------------------------------
AnsiString __fastcall CFree::ReversStr(AnsiString &Str)
{
	AnsiString XStr = Str;
	int len = Str.Length();
	for(int i = len; i >= 1; i--)
	{
		XStr[len - i + 1] = Str[i];
	}
	return XStr;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CFree::GetSkobki(AnsiString &Str,int &skLeft, int &skRight)
{
	AnsiString TmpStr = Str;
	int Dlina = TmpStr.Length();
	skLeft = 1;
   skRight = TmpStr.Pos(")");
   if(skRight)
   {
   	for(int i = 1; i <= Dlina; i++)
      {
      	if(TmpStr[i] == '(')
         {
         	if((i < skRight) && (i > skLeft))
            skLeft = i;
         }
      }
      TmpStr.Delete(1, skLeft).
      Delete(skRight - skLeft, Dlina - skRight + 1);
   }
   else
   {
   	if(!FirstTime) return "END";
   }
	return TmpStr;
}
//---------------------------------------------------------------------------
int __fastcall CFree::UnarOps(AnsiString &TmpStr, TOPS OPERA)
{
	WASERR = (TERR)OPERA;
	AnsiString RezStr;
	int posOp;
	int wRight;
	int offset = 0;
	double op, TmpRez;
	AnsiString opStr = "";
   switch(OPERA)
   {
   	case opSIN: offset = 3; break;
      case opARCSIN: offset = 6; break;
      case opCOS: offset = 3; break;
      case opARCCOS: offset = 6; break;
      case opTAN: offset = 2; break;
      case opARCTAN: offset = 5; break;
      case opCOTAN: offset = 3; break;
      case opARCCOTAN: offset = 6; break;
      case opLN: offset = 2; break;
      case opLOG2: offset = 4; break;
      case opLOG10: offset = 2; break;
      case opROOT: offset = 4;
   }
   posOp = TmpStr.Pos(mOPS[OPERA]);
   if(posOp)
   {
   	if((posOp > 1) && (TmpStr[posOp - 1] == 'C'))
      {
      	WASERR = erNO;
         return 0;
      }
      op = SeekRight(TmpStr, posOp + offset, wRight);
      switch(OPERA)
      {
        	case opSIN: TmpRez = sin(op); break;
        	case opARCSIN: TmpRez = asin(op); break;
        	case opCOS: TmpRez = cos(op); break;
        	case opARCCOS: TmpRez = acos(op); break;
        	case opTAN: TmpRez = tan(op); break;
        	case opARCTAN: TmpRez = atan(op); break;
        	case opCOTAN: TmpRez = 1.0/tan(op); break;
        	case opARCCOTAN: TmpRez = atan(1.0/op); break;
        	case opLN:  TmpRez = log(op); break;
        	case opLOG2: TmpRez = Log2(op); break;
        	case opLOG10: TmpRez = log10(op); break;
        	case opROOT: TmpRez = sqrt(op);
      }
      RezStr = FloatToStr(TmpRez);
      if(RezStr.Pos("NAN")) return 0;
      ReplaceSign(opStr, '-');
      TmpStr.Delete(posOp, wRight - posOp + 1);
      TmpStr.Insert(RezStr, posOp);
   }
	WASERR = erNO;
	return posOp;
}
//---------------------------------------------------------------------------
int __fastcall CFree::LeftMul(AnsiString &TmpStr, TOPS &OPERA)
{
	int len = TmpStr.Length();
	for (int i = 1; i<=len; i++)
	{
		if (TmpStr[i] == '*')
      {
      	OPERA = opMUL;
         return i;
      }
		else
		{
			if(TmpStr[i] == '/')
        	{
         	OPERA = opDIV;
            return i;
         }
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
int __fastcall CFree::LeftPlus(AnsiString &TmpStr, TOPS &OPERA)
{
	int len = TmpStr.Length();
	for(int i = 1; i <= len; i++)
	{
		if(TmpStr[i] == '+')
      {
      	OPERA = opPLUS;
         return i;
      }
		else
		{
			if((TmpStr[i] == '-') && (i != 1))
        	{
         	OPERA = opMINUS;
            return i;
         }
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
int __fastcall CFree::ReplaceSign(AnsiString &TmpStr, AnsiString sm)
{
	int i = 1;
	while(i)
	{
		i = TmpStr.Pos(sm);
		if(i)
      {
        	TmpStr.Delete(i, 1);
        	if(sm == '-')
         	TmpStr.Insert('|', i);
         else
         	TmpStr.Insert('-', i);
      }
	}
	return 0;
}
//---------------------------------------------------------------------------
void __fastcall CFree::ErrorProcessor(void)
{
	switch(WASERR)
	{
		case erSIN: ErrMsg("Ошибка при выполнении операции sin(x)!"); break;
		case opARCSIN: ErrMsg("Ошибка при выполнении операции arcsin(x)!"); break;
		case opCOS: ErrMsg("Ошибка при выполнении операции cos(x)!"); break;
		case opARCCOS: ErrMsg("Ошибка при выполнении операции arccos(x)!"); break;
		case opTAN: ErrMsg("Ошибка при выполнении операции tg(x)!"); break;
		case opARCTAN: ErrMsg("Ошибка при выполнении операции arctg(x)!"); break;
		case opCOTAN: ErrMsg("Ошибка при выполнении операции ctg(x)!"); break;
		case opARCCOTAN: ErrMsg("Ошибка при выполнении операции arcctg(x)!"); break;
		case opLN: ErrMsg("Ошибка при выполнении операции ln(x)! Значение Х должно быть больше нуля!"); break;
		case opLOG2: ErrMsg("Ошибка при выполнении операции log2(x)! Значение Х должно быть больше нуля!"); break;
		case opLOG10: ErrMsg("Ошибка при выполнении операции lg(x)! Значение Х должно быть больше нуля!"); break;
		case erMUL: ErrMsg("Ошибка при выполнении операции ""умножение""!"); break;
		case erDIV: ErrMsg("Ошибка при выполнении операции ""деление""! Возможно возникло деление на ноль!"); break;
		case erPLUS: ErrMsg("Ошибка при выполнении операции ""сложение""!"); break;
		case erMINUS: ErrMsg("Ошибка при выполнении операции ""вычитание""!"); break;
		case erPOW: ErrMsg("Ошибка при выполнении возведения в степень!"); break;
      case erROOT: ErrMsg("Ошибка при вычислении квадратного корня!"); break;
		case erUFO: ErrMsg("Проверьте правильность параметров и формулы!"); break;
		default: ErrMsg("Ошибка. Причина не определена!");
	}
}
//---------------------------------------------------------------------------
double __fastcall CFree::SeekRight(AnsiString &TmpStr, int begOp, int &endOp)
{
	AnsiString opStr = "";
   for(int i = begOp; i <= TmpStr.Length(); i++)
   {
   	if(((TmpStr[i] != '-') &&
          (TmpStr[i] != '+') &&
          (TmpStr[i] != '*') &&
          (TmpStr[i] != '/') &&
          (TmpStr[i] != '^')) ||
          (i == begOp))
      {
			opStr += TmpStr[i];
         endOp = i;
      }
      else break;
   }
   ReplaceSign(opStr, '|');
	return StrToFloat(opStr);
}
//---------------------------------------------------------------------------
double __fastcall CFree::SeekLeft(AnsiString &TmpStr, int begOp, int &endOp)
{
	AnsiString opStr = "";
	for(int i = --begOp; i >= 1; i--)
   {
   	if(((TmpStr[i] != '-') &&
          (TmpStr[i] != '+') &&
          (TmpStr[i] != '*') &&
          (TmpStr[i] != '^') &&
          (TmpStr[i] != '/')) ||
          (i == 1))
      {
      	opStr += TmpStr[i];
         endOp = i;
      }
      else break;
	}
   ReplaceSign(opStr, '|');
	return StrToFloat(ReversStr(opStr));
}
//---------------------------------------------------------------------------
CFree::CFree(void):CStdElement()
{
   ID_OBJECT = ID_FREE;
   FirstTime = 1;
   ElName = "Произвольный";
	MFormula = "x";
   mOPS = new AnsiString[13];
   mOPS[0] = "NO"; mOPS[1] = "SIN"; mOPS[2] = "ARCSIN";
   mOPS[3] = "COS"; mOPS[4] = "ARCCOS"; mOPS[5] = "TG";
   mOPS[6] = "ARCTG"; mOPS[7] = "CTG"; mOPS[8] = "ARCCTG";
   mOPS[9] = "LN"; mOPS[10] = "LOG2"; mOPS[11] = "LG"; mOPS[12] = "ROOT";
   FFreeProp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CFree::SetData(void)
{
   FFreeProp = new TFFreeProp(Application);
   FFreeProp->EFormula->Text = MFormula;
   if(FFreeProp->ShowModal() == mrOk)
   {
   	MFormula = FFreeProp->EFormula->Text;
   }
   FFreeProp->Free();
}
//---------------------------------------------------------------------------
void CFree::FUNKCIJA(int index, int end, long double DT)
{
	WASERR = erNO;
	Out[index] = complex <long double>(Interpretator(real(In[index])), 0.0);
}
//---------------------------------------------------------------------------
void __fastcall CFree::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   int StrLen = MFormula.Length() + 1;
   AddValue(Dump, DumpSize, &StrLen, sizeof(int));
   AddValue(Dump, DumpSize, MFormula.c_str(), StrLen);
}
//---------------------------------------------------------------------------
void __fastcall CFree::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   int StrLen = 0;
   GetValue(Dump, DumpSize, &StrLen, sizeof(int));
   LPSTR Str = new char[StrLen];
   GetValue(Dump, DumpSize, Str, StrLen);
   MFormula = Str;
   delete []Str;
}
//---------------------------------------------------------------------------
