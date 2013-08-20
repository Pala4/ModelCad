//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <dir.h>

#include "MCApp.h"
//---------------------------------------------------------------------------
#define CFG_FILE_NAME "MCad.mcc"
#define DSK_FILE_NAME "MCad.mcd"
#define DEFAULT_FIELD_COLOR COLOR_BTNFACE
#define DEFAULT_GRID_COLOR 0x00000000
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CApp::CApp(void):CObject()
{
   CFGFile = NULL;
   DSKFile = NULL;
   SysInfo = NULL;
   CFG = NULL;
   DSK = NULL;
   Options = NULL;
   FCalcParam = NULL;
   FAbout = NULL;
   ProjCont = NULL;

   ElMove = FALSE;
   CURRENT_ID = ID_ARROW;
   ProjLoaded = FALSE;
	CurrentProjName = "";
}

void __fastcall CApp::BtnClick(TObject *Sender)
{
	//CURRENT_ID = ((TElButton*)Sender)->ID_ELEM;
}

void __fastcall CApp::OnFieldMD(TObject *Sender,
                                    TMouseButton Button,
                                    TShiftState Shift, int X, int Y)
{
/*
   if((DWORD)X <= IOManager->DDView->Width &&
      (DWORD)Y <= IOManager->DDView->Height)
   {
      CElement *El;
   	switch(CURRENT_ID)
      {
      	case ID_ARROW:
            if(Button == mbLeft)
            {
               El = IOManager->ElemClick(X, Y);
               if(!El)
               {
            		IOManager->Selector->UnSelect();
      				IOManager->Selector->StartFrame(X, Y);
               }
               else
               {
                  ElMove = TRUE;
    					El->ScrPosX = El->Left + IOManager->ScrPosX;
      				El->ScrPosY = El->Top + IOManager->ScrPosY;
    					if(Shift.Contains(ssShift) || IOManager->Selector->Consist(El))
      				{
         				if(!IOManager->Selector->Consist(El))
                     	IOManager->Selector->Select(El);
      				}
      				else
      				{
      					IOManager->Selector->UnSelect();
      					IOManager->Selector->Select(El);
     	 				}
                  if(IOManager->Selector->Consist(El))
                  	for(int ci = 0; ci < IOManager->Selector->SelBuf->Count; ci++)
                  	{
                  		((CElement*)IOManager->Selector->SelBuf->Items[ci])->DragLeft =
                     		X - ((CElement*)IOManager->Selector->SelBuf->Items[ci])->Left;
                  		((CElement*)IOManager->Selector->SelBuf->Items[ci])->DragTop =
                     		Y - ((CElement*)IOManager->Selector->SelBuf->Items[ci])->Top;
                  	}
                  if(IOManager->Selector->SelBuf->Count)
                  	FObjInspect->SetProperty((CElement*)IOManager->Selector->SelBuf->Items[0]);
               }
            }
            else
            {
               TPoint P;
            	El = IOManager->ElemClick(X, Y);
               if(El)
               	if(El->ID_ELEM == ID_TRANSLINK)
                  {
               		P = TSScheme->ClientToScreen(Point(X, Y));
                     PMTL->Popup(P.x, P.y);
                     CurEl = El;
                  }
            }
         break;
         case ID_LINK:
         	El = IOManager->ElemClick(X, Y);
            if(El) IOManager->Linking(El, IOManager->Selector->CURRENT_OR);
         break;
         case ID_NONE:
         break;
         default:
         	IOManager->AddElem(CURRENT_ID, X, Y);
   			IOManager->Selector->UnSelect();
   			IOManager->Selector->Select(IOManager->Els->CurrentAdd);
         	IOManager->Render();
   			FElBts->ResetButtons();
         	CURRENT_ID = ID_ARROW;
      }
   }
*/
}

void __fastcall CApp::OnFieldMM(TObject *Sender, TShiftState Shift,
                                    int X, int Y)
{
/*
   if(IOManager->Selector->SelFrame)
   {
      IOManager->Selector->UpDateFrame(X, Y);
   	IOManager->Render();
   }
   else
   {
   	CElement *El;
   	if(ElMove)
   	{
     		for(int ci = 0; ci < IOManager->Selector->SelBuf->Count; ci++)
      	{
      		El = (CElement*)IOManager->Selector->SelBuf->Items[ci];
   			El->Left = X - El->DragLeft;
         	El->Top = Y - El->DragTop;
         	El->ScrPosX = El->Left + IOManager->ScrPosX;
         	El->ScrPosY = El->Top + IOManager->ScrPosY;
      	}
      	IOManager->Render();
   	}
      if(CURRENT_ID == ID_LINK)
      {
         El = IOManager->ElemClick(X, Y);
         if(El)
         {
         	IOManager->Selector->CalcLinkOrient(El, X, Y);
            if(El->OrientBusy(IOManager->Selector->CURRENT_OR))
               IOManager->Selector->CURRENT_OR = OR_BUSY;
         }
         else
         {
         	IOManager->Selector->DoneLinkOrient();
         }
      }
   }
*/
}

