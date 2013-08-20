//---------------------------------------------------------------------------
#ifndef TransLinkPropFrmH
#define TransLinkPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Graphics.hpp>
#include <Forms.hpp>

#include "CharFrm.h"
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TApply)(void);
//---------------------------------------------------------------------------
class TFTransLinkProp : public TForm
{
__published:	// IDE-managed Components
	TPanel *PImTransLink;
	TGroupBox *GBxParam;
	TRadioGroup *RGAlgType;
	TRadioGroup *RGModelType;
	TGroupBox *GBxTL;
	TLabel *LTLDiv;
	TLabel *LTL;
	TLabel *LTLMulK;
	TLabel *LNs;
	TLabel *LTs;
	TLabel *LK;
	TEdit *ETs;
	TEdit *ENs;
	TEdit *EK;
	TButton *BtChar;
	TImage *ImTLViewG;
	TImage *ImTLViewT;
	TButton *BtOk;
	TButton *BtCancel;
	TButton *BtApply;
	void __fastcall RGModelTypeClick(TObject *Sender);
	void __fastcall BtOkApplyClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
	void __fastcall EKKeyPress(TObject *Sender, char &Key);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall BtCharClick(TObject *Sender);
	void __fastcall RGAlgTypeClick(TObject *Sender);
	void __fastcall EChange(TObject *Sender);
private:	// User declarations
   long double* StrToArray(AnsiString Str, AnsiString Separator, DWORD &Num);
public:		// User declarations
	bool ResultOk;
   DWORD n;
   DWORD m;
   int CharGroup;
   int CharTIndex;
   int CharFIndex;
   long double T1;
   long double T2;
   long double DT;
   long double W1;
   long double W2;
   long double DW;
   long double K;
   long double *N;
   long double *T;
   TShowChar ShowChar;
   TApply Apply;
   TFChar *FChar;
	__fastcall TFTransLinkProp(TComponent *Owner);
   AnsiString ArrayToStr(long double *Array, DWORD Num);
};
//---------------------------------------------------------------------------
#endif
