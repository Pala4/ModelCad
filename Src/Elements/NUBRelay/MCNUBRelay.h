//---------------------------------------------------------------------------
#ifndef MCNUBRelayH
#define MCNUBRelayH

#include "MCStdElement.h"
#include "NUBRelayPropFrm.h"
//---------------------------------------------------------------------------
class CNUBRelay : public CStdElement
{
private:
	long double A;//ширина зоны нечувствительности
	long double B;//уровень ограничения
   long double dX;//смещение по X
   long double dY;//смещение по Y
   TFNUBRelayProp *FNUBRelayProp;
public:
	CNUBRelay(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
