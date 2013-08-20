//---------------------------------------------------------------------------
#ifndef SmPropFrmH
#define SmPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFSmProp : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GBxInvers;
	TImage *ImSm;
	TCheckBox *CBxTopInvers;
	TCheckBox *CBxRightInvers;
	TCheckBox *CBxBottomInvers;
	TCheckBox *CBxLeftInvers;
	TButton *BtOk;
	TButton *BtCancel;
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall BtOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	bool Result;
	__fastcall TFSmProp(TComponent *Owner);
};
//---------------------------------------------------------------------------
#endif
