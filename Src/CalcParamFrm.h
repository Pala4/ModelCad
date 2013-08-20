//---------------------------------------------------------------------------
#ifndef CalcParamFrmH
#define CalcParamFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFCalcParam : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RGCalcAlg;
	TGroupBox *GBxTRegion;
	TGroupBox *GBxWRegion;
	TButton *BtOk;
	TButton *BtCancel;
	TLabel *LDT;
	TEdit *EDT;
	TLabel *LT;
	TEdit *ET;
	TLabel *LDW;
	TLabel *LW;
	TEdit *EDW;
	TEdit *EW;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
   bool ResultOk;
	long double DT;
   long double T;
   long double DW;
   long double W;
	__fastcall TFCalcParam(TComponent *Owner);
};
//---------------------------------------------------------------------------
#endif
