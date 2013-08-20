//---------------------------------------------------------------------------
#ifndef MCPIH
#define MCPIH

#include "MCStdElement.h"
#include "PIRegPropFrm.h"
//---------------------------------------------------------------------------
class CPI : public CStdElement
{
private:
	long double C1;
	long double C0;
   TFPIProp *FPIProp;
public:
	CPI(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
