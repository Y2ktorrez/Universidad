object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 342
  ClientWidth = 590
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 80
    Top = 168
    Width = 457
    Height = 33
    DefaultColWidth = 40
    FixedCols = 0
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs, goFixedRowDefAlign]
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 152
    Top = 24
    Width = 329
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 152
    Top = 64
    Width = 329
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 152
    Top = 104
    Width = 329
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object Button1: TButton
    Left = 16
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Dimencionar'
    TabOrder = 4
    OnClick = Button1Click
  end
  object StringGrid2: TStringGrid
    Left = 80
    Top = 224
    Width = 457
    Height = 33
    DefaultColWidth = 40
    FixedCols = 0
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs, goFixedRowDefAlign]
    TabOrder = 5
  end
  object Button2: TButton
    Left = 16
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Limpiar'
    TabOrder = 6
    OnClick = Button2Click
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 32
    object N11: TMenuItem
      Caption = 'Vectores'
      object N12: TMenuItem
        Caption = '1'
        OnClick = N12Click
      end
      object N13: TMenuItem
        Caption = '2'
        OnClick = N13Click
      end
      object N31: TMenuItem
        Caption = '3'
        OnClick = N31Click
      end
      object N32: TMenuItem
        Caption = '4'
        OnClick = N32Click
      end
      object N51: TMenuItem
        Caption = '5'
        OnClick = N51Click
      end
      object N52: TMenuItem
        Caption = '6'
        OnClick = N52Click
      end
      object N71: TMenuItem
        Caption = '7  REVISAR'
        OnClick = N71Click
      end
      object N72: TMenuItem
        Caption = '8 revisar'
        OnClick = N72Click
      end
      object N91: TMenuItem
        Caption = '9 REVISAR'
        OnClick = N91Click
      end
      object N92: TMenuItem
        Caption = '10'
        OnClick = N92Click
      end
    end
    object Seguimos1: TMenuItem
      Caption = 'Seguimos'
      object Seguimos2: TMenuItem
        Caption = '11'
        OnClick = Seguimos2Click
      end
      object N121: TMenuItem
        Caption = '12'
        OnClick = N121Click
      end
      object N122: TMenuItem
        Caption = '13'
        OnClick = N122Click
      end
      object N141: TMenuItem
        Caption = '14'
        OnClick = N141Click
      end
      object N142: TMenuItem
        Caption = '15'
        OnClick = N142Click
      end
      object N161: TMenuItem
        Caption = '16 REVISAR'
        OnClick = N161Click
      end
      object N162: TMenuItem
        Caption = '17 REVISAR'
        OnClick = N162Click
      end
      object N181: TMenuItem
        Caption = '18'
        OnClick = N181Click
      end
      object N182: TMenuItem
        Caption = '19 REVISAR'
        OnClick = N182Click
      end
      object N201: TMenuItem
        Caption = '20'
        OnClick = N201Click
      end
    end
    object Seguimos3: TMenuItem
      Caption = 'Seguimos'
      object Seguimos4: TMenuItem
        Caption = '21'
        OnClick = Seguimos4Click
      end
      object N221: TMenuItem
        Caption = '22'
        OnClick = N221Click
      end
      object N222: TMenuItem
        Caption = '23'
        OnClick = N222Click
      end
      object N241: TMenuItem
        Caption = '24'
        OnClick = N241Click
      end
      object N242: TMenuItem
        Caption = '25'
        OnClick = N242Click
      end
      object N261: TMenuItem
        Caption = '26'
        OnClick = N261Click
      end
      object N262: TMenuItem
        Caption = '27'
        OnClick = N262Click
      end
      object N281: TMenuItem
        Caption = '28'
        OnClick = N281Click
      end
      object N291: TMenuItem
        Caption = '29'
        OnClick = N291Click
      end
      object N292: TMenuItem
        Caption = '30'
        OnClick = N292Click
      end
    end
    object Seguimos5: TMenuItem
      Caption = 'Seguimos'
      object Seguimos6: TMenuItem
        Caption = '31'
        OnClick = Seguimos6Click
      end
      object N321: TMenuItem
        Caption = '32'
        OnClick = N321Click
      end
      object N322: TMenuItem
        Caption = '33'
        OnClick = N322Click
      end
      object N341: TMenuItem
        Caption = '34'
        OnClick = N341Click
      end
      object N342: TMenuItem
        Caption = '35'
        OnClick = N342Click
      end
      object N351: TMenuItem
        Caption = '36'
        OnClick = N351Click
      end
      object N371: TMenuItem
        Caption = '37'
        OnClick = N371Click
      end
      object N372: TMenuItem
        Caption = '38'
        OnClick = N372Click
      end
      object N391: TMenuItem
        Caption = '39'
        OnClick = N391Click
      end
      object N392: TMenuItem
        Caption = '40'
        OnClick = N392Click
      end
    end
    object Seguimos7: TMenuItem
      Caption = 'Seguimos'
      object N411: TMenuItem
        Caption = '41'
        OnClick = N411Click
      end
      object N412: TMenuItem
        Caption = '42'
        OnClick = N412Click
      end
      object N431: TMenuItem
        Caption = '43'
        OnClick = N431Click
      end
      object N432: TMenuItem
        Caption = '44'
        OnClick = N432Click
      end
      object N451: TMenuItem
        Caption = '45'
        OnClick = N451Click
      end
      object N452: TMenuItem
        Caption = '46'
        OnClick = N452Click
      end
      object N471: TMenuItem
        Caption = '47'
        OnClick = N471Click
      end
      object N481: TMenuItem
        Caption = '48'
        OnClick = N481Click
      end
      object N482: TMenuItem
        Caption = '49'
        OnClick = N482Click
      end
      object N501: TMenuItem
        Caption = '50'
        OnClick = N501Click
      end
    end
    object Seguimos8: TMenuItem
      Caption = 'Seguimos'
      object N511: TMenuItem
        Caption = '51 REPETIDA'
        OnClick = N511Click
      end
      object N521: TMenuItem
        Caption = '52'
        OnClick = N521Click
      end
      object N522: TMenuItem
        Caption = '53 REVISAR'
        OnClick = N522Click
      end
      object N541: TMenuItem
        Caption = '54'
        OnClick = N541Click
      end
      object N542: TMenuItem
        Caption = '55'
        OnClick = N542Click
      end
      object N561: TMenuItem
        Caption = '56'
        OnClick = N561Click
      end
      object N562: TMenuItem
        Caption = '57'
        OnClick = N562Click
      end
      object N581: TMenuItem
        Caption = '58 REVISAR'
        OnClick = N581Click
      end
      object N582: TMenuItem
        Caption = '59'
        OnClick = N582Click
      end
      object N601: TMenuItem
        Caption = '60'
      end
    end
  end
end
