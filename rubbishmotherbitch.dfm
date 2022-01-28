object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 873
  ClientWidth = 1088
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnActivate = FormActivate
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object im1: TImage
    Left = 40
    Top = 24
    Width = 400
    Height = 400
    OnMouseDown = im1MouseDown
  end
  object im2: TImage
    Left = 487
    Top = 24
    Width = 400
    Height = 400
  end
  object Label1: TLabel
    Left = 922
    Top = 51
    Width = 31
    Height = 13
    Caption = 'X-MAX'
  end
  object Label2: TLabel
    Left = 922
    Top = 78
    Width = 31
    Height = 13
    Caption = 'Y-MAX'
  end
  object Label3: TLabel
    Left = 919
    Top = 105
    Width = 34
    Height = 13
    Caption = #1059#1043#1054#1051#1068
  end
  object Label4: TLabel
    Left = 922
    Top = 132
    Width = 19
    Height = 13
    Caption = #1082#1101#1092
  end
  object Label5: TLabel
    Left = 192
    Top = 436
    Width = 92
    Height = 13
    Caption = #1042#1067#1041#1056#1040#1053#1067#1045' '#1058#1054#1063#1050#1048
  end
  object Label6: TLabel
    Left = 360
    Top = 436
    Width = 146
    Height = 13
    Caption = #1052#1040#1058#1056#1048#1062#1040' '#1055#1056#1045#1054#1041#1056#1040#1047#1054#1042#1040#1053#1048#1071
  end
  object Label7: TLabel
    Left = 24
    Top = 436
    Width = 140
    Height = 13
    Caption = #1048#1057#1061#1054#1044#1053#1067#1045' '#1058#1054#1063#1050#1048' '#1060#1048#1043#1059#1056#1067
  end
  object Label8: TLabel
    Left = 551
    Top = 436
    Width = 188
    Height = 13
    Caption = #1058#1054#1063#1050#1048' '#1055#1056#1045#1054#1041#1056#1040#1047#1054#1042#1040#1053#1053#1054#1049' '#1060#1048#1043#1059#1056#1067' '
  end
  object Button1: TButton
    Left = 360
    Top = 550
    Width = 137
    Height = 25
    Caption = #1089#1074#1086#1077' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077
    TabOrder = 0
    OnClick = Button1Click
  end
  object sg1: TStringGrid
    Left = 8
    Top = 455
    Width = 161
    Height = 217
    ColCount = 2
    FixedCols = 0
    RowCount = 8
    FixedRows = 0
    TabOrder = 1
    ColWidths = (
      64
      64)
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object rb1: TRadioButton
    Left = 752
    Top = 496
    Width = 113
    Height = 17
    Caption = #1087#1077#1088#1077#1085#1086#1089
    TabOrder = 2
    OnClick = rb1Click
  end
  object rb2: TRadioButton
    Left = 752
    Top = 536
    Width = 113
    Height = 17
    Caption = #1084#1072#1096#1090#1072#1073#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 3
  end
  object sg2: TStringGrid
    Left = 175
    Top = 455
    Width = 145
    Height = 58
    ColCount = 2
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    TabOrder = 4
    ColWidths = (
      64
      64)
    RowHeights = (
      24
      24)
  end
  object e1: TEdit
    Left = 959
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '10'
  end
  object e2: TEdit
    Left = 959
    Top = 75
    Width = 121
    Height = 21
    TabOrder = 6
    Text = '10'
  end
  object sg3: TStringGrid
    Left = 336
    Top = 455
    Width = 209
    Height = 89
    ColCount = 3
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 7
    ColWidths = (
      64
      64
      64)
    RowHeights = (
      24
      24
      24)
  end
  object sg4: TStringGrid
    Left = 551
    Top = 455
    Width = 169
    Height = 213
    ColCount = 2
    FixedCols = 0
    RowCount = 8
    FixedRows = 0
    TabOrder = 8
    ColWidths = (
      64
      64)
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object cb1: TCheckBox
    Left = 936
    Top = 156
    Width = 97
    Height = 17
    Caption = #1054#1057#1068
    TabOrder = 9
    OnClick = cb1Click
  end
  object cb2: TCheckBox
    Left = 936
    Top = 179
    Width = 89
    Height = 17
    Caption = #1057#1045#1058#1050#1040
    TabOrder = 10
    OnClick = cb2Click
  end
  object cb3: TCheckBox
    Left = 936
    Top = 202
    Width = 137
    Height = 17
    Caption = #1063#1048#1057#1051#1040
    TabOrder = 11
    OnClick = cb3Click
  end
  object cb4: TCheckBox
    Left = 936
    Top = 225
    Width = 144
    Height = 17
    Caption = #1053#1040#1056#1048#1057#1054#1042#1040#1058#1068' '#1052#1067#1065#1050#1054#1049
    TabOrder = 12
  end
  object cb5: TCheckBox
    Left = 752
    Top = 655
    Width = 97
    Height = 17
    Caption = #1076#1080#1085#1072#1084#1080#1095#1077#1089#1082#1080#1081
    TabOrder = 13
    OnClick = cb5Click
  end
  object rb3: TRadioButton
    Left = 752
    Top = 568
    Width = 113
    Height = 17
    Caption = #1086#1090#1088#1086#1078#1077#1085#1080#1077
    TabOrder = 14
  end
  object rb4: TRadioButton
    Left = 752
    Top = 599
    Width = 135
    Height = 17
    Caption = #1087#1086#1074#1086#1088#1086#1090'-'#1072#1082#1090#1080#1074#1085#1099#1081
    TabOrder = 15
  end
  object rb5: TRadioButton
    Left = 752
    Top = 630
    Width = 129
    Height = 17
    Caption = #1087#1086#1074#1086#1088#1086#1090'-'#1087#1072#1089#1089#1080#1074#1085#1099#1081
    TabOrder = 16
  end
  object e3: TEdit
    Left = 959
    Top = 102
    Width = 121
    Height = 21
    TabOrder = 17
    Text = '0'
    OnChange = e3Change
  end
  object e4: TEdit
    Left = 959
    Top = 129
    Width = 121
    Height = 21
    TabOrder = 18
    Text = '0'
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 408
    Top = 592
  end
end
