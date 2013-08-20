object FChar: TFChar
  Left = 248
  Top = 195
  BorderStyle = bsDialog
  Caption = 'Характеристики'
  ClientHeight = 177
  ClientWidth = 334
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object PCChars: TPageControl
    Left = 7
    Top = 8
    Width = 321
    Height = 129
    ActivePage = TSTemp
    TabOrder = 0
    object TSTemp: TTabSheet
      Caption = 'Временные'
      object LTempWidth: TLabel
        Left = 167
        Top = 8
        Width = 111
        Height = 13
        Caption = 'Временной диапазон:'
        ParentShowHint = False
        ShowHint = True
      end
      object LTempS: TLabel
        Left = 232
        Top = 20
        Width = 6
        Height = 24
        Caption = '-'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LDT: TLabel
        Left = 168
        Top = 52
        Width = 76
        Height = 13
        Caption = 'Дискретность:'
        ParentShowHint = False
        ShowHint = True
      end
      object RGTemp: TRadioGroup
        Left = 7
        Top = 0
        Width = 154
        Height = 97
        Items.Strings = (
          'Переходная h(t)'
          'Весовая k(t)')
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object ET1: TEdit
        Left = 167
        Top = 24
        Width = 58
        Height = 21
        ParentShowHint = False
        ShowHint = False
        TabOrder = 1
        OnKeyPress = EKeyPress
      end
      object ET2: TEdit
        Left = 247
        Top = 24
        Width = 58
        Height = 21
        TabOrder = 2
      end
      object EDT: TEdit
        Left = 248
        Top = 48
        Width = 57
        Height = 21
        TabOrder = 3
        OnKeyPress = EKeyPress
      end
    end
    object TSFreq: TTabSheet
      Caption = 'Частотные'
      ImageIndex = 1
      object LFreqS: TLabel
        Left = 232
        Top = 20
        Width = 6
        Height = 24
        Caption = '-'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LFreqWidth: TLabel
        Left = 167
        Top = 8
        Width = 110
        Height = 13
        Caption = 'Частотный диапазон:'
        ParentShowHint = False
        ShowHint = True
      end
      object LDW: TLabel
        Left = 168
        Top = 52
        Width = 76
        Height = 13
        Caption = 'Дискретность:'
        ParentShowHint = False
        ShowHint = True
      end
      object RGFreq: TRadioGroup
        Left = 7
        Top = 0
        Width = 154
        Height = 97
        Columns = 2
        Items.Strings = (
          'АЧХ'
          'ЛАЧХ'
          'ФЧХ'
          'ЛФЧХ'
          'АФЧХ'
          'НПЧХ')
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object EW1: TEdit
        Left = 167
        Top = 24
        Width = 58
        Height = 21
        TabOrder = 1
      end
      object EW2: TEdit
        Left = 247
        Top = 24
        Width = 58
        Height = 21
        TabOrder = 2
      end
      object EDW: TEdit
        Left = 248
        Top = 48
        Width = 57
        Height = 21
        TabOrder = 3
        OnKeyPress = EKeyPress
      end
    end
  end
  object BtShow: TButton
    Left = 232
    Top = 104
    Width = 89
    Height = 25
    Caption = 'Отобразить>>'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnClick = BtShowClick
  end
  object BtOk: TButton
    Left = 81
    Top = 144
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = BtOkClick
  end
  object BtCancel: TButton
    Left = 177
    Top = 144
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = BtCancelClick
  end
end
