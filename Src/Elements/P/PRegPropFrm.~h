//---------------------------------------------------------------------------
#ifndef PRegPropFrmH
#define PRegPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFPProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LC1;
	TEdit *EC1;
	TPanel *PImP;
	TImage *ImP;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
   bool ResultOk;
   long double C1;
	__fastcall TFPProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
