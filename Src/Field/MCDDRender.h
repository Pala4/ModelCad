//---------------------------------------------------------------------------
#ifndef MCDDRenderH
#define MCDDRenderH

#include <ddraw.h>

#include "DDErrors.h"
#include "MCRender.h"
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TRestore)(void);
//---------------------------------------------------------------------------
class CDDRender : public CRender
{
private:
   int ScrX;
   int ScrY;
   TCanvas *Canvas;
   TWinControl *Parent;
	LPDIRECTDRAW lpDDraw;
	LPDIRECTDRAWSURFACE lpDDSPrim;
   LPDIRECTDRAWSURFACE lpDDSBack;
   LPDIRECTDRAWSURFACE lpDDSGrid;
   LPDIRECTDRAWCLIPPER lpDDClip;
   BOOL DDCreate(void);
   BOOL SetCoopLevel(void);
   BOOL CreateGrid(void);
   BOOL CreateFlipper(void);
   void FillGrid(HDC hdc);
public:
	int GridStep;
   HRESULT DDResult;
	CDDRender(void);
   void __fastcall virtual Init(TForm *_FMain);
   LPDIRECTDRAW GetDD(void){return lpDDraw;}
   LPDIRECTDRAWSURFACE GetDDSB(void){return lpDDSBack;}
   void __fastcall virtual SetParent(TWinControl *_Parent)
   {
   	Parent = _Parent;
   }
   BOOL __fastcall virtual SetMetrix(DWORD _Width, DWORD _Height);
   void __fastcall virtual SetColor(DWORD _FieldColor,
                                    DWORD _GridColor);
   BOOL __fastcall virtual DrawGrid(void);
	BOOL __fastcall virtual CopyBuf(LPDIRECTDRAWSURFACE lpDDS,
                                   TRestore Restore,
                                   int &X, int &Y,
                                   DWORD Width, DWORD Height);
   void __fastcall virtual Scroll(int DX, int DY)
   {
   	ScrX = DX;
      ScrY = DY;
   }
   BOOL __fastcall virtual Flip(void);
   void __fastcall virtual Done(void);
};
//---------------------------------------------------------------------------
#endif
