object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 387
  ClientWidth = 599
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 599
    Height = 387
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'N'#250'meros'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      object Label1: TLabel
        Left = 56
        Top = 66
        Width = 50
        Height = 16
        Caption = 'N'#250'mero:'
      end
      object Label2: TLabel
        Left = 221
        Top = 66
        Width = 61
        Height = 16
        Caption = 'N'#250'mero 2:'
      end
      object Label3: TLabel
        Left = 56
        Top = 162
        Width = 61
        Height = 16
        Caption = 'Resultado:'
      end
      object Label4: TLabel
        Left = 388
        Top = 66
        Width = 61
        Height = 16
        Caption = 'N'#250'mero 3:'
      end
      object Edit1: TEdit
        Left = 56
        Top = 88
        Width = 153
        Height = 24
        TabOrder = 0
      end
      object Edit2: TEdit
        Left = 221
        Top = 88
        Width = 153
        Height = 24
        TabOrder = 1
      end
      object Edit3: TEdit
        Left = 56
        Top = 184
        Width = 153
        Height = 24
        TabOrder = 2
      end
      object Edit4: TEdit
        Left = 388
        Top = 88
        Width = 153
        Height = 24
        TabOrder = 3
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Series'
      ImageIndex = 1
    end
    object Cadenas: TTabSheet
      Caption = 'Cadenas'
      ImageIndex = 2
      Touch.InteractiveGestures = [igZoom, igPressAndTap]
      object Label5: TLabel
        Left = 56
        Top = 162
        Width = 61
        Height = 16
        Caption = 'Resultado:'
      end
      object Label6: TLabel
        Left = 56
        Top = 66
        Width = 48
        Height = 16
        Caption = 'Cadena:'
      end
      object Label7: TLabel
        Left = 336
        Top = 66
        Width = 59
        Height = 16
        Caption = 'Cadena 2:'
      end
      object Edit5: TEdit
        Left = 56
        Top = 88
        Width = 241
        Height = 24
        TabOrder = 0
      end
      object Edit6: TEdit
        Left = 56
        Top = 184
        Width = 241
        Height = 24
        TabOrder = 1
      end
      object Edit7: TEdit
        Left = 336
        Top = 88
        Width = 209
        Height = 24
        TabOrder = 2
      end
    end
    object Vectores: TTabSheet
      Caption = 'Vectores'
      ImageIndex = 3
      object Label8: TLabel
        Left = 24
        Top = 245
        Width = 61
        Height = 16
        Caption = 'Resultado:'
      end
      object Label9: TLabel
        Left = 24
        Top = 29
        Width = 50
        Height = 16
        Caption = 'N'#250'mero:'
      end
      object Label10: TLabel
        Left = 232
        Top = 29
        Width = 61
        Height = 16
        Caption = 'N'#250'mero 2:'
      end
      object Label11: TLabel
        Left = 344
        Top = 29
        Width = 61
        Height = 16
        Caption = 'N'#250'mero 3:'
      end
      object Vector1: TStringGrid
        Left = 24
        Top = 81
        Width = 521
        Height = 33
        ColCount = 10
        DefaultColWidth = 30
        DefaultRowHeight = 25
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
        TabOrder = 0
      end
      object Vector2: TStringGrid
        Left = 24
        Top = 150
        Width = 521
        Height = 33
        DefaultColWidth = 55
        DefaultRowHeight = 25
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
        TabOrder = 1
      end
      object Edit8: TEdit
        Left = 24
        Top = 51
        Width = 193
        Height = 24
        TabOrder = 2
      end
      object Txt_Dimension: TEdit
        Left = 24
        Top = 120
        Width = 97
        Height = 24
        TabOrder = 3
      end
      object Txt_Dimension2: TEdit
        Left = 24
        Top = 190
        Width = 97
        Height = 24
        TabOrder = 4
      end
      object Edit11: TEdit
        Left = 232
        Top = 51
        Width = 97
        Height = 24
        TabOrder = 5
      end
      object Btn_Dimensionar: TButton
        Left = 127
        Top = 120
        Width = 90
        Height = 25
        Caption = 'Dimensionar'
        TabOrder = 6
        OnClick = Btn_DimensionarClick
      end
      object Btn_Dimensionar2: TButton
        Left = 127
        Top = 190
        Width = 90
        Height = 25
        Caption = 'Dimensionar'
        TabOrder = 7
        OnClick = Btn_Dimensionar2Click
      end
      object Btn_Random: TButton
        Left = 313
        Top = 120
        Width = 113
        Height = 25
        Caption = 'Cargar Random'
        TabOrder = 8
        OnClick = Btn_RandomClick
      end
      object Edit9: TEdit
        Left = 24
        Top = 267
        Width = 193
        Height = 24
        TabOrder = 9
      end
      object Edit10: TEdit
        Left = 344
        Top = 51
        Width = 97
        Height = 24
        TabOrder = 10
      end
      object Btn_Limpiar: TButton
        Left = 432
        Top = 120
        Width = 113
        Height = 25
        Caption = 'Limpiar'
        TabOrder = 11
        OnClick = Btn_LimpiarClick
      end
      object Btn_Limpiar2: TButton
        Left = 432
        Top = 189
        Width = 113
        Height = 25
        Caption = 'Limpiar'
        TabOrder = 12
        OnClick = Btn_Limpiar2Click
      end
    end
    object Matrices: TTabSheet
      Caption = 'Matrices'
      ImageIndex = 4
      object Label12: TLabel
        Left = 389
        Top = 59
        Width = 31
        Height = 16
        Caption = 'Filas:'
      end
      object Label13: TLabel
        Left = 389
        Top = 89
        Width = 61
        Height = 16
        Caption = 'Columnas:'
      end
      object StringGrid1: TStringGrid
        Left = 3
        Top = 3
        Width = 350
        Height = 350
        DefaultColWidth = 30
        DefaultRowHeight = 30
        FixedCols = 0
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
        TabOrder = 0
      end
      object Txt_Filas: TEdit
        Left = 464
        Top = 56
        Width = 73
        Height = 24
        TabOrder = 1
        Text = '5'
        OnChange = Txt_FilasChange
      end
      object Txt_Columnas: TEdit
        Left = 464
        Top = 86
        Width = 73
        Height = 24
        TabOrder = 2
        Text = '5'
        OnChange = Txt_ColumnasChange
      end
      object Btn_Limpiar3: TButton
        Left = 464
        Top = 128
        Width = 75
        Height = 25
        Caption = 'Limpiar'
        TabOrder = 3
        OnClick = Btn_Limpiar3Click
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 525
    Top = 312
    object Nmeros1: TMenuItem
      Caption = 'N'#250'meros'
      object SumadeDigitos1: TMenuItem
        Caption = 'Suma de Digitos'
        OnClick = SumadeDigitos1Click
      end
      object DigitoMayor1: TMenuItem
        Caption = 'Digito Mayor'
        OnClick = DigitoMayor1Click
      end
      object EliminarDigitoxdig1: TMenuItem
        Caption = 'Eliminar Digito (x, dig)'
        OnClick = EliminarDigitoxdig1Click
      end
      object Literal1: TMenuItem
        Caption = 'Literal'
        OnClick = Literal1Click
      end
      object RotarPrimerDigitoalaDerecha1: TMenuItem
        Caption = 'Rotar Primer Digito a la Derecha'
        OnClick = RotarPrimerDigitoalaDerecha1Click
      end
      object VerificarOrdenAscendente1: TMenuItem
        Caption = 'Verificar Orden Ascendente'
        OnClick = VerificarOrdenAscendente1Click
      end
      object VerificarOrdenDescendente1: TMenuItem
        Caption = 'Verificar Orden Descendente'
        OnClick = VerificarOrdenDescendente1Click
      end
      object SepararenDigitosPareseImpares1: TMenuItem
        Caption = 'Separar en Digitos Pares e Impares'
        OnClick = SepararenDigitosPareseImpares1Click
      end
      object EliminarDigitosPares1: TMenuItem
        Caption = 'Eliminar Digitos Pares'
        OnClick = EliminarDigitosPares1Click
      end
      object EliminarDigitosPrimos1: TMenuItem
        Caption = 'Eliminar Digitos Primos'
        OnClick = EliminarDigitosPrimos1Click
      end
      object Invertir1: TMenuItem
        Caption = 'Invertir'
        OnClick = Invertir1Click
      end
      object MoverMayoralFinal1: TMenuItem
        Caption = 'Mover Mayor al Final'
        OnClick = MoverMayoralFinal1Click
      end
      object CantidadParesantesdeImpar1: TMenuItem
        Caption = 'Cantidad Pares antes de Impar'
        OnClick = CantidadParesantesdeImpar1Click
      end
      object CantidaddeDigitos1: TMenuItem
        Caption = 'Cantidad de Digitos'
        OnClick = CantidaddeDigitos1Click
      end
      object CantidadDigitosPares1: TMenuItem
        Caption = 'Cantidad Digitos Pares'
        OnClick = CantidadDigitosPares1Click
      end
      object CantidadDigitosImpares1: TMenuItem
        Caption = 'Cantidad Digitos Impares'
        OnClick = CantidadDigitosImpares1Click
      end
      object OrdenarAscendentemente1: TMenuItem
        Caption = 'Ordenar Ascendentemente'
        OnClick = OrdenarAscendentemente1Click
      end
      object OrdenarAscendentemente2: TMenuItem
        Caption = 'Ordenar Descendentemente'
        OnClick = OrdenarAscendentemente2Click
      end
      object DigitoMenoryMayor1: TMenuItem
        Caption = 'Digito Menor y Mayor'
        OnClick = DigitoMenoryMayor1Click
      end
      object SumaDigitosPares1: TMenuItem
        Caption = 'Suma Digitos Pares'
        OnClick = SumaDigitosPares1Click
      end
      object CantidadDigitosPrimos1: TMenuItem
        Caption = 'Cantidad Digitos Primos'
        OnClick = CantidadDigitosPrimos1Click
      end
      object SumaDigitosPrimos1: TMenuItem
        Caption = 'Suma Digitos Primos'
        OnClick = SumaDigitosPrimos1Click
      end
      object DiferenciaentreDigitosPareseImpares1: TMenuItem
        Caption = 'Diferencia entre Digitos Pares e Impares'
        OnClick = DiferenciaentreDigitosPareseImpares1Click
      end
      object InsertarDigitoxpdig1: TMenuItem
        Caption = 'Insertar Digito (x, p, dig)'
        OnClick = InsertarDigitoxpdig1Click
      end
      object CambiarunDigitoporOtro1: TMenuItem
        Caption = 'Cambiar un Digito por Otro (x, dig, dig)'
        OnClick = CambiarunDigitoporOtro1Click
      end
      object PosicindeunDigito1: TMenuItem
        Caption = 'Posici'#243'n de un Digito (x, dig)'
        OnClick = PosicindeunDigito1Click
      end
    end
    object Series1: TMenuItem
      Caption = 'Series'
    end
    object Series2: TMenuItem
      Caption = 'Cadenas'
      object CantidaddeVocales1: TMenuItem
        Caption = 'Cantidad de Vocales'
        OnClick = CantidaddeVocales1Click
      end
      object Invertir2: TMenuItem
        Caption = 'Invertir'
        OnClick = Invertir2Click
      end
      object InvertirPalabras1: TMenuItem
        Caption = 'Invertir Palabras'
        OnClick = InvertirPalabras1Click
      end
      object PalabraMsLarga1: TMenuItem
        Caption = 'Palabra M'#225's Larga'
        OnClick = PalabraMsLarga1Click
      end
      object EliminarPrimeraLetra1: TMenuItem
        Caption = 'Eliminar Primera Letra'
        OnClick = EliminarPrimeraLetra1Click
      end
      object EsPalindrome1: TMenuItem
        Caption = 'Es Palindrome'
        OnClick = EsPalindrome1Click
      end
      object InvertirOrden1: TMenuItem
        Caption = 'Invertir Orden'
        OnClick = InvertirOrden1Click
      end
      object ExistePalabra1: TMenuItem
        Caption = 'Existe Palabra'
        OnClick = ExistePalabra1Click
      end
      object EliminarPrimeryUltimaLetra1: TMenuItem
        Caption = 'Eliminar Primer y Ultima Letra'
        OnClick = EliminarPrimeryUltimaLetra1Click
      end
      object NmeroMayor1: TMenuItem
        Caption = 'N'#250'mero Mayor'
        OnClick = NmeroMayor1Click
      end
      object CantidaddePalabras1: TMenuItem
        Caption = 'Cantidad de Palabras'
        OnClick = CantidaddePalabras1Click
      end
      object CantidaddeLetras1: TMenuItem
        Caption = 'Cantidad de Letras'
        OnClick = CantidaddeLetras1Click
      end
      object CantidaddeEspacios1: TMenuItem
        Caption = 'Cantidad de Espacios'
        OnClick = CantidaddeEspacios1Click
      end
      object CantidaddeEspacios2: TMenuItem
        Caption = 'Cadena de Digitos'
        OnClick = CantidaddeEspacios2Click
      end
      object SumadeDigitos2: TMenuItem
        Caption = 'Suma de Digitos'
        OnClick = SumadeDigitos2Click
      end
      object CadenaPareseImpares1: TMenuItem
        Caption = 'Cadena Pares '
        OnClick = CadenaPareseImpares1Click
      end
      object NmeroMenor1: TMenuItem
        Caption = 'N'#250'mero Menor'
        OnClick = NmeroMenor1Click
      end
      object PalabraMsCorta1: TMenuItem
        Caption = 'Palabra M'#225's Corta'
        OnClick = PalabraMsCorta1Click
      end
      object CantidaddeCaracteresEspeciales1: TMenuItem
        Caption = 'Cantidad de Caracteres Especiales'
        OnClick = CantidaddeCaracteresEspeciales1Click
      end
    end
    object Vectores1: TMenuItem
      Caption = 'Vectores'
      object Suma1: TMenuItem
        Caption = 'Suma'
        OnClick = Suma1Click
      end
      object SumaPares1: TMenuItem
        Caption = 'Suma Pares'
        OnClick = SumaPares1Click
      end
      object ExisteElemento1: TMenuItem
        Caption = 'Existe Elemento'
        OnClick = ExisteElemento1Click
      end
      object CargarvocalesdeunaCadena1: TMenuItem
        Caption = 'Cargar vocales de una Cadena'
        OnClick = CargarvocalesdeunaCadena1Click
      end
      object CadenaconlasUltimasLetras1: TMenuItem
        Caption = 'Cadena con las Ultimas Letras'
        OnClick = CadenaconlasUltimasLetras1Click
      end
      object CargarconPrimeraletraenMayuscula1: TMenuItem
        Caption = 'Cargar con Primera letra en Mayuscula'
        OnClick = CargarconPrimeraletraenMayuscula1Click
      end
      object CargarPalabras1: TMenuItem
        Caption = 'Cargar Palabras '
        OnClick = CargarPalabras1Click
      end
      object CadenaconlasPrimerasLetras1: TMenuItem
        Caption = 'Cadena con las Primeras Letras'
        OnClick = CadenaconlasPrimerasLetras1Click
      end
      object CargarVocales1: TMenuItem
        Caption = 'Cargar Vocales'
        OnClick = CargarVocales1Click
      end
      object CargarCadenaInvertida1: TMenuItem
        Caption = 'Cargar Cadena Invertida'
        OnClick = CargarCadenaInvertida1Click
      end
      object CargarPalabrassinVocales1: TMenuItem
        Caption = 'Cargar Palabras sin Vocales'
        OnClick = CargarPalabrassinVocales1Click
      end
      object GenerarNmeroInvertido1: TMenuItem
        Caption = 'Generar N'#250'mero Invertido'
        OnClick = GenerarNmeroInvertido1Click
      end
      object OrdenarAscendentemente3: TMenuItem
        Caption = 'Ordenar Ascendentemente'
        OnClick = OrdenarAscendentemente3Click
      end
      object OrdenarDescendentemente1: TMenuItem
        Caption = 'Ordenar Descendentemente'
        OnClick = OrdenarDescendentemente1Click
      end
      object OrdenarSegmentoAscendentemente1: TMenuItem
        Caption = 'Ordenar Segmento Ascendentemente'
        OnClick = OrdenarSegmentoAscendentemente1Click
      end
      object InvertirSegmento1: TMenuItem
        Caption = 'Invertir Segmento'
        OnClick = InvertirSegmento1Click
      end
      object EliminarunElemento1: TMenuItem
        Caption = 'Eliminar un Elemento'
        OnClick = EliminarunElemento1Click
      end
      object EliminarSegmento1: TMenuItem
        Caption = 'Eliminar Segmento'
        OnClick = EliminarSegmento1Click
      end
      object CantidadVocales1: TMenuItem
        Caption = 'Cantidad Vocales'
        OnClick = CantidadVocales1Click
      end
      object CantidadDigitosPrimos2: TMenuItem
        Caption = 'Cantidad Digitos Primos'
        OnClick = CantidadDigitosPrimos2Click
      end
      object SumaDigitosPares2: TMenuItem
        Caption = 'Suma Digitos Pares'
        OnClick = SumaDigitosPares2Click
      end
    end
    object Vectores2: TMenuItem
      Caption = 'Matrices'
      object CargarFilas1: TMenuItem
        Caption = 'Cargar Filas Izq a Der'
        OnClick = CargarFilas1Click
      end
      object CargarFilasDeraIzq1: TMenuItem
        Caption = 'Cargar Filas Der a Izq'
        OnClick = CargarFilasDeraIzq1Click
      end
      object CargarColumnasArribaaAbajo1: TMenuItem
        Caption = 'Cargar Columnas Arriba a Abajo'
        OnClick = CargarColumnasArribaaAbajo1Click
      end
      object CargarColumnasAbajoaArriba1: TMenuItem
        Caption = 'Cargar Columnas Abajo a Arriba'
        OnClick = CargarColumnasAbajoaArriba1Click
      end
      object SerpienteIzqaDer1: TMenuItem
        Caption = 'Serpiente Izq a Der '
        OnClick = SerpienteIzqaDer1Click
      end
      object SerpienteDeraIzq1: TMenuItem
        Caption = 'Serpiente Der a Izq '
        OnClick = SerpienteDeraIzq1Click
      end
      object riangularSuperiorIzqaDer1: TMenuItem
        Caption = 'Triangular Superior Izq a Der'
        OnClick = riangularSuperiorIzqaDer1Click
      end
      object riangularSuperiorDeraIzq1: TMenuItem
        Caption = 'Triangular Superior Der a Izq'
        OnClick = riangularSuperiorDeraIzq1Click
      end
      object riangularSuperiorArribaaAbajo1: TMenuItem
        Caption = 'Triangular Superior Arriba a Abajo'
        OnClick = riangularSuperiorArribaaAbajo1Click
      end
    end
  end
end
