object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 495
  ClientWidth = 680
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
    Left = 160
    Top = 16
    Width = 361
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
    Left = 160
    Top = 67
    Width = 361
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
    Left = 160
    Top = 120
    Width = 361
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 8
    Top = 176
    Width = 146
    Height = 25
    Caption = 'Redimencionar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 160
    Top = 176
    Width = 361
    Height = 25
    ColCount = 9
    DefaultColWidth = 35
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs, goFixedRowDefAlign]
    ParentFont = False
    TabOrder = 4
  end
  object StringGrid2: TStringGrid
    Left = 160
    Top = 240
    Width = 361
    Height = 233
    DefaultColWidth = 40
    DefaultRowHeight = 30
    FixedCols = 0
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs, goFixedRowDefAlign]
    TabOrder = 5
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 16
    object Nmeros1: TMenuItem
      Caption = 'N'#250'meros '
      object Nmeros2: TMenuItem
        Caption = 'SumaDig'
        OnClick = Nmeros2Click
      end
      object SumaDigPrim1: TMenuItem
        Caption = 'SumaDigPrim'
        OnClick = SumaDigPrim1Click
      end
      object SumaDigPrim2: TMenuItem
        Caption = 'Menor'
        OnClick = SumaDigPrim2Click
      end
      object Mayor1: TMenuItem
        Caption = 'Mayor'
        OnClick = Mayor1Click
      end
      object ManorAlFinal1: TMenuItem
        Caption = 'ManorAlFinal'
        OnClick = ManorAlFinal1Click
      end
      object Ordenar1: TMenuItem
        Caption = 'Ordenar'
        OnClick = Ordenar1Click
      end
    end
    object Cadenas1: TMenuItem
      Caption = 'Cadenas'
      object CantVocales1: TMenuItem
        Caption = 'CantVocales'
        OnClick = CantVocales1Click
      end
      object Invertir1: TMenuItem
        Caption = 'Invertir '
        OnClick = Invertir1Click
      end
      object ElimNoAlfabticos1: TMenuItem
        Caption = 'ElimNoLetras'
        OnClick = ElimNoAlfabticos1Click
      end
    end
    object Cadenas2: TMenuItem
      Caption = 'Vectores'
      object N11: TMenuItem
        Caption = '11-04'
        OnClick = N11Click
      end
      object BusBin1: TMenuItem
        Caption = 'BusBin'
        OnClick = BusBin1Click
      end
      object Ordenamiento1: TMenuItem
        Caption = 'Ordenamiento'
        OnClick = Ordenamiento1Click
      end
    end
    object Martices1: TMenuItem
      Caption = 'Martices'
      object Martices2: TMenuItem
        Caption = 'Randomicamente'
        OnClick = Martices2Click
      end
      object Clase1: TMenuItem
        Caption = 'Clase'
      end
      object Clase2: TMenuItem
        Caption = 'Hola'
      end
      object MatricescomoVectores1: TMenuItem
        Caption = 'Matrices como Vectores'
        OnClick = MatricescomoVectores1Click
      end
      object ContarlaCantidaddeDatosxenlamatriz1: TMenuItem
        Caption = 'Contar la Cantidad de Datos x en la matriz'
        OnClick = ContarlaCantidaddeDatosxenlamatriz1Click
      end
      object BusquedaBinaria1: TMenuItem
        Caption = 'Busqueda Binaria '
        OnClick = BusquedaBinaria1Click
      end
    end
  end
end
