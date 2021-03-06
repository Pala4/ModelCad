object FProperty: TFProperty
  Left = 740
  Top = 301
  BorderStyle = bsDialog
  Caption = #1057#1074#1086#1081#1089#1090#1074#1072
  ClientHeight = 217
  ClientWidth = 268
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
  object PCProp: TPageControl
    Left = 0
    Top = 0
    Width = 268
    Height = 177
    ActivePage = TSAxis
    Align = alTop
    TabIndex = 0
    TabOrder = 0
    object TSAxis: TTabSheet
      Caption = #1054#1089#1080
      object LAxColor: TLabel
        Left = 8
        Top = 80
        Width = 55
        Height = 13
        Caption = #1062#1074#1077#1090' '#1086#1089#1077#1081':'
      end
      object LAxCHexPref: TLabel
        Left = 64
        Top = 80
        Width = 11
        Height = 13
        Caption = '0x'
      end
      object GrBxVisible: TGroupBox
        Left = 0
        Top = 0
        Width = 127
        Height = 65
        Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100
        TabOrder = 0
        object ChBxAXVisible: TCheckBox
          Left = 8
          Top = 16
          Width = 113
          Height = 17
          Caption = #1054#1089#1100' X('#1082#1072#1090#1077#1075#1086#1088#1080#1081')'
          Checked = True
          State = cbChecked
          TabOrder = 0
        end
        object ChBxAYVisible: TCheckBox
          Left = 8
          Top = 40
          Width = 113
          Height = 17
          Caption = #1054#1089#1100' Y('#1079#1085#1072#1095#1077#1085#1080#1081')'
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
      end
      object EAxColor: TEdit
        Left = 80
        Top = 72
        Width = 121
        Height = 21
        MaxLength = 6
        TabOrder = 2
      end
      object BtAxColor: TButton
        Left = 182
        Top = 74
        Width = 17
        Height = 17
        Hint = #1048#1079#1084#1077#1085#1080#1090#1100' '#1094#1074#1077#1090
        Caption = '...'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = BtColorClick
      end
      object BtAxCDefault: TButton
        Left = 165
        Top = 74
        Width = 17
        Height = 17
        Hint = #1057#1073#1088#1086#1089#1080#1090#1100' '#1087#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
        Caption = 'D'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = BtDefaultClick
      end
      object GrBxInvert: TGroupBox
        Left = 132
        Top = 0
        Width = 127
        Height = 65
        Caption = #1048#1085#1074#1077#1088#1090#1080#1088#1086#1074#1072#1090#1100
        TabOrder = 1
        object ChBxAXInvert: TCheckBox
          Left = 8
          Top = 16
          Width = 113
          Height = 17
          Caption = #1054#1089#1100' X('#1082#1072#1090#1077#1075#1086#1088#1080#1081')'
          TabOrder = 0
        end
        object ChBxAYInvert: TCheckBox
          Left = 8
          Top = 40
          Width = 113
          Height = 17
          Caption = #1054#1089#1100' Y('#1079#1085#1072#1095#1077#1085#1080#1081')'
          TabOrder = 1
        end
      end
    end
    object TSField: TTabSheet
      Caption = #1054#1073#1083#1072#1089#1090#1100' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1103
      ImageIndex = 1
      object LFCHexPref: TLabel
        Left = 65
        Top = 24
        Width = 11
        Height = 13
        Caption = '0x'
      end
      object LFColor: TLabel
        Left = 8
        Top = 24
        Width = 57
        Height = 13
        Caption = #1062#1074#1077#1090' '#1092#1086#1085#1072':'
      end
      object EFColor: TEdit
        Left = 80
        Top = 16
        Width = 121
        Height = 21
        MaxLength = 6
        TabOrder = 0
      end
      object BtFColor: TButton
        Left = 182
        Top = 18
        Width = 17
        Height = 17
        Caption = '...'
        TabOrder = 1
        OnClick = BtColorClick
      end
      object BtFCDefault: TButton
        Left = 165
        Top = 18
        Width = 17
        Height = 17
        Hint = #1057#1073#1088#1086#1089#1080#1090#1100' '#1087#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
        Caption = 'D'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = BtDefaultClick
      end
      object CBxSaveSers: TCheckBox
        Left = 8
        Top = 48
        Width = 113
        Height = 17
        Caption = #1057#1086#1093#1088#1072#1085#1103#1090#1100' '#1088#1103#1076#1099
        TabOrder = 3
        OnClick = CBxSaveSersClick
      end
      object PNumSers: TPanel
        Left = 1
        Top = 72
        Width = 257
        Height = 41
        BevelInner = bvSpace
        BevelOuter = bvLowered
        TabOrder = 4
        object LNumSers: TLabel
          Left = 8
          Top = 12
          Width = 198
          Height = 13
          Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1088#1103#1076#1086#1074' (-1 '#1085#1077#1086#1075#1088#1072#1085#1080#1095#1077#1085#1085#1086#1077'):'
        end
        object ENumSers: TEdit
          Left = 208
          Top = 8
          Width = 41
          Height = 21
          TabOrder = 0
          OnKeyPress = ENumSersKeyPress
        end
      end
    end
  end
  object BtOK: TButton
    Left = 52
    Top = 184
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = BtOKClick
  end
  object BtCancel: TButton
    Left = 140
    Top = 184
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = BtCancelClick
  end
  object BtAdvanced: TButton
    Left = 152
    Top = 144
    Width = 105
    Height = 25
    Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086'...'
    Enabled = False
    TabOrder = 3
    OnClick = BtAdvancedClick
  end
  object CDlgProp: TColorDialog
    Ctl3D = True
    Options = [cdFullOpen]
    Left = 232
    Top = 184
  end
end
