//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MCElBts.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void __fastcall CElBts::OnTabChange(TObject *Sender)
{
   ((TPanel*)TabPanels->Items[ActiveTabIndex])->Visible = false;
	ActiveTabIndex = TCElBts->TabIndex;
   ((TPanel*)TabPanels->Items[ActiveTabIndex])->Visible = true;
   OnResizeHandle(NULL);
}
//---------------------------------------------------------------------------
void __fastcall CElBts::OnResizeHandle(TObject *Sender)
{
   if(TabPanels)
   	for(int ci = 0; ci < TabPanels->Count; ci++)
   		((TPanel*)TabPanels->Items[ActiveTabIndex])->SetBounds(OffsetEls + 12,
         	TCElBts->DisplayRect.Top,
            TCElBts->DisplayRect.Width() - OffsetEls - 12,
            TCElBts->DisplayRect.Height());
}
//---------------------------------------------------------------------------
void __fastcall CElBts::OnRootBtDown(TObject *Sender)
{
	if(DownBt) DownBt->Down = false;
   DownBt = NULL;
   if(OnElButtonClick) OnElButtonClick(RootBt->Tag);
}
//---------------------------------------------------------------------------
void __fastcall CElBts::OnBtDown(TObject *Sender)
{
	if(DownBt) DownBt->Down = false;
	if(RootBt) RootBt->Down = false;
   DownBt = (TSpeedButton*)Sender;
   if(OnElButtonClick) OnElButtonClick(DownBt->Tag);
}
//---------------------------------------------------------------------------
void __fastcall CElBts::CreateTab(AnsiString TabName)
{
	TCElBts->Tabs->Add(TabName);
   TPanel *PTabPanel = new TPanel(TCElBts);
   PTabPanel->SetBounds(OffsetEls + 12,
                        TCElBts->DisplayRect.Top,
                        TCElBts->DisplayRect.Width() - OffsetEls - 12,
                        TCElBts->DisplayRect.Height());
   PTabPanel->Visible = false;
   PTabPanel->BevelInner = bvNone;
   PTabPanel->BevelOuter = bvNone;
	PTabPanel->Parent = TCElBts;
   TabPanels->Add(PTabPanel);
   TPageScroller *PSElPanel = new TPageScroller(PTabPanel);
   PSElPanel->Align = alClient;
   PSElPanel->Parent = PTabPanel;
   TPanel *ElPanel = new TPanel(PTabPanel);
   ElPanel->Align = alNone;
   ElPanel->BevelInner = bvNone;
   ElPanel->BevelOuter = bvNone;
   ElPanel->Parent = PTabPanel;
   PSElPanel->Control = ElPanel;
   ElPanel->Left = PSElPanel->BorderWidth;
   ElPanels->Add(ElPanel);
   OnTabChange(TCElBts);
}
//---------------------------------------------------------------------------
int CElBts::GetTabIndex(AnsiString TabName)
{
	int TabIndex = TCElBts->Tabs->IndexOf(TabName);
   if(TabIndex == -1)
   {
   	CreateTab(TabName);
      TabIndex = TCElBts->Tabs->Count - 1;
   }
   return TabIndex;
}
//---------------------------------------------------------------------------
__fastcall CElBts::CElBts(TComponent *AOwner):TPanel(AOwner)
{
   OffsetEls = 0;
   ActiveTabIndex = 0;
	TCElBts = NULL;
   RootBt = NULL;
   DownBt = NULL;
   TabPanels = NULL;
   ElPanels = NULL;
   BevelInner = bvNone;
   BevelOuter = bvNone;
   OnResize = OnResizeHandle;
   OnElButtonClick = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CElBts::Init(void)
{
	TCElBts = new TTabControl(this);
   TCElBts->Parent = this;
   TCElBts->TabHeight = 15;
   TCElBts->Font->Height = 8;
   TCElBts->Align = alClient;
   TCElBts->OnChange = OnTabChange;
   RootBt = new TSpeedButton(TCElBts);
   RootBt->Parent = TCElBts;
   RootBt->Flat = true;
   RootBt->GroupIndex = 1;
   RootBt->AllowAllUp = true;
   RootBt->Down = true;
   RootBt->SetBounds(TCElBts->DisplayRect.Left,
                     TCElBts->DisplayRect.Top + TCElBts->TabHeight,
                     TCElBts->DisplayRect.Height() - TCElBts->TabHeight,
                     TCElBts->DisplayRect.Height() - TCElBts->TabHeight);
	RootBt->OnClick = OnRootBtDown;
 	OffsetEls = RootBt->Width + RootBt->Left;
   TabPanels = new TList;
   ElPanels = new TList;
}
//---------------------------------------------------------------------------
void __fastcall CElBts::AddRootButton(AnsiString  Hint,
                                      AnsiString ResName, HINSTANCE HI,
                                      int ObjectID)
{
   RootBt->ShowHint = true;
   RootBt->Hint = Hint;
   RootBt->Glyph->LoadFromResourceName((THandle)HI, ResName);
  	RootBt->Tag = ObjectID;
}
//---------------------------------------------------------------------------
void __fastcall CElBts::AddButton(AnsiString TabName,
                                  AnsiString Hint,
                                  AnsiString ResName,
                                  HINSTANCE HI, int ObjectID)
{
   TPanel *ElPanel = (TPanel*)ElPanels->Items[GetTabIndex(TabName)];
	TSpeedButton *SBt = new TSpeedButton(ElPanel);
   ElPanel->AutoSize = false;
   ElPanel->Align = alClient;
   SBt->Flat = true;
   SBt->GroupIndex = 1;
   SBt->SetBounds(ElPanel->Width, 0, ElPanel->Height, ElPanel->Height);
   SBt->Align = alLeft;
   SBt->ShowHint = true;
   SBt->Hint = Hint;
   SBt->Glyph->LoadFromResourceName((THandle)HI, ResName);
   SBt->AllowAllUp = true;
   SBt->OnClick = OnBtDown;
   SBt->Parent = ElPanel;
   SBt->Tag = ObjectID;
   ElPanel->AutoSize = true;
   ElPanel->Align = alNone;
}
//---------------------------------------------------------------------------
void __fastcall CElBts::ResetButtons()
{
	RootBt->Down = true;
	OnRootBtDown(NULL);
}
//---------------------------------------------------------------------------
