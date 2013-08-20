//---------------------------------------------------------------------------
#ifndef PIRegPropFrmH
#define PIRegPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFPIProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LC1;
	TLabel *LC0;
	TEdit *EC1;
	TEdit *EC0;
	TPanel *PImPI;
	TImage *ImPI;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
   bool ResultOk;
   long double C1;
   long double C0;
	__fastcall TFPIProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
