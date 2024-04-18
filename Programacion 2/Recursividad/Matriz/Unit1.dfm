object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 462
  ClientWidth = 582
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
    Top = 176
    Width = 320
    Height = 224
    DefaultColWidth = 40
    DefaultRowHeight = 30
    FixedCols = 0
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs, goFixedRowDefAlign]
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 128
    Top = 48
    Width = 185
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
    Left = 128
    Top = 88
    Width = 185
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
    Left = 128
    Top = 128
    Width = 185
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
    Left = 384
    Top = 54
    Width = 75
    Height = 25
    Caption = 'Dimencionar'
    TabOrder = 4
  end
  object Button2: TButton
    Left = 384
    Top = 94
    Width = 75
    Height = 25
    Caption = 'Random'
    TabOrder = 5
    OnClick = Button2Click
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 48
    object Matrices1: TMenuItem
      Caption = 'Matrices'
      object Matrices2: TMenuItem
        Caption = '1'
        OnClick = Matrices2Click
      end
      object N21: TMenuItem
        Caption = '2'
        OnClick = N21Click
      end
      object N22: TMenuItem
        Caption = '3'
        OnClick = N22Click
      end
      object N41: TMenuItem
        Caption = '4'
        OnClick = N41Click
      end
      object N42: TMenuItem
        Caption = '5'
        OnClick = N42Click
      end
      object N61: TMenuItem
        Caption = '6'
        OnClick = N61Click
      end
      object N62: TMenuItem
        Caption = '7'
        OnClick = N62Click
      end
      object N81: TMenuItem
        Caption = '8'
        OnClick = N81Click
      end
      object N82: TMenuItem
        Caption = '9'
        OnClick = N82Click
      end
      object N101: TMenuItem
        Caption = '10'
        OnClick = N101Click
      end
    end
    object N102: TMenuItem
      Caption = 'Seguimos'
      object N111: TMenuItem
        Caption = '11'
        OnClick = N111Click
      end
      object N112: TMenuItem
        Caption = '12'
        OnClick = N112Click
      end
      object N131: TMenuItem
        Caption = '13'
        OnClick = N131Click
      end
      object N132: TMenuItem
        Caption = '14'
        OnClick = N132Click
      end
      object N151: TMenuItem
        Caption = '15'
        OnClick = N151Click
      end
      object N152: TMenuItem
        Caption = '16'
        OnClick = N152Click
      end
      object N171: TMenuItem
        Caption = '17'
        OnClick = N171Click
      end
      object N172: TMenuItem
        Caption = '18'
        OnClick = N172Click
      end
      object N191: TMenuItem
        Caption = '19'
        OnClick = N191Click
      end
      object N192: TMenuItem
        Caption = '20'
        OnClick = N192Click
      end
    end
    object Seguimos1: TMenuItem
      Caption = 'Seguimos'
      object Seguimos2: TMenuItem
        Caption = '21'
        OnClick = Seguimos2Click
      end
      object N221: TMenuItem
        Caption = '22'
        OnClick = N221Click
      end
      object N222: TMenuItem
        Caption = '23'
        OnClick = N222Click
      end
      object N251: TMenuItem
        Caption = '24'
        OnClick = N251Click
      end
      object N252: TMenuItem
        Caption = '25'
        OnClick = N252Click
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
      object N282: TMenuItem
        Caption = '29'
        OnClick = N282Click
      end
      object N301: TMenuItem
        Caption = '30'
        OnClick = N301Click
      end
    end
    object Seguimos3: TMenuItem
      Caption = 'Seguimos'
      object Seguimos4: TMenuItem
        Caption = '31'
        OnClick = Seguimos4Click
      end
      object N321: TMenuItem
        Caption = '32'
        OnClick = N321Click
      end
      object N322: TMenuItem
        Caption = '33 (26)'
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
      object N361: TMenuItem
        Caption = '36'
        OnClick = N361Click
      end
      object N362: TMenuItem
        Caption = '37'
        OnClick = N362Click
      end
      object N381: TMenuItem
        Caption = '38'
        OnClick = N381Click
      end
      object N382: TMenuItem
        Caption = '39'
        OnClick = N382Click
      end
      object N401: TMenuItem
        Caption = '40'
        OnClick = N401Click
      end
    end
    object Seguimos5: TMenuItem
      Caption = 'Seguimos'
      object Seguimos6: TMenuItem
        Caption = '41'
        OnClick = Seguimos6Click
      end
      object N421: TMenuItem
        Caption = '42'
        OnClick = N421Click
      end
      object N422: TMenuItem
        Caption = '43'
        OnClick = N422Click
      end
      object N441: TMenuItem
        Caption = '44'
        OnClick = N441Click
      end
      object N442: TMenuItem
        Caption = '45'
        OnClick = N442Click
      end
      object N461: TMenuItem
        Caption = '46'
        OnClick = N461Click
      end
      object N471: TMenuItem
        Caption = '47'
        OnClick = N471Click
      end
      object N472: TMenuItem
        Caption = '48'
        OnClick = N472Click
      end
      object N491: TMenuItem
        Caption = '49'
        OnClick = N491Click
      end
      object N492: TMenuItem
        Caption = '50'
        OnClick = N492Click
      end
    end
    object Seguimos7: TMenuItem
      Caption = 'Seguimos'
      object Seguimos8: TMenuItem
        Caption = '51'
        OnClick = Seguimos8Click
      end
      object N521: TMenuItem
        Caption = '52'
        OnClick = N521Click
      end
      object N522: TMenuItem
        Caption = '53'
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
        Caption = '58'
        OnClick = N581Click
      end
      object N582: TMenuItem
        Caption = '59'
        OnClick = N582Click
      end
      object N601: TMenuItem
        Caption = '60'
        OnClick = N601Click
      end
    end
    object Seguimos9: TMenuItem
      Caption = 'Seguimos'
      object N611: TMenuItem
        Caption = '61'
        OnClick = N611Click
      end
      object N612: TMenuItem
        Caption = '62'
        OnClick = N612Click
      end
      object N631: TMenuItem
        Caption = '63'
        OnClick = N631Click
      end
      object N632: TMenuItem
        Caption = '64'
        OnClick = N632Click
      end
      object N651: TMenuItem
        Caption = '65'
        OnClick = N651Click
      end
      object N661: TMenuItem
        Caption = '66'
        OnClick = N661Click
      end
      object N662: TMenuItem
        Caption = '67'
        OnClick = N662Click
      end
      object N681: TMenuItem
        Caption = '68'
        OnClick = N681Click
      end
      object N682: TMenuItem
        Caption = '69'
        OnClick = N682Click
      end
      object N701: TMenuItem
        Caption = '70'
        OnClick = N701Click
      end
    end
  end
end
