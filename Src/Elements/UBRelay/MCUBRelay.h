//---------------------------------------------------------------------------
#ifndef MCUBRelayH
#define MCUBRelayH

#include "MCStdElement.h"
#include "UBRelayFrm.h"
//---------------------------------------------------------------------------
class CUBRelay : public CStdElement
{
private:
	long double B;//уровень ограничения
   long double dX;//смещение по X
   long double dY;//смещение по Y
   TFUBRelayProp *FUBRelayProp;
public:
	CUBRelay(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
