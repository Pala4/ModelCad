//---------------------------------------------------------------------------
#ifndef PPropFrmH
#define PPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TF1PProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LN;
	TLabel *LK;
	TEdit *EN;
	TEdit *EK;
	TPanel *PIm1P;
	TImage *Im1P;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
   bool ResultOk;
   long double N;
   long double K;
	__fastcall TF1PProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
