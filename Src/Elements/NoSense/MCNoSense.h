//---------------------------------------------------------------------------
#ifndef MCNoSenseH
#define MCNoSenseH

#include "MCStdElement.h"
#include "NoSensePropFrm.h"
//---------------------------------------------------------------------------
class CNoSense : public CStdElement
{
private:
	long double A; //ширина зоны нечувствительности
   long double K; //коэффициент пропорциональности
   long double dX;//смещение по X
   long double dY;//смещение по Y
   TFNoSenseProp *FNoSenseProp;
public:
	CNoSense(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
