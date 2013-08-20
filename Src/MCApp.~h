//---------------------------------------------------------------------------
#ifndef MCAppH
#define MCAppH

#include "MCBase.h"
#include "MCSys.h"
#include "MCFile.h"
#include "MCOptions.h"
#include "MCProj.h"
#include "CalcParamFrm.h"
#include "AboutFrm.h"
//---------------------------------------------------------------------------
#define DEFAULT_PROJ_NAME "нет_имени_"
#define DEFAULT_PROJ_EXT "mcp"
#define DEFAULT_PROJ_FOLDER "..\\Projects"
#define DEFAULT_FIELD_WIDTH 500
#define DEFAULT_FIELD_HEIGHT 300
//---------------------------------------------------------------------------
class CApp: public CObject
{
private:
   TCFGFile *CFGFile;
   TDSKFile *DSKFile;
   CSysInfo *SysInfo;
   CCFG *CFG;
   CDSK *DSK;
   COptions *Options;
   TFCalcParam *FCalcParam;
   TFAbout *FAbout;
   CProjCont *ProjCont;
   void __fastcall SetDefaultCFGSettings(void);
   void __fastcall SetDefaultDSKSettings(void);
   void __fastcall SetConfigSettings(void);
   void __fastcall SetDeskSettings(void);


	TPopupMenu *PMTL;
   void __fastcall PMTLClick(TObject *Sender);
   CElement *CurEl;

   BOOL ProjLoaded;
   BOOL ElMove;
   T_ID CURRENT_ID;
   int StartX;
   int StartY;
   int FElBtsDockWidth;
   AnsiString CurrentProjName;

   //TTabSheet *TSScheme;
   //TFElBts *FElBts;
   //TFObjInspect *FObjInspect;
   //CIOManager *IOManager;

   void __fastcall CreateWorkSpace(void);
   void __fastcall DoneWorkSpace(void);
   void __fastcall BtnClick(TObject* Sender);
   void __fastcall OnFieldMD(TObject *Sender, TMouseButton Button,
                             TShiftState Shift, int X, int Y);
   void __fastcall OnFieldMM(TObject *Sender, TShiftState Shift, int X, int Y);
   void __fastcall OnFieldMU(TObject *Sender, TMouseButton Button,
                             TShiftState Shift, int X, int Y);
   void __fastcall SC(Messages::TWMKey &Msg, bool &Handled);
public:
   TFProj *FProj;
   TPageControl *PCProj;

	CApp(void);
   virtual void __fastcall Init(CBase *Parent);
   TDSKFile* __fastcall GetDSK(void);
   void __fastcall SetObjectID(int ObjectID);
   void __fastcall SetResetButtonsHandler(TResetButtonsHandler OnResetButtons);



   void __fastcall NewProject(void);
	void __fastcall OpenLastProject(void);
   void __fastcall SaveCFGSettings(void);
   void __fastcall SaveDSKSettings(void);
   void __fastcall ShowOptions(void);
   void __fastcall ShowCalcParam(void);
   bool __fastcall ElBtsVisible(void);
   void __fastcall ShowElBts(void);
   void __fastcall HideElBts(void);
   void __fastcall OpenProject(void);
   void __fastcall SaveProject(void);
   void __fastcall SaveAllProjects(void);
   void __fastcall SaveAsProject(void);
   void __fastcall CloseProj(void);
   TCloseAction __fastcall CloseAllProjs(bool CloseApp);
   void __fastcall ShowAbout(void);
   virtual void __fastcall Done(void);


   void __fastcall SaveSettings(void);
   void __fastcall NewProj1(void);
   void __fastcall OpenGrp(void);
   void __fastcall CloseProj1(void);
   void __fastcall CalcActive(void);
   void __fastcall CalcActiveByStep(void);
};
#endif
