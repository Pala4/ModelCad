//---------------------------------------------------------------------------
#ifndef MCLuftH
#define MCLuftH

#include "MCStdElement.h"
#include "LuftPropFrm.h"
//---------------------------------------------------------------------------
class CLuft : public CStdElement
{
private:
	long double A;//ширина зоны нечувствительности
   long double K;//коэффициент пропорциональности
   long double dX;//смещение по X
   long double dY;//смещение по Y
	TFLuftProp *FLuftProp;
public:
	CLuft(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
