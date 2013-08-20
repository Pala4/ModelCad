//---------------------------------------------------------------------------
#ifndef GrpFrmH
#define GrpFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include <complex.h>
//---------------------------------------------------------------------------
class TForm_Grafic : public TForm
{
__published:	// IDE-managed Components
   void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
   long double DT;
	long double T;
   bool EnAct;
	std::complex<long double> *Y;

	__fastcall TForm_Grafic(TComponent* Owner);
   void __fastcall SetAxName(AnsiString X, AnsiString Y);
   void __fastcall AddGrp(long double *XX, long double *YY, int N);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Grafic *Form_Grafic;
//---------------------------------------------------------------------------
#endif
