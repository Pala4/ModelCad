object FGrp: TFGrp
  Left = 276
  Top = 228
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
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object StBrGrp: TStatusBar
    Left = 0
    Top = 241
    Width = 462
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
    Width = 462
    Height = 241
    Align = alClient
    BorderStyle = bsNone
    TabOrder = 1
  end
  object MGrp: TMainMenu
    Left = 424
    Top = 8
    object MIFile: TMenuItem
      Caption = '&Файл'
      object MIParam: TMenuItem
        Caption = 'Параметры диаграммы...'
        ShortCut = 16463
        OnClick = MIParamClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object MIPageParam: TMenuItem
        Caption = 'Параметры страницы...'
      end
      object MIPreView: TMenuItem
        Caption = 'Предварительный просмотр...'
      end
      object MIPrint: TMenuItem
        Caption = 'Печать...'
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object MIClose: TMenuItem
        Caption = '&Закрыть'
        ShortCut = 16453
        OnClick = MICloseClick
      end
    end
    object MIEdit: TMenuItem
      Caption = '&Правка'
      OnClick = MICheckClick
      object MIClearDiagram: TMenuItem
        Caption = 'Очистить диаграмму'
        OnClick = MIClearDiagramClick
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object MICut: TMenuItem
        Caption = 'Вырезать'
        ShortCut = 16472
      end
      object MICopy: TMenuItem
        Caption = 'Копировать'
        ShortCut = 16451
        OnClick = MICopyClick
      end
      object MIPast: TMenuItem
        Caption = 'Вставить'
        ShortCut = 16470
        OnClick = MIPastClick
      end
      object MIDel: TMenuItem
        Caption = 'Удалить'
        ShortCut = 16430
        OnClick = MIDelClick
      end
      object MISelectAll: TMenuItem
        Caption = 'Выделить все'
        ShortCut = 16449
        OnClick = MISelectAllClick
      end
    end
    object MIClipBoard: TMenuItem
      Caption = 'Буфер обмена'
      OnClick = MICheckClick
      object MICBClear: TMenuItem
        Caption = 'Очистить буфер'
        OnClick = MICBClearClick
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object MICopyData: TMenuItem
        Caption = 'Копировать данные'
        OnClick = MICopyDataClick
      end
    end
  end
end
