//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SmPropFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFSmProp::TFSmProp(TComponent *Owner):TForm(Owner)
{
	Result = false;
}
//---------------------------------------------------------------------------
void __fastcall TFSmProp::BtOkClick(TObject *Sender)
{
	Result = true;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFSmProp::BtCancelClick(TObject *Sender)
{
	Result = false;
	Close();
}
//---------------------------------------------------------------------------
