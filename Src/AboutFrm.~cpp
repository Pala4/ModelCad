//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "AboutFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFAbout::TFAbout(TComponent* Owner):TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAbout::ImAboutMouseDown(TObject *Sender,
                                          TMouseButton Button,
                                          TShiftState Shift,
                                          int X, int Y)
{
	long int SC_DRAGMOVE = 0xF012;
   if(Button == mbLeft)
   {
   	ReleaseCapture();
		SendMessage(Handle, WM_SYSCOMMAND, SC_DRAGMOVE, 0);
   }
}
//---------------------------------------------------------------------------
void __fastcall TFAbout::LLinkClick(TObject *Sender)
{
	ShellExecute(Handle, "open", "http://www.brstu.ru", NULL, NULL, 0);
}
//---------------------------------------------------------------------------
void __fastcall TFAbout::LCloseClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFAbout::FormKeyPress(TObject *Sender, char &Key)
{
   Close();
}
//---------------------------------------------------------------------------