void __fastcall CApp::OnFieldMU(TObject *Sender, TMouseButton Button,
                                    TShiftState Shift, int X, int Y)
{
/*
 	if(IOManager->Selector->SelFrame && Button == mbLeft)
   {
		IOManager->Selector->EndFrame();
      IOManager->Selector->SelGroup(IOManager->Els);
   	IOManager->Render();
   }
   if(ElMove)
   {
   	CElement *El;
   	ElMove = FALSE;
     	for(int ci = 0; ci < IOManager->Selector->SelBuf->Count; ci++)
      {
      	El = (CElement*)IOManager->Selector->SelBuf->Items[ci];
         El->ScrPosX = El->Left + IOManager->ScrPosX;
         El->ScrPosY = El->Top + IOManager->ScrPosY;
      }
   }
*/
}

void __fastcall CApp::SC(Messages::TWMKey &Msg, bool &Handled)
{
/*
	switch(Msg.CharCode)
   {
   	case VK_DELETE:
      	if(IOManager) IOManager->DelSelected();
      break;
   }
*/
}

void __fastcall CApp::OpenGrp(void)
{
   ProjCont->OpenGraph();
	//IOManager->OpenGraph();
}



//---------------------------------------------------------------------------
void __fastcall CApp::SetDefaultCFGSettings(void)
{
   if(!CFGFile) return;
   CFGFile->StartAction = 0;
   CFGFile->AutoSaveDSK = false;
   CFGFile->AutoSaveCFG = false;
   CFGFile->AutoSavePRJ = false;
   CFGFile->GridVisible = true;
   CFGFile->AlignToGrid = true;
   CFGFile->UseSmartLinks = true;
   CFGFile->FieldColor = DEFAULT_FIELD_COLOR;
   CFGFile->GridColor = DEFAULT_GRID_COLOR;
}
//---------------------------------------------------------------------------
void __fastcall CApp::SetDefaultDSKSettings(void)
{
   DSKFile->MWLeft = 0;
   DSKFile->MWTop = 0;
   DSKFile->MWWidth = SysInfo->ScrWidth;
   DSKFile->MWMax = true;
   DSKFile->ElBTSVisible = true;
   DSKFile->ElBTSLeft = 0;
   DSKFile->ElBTSTop = 200;
   DSKFile->ElBTSWidth = SysInfo->ScrWidth/2;
   DSKFile->OptionsPageNomber = 0;
}
//---------------------------------------------------------------------------
void __fastcall CApp::SetConfigSettings(void)
{
}
//---------------------------------------------------------------------------
void __fastcall CApp::SetDeskSettings(void)
{
}
//---------------------------------------------------------------------------
void __fastcall CApp::Init(CBase *Parent)
{
	CObject::Init(Parent);
   Application->HintHidePause = 20000;
   SysInfo = new CSysInfo;
   SysInfo->Init(this);
   CFG = new CCFG;
   CFG->Init(this);
   CFG->DefaultFolder = ExtractFilePath(Application->ExeName);
   CFGFile = &CFG->CFGFile;
   DSK = new CDSK;
   DSK->Init(this);
   DSK->DefaultFolder = ExtractFilePath(Application->ExeName);
   DSKFile = &DSK->DSKFile;
   Options = new COptions;
   Options->Init(this);
   if(CFG->Read(CFG_FILE_NAME))
      SetConfigSettings();
   else
   	SetDefaultCFGSettings();
   if(DSK->Read(DSK_FILE_NAME))
      SetDeskSettings();
   else
   	SetDefaultDSKSettings();
   ProjCont = new CProjCont(CFGFile, DSKFile);

   ProjCont->DefaultWndLeft = 0;
   ProjCont->DefaultWndTop = ((TForm*)Parent)->Height;
   ProjCont->DefaultWndWidth = SysInfo->ScrWidth*0.8;
   ProjCont->DefaultWndHeight = SysInfo->MaxWinHeight*0.9 - ((TForm*)Parent)->Height;

   ProjCont->DefaultProjName = DEFAULT_PROJ_NAME;
   ProjCont->DefaultProjExt = DEFAULT_PROJ_EXT;
   ProjCont->DefaultProjFolder = DEFAULT_PROJ_FOLDER;
   ProjCont->DefaultFieldWidth = DEFAULT_FIELD_WIDTH;
   ProjCont->DefaultFieldHeight = DEFAULT_FIELD_HEIGHT;
   ProjCont->Init(this);
   switch(CFGFile->StartAction)
   {
   	case 0:
   		NewProject();
      break;
      case 1:
			OpenLastProject();
		break;
   }
}
//---------------------------------------------------------------------------
TDSKFile* __fastcall CApp::GetDSK(void)
{
	return DSKFile;
}
//---------------------------------------------------------------------------
void __fastcall CApp::SetObjectID(int ObjectID)
{
	ProjCont->CURRENT_ID = (T_ID)ObjectID;
}
//---------------------------------------------------------------------------
void __fastcall CApp::SetResetButtonsHandler(TResetButtonsHandler OnResetButtons)
{
   ProjCont->OnResetButtons = OnResetButtons;
}
//---------------------------------------------------------------------------
void __fastcall CApp::NewProject(void)
{
   if(!ProjCont) return;
   ProjCont->NewProject();
}
//---------------------------------------------------------------------------
void __fastcall CApp::OpenLastProject(void)
{
   if(!ProjCont) return;
   ProjCont->OpenLastProjects();
}
//---------------------------------------------------------------------------
void __fastcall CApp::ShowOptions(void)
{
   TPRJFile *PRJFile = ProjCont->GetActivePRJData();
	Options->ShowDlg(CFGFile, DSKFile, PRJFile);
   ProjCont->SetConfig(CFGFile->AlignToGrid, CFGFile->UseSmartLinks,
                       CFGFile->FieldColor, CFGFile->GridColor,
                       PRJFile->FieldWidth, PRJFile->FieldHeight,
                       CFGFile->GridStep);
}
//---------------------------------------------------------------------------
void __fastcall CApp::ShowCalcParam(void)
{
	FCalcParam = new TFCalcParam(Application);
   TPRJFile *PRJFile = ProjCont->GetActivePRJData();
   FCalcParam->RGCalcAlg->ItemIndex = PRJFile->CalcOrder;
   FCalcParam->EDT->Text = FloatToStr(PRJFile->DT);
   FCalcParam->ET->Text = FloatToStr(PRJFile->T);
   FCalcParam->EDW->Text = FloatToStr(PRJFile->DW);
   FCalcParam->EW->Text = FloatToStr(PRJFile->W);
   FCalcParam->ShowModal();
   if(FCalcParam->ResultOk)
   {
   	PRJFile->CalcOrder = FCalcParam->RGCalcAlg->ItemIndex;
   	PRJFile->DT = FCalcParam->DT;
   	PRJFile->T = FCalcParam->T;
   	PRJFile->DW = FCalcParam->DW;
   	PRJFile->W = FCalcParam->W;
   }
   FCalcParam->Free();
}
//---------------------------------------------------------------------------
bool __fastcall CApp::ElBtsVisible(void)
{
	return ProjCont->ElBtsVisible();
}
//---------------------------------------------------------------------------
void __fastcall CApp::ShowElBts(void)
{
	ProjCont->ShowElBts();
}
//---------------------------------------------------------------------------
void __fastcall CApp::HideElBts(void)
{
	ProjCont->HideElBts();
}
//---------------------------------------------------------------------------
void __fastcall CApp::SaveCFGSettings(void)
{
   if(!CFG->Write(CFG_FILE_NAME))
   	Application->MessageBox(CFG->IODsc, "IOError",
                              MB_OK | MB_ICONERROR);
}
//---------------------------------------------------------------------------
void __fastcall CApp::SaveDSKSettings(void)
{
   ProjCont->SetDSK();
   if(!DSK->Write(DSK_FILE_NAME))
   	Application->MessageBox(DSK->IODsc, "IOError",
                              MB_OK | MB_ICONERROR);
}
//---------------------------------------------------------------------------
void __fastcall CApp::OpenProject(void)
{
	ProjCont->OpenProject();
}
//---------------------------------------------------------------------------
void __fastcall CApp::SaveProject(void)
{
	ProjCont->SaveActiveProj();
}
//---------------------------------------------------------------------------
void __fastcall CApp::SaveAllProjects(void)
{
	ProjCont->SaveAllProjs();
}
//---------------------------------------------------------------------------
void __fastcall CApp::SaveAsProject(void)
{
   ProjCont->SaveAsActiveProj();
}
//---------------------------------------------------------------------------
void __fastcall CApp::CloseProj(void)
{
	ProjCont->CloseActiveProj();
}
//---------------------------------------------------------------------------
TCloseAction __fastcall CApp::CloseAllProjs(bool CloseApp)
{
	return ProjCont->CloseAllProjs(CloseApp);
}
//---------------------------------------------------------------------------
void __fastcall CApp::ShowAbout(void)
{
	FAbout = new TFAbout(Application);
   FAbout->ShowModal();
   FAbout->Free();
}
//---------------------------------------------------------------------------
void __fastcall CApp::Done(void)
{
   if(CFGFile->AutoSaveCFG) SaveCFGSettings();
   if(CFGFile->AutoSaveDSK) SaveDSKSettings();
   CFGFile = NULL;
   DSKFile = NULL;
   if(SysInfo)
   {
   	SysInfo->Done();
      delete SysInfo;
      SysInfo = NULL;
   }
   if(CFG)
   {
      CFG->Done();
      delete CFG;
   	CFG = NULL;
   }
   if(DSK)
   {
      DSK->Done();
      delete DSK;
   	DSK = NULL;
   }
   if(Options)
   {
   	Options->Done();
      delete Options;
      Options = NULL;
   }
   if(ProjCont)
   {
   	ProjCont->Done();
      delete ProjCont;
      ProjCont = NULL;
   }
   CObject::Done();
}
//---------------------------------------------------------------------------



