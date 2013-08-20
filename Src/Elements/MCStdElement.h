//---------------------------------------------------------------------------
#ifndef MCStdElementH
#define MCStdElementH

#include "MCLink.h"
//---------------------------------------------------------------------------
class CStdElement : public CElement
{
protected:
   virtual bool CheckOut(void);
public:
   CLink *InLink;
   CLink *OutLink;
   CElement *InEl;
   CElement *OutEl;
   CElement *Input;
   CElement *Output;
	complex <long double> *In;
	complex <long double> *Out;
	CStdElement(void);
   virtual void __fastcall ShowGrp(void);
   BOOL __fastcall virtual OrientBusy(T_ORIENT OR);
   virtual void VICHISLENIE(int index, int end, long double DT);
	virtual void FUNKCIJA(int index, int end, long double DT){}
	virtual void DELETE_GRAFIC_MASSIV(void);
   virtual void DelLink(void *LinkPtr);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
   virtual void DelInfo(void);
	virtual ~CStdElement();
};
//---------------------------------------------------------------------------
#endif
