object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 407
  ClientWidth = 541
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
  object Edit1: TEdit
    Left = 128
    Top = 32
    Width = 281
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
    Left = 128
    Top = 80
    Width = 281
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
    Left = 128
    Top = 128
    Width = 281
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
    Left = 112
    Top = 192
    Width = 297
    Height = 185
    DefaultColWidth = 40
    FixedCols = 0
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs, goFixedRowDefAlign]
    ParentFont = False
    TabOrder = 3
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 32
    object Numeros1: TMenuItem
      Caption = 'Cadenas'
      object CantDigParesDif1: TMenuItem
        Caption = 'CantDigParesDif'
        OnClick = CantDigParesDif1Click
      end
      object GetDigPares1: TMenuItem
        Caption = 'GetDigPares'
        OnClick = GetDigPares1Click
      end
      object GetDigPares2: TMenuItem
        Caption = 'MayorMenor'
        OnClick = GetDigPares2Click
      end
      object MayorMenor21: TMenuItem
        Caption = 'MayorMenor2'
        OnClick = MayorMenor21Click
      end
      object ElimPrimNum1: TMenuItem
        Caption = 'ElimPrimerNum'
        OnClick = ElimPrimNum1Click
      end
      object PalMasLarga1: TMenuItem
        Caption = 'PalMasLarga'
        OnClick = PalMasLarga1Click
      end
      object MoverMenor1: TMenuItem
        Caption = 'MoverMenor'
        OnClick = MoverMenor1Click
      end
      object CadenaDeDig1: TMenuItem
        Caption = 'CadenaDeDig'
        OnClick = CadenaDeDig1Click
      end
      object SumaNum1: TMenuItem
        Caption = 'SumaNum'
        OnClick = SumaNum1Click
      end
      object ElimPares1: TMenuItem
        Caption = 'ElimPares'
        OnClick = ElimPares1Click
      end
      object ContadorDeSignos1: TMenuItem
        Caption = 'ContadorDeSignos'
        OnClick = ContadorDeSignos1Click
      end
      object ElimUltNum1: TMenuItem
        Caption = 'ElimUltNum'
        OnClick = ElimUltNum1Click
      end
      object InvertirCad1: TMenuItem
        Caption = 'InvertirCad'
        OnClick = InvertirCad1Click
      end
      object ContadorPalabras1: TMenuItem
        Caption = 'ContadorPalabras'
        OnClick = ContadorPalabras1Click
      end
      object ElimVocales1: TMenuItem
        Caption = 'ElimVocales'
        OnClick = ElimVocales1Click
      end
      object ElimPrimerLetra1: TMenuItem
        Caption = 'ElimPrimerLetra'
        OnClick = ElimPrimerLetra1Click
      end
      object InvertirPalabra1: TMenuItem
        Caption = 'InvertirPalabra'
        OnClick = InvertirPalabra1Click
      end
    end
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
      object N11: TMenuItem
        Caption = '11'
        OnClick = N11Click
      end
      object N12: TMenuItem
        Caption = '12'
        OnClick = N12Click
      end
      object N131: TMenuItem
        Caption = '13'
        OnClick = N131Click
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
        Caption = '16'
        OnClick = N161Click
      end
      object N162: TMenuItem
        Caption = '17'
        OnClick = N162Click
      end
      object N181: TMenuItem
        Caption = '18'
        OnClick = N181Click
      end
      object N182: TMenuItem
        Caption = '19'
        OnClick = N182Click
      end
      object N201: TMenuItem
        Caption = '20'
        OnClick = N201Click
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
      object N231: TMenuItem
        Caption = '23'
        OnClick = N231Click
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
      end
      object N281: TMenuItem
        Caption = '28'
      end
      object N282: TMenuItem
        Caption = '29'
      end
      object N301: TMenuItem
        Caption = '30'
      end
    end
  end
end
