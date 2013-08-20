//---------------------------------------------------------------------------
#ifndef GrpWinH
#define GrpWinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>

#include "Grp.h"
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TOnGrpClose)(void);
//---------------------------------------------------------------------------
class TFGrp : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MGrp;
	TMenuItem *MIFile;
	TMenuItem *MIClose;
	TStatusBar *StBrGrp;
	TScrollBox *ScrBxGrp;
	TMenuItem *MIParam;
	TMenuItem *N1;
	TMenuItem *MIPageParam;
	TMenuItem *MIPreView;
	TMenuItem *MIPrint;
	TMenuItem *N2;
	TMenuItem *MIEdit;
	TMenuItem *MICut;
	TMenuItem *MICopy;
	TMenuItem *MIPast;
	TMenuItem *MIDel;
	TMenuItem *MISelectAll;
	TMenuItem *MIClipBoard;
	TMenuItem *MICBClear;
	TMenuItem *N4;
	TMenuItem *MICopyData;
	TMenuItem *N5;
	TMenuItem *MIClearDiagram;
	void __fastcall MICloseClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall MICopyDataClick(TObject *Sender);
	void __fastcall MIParamClick(TObject *Sender);
	void __fastcall MIClearDiagramClick(TObject *Sender);
	void __fastcall MICheckClick(TObject *Sender);
	void __fastcall MIDelClick(TObject *Sender);
	void __fastcall MISelectAllClick(TObject *Sender);
	void __fastcall MICBClearClick(TObject *Sender);
	void __fastcall MICopyClick(TObject *Sender);
	void __fastcall MIPastClick(TObject *Sender);
private:	// User declarations
	CGrps *Grps;
   void __fastcall OnReleaseHitTest(void);
   void __fastcall GPHTDataEvent(TGPHTData GPHTData);
public:		// User declarations
	TOnGrpClose OnGrpClose;
	__fastcall TFGrp(TComponent *Owner);
   void __fastcall SetAxNames(AnsiString XName, AnsiString YName);
   void __fastcall AddPset(long double X, long double Y);
   void __fastcall AddSer(long double *X, long double *Y, DWORD N, AnsiString SerName = "");
};
//---------------------------------------------------------------------------
#endif
