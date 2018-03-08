object Form1: TForm1
  Left = 302
  Top = 269
  Width = 1525
  Height = 758
  Caption = 'ChartPro'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefaultSizeOnly
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnCanResize = FormCanResize
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnDestroy = FormDestroy
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 1371
    Top = 164
    Width = 3
    Height = 512
    Cursor = crHSplit
    Align = alRight
  end
  object Splitter7: TSplitter
    Left = 0
    Top = 161
    Width = 1509
    Height = 3
    Cursor = crVSplit
    Align = alTop
  end
  object GroupBox1: TGroupBox
    Left = 1374
    Top = 164
    Width = 135
    Height = 512
    Align = alRight
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 2
      Top = 15
      Width = 131
      Height = 495
      ActivePage = TabSheet1
      Align = alClient
      MultiLine = True
      TabIndex = 2
      TabOrder = 0
      object TabSheet2: TTabSheet
        Caption = #1056#1077#1078#1080#1084#1099
        ImageIndex = 1
        object FileListBox1: TFileListBox
          Left = 0
          Top = 20
          Width = 123
          Height = 429
          Align = alClient
          FileEdit = Edit1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 16
          Mask = '*.tee'
          ParentFont = False
          TabOrder = 0
          OnDblClick = FileListBox1DblClick
        end
        object Panel3: TPanel
          Left = 0
          Top = 0
          Width = 123
          Height = 20
          Align = alTop
          TabOrder = 1
          object Edit1: TEdit
            Left = -1
            Top = 0
            Width = 177
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            Text = '*.tee'
          end
        end
      end
      object TabSheet3: TTabSheet
        Caption = #1047#1085#1072#1095#1077#1085#1080#1103
        ImageIndex = 2
        object Panel11: TPanel
          Left = 0
          Top = 0
          Width = 123
          Height = 449
          Align = alClient
          Color = clBtnHighlight
          TabOrder = 0
          DesignSize = (
            123
            449)
          object LabelExample: TLabel
            Left = 8
            Top = 64
            Width = 66
            Height = 13
            Anchors = [akLeft, akTop, akRight, akBottom]
            Caption = 'LabelExample'
            Visible = False
            OnDblClick = LabelExampleDblClick
            OnMouseDown = LabelExampleMouseDown
            OnMouseMove = LabelExampleMouseMove
            OnMouseUp = LabelExampleMouseUp
          end
          object Memo1: TMemo
            Left = 8
            Top = 24
            Width = 41
            Height = 33
            BorderStyle = bsNone
            Color = clScrollBar
            Lines.Strings = (
              '')
            ReadOnly = True
            TabOrder = 0
            Visible = False
            OnMouseDown = Memo1MouseDown
            OnMouseMove = Memo1MouseMove
            OnMouseUp = Memo1MouseUp
          end
          object EditExample: TEdit
            Left = 8
            Top = 88
            Width = 1000
            Height = 21
            Constraints.MinWidth = 40
            TabOrder = 1
            Text = 'EditExample'
            Visible = False
            OnKeyPress = EditExampleKeyPress
          end
          object PanelRenameTab: TPanel
            Left = -38
            Top = 240
            Width = 297
            Height = 97
            TabOrder = 2
            Visible = False
            object Label5: TLabel
              Left = 8
              Top = 16
              Width = 59
              Height = 13
              Caption = #1057#1090#1072#1088#1086#1077' '#1080#1084#1103
            end
            object Label6: TLabel
              Left = 8
              Top = 48
              Width = 55
              Height = 13
              Caption = #1053#1086#1074#1086#1077' '#1080#1084#1103
            end
            object Edit9: TEdit
              Left = 72
              Top = 8
              Width = 217
              Height = 21
              ReadOnly = True
              TabOrder = 0
              Text = 'Edit9'
            end
            object ButtonOKRename: TButton
              Left = 128
              Top = 64
              Width = 75
              Height = 25
              Caption = #1054#1050
              TabOrder = 1
              OnClick = ButtonOKRenameClick
            end
            object Edit10: TEdit
              Left = 72
              Top = 40
              Width = 217
              Height = 21
              TabOrder = 2
              Text = 'Edit10'
            end
            object ButtonExitRename: TButton
              Left = 216
              Top = 64
              Width = 75
              Height = 25
              Caption = #1054#1090#1084#1077#1085#1072
              TabOrder = 3
              OnClick = ButtonExitRenameClick
            end
          end
        end
      end
      object TabSheet1: TTabSheet
        Caption = #1047#1085#1072#1095#1077#1085#1080#1103'('#1074#1080#1076' 2)'
        ImageIndex = 2
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 123
          Height = 449
          Align = alClient
          ColCount = 2
          FixedCols = 0
          FixedRows = 0
          TabOrder = 0
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 1509
    Height = 121
    Align = alTop
    ParentShowHint = False
    PopupMenu = PopupMenuAxis
    ShowHint = False
    TabOrder = 1
    Visible = False
    object Splitter6: TSplitter
      Left = 657
      Top = 1
      Width = 3
      Height = 119
      Cursor = crHSplit
    end
    object Splitter5: TSplitter
      Left = 432
      Top = 1
      Width = 3
      Height = 119
      Cursor = crHSplit
    end
    object Splitter4: TSplitter
      Left = 384
      Top = 1
      Width = 3
      Height = 119
      Cursor = crHSplit
    end
    object Splitter3: TSplitter
      Left = 805
      Top = 1
      Width = 3
      Height = 119
      Cursor = crHSplit
    end
    object Splitter2: TSplitter
      Left = 241
      Top = 1
      Width = 3
      Height = 119
      Cursor = crHSplit
    end
    object Panel8: TPanel
      Left = 244
      Top = 1
      Width = 140
      Height = 119
      Align = alLeft
      Caption = 'Panel8'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowFrame
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object GroupBoxMarks: TGroupBox
        Left = 1
        Top = 1
        Width = 138
        Height = 117
        Align = alClient
        TabOrder = 0
        object Label13: TLabel
          Left = 5
          Top = 16
          Width = 19
          Height = 13
          Caption = #1058#1080#1087
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label14: TLabel
          Left = 5
          Top = 48
          Width = 20
          Height = 13
          Caption = #1064#1072#1075
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label22: TLabel
          Left = 2
          Top = 102
          Width = 134
          Height = 13
          Align = alBottom
          Alignment = taCenter
          Caption = #1052#1072#1088#1082#1077#1088
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clInactiveCaptionText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Edit3: TEdit
          Left = 48
          Top = 40
          Width = 57
          Height = 21
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object CheckBoxMarks: TCheckBox
          Left = 5
          Top = 80
          Width = 78
          Height = 14
          Caption = #1052#1072#1088#1082#1077#1088#1099
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
        object ComboBox3: TComboBox
          Left = 48
          Top = 8
          Width = 57
          Height = 27
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowFrame
          Font.Height = -16
          Font.Name = 'Webdings'
          Font.Style = []
          ItemHeight = 19
          ItemIndex = 0
          ParentFont = False
          TabOrder = 2
          Text = 'a'
          Items.Strings = (
            'a'
            'b'
            'c'
            'd'
            'e'
            'f'
            'g'
            'h'
            'i'
            'j'
            'k'
            'l'
            'm'
            'n'
            'o'
            'p'
            'q'
            'r'
            's'
            't'
            'u'
            'v'
            'w'
            'x'
            'y'
            'z')
        end
      end
    end
    object Panel7: TPanel
      Left = 387
      Top = 1
      Width = 45
      Height = 119
      Align = alLeft
      Caption = 'Panel7'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowFrame
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object GroupBoxStrings: TGroupBox
        Left = 1
        Top = 1
        Width = 43
        Height = 117
        Align = alClient
        TabOrder = 0
        object ButtonCreateString: TSpeedButton
          Left = 9
          Top = 10
          Width = 27
          Height = 27
          Hint = #1053#1086#1074#1072#1103' '#1089#1090#1088#1086#1082#1072
          AllowAllUp = True
          GroupIndex = 1
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
            0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
            0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
            0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
            0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF0000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFF00
            0000000000FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF0000000000000000000000000000000000000000000000000000000000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentShowHint = False
          ShowHint = True
          OnClick = ButtonCreateStringClick
        end
        object Label21: TLabel
          Left = 2
          Top = 102
          Width = 39
          Height = 13
          Align = alBottom
          Alignment = taCenter
          Caption = #1057#1090#1088#1086#1082#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clInactiveCaptionText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
      end
    end
    object Panel6: TPanel
      Left = 660
      Top = 1
      Width = 145
      Height = 119
      Align = alLeft
      Caption = 'Panel6'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowFrame
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      object GroupBoxArg: TGroupBox
        Left = 1
        Top = 1
        Width = 143
        Height = 117
        Align = alClient
        TabOrder = 0
        object Label16: TLabel
          Left = 8
          Top = 8
          Width = 42
          Height = 13
          Caption = #1060#1086#1088#1084#1072#1090
        end
        object Label17: TLabel
          Left = 0
          Top = 48
          Width = 139
          Height = 13
          Caption = #1063#1080#1089#1083#1086' '#1083#1080#1085#1080#1081' '#1089' '#1086#1094#1080#1092#1088#1086#1074#1082#1086#1081
        end
        object Label20: TLabel
          Left = 2
          Top = 102
          Width = 139
          Height = 13
          Align = alBottom
          Alignment = taCenter
          Caption = #1040#1088#1075#1091#1084#1077#1085#1090
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clInactiveCaptionText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object ComboBox2: TComboBox
          Left = 8
          Top = 24
          Width = 121
          Height = 21
          Hint = #1060#1086#1088#1084#1072#1090' '#1072#1088#1075#1091#1084#1077#1085#1090#1072
          Enabled = False
          ItemHeight = 13
          ItemIndex = 0
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          Text = #1063#1063':'#1052#1052':'#1057#1057
          Items.Strings = (
            #1063#1063':'#1052#1052':'#1057#1057
            #1057#1077#1082#1091#1085#1076#1099)
        end
        object EditMinorCount: TCSpinEdit
          Left = 6
          Top = 64
          Width = 123
          Height = 22
          Enabled = False
          MaxValue = 20
          MinValue = 1
          TabOrder = 1
          OnChange = CSpinEditMinorCountChange
          OnKeyPress = EditKolVertLinesKeyPress
        end
      end
    end
    object Panel5: TPanel
      Left = 435
      Top = 1
      Width = 222
      Height = 119
      Align = alLeft
      Caption = 'Panel5'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowFrame
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      object GroupBox5: TGroupBox
        Left = 1
        Top = 1
        Width = 220
        Height = 117
        Align = alClient
        ParentShowHint = False
        ShowHint = False
        TabOrder = 0
        object SpeedButtonGridEnable: TSpeedButton
          Left = 8
          Top = 56
          Width = 27
          Height = 27
          Hint = #1056#1091#1095#1085#1072#1103' '#1085#1072#1089#1090#1088#1086#1081#1082#1072' '#1089#1077#1090#1082#1080
          AllowAllUp = True
          GroupIndex = 1
          Glyph.Data = {
            B6020000424DB60200000000000076000000280000002F000000180000000100
            0400000000004002000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
            8888888888888888888888888888888888808877777777777777777777787888
            888888888888888888808F888888888888888888887878888888888888888888
            88808F88888888888888888888787880000000000000000008808F8000000000
            0000000008787880888808880888088808808F80888808880888088808787880
            888808880888088808808F808888088808880888087878807777000000000000
            08808F80777700000000000008787880888808880888088808808F8088880888
            0888088808787880888808880888088808808F80888808880888088808787880
            777700000000000008808F807777000000000000087878808888088808880888
            08808F80888808880888088808787880888808880888088808808F8088880888
            0888088808787880777700000000000008808F80777700000000000008787880
            888808880888088808808F808888088808880888087878808888088808880888
            08808F80888808880888088808787880777700000000000008808F8077770000
            0000000008787880888878887888788808808F80888878887888788808787880
            888878887888788808808F808888788878887888087878800000000000000000
            08808F80000000000000000008787888888888888888888888808F8888888888
            8888888888787888888888888888888888808F88888888888888888888787888
            888888888888888888808FFFFFFFFFFFFFFFFFFFFF8877777777777777777777
            7780888888888888888888888888888888888888888888888880}
          NumGlyphs = 2
          ParentShowHint = False
          ShowHint = True
          OnClick = SpeedButtonGridEnableClick
        end
        object Label3: TLabel
          Left = 8
          Top = 40
          Width = 102
          Height = 13
          Caption = #1050#1086#1083'-'#1074#1086' '#1075#1086#1088#1080#1079'. '#1087#1086#1083#1086#1089
        end
        object Label4: TLabel
          Left = 8
          Top = 16
          Width = 96
          Height = 13
          Caption = #1050#1086#1083'-'#1074#1086' '#1074#1077#1088#1090'. '#1087#1086#1083#1086#1089
        end
        object Label19: TLabel
          Left = 2
          Top = 102
          Width = 216
          Height = 13
          Align = alBottom
          Alignment = taCenter
          Caption = #1057#1077#1090#1082#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clInactiveCaptionText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object GroupBoxMargins: TGroupBox
          Left = 210
          Top = 8
          Width = 137
          Height = 89
          Caption = #1055#1086#1083#1077
          TabOrder = 0
          Visible = False
          object CSpinEditLeft: TCSpinEdit
            Left = 8
            Top = 35
            Width = 41
            Height = 22
            Enabled = False
            TabOrder = 0
            OnChange = CSpinEditLeftChange
            OnKeyPress = EditKolVertLinesKeyPress
          end
          object CSpinEditBottom: TCSpinEdit
            Left = 48
            Top = 59
            Width = 41
            Height = 22
            Enabled = False
            TabOrder = 1
            OnChange = CSpinEditBottomChange
            OnKeyPress = EditKolVertLinesKeyPress
          end
          object CSpinEditTop: TCSpinEdit
            Left = 48
            Top = 11
            Width = 41
            Height = 22
            Enabled = False
            TabOrder = 2
            OnChange = CSpinEditTopChange
            OnKeyPress = EditKolVertLinesKeyPress
          end
          object CSpinEditRight: TCSpinEdit
            Left = 88
            Top = 35
            Width = 41
            Height = 22
            Enabled = False
            TabOrder = 3
            OnChange = CSpinEditRightChange
            OnKeyPress = EditKolVertLinesKeyPress
          end
        end
        object EditKolVertLines: TCSpinEdit
          Left = 120
          Top = 8
          Width = 81
          Height = 22
          Enabled = False
          MaxValue = 60
          MinValue = 1
          TabOrder = 1
          OnChange = EditKolVertLinesChange
          OnKeyPress = EditKolVertLinesKeyPress
        end
        object EditKolHorizLines: TCSpinEdit
          Left = 120
          Top = 32
          Width = 81
          Height = 22
          Enabled = False
          MaxValue = 60
          MinValue = 1
          TabOrder = 2
          OnChange = EditKolHorizLinesChange
          OnKeyPress = EditKolVertLinesKeyPress
        end
      end
    end
    object Panel9: TPanel
      Left = 808
      Top = 1
      Width = 700
      Height = 119
      Align = alClient
      Caption = 'Panel9'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowFrame
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      object GroupBoxFlags: TGroupBox
        Left = 1
        Top = 1
        Width = 698
        Height = 117
        Align = alClient
        DockSite = True
        TabOrder = 0
        object Label23: TLabel
          Left = 2
          Top = 102
          Width = 694
          Height = 13
          Align = alBottom
          Alignment = taCenter
          Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clInactiveCaptionText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label2: TLabel
          Left = 7
          Top = 69
          Width = 39
          Height = 13
          Caption = 'Label2'
          Color = clInactiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold, fsUnderline]
          ParentColor = False
          ParentFont = False
          Visible = False
        end
        object Label1: TLabel
          Left = 7
          Top = 58
          Width = 39
          Height = 13
          Caption = 'Label1'
          Color = clInactiveCaption
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold, fsUnderline]
          ParentColor = False
          ParentFont = False
          Visible = False
        end
        object CheckBoxEndIdent: TCheckBox
          Left = 9
          Top = 20
          Width = 152
          Height = 13
          Caption = #1048#1076#1077#1085#1090#1080#1092#1080#1082#1072#1090#1086#1088#1099' '#1074' '#1082#1086#1085#1094#1077
          Enabled = False
          TabOrder = 0
          OnClick = CheckBoxEndIdentClick
        end
        object CheckBox1: TCheckBox
          Left = 8
          Top = 40
          Width = 185
          Height = 17
          Caption = #1055#1088#1086#1088#1080#1089#1086#1074#1082#1072' '#1074#1089#1077#1093' '#1090#1086#1095#1077#1082' '#1075#1088#1072#1092#1080#1082#1072
          Checked = True
          Enabled = False
          State = cbChecked
          TabOrder = 1
          OnClick = CheckBox1Click
        end
        object EditMin: TEdit
          Left = 54
          Top = 72
          Width = 41
          Height = 17
          BorderStyle = bsNone
          Color = clSkyBlue
          TabOrder = 2
          Text = 'EditMin'
          Visible = False
          OnKeyPress = EditMaxKeyPress
        end
        object EditMax: TEdit
          Left = 54
          Top = 56
          Width = 41
          Height = 17
          BorderStyle = bsNone
          Color = clSkyBlue
          TabOrder = 3
          Text = 'EditMax'
          Visible = False
          OnKeyPress = EditMaxKeyPress
        end
        object ButtonMinMaxOk: TButton
          Left = 96
          Top = 56
          Width = 25
          Height = 17
          Caption = 'OK'
          TabOrder = 4
          Visible = False
          OnClick = ButtonMinMaxOkClick
        end
        object Panel12: TPanel
          Left = 200
          Top = 0
          Width = 313
          Height = 89
          Caption = #1042#1088#1077#1084#1077#1085#1085#1086
          TabOrder = 5
          object TeeCommander1: TTeeCommander
            Left = 1
            Top = 1
            Width = 311
            Height = 34
            Panel = Chart1
            Align = alTop
            ParentShowHint = False
            TabOrder = 0
          end
          object Button3: TButton
            Left = 238
            Top = 56
            Width = 67
            Height = 25
            Caption = '3 '#1085#1072#1076#1087#1080#1089#1080
            TabOrder = 1
            OnClick = Button3Click
          end
          object Edit7: TEdit
            Left = 264
            Top = 40
            Width = 33
            Height = 21
            TabOrder = 2
            Text = '-11'
          end
          object Edit5: TEdit
            Left = 232
            Top = 40
            Width = 33
            Height = 21
            TabOrder = 3
            Text = '8'
          end
          object Edit2: TEdit
            Left = 200
            Top = 40
            Width = 33
            Height = 21
            Enabled = False
            TabOrder = 4
            Text = '72'
          end
          object Edit6: TEdit
            Left = 24
            Top = 60
            Width = 121
            Height = 21
            BiDiMode = bdLeftToRight
            Ctl3D = True
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowFrame
            Font.Height = -12
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentBiDiMode = False
            ParentCtl3D = False
            ParentFont = False
            ParentShowHint = False
            ShowHint = False
            TabOrder = 5
            Text = 'Edit6'
          end
        end
        object EditInfo: TEdit
          Left = 6
          Top = 88
          Width = 363
          Height = 25
          BorderStyle = bsNone
          Color = clSkyBlue
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowFrame
          Font.Height = -20
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          Text = #1044#1083#1103' '#1086#1089#1090#1072#1085#1086#1074#1082#1080' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1103' '#1085#1072#1078#1084#1080#1090#1077' Q'
          Visible = False
          OnKeyPress = EditMaxKeyPress
        end
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 240
      Height = 119
      Align = alLeft
      Caption = 'Panel4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowFrame
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      object GroupBox8: TGroupBox
        Left = 1
        Top = 1
        Width = 238
        Height = 117
        Align = alClient
        ParentShowHint = False
        ShowHint = False
        TabOrder = 0
        object SpeedButtonStretch: TSpeedButton
          Left = 104
          Top = 40
          Width = 31
          Height = 31
          Hint = #1056#1072#1089#1090#1103#1075#1080#1074#1072#1085#1080#1077' '#1096#1082#1072#1083#1099
          AllowAllUp = True
          GroupIndex = 2
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            04000000000080000000120B0000120B00001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666606666
            6666666666090666666666666609066666666666609990666666666660999066
            6666666600090006666666666609066666666666660906666666666666090666
            6666666600090006666666666099906666666666609990666666666666090666
            6666666666090666666666666660666666666666666066666666}
          ParentShowHint = False
          ShowHint = True
          OnMouseDown = SpeedButtonMoveMouseDown
        end
        object Label18: TLabel
          Left = 2
          Top = 102
          Width = 234
          Height = 13
          Align = alBottom
          Alignment = taCenter
          Caption = #1064#1082#1072#1083#1099' '#1080' '#1075#1088#1072#1092#1080#1082#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clInactiveCaptionText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object SpeedButtonMove: TSpeedButton
          Left = 8
          Top = 40
          Width = 31
          Height = 31
          Hint = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077' '#1096#1082#1072#1083#1099
          AllowAllUp = True
          GroupIndex = 2
          Down = True
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            333333333333333FFF3333333333333707333333333333F777F3333333333370
            F033333333F33F7737F333333733370F0733333337F3F77377333333300370F0
            73333333377F77377333333330F00F073333333337377377333333330FFFF073
            333333337F333773333333330FFFF03333333333733337F333333330FFFFFF03
            33333337F3333F7FF3333330FFFFF00733333337333FF7773333330FFFF00333
            3333337F3FF773333333330FF00333333333337FF7733333333330F003333333
            333337F773333333333330033333333333333773333333333333333333333333
            3333333333333333333333333333333333333333333333333333}
          NumGlyphs = 2
          ParentShowHint = False
          ShowHint = True
          OnMouseDown = SpeedButtonMoveMouseDown
        end
        object SpeedButtonMaxMin: TSpeedButton
          Left = 40
          Top = 40
          Width = 31
          Height = 31
          Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' Max Min '#1096#1082#1072#1083#1099
          AllowAllUp = True
          GroupIndex = 2
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000130B0000130B00001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
            FFFFF7777777777777F3FFFFFFFFFFFFFFFFF7F33F333F3337F3F0FFF0FF0FF0
            FF0FF7F37F337F3337F3F0FFF0FF0FF0F00FF7F37FFF7FFF37F3F0F0F0FF0FF0
            000FF7F77777777337F3F00000FF0FF00F0FF7F337F337F337F3F00F00FFFFF0
            FF0FF7F337FFF7FFF7F3F0FFF0FF0FF0FF0FF7F37777777737F3FFFFFFFFFFFF
            FFFFF7F3337F337F37F3F0FFF0F0FF0F0FF0F7F33373337337F3F0FFF0F0FF0F
            0FF0F7F33333333FF7F3F0F0F0F0000FF00FF7F33333337777F3F00000F0FF0F
            F00FF7FFFFFFFF7F3733F00F00F0FF0F0FF0F7777777777F7333F0FFF0FF00FF
            0FF0F7FFFFFFFF773333FFFFFFFFFFFFFFFFF777777777733333}
          NumGlyphs = 2
          ParentShowHint = False
          ShowHint = True
        end
        object SpeedButtonAddInc: TSpeedButton
          Left = 72
          Top = 40
          Width = 31
          Height = 31
          Hint = #1059#1074#1077#1083#1080#1095#1077#1085#1080#1077' '#1096#1082#1072#1083#1099
          AllowAllUp = True
          GroupIndex = 2
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333000333
            3333333333777F33333333333309033333333333337F7F333333333333090333
            33333333337F7F33333333333309033333333333337F7F333333333333090333
            33333333337F7F33333333333309033333333333FF7F7FFFF333333000090000
            3333333777737777F333333099999990333333373F3333373333333309999903
            333333337F33337F33333333099999033333333373F333733333333330999033
            3333333337F337F3333333333099903333333333373F37333333333333090333
            33333333337F7F33333333333309033333333333337373333333333333303333
            333333333337F333333333333330333333333333333733333333}
          NumGlyphs = 2
          ParentShowHint = False
          ShowHint = True
          OnMouseDown = SpeedButtonMoveMouseDown
        end
        object SpeedButtonDelete: TSpeedButton
          Left = 136
          Top = 40
          Width = 31
          Height = 31
          Hint = #1059#1076#1072#1083#1077#1085#1080#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1072
          AllowAllUp = True
          GroupIndex = 2
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333000000000
            3333333777777777F3333330F777777033333337F3F3F3F7F3333330F0808070
            33333337F7F7F7F7F3333330F080707033333337F7F7F7F7F3333330F0808070
            33333337F7F7F7F7F3333330F080707033333337F7F7F7F7F3333330F0808070
            333333F7F7F7F7F7F3F33030F080707030333737F7F7F7F7F7333300F0808070
            03333377F7F7F7F773333330F080707033333337F7F7F7F7F333333070707070
            33333337F7F7F7F7FF3333000000000003333377777777777F33330F88877777
            0333337FFFFFFFFF7F3333000000000003333377777777777333333330777033
            3333333337FFF7F3333333333000003333333333377777333333}
          NumGlyphs = 2
          ParentShowHint = False
          ShowHint = True
          OnMouseDown = SpeedButtonMoveMouseDown
        end
        object SpeedButton1: TSpeedButton
          Left = 168
          Top = 40
          Width = 31
          Height = 31
          Hint = #1057#1076#1077#1083#1072#1090#1100' '#1096#1082#1072#1083#1091' '#1085#1077#1074#1080#1076#1080#1084#1086#1081
          AllowAllUp = True
          GroupIndex = 2
          Enabled = False
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            1800000000000003000000000000000000000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBF7F7F7FBFBFBFBFBF
            BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBF7F7F7F3F3F3F7F7F7F7F
            7F7F7F7F7FBFBFBFBFBFBFFFFFFF3F3F3FFFFFFFFFFFFFFFFFFFFFFFFFBFBFBF
            0000007F7F7FFFFFFFFFFFFFBFBFBFFFFFFFFFFFFFFFFFFF7F7F7F000000BFBF
            BFBFBFBFFFFFFFFFFFFF3F3F3F3F3F3FBFBFBFBFBFBF000000000000BFBFBF7F
            7F7FFFFFFF3F3F3F000000BFBFBFFFFFFF7F7F7FFFFFFFFFFFFF0000003F3F3F
            3F3F3F3F3F3F0000000000000000000000000000003F3F3FBFBFBFBFBFBF7F7F
            7FFFFFFFFFFFFFFFFFFF00000000000000000000000000000000000000000000
            00007F7F7FFFFFFF7F7F7F3F3F3FFFFFFFFFFFFFFFFFFFFFFFFF000000000000
            0000000000000000000000000000007F7F7F0000003F3F3FBFBFBFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000003F
            3F3FBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F7F7F7F
            7F7F7F7F7F7F7F7F7FBFBFBFBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF7F7F7F7F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBF7F
            7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7FBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FF7F7F7F000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF7F7F7F000000000000000000BFBFBFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBF7F7F7F0000000000000000
            00000000BFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F7F7F7F00
            00000000000000000000000000007F7F7FFFFFFFFFFFFFFFFFFF000000000000
            0000000000000000000000000000000000000000003F3F3F7F7F7FFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentShowHint = False
          ShowHint = True
        end
        object ColorBoxLine: TColorBox
          Left = 120
          Top = 8
          Width = 81
          Height = 22
          Hint = #1062#1074#1077#1090' '#1096#1082#1072#1083#1099' '#1080' '#1075#1088#1072#1092#1080#1082#1072
          Style = [cbStandardColors]
          Color = clSilver
          ItemHeight = 16
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object ComboBoxLineWidth: TComboBoxEx
          Left = 8
          Top = 8
          Width = 49
          Height = 22
          Hint = #1058#1086#1083#1097#1080#1085#1072' '#1083#1080#1085#1080#1080' '#1075#1088#1072#1092#1080#1082#1072
          ItemsEx.CaseSensitive = False
          ItemsEx.SortType = stNone
          ItemsEx = <
            item
              Caption = '0'
            end
            item
              Caption = '1'
            end
            item
              Caption = '2'
            end
            item
              Caption = '3'
            end
            item
              Caption = '4'
            end
            item
              Caption = '5'
            end
            item
              Caption = '6'
            end
            item
              Caption = '7'
            end
            item
              Caption = '8'
            end
            item
              Caption = '9'
            end>
          StyleEx = []
          Color = clSilver
          Ctl3D = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowFrame
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 16
          ParentCtl3D = False
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          Text = '1'
          OnBeginEdit = ComboBoxLineWidthBeginEdit
          OnClick = ComboBoxLineWidthClick
          OnKeyPress = EditKolVertLinesKeyPress
          DropDownCount = 8
        end
        object ComboBoxLineType: TComboBox
          Left = 56
          Top = 8
          Width = 65
          Height = 22
          Hint = #1058#1080#1087' '#1083#1080#1085#1080#1080' '#1075#1088#1072#1092#1080#1082#1072
          Style = csOwnerDrawFixed
          Color = clSilver
          ItemHeight = 16
          ItemIndex = 2
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
          Text = ' '
          OnDrawItem = ComboBoxLineTypeDrawItem
          OnSelect = ComboBoxLineTypeSelect
          Items.Strings = (
            ''
            ' '
            ' '
            ' '
            ' '
            ' '
            ' ')
        end
        object BottonFont: TBitBtn
          Left = 200
          Top = 40
          Width = 31
          Height = 31
          Hint = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1096#1090#1088#1080#1092#1090#1072' '#1086#1089#1080
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          OnClick = BottonFontClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000130B0000130B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333333333333333333333333333333333FFF33FFFFF33333300033000
            00333337773377777333333330333300033333337FF33777F333333330733300
            0333333377FFF777F33333333700000073333333777777773333333333033000
            3333333337FF777F333333333307300033333333377F777F3333333333703007
            33333333377F7773333333333330000333333333337777F33333333333300003
            33333333337777F3333333333337007333333333337777333333333333330033
            3333333333377333333333333333033333333333333733333333333333333333
            3333333333333333333333333333333333333333333333333333}
          NumGlyphs = 2
        end
        object CheckBoxMouse: TCheckBox
          Left = 8
          Top = 80
          Width = 121
          Height = 17
          Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1084#1099#1096#1100#1102
          TabOrder = 4
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 676
    Width = 1509
    Height = 24
    Align = alBottom
    TabOrder = 2
    OnCanResize = Panel1CanResize
    object SplitterStart: TSplitter
      Left = 31
      Top = 1
      Width = 3
      Height = 22
      Cursor = crHSplit
      AutoSnap = False
      ResizeStyle = rsUpdate
      OnCanResize = SplitterStartCanResize
      OnMoved = SplitterStartMoved
    end
    object SplitterEnd: TSplitter
      Left = 1474
      Top = 1
      Width = 4
      Height = 22
      Cursor = crHSplit
      Align = alRight
      AutoSnap = False
      ResizeStyle = rsUpdate
      OnCanResize = SplitterEndCanResize
      OnMoved = SplitterEndMoved
    end
    object PanelStart: TPanel
      Left = 1
      Top = 1
      Width = 30
      Height = 22
      Align = alLeft
      Constraints.MinWidth = 30
      TabOrder = 0
      object LabelStartTime: TLabel
        Left = -6
        Top = 2
        Width = 36
        Height = 13
        Caption = '0:00:00'
        Color = clInfoBk
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMenuText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
    end
    object PanelEnd: TPanel
      Left = 1478
      Top = 1
      Width = 30
      Height = 22
      Align = alRight
      Anchors = [akLeft, akTop, akBottom]
      Constraints.MinWidth = 30
      TabOrder = 1
      OnClick = PanelEndClick
      DesignSize = (
        30
        22)
      object LabelEndTime: TLabel
        Left = -6
        Top = 1
        Width = 36
        Height = 13
        Anchors = [akTop, akRight]
        Caption = '0:00:00'
        Color = clInfoBk
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMenuText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
    end
    object PanelScroll: TPanel
      Left = 34
      Top = 1
      Width = 1440
      Height = 22
      Align = alClient
      Anchors = [akLeft, akTop, akBottom]
      Caption = ' <- -> '
      Color = clActiveCaption
      Constraints.MinWidth = 10
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnMouseDown = PanelScrollMouseDown
      OnMouseMove = PanelScrollMouseMove
      OnMouseUp = PanelScrollMouseUp
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 121
    Width = 1509
    Height = 40
    ButtonHeight = 31
    ButtonWidth = 25
    Caption = 'ToolBar1'
    EdgeBorders = [ebLeft, ebTop]
    Images = ImageList1
    TabOrder = 3
    object buttonOpenFlyingFile: TSpeedButton
      Left = 0
      Top = 2
      Width = 31
      Height = 31
      Action = AOpenFlyingFile
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Caption = ' '
      Flat = True
      Glyph.Data = {
        2A020000424D2A020000000000002A0100002800000010000000100000000100
        08000000000000010000120B0000120B00003D00000000000000000099000066
        9900006A9D00006EA1000072A6000076AA00007AAE00007BAE00007FB2000080
        B4000083B6000087BA000088BB00008BBE00008DC000008FC2000094C7000094
        C8000096C9000098CB00009ACD00009BCF00009CCF00009DD00000A0D30000A3
        D60000A4D70000A5D80000A8DB0000A9DC0000ADE00000AEE10000AFE30000B1
        E50000B3E60000B5E80000B5E90000B9ED0000BEF10000C2F50000C6F90002CD
        FF000ED1FF0017D4FF001BD5FF0027DAFF002DDBFF0034DEFF0041E2FF0042E3
        FF004DE6FF0058EAFF005AEAFF0067EFFF006EF1FF0073F3FF0080F7FF0083F8
        FF008CFBFF0099FFFF00C0C0C0000D0B0A080605040302010101013C3C3C1332
        302F2D2C2A2929292929013C3C3C0716353432302F2D2C2A292929013C3C091B
        3837353432302F2D2C2A29033C3C0C2B1E3B3A3837353432302F2D2C053C0F2E
        243B3B3B3A3837353432302F083C113131253B3B3B3B3B3A38373534320B1533
        3328272625241E1D1B181613100F1936363636363636363636360E3C3C3C1C39
        39393939391715141312113C3C3C203B3B3B3B3B1A3C3C3C3C3C3C3C3C3C3C23
        2221201F3C3C3C3C3C3C0000003C3C3C3C3C3C3C3C3C003C3C3C3C00003C3C3C
        3C3C3C3C3C3C003C3C3C003C003C3C3C3C3C3C3C3C3C3C0000003C3C3C3C3C3C
        3C3C3C3C3C3C3C3C3C3C3C3C3C3C}
      Layout = blGlyphRight
      ParentShowHint = False
      ShowHint = True
    end
    object buttonOpenINI: TSpeedButton
      Left = 31
      Top = 2
      Width = 31
      Height = 31
      Action = AOpenINI
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Caption = ' '
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C40E0000C40E00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C000000000000000000000000000000000000000
        0000000000000000000000000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0000000
        0000009999999999999999999999999999999999999999999999999999990000
        00C0C0C0C0C0C0C0C0C0C0C0C0000000FFFF0000000099999999999999999999
        9999999999999999999999999999999999000000C0C0C0C0C0C0C0C0C0000000
        FFFF00FFFF000000009999999999999999999999999999999999999999999999
        99999999000000C0C0C0C0C0C0000000FFFF00FFFF00FFFF0000000000000000
        0000000000000000000000000000000000000000000000000000C0C0C0000000
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF000000
        00C0C0C0C0C0C0C0C0C0C0C0C0000000FFFF00FFFF0000000000000000000000
        0000000000000000000000000000000000C0C0C0C0C0C0C0C0C0C0C0C0000000
        FFFF00FFFF00000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0000000000000000000000000C0C0C000000000
        0000000000000000000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C000000000FFFF00FFFF00FFFF000000000000C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C000000000
        FFFF00FFFF00FFFF00000000FFFF000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C000000000FFFF00FFFF00FFFF00000000FFFF0000
        00C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C000000000
        000000000000000000000000FFFF000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C000000000FFFF00FFFF00FFFF0000000000
        00C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0000000000000000000000000000000C0C0C0C0C0C0C0C0C0}
      Layout = blGlyphRight
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButton5: TToolButton
      Left = 62
      Top = 2
      Width = 8
      Caption = 'ToolButton5'
      ImageIndex = 4
      Style = tbsDivider
    end
    object buttonPrint: TSpeedButton
      Left = 70
      Top = 2
      Width = 31
      Height = 31
      Hint = #1055#1077#1095#1072#1090#1100
      Action = ChartActionPrint1
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Caption = ' '
      Flat = True
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000FF00FF0000000000BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF000000000000000000BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF0000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000000000000000000000000000FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF000000000000000000BFBF
        BF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBF
        BF00FFFFFF00BFBFBF00FFFFFF000000FF00FFFFFF000000000000000000FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF0000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF0000000000000000000000000000000000FFFF
        FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF00000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF0000000000BFBFBF00FFFFFF0000000000FFFF
        FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00000000000000000000000000000000000000000000000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphRight
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButton3: TToolButton
      Left = 101
      Top = 2
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 4
      Style = tbsDivider
    end
    object buttonSlowBuilt: TSpeedButton
      Left = 109
      Top = 2
      Width = 31
      Height = 31
      Hint = #1055#1086#1089#1090#1088#1086#1077#1085#1080#1077
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Flat = True
      Glyph.Data = {
        C6000000424DC600000000000000460000002800000010000000100000000100
        040000000000800000006B0B00006B0B00000400000004000000FFFFFF00C0C0
        C000521018000000000011111111111111111111111111111111111111111111
        1111111111311111111111111033111111111111102331111111111110223311
        1111111110222331111111111022222111111111102222111111111110222111
        1111111110221111111111111021111111111111111111111111111111111111
        11111111111111111111}
      ParentShowHint = False
      ShowHint = True
      OnClick = buttonSlowBuiltClick
    end
    object buttonFastBuilt: TSpeedButton
      Left = 140
      Top = 2
      Width = 31
      Height = 31
      Hint = #1041#1099#1089#1090#1088#1086#1077' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1077
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Flat = True
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        040000000000800000006B0B00006B0B00001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8888888888888888888888888888888888888888899888888888888889998888
        8888888889999888888888888999998888888888899999988888888889999998
        8888888889999988888888888999988888888888899988888888888889988888
        8888888888888888888888888888888888888888888888888888}
      ParentShowHint = False
      ShowHint = True
      OnClick = buttonFastBuiltClick
    end
    object Panel10: TPanel
      Left = 171
      Top = 2
      Width = 71
      Height = 31
      Caption = 'Panel10'
      Color = clGradientActiveCaption
      TabOrder = 2
      object CheckBoxWithTime: TCheckBox
        Left = 0
        Top = 0
        Width = 71
        Height = 31
        Hint = #1053#1072#1078#1084#1080#1090#1077', '#1095#1090#1086#1073#1099' '#1074#1099#1089#1090#1072#1074#1080#1090#1100' '#1080#1085#1090#1077#1088#1074#1072#1083' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1103
        Caption = #1048#1085#1090#1077#1088#1074#1072#1083
        Constraints.MinHeight = 31
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -8
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = CheckBoxWithTimeClick
      end
      object EditStartTime: TEdit
        Left = 71
        Top = 0
        Width = 88
        Height = 21
        TabOrder = 1
        Text = 'EditStartTime'
      end
      object EditEndTime: TEdit
        Left = 159
        Top = 0
        Width = 88
        Height = 21
        TabOrder = 2
        Text = 'EditEndTime'
      end
    end
    object buttonFullTime: TSpeedButton
      Left = 242
      Top = 2
      Width = 31
      Height = 31
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Flat = True
      Glyph.Data = {
        6E070000424D6E0700000000000036000000280000001B000000160000000100
        18000000000038070000C30E0000C30E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
        0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFF000066
        000000000000000000FFB666FFFFFF0066B6000000000000B66600FFFFFFFFFF
        FF0066B6000000000000B66600FFFFFFDBFFFF003A90FFB666FFFFFF90DBFF00
        003A000000FFB666FFFFFF000000FFFFFFFFFFFF3A90DB660000FFFFB6FFFFFF
        66B6FF3A0000FFDB9090DBFF00003AFFB66666B6FF3A0000FFDB9090DBFF0000
        3AFFB666FFFFFF90DBFF66003AFFFFB63A90DBB6660066B6FFB66600FFFFFF00
        0000FFFFFFFFFFFF3A90DB660000FFFFB6FFFFFF3A90DB903A00FFFFDBDBFFFF
        003A90B666003A90DB903A00FFFFDBDBFFFF003A90B66600FFFFFFFFFFFF66B6
        FF903A003A90B6B6660066B6FFB66600FFFFFF000000FFFFFFFFFFFF3A90DB66
        0000FFFFB6FFFFFF0066B6903A00FFFFDBDBFFFF003A90B666000066B6903A00
        FFFFDBDBFFFF003A90B6660066B6FF0000003A00003A666690903A0000660000
        00FFB666FFFFFF000000FFFFFFFFFFFF3A90DB660000FFFFB6FFFFFF3A90DB90
        3A00FFFFDBDBFFFF003A90B666003A90DB903A00FFFFDBDBFFFF003A90B66600
        0066B6DB903A3A90DBB6903A003A90FFB666FFFFFFFFFFFFFFFFFF000000FFFF
        FF6600663A9090660000FFFFB6FFFFFF66B6FF3A0000FFDB90B6FFFF000066FF
        B66666B6FF3A0000FFDB90B6FFFF000066FFB6660066B6FFB6663A90DBDB903A
        B6FFFF660066FFFFB6FFFFFFFFFFFF000000FFFFFFB6FFFF000066660000FFFF
        B6FFFFFFFFFFFF3A90DB000000000000903A00FFFFDBFFFFFF3A90DB00000000
        0000903A00FFFFDB66B6FF0000003A0000FFDB90FFFFFF66B6FF903A00FFFFDB
        FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
        0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000}
      OnClick = buttonFullTimeClick
    end
    object buttonZoomIn: TSpeedButton
      Left = 273
      Top = 2
      Width = 31
      Height = 31
      Hint = #1059#1074#1077#1083#1080#1095#1077#1085#1080#1077' '#1092#1088#1072#1075#1084#1077#1085#1090#1072' '#1075#1088#1072#1092#1080#1082#1072
      AllowAllUp = True
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      GroupIndex = 2
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        33033333333333333F7F3333333333333000333333333333F777333333333333
        000333333333333F777333333333333000333333333333F77733333333333300
        033333333FFF3F777333333700073B703333333F7773F77733333307777700B3
        33333377333777733333307F8F8F7033333337F333F337F3333377F8F9F8F773
        3333373337F3373F3333078F898F870333337F33F7FFF37F333307F99999F703
        33337F377777337F3333078F898F8703333373F337F33373333377F8F9F8F773
        333337F3373337F33333307F8F8F70333333373FF333F7333333330777770333
        333333773FF77333333333370007333333333333777333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = buttonZoomInClick
    end
    object ToolButton10: TToolButton
      Left = 304
      Top = 2
      Width = 8
      Caption = 'ToolButton10'
      ImageIndex = 9
      Style = tbsDivider
    end
    object SpeedButton10: TSpeedButton
      Left = 312
      Top = 2
      Width = 31
      Height = 31
      Hint = #1057#1086#1093#1088#1072#1085#1077#1085#1080#1077' '#1075#1088#1072#1092#1080#1095#1077#1089#1082#1086#1075#1086' '#1086#1082#1085#1072
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Enabled = False
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
        9989779989779989779989779989779989779989779989779989779989779989
        77998977998977998977FFFFFFD3B7BB70384070384070384070384070384070
        3840703840703840703840703840703840703840703840998977FFFFFFD06870
        F09090E08080B04820403020C0B8B0C0B8B0D0C0C0D0C8C0505050A04030A040
        30A03830703840998977FFFFFFD07070FF98A0F08880E0808070585040403090
        7870F0E0E0F0E8E0908070A04030A04040A04030703840998977FFFFFFD07870
        FFA0A0F09090F08880705850000000404030F0D8D0F0E0D0807860B04840B048
        40A04040703840998977FFFFFFD07880FFA8B0FFA0A0F0909070585070585070
        5850705850706050806860C05850B05050B04840703840998977FFFFFFE08080
        FFB0B0FFB0B0FFA0A0F09090F08880E08080E07880D07070D06870C06060C058
        50B05050703840998977FFFFFFE08890FFB8C0FFB8B0D06060C06050C05850C0
        5040B05030B04830A04020A03810C06060C05850703840998977FFFFFFE09090
        FFC0C0D06860FFFFFFFFFFFFFFF8F0F0F0F0F0E8E0F0D8D0E0D0C0E0C8C0A038
        10C06060703840998977FFFFFFE098A0FFC0C0D07070FFFFFFFFFFFFFFFFFFFF
        F8F0F0F0F0F0E8E0F0D8D0E0D0C0A04020D06860703840998977FFFFFFF0A0A0
        FFC0C0E07870FFFFFFFFFFFFFFFFFFFFFFFFFFF8F0F0F0F0F0E8E0F0D8D0B048
        30D07070703840998977FFFFFFF0A8A0FFC0C0E08080FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFF8F0F0F0F0F0E8E0B05030E07880703840998977FFFFFFF0B0B0
        FFC0C0F08890FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F0F0F0F0C050
        40603030703840998977FFFFFFF0B0B0FFC0C0FF9090FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFF8F0C05850B05860703840998977FFFFFFF0B8B0
        F0B8B0F0B0B0F0B0B0F0A8B0F0A0A0E098A0E09090E09090E08890E08080D078
        80D07870703840FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ParentShowHint = False
      ShowHint = True
    end
    object SpeedButton9: TSpeedButton
      Left = 343
      Top = 2
      Width = 31
      Height = 31
      Hint = #1057#1086#1093#1088#1072#1085#1077#1085#1080#1077' '#1089#1087#1080#1089#1082#1072' '#1088#1077#1078#1080#1084#1086#1074
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Enabled = False
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
        0000000000000000000000000000000000000000000000FFFFFFFFFFFF000000
        008284008284000000000000000000000000000000000000C6C3C6C6C3C60000
        00008284000000FFFFFFFFFFFF00000000828400828400000000000000000000
        0000000000000000C6C3C6C6C3C6000000008284000000FFFFFFFFFFFF000000
        008284008284000000000000000000000000000000000000C6C3C6C6C3C60000
        00008284000000FFFFFFFFFFFF00000000828400828400000000000000000000
        0000000000000000000000000000000000008284000000FFFFFFFFFFFF000000
        0082840082840082840082840082840082840082840082840082840082840082
        84008284000000FFFFFFFFFFFF00000000828400828400000000000000000000
        0000000000000000000000000000008284008284000000FFFFFFFFFFFF000000
        008284000000C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C60000
        00008284000000FFFFFFFFFFFF000000008284000000C6C3C6C6C3C6C6C3C6C6
        C3C6C6C3C6C6C3C6C6C3C6C6C3C6000000008284000000FFFFFFFFFFFF000000
        008284000000C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C60000
        00008284000000FFFFFFFFFFFF000000008284000000C6C3C6C6C3C6C6C3C6C6
        C3C6C6C3C6C6C3C6C6C3C6C6C3C6000000008284000000FFFFFFFFFFFF000000
        008284000000C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C6C6C3C60000
        00000000000000FFFFFFFFFFFF000000008284000000C6C3C6C6C3C6C6C3C6C6
        C3C6C6C3C6C6C3C6C6C3C6C6C3C6000000C6C3C6000000FFFFFFFFFFFF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ParentShowHint = False
      ShowHint = True
    end
    object buttonLoadChart: TSpeedButton
      Left = 374
      Top = 2
      Width = 31
      Height = 31
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1086#1088#1084#1072#1090#1082#1091
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
        5555555555555555555555555555555555555555555555555555555555555555
        555555555555555555555555555555555555555FFFFFFFFFF555550000000000
        55555577777777775F55500B8B8B8B8B05555775F555555575F550F0B8B8B8B8
        B05557F75F555555575F50BF0B8B8B8B8B0557F575FFFFFFFF7F50FBF0000000
        000557F557777777777550BFBFBFBFB0555557F555555557F55550FBFBFBFBF0
        555557F555555FF7555550BFBFBF00055555575F555577755555550BFBF05555
        55555575FFF75555555555700007555555555557777555555555555555555555
        5555555555555555555555555555555555555555555555555555}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = buttonLoadChartClick
    end
    object buttonSaveChart: TSpeedButton
      Left = 405
      Top = 2
      Width = 31
      Height = 31
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1086#1088#1084#1072#1090#1082#1091
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Caption = ' '
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        333333FFFFFFFFFFFFF33000077777770033377777777777773F000007888888
        00037F3337F3FF37F37F00000780088800037F3337F77F37F37F000007800888
        00037F3337F77FF7F37F00000788888800037F3337777777337F000000000000
        00037F3FFFFFFFFFFF7F00000000000000037F77777777777F7F000FFFFFFFFF
        00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
        00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
        00037F7F333333337F7F000FFFFFFFFF07037F7F33333333777F000FFFFFFFFF
        0003737FFFFFFFFF7F7330099999999900333777777777777733}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButton13: TToolButton
      Left = 436
      Top = 2
      Width = 8
      Caption = 'ToolButton13'
      ImageIndex = 12
      Style = tbsDivider
    end
    object SpeedButton12: TSpeedButton
      Left = 444
      Top = 2
      Width = 31
      Height = 31
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Enabled = False
      Flat = True
      Glyph.Data = {
        C6000000424DC600000000000000460000002800000010000000100000000100
        0400000000008000000000000000000000000400000000000000FFFFFF00C0C0
        C000800000000000000011111111111111111111221111111111111211211221
        1111111211212112111111121121211211111111222121121111111111212221
        1111111111232111111111111113111111111111113331111111111111313111
        1111111113313311111111111311131111111111131113111111111113111311
        11111111111111111111}
    end
    object SpeedButton11: TSpeedButton
      Left = 475
      Top = 2
      Width = 31
      Height = 31
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Enabled = False
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C40E0000C40E00000000000000000000C6C6C6C6C6C6
        C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6
        C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6
        C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6
        C6C6C6C6C6C6C6C6C6C6C6C68400008400008400008400008400008400008400
        00840000840000C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6840000FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF840000C6C6C6C6C6C6C6C6C6
        C6C6C6C6C6C6C6C6C6C6C6C6840000FFFFFF0000000000000000000000000000
        00FFFFFF840000C6C6C6000000000000000000000000000000000000840000FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF840000C6C6C6000000FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF840000FFFFFF0000000000000000000000000000
        00FFFFFF840000C6C6C6000000FFFFFF000000000000000000000000840000FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF840000C6C6C6000000FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF840000FFFFFF000000000000FFFFFF8400008400
        00840000840000C6C6C6000000FFFFFF000000000000000000000000840000FF
        FFFFFFFFFFFFFFFFFFFFFF840000FFFFFF840000C6C6C6C6C6C6000000FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF840000FFFFFFFFFFFFFFFFFFFFFFFF8400008400
        00C6C6C6C6C6C6C6C6C6000000FFFFFF000000000000FFFFFF00000084000084
        0000840000840000840000840000C6C6C6C6C6C6C6C6C6C6C6C6000000FFFFFF
        FFFFFFFFFFFFFFFFFF000000FFFFFF000000C6C6C6C6C6C6C6C6C6C6C6C6C6C6
        C6C6C6C6C6C6C6C6C6C6000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000C6
        C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6000000000000
        000000000000000000000000C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6
        C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6
        C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6C6}
    end
    object SpeedButton15: TSpeedButton
      Left = 506
      Top = 2
      Width = 31
      Height = 31
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Enabled = False
      Flat = True
      Glyph.Data = {
        D6000000424DD600000000000000560000002800000010000000100000000100
        0400000000008000000000000000000000000800000000000000FFFFFF0000FF
        FF00C0C0C0008080800000808000800000000000000000000000222222222222
        2222222222555555555526666650000000056343435066666605643434500000
        0005634343506660555564343450000050526343435000005522643434555555
        5622634343434343462264366666666336226336222222634622643461661634
        3622266666116666622222222666622222222222222222222222}
    end
    object ToolButton17: TToolButton
      Left = 537
      Top = 2
      Width = 8
      Caption = 'ToolButton17'
      ImageIndex = 16
      Style = tbsDivider
    end
    object PanelColor: TPanel
      Left = 545
      Top = 2
      Width = 33
      Height = 31
      Constraints.MinHeight = 31
      TabOrder = 3
      object buttonColor: TSpeedButton
        Left = 0
        Top = 0
        Width = 31
        Height = 31
        Hint = #1042#1099#1073#1086#1088' '#1094#1074#1077#1090#1072
        AllowAllUp = True
        Constraints.MinHeight = 31
        Constraints.MinWidth = 31
        GroupIndex = 1
        Flat = True
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFF9999999999999999999999999999999999999999999999999999
          99999999FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
          0000000000000000000000000000000000999999FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF0000009BB0ED9BB0ED9BB0ED9BB0ED9BB0ED9BB0ED9BB0ED9BB0ED0000
          00999999FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000009BC3ED9BC3ED9BC3ED9B
          C3ED9BC3ED9BC3ED9BC3ED9BC3ED000000999999FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF0000009BD6ED9BD6ED9BD6ED9BD6ED9BD6ED9BD6ED9BD6ED9BD6ED0000
          00999999FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000009BE8ED9BE8ED9BE8ED9B
          E8ED9BE8ED9BE8ED9BE8ED9BE8ED000000999999FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF000000A8EDDFA8EDDFA8EDDFA8EDDFA8EDDFA8EDDFA8EDDFA8EDDF0000
          00999999FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000BCEDCBBCEDCBBCEDCBBC
          EDCBBCEDCBBCEDCBBCEDCBBCEDCB000000999999FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF000000CFEDB9CFEDB9CFEDB9CFEDB9CFEDB9CFEDB9CFEDB9CFEDB90000
          00999999FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000E2EDA5E2EDA5E2EDA5E2
          EDA5E2EDA5E2EDA5E2EDA5E2EDA5000000999999FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF000000EDE69BEDE69BEDE69BEDE69BEDE69BEDE69BEDE69BEDE69B0000
          00999999FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000EDD29BEDD29BEDD29BED
          D29BEDD29BEDD29BEDD29BEDD29B000000999999FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF000000EDC09BEDC09BEDC09BEDC09BEDC09BEDC09BEDC09BEDC09B0000
          00999999FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000EDAC9BEDAC9BEDAC9BED
          AC9BEDAC9BEDAC9BEDAC9BEDAC9B000000999999FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF000000EC9C9BEC9C9BEC9C9BEC9C9BEC9C9BEC9C9BEC9C9BEC9C9B0000
          00999999FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
          0000000000000000000000000000000000FFFFFFFFFFFFFFFFFF}
        ParentShowHint = False
        ShowHint = True
        OnClick = buttonColorClick
      end
      object ColorBox1: TColorBox
        Left = 30
        Top = 0
        Width = 40
        Height = 33
        Constraints.MinHeight = 31
        ItemHeight = 27
        TabOrder = 0
      end
    end
    object buttonSelectColor: TSpeedButton
      Left = 578
      Top = 2
      Width = 31
      Height = 31
      Hint = #1042#1074#1086#1076' '#1090#1077#1082#1089#1090#1072
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
        0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
        0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
        0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
        0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFF000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF0000
        00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFF00
        0000000000FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFF0000000000000000000000000000000000000000000000000000000000
        00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ParentShowHint = False
      ShowHint = True
      OnClick = ButtonCreateStringClick
    end
    object buttonLinkingGrid: TSpeedButton
      Left = 609
      Top = 2
      Width = 31
      Height = 31
      Hint = #1055#1088#1080#1074#1103#1079#1082#1072' '#1096#1082#1072#1083' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074' '#1082' '#1075#1086#1088#1080#1079#1086#1085#1090#1072#1083#1100#1085#1086#1081' '#1089#1077#1090#1082#1077
      AllowAllUp = True
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      GroupIndex = 2
      Down = True
      Flat = True
      Glyph.Data = {
        72010000424D7201000000000000760000002800000015000000150000000100
        040000000000FC000000120B0000120B00001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888C8888C888
        8C8888C880008886888868888688886880008C666CC666CC666CC666C0008886
        88886888868888688000888C8888C8888C8888C88000888C8888C8888C8888C8
        80008886888868888688886880008C666CC666CC666CC666C000888688886888
        868888688000888C888818888C8888C88000888C8881B1888C8888C880008886
        8811B1188688886880008C6661BBBBB1666CC666C00088868811B11886888868
        8000888C8881B1888C8888C88000888C888818888C8888C88000888688886888
        8688886880008C666CC666CC666CC666C000888688886888868888688000888C
        8888C8888C8888C88000888888888888888888888000}
      ParentShowHint = False
      ShowHint = True
      OnClick = buttonLinkingGridClick
    end
    object ToolButton4: TToolButton
      Left = 640
      Top = 2
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 29
      Style = tbsDivider
    end
    object buttonSettingsGrid: TSpeedButton
      Left = 648
      Top = 2
      Width = 31
      Height = 31
      Hint = #1074#1082#1083#1102#1095#1077#1085#1080#1077' '#1088#1091#1095#1085#1086#1081' '#1086#1094#1080#1092#1088#1086#1074#1082#1080' '#1096#1082#1072#1083#1099' '#1074#1088#1077#1084#1077#1085#1080' '
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Enabled = False
      Flat = True
      Glyph.Data = {
        86020000424D860200000000000076000000280000002C000000160000000100
        0400000000001002000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8888888888FFFFFFFFFFFFFFFFFFFFFF0000888C8888C8888C8888C888FFFCFF
        FFCFFFFCFFFFCFFF00008886888868888688886888FFF6FFFF6FFFF6FFFF6FFF
        00008C666CC666CC666CC666C8FC666CC666CC666CC666CF0000888688886888
        8688886888FFF6FFFF6FFFF6FFFF6FFF0000888C8888C8888C8888C888FFFCFF
        FFCFFFFCFFFFCFFF0000888C8888C8888C8888C888FFFCFFFFCFFFFCFFFFCFFF
        00008886888868888688886888FFF6FFFF6FFFF6FFFF6FFF00008C666CC666CC
        666CC666C8FC666CC666CC666CC666CF00008886888868888688886888FFF6FF
        FF6FFFF6FFFF6FFF0000888C8888C8888C8888C888FFFCFFFFCFFFFCFFFFCFFF
        0000888C8888C8888C8888C888FFFCFFFFCFFFFCFFFFCFFF0000888688886888
        8688886888FFF6FFFF6FFFF6FFFF6FFF00008C666CC666CC666CC666C8FC666C
        C666CC666CC666CF00008886888868888688886888FFF6FFFF6FFFF6FFFF6FFF
        0000888C8888C8888C8888C888FFFCFFFFCFFFFCFFFFCFFF0000888C8888C888
        8C8888C888FFFCFFFFCFFFFCFFFFCFFF00008886888868888688886888FFF6FF
        FF6FFFF6FFFF6FFF00008C666CC666CC666CC666C8FC666CC666CC666CC666CF
        00008886888868888688886888FFF6FFFF6FFFF6FFFF6FFF0000888C8888C888
        8C8888C888FFFCFFFFCFFFFCFFFFCFFF00008888888888888888888888FFFFFF
        FFFFFFFFFFFFFFFF0000}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
    end
    object Edit4: TEdit
      Left = 679
      Top = 2
      Width = 56
      Height = 31
      Hint = #1064#1072#1075' '#1086#1094#1080#1092#1088#1086#1074#1082#1080
      Constraints.MinHeight = 31
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      Text = '0'
      OnKeyPress = EditKolVertLinesKeyPress
    end
    object Edit8: TEdit
      Left = 735
      Top = 2
      Width = 56
      Height = 31
      Hint = #1056#1072#1079#1084#1077#1088' '#1076#1077#1083#1077#1085#1080#1103' '#1074' '#1089#1077#1082#1091#1085#1076#1072#1093
      Constraints.MinHeight = 31
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      Text = '0.0'
    end
    object ToolButton26: TToolButton
      Left = 791
      Top = 2
      Width = 8
      Caption = 'ToolButton26'
      ImageIndex = 25
      Style = tbsDivider
    end
    object SpeedButton20: TSpeedButton
      Left = 799
      Top = 2
      Width = 31
      Height = 31
      Hint = #1089#1080#1085#1093#1088#1086#1085#1080#1079#1072#1094#1080#1103' '#1074#1088#1077#1084#1077#1085#1080' '#1075#1088#1072#1092#1080#1095#1077#1089#1082#1086#1075#1086' '#1086#1082#1085#1072' '#1089' '#1074#1088#1077#1084#1077#1085#1077#1084' '#1088#1077#1078#1080#1084#1072
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Enabled = False
      Flat = True
      Glyph.Data = {
        36050000424D3605000000000000360400002800000010000000100000000100
        08000000000000010000C40E0000C40E00000001000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
        A6000020400000206000002080000020A0000020C0000020E000004000000040
        20000040400000406000004080000040A0000040C0000040E000006000000060
        20000060400000606000006080000060A0000060C0000060E000008000000080
        20000080400000806000008080000080A0000080C0000080E00000A0000000A0
        200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
        200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
        200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
        20004000400040006000400080004000A0004000C0004000E000402000004020
        20004020400040206000402080004020A0004020C0004020E000404000004040
        20004040400040406000404080004040A0004040C0004040E000406000004060
        20004060400040606000406080004060A0004060C0004060E000408000004080
        20004080400040806000408080004080A0004080C0004080E00040A0000040A0
        200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
        200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
        200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
        20008000400080006000800080008000A0008000C0008000E000802000008020
        20008020400080206000802080008020A0008020C0008020E000804000008040
        20008040400080406000804080008040A0008040C0008040E000806000008060
        20008060400080606000806080008060A0008060C0008060E000808000008080
        20008080400080806000808080008080A0008080C0008080E00080A0000080A0
        200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
        200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
        200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
        2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
        2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
        2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
        2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
        2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
        2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
        2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
        0707070707070707070707070707070707070707070707070707070707FC0707
        0707070707FC070707070707FCFCFC0707070707FCFCFC070707070707FC0707
        0707070707FC070707070707FC07FCFCFC070707FC07FCFCFC070707FC0707FC
        FC070707FC0707FCFC0707FC0707FC07FC0707FC0707FC07FC0707F907F90707
        070707F907F90707070707F9F9070700070007F9F907070007000707F9070707
        00070707F90707070007070707FC07000700070707FC0700070007070707FC07
        FC0707070707FC07FC070707070707FCFC070707070707FCFC0707070707FCFC
        FC0707070707FCFCFC0707070707070707070707070707070707}
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButton2: TToolButton
      Left = 830
      Top = 2
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 29
      Style = tbsDivider
    end
    object buttonReperLine: TSpeedButton
      Left = 838
      Top = 2
      Width = 31
      Height = 31
      Hint = #1056#1077#1087#1077#1088#1085#1072#1103' '#1083#1080#1085#1080#1103
      AllowAllUp = True
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      GroupIndex = 1
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00337333733373
        3373337F3F7F3F7F3F7F33737373737373733F7F7F7F7F7F7F7F770000000000
        00007777777777777777330333333C333333337FFF3337F3333F370993333C33
        3399377773F337F33377330339333C3339333F7FF7FFF7FFF7FF770777977C77
        97777777777777777777330333933C339333337F3373F7F37333370333393C39
        3333377F333737F7333333033333999333333F7FFFFF777FFFFF770777777C77
        77777777777777777777330333333C330333337F333337FF7FF3370333333C00
        003C377F333337777737330333333C3303333F7FFFFFF7FF7FFF770777777777
        7777777777777777777733333333333333333333333333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = buttonReperLineClick
    end
    object ToolButton1: TToolButton
      Left = 869
      Top = 2
      Width = 8
      Caption = 'ToolButton1'
      ImageIndex = 28
      Style = tbsDivider
    end
    object buttonCut: TSpeedButton
      Left = 877
      Top = 2
      Width = 31
      Height = 31
      Hint = #1042#1099#1088#1077#1079#1072#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1081' '#1092#1088#1072#1075#1084#1077#1085#1090
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Enabled = False
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333FF3333333333333003333333333333377F33333333333307
        733333FFF333337773333C003333307733333777FF333777FFFFC0CC03330770
        000077777FF377777777C033C03077FFFFF077FF77F777FFFFF7CC00000F7777
        777077777777777777773CCCCC00000000003777777777777777333330030FFF
        FFF03333F77F7F3FF3F7333C0C030F00F0F03337777F7F77373733C03C030FFF
        FFF03377F77F7F3F333733C03C030F0FFFF03377F7737F733FF733C000330FFF
        0000337777F37F3F7777333CCC330F0F0FF0333777337F737F37333333330FFF
        0F03333333337FFF7F7333333333000000333333333377777733}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = buttonCutClick
    end
    object buttonInfo: TSpeedButton
      Left = 908
      Top = 2
      Width = 31
      Height = 31
      Action = AInfo
      Constraints.MinHeight = 31
      Constraints.MinWidth = 31
      Caption = ' '
      Flat = True
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000120B0000120B00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFF3F3F3D2D2D2B6B6B6A1A1A1A1A1A1B6B6B6D2D2D2F3F3
        F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE2E2F28282EB3434F70D0DF7
        0D0DE22B2BC65656A58888999999B9B9B9E8E8E8FFFFFFFFFFFFFFFFFFFFFFFF
        FFC6C6FB4B4BFF0000FF0000FF0000FF0000FF0000FF0000DF2F2FB077779999
        99B9B9B9F3F3F3FFFFFFFFFFFFFFE2E2FF4F4FFF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000DF2F2FA58888999999D2D2D2FFFFFFFFFFFFFF8F8F
        FF0000FF0000FF0000FFFFFFFFFFFFFFFFFFFFFFFFFF0000FF0000FF0000C656
        56999999B6B6B6FFFFFFFFFFFFFF4848FF0000FF0000FF0000FF0000FFFFFFFF
        FFFFFF0000FF0000FF0000FF0000E22B2B999999A1A1A1FFFFFFFFFFFFFF1515
        FF0000FF0000FF0000FF0000FFFFFFFFFFFFFF0000FF0000FF0000FF0000F70D
        0D999999A1A1A1FFFFFFFFFFFFFF1515FF0000FF0000FF0000FF0000FFFFFFFF
        FFFFFF0000FF0000FF0000FF0000F70D0D999999B6B6B6FFFFFFFFFFFFFF4848
        FF0000FF0000FF0000FFFFFFFFFFFFFFFFFFFF0000FF0000FF0000FF0000E22B
        2B999999D2D2D2FFFFFFFFFFFFFF8F8FFF0000FF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000FF0000C65656B9B9B9F3F3F3FFFFFFFFFFFFFFE2E2
        FF4F4FFF0000FF0000FF0000FFFFFFFFFFFFFF0000FF0000FF0000DF2F2FC1A4
        A4E8E8E8FFFFFFFFFFFFFFFFFFFFFFFFFFC6C6FF4F4FFF0000FF0000FFFFFFFF
        FFFFFF0000FF0000E83838DCA3A3F3F3F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFE2E2FF8F8FFF4848FF1515FF1515FF4848FF8F8FFFE2E2FFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    end
  end
  object TabControl1: TTabControl
    Left = 0
    Top = 164
    Width = 1371
    Height = 512
    Align = alClient
    PopupMenu = PopupMenuTab
    TabOrder = 4
    OnChange = TabControl1Change
    OnChanging = TabControl1Changing
    OnMouseDown = TabControl1MouseDown
    object ScrollBox1: TScrollBox
      Left = 4
      Top = 6
      Width = 1363
      Height = 502
      Align = alClient
      TabOrder = 0
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 1359
        Height = 498
        Cursor = crArrow
        AllowPanning = pmNone
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Legend.Alignment = laBottom
        Legend.CurrentPage = False
        Legend.CustomPosition = True
        Legend.Left = 570
        Legend.LeftPercent = 75
        Legend.LegendStyle = lsLastValues
        Legend.ResizeChart = False
        Legend.TextStyle = ltsPlain
        Legend.Title.Text.Strings = (
          'sertg')
        Legend.Top = 195
        Legend.TopPos = 41
        Legend.VertSpacing = -3
        Legend.Visible = False
        PrintProportional = False
        SubTitle.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        OnClickAxis = Chart1ClickAxis
        BottomAxis.Axis.Width = 1
        BottomAxis.LabelsSeparation = 0
        BottomAxis.MinorGrid.SmallDots = True
        BottomAxis.MinorGrid.Visible = True
        BottomAxis.MinorTickCount = 2
        Chart3DPercent = 1
        ClipPoints = False
        DepthTopAxis.Title.Caption = 'FFF'
        LeftAxis.Axis.Width = 1
        LeftAxis.LabelStyle = talValue
        LeftAxis.MinorGrid.Style = psDot
        LeftAxis.MinorGrid.Visible = True
        LeftAxis.MinorTickCount = 0
        LeftAxis.ZPosition = 90
        Pages.ScaleLastPage = False
        RightAxis.Axis.Width = 1
        TopAxis.Axis.Width = 1
        View3D = False
        View3DOptions.OrthoAngle = 100
        View3DOptions.Zoom = 102
        View3DOptions.ZoomText = False
        Zoom.Allow = False
        Zoom.Brush.Color = clSilver
        Zoom.Brush.Style = bsDiagCross
        Zoom.Pen.Color = clBlack
        Zoom.Pen.Width = 2
        Zoom.UpLeftZooms = True
        OnAfterDraw = Chart1AfterDraw
        Align = alClient
        Color = clWhite
        PopupMenu = PopupMenu1
        TabOrder = 0
        OnMouseDown = Chart1MouseDown
        OnMouseMove = Chart1MouseMove
        OnMouseUp = Chart1MouseUp
        PrintMargins = (
          0
          0
          0
          0)
        ColorPaletteIndex = 13
        object ChartTool1: TPageNumTool
          Active = False
          Callout.Brush.Color = clBlack
          Callout.Arrow.Visible = False
          Shape.Text = 'Page 1 of 1'
          Text = 'Page 1 of 1'
          DisabledButton.EndColor = clSilver
          DisabledButton.Visible = True
          EnabledButton.EndColor = clSilver
          EnabledButton.StartColor = clBlack
          EnabledButton.Visible = True
        end
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 712
    Top = 264
    object NAddParameter: TMenuItem
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088
      OnClick = MParametrsClick
    end
    object NMarginSettings: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1087#1086#1083#1103
    end
    object NFormatCurrentProperties: TMenuItem
      Caption = #1057#1074#1086#1081#1089#1090#1074#1072' '#1090#1077#1082#1091#1097#1077#1075#1086' '#1092#1086#1088#1084#1072#1090#1072
    end
  end
  object OpenDialogData: TOpenDialog
    DefaultExt = '*.48XX'
    Filter = #1074#1089#1077' '#1092#1072#1081#1083#1099'(*.*)|*.*|48XX '#1092#1072#1081#1083#1099'(*.48XX)|*.48XX'
    FilterIndex = 2
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1092#1072#1081#1083' '#1087#1086#1083#1077#1090#1072
    Left = 648
    Top = 232
  end
  object OpenDialogFormat: TOpenDialog
    DefaultExt = '*.fmt'
    Filter = #1060#1072#1081#1083#1099' '#1092#1086#1088#1084#1072#1090#1086#1082'(*.fmt)|*.fmt|'#1060#1072#1081#1083#1099' '#1074#1082#1083#1072#1076#1086#1082'(*.tee)|*.tee'
    Options = [ofHideReadOnly, ofExtensionDifferent, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Title = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1092#1086#1088#1084#1072#1090#1072
    Left = 648
    Top = 264
  end
  object PopupMenuAxis: TPopupMenu
    Left = 712
    Top = 296
    object Delete: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = DeleteClick
    end
    object N5: TMenuItem
      Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
    end
    object NPaste: TMenuItem
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100
      Enabled = False
    end
    object Settings: TMenuItem
      Caption = #1057#1074#1086#1081#1089#1090#1074#1072
      OnClick = SettingsClick
    end
  end
  object SaveDialogFormat: TSaveDialog
    DefaultExt = '*.fmt'
    Filter = #1060#1086#1088#1084#1072#1090#1082#1080'(*.fmt)|*.fmt'
    Title = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1092#1086#1088#1084#1072#1090#1072
    Left = 616
    Top = 232
  end
  object ImageList1: TImageList
    Left = 584
    Top = 232
    Bitmap = {
      494C01011B001D00040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000008000000001002000000000000080
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000080000000800000008000000080000000800000008000
      0000800000008000000080000000800000000000000000000000A79D00000000
      00000000000000000000A79D00000000000000000000A79D0000000000000000
      000000000000A79D000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF008000000000000000A79D0000A79D0000A79D
      0000FF000A00A79D0000A79D0000FF000A00FF000A00A79D0000A79D0000FF00
      0A00A79D0000A79D0000A79D0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000008080008080
      8000008080008080800080000000FFFFFF000000000000000000000000000000
      00000000000000000000FFFFFF00800000000000000000000000A79D00000000
      00000000000000000000A79D00000000000000000000A79D0000000000000000
      000000000000A79D000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000808000808080000080
      8000808080000080800080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00800000000000000000000000FF000A000000
      00000000000000000000FF000A000000000000000000FF000A00000000000000
      000000000000FF000A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000008080008080
      8000008080008080800080000000FFFFFF00000000000000000000000000FFFF
      FF00800000008000000080000000800000000000000000000000A79D00000000
      00000000000000000000A79D00000000000000000000A79D0000000000000000
      000000000000A79D000000000000000000000000660000000000000000000066
      B60000000000B66600000066B60000000000B666000000000000DBFFFF000000
      00000000000090DBFF0000000000FFB666000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000808000808080000080
      8000808080000080800080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0080000000FFFFFF00800000000000000000000000A79D0000A79D0000A79D
      0000FF000A00A79D0000A79D0000FF000A00FF000A00A79D0000A79D0000FF00
      0A00A79D0000A79D0000A79D000000000000000000003A90DB00FFFFB6003A00
      0000FFDB900000003A003A000000FFDB900000003A0000000000000000006600
      3A00FFFFB6003A90DB0066B6FF00B66600000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000008080008080
      8000008080008080800080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00800000008000000000000000000000000000000000000000FF000A000000
      0000000000000000000000009B000000000000000000FF000A00000000000000
      000000000000FF000A000000000000000000000000003A90DB00FFFFB600903A
      0000FFFFDB00003A9000903A0000FFFFDB00003A9000000000000000000066B6
      FF00903A00003A90B60066B6FF00B66600000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000808000808080000080
      8000808080000080800080000000800000008000000080000000800000008000
      0000800000000000000000000000000000000000000000000000FF000A000000
      00000000000000009B0000FFFF000000000000000000FF000A00000000000000
      000000000000FF000A000000000000000000000000003A90DB00FFFFB600903A
      0000FFFFDB00003A9000903A0000FFFFDB00003A9000000000000066B6003A90
      DB00B6903A00003A900000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000008080008080
      8000008080008080800000808000808080000080800080808000008080008080
      80000080800000000000000000000000000000000000A79D0000A79D0000A79D
      000000FFFF0000FFFF0000FFFF0000FFFF0000009B00A79D0000A79D0000FF00
      0A00A79D0000A79D0000A79D000000000000660066003A909000FFFFB6003A00
      0000FFDB9000000066003A000000FFDB900000006600000000000066B6003A90
      DB00DB903A00B6FFFF00FFFFB600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000808000808080000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000808080000000000000000000000000000000000000000000A79D00000000
      000000009B0000009B0000FFFF0000009B0000000000A79D0000000000000000
      000000000000A79D00000000000000000000B6FFFF0000006600FFFFB6003A90
      DB0000000000903A00003A90DB0000000000903A00000000000066B6FF003A00
      00000000000000000000903A0000FFFFDB000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000008080000000000000000000000000000000000000000000FF000A000000
      00000000000000009B0000FFFF000000000000000000FF000A00000000000000
      000000000000FF000A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000808000808080000080
      80000000000000FFFF00000000000000000000FFFF0000000000808080000080
      8000808080000000000000000000000000000000000000000000A79D00000000
      00000000000000000000A79D00000000000000000000A79D0000000000000000
      000000000000A79D000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000FFFF0000FFFF000000000000000000000000000000
      00000000000000000000000000000000000000000000A79D0000A79D0000A79D
      0000FF000A00A79D0000A79D0000FF000A00FF000A00A79D0000A79D0000FF00
      0A00A79D0000A79D0000A79D0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000A79D00000000
      00000000000000000000A79D00000000000000000000A79D0000000000000000
      000000000000A79D000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000998977009989
      7700998977009989770099897700998977009989770099897700998977009989
      7700998977009989770099897700998977000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D3B7BB00703840007038
      4000703840007038400070384000703840007038400070384000703840007038
      4000703840007038400070384000998977000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008000000080000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D0687000F0909000E080
      8000B048200040302000C0B8B000C0B8B000D0C0C000D0C8C00050505000A040
      3000A0403000A038300070384000998977000000000000000000008284000082
      8400000000000000000000000000000000000000000000000000C6C3C600C6C3
      C600000000000082840000000000000000000000000000000000000000000000
      0000800000000000000000000000800000000000000000000000800000008000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084000000840000008400000084000000840000008400
      00008400000084000000840000000000000000000000D0707000FF98A000F088
      8000E0808000705850004040300090787000F0E0E000F0E8E00090807000A040
      3000A0404000A040300070384000998977000000000000000000008284000082
      8400000000000000000000000000000000000000000000000000C6C3C600C6C3
      C600000000000082840000000000000000000000000000000000000000000000
      0000800000000000000000000000800000000000000080000000000000000000
      0000800000000000000000000000000000000000000000000000000000000000
      0000000000000000000084000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00840000000000000000000000D0787000FFA0A000F090
      9000F0888000705850000000000040403000F0D8D000F0E0D00080786000B048
      4000B0484000A040400070384000998977000000000000000000008284000082
      8400000000000000000000000000000000000000000000000000C6C3C600C6C3
      C600000000000082840000000000000000000000000000000000000000000000
      0000800000000000000000000000800000000000000080000000000000000000
      0000800000000000000000000000000000000000000000000000000000000000
      0000000000000000000084000000FFFFFF000000000000000000000000000000
      000000000000FFFFFF00840000000000000000000000D0788000FFA8B000FFA0
      A000F0909000705850007058500070585000705850007060500080686000C058
      5000B0505000B048400070384000998977000000000000000000008284000082
      8400000000000000000000000000000000000000000000000000000000000000
      0000000000000082840000000000000000000000000000000000000000000000
      0000000000008000000080000000800000000000000080000000000000000000
      0000800000000000000000000000000000000000000000000000000000000000
      0000000000000000000084000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00840000000000000000000000E0808000FFB0B000FFB0
      B000FFA0A000F0909000F0888000E0808000E0788000D0707000D0687000C060
      6000C0585000B050500070384000998977000000000000000000008284000082
      8400008284000082840000828400008284000082840000828400008284000082
      8400008284000082840000000000000000000000000000000000000000000000
      0000000000000000000000000000800000000000000080000000800000008000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0084000000FFFFFF000000000000000000000000000000
      000000000000FFFFFF00840000000000000000000000E0889000FFB8C000FFB8
      B000D0606000C0605000C0585000C0504000B0503000B0483000A0402000A038
      1000C0606000C058500070384000998977000000000000000000008284000082
      8400000000000000000000000000000000000000000000000000000000000000
      0000008284000082840000000000000000000000000000000000000000000000
      0000000000000000000000000000800000000000000080000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000084000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00840000000000000000000000E0909000FFC0C000D068
      60000000000000000000FFF8F000F0F0F000F0E8E000F0D8D000E0D0C000E0C8
      C000A0381000C060600070384000998977000000000000000000008284000000
      0000C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3
      C600000000000082840000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0084000000FFFFFF000000000000000000FFFFFF008400
      00008400000084000000840000000000000000000000E098A000FFC0C000D070
      7000000000000000000000000000FFF8F000F0F0F000F0E8E000F0D8D000E0D0
      C000A0402000D068600070384000998977000000000000000000008284000000
      0000C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3
      C600000000000082840000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000084000000FFFFFF00FFFFFF00FFFFFF00FFFFFF008400
      0000FFFFFF0084000000000000000000000000000000F0A0A000FFC0C000E078
      700000000000000000000000000000000000FFF8F000F0F0F000F0E8E000F0D8
      D000B0483000D070700070384000998977000000000000000000008284000000
      0000C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3
      C600000000000082840000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFFFF008400
      00008400000000000000000000000000000000000000F0A8A000FFC0C000E080
      80000000000000000000000000000000000000000000FFF8F000F0F0F000F0E8
      E000B0503000E078800070384000998977000000000000000000008284000000
      0000C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3
      C600000000000082840000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000FFFFFF000000000084000000840000008400000084000000840000008400
      00000000000000000000000000000000000000000000F0B0B000FFC0C000F088
      9000000000000000000000000000000000000000000000000000FFF8F000F0F0
      F000C05040006030300070384000998977000000000000000000008284000000
      0000C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3
      C600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F0B0B000FFC0C000FF90
      900000000000000000000000000000000000000000000000000000000000FFF8
      F000C0585000B058600070384000998977000000000000000000008284000000
      0000C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3C600C6C3
      C60000000000C6C3C60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F0B8B000F0B8B000F0B0
      B000F0B0B000F0A8B000F0A0A000E098A000E0909000E0909000E0889000E080
      8000D0788000D078700070384000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF00000000
      0000999999009999990099999900999999009999990099999900999999009999
      9900999999000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000000000009999990099999900999999009999990099999900999999009999
      990099999900999999000000000000000000000000000000000000000000FFFF
      FF000000000000000000000000000000000000000000FFFFFF00521018000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00521018000000000000000000000000000000000052101800521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180000000000000000000000000000000000FFFFFF00521018000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00521018000000000000000000000000005210180052101800521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0052101800000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180052101800000000000000000000000000FFFFFF00521018000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00521018000000000000000000521018005210180052101800521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0052101800521018000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180052101800521018000000000000000000FFFFFF00521018000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00521018000000000052101800521018005210180052101800521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0052101800521018005210180000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180052101800521018005210180052101800FFFFFF00521018000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180000000000FFFFFF00FFFFFF005210180052101800521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0052101800521018005210180052101800521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180052101800521018005210180000000000FFFFFF00521018000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00521018000000000000000000FFFFFF00FFFFFF0052101800521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0052101800521018005210180052101800000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF0000FFFF0000FFFF00000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180052101800521018000000000000000000FFFFFF00521018000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF0052101800000000000000000000000000FFFFFF00FFFFFF00521018000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0052101800521018005210180000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF0000FFFF0000FFFF000000000000FF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180052101800000000000000000000000000FFFFFF00521018000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180000000000000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0052101800521018000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF0000FFFF0000FFFF000000000000FF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF005210180000000000000000000000000000000000FFFFFF00FFFFFF000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0052101800000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000FFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F3F3F300D2D2D200B6B6B600A1A1A100A1A1A100B6B6B600D2D2
      D200F3F3F3000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000840084008400840084848400000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFE2
      E200F2828200EB343400F70D0D00F70D0D00E22B2B00C6565600A58888009999
      9900B9B9B900E8E8E80000000000000000000000000000000000000000000000
      0000000000008400840084008400FFFFFF00FFFFFF00C6C6C600848484000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFC6C600FB4B
      4B00FF000000FF000000FF000000FF000000FF000000FF000000DF2F2F00B077
      770099999900B9B9B900F3F3F300000000000000000000000000000000008400
      840084008400FFFFFF00FFFFFF000000000000000000C6C6C600C6C6C6008484
      84000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000008484840000000000000000008484
      84000000000000000000000000000000000000000000000000000000000000FF
      FF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF000000000000000000000000000000000000000000FFE2E200FF4F4F00FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000DF2F
      2F00A588880099999900D2D2D20000000000848484008400840084008400FFFF
      FF00FFFFFF000000000000000000840084008400840000000000C6C6C600C6C6
      C6008484840000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000848484000000000000000000FFFF00008484
      8400848484000000000000000000000000000000000000000000FFFFFF000000
      000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0
      C00000FFFF0000000000000000000000000000000000FF8F8F00FF000000FF00
      0000FF00000000000000000000000000000000000000FF000000FF000000FF00
      0000C656560099999900B6B6B600000000008484840084008400FFFFFF000000
      000000000000840084008400840084008400840084008400840000000000C6C6
      C600C6C6C60084848400000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000008484
      840000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF000000000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF00C0C0C00000FFFF00000000000000000000000000FF484800FF000000FF00
      0000FF000000FF0000000000000000000000FF000000FF000000FF000000FF00
      0000E22B2B0099999900A1A1A100000000008484840000000000000000008400
      840084008400840084000084840000FFFF008400840084008400840084000000
      0000C6C6C600C6C6C600848484000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000000000000000FFFF000000000000000000008484
      8400000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF151500FF000000FF00
      0000FF000000FF0000000000000000000000FF000000FF000000FF000000FF00
      0000F70D0D0099999900A1A1A100000000008484840084008400840084008400
      8400840084008400840084008400008484008400840084008400840084008400
      840000000000C6C6C600000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000000084848400FFFF0000FFFF0000000000008484
      840084848400000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000
      00000000000000000000000000000000000000000000FF151500FF000000FF00
      0000FF000000FF0000000000000000000000FF000000FF000000FF000000FF00
      0000F70D0D0099999900B6B6B600000000000000000084008400FFFFFF008400
      84008400840084008400840084008400840000FFFF0000FFFF00840084008400
      84008400840000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000008484840000000000000000008484
      8400000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
      00000000000000000000000000000000000000000000FF484800FF000000FF00
      0000FF000000000000000000000000000000FF000000FF000000FF000000FF00
      0000E22B2B0099999900D2D2D20000000000000000000000000084008400FFFF
      FF0084008400840084008400840084008400840084000084840000FFFF0000FF
      FF008400840084008400000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
      00000000000000000000000000000000000000000000FF8F8F00FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000C6565600B9B9B900F3F3F300000000000000000000000000000000008400
      8400FFFFFF00840084008400840084008400008484008400840000FFFF0000FF
      FF008400840084008400840084000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFE2E200FF4F4F00FF00
      0000FF000000FF0000000000000000000000FF000000FF000000FF000000DF2F
      2F00C1A4A400E8E8E80000000000000000000000000000000000000000000000
      000084008400FFFFFF00840084008400840000FFFF0000FFFF0000FFFF008400
      84008400840084008400000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFC6C600FF4F
      4F00FF000000FF0000000000000000000000FF000000FF000000E8383800DCA3
      A300F3F3F3000000000000000000000000000000000000000000000000000000
      00000000000084008400FFFFFF00840084008400840084008400840084008400
      84000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFE2
      E200FF8F8F00FF484800FF151500FF151500FF484800FF8F8F00FFE2E2000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084008400FFFFFF008400840084008400000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000840084008400840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF000000000000000000000000000000000000000000000000000000000000FF
      FF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF000000000000000000000000000000000000000000000000000000000000FF
      FF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0
      C00000FFFF000000000000000000000000000000000000000000FFFFFF000000
      000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0
      C00000FFFF000000000000000000000000000000000000000000FFFFFF000000
      000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0
      C00000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF000000000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF00C0C0C00000FFFF000000000000000000000000000000000000FFFF00FFFF
      FF000000000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF00C0C0C00000FFFF000000000000000000000000000000000000FFFF00FFFF
      FF000000000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF00C0C0C00000FFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000
      000000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000
      000000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007F7F
      7F00000000007F7F7F0000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007F7F7F000000
      00000000FF000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF0000000000BFBFBF00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000007F7F7F000000000000000000000000007F7F7F00000000000000
      FF00000000007F7F7F0000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF00000000007F7F7F00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007F7F7F00000000000000FF000000
      00007F7F7F000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF0000000000BFBFBF00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF0000000000000000000000FF00000000007F7F
      7F00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF00000000007F7F7F00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000FF00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF0000000000BFBFBF00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF00000000007F7F7F00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF0000000000BFBFBF00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF000000FF000000FF0000000000000000007F7F
      7F00000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF00000000007F7F7F00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007F7F7F00000000007F7F7F00000000007F7F7F00000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00BFBFBF00BFBFBF00BFBFBF007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000007F7F7F007F7F7F007F7F7F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008484840084848400848484008484
      8400848484008484840084848400848484008484840084848400FFFFFF00C6C6
      C60084848400C6C6C600FFFFFF00C6C6C6000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008484840084848400848484008484
      840084848400848484008484840084848400848484008484840084848400FFFF
      FF0084848400FFFFFF00848484008484840000000000BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008400000084000000840000008400
      00000000000000000000848484008484840084848400FFFFFF00FFFFFF00FFFF
      FF008400000084000000840000008400000000000000BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00000000000000000000000000008484000084
      8400008484000084840000848400008484000084840000848400008484000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000008484000084840000000000000000000000000000000000C6C6C6000000
      0000008484000000000000000000000000000000000000000000000000008400
      0000FF00000084000000000000000000000084848400FFFFFF00FFFFFF00FFFF
      FF00840000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF00000000000084
      8400008484000084840000848400008484000084840000848400008484000084
      8400000000000000000000000000000000000000000000000000000000000000
      0000008484000084840000000000000000000000000000000000C6C6C6000000
      0000008484000000000000000000000000000000000000000000000000008400
      000084000000FF0000008400000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF008400000000000000000000000000000000000000FFFFFF00BFBFBF00FFFF
      FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
      FF00BFBFBF00FFFFFF00BFBFBF000000000000000000FFFFFF0000FFFF000000
      0000008484000084840000848400008484000084840000848400008484000084
      8400008484000000000000000000000000000000000000000000000000000000
      0000008484000084840000000000000000000000000000000000000000000000
      0000008484000000000000000000000000000000000000000000000000008400
      0000FF00000084000000FF00000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF008400000000000000000000000000000000000000BFBFBF00FFFFFF00BFBF
      BF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBF
      BF00FFFFFF000000FF00FFFFFF00000000000000000000FFFF00FFFFFF0000FF
      FF00000000000084840000848400008484000084840000848400008484000084
      8400008484000084840000000000000000000000000000000000000000000000
      0000008484000084840000848400008484000084840000848400008484000084
      8400008484000000000000000000000000000000000000000000000000008400
      000084000000FF0000008400000000000000FFFFFF00FFFF0000FFFFFF00FFFF
      00008400000000000000000000000000000000000000FFFFFF00BFBFBF00FFFF
      FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
      FF00BFBFBF00FFFFFF00BFBFBF000000000000000000FFFFFF0000FFFF00FFFF
      FF0000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000008484000084840000000000000000000000000000000000000000000084
      8400008484000000000000000000000000000000000000000000000000008400
      0000FF00000084000000FF00000000000000FFFF0000FFFFFF00FFFF0000FFFF
      FF00840000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF00FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000084840000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      0000008484000000000000000000000000000000000000000000000000008400
      000084000000FF0000008400000000000000FFFFFF00FFFF0000FFFFFF00FFFF
      0000840000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000000000000FFFFFF0000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000084840000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      0000008484000000000000000000000000000000000000000000000000008400
      0000FF00000084000000FF00000000000000FFFF0000FFFFFF00FFFF0000FFFF
      FF00840000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000000000000000000000000000FFFFFF0000000000FFFF
      FF00000000000000000000000000000000000000000000FFFF00FFFFFF0000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000084840000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      0000000000000000000000000000000000000000000000000000000000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000084840000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      0000C6C6C6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000840000008400000084000000840000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF00FFFFFF0000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000800000000100010000000000000400000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFFFFFFFFF0000FC00DDBBFFFF0000
      80008001FFFF00000000DDBBFFFF00000000DDBBFFFF00000000DDBB00580000
      00018001806000000003DDBB806000000003D9BB804300000003800100410000
      0003D0BB004C00000FC3D9BBFFFF00000003DDBBFFFF000080078001FFFF0000
      F87FDDBBFFFF0000FFFFFFFFFFFF0000C000FFFFFFFFFFFF8000C001F9FFFFFF
      80008001F6CFFC0180008001F6B7FC0180008001F6B7FC0180008001F8B70001
      80008001FE8F000180008001FE3F00018C008001FF7F00018E008001FE3F0003
      8F008001FEBF00078F808001FC9F000F8FC08001FDDF00FF8FE08001FDDF01FF
      80018001FDDF03FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF800FFFFFFFFFFFFF
      8007FFFFFFFFFFFF8003F7CFF3CFFDFF8001E38FE38FF8FF8000E18FE30FF87F
      8007E08FE20FF83F8007E00FE00FF81F87FFE00FE00FF81F841FE08FE20FF83F
      FC0FE18FE30FF87FFC07E38FE38FF8FFFC07E79FE7DFF9FFFC07FFFFFFFFFFFF
      FE07FFFFFFFFFFFFFF07FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3F000C
      FFFFF807F81F0008FFFFE003E00F0001C00FC0018007006380078001000300C3
      80038781000101EB800183010000016B8001830100010023800F830180010067
      80008701C001000F80178001E000000FC0F78303F000000FC0F7C307F803005F
      FFF7E01FFC0F003FFFF7FFFFFE3F007FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      BB6DFFFFFFFFFFFFBB69FFFFFFFFFFFFAB61C00FC00FC00F8365800780078007
      93ED800380038003BB6D800180018001FFFF800180018001BAD68007800F800F
      BAD6800780008007AA198017801B801782D9C0F1C0FBC0F192D6C0F7C0FBC0F6
      BB36FFF7FFFBFFF6FFFFFFF0FFE0FFF1FFFFFC7FFEFFE00FFFE3FC7FFC7FE00F
      FFC3FC7FFC7FE00FFB83FC7FF83FE00FF907FC7FF83FE00FF80FFC7FF01FE00F
      F01FE00FFC7FE00FF03FE00FFC7FA00BE01FF01FFC7FC007E00FF01FF01FE00F
      C07FF83FF83FE00FC1FFF83FF83FC00787FFFC7FFC7FC0079FFFFC7FFC7FC007
      FFFFFEFFFEFFF83FFFFFFEFFFEFFF83FFFFFFF7E00008001FFFFBFFF00000000
      001FF00300000000000FE003E00700000007E003E00700000003E003E0070000
      0001E003E007000000002003E0070000001FE002E007E007001FE003E007E007
      001FE003E007E0078FF1E003FFFFE007FFF9E003F81FE00FFF75FFFFF81FE01F
      FF8FBF7DF81FE03FFFFF7F7EFFFFE07F00000000000000000000000000000000
      000000000000}
  end
  object ImageListPageControl2: TImageList
    Left = 584
    Top = 264
    Bitmap = {
      494C010108000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00BFBFBF0000000000000000000000000000FFFF0000FF
      FF00000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF00000000000000
      00000000000000000000FF000000FF00000000000000000000000000FF000000
      00000000000000000000FFFF00000000000000000000BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00BFBFBF0000000000000000000000000000FFFF0000FF
      FF000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000
      000000FFFF0000FFFF0000000000000000000000000000000000000000000000
      00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
      FF00FFFFFF0000FFFF0000000000000000000000000000FFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFF0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000FFFF0000FF
      FF0000FFFF000000000000FFFF0000FFFF0000FFFF0000FFFF00000000000000
      00000000000000FFFF0000000000000000000000000000000000000000000000
      000000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
      FF0000FFFF00FFFFFF0000000000000000000000000000FFFF007F7F7F007F7F
      7F000000000000000000FF000000FF00000000000000000000000000FF000000
      00000000000000000000FFFF00000000000000000000FFFFFF00BFBFBF00FFFF
      FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
      FF00BFBFBF00FFFFFF00BFBFBF0000000000000000000000000000FFFF0000FF
      FF0000FFFF00000000000000000000FFFF0000FFFF00000000000000000000FF
      FF0000FFFF0000FFFF00000000000000000000000000000000000000000000FF
      FF000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
      FF00FFFFFF0000FFFF0000000000000000007F7F7F007F7F7F0000FFFF000000
      00000000000000000000FF000000FF00000000000000000000000000FF000000
      00000000000000000000FFFF00000000000000000000BFBFBF00FFFFFF00BFBF
      BF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBF
      BF00FFFFFF000000FF00FFFFFF0000000000000000000000000000FFFF0000FF
      FF0000FFFF0000FFFF000000000000FFFF00000000000000000000FFFF0000FF
      FF0000FFFF0000FFFF000000000000000000000000000000000000000000FFFF
      FF0000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
      FF0000FFFF00FFFFFF000000000000000000000000000000000000FFFF000000
      00000000000000000000FF000000FF00000000000000000000000000FF000000
      00000000000000000000FFFF00000000000000000000FFFFFF00BFBFBF00FFFF
      FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
      FF00BFBFBF00FFFFFF00BFBFBF0000000000000000000000000000FFFF0000FF
      FF0000FFFF0000FFFF0000000000000000000000000000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000000000000000000000000000FFFF000000000000FF
      FF000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
      FF00FFFFFF0000FFFF000000000000000000000000000000000000FFFF007F7F
      7F007F7F7F0000000000FF000000FF00000000000000000000000000FF000000
      00000000000000000000FFFF0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF0000000000000000000000000000FFFF0000FFFF0000FFFF
      0000FFFF0000FFFF0000000000000000000000000000FFFFFF0000000000FFFF
      FF0000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
      FF0000FFFF00FFFFFF000000000000000000000000007F7F7F007F7F7F0000FF
      FF000000000000000000FF000000FF00000000000000000000000000FF000000
      00000000000000000000FFFF0000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000FFFF0000FFFF
      000000000000FFFF0000BFBFBF0000000000000000000000000000000000FFFF
      0000FFFF0000FFFF000000000000000000000000000000FFFF000000000000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF000080800000000000FF000000FF00000000000000000000000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000000000000000000000000000FFFFFF0000000000FFFF
      FF00000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF000000000000BFBFBF000000000000000000FFFF0000FFFF0000FFFF
      0000FFFF0000FFFF0000000000000000000000000000FFFFFF0000000000FFFF
      FF0000FFFF0000000000FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
      FF000000000000000000000000000000000000000000000000000000000000FF
      FF000080800000000000000000000000000000000000000000000000FF000000
      00000000000000000000FFFF0000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF0000000000000000000000000000FFFF0000FFFF0000FFFF
      0000FFFF0000FFFF000000000000000000000000000000FFFF00000000000000
      0000000000007F7F7F00000000000000000000000000000000007F7F7F000000
      00000000000000000000000000000000000000000000000000007F7F7F000000
      00000000000000000000FF000000FF00000000000000000000000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF0000FFFF00000000000000000000FFFF0000FFFF0000FFFF
      0000FFFF0000FFFF0000000000000000000000000000FFFFFF0000FFFF000000
      0000FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF0000FFFF0000FFFF00000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF000000000000000000000000000000000000000000007F7F
      7F00000000000000000000000000000000007F7F7F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000BFBFBF00FFFFFF0000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF0000FFFF0000FFFF00000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF
      0000FFFF0000FFFF00000000000000000000000000007F7F7F00000000000000
      000000000000000000007F7F7F00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFF0000FFFF
      0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF
      0000FFFF0000FFFF000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000000000000000
      FF00000080000000FF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007F7F7F000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000000000007F7F7F00000000000000
      000000000000FFFFFF00FFFFFF00000000000000000000000000000000000000
      FF00000080000000FF0000000000008080000000000000000000000000000000
      00000000000000000000FFFFFF00000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF0000000000FFFF
      FF000000000000000000FFFFFF00000000007F7F7F0000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      FF00000080000000FF0000808000008080000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF0000000000BFBFBF0000000000BFBFBF000000FF000000FF000000FF00BFBF
      BF0000000000000000000000000000000000FFFF0000000000000000000000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      FF00000080000000FF0000808000008080000000000000000000000000000000
      0000FFFFFF00BFBFBF0000000000FFFFFF00FFFFFF0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF0000000000000000000000000000000000FFFF00000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00000000000000000000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      FF00000080000000FF000080800000000000000000000000000000000000FFFF
      FF00BFBFBF0000000000FFFFFF007F7F7F00FFFFFF00FFFFFF00000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF0000000000BFBFBF0000000000BFBFBF0000000000BFBFBF0000000000BFBF
      BF0000000000000000000000000000000000FFFF000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF000000
      000000000000FFFFFF00FFFFFF0000000000000000007F7F7F00000000000000
      000000000000FFFFFF00000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF00000000000000000000000000FFFFFF007F7F
      7F0000000000FFFFFF0000000000FFFFFF0000000000FFFFFF00FFFFFF000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF0000000000000000000000000000000000FFFF00000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF00000000000000000000000000000000000000000000FF
      FF0000000000FFFFFF00FFFFFF000000000000000000000000007F7F7F000000
      0000FFFFFF00000000007F7F7F00000000000000000000000000000080000000
      800000008000000080000000800000000000000000000000000000000000FFFF
      FF007F7F7F007F7F7F00FFFFFF007F7F7F00FFFFFF0000000000FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000BFBF
      BF0000000000BFBFBF0000000000BFBFBF0000000000BFBFBF0000000000BFBF
      BF0000000000000000000000000000000000FFFF000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000007F7F7F0000000000000000000000000000808000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF007F7F7F0000000000FFFFFF0000000000FFFFFF0000000000FFFF
      FF00FFFFFF00000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF0000000000000000000000000000000000FFFF00000000000000FFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000080800000808000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF007F7F7F007F7F7F00FFFFFF007F7F7F00FFFFFF007F7F
      7F00FFFFFF00FFFFFF000000000000000000000000000000000000000000BFBF
      BF0000000000BFBFBF0000000000BFBFBF0000000000BFBFBF0000000000BFBF
      BF000000000000000000000000000000000000000000000000000000000000FF
      FF00FFFFFF0000FFFF00000000000000000000FFFF0000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000008080000080800000808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF007F7F7F0000000000FFFFFF0000000000FFFF
      FF00000000007F7F7F00FFFFFF0000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF0000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000808000008080000080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF007F7F7F007F7F7F00FFFFFF00FFFF
      FF007F7F7F00FFFFFF000000000000000000000000000000000000000000BFBF
      BF0000000000000000000000000000000000000000000000000000000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000808000008080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF007F7F7F00000000007F7F
      7F00FFFFFF00000000000000000000000000000000000000000000000000BFBF
      BF00000000000000000000000000FFFF000000000000FFFF000000000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000000000FFFFFF00FFFFFF000000000000000000FFFF
      FF0000000000FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000808000000000000000000000000000000000007F7F
      7F00000000007F7F7F0000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF007F7F7F00FFFF
      FF0000000000000000000000000000000000000000000000000000000000BFBF
      BF0000000000000000000000000000000000000000000000000000000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      000000FFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007F7F
      7F00000000007F7F7F0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      FF00000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000008080000000
      00000000000000000000000000007F7F7F000000000000000000000000007F7F
      7F00000000007F7F7F0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007F7F7F000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007F7F7F00000000000000000000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFF8001C003FFFF18080000C003F801
      18080000C003F00118080000C003E00108080000C003C00108080000C0038001
      88080000C003000180080000C00300018008E007C0030003C008E007C0030007
      C008E007C003000FC008E007C003001FF80FE00FC003003FFF8FE01FC00381FF
      FF8FE03FC00381FFFF8FE07FC003FFFFFC00F862FDFFC007FC0080E0F8FFC007
      200001E0F07FC007000001E0E03FC007000031E1C01FC007000031C1800FC007
      0000C181C007C0070000C307E003C0070000FE17F001C0070000CC37F800C007
      E000A877FC01C007F80040F7FE03C007F00001E3FF07C007E001C1E3FF8BC007
      C403C0E3AADBC007EC07C83F5507C00700000000000000000000000000000000
      000000000000}
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 680
    Top = 232
  end
  object OpenDialogIni: TOpenDialog
    DefaultExt = '*.ini'
    Filter = #1092#1072#1081#1083#1099' '#1080#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1080'(*.ini)|*.ini'
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1092#1072#1081#1083' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
    Left = 648
    Top = 296
  end
  object SaveDialogIni: TSaveDialog
    DefaultExt = '*.ini'
    Filter = #1092#1072#1081#1083#1099' '#1082#1086#1092#1080#1075#1091#1088#1072#1094#1080#1080'(*.ini)|*.ini'
    Title = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
    Left = 616
    Top = 264
  end
  object MainMenu1: TMainMenu
    Left = 712
    Top = 232
    object MFile: TMenuItem
      Caption = #1060#1072#1081#1083
      object NOpen: TMenuItem
        Action = AOpenFlyingFile
        Default = True
      end
      object NOpenFormatka: TMenuItem
        Caption = #1060#1086#1088#1084#1072#1090#1082#1072
        object NFormatOpen: TMenuItem
          Caption = #1054#1090#1082#1088#1099#1090#1100
          OnClick = NFormatOpenClick
        end
        object NFormatSave: TMenuItem
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
          Enabled = False
          ImageIndex = 1
        end
        object NFormatSaveAs: TMenuItem
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'...'
          Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'...'
          ImageIndex = 5
          OnClick = NFormatSaveAsClick
        end
      end
      object NRegim: TMenuItem
        Caption = #1056#1077#1078#1080#1084#1099
        Enabled = False
        object NOpenRegim: TMenuItem
          Caption = #1054#1090#1082#1088#1099#1090#1100
          OnClick = NOpenRegimClick
        end
        object NSaveRegim: TMenuItem
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
          Enabled = False
        end
        object NSaveAs: TMenuItem
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'...'
          OnClick = NSaveAsClick
        end
      end
      object NSettings: TMenuItem
        Caption = '&'#1053#1072#1089#1090#1088#1086#1081#1082#1072
        object NSettingsOpen: TMenuItem
          Action = AOpenINI
          Caption = #1054#1090#1082#1088#1099#1090#1100
        end
        object NSettingsSave: TMenuItem
          Action = ASaveINI
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        end
        object NSettingsSaveAs: TMenuItem
          Action = ASaveINIAs
        end
      end
      object NLibrary: TMenuItem
        Caption = '&'#1041#1080#1073#1083#1080#1086#1090#1077#1082#1072
        Enabled = False
        object LibraryOpen: TMenuItem
          Caption = #1054#1090#1082#1088#1099#1090#1100
        end
        object LibraryClose: TMenuItem
          Caption = #1047#1072#1082#1088#1099#1090#1100
        end
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object NSaveGraphtAs: TMenuItem
        Caption = '&'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1075#1088#1072#1092#1080#1082' '#1082#1072#1082'...'
        Enabled = False
      end
      object NExport: TMenuItem
        Caption = #1069#1082#1089#1087#1086#1088#1090
        Enabled = False
        object NExportTXT: TMenuItem
          Caption = #1058#1077#1082#1089#1090#1086#1074#1099#1081' '#1092#1072#1081#1083
        end
        object NExportEXC: TMenuItem
          Caption = 'Ex'#1089'el '#1092#1072#1081#1083
        end
      end
      object NOpenTxt: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' TXT'
        Enabled = False
        OnClick = NOpenTxtClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object NPrint: TMenuItem
        Action = ChartActionPrint1
        Caption = '&'#1055#1077#1095#1072#1090#1100
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object NExit: TMenuItem
        Action = Exit
        Caption = #1042#1099#1093#1086#1076
      end
    end
    object MParametrs: TMenuItem
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      OnClick = MParametrsClick
    end
    object MEdit: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
      OnClick = MEditClick
    end
    object Mmanagement: TMenuItem
      Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      OnClick = MmanagementClick
    end
    object MLibrary: TMenuItem
      Caption = #1041#1080#1073#1083#1080#1086#1090#1077#1082#1072
      Enabled = False
      Visible = False
    end
    object Mregime: TMenuItem
      Caption = #1056#1077#1078#1080#1084
      Enabled = False
      Visible = False
    end
    object MHelp: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object NInfo: TMenuItem
        Action = AInfo
        Caption = #1048#1085#1092#1086
      end
      object NAbout: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
        OnClick = NAboutClick
      end
    end
    object N4: TMenuItem
      Caption = #1056#1072#1089#1095#1077#1090#1085#1099#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1099
      object N6: TMenuItem
        Caption = #1057#1086#1079#1076#1072#1085#1080#1077' '#1080' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
        OnClick = N6Click
      end
      object N7: TMenuItem
        Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100
        OnClick = N7Click
      end
      object N8: TMenuItem
        Caption = #1054#1090#1082#1083#1102#1095#1080#1090#1100
        OnClick = N8Click
      end
    end
  end
  object ActionList1: TActionList
    Images = ImageList1
    Left = 744
    Top = 232
    object Exit: TFileExit
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'Exit|Quits the application'
      ImageIndex = 2
    end
    object AOpenINI: TAction
      Category = 'Open'
      Caption = #1060#1072#1081#1083' '#1080#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1080
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1080#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1080
      ImageIndex = 10
      OnExecute = AOpenINIExecute
    end
    object ASaveINIAs: TAction
      Category = 'Save'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'...'
      OnExecute = ASaveINIAsExecute
    end
    object AOpenLibrary: TAction
      Category = 'Open'
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1073#1080#1073#1083#1080#1086#1090#1077#1082#1091
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1073#1080#1073#1083#1080#1086#1090#1077#1082#1091
      ImageIndex = 12
    end
    object AOpenMode: TAction
      Category = 'Open'
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1088#1077#1078#1080#1084
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1088#1077#1078#1080#1084
      ImageIndex = 11
    end
    object ChartActionPrint1: TChartActionPrint
      Category = 'File'
      Caption = '&Print...'
      Hint = 'Print preview Chart'
      ImageIndex = 3
      OnExecute = ChartActionPrint1Execute
    end
    object ASaveINI: TAction
      Category = 'Save'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1080#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1080
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1080#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1080
      OnExecute = ASaveINIExecute
    end
    object ASaveMode: TAction
      Category = 'Save'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100'  '#1088#1077#1078#1080#1084
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1088#1077#1078#1080#1084
    end
    object ASaveAll: TAction
      Category = 'Save'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074#1089#1077
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074#1089#1077
      OnExecute = ASaveAllExecute
    end
    object ASaveAsPicture: TAction
      Category = 'Save'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' '#1088#1080#1089#1091#1085#1086#1082'...'
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' '#1088#1080#1089#1091#1085#1086#1082
    end
    object AAxisMove: TAction
      Category = 'Axes'
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077' '#1086#1089#1080
      Hint = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077' '#1086#1089#1080
      ImageIndex = 4
    end
    object AAxisStretch: TAction
      Category = 'Axes'
      Caption = #1056#1072#1089#1090#1103#1075#1080#1074#1072#1085#1080#1077' '#1086#1089#1080
      Hint = #1056#1072#1089#1090#1103#1075#1080#1074#1072#1085#1080#1077' '#1086#1089#1080
      ImageIndex = 6
    end
    object AAxisAdd: TAction
      Category = 'Axes'
      Caption = #1059#1074#1077#1083#1080#1095#1077#1085#1080#1077' '#1086#1089#1080
      Hint = #1059#1074#1077#1083#1080#1095#1077#1085#1080#1077' '#1086#1089#1080
      ImageIndex = 5
    end
    object AAxisDelete: TAction
      Category = 'Axes'
      Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1086#1089#1080
      Hint = #1059#1076#1072#1083#1077#1085#1080#1077' '#1086#1089#1080
      ImageIndex = 7
    end
    object AAxisSetMinMax: TAction
      Category = 'Axes'
      Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072' Min Max'
      HelpKeyword = #1059#1089#1090#1072#1085#1086#1074#1082#1072' Min Max'
      ImageIndex = 8
    end
    object AOpenFlyingFile: TAction
      Category = 'Open'
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1087#1086#1083#1077#1090#1072
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1087#1086#1083#1077#1090#1072
      ImageIndex = 0
      OnExecute = AOpenFlyingFileExecute
    end
    object AInfo: TAction
      Category = 'File'
      Caption = 'AInfo'
      ImageIndex = 13
      OnExecute = AInfoExecute
    end
  end
  object OpenDialogFileRashet: TOpenDialog
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1092#1072#1081#1083' '#1088#1072#1089#1095#1077#1090#1072
    Left = 648
    Top = 360
  end
  object LabelPopupMenu: TPopupMenu
    Left = 712
    Top = 328
    object LableFontMenu: TMenuItem
      Caption = #1064#1088#1080#1092#1090
    end
    object LabelDeleteMenu: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = LabelDeleteMenuClick
    end
  end
  object PopupMenuTab: TPopupMenu
    Left = 712
    Top = 360
    object NnewTab: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1074#1082#1083#1072#1076#1082#1072
      OnClick = NnewTab2Click
    end
    object NCopyTab: TMenuItem
      Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
      Enabled = False
    end
    object NPasteTab: TMenuItem
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100
      Enabled = False
    end
    object NRenameTab: TMenuItem
      Caption = #1055#1077#1088#1077#1080#1084#1077#1085#1086#1074#1072#1090#1100
      OnClick = NRenameTabClick
    end
    object NDeleteTab: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = NDeleteTabClick
    end
  end
  object OpenDialogMode: TOpenDialog
    DefaultExt = '*.tee'
    Filter = #1060#1072#1081#1083#1099' '#1088#1077#1078#1080#1084#1086#1074' (*.tee)|*.tee'
    Options = [ofHideReadOnly, ofExtensionDifferent, ofFileMustExist, ofCreatePrompt, ofEnableSizing]
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1092#1072#1081#1083' '#1088#1077#1078#1080#1084#1072
    Left = 648
    Top = 328
  end
  object SaveDialogMode: TSaveDialog
    DefaultExt = '*.tee'
    Filter = #1060#1072#1081#1083#1099' '#1088#1077#1078#1080#1084#1086#1074' (*.tee)|*.tee'
    Title = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1078#1080#1084#1072
    Left = 616
    Top = 296
  end
  object OpenDialogTxt: TOpenDialog
    DefaultExt = '*.txt'
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1077' '#1092#1072#1081#1083#1099' (*.txt)|*.txt'
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1090#1077#1082#1089#1090#1086#1074#1099#1081' '#1092#1072#1081#1083
    Left = 648
    Top = 392
  end
end
