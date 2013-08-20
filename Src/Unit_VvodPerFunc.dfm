object Form_PerFunc: TForm_PerFunc
  Left = 251
  Top = 214
  BorderStyle = bsDialog
  Caption = 'Ввод передаточной функции'
  ClientHeight = 296
  ClientWidth = 457
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 4
    Height = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 260
    Top = 10
    Width = 4
    Height = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 32
    Top = 176
    Width = 159
    Height = 13
    Caption = 'Дискретность по частоте (dW):'
  end
  object Label4: TLabel
    Left = 32
    Top = 200
    Width = 213
    Height = 13
    Caption = 'Максимальное значение частоты (Wmax):'
  end
  object Label5: TLabel
    Left = 248
    Top = 232
    Width = 123
    Height = 13
    Caption = 'Коэффициент усиления:'
  end
  object CSE_znach: TCSpinEdit
    Left = 200
    Top = 40
    Width = 65
    Height = 22
    TabStop = True
    MaxValue = 50
    MinValue = 1
    ParentColor = False
    TabOrder = 2
    Value = 1
    OnClick = CSE_znachClick
    OnKeyDown = CSE_znachKeyDown
  end
  object BB_Add: TBitBtn
    Left = 200
    Top = 72
    Width = 65
    Height = 25
    Caption = 'Добавить'
    TabOrder = 3
    OnClick = BB_AddClick
  end
  object LB_A: TListBox
    Left = 32
    Top = 32
    Width = 145
    Height = 129
    TabStop = False
    ItemHeight = 13
    TabOrder = 0
    OnKeyDown = Edit1KeyDown
  end
  object LB_B: TListBox
    Left = 280
    Top = 32
    Width = 145
    Height = 129
    TabStop = False
    ItemHeight = 13
    TabOrder = 1
    OnClick = LB_BClick
  end
  object BB_Ok: TBitBtn
    Left = 144
    Top = 264
    Width = 65
    Height = 25
    Caption = 'Ok'
    TabOrder = 4
    OnClick = BB_OkClick
  end
  object BB_Cancel: TBitBtn
    Left = 256
    Top = 264
    Width = 65
    Height = 25
    Caption = 'Отмена'
    TabOrder = 5
    OnClick = BB_CancelClick
  end
  object Edit1: TEdit
    Left = 56
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object Edit_B: TEdit
    Left = 304
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object EDW: TEdit
    Left = 248
    Top = 168
    Width = 121
    Height = 21
    TabOrder = 8
  end
  object EWMax: TEdit
    Left = 248
    Top = 200
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object CB_Tkoff: TCheckBox
    Left = 72
    Top = 232
    Width = 145
    Height = 17
    Caption = 'Через Т-коэффиценты'
    TabOrder = 10
    OnClick = CB_TkoffClick
  end
  object E_KofUsil: TEdit
    Left = 376
    Top = 232
    Width = 57
    Height = 21
    TabOrder = 11
    Text = '1'
  end
end
