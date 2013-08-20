//---------------------------------------------------------------------------
#ifndef MCSysH
#define MCSysH

#ifndef MCBaseH
	#include "MCBase.h"
#endif
//---------------------------------------------------------------------------
class CSysInfo : public CObject
{
private:
	void __fastcall GetSysInfo(void);
public:
	int ScrWidth;
   int ScrHeight;
   int MaxWinWidth;
   int MaxWinHeight;
   int BPP;
	CSysInfo(void);
   virtual void __fastcall Init(CBase *Parent);
   virtual void __fastcall Done(void);
};
//---------------------------------------------------------------------------
#endif
