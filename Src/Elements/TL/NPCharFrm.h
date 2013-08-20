//---------------------------------------------------------------------------
#ifndef NPCharFrmH
#define NPCharFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "..\..\GrpApi\Grp.h"
//---------------------------------------------------------------------------
class TFNPChar : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	CGrps *Grp;
	__fastcall TFNPChar(TComponent* Owner);
   void __fastcall AddRoot(long double Re, long double Im, AnsiString Res);
};
//---------------------------------------------------------------------------
#endif
