//---------------------------------------------------------------------------
#ifndef MCNoSenseRestH
#define MCNoSenseRestH

#include "MCStdElement.h"
#include "NoSenseRestPropFrm.h"
//---------------------------------------------------------------------------
class CNoSenseRest : public CStdElement
{
private:
	long double A;//ширина зоны нечувствительности
	long double B;//уровень ограничения
   long double K;//коэффициент пропорциональности
   long double dX;//смещение по X
   long double dY;//смещение по Y
   TFNoSenseRestProp *FNoSenseRestProp;
public:
	CNoSenseRest(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
