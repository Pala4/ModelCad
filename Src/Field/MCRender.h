//---------------------------------------------------------------------------
#ifndef MCRenderH
#define MCRenderH

#include "..\MCBase.h"
//---------------------------------------------------------------------------
class CRender : public CIcarBase
{
private:
public:
	DWORD Width;
   DWORD Height;
   DWORD FieldColor;
   DWORD GridColor;
	CRender(void);
   BOOL __fastcall virtual SetMetrix(DWORD _Width, DWORD _Height)
   {
   	Width = _Width;
      Height = _Height;
      return TRUE;
   }
   void __fastcall virtual SetColor(DWORD _FieldColor,
                                    DWORD _GridColor)
   {
   	FieldColor = _FieldColor;
   	GridColor = _GridColor;
   }
};
//---------------------------------------------------------------------------
#endif
