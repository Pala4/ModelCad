//---------------------------------------------------------------------------
#ifndef MCTLH
#define MCTLH

#include "..\..\GrpFrm.h"
#include "..\MCStdElement.h"
#include "TransLinkPropFrm.h"

#include "NPCharFrm.h"
//---------------------------------------------------------------------------
struct TPolyVal
{
	DWORD Pow;
   long double Val;
};
//---------------------------------------------------------------------------
class CTransLink: public CStdElement
{
private:
	enum ID_ALGORITM {ANALOG_Z_PREOB, ANALOG_RAG_BERG_PREOB, DISKR_DM_PREOB};
	bool astotizm;
	bool ERROR_V;
	bool U_Stepen_bolshe;
	ID_ALGORITM Algoritm;
	int stepen;
	int U_Stepen;
	int U_z_Step;
	int Stepen_astotizma;
   DWORD n;
   DWORD m;
   int ModelTypeIndex;
   int CharGroup;
   int CharTIndex;
   int CharFIndex;
   long double T1;
   long double T2;
   long double DT;
   long double W1;
   long double W2;
   long double DW;
   long double K;
   long double *N;
   long double *T;
	std::complex<long double> *U_kof;
	std::complex<long double> *V_kof;
   std::complex<long double> *Kof;
   std::complex<long double> *Vast_kof;
   std::complex<long double> *Nign_kof;
   std::complex <long double> W0;
	std::complex<long double> *K_1;
	std::complex<long double> *P_i;
	std::complex<long double> *A_z0;
	std::complex<long double> *B_z1;
	std::complex<long double> **YYY_j;
	std::complex<long double> *A_d;
	std::complex<long double> *B_d;
   TFChar *FChar;
   TFTransLinkProp *FTransLinkProp;
   TForm_Grafic *FG;
   TFNPChar *FNPChar;
   long double Factorial(int n);
   long double Sochetanie(int n, int k);
   void Opred_Kof_Diskr_Perechodnoi(int end, long double DT);
	void Analog_Z_preobraz(int index);
	void Analog_RagaziniBerger_preobraz(int);
   void DM_preobraz(int);
	void Del_YYY();
   void Opred_Kof_Perechodnoi(bool);
   void Opred_Kof_DM(long double DT);
   void Opred_Tochek_Perechodnoi(long double * &X ,long double * &Y, int N, long double sdvig_T, long double T);
   void AFChX(long double * &X ,long double * &Y, int N, long double w_nach,long double w_kon );
   void AChX(long double * &X ,long double * &Y, int N, long double w_nach,long double w_kon);
   void FChX(long double * &X ,long double * &Y, int N, long double w_nach,long double w_kon, bool Gradus );
	void MulPoly(long double *&A, DWORD N, long double T);
   void __fastcall CalcRoots(std::complex <long double> * &Polusa, std::complex <long double> *& Nyli, int &n_st, int &m_st);
	void __fastcall ShowChar(int CharIndex, long double D1, long double D2, long double DD);
   void __fastcall Apply(void);
public:
   long double w_max;
   int diskr_w;
   std::complex<long double> *FAZA;
   std::complex<long double> *Amplituda;
   std::complex<long double> *LAHX;
	CTransLink(void);
   void FazaHarakteristik();
	virtual void __fastcall SetData(void);
   virtual void FUNKCIJA(int index, int, long double DT);
   void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
   ~CTransLink();
};
//---------------------------------------------------------------------------
#endif
