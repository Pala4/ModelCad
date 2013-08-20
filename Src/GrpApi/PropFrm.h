//---------------------------------------------------------------------------
#ifndef PropFrmH
#define PropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include "CSPIN.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TOnAdvanced)(void);
//---------------------------------------------------------------------------
class TFProperty : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PCProp;
	TTabSheet *TSAxis;
	TGroupBox *GrBxVisible;
	TCheckBox *ChBxAXVisible;
	TCheckBox *ChBxAYVisible;
	TTabSheet *TSField;
	TEdit *EAxColor;
	TButton *BtAxColor;
	TLabel *LAxColor;
	TLabel *LAxCHexPref;
	TLabel *LFCHexPref;
	TLabel *LFColor;
	TButton *BtOK;
	TButton *BtCancel;
	TEdit *EFColor;
	TButton *BtFColor;
	TColorDialog *CDlgProp;
	TButton *BtAxCDefault;
	TButton *BtFCDefault;
	TGroupBox *GrBxInvert;
	TCheckBox *ChBxAXInvert;
	TCheckBox *ChBxAYInvert;
	TButton *BtAdvanced;
	TCheckBox *CBxSaveSers;
	TPanel *PNumSers;
	TLabel *LNumSers;
	TEdit *ENumSers;
	void __fastcall BtColorClick(TObject *Sender);
	void __fastcall BtDefaultClick(TObject *Sender);
	void __fastcall BtAdvancedClick(TObject *Sender);
	void __fastcall CBxSaveSersClick(TObject *Sender);
	void __fastcall ENumSersKeyPress(TObject *Sender, char &Key);
	void __fastcall BtOKClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
private:	// User declarations
	TOnAdvanced FOnAdvanced;
   void __fastcall SetAdvabced(TOnAdvanced AOnAdvanced);
	void __fastcall EColorKeyPress(TObject *Sender, char &Key);
public:		// User declarations
   bool ResultOk;
   long int NumSers;
   __property TOnAdvanced OnAdvanced = {write = SetAdvabced, default = NULL};
	__fastcall TFProperty(TComponent *Owner);
	long __fastcall StrHexToInt(AnsiString HexText, BYTE StartIndex);
};
//---------------------------------------------------------------------------
#endif
