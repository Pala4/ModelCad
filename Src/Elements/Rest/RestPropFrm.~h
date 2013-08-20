//---------------------------------------------------------------------------
#ifndef RestPropFrmH
#define RestPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFRestProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LB;
	TLabel *LK;
	TLabel *LdX;
	TLabel *LdY;
	TEdit *EB;
	TEdit *EK;
	TEdit *EdX;
	TEdit *EdY;
	TPanel *PImRest;
	TImage *ImRest;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	bool ResultOk;
   long double B;
   long double K;
  	long double dX;
  	long double dY;
	__fastcall TFRestProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
