//---------------------------------------------------------------------------
#ifndef MCLuftH
#define MCLuftH

#include "MCStdElement.h"
#include "LuftPropFrm.h"
//---------------------------------------------------------------------------
class CLuft : public CStdElement
{
private:
	long double A;//������ ���� ������������������
   long double K;//����������� ������������������
   long double dX;//�������� �� X
   long double dY;//�������� �� Y
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
