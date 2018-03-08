object FormRashet: TFormRashet
  Left = 192
  Top = 124
  Width = 1305
  Height = 675
  Caption = #1056#1072#1089#1095#1077#1090#1085#1099#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1099
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1289
    Height = 29
    Caption = 'ToolBar1'
    TabOrder = 0
    object BitBtn4: TBitBtn
      Left = 0
      Top = 2
      Width = 75
      Height = 22
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 0
      OnClick = BitBtn4Click
    end
    object BitBtn5: TBitBtn
      Left = 75
      Top = 2
      Width = 93
      Height = 22
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082
      TabOrder = 1
      OnClick = BitBtn5Click
    end
  end
  object Memo1: TMemo
    Left = 0
    Top = 29
    Width = 1289
    Height = 608
    Align = alClient
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object OpenDialogFileRashet: TOpenDialog
    DefaultExt = 'txt'
    Left = 672
    Top = 72
  end
  object SaveDialogFileRashet: TSaveDialog
    DefaultExt = 'txt'
    Left = 728
    Top = 72
  end
end
