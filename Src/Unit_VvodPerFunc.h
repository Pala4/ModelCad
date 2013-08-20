//---------------------------------------------------------------------------

#ifndef Unit_VvodPerFuncH
#define Unit_VvodPerFuncH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//#include "EditLetNum.h"

//---------------------------------------------------------------------------
class TForm_PerFunc : public TForm
{
__published:	// IDE-managed Components
        TCSpinEdit *CSE_znach;
        TBitBtn *BB_Add;
        TLabel *Label1;
        TListBox *LB_A;
        TListBox *LB_B;
        TLabel *Label2;
        TBitBtn *BB_Ok;
        TBitBtn *BB_Cancel;
	TEdit *Edit1;
	TEdit *Edit_B;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *EDW;
        TEdit *EWMax;
        TCheckBox *CB_Tkoff;
        TEdit *E_KofUsil;
        TLabel *Label5;
        //TEdit *Edit1;
        //TEdit *Edit_B;
        void __fastcall BB_AddClick(TObject *Sender);
        void __fastcall LB_AClick(TObject *Sender);
        void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall LB_BClick(TObject *Sender);
        void __fastcall Edit_BKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall BB_OkClick(TObject *Sender);
        void __fastcall CSE_znachKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall CSE_znachClick(TObject *Sender);
        void __fastcall Edit1KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Edit_BKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall BB_CancelClick(TObject *Sender);
        void __fastcall CB_TkoffClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
double *A_i, *B_i;
long double K;
bool Ok, TT_kof;
        __fastcall TForm_PerFunc(TComponent* Owner);
BYTE count_An;
bool zapusk;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_PerFunc *Form_PerFunc;
//---------------------------------------------------------------------------
#endif
