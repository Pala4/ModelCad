//---------------------------------------------------------------------------
#ifndef MCKH
#define MCKH

#include "MCStdElement.h"
#include "KPropFrm.h"
//---------------------------------------------------------------------------
class CK : public CStdElement
{
private:
   long double K;//коэффициент пропорциональности
   TFKProp *FKProp;
public:
	CK(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
