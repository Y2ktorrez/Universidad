object Form1: TForm1
  Left = 683
  Top = 55
  Caption = 'Form1'
  ClientHeight = 422
  ClientWidth = 648
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 16
    Top = 22
    Width = 241
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 16
    Top = 59
    Width = 241
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 16
    Top = 102
    Width = 241
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 160
    Width = 401
    Height = 217
    DefaultColWidth = 48
    FixedCols = 0
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs, goFixedRowDefAlign]
    TabOrder = 3
  end
  object Button1: TButton
    Left = 284
    Top = 22
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 284
    Top = 59
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 284
    Top = 90
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 6
  end
  object Button4: TButton
    Left = 439
    Top = 160
    Width = 118
    Height = 25
    Caption = 'Dimencionar Vector'
    TabOrder = 7
    OnClick = Button4Click
  end
end
