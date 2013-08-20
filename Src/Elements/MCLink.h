//---------------------------------------------------------------------------
#ifndef MCLinkH
#define MCLinkH

#include "MCElement.h"
//---------------------------------------------------------------------------
class CLink
{
private:
   TPoint APs[3];
   RECT InversOutSign;
   RECT InversInSign;
	LPDIRECTDRAWSURFACE lpDDS;
   TCanvas *Canvas;
   void __fastcall virtual CalcLink(int DX, int DY);
   void __fastcall virtual CalcSmartLink(int DX, int DY);
   void __fastcall virtual CalcArrowEnd(int DX, int DY, BOOL Smart);
public:
   TPoint LPs[6];
   bool *InversOutPtr;
   bool InversOut;
   bool *InversInPtr;
   bool InversIn;
   bool Selected;
   DWORD DX;
   DWORD DY;
	T_ORIENT IN_OR;
   T_ORIENT OUT_OR;
   CElement *InEl;
   CElement *OutEl;
   CElement *OutElSm;
	CLink(void);
   void __fastcall virtual SetSurf(LPDIRECTDRAWSURFACE _lpDDS)
   {
   	lpDDS = _lpDDS;
   }
   void __fastcall virtual Draw(int DX, int DY, BOOL Smart, HDC DrawDC);
   ~CLink(void);
};
//---------------------------------------------------------------------------
#endif
