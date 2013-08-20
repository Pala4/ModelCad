//---------------------------------------------------------------------------
#ifndef MCFreeH
#define MCFreeH

#include "MCStdElement.h"
#include "FreePropFrm.h"
//---------------------------------------------------------------------------
class CFree: public CStdElement
{
private:
	enum TERR{erNO,erSIN,erARCSIN,erCOS,erARCCOS,
             erTAN,erARCTAN,erCOTAN,erARCCOTAN,
             erLN,erLOG2,erLOG10, erROOT,
             erMUL,erDIV,erPLUS,erMINUS,erPOW, erUFO};
	enum TOPS {opNO,opSIN,opARCSIN,opCOS,opARCCOS,
              opTAN,opARCTAN,opCOTAN,opARCCOTAN,
              opLN,opLOG2,opLOG10, opROOT,
              opMUL,opDIV,opPLUS,opMINUS,opPOW};
   int FirstTime;
	TERR WASERR;
   AnsiString MFormula;
	AnsiString *mOPS;
   TFFreeProp *FFreeProp;
	AnsiString __fastcall GetSkobki(AnsiString &Str,int &skLeft, int &skRight);
	AnsiString __fastcall Clean(AnsiString &AStr);
	AnsiString __fastcall ReversStr(AnsiString &Str);
	int __fastcall BinarOps(AnsiString &TmpStr, TOPS OPERA, int posOp);
	int __fastcall UnarOps(AnsiString &TmpStr, TOPS OPERA);
	int __fastcall LeftMul(AnsiString &TmpStr, TOPS &OPERA);
	int __fastcall LeftPlus(AnsiString &TmpStr, TOPS &OPERA);
	int __fastcall ReplaceSign(AnsiString &TmpStr, AnsiString sm);
	void __fastcall InsertX(AnsiString &Str, double &iks);
	void __fastcall ErrMsg(const char* ErrStr);
	void __fastcall ErrorProcessor(void);
	long double __fastcall Interpretator(double IX);
	double __fastcall SeekLeft(AnsiString &TmpStr, int begOp, int &endOp);
	double __fastcall SeekRight(AnsiString &TmpStr, int begOp, int &endOp);
public:
	CFree(void);
   void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
