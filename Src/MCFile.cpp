//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <errno.h>
#include <string.h>
#include <dir.h>

#include "MCFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
#define ENOENT_DSC "Каталог или файл не найдены"
#define EMFILE_DSC "Слишком много открытых файлов"
#define EACCES_DSC "Доступ запрещен"
#define EINVACC_DSC "Неверный код доступа"
#define EBADF_DSC "Неверный номер файла"
#define EUNKNOWN_DSC "Неизвестная ошибка"
//---------------------------------------------------------------------------
void FSplit(AnsiString &Path, TFSRet FSRet)
{
	char drive[MAXDRIVE];
	char dir[MAXDIR];
	char file[MAXFILE];
	char ext[MAXEXT];
	fnsplit(Path.c_str(), drive, dir, file, ext);
	switch(FSRet)
   {
   	case fsrExt: Path = ext; break;
   	case fsrName: Path = file; break;
   	case fsrDir: Path = dir; break;
   	case fsrDrive: Path = drive;
   }
}
//---------------------------------------------------------------------------
CFile::CFile(void):CObject()
{
	IOErr = 0;
   IODsc = "";
}
//---------------------------------------------------------------------------
void __fastcall CFile::CvtIOErrToIODsc(void)
{
	switch(IOErr)
   {
   	case ENOENT:
      	IODsc = ENOENT_DSC;
         break;
      case EMFILE:
      	IODsc = EMFILE_DSC;
         break;
      case EACCES:
      	IODsc = EACCES_DSC;
         break;
      case EINVACC:
      	IODsc = EINVACC_DSC;
         break;
      case EBADF:
      	IODsc = EBADF_DSC;
         break;
      default:
      	IODsc = EUNKNOWN_DSC;
   }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CDSK::CDSK(void):CFile()
{
}
//---------------------------------------------------------------------------
void __fastcall CDSK::Init(CBase *Parent)
{
	CObject::Init(Parent);
   ZeroMemory(&DSKFile, sizeof(TDSKFile));
	DSKFile.LastProjs = new TList;
}
//---------------------------------------------------------------------------
bool __fastcall CDSK::Write(AnsiString FileName)
{
	FileName = DefaultFolder + FileName;
   int Handle = open(FileName.c_str(),
                     O_CREAT|O_TRUNC|O_BINARY|O_RDWR,
                     S_IREAD|S_IWRITE);
   if(Handle < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
   DSKFile.NumLastProjs = DSKFile.LastProjs->Count;
   if(write(Handle, &DSKFile, sizeof(TDSKFile) - sizeof(TList*)) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	close(Handle);
      return false;
   }
   int StrLen;
   TLastProj *LP;
   AnsiString StrTmp;
   for(int ci = 0; ci < DSKFile.LastProjs->Count; ci++)
   {
      LP = (TLastProj*)DSKFile.LastProjs->Items[ci];
   	if(write(Handle, LP, sizeof(TLastProj) - sizeof(AnsiString)) < 0)
   	{
      	IOErr = errno;
      	CvtIOErrToIODsc();
   		close(Handle);
      	return false;
   	}
      StrTmp = LP->Name;
      StrLen = strlen(StrTmp.c_str()) + 1;
   	if(write(Handle, &StrLen, sizeof(int)) < 0)
   	{
      	IOErr = errno;
      	CvtIOErrToIODsc();
   		close(Handle);
      	return false;
   	}
   	if(write(Handle, StrTmp.c_str(), StrLen) < 0)
   	{
      	IOErr = errno;
      	CvtIOErrToIODsc();
   		close(Handle);
      	return false;
   	}
   }
   if(close(Handle) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
	return true;
}
//---------------------------------------------------------------------------
bool __fastcall CDSK::Read(AnsiString FileName)
{
   if(!FileExists(FileName))
   {
      IODsc = ENOENT_DSC;
   	return false;
   }
   int Handle = open(FileName.c_str(), O_BINARY|O_RDONLY);
   if(Handle < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
   if(read(Handle, &DSKFile, sizeof(TDSKFile) - sizeof(TList*)) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	close(Handle);
   	return false;
   }
   int StrLen;
   TLastProj *LP;
   LPSTR StrTmp;
   DSKFile.LastProjs->Clear();
   for(int ci = 0; ci < DSKFile.NumLastProjs; ci++)
   {
      LP = new TLastProj;
   	if(read(Handle, LP, sizeof(TLastProj) - sizeof(AnsiString)) < 0)
   	{
      	IOErr = errno;
      	CvtIOErrToIODsc();
   		close(Handle);
      	return false;
   	}
   	if(read(Handle, &StrLen, sizeof(int)) < 0)
   	{
      	IOErr = errno;
      	CvtIOErrToIODsc();
   		close(Handle);
      	return false;
   	}
      StrTmp = new char[StrLen];
   	if(read(Handle, StrTmp, StrLen) < 0)
   	{
      	IOErr = errno;
      	CvtIOErrToIODsc();
   		close(Handle);
      	return false;
   	}
      LP->Name = StrTmp;
      delete []StrTmp;
      DSKFile.LastProjs->Add(LP);
   }
   if(close(Handle) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
	return true;
}
//---------------------------------------------------------------------------
void __fastcall CDSK::Done(void)
{
   if(DSKFile.LastProjs)
   {
      for(int ci = 0; ci < DSKFile.LastProjs->Count; ci++)
      	delete (TLastProj*)DSKFile.LastProjs->Items[ci];
   	DSKFile.LastProjs->Clear();
   	delete DSKFile.LastProjs;
   }
   ZeroMemory(&DSKFile, sizeof(TDSKFile));
	CObject::Done();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CCFG::CCFG(void):CFile()
{
}
//---------------------------------------------------------------------------
void __fastcall CCFG::Init(CBase *Parent)
{
	CObject::Init(Parent);
   ZeroMemory(&CFGFile, sizeof(TCFGFile));
}
//---------------------------------------------------------------------------
bool __fastcall CCFG::Write(AnsiString FileName)
{
	FileName = DefaultFolder + FileName;
   int Handle = open(FileName.c_str(),
                     O_CREAT|O_TRUNC|O_BINARY|O_RDWR,
                     S_IREAD|S_IWRITE);
   if(Handle < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
   if(write(Handle, &CFGFile, sizeof(TCFGFile)) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	close(Handle);
      return false;
   }
   if(close(Handle) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
	return true;
}
//---------------------------------------------------------------------------
bool __fastcall CCFG::Read(AnsiString FileName)
{
   if(!FileExists(FileName))
   {
      IODsc = ENOENT_DSC;
   	return false;
   }
   int Handle = open(FileName.c_str(), O_BINARY|O_RDONLY);
   if(Handle < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
   if(read(Handle, &CFGFile, sizeof(TCFGFile)) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	close(Handle);
   	return false;
   }
   if(close(Handle) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
	return true;
}
//---------------------------------------------------------------------------
void __fastcall CCFG::Done(void)
{
   ZeroMemory(&CFGFile, sizeof(TCFGFile));
   CObject::Done();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CPRJ::CPRJ(void):CFile()
{
   FileSaved = false;
   FileOpened = false;
   PRJDump = NULL;
   PRJDumpSize = 0;
	SvDlg = NULL;
   OpDlg = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CPRJ::Init(CBase *Parent)
{
	CObject::Init(Parent);
   ZeroMemory(&PRJFile, sizeof(TPRJFile));
}
//---------------------------------------------------------------------------
void __fastcall CPRJ::DonePRJDump(void)
{
   if(PRJDump)
   {
   	PRJDump = (byte*)realloc(PRJDump, 0);
      PRJDump = NULL;
   }
   PRJDumpSize = 0;
}
//---------------------------------------------------------------------------
void __fastcall CPRJ::SetPRJDump(void *Dump, DWORD DumpSize)
{
	DonePRJDump();
   PRJDump = Dump;
  	PRJDumpSize = DumpSize;
}
//---------------------------------------------------------------------------
bool __fastcall CPRJ::Write(AnsiString FileName)
{
   int Handle = open(FileName.c_str(),
                     O_CREAT|O_TRUNC|O_BINARY|O_RDWR,
                     S_IREAD|S_IWRITE);
   if(Handle < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
   PRJFile.PRJDumpSize = PRJDumpSize;
   if(write(Handle, &PRJFile, sizeof(TPRJFile)) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	close(Handle);
   	return false;
   }
   if(PRJDump)
   	if(write(Handle, PRJDump, PRJDumpSize) < 0)
   	{
      	IOErr = errno;
      	CvtIOErrToIODsc();
   		close(Handle);
   		return false;
   	}
   if(close(Handle) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
	return true;
}
//---------------------------------------------------------------------------
bool __fastcall CPRJ::SaveAs(AnsiString &FileName)
{
	SvDlg = new TSaveDialog(NULL);
   SvDlg->DefaultExt = DefaultExt;
   SvDlg->FileName = FileName;
   SvDlg->Filter = "Файлы проектов (*.";
   SvDlg->Filter += DefaultExt;
   SvDlg->Filter += ")|*.";
   SvDlg->Filter += DefaultExt;
   SvDlg->InitialDir = DefaultFolder;
   SvDlg->Options << ofOverwritePrompt;
   if(SvDlg->Execute())
   {
		if(!Write(SvDlg->FileName)) return (FileSaved = false);
      FileName = SvDlg->FileName;
      FileSaved = true;
   }
   else FileSaved = false;
   delete SvDlg;
   SvDlg = NULL;
   return true;
}
//---------------------------------------------------------------------------
bool __fastcall CPRJ::Read(AnsiString FileName)
{
   if(!FileExists(FileName))
   {
      IODsc = ENOENT_DSC;
   	return false;
   }
   int Handle = open(FileName.c_str(), O_BINARY|O_RDONLY);
   if(Handle < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
   if(read(Handle, &PRJFile, sizeof(TPRJFile)) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	close(Handle);
   	return false;
   }
	DonePRJDump();
   PRJDump = (byte*)realloc(PRJDump, PRJFile.PRJDumpSize);
   if(read(Handle, PRJDump, PRJFile.PRJDumpSize) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	close(Handle);
   	return false;
   }
   if(close(Handle) < 0)
   {
      IOErr = errno;
      CvtIOErrToIODsc();
   	return false;
   }
	return true;
}
//---------------------------------------------------------------------------
void __fastcall CPRJ::GetPRJDump(void *&Dump, DWORD &DumpSize)
{
	Dump = PRJDump;
   DumpSize = PRJDumpSize;
}
//---------------------------------------------------------------------------
bool __fastcall CPRJ::Open(AnsiString &FileName)
{
	OpDlg = new TOpenDialog(NULL);
   OpDlg->DefaultExt = DefaultExt;
   OpDlg->Filter = "Файлы проектов (*.";
   OpDlg->Filter += DefaultExt;
   OpDlg->Filter += ")|*.";
   OpDlg->Filter += DefaultExt;
   OpDlg->InitialDir = DefaultFolder;
   if(OpDlg->Execute())
   {
		if(!Read(OpDlg->FileName)) return (FileOpened = false);
      FileName = OpDlg->FileName;
      FileOpened = true;
   }
   else FileOpened = false;
   delete OpDlg;
   OpDlg = NULL;
   return true;
}
//---------------------------------------------------------------------------
void __fastcall CPRJ::Done(void)
{
   FileSaved = false;
   FileOpened = false;
   DonePRJDump();
   if(SvDlg)
   {
   	delete SvDlg;
   	SvDlg = NULL;
   }
   if(OpDlg)
   {
      delete OpDlg;
   	OpDlg = NULL;
   }
   ZeroMemory(&PRJFile, sizeof(TPRJFile));
   CObject::Done();
}
//---------------------------------------------------------------------------
