//---------------------------------------------------------------------------
#ifndef MCPIDH
#define MCPIDH

#include "MCStdElement.h"
#include "PIDRegPropFrm.h"
//---------------------------------------------------------------------------
class CPID : public CStdElement
{
private:
	long double C1;
	long double C0;
	long double C2;
   TFPIDProp *FPIDProp;
public:
	CPID(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
