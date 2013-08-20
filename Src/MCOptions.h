//---------------------------------------------------------------------------
#ifndef MCOptionsH
#define MCOptionsH

#ifndef MCBaseH
	#include "MCBase.h"
#endif
#ifndef OptionsFrmH
	#include "OptionsFrm.h"
#endif
#ifndef MCFileH
	#include "MCFile.h"
#endif

extern int KOLICHESTVO_SHAGOV;

//---------------------------------------------------------------------------
class COptions : public CObject
{
private:
	TFOptions *FOptions;
public:
	COptions(void);
   virtual void __fastcall Init(CBase *Parent);
   void __fastcall ShowDlg(TCFGFile *CFGFile, TDSKFile *DSKFile, TPRJFile *PRJFile);
   virtual void __fastcall Done(void);
};
//---------------------------------------------------------------------------
#endif
