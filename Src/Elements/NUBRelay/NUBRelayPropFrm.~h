//---------------------------------------------------------------------------
#ifndef NUBRelayPropFrmH
#define NUBRelayPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFNUBRelayProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LA;
	TLabel *LdX;
	TLabel *LdY;
	TLabel *LB;
	TEdit *EA;
	TEdit *EdX;
	TEdit *EdY;
	TEdit *EB;
	TPanel *PImNUBRelay;
	TImage *ImNUBRelay;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	bool ResultOk;
   long double A;
   long double B;
   long double dX;
   long double dY;
	__fastcall TFNUBRelayProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
