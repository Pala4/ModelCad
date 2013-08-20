//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCTL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "TLRes.res"
//---------------------------------------------------------------------------
void __fastcall CTransLink::Apply(void)
{
	if(!FTransLinkProp) return;
   ModelTypeIndex = FTransLinkProp->RGModelType->ItemIndex;
   K = FTransLinkProp->K;
   n = FTransLinkProp->n;
   N = (long double*)realloc(N, sizeof(long double)*FTransLinkProp->n);
   memcpy(N, FTransLinkProp->N, sizeof(long double)*(FTransLinkProp->n));
   m = FTransLinkProp->m;
   T = (long double*)realloc(T, sizeof(long double)*FTransLinkProp->m);
   memcpy(T, FTransLinkProp->T, sizeof(long double)*(FTransLinkProp->m));
   if(ModelTypeIndex == 1)
   {
   	long double *Tmp = NULL;
      Tmp = (long double*)realloc(Tmp, sizeof(long double)*2);
      Tmp[0] = FTransLinkProp->N[0];
      Tmp[1] = 1.0;
      for(DWORD ci = 1; ci < FTransLinkProp->n; ci++)
      {
      	MulPoly(Tmp, ci + 1, FTransLinkProp->N[ci]);
      }
      FTransLinkProp->N = (long double*)realloc(FTransLinkProp->N, sizeof(long double)*(FTransLinkProp->n + 1));
      for(DWORD ci = 0; ci <= FTransLinkProp->n; ci++)
      {
      	Tmp[ci] *= K;
         FTransLinkProp->N[FTransLinkProp->n - ci] = Tmp[ci];
      }
      Tmp = (long double*)realloc(Tmp, sizeof(long double)*2);
      Tmp[0] = FTransLinkProp->T[0];
      Tmp[1] = 1.0;
      for(DWORD ci = 1; ci < FTransLinkProp->m; ci++)
      {
      	MulPoly(Tmp, ci + 1, FTransLinkProp->T[ci]);
      }
      FTransLinkProp->T = (long double*)realloc(FTransLinkProp->T, sizeof(long double)*(FTransLinkProp->m + 1));
      for(DWORD ci = 0; ci <= FTransLinkProp->m; ci++)
      	FTransLinkProp->T[FTransLinkProp->m - ci] = Tmp[ci];
      Tmp = (long double*)realloc(Tmp, 0);
   }
   //ubrat nahren
   delete [] U_kof; U_kof=NULL;
  	delete [] V_kof; V_kof=NULL;
   if(!ModelTypeIndex)
   	stepen = m > n ? m:n;
   else
   	stepen = m > n ? m + 1:n + 1;
   long double *B_i = new long double[stepen];
   ZeroMemory(B_i, sizeof(long double)*stepen);
   long double *A_i = new long double[stepen];
   ZeroMemory(A_i, sizeof(long double)*stepen);
   stepen--;
   if(!ModelTypeIndex)
   {
   	memcpy(B_i, FTransLinkProp->T, sizeof(long double)*m);
      memcpy(A_i, FTransLinkProp->N, sizeof(long double)*n);
   }
   else
   {
   	memcpy(B_i, FTransLinkProp->T, sizeof(long double)*(m + 1));
      memcpy(A_i, FTransLinkProp->N, sizeof(long double)*(n + 1));
   }
   U_Stepen = 0;
   astotizm = false;
   ERROR_V = false;
   Stepen_astotizma = 0;
   U_Stepen_bolshe = false;
   int ii = stepen;
   while((B_i[ii] == 0.0) && (ii >= 0))
   {
    	if(A_i[ii] != 0.0) U_Stepen_bolshe = true;
   	if(U_Stepen_bolshe) U_Stepen++;
      stepen--;
      ii--;
   }
   U_kof = new complex<long double>[stepen + U_Stepen + 1];
   V_kof = new complex<long double>[stepen + 1];
   for(int i = 0; i < stepen + 1; i++)
   {
   	V_kof[i] = complex<long double>(B_i[i], 0.0);
   }
   for(int i = 0; i < stepen + U_Stepen + 1; i++)
   {
   	U_kof[i] = complex<long double>(A_i[i], 0.0);
   }
   if(stepen <= 0) ERROR_V = true;
   delete []B_i;
   delete []A_i;
   switch(FTransLinkProp->RGAlgType->ItemIndex)
   {
   	case 0: Algoritm = ANALOG_Z_PREOB; break;
      case 1: Algoritm = ANALOG_RAG_BERG_PREOB; break;
      case 2: Algoritm = DISKR_DM_PREOB; break;
   }
   CharGroup = FTransLinkProp->CharGroup;
   CharTIndex = FTransLinkProp->CharTIndex;
   CharFIndex = FTransLinkProp->CharFIndex;
   T1 = FTransLinkProp->T1;
   T2 = FTransLinkProp->T2;
   DT = FTransLinkProp->DT;
   W1 = FTransLinkProp->W1;
   W2 = FTransLinkProp->W2;
   DW = FTransLinkProp->DW;
}
//---------------------------------------------------------------------------
CTransLink::CTransLink(void):CStdElement()
{
   FChar = NULL;
   FTransLinkProp = NULL;
   FG = NULL;
   FNPChar = NULL;
   ID_OBJECT = ID_TRANSLINK;
   A_d = NULL;
	B_d = NULL;
	K_1 = NULL; A_z0 = NULL; B_z1 = NULL;
	B_z1 = NULL; A_z0 = NULL; P_i = NULL;
	YYY_j = NULL; U_Stepen = 0;
	U_z_Step = 0;
	stepen = 2;
	astotizm = false;
	ERROR_V = false;
	Stepen_astotizma = 0;
	U_Stepen_bolshe = 0;
	Algoritm = ANALOG_Z_PREOB;
	diskr_w = 1000;
	w_max = 1000.;
   ElName = "Передаточное звено";
	Kof = NULL;
	Vast_kof = NULL;
	Nign_kof = NULL;
	FAZA = NULL;
	Amplituda = NULL;
	LAHX = NULL;
   CharGroup = 0;
   CharTIndex = 0;
   CharFIndex = 0;
   T1 = 0.0;
   T2 = 100.0;
   DT = 0.01;
   W1 = 0.0;
   W2 = 100.0;
   DW = 0.01;
   ModelTypeIndex = 0;
   K = 1.0;
   U_kof = new complex<long double> [stepen + U_Stepen + 1];
	U_kof[0] = complex <long double>(0.8,0.0);
	U_kof[1] = complex <long double>(0.0,0.0);
	U_kof[2] = complex <long double>(0.0,0.0);
	V_kof = new complex<long double> [stepen + 1];
	V_kof[0] = complex <long double>(1.0,0.0);
	V_kof[1] = complex <long double>(0.7,0.0);
	V_kof[2] = complex <long double>(0.08,0.0);
   n = 1;
   m = 3;
   N = NULL;
   T = NULL;
   N = (long double*)realloc(N, sizeof(long double)*n);
   T = (long double*)realloc(T, sizeof(long double)*m);
   for(DWORD ci = 0; ci < n; ci++) N[ci] = real(U_kof[ci]);
   for(DWORD ci = 0; ci < m; ci++) T[ci] = real(V_kof[ci]);
}
//---------------------------------------------------------------------------
void CTransLink::MulPoly(long double *&A, DWORD N, long double T)
{
	TPolyVal *PV = new TPolyVal[N*2];
   DWORD cj = 0;
   for(DWORD ci = 0; ci < N*2 - 1; ci += 2)
   {
   	PV[ci].Pow = N - cj;
      PV[ci].Val = A[cj]*T;
   	PV[ci + 1].Pow = N - cj - 1;
      PV[ci + 1].Val = A[cj];
      cj++;
      if(cj >= N) cj = 0;
   }
   A = (long double*)realloc(A, sizeof(long double)*(N + 1));
   for(DWORD ci = 0; ci <= N; ci++)
   {
   	A[N - ci] = 0.0;
   	for(DWORD cj = 0; cj < N*2; cj++)
      {
      	if(PV[cj].Pow == ci) A[N - ci] += PV[cj].Val;
      }
   }
   delete []PV;
}
//---------------------------------------------------------------------------
void __fastcall CTransLink::CalcRoots(complex <long double> *&Polusa, complex <long double> * &Nyli, int &n_st, int &m_st )
{
n_st=n, m_st=m;
if(ModelTypeIndex==0)
{n_st--;m_st--;}
else
{

}

if(n_st!=0)
Polusa = new complex <long double> [n_st];
if(m_st!=0)
Nyli = new complex <long double> [m_st];

if(ModelTypeIndex==0)
{
if(m_st!=0)
{
fcomplex* V1 = new fcomplex [m_st+1];
for(int i=0;i<m_st+1;i++)
    {
     V1[i].r=real(V_kof[i]);
     V1[i].i=imag(V_kof[i]);
    }
   fcomplex* b = new fcomplex [m_st+1];
   for(int i=0;i<m_st+1;i++)
    {b[i].r=0;b[i].i=0; }
 int k;
 zroots(V1,m_st,b,k); //определение корней полиномв
   for(int i=0;i<m_st;i++)
    Nyli[i]=complex <long double>(b[i+1].r,b[i+1].i);
  delete [] V1; V1=NULL;
  delete [] b; b=NULL;
}
if(n_st!=0)
{
fcomplex*V1 = new fcomplex [n_st+1];
for(int i=0;i<n_st+1;i++)
    {
     V1[i].r=real(U_kof[i]);
     V1[i].i=imag(U_kof[i]);
    }
fcomplex*   b = new fcomplex [n_st+1];
   for(int i=0;i<n_st+1;i++)
    {b[i].r=0;b[i].i=0; }
 int k;
 zroots(V1,n_st,b,k); //определение корней полиномв
   for(int i=0;i<n_st;i++)
    Polusa[i]=complex <long double>(b[i+1].r,b[i+1].i);
  delete [] V1; V1=NULL;
  delete [] b; b=NULL;
}
}
else
{
if(m_st!=0)
{
int ii=0;
for(int i=0;i<m_st;i++)
if(T[i]!=0.) {Nyli[ii] = complex <long double>(-1/T[i],0.0);ii++; }

complex <long double> * nnn = new complex <long double> [ii];
m_st=ii;
for(int i=0;i<m_st;i++)
nnn[i]=Nyli[i];
delete [] Nyli; Nyli = NULL;
Nyli = new complex <long double> [m_st];
for(int i=0;i<m_st;i++)
Nyli[i]=nnn[i];
delete [] nnn; nnn = NULL;
}

if(n_st!=0)
{
int ii=0;
for(int i=0;i<n_st;i++)
if(N[i]!=0.) {Polusa[ii] = complex <long double>(-1/N[i],0.0);ii++ ;}

complex <long double> * nnn = new complex <long double> [ii];
n_st=ii;
for(int i=0;i<n_st;i++)
nnn[i]=Polusa[i];
delete [] Polusa; Polusa = NULL;
Polusa = new complex <long double> [m_st];
for(int i=0;i<n_st;i++)
Polusa[i]=nnn[i];
delete [] nnn; nnn = NULL;
}
}
//delete [] Polusa; Polusa=NULL;
//delete [] Nuli; Nyli = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CTransLink::SetData(void)
{
	FTransLinkProp = new TFTransLinkProp(Application);
   FTransLinkProp->RGModelType->ItemIndex = ModelTypeIndex;
   FTransLinkProp->RGModelType->OnClick(FTransLinkProp->RGModelType);
   if(ModelTypeIndex) FTransLinkProp->EK->Text = FloatToStr(K);
   FTransLinkProp->K = K;
   switch(Algoritm)
   {
   	case ANALOG_Z_PREOB:
        	FTransLinkProp->RGAlgType->ItemIndex = 0;
      break;
      case ANALOG_RAG_BERG_PREOB:
         FTransLinkProp->RGAlgType->ItemIndex = 1;
      break;
      case DISKR_DM_PREOB:
         FTransLinkProp->RGAlgType->ItemIndex = 2;
      break;
   }
   FTransLinkProp->ENs->Text = FTransLinkProp->ArrayToStr(N, n);
   FTransLinkProp->ETs->Text = FTransLinkProp->ArrayToStr(T, m);
   FTransLinkProp->ShowChar =	ShowChar;
   FTransLinkProp->Apply =	Apply;
   FTransLinkProp->CharGroup = CharGroup;
   FTransLinkProp->CharTIndex = CharTIndex;
   FTransLinkProp->CharFIndex = CharFIndex;
  	FTransLinkProp->T1 = T1;
  	FTransLinkProp->T2 = T2;
  	FTransLinkProp->DT = DT;
  	FTransLinkProp->W1 = W1;
  	FTransLinkProp->W2 = W2;
  	FTransLinkProp->DW = DW;
   FTransLinkProp->ShowModal();
   if(FTransLinkProp->ResultOk) Apply();
   FTransLinkProp->Free();
}
//---------------------------------------------------------------------------
void __fastcall CTransLink::ShowChar(int CharIndex, long double D1, long double D2, long double DD)
{
   if(D1 > D2)
   {
   	long double Tmp = D2;
      D2 = D1;
      D1 = Tmp;
   }
   long double *X = NULL;
   long double *Y = NULL;
   long double NumSteps = (D2 - D1)/DD;
   AnsiString AxX = "", AxY = "", Caption = "";
   switch(CharIndex)
   {
   	case 0:
      	Opred_Kof_Perechodnoi(false);
         Opred_Tochek_Perechodnoi(X, Y, NumSteps, D1, D2);
         Caption = "Переходная характеристика";
         AxX = "t";
         AxY = "h(t)";
      break;
   	case 1:
      	Opred_Kof_Perechodnoi(true);
         Opred_Tochek_Perechodnoi(X, Y, NumSteps, D1, D2);
         Caption = "Импульсная характеристика";
         AxX = "t";
         AxY = "k(t)";
      break;
   	case 2:
      	AChX(X, Y, NumSteps, D1, D2);
         Caption = "АЧХ";
         AxX = "w";
         AxY = "A(w)";
      break;
   	case 3:
      {
      	AChX(X, Y, NumSteps, D1, D2);
         long double *TmpX = new long double[DWORD(NumSteps)];
         long double *TmpY = new long double[DWORD(NumSteps)];
         DWORD cj = 0, TmpNS = NumSteps;
         for(DWORD ci = 0; ci < NumSteps; ci++)
         {
         	if(X[ci] > 0 && Y[ci] > 0)
            {
            	TmpX[cj] = log10l(X[ci]);
               TmpY[cj] = 20*log10l(Y[ci]);
               cj++;
            }
            else TmpNS--;
         }
         delete []X;
         delete []Y;
         NumSteps = TmpNS;
         X = new long double[NumSteps];
         Y = new long double[NumSteps];
         memcpy(X, TmpX, sizeof(long double)*NumSteps);
         memcpy(Y, TmpY, sizeof(long double)*NumSteps);
         delete []TmpX;
         delete []TmpY;
         Caption = "ЛАЧХ";
         AxX = "lg(w)";
         AxY = "20lg{A(w)}, дБ";
      }
      break;
   	case 4:
      	FChX(X, Y, NumSteps, D1, D2, true);
         Caption = "ФЧХ";
         AxX = "w";
         AxY = "Ф(w)";
      break;
   	case 5:
      {
      	FChX(X, Y, NumSteps, D1, D2, true);
         long double *TmpX = new long double[DWORD(NumSteps)];
         long double *TmpY = new long double[DWORD(NumSteps)];
         DWORD cj = 0, TmpNS = NumSteps;
         for(DWORD ci = 0; ci < NumSteps; ci++)
         {
         	if(X[ci] > 0)
            {
            	TmpX[cj] = log10l(X[ci]);
               TmpY[cj] = Y[ci];
               cj++;
            }
            else TmpNS--;
         }
         delete []X;
         delete []Y;
         NumSteps = TmpNS;
         X = new long double[NumSteps];
         Y = new long double[NumSteps];
         memcpy(X, TmpX, sizeof(long double)*NumSteps);
         memcpy(Y, TmpY, sizeof(long double)*NumSteps);
         delete []TmpX;
         delete []TmpY;
         Caption = "ФЧХ";
         AxX = "w";
         AxY = "lg{Ф(w)}, дБ";
      }
      break;
   	case 6:
      	AFChX(X, Y, NumSteps, D1, D2);
         Caption = "АФЧХ";
         AxX = "Re(w)";
         AxY = "Im(w)";
      break;
   	case 7:
      	int dn, dm;
         complex<long double> *Polus = NULL;
         complex<long double> *Null = NULL;
         CalcRoots(Polus, Null, dn, dm);
         FNPChar = new TFNPChar(Application);
         for(int ci = 0; ci < dn; ci++)
         	FNPChar->AddRoot(real(Polus[ci]), imag(Polus[ci]), "NULL");
         for(int ci = 0; ci < dm; ci++)
         	FNPChar->AddRoot(real(Null[ci]), imag(Null[ci]), "POLUS");
         FNPChar->ShowModal();
         FNPChar->Free();
         if(Polus) delete []Polus;
         if(Null) delete []Null;
         return;
      break;
   }
   FGrp->SetAxNames(AxX, AxY);
   FGrp->Caption = Caption;
   FGrp->AddSer(X, Y, NumSteps, ElName + ":Состояние");
   FGrp->ShowModal();
}
//---------------------------------------------------------------------------
void CTransLink::FazaHarakteristik()
{
delete []FAZA;FAZA=NULL;
delete []Amplituda;Amplituda=NULL;
delete []LAHX;LAHX=NULL;
FAZA= new complex<long double>[diskr_w];
Amplituda=new complex<long double>[diskr_w];
LAHX=new complex<long double>[diskr_w];
for(int i=0;i<diskr_w;i++)
 {
      complex<long double> U=complex<long double>(0.0,0.0);
      complex<long double> V=complex<long double>(0.0,0.0);
      complex<long double> F=complex<long double>(0.0,0.0);
      for(int j=0;j<stepen+U_Stepen+1;j++)
      {
        U=U+U_kof[j]*pow(complex<long double>(0.0,(long double)w_max/diskr_w*i),j);
      }
      for(int j=0;j<stepen+1;j++)
      {
        V=V+V_kof[j]*pow(complex<long double>(0.0,(long double)w_max/diskr_w*i),j);
      }
   FAZA[i]=U/V;
   Amplituda[i]=complex<long double>(real(FAZA[i])*real(FAZA[i])+imag(FAZA[i])*imag(FAZA[i]), 0.0);
   LAHX[i]=complex<long double>(20*log(real(Amplituda[i])), 0.0);
}
}
//---------------------------------------------------------------------------
CTransLink::~CTransLink()
{
	if(N){N = (long double*)realloc(N, 0); N = NULL;}
   if(T){T = (long double*)realloc(T, 0); T = NULL;}
delete []A_d; A_d=NULL;
delete []B_d; B_d = NULL;
delete []FAZA;FAZA=NULL;
delete []Amplituda;Amplituda=NULL;
delete []LAHX;LAHX=NULL;
// Пер функция
this->Del_YYY();
delete [] U_kof; U_kof=NULL;
delete [] V_kof; V_kof=NULL;
delete []P_i;P_i=NULL;
delete []K_1;K_1=NULL;
delete []A_z0; A_z0=NULL;
delete []B_z1; B_z1=NULL;
delete [] Kof; Kof=NULL;
delete [] Vast_kof; Vast_kof=NULL;
delete [] Nign_kof; Nign_kof=NULL;
}
//---------------------------------------------------------------------------
void CTransLink::FUNKCIJA(int index, int end, long double DT)
{
	if(index == 0)
	{
   	if(Algoritm == DISKR_DM_PREOB)
      	Opred_Kof_DM(DT);
      else
      	Opred_Kof_Diskr_Perechodnoi(end, DT);
	}
	if(stepen >= 0)
	{
   	if(Algoritm == DISKR_DM_PREOB) DM_preobraz(index);
      if(Algoritm == ANALOG_Z_PREOB) Analog_Z_preobraz(index);
 		if(Algoritm == ANALOG_RAG_BERG_PREOB) Analog_RagaziniBerger_preobraz(index);
 		if(index == end) Del_YYY();
   }
	else
   	Out[index] = In[index];
}
//---------------------------------------------------------------------------
void CTransLink::Opred_Kof_Diskr_Perechodnoi(int end, long double DT)
{
	delete []P_i; P_i = NULL;
	delete []K_1; K_1 = NULL;
	delete []A_z0; A_z0 = NULL;
	delete []B_z1; B_z1 = NULL;
	Del_YYY();
 		int ii = 0;
 		while((V_kof[ii] == complex <long double>(0.0,0.0))&&(ii<=stepen))
 		{
 			if(!U_Stepen_bolshe)
  			{
         	if(U_kof[stepen-ii] != complex <long double>(0.0,0.0))
            {
            	U_Stepen_bolshe = true;
            	U_Stepen = 1;
         	}
  			}
 			else
         	U_Stepen++;
 			ii++;
 			astotizm = true;
 			Stepen_astotizma++;
 			if((Stepen_astotizma == (stepen + 1)) &&
            (V_kof[stepen] == complex<long double>(0.0,0.0)))
         	ERROR_V = true;
 		}
		if(U_kof[stepen] != complex<long double>(0.0,0.0)) U_z_Step = 1;
		U_z_Step = U_z_Step + U_Stepen;
	if(!ERROR_V)
	{
		if(astotizm)
 		{
  			complex<long double> *Vast_kof = new complex<long double> [stepen-Stepen_astotizma+1];
  			for(int i = 0; i < stepen-Stepen_astotizma + 1; i++)
   			Vast_kof[i]=V_kof[i+Stepen_astotizma];
   		fcomplex *V1 = new fcomplex[stepen - Stepen_astotizma + 1];
   		for(int i = 0; i < stepen - Stepen_astotizma + 1; i++)
    		{
     			V1[i].r = real(Vast_kof[i]);
     			V1[i].i = imag(Vast_kof[i]);
    		}
   		fcomplex *b = new fcomplex[stepen - Stepen_astotizma + 1];
   		for(int i = 0; i < stepen - Stepen_astotizma + 1; i++)
    		{
         	b[i].r = 0;
            b[i].i = 0;
         }
   		int k;
 			zroots(V1, stepen - Stepen_astotizma, b, k);
   		P_i = new complex<long double>[stepen - Stepen_astotizma];
   		for(int i = 0; i < stepen - Stepen_astotizma; i++)
    		{
    			P_i[i] = complex <long double>(b[i + 1].r, b[i + 1].i);
    		}
 			complex <long double> Vspom1 = complex<long double>(0.0,0.0);
 			complex <long double> Vspom2 = complex <long double>(0.0,0.0);
 			complex <long double> *V_strih = new complex<long double>[stepen - Stepen_astotizma];
 			K_1 = new complex<long double>[stepen - Stepen_astotizma + U_z_Step*(stepen - Stepen_astotizma)];
   		for(int i = stepen - Stepen_astotizma - 1; i >= 0; i--)
   			V_strih[i] = Vast_kof[i + 1]*(long double)(i + 1);
   		for(int i = 0; i < stepen - Stepen_astotizma; i++)
    		{
         	Vspom1 = complex<long double>(0.0,0.0);
     			Vspom2 = complex <long double>(0.0,0.0);
       		for(int j = 0; j < stepen - Stepen_astotizma; j++)
      		{
       			Vspom2 = Vspom2 + V_strih[j]*pow(P_i[i], j);
       			Vspom1 = Vspom1 + U_kof[j]*pow(P_i[i], j);
      		}
     			if(Vspom2 == complex<long double>(0.0,0.0))
            	K_1[i] = complex <long double>(0.0,0.0);
     			else
     				for(int jj = 0; jj < U_z_Step + 1; jj++)
       			{
        				if(jj == 0)
         				K_1[i] = Vspom1/(Vspom2*pow(P_i[i],Stepen_astotizma));
        				else
          				K_1[i + jj*(stepen - Stepen_astotizma)] = U_kof[stepen - Stepen_astotizma + jj - 1]*pow(P_i[i],stepen - Stepen_astotizma + jj - 1)/(Vspom2*pow(P_i[i],Stepen_astotizma));
        			}
     				YYY_j=new complex<long double>* [stepen-Stepen_astotizma+U_z_Step*(stepen-Stepen_astotizma)];
     for(int ik=0;ik<stepen-Stepen_astotizma+U_z_Step*(stepen-Stepen_astotizma);ik++)
     YYY_j[ik]=new complex<long double> [end];
     A_z0= new complex<long double> [stepen-Stepen_astotizma+U_z_Step*(stepen-Stepen_astotizma)];
     B_z1= new complex<long double> [stepen-Stepen_astotizma+U_z_Step*(stepen-Stepen_astotizma)];
     for(int jj=0;jj<U_z_Step+1;jj++)
     for(int i=0;i<stepen-Stepen_astotizma;i++)
        {
        if(Algoritm==ANALOG_Z_PREOB)
         {
         A_z0[i+(stepen-Stepen_astotizma)*jj]=K_1[i+(stepen-Stepen_astotizma)*jj]*complex<long double>(DT, 0.0)/(complex<long double>(1.0,0.0)-complex<long double>(DT, 0.0)*P_i[i]);
         B_z1[i+(stepen-Stepen_astotizma)*jj]=-complex<long double>(1.0,0.0)/(complex<long double>(1.0,0.0)-complex<long double>(DT, 0.0)*P_i[i]);
         }
        else
         {
         A_z0[i+(stepen-Stepen_astotizma)*jj]=K_1[i+(stepen-Stepen_astotizma)*jj]*complex<long double>(DT, 0.0);
         B_z1[i+(stepen-Stepen_astotizma)*jj]=-complex<long double>(1.0,0.0)-complex<long double>(DT, 0.0)*P_i[i];
         }
        }
     }
 delete [] Vast_kof; Vast_kof=NULL;
 delete [] V_strih; V_strih=NULL;
 delete [] V1; V1=NULL;
 delete [] b; b=NULL;
 }
else //астотизма в знаменателе нет
 {
 P_i=new complex<long double> [stepen];
   fcomplex* V1 = new fcomplex [stepen+1];
   for(int i=0;i<stepen+1;i++)
    {
     V1[i].r=real(V_kof[i]);
     V1[i].i=imag(V_kof[i]);
    }
   fcomplex* b = new fcomplex [stepen+1];
   for(int i=0;i<stepen+1;i++)
    {b[i].r=0;b[i].i=0; }
   int k;
 zroots(V1,stepen,b,k); //определение корней полиномв
//  P_i=new complex<long double> [stepen];
   for(int i=0;i<stepen;i++)
    P_i[i]=complex <long double>(b[i+1].r,b[i+1].i);
  delete [] V1; V1=NULL;
  delete [] b; b=NULL;
  }
 complex <long double> Vspom1= complex <long double>(0.0,0.0);
 complex <long double> Vspom2= complex <long double>(0.0,0.0);
 complex<long double> *V_strih= new complex<long double> [stepen];
 K_1= new complex<long double> [stepen+U_z_Step*stepen];
   for(int i=stepen-1;i>=0;i--)
   V_strih[i]=V_kof[i+1]*(long double)(i+1);


  for(int i=0;i<stepen;i++)
    {Vspom1=complex <long double>(0.0,0.0);
     Vspom2=complex <long double>(0.0,0.0);
      for(int j=0;j<stepen;j++)
      {
       Vspom2=Vspom2+V_strih[j]*pow(P_i[i],j);
       Vspom1=Vspom1+U_kof[j]*pow(P_i[i],j);
      }
     if (Vspom2==complex <long double>(0.0,0.0)) K_1[i]=complex <long double>(0.0,0.0);
     else
      for(int jj=0;jj<U_z_Step+1;jj++)
       {
        if (jj==0)
         K_1[i]=Vspom1/Vspom2;
        else
          K_1[i+jj*stepen]=U_kof[stepen+jj-1]*pow(P_i[i],stepen+jj-1)/Vspom2;
        }
    YYY_j=new complex<long double> *[stepen+U_z_Step*stepen];
    for(int ik=0;ik<stepen+U_z_Step*stepen;ik++)
    YYY_j[ik]=new complex<long double> [end];
    A_z0= new complex<long double> [stepen+U_z_Step*stepen];
    B_z1= new complex<long double> [stepen+U_z_Step*stepen];
    for(int jj=0;jj<U_z_Step+1;jj++)
    for(int i=0;i<stepen;i++)
        {
        if(Algoritm==ANALOG_Z_PREOB)
         {
          A_z0[i+stepen*jj]=K_1[i+stepen*jj]*complex<long double>(DT, 0.0)/(complex<long double>(1.0,0.0)-complex<long double>(DT, 0.0)*P_i[i]);
          B_z1[i+stepen*jj]=-complex<long double>(1.0,0.0)/(complex<long double>(1.0,0.0)-complex<long double>(DT, 0.0)*P_i[i]);
         }
        else
         {
          A_z0[i+stepen*jj]=K_1[i+stepen*jj]*complex<long double>(DT, 0.0);
          B_z1[i+stepen*jj]=-complex<long double>(1.0,0.0)-complex<long double>(DT, 0.0)*P_i[i];
         }

        }
    }

 delete [] V_strih; V_strih=NULL;
 }
}
//---------------------------------------------------------------------------
long double CTransLink::Factorial(int n)
{
if(n>1)
{
double k=1;
for(int i=1;i<=n;i++)
k=i*k;
return k;
}
else return 1.;
}
//---------------------------------------------------------------------------
long double CTransLink::Sochetanie(int n, int k)
{
if(n<=k)
return Factorial(k)/(Factorial(n)*Factorial(k-n));
else return 1.;
}
//---------------------------------------------------------------------------
void CTransLink::Opred_Kof_DM(long double DT)
{
delete [] A_d;A_d=NULL;
delete [] B_d;B_d=NULL;
int U_st, V_st;
if(ModelTypeIndex==0)
{
U_st=n-1; V_st=m-1;
}
else
{
U_st=n; V_st=m;
}
A_d = new complex<long double> [U_st+1];
B_d = new complex<long double> [V_st+1];

for(int i=0;i<U_st+1;i++)
{
A_d[U_st-i]=complex<long double>(0.,0.);
for(int j=0;j<=i;j++)
{
A_d[U_st-i]=A_d[U_st-i]+complex<long double>(pow(-1.0,U_st-i),0.)*U_kof[U_st-j]/complex<long double>(pow(DT,U_st-j),0.)
*complex<long double>(Sochetanie(i-j,U_st-j),0.);
}
}

for(int i=0;i<V_st+1;i++)
{
B_d[V_st-i]=complex<long double>(0.,0.);
for(int j=0;j<=i;j++)
{
B_d[V_st-i]=B_d[V_st-i]+complex<long double>(pow(-1.0,V_st-i),0)*V_kof[V_st-j]/complex<long double>(pow(DT,V_st-j),0)
*complex<long double>(Sochetanie(i-j,V_st-j),0.);
}
}
}
//---------------------------------------------------------------------------
void CTransLink::Analog_Z_preobraz(int index)
{

	if(astotizm)
	{
 		for(int jj = 0; jj < U_z_Step + 1; jj++)
 			for(int j = 0; j < stepen - Stepen_astotizma; j++)
  			{
   			if(index == 0)
            	YYY_j[j + (stepen - Stepen_astotizma)*jj][index] = A_z0[j + (stepen - Stepen_astotizma)*jj]*In[index];
   			if(index > 0)
            	YYY_j[j + (stepen - Stepen_astotizma)*jj][index] = A_z0[j + (stepen - Stepen_astotizma)*jj]*In[index] - B_z1[j + (stepen - Stepen_astotizma)*jj]*YYY_j[j + (stepen - Stepen_astotizma)*jj][index - 1];
   			if((jj == 0)&&(j == 0))
            	Out[index] = YYY_j[j + stepen*jj][index];
   			else
            	Out[index] = Out[index] + YYY_j[j + stepen*jj][index];
 			}
	}
	else
	{
         if(index==0)
              {
               int U_st, V_st;
                if(ModelTypeIndex==0)
                {
                U_st=n-1; V_st=m-1;
                }
                else
                {
                U_st=n; V_st=m;
                }
               if(U_st==V_st) W0=U_kof[U_st]/V_kof[U_st];
               else W0=complex<long double>(0.0,0.0);
               }
 		for(int jj = 0; jj < U_z_Step + 1; jj++)
 			for(int j = 0; j < stepen; j++)
  			{
   			if(index == 0)
            {
            	YYY_j[j + stepen*jj][index] = A_z0[j + stepen*jj]*In[index];
            }
   			if(index >= 1)
            	YYY_j[j + stepen*jj][index] = A_z0[j + stepen*jj]*In[index] - B_z1[j + stepen*jj]*YYY_j[j + stepen*jj][index - 1];
   			if((jj == 0)&&(j == 0))
            	Out[index] = YYY_j[j + stepen*jj][index];
   			else
            	Out[index] = Out[index] + YYY_j[j + stepen*jj][index];
 			}
               if(W0!=complex<long double>(0.0,0.0))
               Out[index] = Out[index] + In[index]*W0;
	}
}
//---------------------------------------------------------------------------
void CTransLink::Analog_RagaziniBerger_preobraz(int index)
{
	if(astotizm)
	{
 		for(int jj = 0; jj < U_z_Step + 1; jj++)
 			for(int j = 0; j < stepen - Stepen_astotizma; j++)
  			{
   			if(index == 0)
            	YYY_j[j + (stepen - Stepen_astotizma)*jj][index] = complex<long double>(0.0, 0.0);
            if(index > 0)
            	YYY_j[j + (stepen - Stepen_astotizma)*jj][index] = A_z0[j + (stepen - Stepen_astotizma)*jj]*In[index - 1] - B_z1[j + (stepen - Stepen_astotizma)*jj]*YYY_j[j + (stepen - Stepen_astotizma)*jj - 1][index];
   			if((jj == 0)&&(j == 0))
            	Out[index] = YYY_j[j + stepen*jj][index];
   			else
            	Out[index] = Out[index] + YYY_j[j + stepen*jj][index];
 			}
	}
	else
	{
         if(index==0)
              {
               int U_st, V_st;
                if(ModelTypeIndex==0)
                {
                U_st=n-1; V_st=m-1;
                }
                else
                {
                U_st=n; V_st=m;
                }
               if(U_st==V_st) W0=U_kof[U_st]/V_kof[U_st];
               else W0=complex<long double>(0.0,0.0);
               }
 		for(int jj = 0; jj < U_z_Step + 1; jj++)
 			for(int j = 0; j < stepen; j++)
  			{
   			if(index == 0)
            	YYY_j[j + stepen*jj][index] = complex<long double>(0.0, 0.0);
            if(index >= 1)
            	YYY_j[j + stepen*jj][index] =
               	A_z0[j + stepen*jj]*In[index - 1] - B_z1[j + stepen*jj]*YYY_j[j + stepen*jj][index - 1];
   			if((jj == 0)&&(j == 0))
            	Out[index] = YYY_j[j + stepen*jj][index];
   			else
            	Out[index] = Out[index] + YYY_j[j + stepen*jj][index];
 			}
               if(W0!=complex<long double>(0.0,0.0))
               Out[index] = Out[index] + In[index]*W0;
	}
}
void CTransLink::DM_preobraz(int index)
{
complex<long double> AA=complex<long double>(0.,0.);
complex<long double> BB=complex<long double>(0.,0.);
for(DWORD i = 0;i<n;i++)
{
 if((index-i)>=0) AA=AA+A_d[i]*In[index-i];
}
for(DWORD i = 1;i<m;i++)
{
 if((index-i)>=0) BB=BB+B_d[i]*Out[index-i];
}
Out[index] = (AA-BB)/B_d[0];
}

//---------------------------------------------------------------------------
void CTransLink::Del_YYY()
{
if(YYY_j!=NULL)
 if (astotizm)
 {
  for(int ik=0;ik<stepen-Stepen_astotizma+U_z_Step*(stepen-Stepen_astotizma);ik++)
   delete [] YYY_j[ik];
   delete [] YYY_j;  YYY_j=NULL;
 }
 else
 {
  for(int ik=0;ik<stepen+U_z_Step*stepen;ik++)
   //delete [] YYY_j[ik];
   if(YYY_j!=NULL)
   {delete [] YYY_j;  YYY_j=NULL;}
 }
}
//----------------------------------------------------------------------
void CTransLink::Opred_Kof_Perechodnoi(bool Impulsno_per)
{
W0 =complex <long double>(0.,0.);
delete [] Kof; Kof=NULL;
delete [] P_i; P_i=NULL;
int ii=0;
while((V_kof[ii]==complex <long double>(0.0,0.0))&&(ii<=stepen))
{
if(!U_Stepen_bolshe)
{if(U_kof[stepen-ii]!=complex <long double>(0.0,0.0)) {U_Stepen_bolshe=true;
                                U_Stepen=1;}
}
else U_Stepen++;
ii++;
astotizm=true;
Stepen_astotizma++;
if((Stepen_astotizma==(stepen+1))&&(V_kof[stepen]==complex <long double>(0.0,0.0)))ERROR_V=true; //нулевой знаменатель
}
if(!ERROR_V)
{
if(astotizm)//умножение знаменателя на S в степени n
 {
  delete [] Vast_kof; Vast_kof=NULL;
  Vast_kof=new complex<long double> [stepen-Stepen_astotizma+1];
  for(int i=0;i<stepen-Stepen_astotizma+1;i++)
   Vast_kof[i]=V_kof[i+Stepen_astotizma];
    if (Impulsno_per) W0=0;
   else W0=U_kof[0]/Vast_kof[0];

   fcomplex* V1 = new fcomplex [stepen-Stepen_astotizma+1];
   for(int i=0;i<stepen-Stepen_astotizma+1;i++)
    {
     V1[i].r=real(Vast_kof[i]);
     V1[i].i=imag(Vast_kof[i]);
    }
   fcomplex* b = new fcomplex [stepen-Stepen_astotizma+1];
   for(int i=0;i<stepen-Stepen_astotizma+1;i++)
    {b[i].r=0;b[i].i=0; }
   int k;
 zroots(V1,stepen-Stepen_astotizma,b,k); //определение корней полиномв
   P_i=new complex<long double> [stepen-Stepen_astotizma];
   for(int i=0;i<stepen-Stepen_astotizma;i++)
    {
    P_i[i]=complex <long double>(b[i+1].r,b[i+1].i);
    }
 complex <long double> Vspom1= complex <long double>(0.0,0.0);
 complex <long double> Vspom2= complex <long double>(0.0,0.0);
 complex<long double> *V_strih= new complex<long double> [stepen-Stepen_astotizma];
 Kof= new complex<long double> [stepen-Stepen_astotizma];
   delete [] Nign_kof; Nign_kof=NULL;
   Nign_kof=new complex<long double> [stepen-Stepen_astotizma];
   for(int i=stepen-Stepen_astotizma-1;i>=0;i--)
   V_strih[i]=Vast_kof[i+1]*(long double)(i+1);

   for(int i=0;i<stepen-Stepen_astotizma;i++)
    {Vspom1=complex <long double>(0.0,0.0);
     Vspom2=complex <long double>(0.0,0.0);
      for(int j=0;j<stepen-Stepen_astotizma+1;j++)
      {
       if(j==stepen-Stepen_astotizma);
       else
       Vspom2=Vspom2+V_strih[j]*pow(P_i[i],j);
       Vspom1=Vspom1+U_kof[j]*pow(P_i[i],j);
      }
     if ((P_i[i]*Vspom2)==complex <long double>(0.0,0.0)) Kof[i]=complex <long double>(0.0,0.0);
     else {if (Impulsno_per) Kof[i]=Vspom1/Vspom2;
           else Kof[i]=Vspom1/(P_i[i]*Vspom2);
           if (Impulsno_per)Nign_kof[i]=Vspom2;
           else Nign_kof[i]=(P_i[i]*Vspom2);
//        Form1->Memo1->Lines->Add(FloatToStr(real(Kof[i]))+" + j"+FloatToStr(imag(Kof[i])));
          }
    }
 delete [] V_strih; V_strih=NULL;
 delete [] V1; V1=NULL;
 delete [] b; b=NULL;
 }
else //астотизма в знаменателе нет
 {
 if (Impulsno_per) W0=0;
 else W0=U_kof[0]/V_kof[0];
   fcomplex* V1 = new fcomplex [stepen+1];
   for(int i=0;i<stepen+1;i++)
    {
     V1[i].r=real(V_kof[i]);
     V1[i].i=imag(V_kof[i]);
    }
   fcomplex* b = new fcomplex [stepen+1];
   for(int i=0;i<stepen+1;i++)
    {b[i].r=0;b[i].i=0; }
   int k;
 zroots(V1,stepen,b,k); //определение корней полиномв
   P_i=new complex<long double> [stepen];
   for(int i=0;i<stepen;i++)
    {
    P_i[i]=complex <long double
    >(b[i+1].r,b[i+1].i);
    }
 complex <long double> Vspom1= complex <long double>(0.0,0.0);
 complex <long double> Vspom2= complex <long double>(0.0,0.0);
 complex<long double> *V_strih= new complex<long double> [stepen];
 Kof= new complex<long double> [stepen];
 if(U_Stepen_bolshe)
  {
   delete [] Nign_kof; Nign_kof=NULL;
   Nign_kof=new complex<long double> [stepen];
  }
   for(int i=stepen-1;i>=0;i--)
   V_strih[i]=V_kof[i+1]*(long double)(i+1);
  for(int i=0;i<stepen;i++)
    {Vspom1=complex <long double>(0.0,0.0);
     Vspom2=complex <long double>(0.0,0.0);
      for(int j=0;j<stepen+1;j++)
      {
       if(j==stepen);
       else
       Vspom2=Vspom2+V_strih[j]*pow(P_i[i],j);
       Vspom1=Vspom1+U_kof[j]*pow(P_i[i],j);
      }
     if ((P_i[i]*Vspom2)==complex <long double>(0.0,0.0)) Kof[i]=complex <long double>(0.0,0.0);
     else {if (Impulsno_per) Kof[i]=Vspom1/(Vspom2);
           else Kof[i]=Vspom1/(P_i[i]*Vspom2);

           if(U_Stepen_bolshe)
            if (Impulsno_per) Nign_kof[i]=(Vspom2);
            else Nign_kof[i]=(P_i[i]*Vspom2);
//           Form1->Memo1->Lines->Add(FloatToStr(real(Kof[i]))+" + j"+FloatToStr(imag(Kof[i])));
          }
    }
 delete [] V_strih; V_strih=NULL;
 delete [] V1; V1=NULL;
 delete [] b; b=NULL;
 }
}
}
//---------------------------------------------------------------------------
void CTransLink::Opred_Tochek_Perechodnoi(long double * &X ,long double * &Y, int N, long double sdvig_T, long double T)
{
long double delta_T = (T-sdvig_T)/(long double)N;
if(X!=NULL) { delete [] X; X=NULL;}
if(Y!=NULL) { delete [] Y; Y=NULL;}
X = new long double [N];
Y = new long double [N];

if(!ERROR_V)
{
complex<long double> *X_tt=new complex<long double> [N];
//Max_Toch=0;Min_Toch=0;
if (astotizm) //астоизм в знаменателе
 {
 if(U_Stepen_bolshe) //верхняя больше нижней
  {
    complex<long double> vsp;
    complex<long double> Vsp_Delitel;
    for(int ind=0;ind<N;ind++)
    {
     for(int  j=0;j<stepen-Stepen_astotizma;j++)
     {
      for(int kk=0;kk<Stepen_astotizma;kk++)
      {
       if(kk==0) Vsp_Delitel=P_i[j];
       else Vsp_Delitel=Vsp_Delitel*P_i[j];
      }
     X_tt[ind]=X_tt[ind]+Kof[j]*exp(P_i[j]*complex<long double>(delta_T*(long double)ind+sdvig_T,0))/Vsp_Delitel
    -Kof[j]/Vsp_Delitel;
     }
     for(int  ij=stepen-Stepen_astotizma+1;ij<stepen-Stepen_astotizma+U_Stepen+1;ij++)
     {
      for(int  j=0;j<stepen-Stepen_astotizma;j++)
      {
       for(int kk=0;kk<Stepen_astotizma;kk++)
        {
        if(kk==0) Vsp_Delitel=P_i[j];
        else Vsp_Delitel=Vsp_Delitel*P_i[j];
        }
       for(int  i=1;i<=ij;i++)
        {
        if(i==1) vsp=P_i[j];
        if(i>1)  vsp=vsp*P_i[j];
        }
       X_tt[ind]=X_tt[ind]+(U_kof[ij]/Nign_kof[j])*vsp*exp(P_i[j]*complex<long double>(delta_T*(long double)ind+sdvig_T,0))/Vsp_Delitel;
//       -(U_kof[ij]/Nign_kof[j])*vsp/Vsp_Delitel;
       }
      }
     Y[ind] = real(X_tt[ind]);
     X[ind] = (long double)ind*T/(long double)N;
//     if (Max_Toch<real(X_tt[ind])) Max_Toch=real(X_tt[ind]);
//     if (Min_Toch>real(X_tt[ind])) Min_Toch=real(X_tt[ind]);
    }
  }
 else //верхняя степень не больше нижней
  {
   complex<long double> Vsp_Delitel;
   for(int i=0;i<N;i++)
   {
    for(int  j=0;j<stepen-Stepen_astotizma;j++)
    {
      for(int kk=0;kk<Stepen_astotizma;kk++)
      {
       if(kk==0) Vsp_Delitel=P_i[j];
       else Vsp_Delitel=Vsp_Delitel*P_i[j];
      }
    X_tt[i]=X_tt[i]+Kof[j]*exp(P_i[j]*complex<long double>(delta_T*(long double)i+sdvig_T,0))/Vsp_Delitel
    -Kof[j]/Vsp_Delitel;
    }
    Y[i] = real(X_tt[i]);
    X[i] = (long double)i*T/(long double)N;
//    if (Max_Toch<real(X_tt[i])) Max_Toch=real(X_tt[i]);
//    if (Min_Toch>real(X_tt[i])) Min_Toch=real(X_tt[i]);
   }
  }
 }
else
 {
if(U_Stepen_bolshe)
 {
 complex<long double> vsp;
 for(int ind=0;ind<N;ind++)
 {
   for(int  j=0;j<stepen;j++)
   X_tt[ind]=X_tt[ind]+Kof[j]*exp(P_i[j]*complex<long double>(delta_T*(long double)ind+sdvig_T,0));
   X_tt[ind]=X_tt[ind]+W0;

   for(int  ij=stepen+1;ij<stepen+U_Stepen+1;ij++)
   {
    for(int  j=0;j<stepen;j++)
    {
     for(int  i=1;i<=ij;i++)
      {
      if(i==1) vsp=P_i[j];
      if(i>1)  vsp=vsp*P_i[j];
      }
    if(j>=0)
    X_tt[ind]=X_tt[ind]+(U_kof[ij]/Nign_kof[j])*vsp*exp(P_i[j]*complex<long double>(delta_T*(long double)ind+sdvig_T,0));
    }
   }
     Y[ind] = real(X_tt[ind]);
     X[ind] = (long double)ind*T/(long double)N;
//   if (Max_Toch<real(X_tt[ind])) Max_Toch=real(X_tt[ind]);
//   if (Min_Toch>real(X_tt[ind])) Min_Toch=real(X_tt[ind]);
 }
 }
 else
 for(int i=0;i<N;i++)
  {
   for(int  j=0;j<stepen;j++)
   X_tt[i]=X_tt[i]+Kof[j]*exp(P_i[j]*complex<long double>(delta_T*(long double)i+sdvig_T,0));
   X_tt[i]=X_tt[i]+W0;
    Y[i] = real(X_tt[i]);
    X[i] = (long double)i*T/(long double)N;
//   if (Max_Toch<real(X_tt[i])) Max_Toch=real(X_tt[i]);
//   if (Min_Toch>real(X_tt[i])) Min_Toch=real(X_tt[i]);
  }
 }
delete []X_tt;X_tt=NULL;
}
}
//---------------------------------------------------------------------------
void CTransLink::AFChX(long double * &X ,long double * &Y, int N, long double w_nach,long double w_kon)
{
if(X!=NULL) { delete [] X; X=NULL;}
if(Y!=NULL) { delete [] Y; Y=NULL;}
X = new long double [N];
Y = new long double [N];
long double delta_w=(w_kon-w_nach)/(long double)N;
for(int i=0;i<N;i++)
 {
      complex<long double> U=complex<long double>(0.0,0.0);
      complex<long double> V=complex<long double>(0.0,0.0);
      complex<long double> F=complex<long double>(0.0,0.0);
      for(int j=0;j<stepen+U_Stepen+1;j++)
      {
        U=U+U_kof[j]*pow(complex<long double>(0.0,w_nach+delta_w*i),j);
      }
      for(int j=0;j<stepen+1;j++)
      {
        V=V+V_kof[j]*pow(complex<long double>(0.0,w_nach+delta_w*i),j);
      }
      X[i]=real(U/V);
      Y[i]=imag(U/V);
  }
}
//---------------------------------------------------------------------------
void CTransLink::AChX(long double * &X ,long double * &Y, int N, long double w_nach,long double w_kon)
{
if(X!=NULL) { delete [] X; X=NULL;}
if(Y!=NULL) { delete [] Y; Y=NULL;}
X = new long double [N];
Y = new long double [N];
long double delta_w=(w_kon-w_nach)/(long double)N;
for(int i=0;i<N;i++)
 {
      complex<long double> U=complex<long double>(0.0,0.0);
      complex<long double> V=complex<long double>(0.0,0.0);
      complex<long double> F=complex<long double>(0.0,0.0);
      for(int j=0;j<stepen+U_Stepen+1;j++)
      {
        U=U+U_kof[j]*pow(complex<long double>(0.0,w_nach+delta_w*i),j);
      }
      for(int j=0;j<stepen+1;j++)
      {
        V=V+V_kof[j]*pow(complex<long double>(0.0,w_nach+delta_w*i),j);
      }
      Y[i]=sqrt(real(U/V)*real(U/V)+imag(U/V)*imag(U/V));
      X[i]=w_nach+delta_w*i;
  }
}
//---------------------------------------------------------------------------
void CTransLink::FChX(long double * &X ,long double * &Y, int N, long double w_nach,long double w_kon, bool Gradus)
{
if(X!=NULL) { delete [] X; X=NULL;}
if(Y!=NULL) { delete [] Y; Y=NULL;}
X = new long double [N];
Y = new long double [N];
int stepen_U=stepen+U_Stepen;
int stepen_V=stepen;
bool istina=true;
long double delta_w=(w_kon-w_nach)/(long double)N;
//complex<long double> t;
while(istina)
 {
  if(U_kof[stepen_U]==complex<long double>(0,0))
   --stepen_U;
  else istina=false;
  if(stepen_U==0) istina=false;
 }
istina=true;
while(istina)
 {
  if(V_kof[stepen_V]==complex<long double>(0,0))
   --stepen_V;
  else istina=false;
  if(stepen_V==0) istina=false;
 }
complex<long double> *Q_i=NULL;
if(stepen_U!=0)
{
 Q_i = new complex<long double>[stepen_U]; //нули ПФ
 fcomplex* U1 = new fcomplex [stepen_U+1];
   for(int i=0;i<stepen_U+1;i++)
    {
     U1[i].r=real(U_kof[i]);
     U1[i].i=imag(U_kof[i]);
    }
   fcomplex* b = new fcomplex [stepen_U+1];
   for(int i=0;i<stepen_U+1;i++)
    {b[i].r=0;b[i].i=0; }
   int k;
 zroots(U1,stepen_U,b,k); //определение корней полиномв
   for(int i=0;i<stepen_U;i++)
    {
    Q_i[i]=complex <long double>(b[i+1].r,b[i+1].i);
    }
    delete []b; b=NULL;
    delete []U1; U1=NULL;
}
complex<long double> *S_i=NULL;
if(stepen_V!=0)
{
 S_i = new complex<long double>[stepen_V]; //полюса ПФ
 fcomplex* V1 = new fcomplex [stepen_V+1];
   for(int i=0;i<stepen_V+1;i++)
    {
     V1[i].r=real(V_kof[i]);
     V1[i].i=imag(V_kof[i]);
    }
   fcomplex* b = new fcomplex [stepen_V+1];
   for(int i=0;i<stepen_V+1;i++)
    {b[i].r=0;b[i].i=0; }
   int k;
 zroots(V1,stepen_V,b,k); //определение корней полиномв
   for(int i=0;i<stepen_V;i++)
    {
    S_i[i]=complex <long double>(b[i+1].r,b[i+1].i);
    }
    delete []b; b=NULL;
    delete []V1; V1=NULL;
}
for(int i=0;i<N;i++)
 {
  long double Pi=3.1415926535897932385;
  Y[i]=0.;
   if((Q_i!=NULL)&&(stepen_U!=0))
   {
    for(int ii=0;ii<stepen_U;ii++)
     {
      int kluch=0;
      if((real(Q_i[ii])==0.0)&&(imag(Q_i[ii])==0.0)) kluch=0;
      else if((real(Q_i[ii])!=0.0)&&(imag(Q_i[ii])==0.0)) kluch=1;
      else kluch=2;
      switch(kluch)
       {
        case 0: Y[i]=Y[i]+Pi/2;
                break;
        case 1: Y[i]=Y[i]+atan((w_nach+delta_w*i)/(-real(Q_i[ii])));
                break;
        case 2:
                long double T2=1/sqrt(real(Q_i[ii])*real(Q_i[ii])+imag(Q_i[ii])*imag(Q_i[ii]));
                long double Ksi=-real(Q_i[ii])/sqrt(real(Q_i[ii])*real(Q_i[ii])+imag(Q_i[ii])*imag(Q_i[ii]));
                if((w_nach+delta_w*i)<=sqrt(real(Q_i[ii])*real(Q_i[ii])+imag(Q_i[ii])*imag(Q_i[ii])))
                Y[i]=Y[i]+atan((w_nach+delta_w*i)*2*T2*Ksi/(1-T2*T2*(w_nach+delta_w*i)*(w_nach+delta_w*i)));
                else Y[i]=Y[i]+Pi+atan((w_nach+delta_w*i)*2*T2*Ksi/(1-T2*T2*(w_nach+delta_w*i)*(w_nach+delta_w*i)));
                ii++;
                break;
       }
     }
   }
   if((S_i!=NULL)&&(stepen_V!=0))
   {
     for(int jj=0;jj<stepen_V;jj++)
     {
      int kluch=0;
      if((real(S_i[jj])==0.0)&&(imag(S_i[jj])==0.0)) kluch=0;
      else if((real(S_i[jj])!=0.0)&&(imag(S_i[jj])==0.0)) kluch=1;
      else kluch=2;
      switch(kluch)
       {
        case 0: Y[i]=Y[i]-Pi/2;
                break;
        case 1: Y[i]=Y[i]-atan((w_nach+delta_w*i)/(-real(S_i[jj])));
                break;
        case 2:
                long double T2=1/sqrt(real(S_i[jj])*real(S_i[jj])+imag(S_i[jj])*imag(S_i[jj]));
                long double Ksi=-real(S_i[jj])/sqrt(real(S_i[jj])*real(S_i[jj])+imag(S_i[jj])*imag(S_i[jj]));
                if((w_nach+delta_w*i)<=sqrt(real(S_i[jj])*real(S_i[jj])+imag(S_i[jj])*imag(S_i[jj])))
                Y[i]=Y[i]-atan((w_nach+delta_w*i)*2*T2*Ksi/(1-T2*T2*(w_nach+delta_w*i)*(w_nach+delta_w*i)));
                else Y[i]=Y[i]-Pi-atan((w_nach+delta_w*i)*2*T2*Ksi/(1-T2*T2*(w_nach+delta_w*i)*(w_nach+delta_w*i)));
                jj++;
                break;
       }
     }
   }
   if(Gradus) Y[i]=Y[i]*180./Pi;
   X[i]=w_nach+delta_w*i;
 }

delete []S_i; S_i=NULL;
delete []Q_i; Q_i=NULL;
}
//------------------------------------------------------------------------
void __fastcall CTransLink::GetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::GetDump(Dump, DumpSize);
   int ID_ALG = (int)Algoritm;
   AddValue(Dump, DumpSize, &ID_ALG, sizeof(int));
   AddValue(Dump, DumpSize, &ModelTypeIndex, sizeof(int));
   AddValue(Dump, DumpSize, &n, sizeof(DWORD));
   AddValue(Dump, DumpSize, &m, sizeof(DWORD));
   AddValue(Dump, DumpSize, N, sizeof(long double)*n);
   AddValue(Dump, DumpSize, T, sizeof(long double)*m);
   AddValue(Dump, DumpSize, &K, sizeof(long double));
   AddValue(Dump, DumpSize, &CharGroup, sizeof(int));
   AddValue(Dump, DumpSize, &CharTIndex, sizeof(int));
   AddValue(Dump, DumpSize, &CharFIndex, sizeof(int));
   AddValue(Dump, DumpSize, &T1, sizeof(long double));
   AddValue(Dump, DumpSize, &T2, sizeof(long double));
   AddValue(Dump, DumpSize, &DT, sizeof(long double));
   AddValue(Dump, DumpSize, &W1, sizeof(long double));
   AddValue(Dump, DumpSize, &W2, sizeof(long double));
   AddValue(Dump, DumpSize, &DW, sizeof(long double));
}
//------------------------------------------------------------------------
void __fastcall CTransLink::SetDump(void *&Dump, DWORD &DumpSize)
{
	CStdElement::SetDump(Dump, DumpSize);
   int ID_ALG = 0;
   GetValue(Dump, DumpSize, &ID_ALG, sizeof(int));
   Algoritm = (ID_ALGORITM)ID_ALG;
   GetValue(Dump, DumpSize, &ModelTypeIndex, sizeof(int));
   GetValue(Dump, DumpSize, &n, sizeof(DWORD));
   GetValue(Dump, DumpSize, &m, sizeof(DWORD));
   N = (long double*)realloc(N, sizeof(long double)*n);
   T = (long double*)realloc(T, sizeof(long double)*m);
   GetValue(Dump, DumpSize, N, sizeof(long double)*n);
   GetValue(Dump, DumpSize, T, sizeof(long double)*m);
   GetValue(Dump, DumpSize, &K, sizeof(long double));

   long double *NF = NULL;
   long double *TF = NULL;
   NF = (long double*)realloc(NF, sizeof(long double)*n);
   TF = (long double*)realloc(TF, sizeof(long double)*m);
   memcpy(NF, N, sizeof(long double)*n);
   memcpy(TF, T, sizeof(long double)*m);
   if(ModelTypeIndex == 1)
   {
   	long double *Tmp = NULL;
      Tmp = (long double*)realloc(Tmp, sizeof(long double)*2);
   	Tmp[0] = N[0];
      Tmp[1] = 1.0;
   	for(DWORD ci = 1; ci < n; ci++)
      {
   		MulPoly(Tmp, ci + 1, N[ci]);
   	}
      NF = (long double*)realloc(NF, sizeof(long double)*(n + 1));
      for(DWORD ci = 0; ci <= n; ci++)
      {
        	Tmp[ci] *= K;
        	NF[n - ci] = Tmp[ci];
      }
      Tmp = (long double*)realloc(Tmp, sizeof(long double)*2);
      Tmp[0] = T[0];
      Tmp[1] = 1.0;
   	for(DWORD ci = 1; ci < m; ci++)
   	{
   		MulPoly(Tmp, ci + 1, T[ci]);
   	}
      TF = (long double*)realloc(TF, sizeof(long double)*(m + 1));
      for(DWORD ci = 0; ci <= m; ci++)
      	TF[m - ci] = Tmp[ci];
      Tmp = (long double*)realloc(Tmp, 0);
   }
   delete []U_kof; U_kof=NULL;
  	delete []V_kof; V_kof=NULL;
   if(!ModelTypeIndex)
     	stepen = m > n ? m:n;
   else
     	stepen = m > n ? m + 1:n + 1;
   long double *B_i = new long double[stepen];
   ZeroMemory(B_i, sizeof(long double)*stepen);
   long double *A_i = new long double[stepen];
   ZeroMemory(A_i, sizeof(long double)*stepen);
   stepen--;
   if(!ModelTypeIndex)
   {
    	memcpy(B_i, TF, sizeof(long double)*m);
      memcpy(A_i, NF, sizeof(long double)*n);
   }
   else
   {
    	memcpy(B_i, TF, sizeof(long double)*(m + 1));
      memcpy(A_i, NF, sizeof(long double)*(n + 1));
   }
   U_Stepen = 0;
   astotizm = false;
   ERROR_V = false;
   Stepen_astotizma = 0;
   U_Stepen_bolshe = false;
   int ii = stepen;
   while((B_i[ii] == 0.0) && (ii >= 0))
   {
     	if(A_i[ii] != 0.0) U_Stepen_bolshe = true;
      if(U_Stepen_bolshe) U_Stepen++;
      stepen--;
      ii--;
   }
   U_kof = new complex<long double>[stepen + U_Stepen + 1];
   V_kof = new complex<long double>[stepen + 1];
   for(int i = 0; i < stepen + 1; i++)
   {
     	V_kof[i] = complex<long double>(B_i[i], 0.0);
   }
   for(int i = 0; i < stepen + U_Stepen + 1; i++)
   {
     	U_kof[i] = complex<long double>(A_i[i], 0.0);
   }
   if(stepen <= 0) ERROR_V = true;
   delete []B_i;
   delete []A_i;
   NF = (long double*)realloc(NF, 0);
   TF = (long double*)realloc(TF, 0);
   GetValue(Dump, DumpSize, &CharGroup, sizeof(int));
   GetValue(Dump, DumpSize, &CharTIndex, sizeof(int));
   GetValue(Dump, DumpSize, &CharFIndex, sizeof(int));
   GetValue(Dump, DumpSize, &T1, sizeof(long double));
   GetValue(Dump, DumpSize, &T2, sizeof(long double));
   GetValue(Dump, DumpSize, &DT, sizeof(long double));
   GetValue(Dump, DumpSize, &W1, sizeof(long double));
   GetValue(Dump, DumpSize, &W2, sizeof(long double));
   GetValue(Dump, DumpSize, &DW, sizeof(long double));
}
//---------------------------------------------------------------------------
