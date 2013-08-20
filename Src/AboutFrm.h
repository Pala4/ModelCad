//---------------------------------------------------------------------------
#ifndef AboutFrmH
#define AboutFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFAbout : public TForm
{
__published:	// IDE-managed Components
	TImage *ImAbout;
	TLabel *LLink;
	TLabel *LClose;
	void __fastcall LLinkClick(TObject *Sender);
	void __fastcall LCloseClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, char &Key);
	void __fastcall ImAboutMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TFAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
