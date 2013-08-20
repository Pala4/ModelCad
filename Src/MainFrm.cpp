//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TFMain *FMain;
//---------------------------------------------------------------------------
void __fastcall TFMain::SetWinMetrix(void)
{
	Left = DSKFile->MWLeft;
   Top = DSKFile->MWTop;
   Width = DSKFile->MWWidth;
   if(DSKFile->MWMax)
   	WindowState = wsMaximized;
   else
   	WindowState = wsNormal;
}
//---------------------------------------------------------------------------
void __fastcall TFMain::OnAddElement(int ObjectID,
                                     AnsiString GroupName,
                                     AnsiString ExtName,
                                     HINSTANCE HI,
                                     AnsiString BtResName)
{
   ElBts->AddButton(GroupName, ExtName, BtResName,
                    HI, ObjectID);
   TMenuItem *MI = NULL, *MISub;
   for(int ci = 0; ci < GroupMIList->Count; ci++)
   {
   	if(((TMenuItem*)GroupMIList->Items[ci])->Caption == GroupName)
      {
         MI = (TMenuItem*)GroupMIList->Items[ci];
      	break;
      }
   }
   if(!MI || !GroupMIList->Count)
   {
   	MI = new TMenuItem(this);
      MI->Caption = GroupName;
   	MIElementes->Add(MI);
   }
   MISub = new TMenuItem(this);
   MISub->Caption = ExtName;
   MISub->Bitmap->LoadFromResourceName((THandle)HI, BtResName);
   MISub->Tag = ObjectID;
   MISub->OnClick = OnElMenuItemClick;
   MI->Add(MISub);
   GroupMIList->Add(MI);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::OnElButtonClick(int ObjectID)
{
	MCApp->SetObjectID(ObjectID);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::OnElMenuItemClick(TObject *Sender)
{
	OnElButtonClick(((TComponent*)Sender)->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::OnGetElPropHandler(TMessage Message)
{
	TBtProperty->Enabled = true;
   MIProperty->Enabled = true;
   SetData = ((CElement*)Message.WParam)->SetData;
	TBtGrp->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFMain::OnReliseElPropHandler(TMessage Message)
{
	TBtProperty->Enabled = false;
   MIProperty->Enabled = false;
   SetData = NULL;
	TBtGrp->Enabled = false;
}
//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner):TForm(Owner)
{
   GroupMIList = NULL;
	ElBts = NULL;
   SetData = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFMain::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TFMain::FormShow(TObject *Sender)
{
	MCApp = new CApp;
	MCApp->Init((CBase*)this);
   DSKFile = MCApp->GetDSK();
   ElBts = new CElBts(CBrMain);
   ElBts->Align = alNone;
   ElBts->Parent = CBrMain;
	ElBts->DragKind = dkDock;
   ElBts->DragMode = dmAutomatic;
   ElBts->Top = 0;
   ElBts->Left = TBrStd->Left + TBrStd->Width;
   ElBts->Width = DSKFile->ElBTSWidth;
   ElBts->Height = 48;
   ElBts->Constraints->MinHeight = ElBts->Height;
   ElBts->Constraints->MaxHeight = ElBts->Height;
   ElBts->Init();
   SetWinMetrix();
   GroupMIList = new TList;
   ElBts->AddRootButton("Переместить", "BTARROW", HInstance, ID_ARROW);

   OnAddElement(ID_K, "Стандартные", "Усилительное звено",
                HInstance, "BTK");
   OnAddElement(ID_1P, "Стандартные", "Интегрирующее звено",
                HInstance, "BT1P");
   OnAddElement(ID_Z, "Стандартные", "Дискретное передаточное звено",
                HInstance, "BTZ");
   OnAddElement(ID_TRANSLINK, "Стандартные", "Передаточное звено",
                HInstance, "BTTRANSLINK");
   OnAddElement(ID_SUMMATOR, "Стандартные", "Сумматор",
                HInstance, "BTSUMMATOR");
   OnAddElement(ID_UNIT, "Стандартные", "Узел",
                HInstance, "BTUNIT");
   OnAddElement(ID_LINK, "Стандартные", "Связь",
                HInstance, "BTLINK");
   OnAddElement(ID_IN, "Стандартные", "Вход",
                HInstance, "BTIN");
   OnAddElement(ID_OUT, "Стандартные", "Выход",
                HInstance, "BTOUT");
   OnAddElement(ID_FREE, "Нелинейные", "Произвольный",
                HInstance, "BTFREE");
   OnAddElement(ID_SINUS, "Нелинейные", "Синусоида",
                HInstance, "BTSINUS");
   OnAddElement(ID_NOSENSE, "Нелинейные", "Нечувствительность",
                HInstance, "BTNOSENSE");
   OnAddElement(ID_REST, "Нелинейные", "Ограничение",
                HInstance, "BTREST");
   OnAddElement(ID_NOSENSEREST, "Нелинейные", "Нечувствительность и ограничение",
                HInstance, "BTNOSENSEREST");
   OnAddElement(ID_LUFT, "Нелинейные", "Люфт",
                HInstance, "BTLUFT");
   OnAddElement(ID_UBRELAY, "Нелинейные", "Однозначное реле",
                HInstance, "BTUBRELAY");
   OnAddElement(ID_NUBRELAY, "Нелинейные", "Неоднозначное реле",
                HInstance, "BTNUBRELAY");
   OnAddElement(ID_GAUSSNOISE, "Шумы", "Гаусовский шум",
                HInstance, "BTGAUSSNOISE");
   OnAddElement(ID_P, "Регуляторы", "П-регулятор",
                HInstance, "BTP");
   OnAddElement(ID_PD, "Регуляторы", "ПД-регулятор",
                HInstance, "BTPD");
   OnAddElement(ID_I, "Регуляторы", "И-регулятор",
                HInstance, "BTI");
   OnAddElement(ID_PI, "Регуляторы", "ПИ-регулятор",
                HInstance, "BTPI");
   OnAddElement(ID_PID, "Регуляторы", "ПИД-регулятор",
                HInstance, "BTPID");
   ElBts->OnElButtonClick = OnElButtonClick;
   MCApp->SetResetButtonsHandler(ElBts->ResetButtons);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::NewClick(TObject *Sender)
{
	MCApp->NewProject();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::OpenClick(TObject *Sender)
{
	MCApp->OpenProject();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::SaveClick(TObject *Sender)
{
	MCApp->SaveProject();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::SaveAllClick(TObject *Sender)
{
   MCApp->SaveAllProjects();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MISaveAsClick(TObject *Sender)
{
	MCApp->SaveAsProject();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MICloseProjClick(TObject *Sender)
{
   MCApp->CloseProj();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MICloseAllProjsClick(TObject *Sender)
{
   MCApp->CloseAllProjs(false);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::ExitClick(TObject *Sender)
{
	if(MCApp->CloseAllProjs(true) == caNone) return;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MIViewClick(TObject *Sender)
{
	if(!MCApp->ElBtsVisible()) MIElBts->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MIElBtsClick(TObject *Sender)
{
	MIElBts->Checked = (!MIElBts->Checked);
   if(MIElBts->Checked)
   	MCApp->ShowElBts();
   else
   	MCApp->HideElBts();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::OptionsClick(TObject *Sender)
{
   MCApp->ShowOptions();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MISaveSettingsClick(TObject *Sender)
{
   MCApp->SaveCFGSettings();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MISaveDesktopClick(TObject *Sender)
{
   MCApp->SaveDSKSettings();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::CalcParamClick(TObject *Sender)
{
	MCApp->ShowCalcParam();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::PropertyClick(TObject *Sender)
{
	if(SetData) SetData();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MIAboutClick(TObject *Sender)
{
	MCApp->ShowAbout();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::FormClose(TObject *Sender, TCloseAction &Action)
{
   if(MCApp)
   {
		Action = MCApp->CloseAllProjs(true);
      if(Action == caNone) return;
      if(GroupMIList)
      {
      	GroupMIList->Clear();
         delete GroupMIList;
      }
		MCApp->Done();
      delete MCApp;
      MCApp = NULL;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFMain::CalcClick(TObject *Sender)
{
   MCApp->CalcActive();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::ToolButton1Click(TObject *Sender)
{
	MCApp->OpenGrp();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::MIStepClick(TObject *Sender)
{
	MCApp->CalcActiveByStep();
}
//---------------------------------------------------------------------------
