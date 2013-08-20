//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCDDRender.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void CDDRender::FillGrid(HDC hdc)
{
	Canvas->Handle = hdc;
   Canvas->Brush->Color = (TColor)FieldColor;
   Canvas->FillRect(Rect(0, 0, Width, Height));
   for(DWORD cj = 0; cj <= Height; cj += GridStep)
     	for(DWORD ci = 0; ci <= Width; ci += GridStep)
         Canvas->Pixels[ci][cj] = (TColor)GridColor;
}
//---------------------------------------------------------------------------
CDDRender::CDDRender(void)
{
   ScrX = 0;
   ScrY = 0;
   GridStep = 8;
	lpDDraw = NULL;
	lpDDSPrim = NULL;
   lpDDSBack = NULL;
   lpDDSGrid = NULL;
   lpDDClip = NULL;
   FieldColor = COLOR_BTNFACE;
   GridColor = 0x00000000;
   Canvas = new TCanvas;
}
//---------------------------------------------------------------------------
void __fastcall CDDRender::Init(TForm *_FMain)
{
	CRender::Init(_FMain);
   if(!DDCreate())
   {
   	Application->MessageBox(DDErrToStr(DDResult),
                              "Direct Draw Error",
                              MB_OK | MB_ICONERROR);
      Application->Terminate();
   }
   if(!SetCoopLevel())
   {
   	Application->MessageBox(DDErrToStr(DDResult),
                              "Direct Draw Error",
                              MB_OK | MB_ICONERROR);
      Application->Terminate();
   }
   if(!CreateFlipper())
   {
   	Application->MessageBox(DDErrToStr(DDResult),
                              "Direct Draw Error",
                              MB_OK | MB_ICONERROR);
      Application->Terminate();
   }
   Width = Parent->ClientWidth;
   Height = Parent->ClientHeight;
}
//---------------------------------------------------------------------------
BOOL CDDRender::DDCreate(void)
{
   DDResult = DirectDrawCreate(NULL, &lpDDraw, NULL);
   if(FAILED(DDResult)) return FALSE;
	return TRUE;
}
//---------------------------------------------------------------------------
BOOL CDDRender::SetCoopLevel(void)
{
   if(Parent && lpDDraw)
   {
		DDResult = lpDDraw->SetCooperativeLevel(Parent->Handle,
                                              DDSCL_NORMAL);
   	if(FAILED(DDResult)) return FALSE;
   }
   else return FALSE;
	return TRUE;
}
//---------------------------------------------------------------------------
BOOL CDDRender::CreateGrid(void)
{
   if(lpDDSGrid)
   {
   	lpDDSGrid->Release();
      lpDDSGrid = NULL;
   }
   DDSURFACEDESC DDSDesc;
   ZeroMemory(&DDSDesc, sizeof(DDSURFACEDESC));
   DDSDesc.dwSize = sizeof(DDSURFACEDESC);
   DDSDesc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
   DDSDesc.dwWidth = Width;
   DDSDesc.dwHeight = Height;
   if(GetDeviceCaps(GetDC(0), BITSPIXEL) < 16)
   	DDSDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN |
                               DDSCAPS_SYSTEMMEMORY;
   else
   	DDSDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN |
                            	 DDSCAPS_VIDEOMEMORY;
   DDResult = lpDDraw->CreateSurface(&DDSDesc, &lpDDSGrid, NULL);
   if(FAILED(DDResult))
   {
   	DDSDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN |
                               DDSCAPS_SYSTEMMEMORY;
      DDResult = lpDDraw->CreateSurface(&DDSDesc, &lpDDSGrid, NULL);
   	if(FAILED(DDResult)) return FALSE;
   }
   HDC hdc;
   DDResult = lpDDSGrid->GetDC(&hdc);
   if(FAILED(DDResult)) return FALSE;
   FillGrid(hdc);
   DDResult = lpDDSGrid->ReleaseDC(hdc);
   if(FAILED(DDResult)) return FALSE;
   return TRUE;
}
//---------------------------------------------------------------------------
BOOL CDDRender::CreateFlipper(void)
{
	DDSURFACEDESC DDSDesc;
   ZeroMemory(&DDSDesc, sizeof(DDSURFACEDESC));
   DDSDesc.dwSize = sizeof(DDSURFACEDESC);
   DDSDesc.dwFlags = DDSD_CAPS;
   DDSDesc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                            DDSCAPS_VIDEOMEMORY;
   DDResult = lpDDraw->CreateSurface(&DDSDesc, &lpDDSPrim, NULL);
   if(FAILED(DDResult))
   {
   	DDSDesc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                               DDSCAPS_SYSTEMMEMORY;
   	DDResult = lpDDraw->CreateSurface(&DDSDesc, &lpDDSPrim, NULL);
   	if(FAILED(DDResult)) return FALSE;
   }
   DDResult = lpDDraw->CreateClipper(0, &lpDDClip, NULL);
   if(FAILED(DDResult)) return FALSE;
   DDResult = lpDDClip->SetHWnd(0, Parent->Handle);
   if(FAILED(DDResult)) return FALSE;
   DDResult = lpDDSPrim->SetClipper(lpDDClip);
   if(FAILED(DDResult)) return FALSE;
   if(!SetMetrix(Parent->ClientWidth, Parent->ClientHeight))
   	return FALSE;
	return TRUE;
}
//---------------------------------------------------------------------------
BOOL __fastcall CDDRender::SetMetrix(DWORD _Width, DWORD _Height)
{
	CRender::SetMetrix(_Width, _Height);
   if(lpDDSBack)
   {
   	lpDDSBack->Release();
      lpDDSBack = NULL;
   }
   DDSURFACEDESC DDSDesc;
   ZeroMemory(&DDSDesc, sizeof(DDSURFACEDESC));
   DDSDesc.dwSize = sizeof(DDSURFACEDESC);
   DDSDesc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
   DDSDesc.dwWidth = Width;
   DDSDesc.dwHeight = Height;
   if(GetDeviceCaps(GetDC(0), BITSPIXEL) < 16)
   	DDSDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN |
                               DDSCAPS_SYSTEMMEMORY;
   else
   	DDSDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN |
                               DDSCAPS_VIDEOMEMORY;
   DDResult = lpDDraw->CreateSurface(&DDSDesc, &lpDDSBack, NULL);
   if(FAILED(DDResult))
   {
   	DDSDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN |
                               DDSCAPS_SYSTEMMEMORY;
      DDResult = lpDDraw->CreateSurface(&DDSDesc, &lpDDSBack, NULL);
   	if(FAILED(DDResult)) return FALSE;
   }
   if(!CreateGrid()) return FALSE;
   return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall CDDRender::SetColor(DWORD _FieldColor, DWORD _GridColor)
{
	CRender::SetColor(_FieldColor, _GridColor);
   if(GetDeviceCaps(GetDC(0), BITSPIXEL) < 16)
   {
      FieldColor = (DWORD)clBtnFace;
      GridColor = 0;
   }
   else
   {
   	if(FieldColor && FieldColor <= 20)
   		FieldColor = GetSysColor(FieldColor);
   	if(GridColor && GridColor <= 20)
   		GridColor = GetSysColor(GridColor);
   }
   CreateGrid();
}
//---------------------------------------------------------------------------
BOOL __fastcall CDDRender::DrawGrid(void)
{
   try
   {
   if(lpDDSGrid && lpDDSBack)
   {
      if(lpDDSBack->IsLost()) lpDDSBack->Restore();
      if(lpDDSGrid->IsLost())
      {
      	lpDDSGrid->Restore();
         HDC hdc;
   		DDResult = lpDDSGrid->GetDC(&hdc);
   		if(FAILED(DDResult)) return false;
   		FillGrid(hdc);
   		DDResult = lpDDSGrid->ReleaseDC(hdc);
   		if(FAILED(DDResult)) return false;
      }
   	Windows::TRect SRect = Rect(0, 0, Width, Height);
		DDResult = lpDDSBack->Blt(&SRect, lpDDSGrid, &SRect,
                                DDBLT_WAIT,
                                NULL);
      if(FAILED(DDResult)) return FALSE;
   }
   else return FALSE;
   }
   catch(...)
   {
   	Application->MessageBoxA("Глюк какой-то", "@@", MB_OK);
   }
	return TRUE;
}
//---------------------------------------------------------------------------
BOOL __fastcall CDDRender::CopyBuf(LPDIRECTDRAWSURFACE lpDDS,
                                   TRestore Restore,
                                   int &X, int &Y,
                                   DWORD SWidth, DWORD SHeight)
{
  	Windows::TRect DestRect, SrcRect;
   if(X + (int)SWidth > (int)Width) X = Width - SWidth;
   if(X < 0) X = 0;
   if(Y + (int)SHeight > (int)Height) Y = Height - SHeight;
   if(Y < 0) Y = 0;
   DestRect = Rect(X, Y, X+SWidth, Y+SHeight);
   SrcRect = Rect(0, 0, SWidth, SHeight);
   if(lpDDSBack->IsLost()) lpDDSBack->Restore();
   if(lpDDS->IsLost())
   {
   	lpDDS->Restore();
      Restore();
   }
   DDResult = lpDDSBack->Blt(&DestRect, lpDDS, &SrcRect,
                             DDBLT_WAIT | DDBLT_KEYSRC,
                             NULL);
   if(FAILED(DDResult)) return FALSE;
	return TRUE;
}
//---------------------------------------------------------------------------
BOOL __fastcall CDDRender::Flip(void)
{
   if(lpDDSPrim && lpDDSBack)
   {
   	int dx = Parent->ClientOrigin.x;
   	int dy = Parent->ClientOrigin.y;
      int DW, DH;
      if(Width > (DWORD)Parent->ClientWidth)
      	DW = Parent->ClientWidth;
      else
      	DW = Width;
      if(Height > (DWORD)Parent->ClientHeight)
      	DH = Parent->ClientHeight;
      else
      	DH = Height;
   	Windows::TRect DestRect = Rect(dx, dy,
                                     dx + DW,
                                     dy + DH);
   	Windows::TRect SrcRect = Rect(ScrX, ScrY,
                                    DW + ScrX, DH + ScrY);
   	if(lpDDSPrim->IsLost()) lpDDSPrim->Restore();
   	if(lpDDSBack->IsLost()) lpDDSBack->Restore();
		DDResult = lpDDSPrim->Blt(&DestRect,
                                lpDDSBack,
                                &SrcRect,
                                DDBLT_WAIT,
                                NULL);
      if(FAILED(DDResult)) return FALSE;
   }
   else return FALSE;
	return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall CDDRender::Done(void)
{
	if(lpDDraw)
   {
      if(lpDDClip)
      {
      	lpDDClip->Release();
         lpDDClip = NULL;
      }
      if(lpDDSBack)
      {
      	lpDDSBack->Release();
         lpDDSBack = NULL;
      }
      if(lpDDSPrim)
      {
      	lpDDSPrim->Release();
         lpDDSPrim = NULL;
      }
   	lpDDraw->Release();
      lpDDraw = NULL;
   }
}
//---------------------------------------------------------------------------
