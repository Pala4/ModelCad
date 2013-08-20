//---------------------------------------------------------------------------
#ifndef UBRelayFrmH
#define UBRelayFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFUBRelayProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LB;
	TLabel *LdX;
	TLabel *LdY;
	TEdit *EB;
	TEdit *EdX;
	TEdit *EdY;
	TPanel *PImUBRelay;
	TImage *ImUBRelay;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EBKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	bool ResultOk;
   long double B;
  	long double dX;
  	long double dY;
	__fastcall TFUBRelayProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
