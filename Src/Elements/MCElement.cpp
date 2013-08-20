//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCElement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void __fastcall CElement::InitSurface(LPDIRECTDRAW lpDDraw)
{
   if(lpDDS)
   {
   	lpDDS->Release();
      lpDDS = NULL;
   }
   DDSURFACEDESC DDSDesc;
   ZeroMemory(&DDSDesc, sizeof(DDSURFACEDESC));
   DDSDesc.dwSize = sizeof(DDSURFACEDESC);
   DDSDesc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
   DDSDesc.dwWidth = Width;
   DDSDesc.dwHeight = Height;
   DDSDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY;
   HRESULT DDResult;
   DDResult = lpDDraw->CreateSurface(&DDSDesc, &lpDDS, NULL);
   if(FAILED(DDResult))
   {
   	DDSDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN |
                               DDSCAPS_SYSTEMMEMORY;
      DDResult = lpDDraw->CreateSurface(&DDSDesc, &lpDDS, NULL);
   }
}
//---------------------------------------------------------------------------
DWORD __fastcall CElement::DDColorMatch(LPDIRECTDRAWSURFACE lpDDSA,
                                        COLORREF rgb)
{
	COLORREF rgbT;
   HDC hdc;
   DWORD dw = CLR_INVALID;
   DDSURFACEDESC ddsd;
   HRESULT hres;
   if (rgb != CLR_INVALID && lpDDSA->GetDC(&hdc) == DD_OK)
   {
    	rgbT = GetPixel(hdc, 0, 0);
		SetPixel(hdc, 0, 0, rgb);
		lpDDSA->ReleaseDC(hdc);
   }
   ddsd.dwSize = sizeof(ddsd);
   while((hres = lpDDSA->Lock(NULL, &ddsd, 0, NULL)) == DDERR_WASSTILLDRAWING);
   if(hres == DD_OK)
   {
		dw  = *(DWORD *)ddsd.lpSurface;
      if(ddsd.ddpfPixelFormat.dwRGBBitCount < 32)
      	dw &= (1 << ddsd.ddpfPixelFormat.dwRGBBitCount)-1;
		lpDDSA->Unlock(NULL);
   }
   if(rgb != CLR_INVALID && lpDDSA->GetDC(&hdc) == DD_OK)
   {
		SetPixel(hdc, 0, 0, rgbT);
		lpDDSA->ReleaseDC(hdc);
   }
   return dw;
}
//---------------------------------------------------------------------------
void __fastcall CElement::SetImage(LPSTR ResName)
{
   HBITMAP hbm;
   BITMAP bm;
   HDC hdcImage;
   HDC hdc;
   DWORD CK;
   hbm = (HBITMAP)LoadImage(GetModuleHandle(NULL), ResName, IMAGE_BITMAP,
                            Width, Height, LR_CREATEDIBSECTION);
   GetObject(hbm, sizeof(bm), &bm);
   lpDDS->Restore();
   hdcImage = CreateCompatibleDC(NULL);
   SelectObject(hdcImage, hbm);
   CK = DDColorMatch(lpDDS, GetPixel(hdcImage, 0, 0));
   if(lpDDS->GetDC(&hdc) == DD_OK)
   {
		StretchBlt(hdc, 0, 0, Width, Height, hdcImage, 0, 0, Width, Height, SRCCOPY);
		lpDDS->ReleaseDC(hdc);
   }
   DeleteDC(hdcImage);
   DeleteObject(hbm);
   DDCOLORKEY DDCK;
	DDCK.dwColorSpaceLowValue = CK;
	DDCK.dwColorSpaceHighValue = CK;
	lpDDS->SetColorKey(DDCKEY_SRCBLT, &DDCK);
}
//---------------------------------------------------------------------------
void __fastcall CElement::PMPropClick(TObject *Sender)
{
	SetData();
}
//---------------------------------------------------------------------------
void __fastcall CElement::PMGrpClick(TObject *Sender)
{
	ShowGrp();
}
//---------------------------------------------------------------------------
CElement::CElement(void)
{
	Top = 0;
   Left = 0;
   Width = 0;
   Height = 0;
   EndIndex = 0;
   DT = 0.0;
   T = 0.0;
	ID_ELEM = ID_NONE;
   ElName = "Element";
   GrpName = "Процесс моделирования:";
   AxXName = "t";
   AxYName = "h(t)";
   ResName = "";
   PMEl = NULL;
   lpDDS = NULL;
   FGrp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CElement::Create(LPDIRECTDRAW lpDDraw,
                                 LPSTR ResName,
                                 int _Left, int _Top,
                                 DWORD _Width, DWORD _Height,
                                 int SX, int SY)
{
   this->ResName = ResName;
   ScrPosX = DragLeft = Left = _Left;
   ScrPosY = DragTop = Top = _Top;
   ScrPosX += SX;
   ScrPosY += SY;
   Width = _Width;
   Height = _Height;
	InitSurface(lpDDraw);
   SetImage(ResName);
   PMEl = new TPopupMenu(NULL);
   PMEl->AutoPopup = false;
   TMenuItem *MIProp = new TMenuItem(NULL);
   MIProp->Caption = "Свойства...";
   MIProp->Default = true;
   MIProp->OnClick = PMPropClick;
   PMEl->Items->Add(MIProp);
   MIProp = new TMenuItem(NULL);
   MIProp->Caption = "График...";
   MIProp->OnClick = PMGrpClick;
   PMEl->Items->Add(MIProp);
   FGrp = new TFGrp(Application);
}
//---------------------------------------------------------------------------
void __fastcall CElement::Restore(void)
{
   SetImage(ResName);
}
//---------------------------------------------------------------------------
void __fastcall CElement::ShowPopupMenu(int X, int Y)
{
   PMEl->Items->Items[1]->Enabled = CheckOut();
	PMEl->Popup(X, Y);
}
//---------------------------------------------------------------------------
void CElement::VICHISLENIE(int index, int end, long double DT)
{
	EndIndex = end;
   this->DT = DT;
   T = EndIndex*this->DT;
}
//---------------------------------------------------------------------------
void __fastcall CElement::AddValue(void *&Data, DWORD &DataSize,
                                   void *Value, int ValSize)
{
   DataSize += ValSize;
   Data = (byte*)realloc(Data, DataSize);
   memcpy((void*)((DWORD)Data + DataSize - ValSize), Value, ValSize);
}
//---------------------------------------------------------------------------
void __fastcall CElement::GetValue(void *&Data, DWORD &DataSize,
                                   void *Value, int ValSize)
{
   memcpy(Value, (void*)((DWORD)Data + DataSize), ValSize);
   DataSize += ValSize;
}
//---------------------------------------------------------------------------
void __fastcall CElement::GetDump(void *&Dump, DWORD &DumpSize)
{
   int ID = (int)ID_ELEM;
   AddValue(Dump, DumpSize, &Left, sizeof(int));
   AddValue(Dump, DumpSize, &Top, sizeof(int));
   AddValue(Dump, DumpSize, &ScrPosX, sizeof(int));
   AddValue(Dump, DumpSize, &ScrPosY, sizeof(int));
   AddValue(Dump, DumpSize, &DragLeft, sizeof(int));
   AddValue(Dump, DumpSize, &DragTop, sizeof(int));
   AddValue(Dump, DumpSize, &Width, sizeof(DWORD));
   AddValue(Dump, DumpSize, &Height, sizeof(DWORD));
   AddValue(Dump, DumpSize, &ID, sizeof(int));

}
//---------------------------------------------------------------------------
void __fastcall CElement::SetDump(void *&Dump, DWORD &DumpSize)
{
   GetValue(Dump, DumpSize, &Left, sizeof(int));
   GetValue(Dump, DumpSize, &Top, sizeof(int));
   GetValue(Dump, DumpSize, &ScrPosX, sizeof(int));
   GetValue(Dump, DumpSize, &ScrPosY, sizeof(int));
   GetValue(Dump, DumpSize, &DragLeft, sizeof(int));
   GetValue(Dump, DumpSize, &DragTop, sizeof(int));
   GetValue(Dump, DumpSize, &Width, sizeof(DWORD));
   GetValue(Dump, DumpSize, &Height, sizeof(DWORD));
   int ID = 0;
   GetValue(Dump, DumpSize, &ID, sizeof(int));
   ID_ELEM = (T_ID)ID;
}
//---------------------------------------------------------------------------
CElement::~CElement(void)
{
	ID_ELEM=ID_NONE;
   if(FGrp){FGrp->Free(); FGrp = NULL;}
	if(lpDDS)
   {
   	lpDDS->Release();
      lpDDS = NULL;
   }
}
//---------------------------------------------------------------------------