void __fastcall CApp::SaveSettings(void)
{
/*
   AnsiString FullPath = ExtractFilePath(Application->ExeName);
   FullPath = FullPath + CurrentProjName;
*/
}

void __fastcall CApp::PMTLClick(TObject *Sender)
{
//	((CLinearTransLink*)CurEl)->SetData();
}

void __fastcall CApp::CreateWorkSpace(void)
{
/*
   FProj = new TFProj(Application);
   PCProj = new TPageControl(FProj);
   PCProj->Align = alClient;
   PCProj->Parent = FProj;
   TSScheme = new TTabSheet(PCProj);
   IOManager = new CIOManager;
   FElBts = new TFElBts(Application);
   FObjInspect = new TFObjInspect(Application);


   FProj->Caption = CurrentProjName;
   TSScheme->Caption = "Структурная схема";
   TSScheme->PageControl = PCProj;

   PMTL = new TPopupMenu(TSScheme);
   TMenuItem *MI = new TMenuItem(TSScheme);
   MI->Caption = "Свойства";
   MI->OnClick = PMTLClick;
   PMTL->Items->Add(MI);
   PMTL->AutoPopup = FALSE;
   TSScheme->PopupMenu = PMTL;



   TSScheme->OnMouseDown = OnFieldMD;
   TSScheme->OnMouseMove = OnFieldMM;
   TSScheme->OnMouseUp = OnFieldMU;
   FProj->Show();
   IOManager->SetParent(TSScheme);
   IOManager->Init(FMain);


   FElBts->Height = 0;
   FElBts->InsertButton(ID_ARROW, "BTARROW", "Переместить", BtnClick);
   FElBts->InsertButton(ID_LINEARTRANSLINK, "BTTRANSLINK", "Передаточное звено", BtnClick);

   FElBts->InsertButton(ID_NONLINEAR, "BTNONLINEAR", "Нелинейный элемент", BtnClick);
   FElBts->InsertButton(ID_SUMMATOR, "BTSUMMATOR", "Сумматор", BtnClick);
   FElBts->InsertButton(ID_UNIT, "BTUNIT", "Узел", BtnClick);
   FElBts->InsertButton(ID_LINK, "BTLINK", "Связь", BtnClick);
   FElBts->InsertButton(ID_IN, "BTIN", "Вход", BtnClick);
   FElBts->InsertButton(ID_OUT, "BTOUT", "Выход", BtnClick);
   FElBtsDockWidth = FElBts->Width;
   FElBts->Show();

   FObjInspect->Show();
*/
}

void __fastcall CApp::DoneWorkSpace(void)
{
/*
   if(IOManager)
   {
   	IOManager->Done();
      delete IOManager;
      IOManager = NULL;
   }
	FObjInspect->Free();
   FElBts->Free();
   FProj->Free();
*/
}

void __fastcall CApp::NewProj1(void)
{
/*
   if(ProjLoaded) CloseProj();
	CurrentProjName = "нет_имени.prj";

   CreateWorkSpace();
   ProjLoaded = TRUE;
*/
}

void __fastcall CApp::CloseProj1(void)
{
/*
   if(ProjLoaded)
   {
		DoneWorkSpace();
		ProjLoaded = FALSE;
   }
*/
}

void __fastcall CApp::CalcActive(void)
{
	ProjCont->CalcActive();
}

void __fastcall CApp::CalcActiveByStep(void)
{
	ProjCont->CalcActiveByStep();
}
