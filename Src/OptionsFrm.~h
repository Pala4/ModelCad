//---------------------------------------------------------------------------
#ifndef OptionsFrmH
#define OptionsFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TFOptions : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PCOptions;
	TTabSheet *TSGeneral;
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxAutoSave;
	TCheckBox *CBxASProgSet;
	TCheckBox *CBxASProj;
	TRadioGroup *RGDoStart;
	TTabSheet *TSView;
	TGroupBox *GBxProjField;
	TEdit *EFieldColor;
	TLabel *LFCHexPref;
	TLabel *LFieldColor;
	TLabel *LGridColor;
	TEdit *EGridColor;
	TLabel *LGCHexPref;
	TButton *BtChGridColor;
	TColorDialog *CDlgView;
	TButton *BtFCDefault;
	TButton *BtGCDefault;
	TCSpinEdit *SEFieldWidth;
	TLabel *LFieldWidth;
	TCSpinEdit *SEFieldHeight;
	TLabel *LFieldHeight;
	TCheckBox *CBxGridVisible;
	TCheckBox *CBxAlignToGrid;
	TCheckBox *CBxUseSmartLink;
	TButton *BtChFieldColor;
	TCheckBox *CBxASDesk;
	void __fastcall BtChColorClick(TObject *Sender);
	void __fastcall BtDefaultClick(TObject *Sender);
private:	// User declarations
	void __fastcall EColorKeyPress(TObject *Sender, char &Key);
public:		// User declarations
	long DefaultFieldColor;
   long DefaultGridColor;
	__fastcall TFOptions(TComponent *Owner);
	long StrHexToInt(AnsiString HexText, BYTE StartIndex);
};
//---------------------------------------------------------------------------
#endif