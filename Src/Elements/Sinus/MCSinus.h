//---------------------------------------------------------------------------
#ifndef MCSinusH
#define MCSinusH

#include "MCStdElement.h"
#include "SinPropFrm.h"
//---------------------------------------------------------------------------
class CSinus : public CStdElement
{
private:
	long double A;
	long double W;
	long double F;
   long double GradToRadians;
   long double dX;//смещение по X
   long double dY;//смещение по Y
   TFSinProp *FSinProp;
public:
	CSinus(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
