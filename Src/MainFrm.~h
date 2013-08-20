//---------------------------------------------------------------------------
#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>

#include "MCApp.h"
#include "MCElBts.h"
//---------------------------------------------------------------------------
class TFMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MMain;
	TMenuItem *MIFile;
	TMenuItem *MIExit;
	TMenuItem *MISettings;
	TMenuItem *MIOptions;
	TMenuItem *MISeparatOptionsSection;
	TMenuItem *MISaveSettings;
	TMenuItem *MINew;
	TMenuItem *MISeparatNewSection;
	TMenuItem *MIOpen;
	TMenuItem *MISeparatOpenSection;
	TMenuItem *MISave;
	TMenuItem *MISaveAs;
	TMenuItem *MISeparatSaveSection;
	TMenuItem *MICloseProj;
   TImageList *ImLMain;
	TMenuItem *MIElBts;
	TControlBar *CBrMain;
	TToolBar *TBrStd;
	TToolButton *TBtNew;
	TToolButton *TBtOpen;
	TToolButton *TBtSave;
	TToolButton *TBtSaveAll;
	TToolBar *TBrOptions;
	TToolButton *TBtOptions;
	TToolBar *TBrCalc;
	TToolButton *TBtCalc;
	TToolButton *TBtGrp;
	TToolBar *TBrExit;
	TToolButton *TBtExit;
	TToolButton *TBtProperty;
	TToolButton *TBtCalcParam;
   TMenuItem *MIRun;
   TMenuItem *MIStep;
   TMenuItem *MIStart;
   TMenuItem *MIElementes;
	TMenuItem *MIProperty;
	TMenuItem *N1;
	TMenuItem *MICalcParam;
	TMenuItem *N2;
	TMenuItem *MIHelp;
	TMenuItem *MIAbout;
	void __fastcall ExitClick(TObject *Sender);
	void __fastcall OptionsClick(TObject *Sender);
	void __fastcall MISaveSettingsClick(TObject *Sender);
	void __fastcall MICloseProjClick(TObject *Sender);
	void __fastcall NewClick(TObject *Sender);
	void __fastcall MISaveAsClick(TObject *Sender);
	void __fastcall SaveClick(TObject *Sender);
	void __fastcall OpenClick(TObject *Sender);
	void __fastcall CalcClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SaveAllClick(TObject *Sender);
	void __fastcall MICloseAllProjsClick(TObject *Sender);
	void __fastcall MISaveDesktopClick(TObject *Sender);
	void __fastcall MIElBtsClick(TObject *Sender);
	void __fastcall MIViewClick(TObject *Sender);
   void __fastcall MIStepClick(TObject *Sender);
	void __fastcall PropertyClick(TObject *Sender);
	void __fastcall CalcParamClick(TObject *Sender);
	void __fastcall MIAboutClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
   TDSKFile *DSKFile;
   TList *GroupMIList;
   CElBts *ElBts;
	CApp *MCApp;
   TSetData SetData;
 	void __fastcall SetWinMetrix(void);
   void __fastcall OnAddElement(int ObjectID,
                                AnsiString GroupName,
                                AnsiString ExtName,
                                HINSTANCE HI,
                                AnsiString BtResName);
   void __fastcall OnElButtonClick(int ObjectID);
   void __fastcall OnElMenuItemClick(TObject *Sender);
   void __fastcall OnGetElPropHandler(TMessage Message);
   void __fastcall OnReliseElPropHandler(TMessage Message);
   BEGIN_MESSAGE_MAP
   	VCL_MESSAGE_HANDLER(WM_SETDATA, TMessage, OnGetElPropHandler);
   	VCL_MESSAGE_HANDLER(WM_RESETDATA, TMessage, OnReliseElPropHandler);
   END_MESSAGE_MAP(TForm)
public:		// User declarations
	__fastcall TFMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMain *FMain;
//---------------------------------------------------------------------------
#endif
