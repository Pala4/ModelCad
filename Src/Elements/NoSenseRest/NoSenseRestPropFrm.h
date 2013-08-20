//---------------------------------------------------------------------------
#ifndef NoSenseRestPropFrmH
#define NoSenseRestPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFNoSenseRestProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LA;
	TLabel *LK;
	TLabel *LdX;
	TLabel *LdY;
	TLabel *LB;
	TEdit *EA;
	TEdit *EK;
	TEdit *EdX;
	TEdit *EdY;
	TEdit *EB;
	TPanel *PImNoSenseRest;
	TImage *ImNoSenseRest;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	bool ResultOk;
   long double A;
   long double B;
   long double K;
   long double dX;
   long double dY;
	__fastcall TFNoSenseRestProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
