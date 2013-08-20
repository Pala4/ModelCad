//---------------------------------------------------------------------------
#ifndef MCBaseH
#define MCBaseH

#include <windows.h>
//---------------------------------------------------------------------------
//   TObject    -|         Hierarchy description:
//     |         |
//		 . 	     |				     CBase   -|
//     .         | VCL                |     > Needed For Support Polymorphic
//     .         > extention       CObject -|
//     |         |                    |
//   TForm       |   ----------------------------------------------------------         ----> Inheritance
//     |         |   |        |       |         |        |            |        |        *---> Encapsulation in container
//  -------      | CApp   CSysInfo  CFile    COptions  CProjCont    CProj  CPlugManager *A--> Encapsulation array in container
//  |      |     | * ^        *       |         *        *    ^     *A ^
//TFMain TFProj -| | |        |   ---------     |        |    |      | |
//  ^      *       | |--------    |   |    |    |        |    -------  |
//  |      |       | |          CDSK CCFG CPRJ  |        |             |
//  ---------------  |            *   *    *    |        |             |
//         |         |            |   |    |    |        |             |
//         |         ------------------------------------              |
//         |                               |                           |
//          ------------------------------------------------------------
//---------------------------------------------------------------------------
class CBase
{
public:
	CBase(void){}
   virtual ~CBase(void){}
};
//---------------------------------------------------------------------------
class CObject : public CBase
{
protected:
	CBase *Parent;
public:
   CObject(void);
   virtual void __fastcall Init(CBase *Parent)
   {
   	this->Parent = Parent;
   }
   virtual void __fastcall Done(void)
   {
   	Parent = NULL;
   }
   virtual ~CObject(void);
};
//---------------------------------------------------------------------------

class CIcarBase: public TObject
{
private:
public:
	TForm *FMain;
	CIcarBase(void);
   void __fastcall virtual Init(TForm *_FMain){FMain = _FMain;}
   void __fastcall virtual Done(void) = 0;
};
//---------------------------------------------------------------------------
#endif
