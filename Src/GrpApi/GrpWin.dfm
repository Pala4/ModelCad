object FGrp: TFGrp
  Left = 648
  Top = 379
  Width = 470
  Height = 314
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  Menu = MGrp
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object StBrGrp: TStatusBar
    Left = 0
    Top = 237
    Width = 454
    Height = 19
    Panels = <
      item
        Width = 230
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object ScrBxGrp: TScrollBox
    Left = 0
    Top = 0
    Width = 454
    Height = 237
    Align = alClient
    BorderStyle = bsNone
    TabOrder = 1
  end
  object MGrp: TMainMenu
    Left = 424
    Top = 8
    object MIFile: TMenuItem
      Caption = '&'#1060#1072#1081#1083
      object MIParam: TMenuItem
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1076#1080#1072#1075#1088#1072#1084#1084#1099'...'
        ShortCut = 16463
        OnClick = MIParamClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object MIPageParam: TMenuItem
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1090#1088#1072#1085#1080#1094#1099'...'
      end
      object MIPreView: TMenuItem
        Caption = #1055#1088#1077#1076#1074#1072#1088#1080#1090#1077#1083#1100#1085#1099#1081' '#1087#1088#1086#1089#1084#1086#1090#1088'...'
      end
      object MIPrint: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100'...'
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object MIClose: TMenuItem
        Caption = '&'#1047#1072#1082#1088#1099#1090#1100
        ShortCut = 16453
        OnClick = MICloseClick
      end
    end
    object MIEdit: TMenuItem
      Caption = '&'#1055#1088#1072#1074#1082#1072
      OnClick = MICheckClick
      object MIClearDiagram: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1076#1080#1072#1075#1088#1072#1084#1084#1091
        OnClick = MIClearDiagramClick
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object MICut: TMenuItem
        Caption = #1042#1099#1088#1077#1079#1072#1090#1100
        ShortCut = 16472
      end
      object MICopy: TMenuItem
        Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
        ShortCut = 16451
        OnClick = MICopyClick
      end
      object MIPast: TMenuItem
        Caption = #1042#1089#1090#1072#1074#1080#1090#1100
        ShortCut = 16470
        OnClick = MIPastClick
      end
      object MIDel: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100
        ShortCut = 16430
        OnClick = MIDelClick
      end
      object MISelectAll: TMenuItem
        Caption = #1042#1099#1076#1077#1083#1080#1090#1100' '#1074#1089#1077
        ShortCut = 16449
        OnClick = MISelectAllClick
      end
    end
    object MIClipBoard: TMenuItem
      Caption = #1041#1091#1092#1077#1088' '#1086#1073#1084#1077#1085#1072
      OnClick = MICheckClick
      object MICBClear: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1073#1091#1092#1077#1088
        OnClick = MICBClearClick
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object MICopyData: TMenuItem
        Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1076#1072#1085#1085#1099#1077
        OnClick = MICopyDataClick
      end
    end
  end
end
