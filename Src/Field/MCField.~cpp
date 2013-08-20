//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCField.h"
#include "GrpFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CSelector::CSelector(void)
{
	Visible = FALSE;
   Selected = FALSE;
   SelConsist = FALSE;
   SelFrame = FALSE;
   SelBuf = new TList;
   LinkBuf = new TList;
   Canvas = new TCanvas;
   FrameColor = (TColor)0x00000000;
   if(GetDeviceCaps(GetDC(0), BITSPIXEL) < 16)
   	LOFrameColor = (TColor)0x00000000;
   else
      LOFrameColor = clGreen;
   DrawLinkOrient = FALSE;
   CURRENT_OR = OR_NONE;
}
//---------------------------------------------------------------------------
#include "MainFrm.h"
void __fastcall CSelector::Select(CElement *SelAddr)
{
   Selected = TRUE;
   Visible = TRUE;
   SelBuf->Add(SelAddr);
   PostMessage(FMain->Handle, WM_SETDATA, (WPARAM)SelAddr, 0);
}
//---------------------------------------------------------------------------
void __fastcall CSelector::UnSelect(void)
{
	SelBuf->Clear();
   for(int ci = 0; ci < LinkBuf->Count; ci++)
   	((CLink*)LinkBuf->Items[ci])->Selected = false;
   LinkBuf->Clear();
   Visible = FALSE;
   Selected = FALSE;
   SelConsist = FALSE;
   SelFrame = FALSE;
   PostMessage(FMain->Handle, WM_RESETDATA, 0, 0);
}
//---------------------------------------------------------------------------
BOOL __fastcall CSelector::Consist(CElement *SelAddr)
{
   if(SelBuf->IndexOf(SelAddr) == -1)
		return (SelConsist = FALSE);
   else
		return (SelConsist = TRUE);
}
//---------------------------------------------------------------------------
void __fastcall CSelector::SelGroup(CEls *Els)
{
	DWORD l = SvFrameRect.left, t = SvFrameRect.top;
   DWORD r = SvFrameRect.right, b = SvFrameRect.bottom;
   if(l > r)
   {
   	l = SvFrameRect.right;
      r = SvFrameRect.left;
   }
   if(t > b)
   {
   	t = SvFrameRect.bottom;
      b = SvFrameRect.top;
   }
   CElement *El;
   for(int ci = 0; ci < Els->TLs->Count; ci++)
   {
   	El = (CElement*)Els->TLs->Items[ci];
      if(El->Left+El->Width/2 > (DWORD)l && El->Left+El->Width/2 < (DWORD)r &&
         El->Top+El->Height/2 > (DWORD)t && El->Top+El->Height/2 < (DWORD)b)
      	Select(El);
   }
   for(int ci = 0; ci < Els->Sms->Count; ci++)
   {
   	El = (CElement*)Els->Sms->Items[ci];
      if(El->Left+El->Width/2 > (DWORD)l && El->Left+El->Width/2 < (DWORD)r &&
         El->Top+El->Height/2 > (DWORD)t && El->Top+El->Height/2 < (DWORD)b)
      	Select(El);
   }
   for(int ci = 0; ci < Els->Us->Count; ci++)
   {
   	El = (CElement*)Els->Us->Items[ci];
      if(El->Left+El->Width/2 > (DWORD)l && El->Left+El->Width/2 < (DWORD)r &&
         El->Top+El->Height/2 > (DWORD)t && El->Top+El->Height/2 < (DWORD)b)
      	Select(El);
   }
   for(int ci = 0; ci < Els->Ins->Count; ci++)
   {
   	El = (CElement*)Els->Ins->Items[ci];
      if(El->Left+El->Width/2 > (DWORD)l && El->Left+El->Width/2 < (DWORD)r &&
         El->Top+El->Height/2 > (DWORD)t && El->Top+El->Height/2 < (DWORD)b)
      	Select(El);
   }
   for(int ci = 0; ci < Els->Outs->Count; ci++)
   {
   	El = (CElement*)Els->Outs->Items[ci];
      if(El->Left+El->Width/2 > (DWORD)l && El->Left+El->Width/2 < (DWORD)r &&
         El->Top+El->Height/2 > (DWORD)t && El->Top+El->Height/2 < (DWORD)b)
      	Select(El);
   }
   for(int ci = 0; ci < Els->Ls->Count; ci++)
   {
       if((((CLink*)Els->Ls->Items[ci])->LPs[0].x - ((CLink*)Els->Ls->Items[ci])->DX >= l &&
           ((CLink*)Els->Ls->Items[ci])->LPs[0].x - ((CLink*)Els->Ls->Items[ci])->DX <= r &&
           ((CLink*)Els->Ls->Items[ci])->LPs[0].y - ((CLink*)Els->Ls->Items[ci])->DY >= t &&
           ((CLink*)Els->Ls->Items[ci])->LPs[0].y - ((CLink*)Els->Ls->Items[ci])->DY <= b) ||
          (((CLink*)Els->Ls->Items[ci])->LPs[1].x - ((CLink*)Els->Ls->Items[ci])->DX >= l &&
           ((CLink*)Els->Ls->Items[ci])->LPs[1].x - ((CLink*)Els->Ls->Items[ci])->DX <= r &&
           ((CLink*)Els->Ls->Items[ci])->LPs[1].y - ((CLink*)Els->Ls->Items[ci])->DY >= t &&
           ((CLink*)Els->Ls->Items[ci])->LPs[1].y - ((CLink*)Els->Ls->Items[ci])->DY <= b) ||
          (((CLink*)Els->Ls->Items[ci])->LPs[2].x - ((CLink*)Els->Ls->Items[ci])->DX >= l &&
           ((CLink*)Els->Ls->Items[ci])->LPs[2].x - ((CLink*)Els->Ls->Items[ci])->DX <= r &&
           ((CLink*)Els->Ls->Items[ci])->LPs[2].y - ((CLink*)Els->Ls->Items[ci])->DY >= t &&
           ((CLink*)Els->Ls->Items[ci])->LPs[2].y - ((CLink*)Els->Ls->Items[ci])->DY <= b) ||
          (((CLink*)Els->Ls->Items[ci])->LPs[3].x - ((CLink*)Els->Ls->Items[ci])->DX >= l &&
           ((CLink*)Els->Ls->Items[ci])->LPs[3].x - ((CLink*)Els->Ls->Items[ci])->DX <= r &&
           ((CLink*)Els->Ls->Items[ci])->LPs[3].y - ((CLink*)Els->Ls->Items[ci])->DY >= t &&
           ((CLink*)Els->Ls->Items[ci])->LPs[3].y - ((CLink*)Els->Ls->Items[ci])->DY <= b) ||
          (((CLink*)Els->Ls->Items[ci])->LPs[4].x - ((CLink*)Els->Ls->Items[ci])->DX >= l &&
           ((CLink*)Els->Ls->Items[ci])->LPs[4].x - ((CLink*)Els->Ls->Items[ci])->DX <= r &&
           ((CLink*)Els->Ls->Items[ci])->LPs[4].y - ((CLink*)Els->Ls->Items[ci])->DY >= t &&
           ((CLink*)Els->Ls->Items[ci])->LPs[4].y - ((CLink*)Els->Ls->Items[ci])->DY <= b) ||
          (((CLink*)Els->Ls->Items[ci])->LPs[5].x - ((CLink*)Els->Ls->Items[ci])->DX >= l &&
           ((CLink*)Els->Ls->Items[ci])->LPs[5].x - ((CLink*)Els->Ls->Items[ci])->DX <= r &&
           ((CLink*)Els->Ls->Items[ci])->LPs[5].y - ((CLink*)Els->Ls->Items[ci])->DY >= t &&
           ((CLink*)Els->Ls->Items[ci])->LPs[5].y - ((CLink*)Els->Ls->Items[ci])->DY <= b) ||
          (((CLink*)Els->Ls->Items[ci])->LPs[6].x - ((CLink*)Els->Ls->Items[ci])->DX >= l &&
           ((CLink*)Els->Ls->Items[ci])->LPs[6].x - ((CLink*)Els->Ls->Items[ci])->DX <= r &&
           ((CLink*)Els->Ls->Items[ci])->LPs[6].y - ((CLink*)Els->Ls->Items[ci])->DY >= t &&
           ((CLink*)Els->Ls->Items[ci])->LPs[6].y - ((CLink*)Els->Ls->Items[ci])->DY <= b))
       {
       	((CLink*)Els->Ls->Items[ci])->Selected = true;
       	LinkBuf->Add((CLink*)Els->Ls->Items[ci]);
       }
   }
}
//---------------------------------------------------------------------------
void __fastcall CSelector::StartFrame(DWORD StartXFrame,
                                      DWORD StartYFrame)
{
   SelFrame = TRUE;
	FrameRect.left = StartXFrame;
	FrameRect.top = StartYFrame;
   FrameRect.right = StartXFrame;
   FrameRect.bottom = StartYFrame;
   if(GetDeviceCaps(GetDC(0), BITSPIXEL) < 16)
   	BPP256 = TRUE;
   else
   	BPP256 = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall CSelector::UpDateFrame(DWORD EndXFrame,
                                       DWORD EndYFrame)
{
   if(SelFrame)
   {
		FrameRect.right = EndXFrame;
		FrameRect.bottom = EndYFrame;
   }
}
//---------------------------------------------------------------------------
void __fastcall CSelector::EndFrame(void)
{
	SelFrame = FALSE;
   SvFrameRect = FrameRect;
   FrameRect.left = 0;
   FrameRect.top = 0;
   FrameRect.right = 0;
   FrameRect.bottom = 0;
}
//---------------------------------------------------------------------------
void __fastcall CSelector::Draw(DWORD DX, DWORD DY, HDC hdc)
{
	//HDC hdc;
   //lpDDS->GetDC(&hdc);
   Canvas->Handle = hdc;
   if(Visible)
   {
      CElement *SelAddr;
      Canvas->Brush->Color = FrameColor;
      for(int ci = 0; ci < SelBuf->Count; ci++)
      {
         SelAddr = (CElement*)SelBuf->Items[ci];
         Canvas->FrameRect(Rect(SelAddr->Left+DX, SelAddr->Top+DY,
                                SelAddr->Left+SelAddr->Width+DX,
                                SelAddr->Top+SelAddr->Height+DY));
      }
   }
   if(SelFrame)
   {
   	int l = FrameRect.left, t = FrameRect.top;
      int r = FrameRect.right, b = FrameRect.bottom;
      if(l > r)
      {
      	l = FrameRect.right;
         r = FrameRect.left;
      }
      if(t > b)
      {
      	t = FrameRect.bottom;
         b = FrameRect.top;
      }
      Canvas->Brush->Color = FrameColor;
      Canvas->FrameRect(Rect(l+DX, t+DY, r+DX, b+DY));
   }
   if(DrawLinkOrient && CURRENT_OR != OR_BUSY)
   {
      Canvas->Brush->Color = LOFrameColor;
      Canvas->FrameRect(Rect(LORect.Left + DX, LORect.Top + DY,
                             LORect.Right + DX, LORect.Bottom + DY));
   }
   //lpDDS->ReleaseDC(hdc);
}
//---------------------------------------------------------------------------
void __fastcall CSelector::CalcLinkOrient(CElement *El, int X, int Y)
{
   switch(El->ID_ELEM)
   {
   	case ID_STDELEMENT:
      case ID_IN:
      case ID_UNIT:
      case ID_OUT:
      case ID_SUMMATOR:
         if(X >= El->Left && X <= El->Left + (int)El->Width*0.25 &&
            Y >= El->Top + (int)El->Height*0.25 && Y <= El->Top + (int)El->Height*0.75)
         {
         	LORect = Rect(El->Left,
                          El->Top + El->Height*0.25,
                          El->Left + El->Width*0.25,
                          El->Top + El->Height*0.75);
            DrawLinkOrient = TRUE;
            CURRENT_OR = OR_LEFT;
         }
         else
         	if(X >= El->Left + (int)El->Width*0.75 && X <= El->Left + (int)El->Width &&
               Y >= El->Top + (int)El->Height*0.25 && Y <= El->Top + (int)El->Height*0.75)
            {
         		LORect = Rect(El->Left + El->Width*0.75,
                             El->Top + El->Height*0.25,
                             El->Left + El->Width,
                             El->Top + El->Height*0.75);
            	DrawLinkOrient = TRUE;
               CURRENT_OR = OR_RIGHT;
            }
            else
            	if(X >= El->Left + (int)El->Width*0.25 && X <= El->Left + (int)El->Width*0.75 &&
                  Y >= El->Top && Y <= El->Top + (int)El->Height*0.25)
               {
         			LORect = Rect(El->Left + El->Width*0.25, El->Top,
                                El->Left + El->Width*0.75,
                                El->Top + El->Height*0.25);
                  DrawLinkOrient = TRUE;
                  CURRENT_OR = OR_TOP;
               }
               else
            		if(X >= El->Left + (int)El->Width*0.25 && X <= El->Left + (int)El->Width*0.75 &&
                  	Y >= El->Top + (int)El->Height*0.75 && Y <= El->Top + (int)El->Height)
               	{
         				LORect = Rect(El->Left + El->Width*0.25,
                                   El->Top + El->Height*0.75,
                                	  El->Left + El->Width*0.75,
                                   El->Top + El->Height);
                  	DrawLinkOrient = TRUE;
                     CURRENT_OR = OR_BOTTOM;
               	}
               	else
                  {
         				DrawLinkOrient = FALSE;
                  	CURRENT_OR = OR_BOTTOM;
                  }
      break;
      default:
 			DrawLinkOrient = FALSE;
         CURRENT_OR = OR_NONE;
   }
}
//---------------------------------------------------------------------------
void __fastcall CSelector::Done(void)
{
   if(SelBuf)
   {
		SelBuf->Clear();
   	delete SelBuf;
      SelBuf = NULL;
   }
   if(LinkBuf)
   {
   	LinkBuf->Clear();
   	delete LinkBuf;
      LinkBuf = NULL;
   }
}
//---------------------------------------------------------------------------
CSelector::~CSelector(void)
{
   if(SelBuf)
   {
		SelBuf->Clear();
   	delete SelBuf;
      SelBuf = NULL;
   }
   if(LinkBuf)
   {
   	LinkBuf->Clear();
   	delete LinkBuf;
      LinkBuf = NULL;
   }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CField::CField(void)
{
   SmartLink = true;
   EnableAlignToGreed = true;
	ScrPosX = 0;
   ScrPosY = 0;
	DDRender = new CDDRender;
   Els = new CEls;
   Selector = new CSelector;
}
//---------------------------------------------------------------------------
void __fastcall CField::Init(TForm *_FMain)
{
	CIcarBase::Init(_FMain);
   DDRender->SetParent(Parent);
   DDRender->Init(FMain);
   DDRender->SetColor(COLOR_BTNFACE, RGB(0x00, 0x00, 0x00));
   ((TTabSheet*)Parent)->OnResize = OnResize;
   Els->SetDD(DDRender->GetDD(), DDRender->GetDDSB());
   Selector->Init(DDRender->GetDDSB());

   ScrBrHorz = new TScrollBar(Parent);
   ScrBrHorz->Kind = sbHorizontal;
   ScrBrHorz->Anchors.Clear();
   ScrBrHorz->Anchors << akLeft << akRight << akBottom;
   ScrBrHorz->Max = 0;
   ScrBrHorz->OnScroll = OnScroll;
   ScrBrHorz->Parent = Parent;

   ScrBrVert = new TScrollBar(Parent);
   ScrBrVert->Kind = sbVertical;
   ScrBrVert->Max = 0;
   ScrBrVert->Anchors.Clear();
   ScrBrVert->Anchors << akTop << akRight << akBottom;
   ScrBrVert->OnScroll = OnScroll;
   ScrBrVert->Parent = Parent;

   ScrBrHorz->Top = Parent->ClientHeight - ScrBrHorz->Height;
   ScrBrHorz->Width = Parent->ClientWidth - ScrBrVert->Width;
   ScrBrVert->Left = Parent->ClientWidth - ScrBrVert->Width;
   ScrBrVert->Height = Parent->ClientHeight - ScrBrHorz->Height;

   PScrBrs = new TPanel(Parent);
   PScrBrs->Anchors.Clear();
   PScrBrs->Anchors << akRight << akBottom;
   PScrBrs->Left = Parent->ClientWidth - ScrBrVert->Width;
   PScrBrs->Top = Parent->ClientHeight - ScrBrHorz->Height;
   PScrBrs->Parent = Parent;
}
//---------------------------------------------------------------------------
void __fastcall CField::OnResize(TObject *Sender)
{
   int DW = DDRender->Width - ScrBrHorz->Position -
            Parent->ClientWidth - ScrBrVert->Width;
   int DH = DDRender->Height - ScrBrVert->Position -
            Parent->ClientHeight - ScrBrHorz->Height;
   if(ScrBrHorz->Position > 0 && DW <= 0)
   {
      ScrBrHorz->Position += DW;
      int Pos = ScrBrHorz->Position;
      ScrBrHorz->OnScroll(ScrBrHorz, scPosition, Pos);
   	ScrBrHorz->Max = ScrBrHorz->Position;
   }
   else
   {
   	DW = DW < 0 ? 0:DW;
   	ScrBrHorz->Max = ScrBrHorz->Position + DW;
   }
   if(ScrBrVert->Position > 0 && DH <= 0)
   {
      ScrBrVert->Position += DH;
      int Pos = ScrBrVert->Position;
      ScrBrVert->OnScroll(ScrBrVert, scPosition, Pos);
   	ScrBrVert->Max = ScrBrVert->Position;
   }
   else
   {
   	DH = DH < 0 ? 0:DH;
   	ScrBrVert->Max = ScrBrVert->Position + DH;
   }
}
//---------------------------------------------------------------------------
void __fastcall CField::OnScroll(TObject *Sender,
                                     TScrollCode ScrollCode,
                                     int &ScrollPos)
{
   DDRender->Scroll(ScrBrHorz->Position, ScrBrVert->Position);
   DDRender->Scroll(ScrBrHorz->Position, ScrBrVert->Position);
   int ci;
   CElement *El;
   int DX = ScrBrHorz->Position;
   int DY = ScrBrVert->Position;
   ScrPosX = DX;
   ScrPosY = DY;
   for(ci = 0; ci < Els->TLs->Count; ci++)
   {
   	El = (CStdElement*)Els->TLs->Items[ci];
      El->Left = El->ScrPosX - DX;
      El->Top = El->ScrPosY - DY;
   }
   for(ci = 0; ci < Els->Sms->Count; ci++)
   {
   	El = (CSummator*)Els->Sms->Items[ci];
      El->Left = El->ScrPosX - DX;
      El->Top = El->ScrPosY - DY;
   }
   for(ci = 0; ci < Els->Us->Count; ci++)
   {
   	El = (CUnit*)Els->Us->Items[ci];
      El->Left = El->ScrPosX - DX;
      El->Top = El->ScrPosY - DY;
   }
   for(ci = 0; ci < Els->Ins->Count; ci++)
   {
   	El = (CIn*)Els->Ins->Items[ci];
      El->Left = El->ScrPosX - DX;
      El->Top = El->ScrPosY - DY;
   }
   for(ci = 0; ci < Els->Outs->Count; ci++)
   {
   	El = (COut*)Els->Outs->Items[ci];
      El->Left = El->ScrPosX - DX;
      El->Top = El->ScrPosY - DY;
   }
   Render();
}
//---------------------------------------------------------------------------
void __fastcall CField::DelSelected(void)
{
   for(int ci = Selector->LinkBuf->Count - 1; ci >= 0; ci--)
   {
   	Els->Ls->Remove(Selector->LinkBuf->Items[ci]);
      delete (CLink*)Selector->LinkBuf->Items[ci];
   }
   for(int ci = Selector->SelBuf->Count - 1; ci >= 0; ci--)
      Els->Del((CElement*)Selector->SelBuf->Items[ci]);
   Selector->UnSelect();
	Render();
}
//---------------------------------------------------------------------------
void __fastcall CField::OutLoopBody(TObject *Sender, bool &Done)
{
//	Render();
}
//---------------------------------------------------------------------------
void __fastcall CField::SetMetrix(DWORD Width, DWORD Height)
{
   DDRender->SetMetrix(Width, Height);
   Selector->Init(DDRender->GetDDSB());
   Els->SetDD(DDRender->GetDD(), DDRender->GetDDSB());
   OnResize(NULL);
}
//---------------------------------------------------------------------------
void __fastcall CField::SetColor(DWORD FieldColor,
                                     DWORD GridColor)
{
	DDRender->SetColor(FieldColor, GridColor);
}
//---------------------------------------------------------------------------
void __fastcall CField::Render(void)
{
   if(DDRender)
   {
   	int ci;
   	int DX = ScrBrHorz->Position;
   	int DY = ScrBrVert->Position;
      if(!DDRender->DrawGrid())
      {
      	Application->MessageBox(DDErrToStr(DDRender->DDResult),
                                 "Draw Greed Error",
                                 MB_OK | MB_ICONERROR);
         Application->Terminate();
      }
      CElement *El;
      int X0, Y0;
      for(ci = 0; ci < Els->TLs->Count; ci++)
      {
          El = (CStdElement*)Els->TLs->Items[ci];
          X0 = El->Left + DX;
          Y0 = El->Top + DY;
          if(!DDRender->CopyBuf(El->lpDDS, El->Restore, X0, Y0,
                              El->Width, El->Height))
          {
          		Application->MessageBox(DDErrToStr(DDRender->DDResult),
                                    	"TLs Elements Draw Error",
                                    	MB_OK | MB_ICONERROR);
         		Application->Terminate();
          }
          El->Left = X0 - DX;
          El->Top = Y0 - DY;
      }
      for(ci = 0; ci < Els->Sms->Count; ci++)
      {
          El = (CSummator*)Els->Sms->Items[ci];
          X0 = El->Left + DX;
          Y0 = El->Top + DY;
          if(!DDRender->CopyBuf(El->lpDDS, El->Restore, X0, Y0,
                              El->Width, El->Height))
          {
          		Application->MessageBox(DDErrToStr(DDRender->DDResult),
                                    	"Sms Elements Draw Error",
                                    	MB_OK | MB_ICONERROR);
         		Application->Terminate();
          }
          El->Left = X0 - DX;
          El->Top = Y0 - DY;
      }
      for(ci = 0; ci < Els->Us->Count; ci++)
      {
          El = (CUnit*)Els->Us->Items[ci];
          X0 = El->Left + DX;
          Y0 = El->Top + DY;
          if(!DDRender->CopyBuf(El->lpDDS, El->Restore, X0, Y0,
                              El->Width, El->Height))
          {
          		Application->MessageBox(DDErrToStr(DDRender->DDResult),
                                    	"Us Elements Draw Error",
                                    	MB_OK | MB_ICONERROR);
         		Application->Terminate();
          }
          El->Left = X0 - DX;
          El->Top = Y0 - DY;
      }
      for(ci = 0; ci < Els->Ins->Count; ci++)
      {
          El = (CIn*)Els->Ins->Items[ci];
          X0 = El->Left + DX;
          Y0 = El->Top + DY;
          if(!DDRender->CopyBuf(El->lpDDS, El->Restore, X0, Y0,
                                El->Width, El->Height))
          {
          		Application->MessageBox(DDErrToStr(DDRender->DDResult),
                                    	"Ins Elements Draw Error",
                                    	MB_OK | MB_ICONERROR);
         		Application->Terminate();
          }
          El->Left = X0 - DX;
          El->Top = Y0 - DY;
      }
      for(ci = 0; ci < Els->Outs->Count; ci++)
      {
          El = (COut*)Els->Outs->Items[ci];
          X0 = El->Left + DX;
          Y0 = El->Top + DY;
          if(!DDRender->CopyBuf(El->lpDDS, El->Restore, X0, Y0,
                                El->Width, El->Height))
          {
          		Application->MessageBox(DDErrToStr(DDRender->DDResult),
                                    	"Outs Elements Draw Error",
                                    	MB_OK | MB_ICONERROR);
         		Application->Terminate();
          }
          El->Left = X0 - DX;
          El->Top = Y0 - DY;
      }
      LPDIRECTDRAWSURFACE lpDDSBack = DDRender->GetDDSB();
      HDC DrawDC;
      CLink *L;
      for(ci = 0; ci < Els->Ls->Count; ci++)
      {
          L = (CLink*)Els->Ls->Items[ci];
          lpDDSBack->GetDC(&DrawDC);
          L->Draw(DX, DY, SmartLink, DrawDC);
          lpDDSBack->ReleaseDC(DrawDC);
      }
      lpDDSBack->GetDC(&DrawDC);
      Selector->Draw(ScrBrHorz->Position, ScrBrVert->Position, DrawDC);
      lpDDSBack->ReleaseDC(DrawDC);
		if(!DDRender->Flip())
      {
      	Application->MessageBox(DDErrToStr(DDRender->DDResult),
                                 "Flip Draw Error",
                                 MB_OK | MB_ICONERROR);
         Application->Terminate();
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall CField::AddElem(T_ID ID_ELEM, DWORD X, DWORD Y)
{
   X -= ELEM_WIDTH / 2;
   Y -= ELEM_HEIGHT / 2;
   AlignToGreed(X, Y);
	Els->Add(ID_ELEM, X, Y, ScrPosX, ScrPosY);
}
//---------------------------------------------------------------------------
void __fastcall CField::AlignToGreed(DWORD &X, DWORD &Y)
{
	if(EnableAlignToGreed)
   {
		X = int(double(X)/double(DDRender->GridStep))*DDRender->GridStep;
		Y = int(double(Y)/double(DDRender->GridStep))*DDRender->GridStep;
   }
}
//---------------------------------------------------------------------------
void __fastcall CField::Linking(CElement *El, T_ORIENT OR)
{
	Els->Linking(El, OR);
   Render();
}
//---------------------------------------------------------------------------
CElement* __fastcall CField::ElemClick(int X, int Y)
{
   int ci;
   CElement *El;
   for(ci = Els->TLs->Count - 1; ci >= 0; ci--)
   {
      El = (CElement*)Els->TLs->Items[ci];
      if(X >= El->Left && Y >= El->Top &&
         X <= El->Left + (int)El->Width &&
         Y <= El->Top + (int)El->Height)
      return El;
   }
   for(ci = Els->Sms->Count - 1; ci >= 0; ci--)
   {
      El = (CElement*)Els->Sms->Items[ci];
      if(X >= El->Left && Y >= El->Top &&
         X <= El->Left + (int)El->Width &&
         Y <= El->Top + (int)El->Height)
      return El;
   }
   for(ci = Els->Us->Count - 1; ci >= 0; ci--)
   {
      El = (CElement*)Els->Us->Items[ci];
      if(X >= El->Left && Y >= El->Top &&
         X <= El->Left + (int)El->Width &&
         Y <= El->Top + (int)El->Height)
      return El;
   }
   for(ci = Els->Ins->Count - 1; ci >= 0; ci--)
   {
      El = (CElement*)Els->Ins->Items[ci];
      if(X >= El->Left && Y >= El->Top &&
         X <= El->Left + (int)El->Width &&
         Y <= El->Top + (int)El->Height)
      return El;
   }
   for(ci = Els->Outs->Count - 1; ci >= 0; ci--)
   {
      El = (CElement*)Els->Outs->Items[ci];
      if(X >= El->Left && Y >= El->Top &&
         X <= El->Left + (int)El->Width &&
         Y <= El->Top + (int)El->Height)
      return El;
   }
	return NULL;
}
//---------------------------------------------------------------------------
void __fastcall CField::Done(void)
{
   Application->OnIdle = NULL;
   if(Selector)
   {
   	Selector->Done();
      delete Selector;
      Selector = NULL;
   }
   if(Els)
   {
   	Els->Done();
      delete Els;
      Els = NULL;
   }
   if(DDRender)
   {
		DDRender->Done();
      delete DDRender;
      DDRender = NULL;
   }
}
//---------------------------------------------------------------------------
void __fastcall CField::OpenGraph(void)
{
 if(Selector->SelBuf->Items[0])
{
  if(((CElement*)Selector->SelBuf->Items[0])->ID_ELEM==ID_OUT)
  if(((COut*)Selector->SelBuf->Items[0])->Y_GRAFIK!=NULL)
   {
   Application->CreateForm(__classid(TForm_Grafic), &Form_Grafic);
   Form_Grafic->Y=((COut*)Selector->SelBuf->Items[0])->Y_GRAFIK;
   Form_Grafic->DT = Els->DT;
   Form_Grafic->T = Els->T;
   Form_Grafic->ShowModal();
   Form_Grafic->Free();
   }
 if(((CElement*)Selector->SelBuf->Items[0])->ID_ELEM==ID_STDELEMENT)
   if(((CStdElement*)Selector->SelBuf->Items[0])->Out!=NULL)
   {
   	Application->CreateForm(__classid(TForm_Grafic), &Form_Grafic);
      Form_Grafic->Y = ((CStdElement*)Selector->SelBuf->Items[0])->Out;
   	Form_Grafic->DT = Els->DT;
   	Form_Grafic->T = Els->T;
   	Form_Grafic->ShowModal();
   	Form_Grafic->Free();
   }
 if(((CElement*)Selector->SelBuf->Items[0])->ID_ELEM==ID_IN)
   if(((CIn*)Selector->SelBuf->Items[0])->Out!=NULL)
   {
   Application->CreateForm(__classid(TForm_Grafic), &Form_Grafic);
   Form_Grafic->Y= ((CIn*)Selector->SelBuf->Items[0])->Out;
   Form_Grafic->DT = Els->DT;
   Form_Grafic->T = Els->T;
   Form_Grafic->ShowModal();
   Form_Grafic->Free();
   }

 if(((CElement*)Selector->SelBuf->Items[0])->ID_ELEM==ID_SUMMATOR1)
   if(((Mod_Summator*)Selector->SelBuf->Items[0])->Out!=NULL)
   {
   Application->CreateForm(__classid(TForm_Grafic), &Form_Grafic);
   Form_Grafic->Y= ((Mod_Summator*)Selector->SelBuf->Items[0])->Out;
   Form_Grafic->DT = Els->DT;
   Form_Grafic->T = Els->T;
   Form_Grafic->ShowModal();
   Form_Grafic->Free();
   }

 /*if(Selector->SelBuf->Items[0]->ID_ELEM==Uzel)
   if(((Mod_Uzel*)Selector->SelBuf->Items[0])->InOut!=NULL)
   {
   Application->CreateForm(__classid(TForm_Grafic), &Form_Grafic);
   Form_Grafic->Y= ((Mod_Uzel*)Selector->SelBuf->Items[0])->InOut;
   Form_Grafic->Kol_Graf_Tochek=KOLICHESTVO_SHAGOV;
   Form_Grafic->ShowModal();
   Form_Grafic->Free();
   }*/
  }
}
//---------------------------------------------------------------------------
__fastcall CField::~CField(void)
{
	Done();
}
//---------------------------------------------------------------------------
