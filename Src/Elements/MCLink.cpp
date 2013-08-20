//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCLink.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CLink::CLink(void)
{
	lpDDS = NULL;
   InEl = NULL;
   OutEl = NULL;
   InversOut = false;
   InversIn = false;
   Selected = false;
   InversOutPtr = NULL;
   InversInPtr = NULL;
   SetRect(&InversOutSign, 0, 0, 0, 0);
   SetRect(&InversInSign, 0, 0, 0, 0);
   DX = 0;
   DY = 0;
   Canvas = new TCanvas;
}
//---------------------------------------------------------------------------
void __fastcall CLink::CalcLink(int DX, int DY)
{
	this->DX = DX;
	this->DY = DY;
	switch(IN_OR)
   {
      case OR_NONE:
      	LPs[0].x = InEl->Left + InEl->Width/2 + DX;
         LPs[0].y = InEl->Top + InEl->Height/2 + DY;
         LPs[1] = LPs[0];
      break;
   	case OR_LEFT:
      	LPs[0].x = InEl->Left + DX;
         LPs[0].y = InEl->Top + InEl->Height/2 + DY;
      	LPs[1].x = InEl->Left - InEl->Width*0.5 + DX;
         LPs[1].y = InEl->Top + InEl->Height/2 + DY;
         SetRect(&InversInSign, LPs[0].x - OutEl->Width*0.1,
                                LPs[0].y - OutEl->Height/4.0,
                                LPs[0].x - OutEl->Width*0.35,
                                LPs[0].y - OutEl->Height/4.0);
      break;
      case OR_TOP:
      	LPs[0].x = InEl->Left + InEl->Width/2 + DX;
         LPs[0].y = InEl->Top + DY;
         LPs[1].x = InEl->Left + InEl->Width/2 + DX;
         LPs[1].y = InEl->Top - InEl->Height*0.5 + DY;
         SetRect(&InversInSign, LPs[0].x + OutEl->Width/2,
                                LPs[0].y - OutEl->Height/4.0,
                                LPs[0].x + OutEl->Width*0.25,
                                LPs[0].y - OutEl->Height/4.0);
      break;
      case OR_RIGHT:
      	LPs[0].x = InEl->Left + InEl->Width + DX;
         LPs[0].y = InEl->Top + InEl->Height/2 + DY;
         LPs[1].x = InEl->Left + InEl->Width + InEl->Width*0.5 + DX;
         LPs[1].y = InEl->Top + InEl->Height/2 + DY;
         SetRect(&InversInSign, LPs[0].x + OutEl->Width*0.1,
                                LPs[0].y + OutEl->Height/4.0,
                                LPs[0].x + OutEl->Width*0.35,
                                LPs[0].y + OutEl->Height/4.0);
      break;
      case OR_BOTTOM:
      	LPs[0].x = InEl->Left + InEl->Width/2 + DX;
         LPs[0].y = InEl->Top + InEl->Height + DY;
         LPs[1].x = InEl->Left + InEl->Width/2 + DX;
         LPs[1].y = InEl->Top + InEl->Height + InEl->Height*0.5 + DY;
         SetRect(&InversInSign, LPs[0].x - OutEl->Width/2,
                                LPs[0].y + OutEl->Height/4.0,
                                LPs[0].x - OutEl->Width*0.25,
                                LPs[0].y + OutEl->Height/4.0);
      break;
   }
	switch(OUT_OR)
   {
      case OR_NONE:
      	LPs[2].x = OutEl->Left + OutEl->Width/2 + DX;
         LPs[2].y = OutEl->Top + OutEl->Height/2 + DY;
         LPs[3] = LPs[2];
      break;
   	case OR_LEFT:
      	LPs[2].x = OutEl->Left - OutEl->Width*0.5 + DX;
         LPs[2].y = OutEl->Top + OutEl->Height/2 + DY;
      	LPs[3].x = OutEl->Left + DX;
         LPs[3].y = OutEl->Top + OutEl->Height/2 + DY;
         SetRect(&InversOutSign, LPs[2].x + OutEl->Width*0.1,
                                 LPs[2].y - OutEl->Height/4.0,
                                 LPs[2].x + OutEl->Width*0.35,
                                 LPs[2].y - OutEl->Height/4.0);
      break;
      case OR_TOP:
         LPs[2].x = OutEl->Left + OutEl->Width/2 + DX;
         LPs[2].y = OutEl->Top - OutEl->Height*0.5 + DY;
      	LPs[3].x = OutEl->Left + OutEl->Width/2 + DX;
         LPs[3].y = OutEl->Top + DY;
         SetRect(&InversOutSign, LPs[3].x + OutEl->Width/2,
                                 LPs[3].y - OutEl->Height/4.0,
                                 LPs[3].x + OutEl->Width*0.25,
                                 LPs[3].y - OutEl->Height/4.0);
      break;
      case OR_RIGHT:
      	LPs[2].x = OutEl->Left + OutEl->Width + OutEl->Width*0.5 + DX;
         LPs[2].y = OutEl->Top + OutEl->Height/2 + DY;
         LPs[3].x = OutEl->Left + OutEl->Width + DX;
         LPs[3].y = OutEl->Top + OutEl->Height/2 + DY;
         SetRect(&InversOutSign, LPs[2].x - OutEl->Width*0.1,
                                 LPs[2].y + OutEl->Height/4.0,
                                 LPs[2].x - OutEl->Width*0.35,
                                 LPs[2].y + OutEl->Height/4.0);
      break;
      case OR_BOTTOM:
         LPs[2].x = OutEl->Left + OutEl->Width/2 + DX;
         LPs[2].y = OutEl->Top + OutEl->Height + OutEl->Height*0.5 + DY;
      	LPs[3].x = OutEl->Left + OutEl->Width/2 + DX;
         LPs[3].y = OutEl->Top + OutEl->Height + DY;
         SetRect(&InversOutSign, LPs[3].x - OutEl->Width/2,
                                 LPs[3].y + OutEl->Height/4.0,
                                 LPs[3].x - OutEl->Width*0.25,
                                 LPs[3].y + OutEl->Height/4.0);
      break;
   }
}
//---------------------------------------------------------------------------
void __fastcall CLink::CalcSmartLink(int DX, int DY)
{
	this->DX = DX;
	this->DY = DY;
	switch(IN_OR)
   {
      case OR_NONE:
      	LPs[0].x = InEl->Left + InEl->Width/2;
         LPs[0].y = InEl->Top + InEl->Height/2;
         LPs[2] = LPs[1] = LPs[0];
      break;
      case OR_LEFT:
      	LPs[0].x = InEl->Left;
         LPs[0].y = InEl->Top + InEl->Height/2;
         LPs[1].x = LPs[0].x - InEl->Width*0.5;
         LPs[1].y = LPs[0].y;
         LPs[2].y = LPs[0].y;
         SetRect(&InversInSign, LPs[0].x - OutEl->Width*0.1,
                                LPs[0].y - OutEl->Height/4.0,
                                LPs[0].x - OutEl->Width*0.35,
                                LPs[0].y - OutEl->Height/4.0);
         switch(OUT_OR)
         {
         	case OR_TOP:
            case OR_BOTTOM:
               LPs[2].x = OutEl->Left + OutEl->Width/2;
            break;
            default:
         		LPs[2].x = (LPs[0].x + OutEl->Left + OutEl->Width)/2;
         }
         if(LPs[2].x > LPs[1].x) LPs[2].x = LPs[1].x;
      break;
      case OR_TOP:
      	LPs[0].x = InEl->Left + InEl->Width/2;
         LPs[0].y = InEl->Top;
         LPs[1].x = LPs[0].x;
         LPs[1].y = LPs[0].y - InEl->Height*0.5;
         LPs[2].x = LPs[0].x;
         SetRect(&InversInSign, LPs[0].x + OutEl->Width/2,
                                LPs[0].y - OutEl->Height/4.0,
                                LPs[0].x + OutEl->Width*0.25,
                                LPs[0].y - OutEl->Height/4.0);
         switch(OUT_OR)
         {
         	case OR_LEFT:
            case OR_RIGHT:
               LPs[2].y = OutEl->Top + OutEl->Height/2;
            break;
            default:
         		LPs[2].y = (LPs[0].y + OutEl->Top + OutEl->Height)/2;
         }
         if(LPs[2].y > LPs[1].y) LPs[2].y = LPs[1].y;
      break;
   	case OR_RIGHT:
      	LPs[0].x = InEl->Left + InEl->Width;
         LPs[0].y = InEl->Top + InEl->Height/2;
         LPs[1].x = LPs[0].x + InEl->Width*0.5;
         LPs[1].y = LPs[0].y;
         LPs[2].y = LPs[0].y;
         SetRect(&InversInSign, LPs[0].x + OutEl->Width*0.1,
                                LPs[0].y + OutEl->Height/4.0,
                                LPs[0].x + OutEl->Width*0.35,
                                LPs[0].y + OutEl->Height/4.0);
         switch(OUT_OR)
         {
         	case OR_TOP:
            case OR_BOTTOM:
               LPs[2].x = OutEl->Left + OutEl->Width/2;
            break;
            default:
         		LPs[2].x = (LPs[0].x + OutEl->Left)/2;
         }
         if(LPs[2].x < LPs[1].x) LPs[2].x = LPs[1].x;
      break;
      case OR_BOTTOM:
      	LPs[0].x = InEl->Left + InEl->Width/2;
         LPs[0].y = InEl->Top + InEl->Height;
         LPs[1].x = LPs[0].x;
         LPs[1].y = LPs[0].y + InEl->Height*0.5;
         LPs[2].x = LPs[0].x;
         SetRect(&InversInSign, LPs[0].x - OutEl->Width/2,
                                LPs[0].y + OutEl->Height/4.0,
                                LPs[0].x - OutEl->Width*0.25,
                                LPs[0].y + OutEl->Height/4.0);
         switch(OUT_OR)
         {
         	case OR_LEFT:
            case OR_RIGHT:
               LPs[2].y = OutEl->Top + OutEl->Height/2;
            break;
            default:
         		LPs[2].y = (LPs[0].y + OutEl->Top)/2;
         }
         if(LPs[2].y < LPs[1].y) LPs[2].y = LPs[1].y;
      break;
   }
   switch(OUT_OR)
   {
      case OR_NONE:
      	LPs[3].x = OutEl->Left + OutEl->Width/2;
         LPs[3].y = OutEl->Top + OutEl->Height/2;
         LPs[5] = LPs[4] = LPs[3];
      break;
   	case OR_LEFT:
         LPs[3].x = (InEl->Left + InEl->Width + OutEl->Left)/2;
         LPs[3].y = OutEl->Top + OutEl->Height/2;
         LPs[4].x = OutEl->Left - OutEl->Width*0.5;
         LPs[4].y = LPs[3].y;
         LPs[5].x = OutEl->Left;
         LPs[5].y = LPs[3].y;
         SetRect(&InversOutSign, LPs[4].x + OutEl->Width*0.1,
                                 LPs[4].y - OutEl->Height/4.0,
                                 LPs[4].x + OutEl->Width*0.35,
                                 LPs[4].y - OutEl->Height/4.0);
         switch(IN_OR)
         {
         	case OR_TOP:
            case OR_BOTTOM:
               LPs[3] = LPs[2];
         		if(LPs[3].x > LPs[4].x)
               {
               	LPs[3].x = LPs[4].x;
                  LPs[2] = LPs[3];
               }
            break;
            default:
         		if(LPs[3].x > LPs[4].x) LPs[3].x = LPs[4].x;
         }
      break;
      case OR_TOP:
      	LPs[3].x = OutEl->Left + OutEl->Width/2;
         LPs[3].y = (InEl->Top + InEl->Height + OutEl->Top)/2;
         LPs[4].x = LPs[3].x;
         LPs[4].y = OutEl->Top - OutEl->Height*0.5;
         LPs[5].x = LPs[3].x;
         LPs[5].y = OutEl->Top;
         SetRect(&InversOutSign, LPs[5].x + OutEl->Width/2,
                                 LPs[5].y - OutEl->Height/4.0,
                                 LPs[5].x + OutEl->Width*0.25,
                                 LPs[5].y - OutEl->Height/4.0);
         switch(IN_OR)
         {
         	case OR_LEFT:
            case OR_RIGHT:
               LPs[3] = LPs[2];
         		if(LPs[3].y > LPs[4].y)
               {
               	LPs[3].y = LPs[4].y;
                  LPs[2] = LPs[3];
               }
            break;
            default:
         		if(LPs[3].y > LPs[4].y) LPs[3].y = LPs[4].y;
         }
      break;
      case OR_RIGHT:
         LPs[3].x = (InEl->Left + OutEl->Left + OutEl->Width)/2;
         LPs[3].y = OutEl->Top + OutEl->Height/2;
         LPs[4].x = OutEl->Left + OutEl->Width + OutEl->Width*0.5;
         LPs[4].y = LPs[3].y;
         LPs[5].x = OutEl->Left + OutEl->Width;
         LPs[5].y = LPs[3].y;
         SetRect(&InversOutSign, LPs[4].x - OutEl->Width*0.1,
                                 LPs[4].y + OutEl->Height/4.0,
                              	LPs[4].x - OutEl->Width*0.35,
                              	LPs[4].y + OutEl->Height/4.0);
         switch(IN_OR)
         {
         	case OR_TOP:
            case OR_BOTTOM:
               LPs[3] = LPs[2];
         		if(LPs[3].x < LPs[4].x)
               {
               	LPs[3].x = LPs[4].x;
                  LPs[2] = LPs[3];
               }
            break;
            default:
          		if(LPs[3].x < LPs[4].x) LPs[3].x = LPs[4].x;
         }
      break;
      case OR_BOTTOM:
      	LPs[3].x = OutEl->Left + OutEl->Width/2;
         LPs[3].y = (InEl->Top + OutEl->Top + OutEl->Height)/2;
         LPs[4].x = LPs[3].x;
         LPs[4].y = OutEl->Top + OutEl->Height + OutEl->Height*0.5;
         LPs[5].x = LPs[3].x;
         LPs[5].y = OutEl->Top + OutEl->Height;
         SetRect(&InversOutSign, LPs[5].x - OutEl->Width/2,
                              	LPs[5].y + OutEl->Height/4.0,
                              	LPs[5].x - OutEl->Width*0.25,
                              	LPs[5].y + OutEl->Height/4.0);
         switch(IN_OR)
         {
         	case OR_LEFT:
            case OR_RIGHT:
               LPs[3] = LPs[2];
         		if(LPs[3].y < LPs[4].y)
               {
               	LPs[3].y = LPs[4].y;
                  LPs[2] = LPs[3];
               }
            break;
            default:
         		if(LPs[3].y < LPs[4].y) LPs[3].y = LPs[4].y;
         }
      break;
   }
   LPs[0].x += DX;
   LPs[0].y += DY;
   LPs[1].x += DX;
   LPs[1].y += DY;
   LPs[2].x += DX;
   LPs[2].y += DY;
   LPs[3].x += DX;
   LPs[3].y += DY;
   LPs[4].x += DX;
   LPs[4].y += DY;
   LPs[5].x += DX;
   LPs[5].y += DY;
   InversOutSign.left += DX;
   InversOutSign.top += DY;
   InversOutSign.right += DX;
   InversOutSign.bottom += DY;
}
//---------------------------------------------------------------------------
void __fastcall CLink::CalcArrowEnd(int DX, int DY, BOOL Smart)
{
   switch(OUT_OR)
   {
      case OR_NONE:
      	if(Smart)
	         switch(IN_OR)
            {
	         	case OR_NONE:
	            	APs[2] = APs[1] = APs[0] = LPs[2];
	            break;
	            case OR_LEFT:
	            	APs[0].x = LPs[2].x + InEl->Width*0.2;
	               APs[0].y = InEl->Top + InEl->Height/2 - InEl->Height*0.1;
	               APs[1].x = LPs[2].x;
	               APs[1].y = InEl->Top + InEl->Height/2;
	               APs[2].x = LPs[2].x + InEl->Width*0.2;
	               APs[2].y = InEl->Top + InEl->Height/2 + InEl->Height*0.1;
	            break;
	            case OR_TOP:
	            	APs[0].x = InEl->Left + InEl->Width/2 - InEl->Width*0.1;
	               APs[0].y = LPs[2].y + InEl->Height*0.2;
	               APs[1].x = InEl->Left + InEl->Width/2;
	               APs[1].y = LPs[2].y;
	               APs[2].x = InEl->Left + InEl->Width/2 + InEl->Width*0.1;
	               APs[2].y = APs[0].y;
	            break;
	            case OR_RIGHT:
	            	APs[0].x = LPs[2].x - InEl->Width*0.2;
	               APs[0].y = InEl->Top + InEl->Height/2 - InEl->Height*0.1;
	               APs[1].x = LPs[2].x;
	               APs[1].y = InEl->Top + InEl->Height/2;
	               APs[2].x = LPs[2].x - InEl->Width*0.2;
	               APs[2].y = InEl->Top + InEl->Height/2 + InEl->Height*0.1;
	           	break;
	           	case OR_BOTTOM:
	              	APs[0].x = InEl->Left + InEl->Width/2 - InEl->Width*0.1;
	              	APs[0].y = LPs[2].y - InEl->Height*0.2;
	              	APs[1].x = InEl->Left + InEl->Width/2;
	              	APs[1].y = LPs[2].y;
	              	APs[2].x = InEl->Left + InEl->Width/2 + InEl->Width*0.1;
	              	APs[2].y = APs[0].y;
	           	break;
	        	}
         else
         {
            APs[0].x = InEl->Left + InEl->Width/2;
            APs[0].y = InEl->Top + InEl->Height/2;
         	APs[2] = APs[1] = APs[0];
         }
      break;
   	case OR_LEFT:
      	APs[0].x = OutEl->Left - OutEl->Width*0.2;
         APs[0].y = OutEl->Top + OutEl->Height/2 - OutEl->Height*0.1;
         APs[1].x = OutEl->Left;
         APs[1].y = OutEl->Top + OutEl->Height/2;
         APs[2].x = APs[0].x;
         APs[2].y = OutEl->Top + OutEl->Height/2 + OutEl->Height*0.1;
      break;
      case OR_TOP:
      	APs[0].x = OutEl->Left + OutEl->Width/2 - OutEl->Width*0.1;
         APs[0].y = OutEl->Top - OutEl->Height*0.2;
         APs[1].x = OutEl->Left + OutEl->Width/2;
         APs[1].y = OutEl->Top;
         APs[2].x = OutEl->Left + OutEl->Width/2 + OutEl->Width*0.1;
         APs[2].y = APs[0].y;
      break;
      case OR_RIGHT:
      	APs[0].x = OutEl->Left + OutEl->Width + OutEl->Width*0.2;
         APs[0].y = OutEl->Top + OutEl->Height/2 - OutEl->Height*0.1;
         APs[1].x = OutEl->Left + OutEl->Width;
         APs[1].y = OutEl->Top + OutEl->Height/2;
         APs[2].x = APs[0].x;
         APs[2].y = OutEl->Top + OutEl->Height/2 + OutEl->Height*0.1;
      break;
      case OR_BOTTOM:
      	APs[0].x = OutEl->Left + OutEl->Width/2 - OutEl->Width*0.1;
         APs[0].y = OutEl->Top + OutEl->Height + OutEl->Height*0.2;
         APs[1].x = OutEl->Left + OutEl->Width/2;
         APs[1].y = OutEl->Top + OutEl->Height;
         APs[2].x = OutEl->Left + OutEl->Width/2 + OutEl->Width*0.1;
         APs[2].y = APs[0].y;
      break;
   }
   APs[0].x += DX;
   APs[0].y += DY;
   APs[1].x += DX;
   APs[1].y += DY;
   APs[2].x += DX;
   APs[2].y += DY;
}
//---------------------------------------------------------------------------
void __fastcall CLink::Draw(int DX, int DY, BOOL Smart, HDC DrawDC)
{
   if(InEl && OutEl)
   {
   	Canvas->Handle = DrawDC;
      Canvas->Pen->Color = clBlack;
      int NumPoints;
      if(Smart)
      {
         NumPoints = 5;
      	CalcSmartLink(DX, DY);
         CalcArrowEnd(DX, DY, TRUE);
      }
      else
      {
      	NumPoints = 3;
      	CalcLink(DX, DY);
         CalcArrowEnd(DX, DY, FALSE);
      }
      if(Selected)
      {
         Canvas->Pen->Width = 2;
      	Canvas->Pen->Color = clRed;
      }
      else
      {
         Canvas->Pen->Width = 1;
      	Canvas->Pen->Color = clBlack;
      }
      Canvas->Polyline(LPs, NumPoints);
      Canvas->MoveTo(APs[0].x, APs[0].y);
      Canvas->LineTo(APs[1].x, APs[1].y);
      Canvas->MoveTo(APs[2].x, APs[2].y);
      Canvas->LineTo(APs[1].x, APs[1].y);
      if(InversOut)
      {
      	Canvas->MoveTo(InversOutSign.left, InversOutSign.top);
      	Canvas->LineTo(InversOutSign.right, InversOutSign.bottom);
      }
      if(InversIn)
      {
      	Canvas->MoveTo(InversInSign.left, InversInSign.top);
      	Canvas->LineTo(InversInSign.right, InversInSign.bottom);
      }
   }
}
//---------------------------------------------------------------------------
CLink::~CLink(void)
{
   if(InversOutPtr) *InversOutPtr = false;
   if(InversInPtr) *InversInPtr = false;
   if(InEl) InEl->DelLink(this);
   if(OutEl) OutEl->DelLink(this);
}
//---------------------------------------------------------------------------
