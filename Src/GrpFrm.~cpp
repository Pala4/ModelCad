//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GrpFrm.h"
#include "GrpApi\Grp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm_Grafic *Form_Grafic;
CGrps *Grp;
//---------------------------------------------------------------------------
__fastcall TForm_Grafic::TForm_Grafic(TComponent* Owner)
                        : TForm(Owner)
{
	Grp = new CGrps(this);
   Grp->Align = alClient;
   Grp->AxisName("t", "h(t)");
   Grp->Parent = this;
   EnAct = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Grafic::FormActivate(TObject *Sender)
{
   if(EnAct)
   {
   	CSer *Ser = new CSer;
   	Ser->Color = clBlue;
      int cj = 0;
   	for(long double ci = 0.0; ci < T+DT; ci =ci+DT)
   	{
   		Ser->AddPset(ci, real(Y[cj]), clRed);
         cj++;
   	}
   	Grp->AddSer(Ser);
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm_Grafic::FormDestroy(TObject *Sender)
{
	if(Grp)
   {
   	delete Grp;
      Grp = NULL;
   }
	Y = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Grafic::SetAxName(AnsiString X, AnsiString Y)
{
   Grp->AxisName(X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TForm_Grafic::AddGrp(long double *XX, long double *YY, int N)
{
   CSer *Ser = new CSer;
   Ser->Color = clBlue;
   for(int ci = 0; ci < N; ci++)
   {
   	Ser->AddPset(XX[ci], YY[ci], clRed);
   }
   Grp->AddSer(Ser);
}
//---------------------------------------------------------------------------
