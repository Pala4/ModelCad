//---------------------------------------------------------------------------
#ifndef CharFrmH
#define CharFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TShowChar)(int CharIndex,
                                               long double D1,
                                               long double D2,
                                               long double DD);
//---------------------------------------------------------------------------
class TFChar : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PCChars;
	TButton *BtShow;
	TTabSheet *TSTemp;
	TTabSheet *TSFreq;
	TRadioGroup *RGTemp;
	TLabel *LTempWidth;
	TEdit *ET1;
	TLabel *LTempS;
	TEdit *ET2;
	TRadioGroup *RGFreq;
	TEdit *EW1;
	TLabel *LFreqS;
	TEdit *EW2;
	TLabel *LFreqWidth;
	TLabel *LDT;
	TEdit *EDT;
	TLabel *LDW;
	TEdit *EDW;
	TButton *BtOk;
	TButton *BtCancel;
	void __fastcall BtShowClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   bool ResultOk;
   int CharGroup;
   int CharTIndex;
   int CharFIndex;
   long double T1;
   long double T2;
   long double DT;
   long double W1;
   long double W2;
   long double DW;
	TShowChar ShowChar;
	__fastcall TFChar(TComponent *Owner);
};
//---------------------------------------------------------------------------
#endif
