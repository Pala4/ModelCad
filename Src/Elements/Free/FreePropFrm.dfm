object FFreeProp: TFFreeProp
  Left = 583
  Top = 417
  BorderStyle = bsDialog
  Caption = #1055#1088#1086#1080#1079#1074#1086#1083#1100#1085#1072#1103' '#1085#1077#1083#1080#1085#1077#1081#1085#1086#1089#1090#1100
  ClientHeight = 104
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
  object GBxParam: TGroupBox
    Left = 7
    Top = 3
    Width = 321
    Height = 54
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099':'
    TabOrder = 0
    object LFormula: TLabel
      Left = 8
      Top = 22
      Width = 51
      Height = 13
      Caption = #1060#1086#1088#1084#1091#1083#1072':'
      ParentShowHint = False
      ShowHint = True
    end
    object EFormula: TEdit
      Left = 64
      Top = 16
      Width = 249
      Height = 21
      TabOrder = 0
    end
  end
  object BtOk: TButton
    Left = 82
    Top = 68
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 1
  end
  object BtCancel: TButton
    Left = 178
    Top = 68
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
  end
end
