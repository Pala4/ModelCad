//---------------------------------------------------------------------------
#ifndef GaussNoisePropFrmH
#define GaussNoisePropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFGaussNoiseProp : public TForm
{
__published:	// IDE-managed Components
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxParam;
	TLabel *LMW;
	TLabel *LD;
	TEdit *EMW;
	TEdit *ED;
	TPanel *PImGaussNoise;
	TImage *ImGaussNoise;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	bool ResultOk;
   long double MW;
   long double D;
	__fastcall TFGaussNoiseProp(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
