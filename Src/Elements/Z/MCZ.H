//---------------------------------------------------------------------------
#ifndef MCZH
#define MCZH

#include "MCStdElement.h"
#include "ZPropFrm.h"
//---------------------------------------------------------------------------
class CZ : public CStdElement
{
private:
	DWORD Azn;
   DWORD Bzn;
   long double *Az;
   long double *Bz;
   TFZProp *FZProp;
public:
	CZ(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
	virtual ~CZ(void);
};
//---------------------------------------------------------------------------
#endif
