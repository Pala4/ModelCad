//---------------------------------------------------------------------------
#ifndef MCElementH
#define MCElementH

#include <ddraw.h>
#include <math.h>
#include <Math.hpp>

#include "MCadID.h"
#include "polynom.h"
#include "..\GrpApi\GrpWin.h"
//---------------------------------------------------------------------------
class CElement
{
private:
	TPopupMenu *PMEl;
   void __fastcall InitSurface(LPDIRECTDRAW lpDDraw);
   void __fastcall SetImage(LPSTR ResName);
	DWORD __fastcall DDColorMatch(LPDIRECTDRAWSURFACE lpDDSA,
                                 COLORREF rgb);
   void __fastcall SetMetrix(DWORD _Width, DWORD _Height)
   {
   	Width = _Width;
      Height = _Height;
   }
   void __fastcall PMPropClick(TObject *Sender);
   void __fastcall PMGrpClick(TObject *Sender);
protected:
   DWORD EndIndex;
   long double DT;
   long double T;
   AnsiString ElName;
   AnsiString GrpName;
   AnsiString AxXName;
   AnsiString AxYName;
   LPSTR ResName;
   TFGrp *FGrp;
   virtual bool CheckOut(void){return false;}
	void __fastcall AddValue(void *&Data, DWORD &DataSize,
                            void *Value, int ValSize);
	void __fastcall GetValue(void *&Data, DWORD &DataSize,
                            void *Value, int ValSize);
public:
   int ScrPosX;
   int ScrPosY;
   int DragLeft;
   int DragTop;
   int Left;
   int Top;
   DWORD Width;
   DWORD Height;
	T_ID ID_ELEM;
	T_ID ID_OBJECT;
	LPDIRECTDRAWSURFACE lpDDS;
	complex <long double>Y_out;
	CElement(void);
   virtual void __fastcall Create(LPDIRECTDRAW lpDDraw, LPSTR ResName,
                                  int _Left, int _Top, DWORD _Width, DWORD _Height,
                                  int SX, int SY);
   void __fastcall Restore(void);
   BOOL __fastcall virtual OrientBusy(T_ORIENT OR){return FALSE;}
   virtual void __fastcall ShowPopupMenu(int X, int Y);
   virtual void __fastcall SetData(void){}
   virtual void __fastcall ShowGrp(void){}
   virtual void VICHISLENIE(int index, int end, long double DT);
   virtual void DELETE_GRAFIC_MASSIV(void){}
   virtual void DelLink(void *LinkPtr) = 0;
   virtual void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
   virtual void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
   virtual void DelInfo(void){}
	virtual ~CElement(void);
};
//---------------------------------------------------------------------------
#endif
