//---------------------------------------------------------------------------
#ifndef InPropFrmH
#define InPropFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFInProp : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RGInfluenceType;
	TPageControl *PCInProp;
	TTabSheet *TS1T;
	TTabSheet *TS1D;
	TTabSheet *TSSin;
	TTabSheet *TSSaw;
	TTabSheet *TSRect;
	TTabSheet *TSRandom;
	TTabSheet *TSFile;
	TOpenDialog *OpDlgFN;
	TTabSheet *TSLine;
	TGroupBox *GBx1TParam;
	TLabel *L1TA;
	TEdit *E1TA;
	TGroupBox *GBxSinParam;
	TRadioGroup *RGSinCorner;
	TLabel *LSinA;
	TLabel *LSinW;
	TLabel *LSinF;
	TEdit *ESinF;
	TEdit *ESinW;
	TEdit *ESinA;
	TPanel *PImIn;
	TImage *Im1T;
	TImage *Im1D;
	TImage *ImLine;
	TImage *ImSin;
	TImage *ImSaw;
	TImage *ImRect;
	TImage *ImRandom;
	TButton *BtOk;
	TButton *BtCancel;
	TGroupBox *GBxLineParam;
	TLabel *LLK;
	TEdit *ELK;
	TGroupBox *GBxSawParam;
	TEdit *ESS;
	TLabel *LSS;
	TLabel *LSA;
	TEdit *ESA;
	TGroupBox *GBxRectParam;
	TLabel *LRS;
	TLabel *LRA;
	TEdit *ERS;
	TEdit *ERA;
	TGroupBox *GBxRandomParam;
	TEdit *ERandMW;
	TEdit *ERandD;
	TLabel *LRandD;
	TLabel *LRandMW;
	TGroupBox *GBxFileParam;
	TLabel *LFFN;
	TEdit *EFFN;
	TButton *BtFFN;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtCancelClick(TObject *Sender);
	void __fastcall RGInfluenceTypeClick(TObject *Sender);
	void __fastcall EKeyPress(TObject *Sender, char &Key);
	void __fastcall BtFFNClick(TObject *Sender);
	void __fastcall RGSinCornerClick(TObject *Sender);
private:	// User declarations
	TImage *ImCurVisible;
   void __fastcall ShowImage(int Index);
public:		// User declarations
	bool ResultOk;
   long double V1TA;
   long double VLK;
   long double VSinA;
   long double VSinW;
   long double VSinF;
   long double VSA;
   long double VSS;
   long double VRA;
   long double VRS;
   long double VRandMW;
   long double VRandD;
   AnsiString VFFN;
	__fastcall TFInProp(TComponent *Owner);
};
//---------------------------------------------------------------------------
#endif
