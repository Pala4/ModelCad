//---------------------------------------------------------------------------
#ifndef ZPropFrmH
#define ZPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Graphics.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFZProp : public TForm
{
__published:	// IDE-managed Components
	TPanel *PImZ;
	TGroupBox *GBxParam;
	TImage *ImZ;
	TLabel *LBz;
	TEdit *EBz;
	TLabel *LZDiv;
	TEdit *EAz;
	TLabel *LAz;
	TLabel *LZ;
	TButton *BtOk;
	TButton *BtCancel;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
   long double* StrToArray(AnsiString Str, AnsiString Separator, DWORD &Num);
public:		// User declarations
	bool ResultOk;
   DWORD Azn;
   DWORD Bzn;
   long double *Az;
   long double *Bz;
	__fastcall TFZProp(TComponent *Owner);
   AnsiString ArrayToStr(long double *Array, DWORD Num);
};
//---------------------------------------------------------------------------
#endif
