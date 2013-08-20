//---------------------------------------------------------------------------
#ifndef PDRegPropFrmH
#define PDRegPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFPDProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LC1;
	TLabel *LC2;
	TEdit *EC1;
	TEdit *EC2;
	TPanel *PImPD;
	TImage *ImPD;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
   bool ResultOk;
   long double C1;
   long double C2;
	__fastcall TFPDProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
