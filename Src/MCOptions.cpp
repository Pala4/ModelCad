//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCOptions.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


//---------------------------------------------------------------------------
COptions::COptions(void):CObject()
{
	FOptions = NULL;
}
//---------------------------------------------------------------------------
void __fastcall COptions::Init(CBase *Parent)
{
	CObject::Init(Parent);
}
//---------------------------------------------------------------------------
void __fastcall COptions::ShowDlg(TCFGFile *CFGFile,
                                  TDSKFile *DSKFile,
                                  TPRJFile *PRJFile)
{
	FOptions = new TFOptions(Application);
   FOptions->RGDoStart->ItemIndex = CFGFile->StartAction;
   FOptions->CBxASProgSet->Checked = CFGFile->AutoSaveCFG;
   FOptions->CBxASDesk->Checked = CFGFile->AutoSaveDSK;
   FOptions->CBxASProj->Checked = CFGFile->AutoSavePRJ;
   FOptions->EFieldColor->Text =
   	FOptions->EFieldColor->Text.sprintf("%X", CFGFile->FieldColor);
   FOptions->EGridColor->Text =
   	FOptions->EGridColor->Text.sprintf("%X", CFGFile->GridColor);
   FOptions->CBxGridVisible->Checked = CFGFile->GridVisible;
   FOptions->CBxAlignToGrid->Checked = CFGFile->AlignToGrid;
   FOptions->CBxUseSmartLink->Checked = CFGFile->UseSmartLinks;
   FOptions->PCOptions->ActivePageIndex = DSKFile->OptionsPageNomber;
   FOptions->SEFieldWidth->Value = PRJFile->FieldWidth;
   FOptions->SEFieldHeight->Value = PRJFile->FieldHeight;
   if(FOptions->ShowModal() == mrOk)
   {
   	CFGFile->UseSmartLinks = FOptions->CBxUseSmartLink->Checked;
   	CFGFile->AlignToGrid = FOptions->CBxAlignToGrid->Checked;
   	CFGFile->GridVisible = FOptions->CBxGridVisible->Checked;
      CFGFile->GridColor =
      	FOptions->StrHexToInt(FOptions->EGridColor->Text, 1);
      CFGFile->FieldColor =
      	FOptions->StrHexToInt(FOptions->EFieldColor->Text, 1);
   	CFGFile->AutoSavePRJ = FOptions->CBxASProj->Checked;
   	CFGFile->AutoSaveDSK = FOptions->CBxASDesk->Checked;
   	CFGFile->AutoSaveCFG = FOptions->CBxASProgSet->Checked;
   	CFGFile->StartAction = FOptions->RGDoStart->ItemIndex;
   	CFGFile->GridStep = FOptions->RGDoStart->ItemIndex;
      DSKFile->OptionsPageNomber = FOptions->PCOptions->ActivePageIndex;
   	PRJFile->FieldWidth = FOptions->SEFieldWidth->Value;
   	PRJFile->FieldHeight = FOptions->SEFieldHeight->Value;
   }
   FOptions->Free();
}
//---------------------------------------------------------------------------
void __fastcall COptions::Done(void)
{
	CObject::Done();
}
//---------------------------------------------------------------------------
