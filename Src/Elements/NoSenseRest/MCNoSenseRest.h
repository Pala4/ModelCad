//---------------------------------------------------------------------------
#ifndef MCNoSenseRestH
#define MCNoSenseRestH

#include "MCStdElement.h"
#include "NoSenseRestPropFrm.h"
//---------------------------------------------------------------------------
class CNoSenseRest : public CStdElement
{
private:
	long double A;//������ ���� ������������������
	long double B;//������� �����������
   long double K;//����������� ������������������
   long double dX;//�������� �� X
   long double dY;//�������� �� Y
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
