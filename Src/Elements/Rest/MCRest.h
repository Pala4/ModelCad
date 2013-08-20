//---------------------------------------------------------------------------
#ifndef MCRestH
#define MCRestH

#include "MCStdElement.h"
#include "RestPropFrm.h"
//---------------------------------------------------------------------------
class CRest : public CStdElement
{
private:
	long double B;//������� �����������
	long double K;//����������� ������������������
   long double dX;//�������� �� X
   long double dY;//�������� �� Y
   TFRestProp *FRestProp;
public:
	CRest(void);
   virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int end, long double DT);
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
};
//---------------------------------------------------------------------------
#endif
