//---------------------------------------------------------------------------
#ifndef LuftPropFrmH
#define LuftPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFLuftProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LA;
	TLabel *LK;
	TLabel *LdX;
	TLabel *LdY;
	TEdit *EA;
	TEdit *EK;
	TEdit *EdX;
	TEdit *EdY;
	TPanel *PImLuft;
	TImage *ImLuft;
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
	__fastcall TFLuftProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
