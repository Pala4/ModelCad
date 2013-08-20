//---------------------------------------------------------------------------
#ifndef NoSensePropFrmH
#define NoSensePropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFNoSenseProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LA;
	TLabel *LK;
	TEdit *EA;
	TEdit *EK;
	TLabel *LdX;
	TLabel *LdY;
	TEdit *EdX;
	TEdit *EdY;
	TPanel *PImNoSense;
	TImage *ImNoSense;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
  	bool ResultOk;
  	long double A;
  	long double K;
  	long double dX;
  	long double dY;
	__fastcall TFNoSenseProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
