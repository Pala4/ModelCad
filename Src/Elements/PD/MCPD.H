//---------------------------------------------------------------------------
#ifndef MCPDH
#define MCPDH

#include "MCStdElement.h"
#include "PDRegPropFrm.h"
//---------------------------------------------------------------------------
class CPD : public CStdElement
{
private:
	long double C1;
	long double C2;
   TFPDProp *FPDProp;
public:
	CPD(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
