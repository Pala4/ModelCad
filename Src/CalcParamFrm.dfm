object FCalcParam: TFCalcParam
  Left = 564
  Top = 302
  BorderStyle = bsDialog
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1088#1072#1089#1095#1105#1090#1072
  ClientHeight = 192
  ClientWidth = 277
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
  object RGCalcAlg: TRadioGroup
    Left = 0
    Top = 0
    Width = 277
    Height = 57
    Align = alTop
    Caption = #1040#1083#1075#1086#1088#1080#1090#1084' '#1088#1072#1089#1095#1105#1090#1072':'
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      #1057' '#1086#1087#1077#1088#1077#1078#1077#1085#1080#1077#1084
      #1041#1077#1079' '#1086#1087#1077#1088#1077#1078#1077#1085#1080#1103)
    TabOrder = 0
  end
  object GBxTRegion: TGroupBox
    Left = 0
    Top = 57
    Width = 277
    Height = 80
    Align = alTop
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1074#1088#1077#1084#1077#1085#1085#1086#1081' '#1086#1073#1083#1072#1089#1090#1080':'
    TabOrder = 1
    object LDT: TLabel
      Left = 10
      Top = 30
      Width = 92
      Height = 13
      Caption = #1044#1080#1089#1082#1088#1077#1090#1085#1086#1089#1090#1100' dT:'
    end
    object LT: TLabel
      Left = 10
      Top = 54
      Width = 129
      Height = 13
      Caption = #1042#1088#1077#1084#1103' '#1084#1086#1076#1077#1083#1080#1088#1086#1074#1072#1085#1080#1103' T:'
    end
    object EDT: TEdit
      Left = 146
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 0
      OnKeyPress = EKeyPress
    end
    object ET: TEdit
      Left = 146
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 1
      OnKeyPress = EKeyPress
    end
  end
  object GBxWRegion: TGroupBox
    Left = 0
    Top = 137
    Width = 277
    Height = 16
    Align = alTop
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1095#1072#1089#1090#1086#1090#1085#1086#1081' '#1086#1073#1083#1072#1089#1090#1080':'
    TabOrder = 2
    Visible = False
    object LDW: TLabel
      Left = 10
      Top = 30
      Width = 96
      Height = 13
      Caption = #1044#1080#1089#1082#1088#1077#1090#1085#1086#1089#1090#1100' dW:'
    end
    object LW: TLabel
      Left = 10
      Top = 54
      Width = 121
      Height = 13
      Caption = #1055#1088#1077#1076#1077#1083#1100#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072' W:'
    end
    object EDW: TEdit
      Left = 146
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 0
      OnKeyPress = EKeyPress
    end
    object EW: TEdit
      Left = 146
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 1
      OnKeyPress = EKeyPress
    end
  end
  object BtOk: TButton
    Left = 45
    Top = 160
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 3
    OnClick = BtOkClick
  end
  object BtCancel: TButton
    Left = 157
    Top = 160
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = BtCancelClick
  end
end
