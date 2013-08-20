//---------------------------------------------------------------------------
#ifndef MCFieldH
#define MCFieldH

#include <comctrls.hpp>

#include "..\MCBase.h"
#include "..\Els.h"
#include "MCDDRender.h"
//---------------------------------------------------------------------------
class CSelector
{
private:
   BOOL Visible;
   BOOL DrawLinkOrient;
   BOOL BPP256;
   Windows::TRect SvFrameRect;
   Windows::TRect FrameRect;
   Windows::TRect LORect;
   LPDIRECTDRAWSURFACE lpDDS;
   TColor FrameColor;
   TColor LOFrameColor;
   TCanvas *Canvas;
public:
   BOOL Selected;
   BOOL SelConsist;
   BOOL SelFrame;
   T_ORIENT CURRENT_OR;
   TList *SelBuf;
   TList *LinkBuf;
	CSelector(void);
   void __fastcall virtual Init(LPDIRECTDRAWSURFACE _lpDDS){lpDDS = _lpDDS;}
   void __fastcall virtual Select(CElement *SelAddr);
   void __fastcall virtual UnSelect(void);
   void __fastcall virtual SelGroup(CEls *Els);
   BOOL __fastcall virtual Consist(CElement *SelAddr);
   void __fastcall virtual StartFrame(DWORD StartXFrame,
                                      DWORD StartYFrame);
   void __fastcall virtual UpDateFrame(DWORD EndXFrame,
                                       DWORD EndYFrame);
   void __fastcall virtual EndFrame(void);
   void __fastcall virtual Draw(DWORD DX, DWORD DY, HDC hdc);
   void __fastcall virtual CalcLinkOrient(CElement *El, int X, int Y);
   void __fastcall virtual DoneLinkOrient(void)
   {
   	DrawLinkOrient = FALSE;
   }
   void __fastcall virtual Done(void);
   virtual ~CSelector(void);
};
//---------------------------------------------------------------------------
class CField : public CIcarBase
{
private:
   TPanel *PScrBrs;
   TScrollBar *ScrBrHorz;
   TScrollBar *ScrBrVert;
   TWinControl *Parent;
   void __fastcall OutLoopBody(TObject *Sender, bool &Done);
   void __fastcall OnResize(TObject *Sender);
public:
	bool SmartLink;
   bool EnableAlignToGreed;
	CDDRender *DDRender;
   CSelector *Selector;
   CEls *Els;
   int ScrPosX;
   int ScrPosY;
	CField(void);
   void __fastcall virtual Init(TForm *_FMain);
   void __fastcall virtual SetParent(TWinControl *_Parent)
   {
   	Parent = _Parent;
   }
   void __fastcall virtual SetMetrix(DWORD Width, DWORD Height);
   void __fastcall virtual SetColor(DWORD FieldColor,
                                    DWORD GridColor);
   void __fastcall virtual UseSmartLink(BOOL Smart){SmartLink = Smart;}
   void __fastcall virtual Render(void);
   void __fastcall virtual AddElem(T_ID ID_ELEM, DWORD X, DWORD Y);
   void __fastcall AlignToGreed(DWORD &X, DWORD &Y);
   void __fastcall virtual Linking(CElement *El, T_ORIENT OR);
   void __fastcall DelSelected(void);
   void __fastcall OnScroll(TObject *Sender,
                            TScrollCode ScrollCode,
                            int &ScrollPos);
   CElement* __fastcall ElemClick(int X, int Y);
   void __fastcall virtual Done(void);
   void __fastcall virtual OpenGraph(void);
   virtual __fastcall ~CField(void);
};
//---------------------------------------------------------------------------
#endif
