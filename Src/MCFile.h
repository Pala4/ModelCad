//---------------------------------------------------------------------------
#ifndef MCFileH
#define MCFileH

#ifndef MCBaseH
	#include "MCBase.h"
#endif

#include "MCadID.h"
//---------------------------------------------------------------------------
enum TFSRet
{
	fsrExt = 0,
   fsrName = 1,
   fsrDir = 2,
   fsrDrive = 4
};

void FSplit(AnsiString &Path, TFSRet FSRet);
//---------------------------------------------------------------------------
class CFile : public CObject
{
protected:
	void __fastcall CvtIOErrToIODsc(void);
public:
   int IOErr;
   LPSTR IODsc;
   AnsiString DefaultFolder;
   AnsiString DefaultExt;
	CFile(void);
   virtual bool __fastcall Write(AnsiString FileName) = 0;
   virtual bool __fastcall Read(AnsiString FileName) = 0;
};
//---------------------------------------------------------------------------
struct TLastProj
{
   bool Active;
   int Left;
   int Top;
   int Width;
   int Height;
	AnsiString Name;
};

struct TDSKFile
{
	int MWLeft;
   int MWTop;
   int MWWidth;
   int MWHeight;
   int MWMax;
   bool ElBTSVisible;
   int ElBTSLeft;
   int ElBTSTop;
   int ElBTSWidth;
   int OILeft;
   int OITop;
   int OIWidth;
   int OIHeight;
   int OptionsPageNomber;
   int NumLastProjs;
   TList *LastProjs;
};

class CDSK : public CFile
{
public:
   TDSKFile DSKFile;
   CDSK(void);
   virtual void __fastcall Init(CBase *Parent);
   virtual bool __fastcall Write(AnsiString FileName);
   virtual bool __fastcall Read(AnsiString FileName);
   virtual void __fastcall Done(void);
};
//---------------------------------------------------------------------------
struct TCFGFile
{
   int StartAction;
   bool AutoSaveDSK;
   bool AutoSaveCFG;
   bool AutoSavePRJ;
   bool GridVisible;
   bool AlignToGrid;
   bool UseSmartLinks;
   long FieldColor;
   long GridColor;
   int GridStep;
};

class CCFG : public CFile
{
public:
   TCFGFile CFGFile;
   CCFG(void);
   virtual void __fastcall Init(CBase *Parent);
   virtual bool __fastcall Write(AnsiString FileName);
   virtual bool __fastcall Read(AnsiString FileName);
   virtual void __fastcall Done(void);
};
//---------------------------------------------------------------------------
struct TPRJFile
{
	int FieldWidth;
   int FieldHeight;
   int CalcOrder;
   long double DT;
   long double T;
   long double DW;
   long double W;
   DWORD PRJDumpSize;
};

class CPRJ : public CFile
{
private:
	void *PRJDump;
   DWORD PRJDumpSize;
	TSaveDialog *SvDlg;
   TOpenDialog *OpDlg;
public:
   bool FileSaved;
   bool FileOpened;
   TPRJFile PRJFile;
   CPRJ(void);
   virtual void __fastcall Init(CBase *Parent);
   void __fastcall DonePRJDump(void);
   void __fastcall SetPRJDump(void *Dump, DWORD DumpSize);
   virtual bool __fastcall Write(AnsiString FileName);
   bool __fastcall SaveAs(AnsiString &FileName);
   virtual bool __fastcall Read(AnsiString FileName);
   void __fastcall GetPRJDump(void *&Dump, DWORD &DumpSize);
   bool __fastcall Open(AnsiString &FileName);
   virtual void __fastcall Done(void);
};
//---------------------------------------------------------------------------
#endif
