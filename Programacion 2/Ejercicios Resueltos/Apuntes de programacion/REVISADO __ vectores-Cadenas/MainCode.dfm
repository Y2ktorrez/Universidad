object MyForm: TMyForm
  Left = 0
  Top = 0
  Caption = 'MyForm'
  ClientHeight = 653
  ClientWidth = 1139
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 368
    Top = 23
    Width = 141
    Height = 35
    Caption = 'ENTRADA'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 368
    Top = 127
    Width = 111
    Height = 35
    Caption = 'SALIDA'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 967
    Top = -9
    Width = 147
    Height = 35
    Caption = 'AUXILIAR'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblColumnas: TLabel
    Left = 296
    Top = 319
    Width = 9
    Height = 35
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 24
    Top = 319
    Width = 250
    Height = 35
    Caption = 'Nro de Columnas'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object txtEntrada: TEdit
    Left = 24
    Top = 64
    Width = 793
    Height = 43
    Alignment = taCenter
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object txtSalida: TEdit
    Left = 24
    Top = 168
    Width = 793
    Height = 43
    Alignment = taCenter
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object Cajita: TListBox
    Left = 960
    Top = 88
    Width = 169
    Height = 465
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ItemHeight = 58
    ParentFont = False
    TabOrder = 2
  end
  object txtAuxiliar: TEdit
    Left = 960
    Top = 32
    Width = 169
    Height = 43
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
  end
  object SGVector: TStringGrid
    Left = 24
    Top = 233
    Width = 905
    Height = 48
    ColCount = 1
    DefaultColWidth = 120
    DefaultRowHeight = 35
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    GridLineWidth = 10
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    ParentFont = False
    ScrollBars = ssNone
    TabOrder = 4
  end
  object SBVector: TScrollBar
    Left = 24
    Top = 280
    Width = 905
    Height = 33
    PageSize = 0
    Position = 1
    TabOrder = 5
    OnChange = SBVectorChange
  end
  object MainMenu1: TMainMenu
    Left = 1064
    Top = 592
    object ALGORITMOS1: TMenuItem
      Caption = 'ALGORITMOS'
      object Ejercicio11: TMenuItem
        Caption = 'Ejercicio 1'
        OnClick = Ejercicio11Click
      end
      object Ejercicio21: TMenuItem
        Caption = 'Ejercicio 2'
        OnClick = Ejercicio21Click
      end
      object Ejercicio31: TMenuItem
        Caption = 'Ejercicio 3'
      end
      object Ejercicio41: TMenuItem
        Caption = 'Ejercicio 4'
      end
      object Ejercicio51: TMenuItem
        Caption = 'Ejercicio 5'
      end
    end
    object STRING1: TMenuItem
      Caption = 'STRING'
      object Delete1: TMenuItem
        Caption = 'Delete'
        OnClick = Delete1Click
      end
      object Pos1: TMenuItem
        Caption = 'Pos'
        OnClick = Pos1Click
      end
      object rim1: TMenuItem
        Caption = 'Trim'
      end
      object LastDelimiter1: TMenuItem
        Caption = 'LastDelimiter'
        OnClick = LastDelimiter1Click
      end
      object rim2: TMenuItem
        Caption = 'Trim'
        OnClick = rim2Click
      end
      object SubString1: TMenuItem
        Caption = 'SubString'
        OnClick = SubString1Click
      end
    end
    object CADENAS1: TMenuItem
      Caption = 'CADENAS'
      object Imprimirpalabrasdeunacadena1: TMenuItem
        Caption = 'Imprimir palabras de una cadena'
        OnClick = Imprimirpalabrasdeunacadena1Click
      end
      object Verificarsiuncaracterestaenunacadena1: TMenuItem
        Caption = 'Verificar si un caracter esta en una cadena'
        OnClick = Verificarsiuncaracterestaenunacadena1Click
      end
      object ConstruirNumero1: TMenuItem
        Caption = 'Construir Numero'
        OnClick = ConstruirNumero1Click
      end
      object Verificarsiesunaconsonante1: TMenuItem
        Caption = 'Verificar si es una consonante'
        OnClick = Verificarsiesunaconsonante1Click
      end
      object Dejarsoloconsonantes1: TMenuItem
        Caption = 'Dejar solo consonantes'
        OnClick = Dejarsoloconsonantes1Click
      end
      object Verificarcuantaspalabrascomienzanyterminanenu1: TMenuItem
        Caption = 'Verificar cuantas palabras comienzan y terminan en consonante'
        OnClick = Verificarcuantaspalabrascomienzanyterminanenu1Click
      end
      object FormatoCadena1: TMenuItem
        Caption = 'Formato Cadena'
        OnClick = FormatoCadena1Click
      end
    end
    object VECTORES1: TMenuItem
      Caption = 'VECTORES'
      object Jugandoconlasceldas1: TMenuItem
        Caption = 'Jugando con las celdas'
        OnClick = Jugandoconlasceldas1Click
      end
      object CargarPalabrasalVector1: TMenuItem
        Caption = 'Cargar Palabras al Vector'
        OnClick = CargarPalabrasalVector1Click
      end
      object CargarPalabrasalvector21: TMenuItem
        Caption = 'Cargar Palabras al vector 2'
        OnClick = CargarPalabrasalvector21Click
      end
      object CargarPalabrasconelprimercaracterenmayuscula1: TMenuItem
        Caption = 'Cargar Palabras con el primer caracter en mayuscula'
        OnClick = CargarPalabrasconelprimercaracterenmayuscula1Click
      end
    end
  end
end
