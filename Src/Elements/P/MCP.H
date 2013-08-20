//---------------------------------------------------------------------------
#ifndef MCPH
#define MCPH

#include "MCStdElement.h"
#include "PRegPropFrm.h"
//---------------------------------------------------------------------------
class CP : public CStdElement
{
private:
	long double C1;
   TFPProp *FPProp;
public:
	CP(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
