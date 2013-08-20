//---------------------------------------------------------------------------
#ifndef MCProjH
#define MCProjH
//---------------------------------------------------------------------------
#include <dir.h>

#include "MCBase.h"
#include "ProjFrm.h"
#include "MCFile.h"
#include "Field\MCField.h"
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TActivateHandler)(CBase *Sender);
typedef void __fastcall (__closure *TCloseHandler)(CBase *Sender);
typedef void __fastcall (__closure *TResetButtonsHandler)(void);
//---------------------------------------------------------------------------
class TEventTab : public TTabSheet
{
private:
public:
   TNotifyEvent OnPaint;
	__property OnKeyDown;
	__fastcall TEventTab(TComponent *AOwner);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
};
//---------------------------------------------------------------------------
class CProj : public CObject
{
private:
   bool ValHintShow;
	bool Modifyed;
   CPRJ *PRJ;
   TEventTab *TSScheme;
	void __fastcall AddValue(void *&Data, DWORD &DataSize,
                            void *Value, int ValSize);
   void __fastcall GetPRJDump(void *&Dump, DWORD &DumpSize);
   void __fastcall SetPRJDump(void *Dump, DWORD DumpSize);

   //---------------
   bool ElMove;
   TStatusBar *StBrProj;
   TPageControl *PCProj;
   CField *Field;
   CElement *CurEl;
   void __fastcall OnPaint(TObject *Sender);
   void __fastcall OnFieldMD(TObject *Sender,
                                    TMouseButton Button,
                                    TShiftState Shift, int X, int Y);
	void __fastcall OnFieldMM(TObject *Sender, TShiftState Shift,
                                    int X, int Y);
	void __fastcall OnFieldMU(TObject *Sender, TMouseButton Button,
                                    TShiftState Shift, int X, int Y);
   void __fastcall OnFieldKD(TObject *Sender, Word &Key,
                             Classes::TShiftState Shift);
   void __fastcall OnEnter(TObject *Sender);
   //--------------

   void __fastcall OnActivateWnd(TObject *Sender);
public:
	CProj(void);
   void __fastcall SetFieldView(bool AlignToGrid, bool SmartLink,
                                DWORD FieldColor, DWORD GridColor,
                                int GridStep);
   void __fastcall SetFieldMetrix(int FieldWidth, int FieldHeight);
	THintWindow *HW;
	bool OneEnabled;
	bool IsNew;
   bool Active;
   int Left;
   int Top;
   int Width;
   int Height;
   int FieldWidth;
   int FieldHeight;
   TActivateHandler OnActivate;
   TCloseEvent OnClose;
   TCFGFile *CFGFile;
   TDSKFile *DSKFile;
   AnsiString DefaultProjName;
   AnsiString ProjExt;
   AnsiString ProjFolder;
	AnsiString ProjName;
	TFProj *FProj;
   virtual void __fastcall Init(CBase *Parent);
   void __fastcall New(void);
   void __fastcall CreateWorkSpace(void);
   bool __fastcall Open(void);
   bool __fastcall Open(AnsiString FileName);
   bool __fastcall SaveAs(void);
   bool __fastcall Save(void);
	TCloseAction __fastcall OnProjClose(bool CloseApp);

   TCloseAction __fastcall CloseProject(bool CloseWnd,
                                        bool CloseApp);

   TPRJFile* __fastcall GetPRJFile(void)
   {
   	if(PRJ)
      	return &PRJ->PRJFile;
      else
      	return NULL;
   }
   virtual void __fastcall Done(void);
   void __fastcall Calc(void);
   void __fastcall CalcByStep(void);
	void __fastcall OpenGraph(void);
   void __fastcall ShowVal(CElement *El, int MX, int MY);
   void __fastcall ReliseValHint(void);
};
//---------------------------------------------------------------------------
class CProjCont : public CObject
{
private:
   bool CloseAllBreak;
   bool CloseApp;
	bool LockOnClose;
	void __fastcall BtnClick(TObject *Sender);
   void __fastcall RenderLoop(TObject* Sender, bool &Done);

	void __fastcall OnActivate(CBase *Sender);
	void __fastcall OnClose(TObject *Sender,
                           TCloseAction &Action);
public:
  	TResetButtonsHandler OnResetButtons;
	CProjCont(TCFGFile *CFGFile, TDSKFile *DSKFile);
   void __fastcall SetConfig(bool AlignToGrid, bool SmartLink,
                             DWORD FieldColor, DWORD GridColor,
                             int AcFieldWidth, int AcFieldHeight,
                             int AcGridStep);

   int ProjCounter;
   int DefaultWndLeft;
   int DefaultWndTop;
   int DefaultWndWidth;
   int DefaultWndHeight;
   int DefaultFieldWidth;
   int DefaultFieldHeight;

   T_ID __fastcall GetID(void);
   void __fastcall ResetElBts(void);

   T_ID CURRENT_ID;
   void __fastcall CalcActive(void);
   void __fastcall CalcActiveByStep(void);
	void __fastcall OpenGraph(void);

	TCFGFile *CFGFile;
	TDSKFile *DSKFile;
	TList *PWnds;
   AnsiString DefaultProjName;
   AnsiString DefaultProjExt;
   AnsiString DefaultProjFolder;
   AnsiString ProjFolder;
   CBase *Parent;
   CProj *AcProj;
   virtual void __fastcall Init(CBase *Parent);
	void __fastcall NewProject(void);
	void __fastcall OpenProject(void);
	void __fastcall OpenLastProjects(void);
   void __fastcall SaveActiveProj(void);
   void __fastcall SaveAllProjs(void);
   void __fastcall SaveAsActiveProj(void);
   void __fastcall CloseActiveProj(void);
   TCloseAction __fastcall CloseAllProjs(bool CloseApp);
   TList* __fastcall GetProjWndList(void)
   {
      return PWnds;
   }
   TPRJFile* __fastcall GetActivePRJData(void)
   {
   	if(AcProj)
   		return AcProj->GetPRJFile();
      else
      	return NULL;
   }
   bool __fastcall ElBtsVisible(void);
   void __fastcall ShowElBts(void);
   void __fastcall HideElBts(void);
   void __fastcall SetDSK(void);
   virtual void __fastcall Done(void);
};
//---------------------------------------------------------------------------
#endif
