object FChar: TFChar
  Left = 677
  Top = 320
  BorderStyle = bsDialog
  Caption = #1061#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1080
  ClientHeight = 177
  ClientWidth = 334
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object PCChars: TPageControl
    Left = 7
    Top = 8
    Width = 321
    Height = 129
    ActivePage = TSTemp
    TabIndex = 0
    TabOrder = 0
    object TSTemp: TTabSheet
      Caption = #1042#1088#1077#1084#1077#1085#1085#1099#1077
      object LTempWidth: TLabel
        Left = 167
        Top = 8
        Width = 111
        Height = 13
        Caption = #1042#1088#1077#1084#1077#1085#1085#1086#1081' '#1076#1080#1072#1087#1072#1079#1086#1085':'
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
        Caption = #1044#1080#1089#1082#1088#1077#1090#1085#1086#1089#1090#1100':'
        ParentShowHint = False
        ShowHint = True
      end
      object RGTemp: TRadioGroup
        Left = 7
        Top = 0
        Width = 154
        Height = 97
        Items.Strings = (
          #1055#1077#1088#1077#1093#1086#1076#1085#1072#1103' h(t)'
          #1042#1077#1089#1086#1074#1072#1103' k(t)')
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
      Caption = #1063#1072#1089#1090#1086#1090#1085#1099#1077
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
        Caption = #1063#1072#1089#1090#1086#1090#1085#1099#1081' '#1076#1080#1072#1087#1072#1079#1086#1085':'
        ParentShowHint = False
        ShowHint = True
      end
      object LDW: TLabel
        Left = 168
        Top = 52
        Width = 76
        Height = 13
        Caption = #1044#1080#1089#1082#1088#1077#1090#1085#1086#1089#1090#1100':'
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
          #1040#1063#1061
          #1051#1040#1063#1061
          #1060#1063#1061
          #1051#1060#1063#1061
          #1040#1060#1063#1061
          #1053#1055#1063#1061)
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
    Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100'>>'
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
