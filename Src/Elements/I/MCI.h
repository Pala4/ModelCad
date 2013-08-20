//---------------------------------------------------------------------------
#ifndef MCIH
#define MCIH

#include "MCStdElement.h"
#include "IRegPropFrm.h"
//---------------------------------------------------------------------------
class CI : public CStdElement
{
private:
	long double C0;
   TFIProp *FIProp;
public:
	CI(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
