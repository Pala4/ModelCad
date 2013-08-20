//---------------------------------------------------------------------------
#ifndef SinPropFrmH
#define SinPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFSinProp : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RGCorner;
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LA;
	TLabel *LF;
	TLabel *LW;
	TEdit *EA;
	TEdit *EF;
	TEdit *EW;
	TPanel *PImSin;
	TImage *ImSin;
	TLabel *LdX;
	TLabel *LdY;
	TEdit *EdY;
	TEdit *EdX;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
	void __fastcall RGCornerClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   bool ResultOk;
   long double A;
   long double W;
   long double F;
   long double dX;
   long double dY;
	__fastcall TFSinProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
