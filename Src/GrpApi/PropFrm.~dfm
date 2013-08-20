object FProperty: TFProperty
  Left = 318
  Top = 182
  BorderStyle = bsDialog
  Caption = 'Свойства'
  ClientHeight = 217
  ClientWidth = 268
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
  object PCProp: TPageControl
    Left = 0
    Top = 0
    Width = 268
    Height = 177
    ActivePage = TSField
    Align = alTop
    TabOrder = 0
    object TSAxis: TTabSheet
      Caption = 'Оси'
      object LAxColor: TLabel
        Left = 8
        Top = 80
        Width = 55
        Height = 13
        Caption = 'Цвет осей:'
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
        Caption = 'Отображать'
        TabOrder = 0
        object ChBxAXVisible: TCheckBox
          Left = 8
          Top = 16
          Width = 113
          Height = 17
          Caption = 'Ось X(категорий)'
          Checked = True
          State = cbChecked
          TabOrder = 0
        end
        object ChBxAYVisible: TCheckBox
          Left = 8
          Top = 40
          Width = 113
          Height = 17
          Caption = 'Ось Y(значений)'
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
        Hint = 'Изменить цвет'
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
        Hint = 'Сбросить по умолчанию'
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
        Caption = 'Инвертировать'
        TabOrder = 1
        object ChBxAXInvert: TCheckBox
          Left = 8
          Top = 16
          Width = 113
          Height = 17
          Caption = 'Ось X(категорий)'
          TabOrder = 0
        end
        object ChBxAYInvert: TCheckBox
          Left = 8
          Top = 40
          Width = 113
          Height = 17
          Caption = 'Ось Y(значений)'
          TabOrder = 1
        end
      end
    end
    object TSField: TTabSheet
      Caption = 'Область построения'
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
        Caption = 'Цвет фона:'
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
        Hint = 'Сбросить по умолчанию'
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
        Caption = 'Сохранять ряды'
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
          Caption = 'Количество рядов (-1 неограниченное):'
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
    Caption = 'Дополнительно...'
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
