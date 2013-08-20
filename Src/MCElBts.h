//---------------------------------------------------------------------------
#ifndef MCElBtsH
#define MCElBtsH

#include <buttons.hpp>
#include <comctrls.hpp>
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TElButtonClick)(int ObjectID);
//---------------------------------------------------------------------------
class CElBts : public TPanel
{
private:
   int OffsetEls;
   int ActiveTabIndex;
	TTabControl *TCElBts;
   TSpeedButton *RootBt;
   TSpeedButton *DownBt;
   TList *TabPanels;
   TList *ElPanels;
   void __fastcall OnTabChange(TObject *Sender);
   void __fastcall OnResizeHandle(TObject *Sender);
   void __fastcall OnRootBtDown(TObject *Sender);
   void __fastcall OnBtDown(TObject *Sender);
   void __fastcall CreateTab(AnsiString TabName);
   int GetTabIndex(AnsiString TabName);
public:
   TElButtonClick OnElButtonClick;
	virtual __fastcall CElBts(TComponent *AOwner);
   void __fastcall Init(void);
   void __fastcall AddRootButton(AnsiString  Hint,
                                 AnsiString ResName, HINSTANCE HI,
                                 int ObjectID);
   void __fastcall AddButton(AnsiString TabName, AnsiString  Hint,
                             AnsiString ResName, HINSTANCE HI,
                             int ObjectID);
   void __fastcall ResetButtons();
};
//---------------------------------------------------------------------------
#endif
