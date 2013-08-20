//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>

#include "GrpWin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TFGrp::OnReleaseHitTest(void)
{
	StBrGrp->Panels->Items[0]->Text = "";
	StBrGrp->Panels->Items[1]->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::GPHTDataEvent(TGPHTData GPHTData)
{
	StBrGrp->Panels->Items[0]->Text = GPHTData.SerName;
	StBrGrp->Panels->Items[1]->Text = "X = ";
   StBrGrp->Panels->Items[1]->Text += FloatToStr(GPHTData.X);
	StBrGrp->Panels->Items[1]->Text += "; Y = ";
   StBrGrp->Panels->Items[1]->Text += FloatToStr(GPHTData.Y);
}
//---------------------------------------------------------------------------
__fastcall TFGrp::TFGrp(TComponent *Owner)
	              :TForm(Owner)
{
	OnGrpClose = NULL;
   Grps = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::SetAxNames(AnsiString XName, AnsiString YName)
{
	Grps->AxisName(XName, YName);
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::AddPset(long double X, long double Y)
{
	if(!Grps) return;
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::AddSer(long double *X, long double *Y, DWORD N, AnsiString SerName)
{
	if(!Grps) return;
   CSer *Ser = new CSer;
   DWORD Color = random(0xFFFFFF);
   Ser->Color = Color;
   for(DWORD ci = 0; ci < N; ci++) Ser->AddPset(X[ci], Y[ci], Color);
   if(!Grps->AddSer(Ser, SerName)) delete Ser;
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::FormCreate(TObject *Sender)
{
	Grps = new CGrps(ScrBxGrp);
   ScrBxGrp->ControlStyle << csOpaque;
   Grps->Align = alClient;
   Grps->OnReleaseHitTest = OnReleaseHitTest;
   Grps->GPHTDataEvent = GPHTDataEvent;
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MIParamClick(TObject *Sender)
{
	Grps->PropDlgExe();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MICloseClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MICheckClick(TObject *Sender)
{
	bool CheckSers = Grps->CheckSers();
   bool CheckCBText = Grps->CheckCBText();
   bool CheckSelSers = Grps->CheckSelSers();
   bool CheckCBBitmap = Grps->CheckCBBitmap();
	MIClearDiagram->Enabled = CheckSers;
   MICut->Enabled = CheckSelSers;
   MICopy->Enabled = CheckSelSers;
   MIPast->Enabled = CheckCBText;
   MIDel->Enabled = CheckSelSers;
	MISelectAll->Enabled = CheckSers;
   MICBClear->Enabled = (CheckCBBitmap || CheckCBText);
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MIClearDiagramClick(TObject *Sender)
{
   Grps->ClearGrp();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MICopyClick(TObject *Sender)
{
	Grps->CopySelected();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MIPastClick(TObject *Sender)
{
	Grps->PastSers();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MIDelClick(TObject *Sender)
{
	Grps->DelSelected();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MISelectAllClick(TObject *Sender)
{
   Grps->SelectAllSers();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MICBClearClick(TObject *Sender)
{
	Grps->ClearCB();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::MICopyDataClick(TObject *Sender)
{
	Grps->CopyToCB();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(OnGrpClose) OnGrpClose();
}
//---------------------------------------------------------------------------
void __fastcall TFGrp::FormDestroy(TObject *Sender)
{
	if(Grps) {delete Grps; Grps = NULL;}
}
//---------------------------------------------------------------------------
