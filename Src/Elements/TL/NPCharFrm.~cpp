//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "NPCharFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFNPChar::TFNPChar(TComponent* Owner)
	                 :TForm(Owner)
{
	Grp = new CGrps(this);
   Grp->Align = alClient;
   Grp->AxisName("Re", "Im");
   Grp->Parent = this;
}
//---------------------------------------------------------------------------
void __fastcall TFNPChar::AddRoot(long double Re, long double Im, AnsiString Res)
{
   CSer *Ser = new CSer;
   Ser->AddPset(Re, Im, clRed, "", Res);
   Grp->AddSer(Ser);
}
//---------------------------------------------------------------------------
void __fastcall TFNPChar::FormDestroy(TObject *Sender)
{
	if(Grp) {delete Grp; Grp = NULL;}
}
//---------------------------------------------------------------------------
