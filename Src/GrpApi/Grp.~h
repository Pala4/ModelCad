//---------------------------------------------------------------------------
#ifndef GrpH
#define GrpH

#include <math.h>
#include <clipbrd.hpp>

#include "..\Error\ErrMain.h"
#include "..\MainDef.h"
#include "..\MCClipBoard.h"
#include "PropFrm.h"
//---------------------------------------------------------------------------
struct TGrpPset
{
   LD X;
   LD Y;
   DWORD Color;
   AnsiString Caption;
	Graphics::TBitmap *BMPset;
	Graphics::TBitmap *BMCaption;
};
//---------------------------------------------------------------------------
enum TRendStyle
{
	rsLogic,
   rsPhiz
};
//---------------------------------------------------------------------------
class CSer : public TList
{
public:
   bool Selected;
	AnsiString DefName;
   AnsiString Name;
	DWORD Color;
	inline __fastcall CSer(void)
   {
   	Selected = false;
		DefName = "";
   	Name = "";
   }
   void __fastcall AddPset(LD X, LD Y, DWORD Color = 0x000000,
                           AnsiString Caption = "",
                           AnsiString BMPsetResName = "",
                           AnsiString BMCaptionResName = "",
                           THandle HI = (THandle)HInstance);
   LD __fastcall GetMinX(void);
   LD __fastcall GetMinY(void);
   LD __fastcall GetMaxX(void);
   LD __fastcall GetMaxY(void);
   void __fastcall Clr(void);
   __fastcall virtual ~CSer(void);
};
//---------------------------------------------------------------------------
class CSerManager : public TList
{
private:
	void __fastcall AddValue(void *&Data, DWORD &DataSize,
                            void *Value, int ValSize);
	void __fastcall GetValue(void *&Data, DWORD &DataSize,
                            void *Value, int ValSize);
	bool CheckSer(CSer *Ser);
public:
	inline __fastcall CSerManager(void){}
   bool __fastcall AddSer(CSer *Ser, AnsiString SerName = "");
   void __fastcall DelPrevSers(long int NumNotDel);
   void __fastcall SetSersName(void);
   AnsiString __fastcall GetTextData(TList *Sers);
   AnsiString __fastcall GetTextData(void);
   bool __fastcall SetTextData(AnsiString TextData);
   void __fastcall DelSers(TList *Sers);
   void __fastcall DelAllSers(void);
   void __fastcall SelectAllSers(void);
   TRectLD GetGrpReg(void);
	TPointLD GetOffsetLogicCenter(void);
   TPointLD GetLogicCenter(void);
	void __fastcall GetDump(void *&Dump, DWORD &DumpSize);
	void __fastcall SetDump(void *&Dump, DWORD &DumpSize);
   __fastcall virtual ~CSerManager(void);
};
//---------------------------------------------------------------------------
enum TTextRend
{
	trLeftTop = TA_RIGHT | TA_BOTTOM,   trCenterTop = TA_CENTER | TA_BOTTOM,   trRightTop = TA_LEFT | TA_BOTTOM,
   trLeftMed = TA_RIGHT | TA_BASELINE, trCenterMed = TA_CENTER | TA_BASELINE, trRightMed = TA_LEFT | TA_BASELINE,
   trLeftBottom = TA_RIGHT | TA_TOP,   trCenterBottom = TA_CENTER | TA_TOP,   trRightBottom = TA_LEFT | TA_TOP
};
//---------------------------------------------------------------------------
struct TGPHTData
{
	long double X;
   long double Y;
   AnsiString SerName;
};
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TGPHTDataEvent)(TGPHTData GPHTData);
typedef void __fastcall (__closure *TOnReleaseHitTest)(void);
//---------------------------------------------------------------------------
struct TGrpDesc
{
	bool InvertX;
   bool InvertY;
   bool XAxVisible;
   bool YAxVisible;
   bool SaveSers;
   int MainFisHeight;
   int IntermedFisHeight;
   int NumMainFis;
   int NumIntermedFis;
   int Accuracy;
   int PropAcPage;
   long int NumSers;
	TColor AxisColor;
   TColor BackColor;
   LD POFX;
   LD POFY;
};
//---------------------------------------------------------------------------
class CGrps : public TWinControl
{
private:
   bool PointLineActive;
   bool HintActive;
   bool HitTest;
   int NumXVNames;
   int NumYVNames;
   UINT CBFormat;
   LD DW;
   LD DH;
   TPointLD OffsetLogicCenter;
   TPointLD LogicCenter;
   TPointLD PhizCenter;
   TPointLD CurrentXY;
   TRectLD LogicReg;
   TRectLD PhizReg;
   TRectLD XVNames;
   TRectLD YVNames;
   HDC BackBuf;
   AnsiString XName;
   AnsiString YName;
   Graphics::TBitmap *BMXName;
   Graphics::TBitmap *BMYName;
   CSerManager *SerManager;
   CClipBoard *ClipBoard;
   THintWindow *HW;
   TFProperty *FProperty;
   TList *SelSers;
   void __fastcall CalcVNames(void);
   void __fastcall CalcStMetrix(void);
   void __fastcall CalcDinMetrix(void);
   LD __fastcall InvertPhizX(LD X);
   LD __fastcall InvertPhizY(LD Y);
   LD __fastcall GetPhizX(LD LogicX);
   LD __fastcall GetPhizY(LD LogicY);
   LD __fastcall LogicXToPhiz(LD X) {return (X + LogicCenter.X)*DW;}
   LD __fastcall LogicYToPhiz(LD Y) {return (Y + LogicCenter.Y)*DH;}
   LD __fastcall PhizXToLogic(LD X) {return X/DW - LogicCenter.X;}
   LD __fastcall PhizYToLogic(LD Y) {return Y/DH - LogicCenter.Y;}
   void CreateBuf(void* &Buff, DWORD BufWidth, DWORD BufHeight);
	void TransparentBlt(HDC hdc, HDC SrcDC,
                       short xStart, short yStart,
                       int Width, int Height,
                       COLORREF cTransparentColor);
   void __fastcall Pset(LD X, LD Y, DWORD Color,
                        TRendStyle RendStyle = rsLogic,
                        AnsiString Caption = "",
                        Graphics::TBitmap *BMPset = NULL,
                        Graphics::TBitmap *BMCaption = NULL);
   void __fastcall Line(HDC hdc, LD X1, LD Y1, LD X2, LD Y2,
                        DWORD PenColor, int PenStyle = PS_SOLID,
                        int PenWidth = 1);
   void __fastcall DTextOut(LD X, LD Y, AnsiString Text,
                            TFont *Font = NULL,
                            TTextRend TextRend = trRightBottom);
   void __fastcall DrawSers(void);
   void __fastcall DrawAxis(void);
   void __fastcall DrawBackGround();
   void __fastcall ShowHintCoord(int MX, int MY);
   void __fastcall ReleaseHC(void);
	void __fastcall Draw(void);
   void __fastcall Render(HDC hdc);
   CSer* __fastcall GetSer(int X, int Y);
   void __fastcall SelectSer(CSer *Ser);
   void __fastcall UnSelectSer(void);
   void __fastcall GrpPsetHitTest(TGPHTData GPHTData);
   void __fastcall OnGrpResize(TObject *Sender);
	void __fastcall OnMM(TObject *Sender, TShiftState Shift,
                        int X, int Y);
	void __fastcall OnMD(TObject *Sender, TMouseButton Button,
                        TShiftState Shift, int X, int Y);
   void __fastcall OnMU(TObject *Sender, TMouseButton Button,
                        TShiftState Shift, int X, int Y);
	void __fastcall OnMIPropertyClick(TObject *Sender);
	void virtual __fastcall WMPaint(TWMPaint &Message);
   BEGIN_MESSAGE_MAP
   	VCL_MESSAGE_HANDLER(WM_PAINT, TWMPaint, WMPaint);
   END_MESSAGE_MAP(TWinControl)
public:
   TGrpDesc GrpDesc;
   TOnReleaseHitTest OnReleaseHitTest;
   TGPHTDataEvent GPHTDataEvent;
	__fastcall virtual CGrps(TComponent *AOwner);
   void __fastcall AxisName(AnsiString XName,
                            AnsiString YName,
                            AnsiString XResName = "",
                            AnsiString YResName = "",
                            THandle HI = (THandle)HInstance);
   bool __fastcall AddSer(CSer *Ser, AnsiString SerName = "");
   bool __fastcall CheckSers(void);
   bool __fastcall CheckCBText(void);
   bool __fastcall CheckSelSers(void);
   bool __fastcall CheckCBBitmap(void);
   void __fastcall PropDlgExe(void);
   void __fastcall Print(void);
   void __fastcall ClearGrp(void);
   void __fastcall CopySelected(void);
   void __fastcall PastSers(void);
   void __fastcall DelSelected(void);
	void __fastcall SelectAllSers(void);
   void __fastcall ClearCB(void);
   void __fastcall CopyToCB(void);
   __fastcall virtual ~CGrps(void);
};
//---------------------------------------------------------------------------
#endif
