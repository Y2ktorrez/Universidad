object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 504
  ClientWidth = 655
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
  object Label1: TLabel
    Left = 40
    Top = 32
    Width = 107
    Height = 13
    Caption = 'Cantidad de N'#250'meros:'
  end
  object Label2: TLabel
    Left = 40
    Top = 80
    Width = 52
    Height = 13
    Caption = 'Resultado:'
  end
  object Label3: TLabel
    Left = 368
    Top = 32
    Width = 103
    Height = 13
    Caption = 'Dimensi'#243'n del Vector:'
  end
  object Txt_Numero: TEdit
    Left = 40
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Txt_Numero2: TEdit
    Left = 184
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Txt_Resultado: TEdit
    Left = 40
    Top = 99
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object StringGrid1: TStringGrid
    Left = 40
    Top = 144
    Width = 545
    Height = 33
    DefaultColWidth = 30
    DefaultRowHeight = 30
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 3
  end
  object Button1: TButton
    Left = 472
    Top = 113
    Width = 99
    Height = 25
    Caption = 'Cargar Random'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Txt_Vector: TEdit
    Left = 368
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 5
    OnExit = Txt_VectorExit
  end
  object StringGrid2: TStringGrid
    Left = 40
    Top = 183
    Width = 393
    Height = 298
    DefaultColWidth = 30
    DefaultRowHeight = 30
    FixedCols = 0
    FixedRows = 0
    TabOrder = 6
  end
  object MainMenu1: TMainMenu
    Left = 552
    Top = 16
    object NmerosNaturales1: TMenuItem
      Caption = 'N'#250'meros Naturales'
      object FactorialdeunNmero1: TMenuItem
        Caption = 'Factorial de un N'#250'mero'
        OnClick = FactorialdeunNmero1Click
      end
      object DigitodelaSerie1: TMenuItem
        Caption = 'Digito de la Serie'
        OnClick = DigitodelaSerie1Click
      end
      object CantidadDigitosdeunNmero1: TMenuItem
        Caption = 'Cantidad Digitos de un N'#250'mero'
        OnClick = CantidadDigitosdeunNmero1Click
      end
      object SumadeDigitosPares1: TMenuItem
        Caption = 'Suma de Digitos Pares'
        OnClick = SumadeDigitosPares1Click
      end
      object DiferenciaentrePreseImpares1: TMenuItem
        Caption = 'Diferencia entre Pres e Impares'
        OnClick = DiferenciaentrePreseImpares1Click
      end
      object PotenciadeunNmero1: TMenuItem
        Caption = 'Potencia de un N'#250'mero'
        OnClick = PotenciadeunNmero1Click
      end
      object DigitoMayordeunNmero1: TMenuItem
        Caption = 'Digito Mayor de un N'#250'mero'
        OnClick = DigitoMayordeunNmero1Click
      end
      object CantidaddeDigitosPares1: TMenuItem
        Caption = 'Cantidad de Digitos Pares'
        OnClick = CantidaddeDigitosPares1Click
      end
      object CantidadDigitosParesantesImpar1: TMenuItem
        Caption = 'Cantidad Digitos Pares antes Impar'
        OnClick = CantidadDigitosParesantesImpar1Click
      end
      object DigitoMayoralFinal1: TMenuItem
        Caption = 'Digito Mayor al Final'
        OnClick = DigitoMayoralFinal1Click
      end
    end
    object Cadenas1: TMenuItem
      Caption = 'Cadenas'
      object ContarlosEspacios1: TMenuItem
        Caption = 'Contar los Espacios'
        OnClick = ContarlosEspacios1Click
      end
      object ContarlasVocales1: TMenuItem
        Caption = 'Contar las Vocales'
        OnClick = ContarlasVocales1Click
      end
      object Invertir1: TMenuItem
        Caption = 'Invertir'
        OnClick = Invertir1Click
      end
      object Invertir21: TMenuItem
        Caption = 'Invertir 2'
        OnClick = Invertir21Click
      end
      object Invertir31: TMenuItem
        Caption = 'Invertir 3'
        OnClick = Invertir31Click
      end
      object PalabramsLarga1: TMenuItem
        Caption = 'Palabra m'#225's Larga'
        OnClick = PalabramsLarga1Click
      end
      object EliminarPrimeraLetra1: TMenuItem
        Caption = 'Eliminar Primera Letra '
        OnClick = EliminarPrimeraLetra1Click
      end
      object InvertircadaPalabra1: TMenuItem
        Caption = 'Invertir cada Palabra'
        OnClick = InvertircadaPalabra1Click
      end
    end
    object Vectores1: TMenuItem
      Caption = 'Vectores'
      object InvertirenunSegmento1: TMenuItem
        Caption = 'Invertir en un Segmento'
        OnClick = InvertirenunSegmento1Click
      end
      object Ordenar1: TMenuItem
        Caption = 'Ordenar  InsertionSort'
        OnClick = Ordenar1Click
      end
      object Suma1: TMenuItem
        Caption = 'Suma '
        OnClick = Suma1Click
      end
      object BusquedaBinaria1: TMenuItem
        Caption = 'Busqueda Binaria'
        OnClick = BusquedaBinaria1Click
      end
      object BubleSort1: TMenuItem
        Caption = 'BubbleSort'
        OnClick = BubleSort1Click
      end
    end
    object Matrices1: TMenuItem
      Caption = 'Matrices'
      object Cargar1: TMenuItem
        Caption = 'Cargar'
        OnClick = Cargar1Click
      end
      object Cargar21: TMenuItem
        Caption = 'Cargar 2'
        OnClick = Cargar21Click
      end
      object CargarEspiral1: TMenuItem
        Caption = 'Cargar Espiral'
        OnClick = CargarEspiral1Click
      end
      object CuadradoMgico1: TMenuItem
        Caption = 'Cuadrado M'#225'gico'
        OnClick = CuadradoMgico1Click
      end
      object CuadradoMagico21: TMenuItem
        Caption = 'Cuadrado Magico 2'
        OnClick = CuadradoMagico21Click
      end
      object riangularInfdeIzqaDer1: TMenuItem
        Caption = 'Triangular Inf de Izq a Der'
      end
      object riangularInfdeArribaaAbajo1: TMenuItem
        Caption = 'Triangular Inf de Arriba a Abajo'
      end
      object CargardeArribaaAbajo1: TMenuItem
        Caption = 'Cargar de Arriba a Abajo'
      end
      object CargarDegradedeMayoraMenor1: TMenuItem
        Caption = 'Cargar Degrade de Mayor a Menor'
        OnClick = CargarDegradedeMayoraMenor1Click
      end
    end
  end
end
