object FCalcParam: TFCalcParam
  Left = 235
  Top = 116
  BorderStyle = bsDialog
  Caption = '��������� �������'
  ClientHeight = 192
  ClientWidth = 277
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
  object RGCalcAlg: TRadioGroup
    Left = 0
    Top = 0
    Width = 277
    Height = 57
    Align = alTop
    Caption = '�������� �������:'
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      '� �����������'
      '��� ����������')
    TabOrder = 0
  end
  object GBxTRegion: TGroupBox
    Left = 0
    Top = 57
    Width = 277
    Height = 80
    Align = alTop
    Caption = '��������� ��������� �������:'
    TabOrder = 1
    object LDT: TLabel
      Left = 10
      Top = 30
      Width = 92
      Height = 13
      Caption = '������������ dT:'
    end
    object LT: TLabel
      Left = 10
      Top = 54
      Width = 129
      Height = 13
      Caption = '����� ������������� T:'
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
    Caption = '��������� ��������� �������:'
    TabOrder = 2
    Visible = False
    object LDW: TLabel
      Left = 10
      Top = 30
      Width = 96
      Height = 13
      Caption = '������������ dW:'
    end
    object LW: TLabel
      Left = 10
      Top = 54
      Width = 121
      Height = 13
      Caption = '���������� ������� W:'
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
