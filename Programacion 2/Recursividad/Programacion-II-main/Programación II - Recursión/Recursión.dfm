object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 388
  ClientWidth = 629
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 629
    Height = 388
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
        Left = 24
        Top = 42
        Width = 50
        Height = 16
        Caption = 'N'#250'mero:'
      end
      object Label2: TLabel
        Left = 24
        Top = 114
        Width = 61
        Height = 16
        Caption = 'Resultado:'
      end
      object Label7: TLabel
        Left = 200
        Top = 42
        Width = 61
        Height = 16
        Caption = 'N'#250'mero 2:'
      end
      object Edit1: TEdit
        Left = 24
        Top = 64
        Width = 153
        Height = 24
        TabOrder = 0
      end
      object Edit2: TEdit
        Left = 24
        Top = 136
        Width = 153
        Height = 24
        TabOrder = 1
      end
      object Edit9: TEdit
        Left = 200
        Top = 64
        Width = 153
        Height = 24
        TabOrder = 2
      end
    end
    object Series: TTabSheet
      Caption = 'Series'
      ImageIndex = 1
      object Label8: TLabel
        Left = 40
        Top = 42
        Width = 50
        Height = 16
        Caption = 'N'#250'mero:'
      end
      object Label9: TLabel
        Left = 40
        Top = 122
        Width = 61
        Height = 16
        Caption = 'Resultado:'
      end
      object Edit10: TEdit
        Left = 40
        Top = 64
        Width = 113
        Height = 24
        TabOrder = 0
      end
      object Edit11: TEdit
        Left = 40
        Top = 144
        Width = 113
        Height = 24
        TabOrder = 1
      end
      object Edit12: TEdit
        Left = 159
        Top = 64
        Width = 105
        Height = 24
        TabOrder = 2
      end
    end
    object Cadenas: TTabSheet
      Caption = 'Cadenas'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 2
      ParentFont = False
      object Label3: TLabel
        Left = 32
        Top = 50
        Width = 48
        Height = 16
        Caption = 'Cadena:'
      end
      object Label4: TLabel
        Left = 32
        Top = 117
        Width = 61
        Height = 16
        Caption = 'Resultado:'
      end
      object Edit3: TEdit
        Left = 32
        Top = 69
        Width = 241
        Height = 24
        TabOrder = 0
      end
      object Edit4: TEdit
        Left = 32
        Top = 136
        Width = 241
        Height = 24
        TabOrder = 1
      end
    end
    object Vectores: TTabSheet
      Caption = 'Vectores'
      ImageIndex = 3
      object StringGrid1: TStringGrid
        Left = 24
        Top = 88
        Width = 561
        Height = 41
        DefaultColWidth = 30
        DefaultRowHeight = 25
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        TabOrder = 0
      end
      object Edit5: TEdit
        Left = 24
        Top = 48
        Width = 177
        Height = 24
        TabOrder = 1
      end
      object Edit6: TEdit
        Left = 207
        Top = 48
        Width = 122
        Height = 24
        TabOrder = 2
      end
      object Txt_Dimension: TEdit
        Left = 24
        Top = 135
        Width = 81
        Height = 24
        TabOrder = 3
      end
      object Dimencionar: TButton
        Left = 111
        Top = 135
        Width = 90
        Height = 25
        Caption = 'Dimensionar'
        TabOrder = 4
        OnClick = DimencionarClick
      end
      object StringGrid2: TStringGrid
        Left = 24
        Top = 190
        Width = 561
        Height = 43
        DefaultColWidth = 60
        DefaultRowHeight = 25
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        TabOrder = 5
      end
      object Button2: TButton
        Left = 472
        Top = 135
        Width = 113
        Height = 25
        Caption = 'Cargar Random'
        TabOrder = 6
        OnClick = Button2Click
      end
      object Txt_Dimension2: TEdit
        Left = 24
        Top = 239
        Width = 81
        Height = 24
        TabOrder = 7
      end
      object Button3: TButton
        Left = 111
        Top = 239
        Width = 90
        Height = 25
        Caption = 'Dimensionar'
        TabOrder = 8
        OnClick = Button3Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Matrices'
      ImageIndex = 4
      object Label5: TLabel
        Left = 410
        Top = 35
        Width = 31
        Height = 16
        Caption = 'Filas:'
      end
      object Label6: TLabel
        Left = 380
        Top = 65
        Width = 61
        Height = 16
        Caption = 'Columnas:'
      end
      object StringGrid3: TStringGrid
        Left = 0
        Top = 3
        Width = 354
        Height = 354
        DefaultColWidth = 30
        DefaultRowHeight = 30
        FixedCols = 0
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        TabOrder = 0
      end
      object Edit7: TEdit
        Left = 447
        Top = 32
        Width = 73
        Height = 24
        TabOrder = 1
        Text = '5'
        OnChange = Edit7Change
      end
      object Edit8: TEdit
        Left = 447
        Top = 62
        Width = 73
        Height = 24
        TabOrder = 2
        Text = '5'
        OnChange = Edit8Change
      end
      object Button1: TButton
        Left = 447
        Top = 104
        Width = 73
        Height = 25
        Caption = 'Limpiar'
        TabOrder = 3
        OnClick = Button1Click
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 560
    Top = 336
    object Nmeros1: TMenuItem
      Caption = 'N'#250'meros'
      object Literal1: TMenuItem
        Caption = 'Literal'
        OnClick = Literal1Click
      end
      object CantidadParantesdeImpar1: TMenuItem
        Caption = 'Cantidad Par antes de Impar'
        OnClick = CantidadParantesdeImpar1Click
      end
      object MoverMayoralFinal1: TMenuItem
        Caption = 'Mover Mayor al Final'
        OnClick = MoverMayoralFinal1Click
      end
      object SumadeBinarios1: TMenuItem
        Caption = 'Suma de Binarios'
        OnClick = SumadeBinarios1Click
      end
      object Invertir2: TMenuItem
        Caption = 'Invertir'
        OnClick = Invertir2Click
      end
      object MoverMayoralFinal2: TMenuItem
        Caption = 'Mover Mayor al Final'
        OnClick = MoverMayoralFinal2Click
      end
      object Ordenar1: TMenuItem
        Caption = 'Ordenar '
        OnClick = Ordenar1Click
      end
      object DecimalaBinario1: TMenuItem
        Caption = 'Decimal a Binario'
        OnClick = DecimalaBinario1Click
      end
      object ConversindeBases1: TMenuItem
        Caption = 'Conversi'#243'n de Bases'
        OnClick = ConversindeBases1Click
      end
      object Factorial1: TMenuItem
        Caption = 'Factorial'
        OnClick = Factorial1Click
      end
      object Potencia1: TMenuItem
        Caption = 'Potencia'
        OnClick = Potencia1Click
      end
      object GitioMayoryMenor1: TMenuItem
        Caption = 'Digito Mayor y Menor'
        OnClick = GitioMayoryMenor1Click
      end
      object DigitoMayor1: TMenuItem
        Caption = 'Digito Mayor'
        OnClick = DigitoMayor1Click
      end
      object VerificarOrdenAscendente1: TMenuItem
        Caption = 'Verificar Orden Ascendente'
        OnClick = VerificarOrdenAscendente1Click
      end
      object VerificarOrdenDescendente1: TMenuItem
        Caption = 'Verificar Orden Descendente'
        OnClick = VerificarOrdenDescendente1Click
      end
      object CantidaddeDigitosPares1: TMenuItem
        Caption = 'Cantidad de Digitos Pares'
        OnClick = CantidaddeDigitosPares1Click
      end
      object SumadeDigitosPares1: TMenuItem
        Caption = 'Suma de Digitos Pares'
        OnClick = SumadeDigitosPares1Click
      end
      object CantidaddeDigitosa1: TMenuItem
        Caption = 'Cantidad de Digitos'
        OnClick = CantidaddeDigitosa1Click
      end
      object SumaDigitosPares1: TMenuItem
        Caption = 'Suma Digitos Pares'
        OnClick = SumaDigitosPares1Click
      end
      object DiferenciaentrePareseImpares1: TMenuItem
        Caption = 'Diferencia entre Pares e Impares'
        OnClick = DiferenciaentrePareseImpares1Click
      end
      object SumadeDigitosPrimos1: TMenuItem
        Caption = 'Suma de Digitos Primos'
        OnClick = SumadeDigitosPrimos1Click
      end
      object SumadeDigitos2: TMenuItem
        Caption = 'Suma de Digitos'
        OnClick = SumadeDigitos2Click
      end
      object CantidaddeDigitoaImpares1: TMenuItem
        Caption = 'Cantidad de Digitos Impares'
        OnClick = CantidaddeDigitoaImpares1Click
      end
      object CantidaddeDigitosPrimos1: TMenuItem
        Caption = 'Cantidad de Digitos Primos'
        OnClick = CantidaddeDigitosPrimos1Click
      end
      object EliminarDigitosPares1: TMenuItem
        Caption = 'Eliminar Digitos Pares'
        OnClick = EliminarDigitosPares1Click
      end
      object InsertarDigito1: TMenuItem
        Caption = 'Insertar Digito a la Derecha'
        OnClick = InsertarDigito1Click
      end
      object RotarelprimerDigito1: TMenuItem
        Caption = 'Rotar el primer Digito'
        OnClick = RotarelprimerDigito1Click
      end
      object OrdenarAscendentemente1: TMenuItem
        Caption = 'Ordenar Ascendentemente'
        OnClick = OrdenarAscendentemente1Click
      end
      object CadenadeDigitos1: TMenuItem
        Caption = 'Cadena de Digitos'
        OnClick = CadenadeDigitos1Click
      end
    end
    object Series1: TMenuItem
      Caption = 'Series'
      object Fibonacci1: TMenuItem
        Caption = 'Fibonacci'
        OnClick = Fibonacci1Click
      end
      object Serie1: TMenuItem
        Caption = 'Serie: 1,2,3,6,7,14,15,30,31..'
        OnClick = Serie1Click
      end
      object SumaSerie1: TMenuItem
        Caption = 'Suma Pares Serie: 1,2,4,5,10,12,13,26,28,29..'
        OnClick = SumaSerie1Click
      end
      object s1: TMenuItem
        Caption = 'Suma Serie: 0, 2, 4, 6, 8, 10, ...'
        OnClick = s1Click
      end
      object Serie13571531631: TMenuItem
        Caption = 'Serie: 1, 3, 7, 15, 31, 63, ...'
        OnClick = Serie13571531631Click
      end
      object DigitodelaSerie24681: TMenuItem
        Caption = 'Digito de la Serie: 2, 4, 6, 8, ..'
        OnClick = DigitodelaSerie24681Click
      end
    end
    object Cadenas1: TMenuItem
      Caption = 'Cadenas'
      object EliminarPrimeraLetra1: TMenuItem
        Caption = 'Eliminar Primera Letra'
        OnClick = EliminarPrimeraLetra1Click
      end
      object LeerConjunto1: TMenuItem
        Caption = 'Leer Conjunto'
        OnClick = LeerConjunto1Click
      end
      object EsPalndrome1: TMenuItem
        Caption = 'Es Pal'#237'ndrome'
        OnClick = EsPalndrome1Click
      end
      object NmeroMayor1: TMenuItem
        Caption = 'N'#250'mero Mayor de Cadena'
        OnClick = NmeroMayor1Click
      end
      object Invertir3: TMenuItem
        Caption = 'Invertir'
        OnClick = Invertir3Click
      end
      object EliminarVocale1: TMenuItem
        Caption = 'Eliminar Vocales'
        OnClick = EliminarVocale1Click
      end
      object PalabramsLarga1: TMenuItem
        Caption = 'Palabra m'#225's Larga'
        OnClick = PalabramsLarga1Click
      end
      object InvertirPalabra1: TMenuItem
        Caption = 'Invertir Palabras'
        OnClick = InvertirPalabra1Click
      end
      object ContarPalabras1: TMenuItem
        Caption = 'Cantidad de Palabras'
        OnClick = ContarPalabras1Click
      end
      object ContarEspacios1: TMenuItem
        Caption = 'Cantidad de Espacios'
        OnClick = ContarEspacios1Click
      end
      object ContarVocales1: TMenuItem
        Caption = 'Cantidad de Vocales'
        OnClick = ContarVocales1Click
      end
      object NmeroMayordeunaCadena1: TMenuItem
        Caption = 'N'#250'mero Mayor de Cadena'
        OnClick = NmeroMayordeunaCadena1Click
      end
      object InvertirCadena1: TMenuItem
        Caption = 'Invertir Cadena'
        OnClick = InvertirCadena1Click
      end
      object SumaDigitosenu1: TMenuItem
        Caption = 'Suma Digitos en una Cadena'
        OnClick = SumaDigitosenu1Click
      end
      object ConstruirCadenaconDigitos1: TMenuItem
        Caption = 'Construir Cadena con Digitos'
        OnClick = ConstruirCadenaconDigitos1Click
      end
      object CantidaddeLetras1: TMenuItem
        Caption = 'Cantidad de Letras'
        OnClick = CantidaddeLetras1Click
      end
      object InvertirFrase1: TMenuItem
        Caption = 'Invertir Frase'
        OnClick = InvertirFrase1Click
      end
    end
    object Vectores1: TMenuItem
      Caption = 'Vectores'
      object Invertir1: TMenuItem
        Caption = 'Invertir (a, b)'
        OnClick = Invertir1Click
      end
      object InsertionSort1: TMenuItem
        Caption = 'InsertionSort'
        OnClick = InsertionSort1Click
      end
      object CargarSerie11: TMenuItem
        Caption = 'Cargar Serie 1'
        OnClick = CargarSerie11Click
      end
      object VerificarOrden1: TMenuItem
        Caption = 'Verificar Orden'
        OnClick = VerificarOrden1Click
      end
      object SumadeDigitos1: TMenuItem
        Caption = 'Suma de Digitos'
        OnClick = SumadeDigitos1Click
      end
      object CargarOrdenadoCadena1: TMenuItem
        Caption = 'Cargar Ordenado Cadena'
        OnClick = CargarOrdenadoCadena1Click
      end
      object OrdenBurbuja1: TMenuItem
        Caption = 'Orden Burbuja'
        OnClick = OrdenBurbuja1Click
      end
      object InsertarVectorenOtrov2v2p1: TMenuItem
        Caption = 'Insertar Vector en Otro v2-> v2, p'
        OnClick = InsertarVectorenOtrov2v2p1Click
      end
      object CargarFraseenunVector1: TMenuItem
        Caption = 'Cargar Cadena'
        OnClick = CargarFraseenunVector1Click
      end
      object EliminarElemento1: TMenuItem
        Caption = 'Eliminar Elemento'
        OnClick = EliminarElemento1Click
      end
      object CargarVocaeles1: TMenuItem
        Caption = 'Cargar Vocales de una Cadena'
        OnClick = CargarVocaeles1Click
      end
      object CargarFrecuencias1: TMenuItem
        Caption = 'Cargar Frecuencias'
        OnClick = CargarFrecuencias1Click
      end
      object SumadeElementosPres1: TMenuItem
        Caption = 'Suma de Elementos Pares'
        OnClick = SumadeElementosPres1Click
      end
      object Cargar1: TMenuItem
        Caption = 'Cargar Vector con Digitos < 100'
        OnClick = Cargar1Click
      end
      object CadenaconNmerosInvertidosdeunvector1: TMenuItem
        Caption = 'Cadena con N'#250'meros Invertidos '
        OnClick = CadenaconNmerosInvertidosdeunvector1Click
      end
      object CargarSerie1: TMenuItem
        Caption = 'Cargar Serie'
        OnClick = CargarSerie1Click
      end
      object Suma1: TMenuItem
        Caption = 'Suma '
        OnClick = Suma1Click
      end
      object CargarCaracteresdeCadena1: TMenuItem
        Caption = 'Cargar Caracteres de Cadena'
        OnClick = CargarCaracteresdeCadena1Click
      end
      object BusquedaBinaria1: TMenuItem
        Caption = 'Busqueda Binaria'
        OnClick = BusquedaBinaria1Click
      end
      object CargarOrdenado1: TMenuItem
        Caption = 'Cargar Ordenado'
        OnClick = CargarOrdenado1Click
      end
      object CargarSerie012367141: TMenuItem
        Caption = 'Cargar Serie: 0, 1, 2, 3, 6, 7, 14,..'
        OnClick = CargarSerie012367141Click
      end
      object QuickSort1: TMenuItem
        Caption = 'QuickSort'
        OnClick = QuickSort1Click
      end
      object CargarPalabrassinVocales1: TMenuItem
        Caption = 'Cargar Palabras sin Vocales'
        OnClick = CargarPalabrassinVocales1Click
      end
      object CargarNmeroRetonarSuma1: TMenuItem
        Caption = 'Cargar N'#250'mero Retonar Suma'
        OnClick = CargarNmeroRetonarSuma1Click
      end
      object ConstruitcadenaconUltimasLetras1: TMenuItem
        Caption = 'Construir cadena con Ultimas Letras'
        OnClick = ConstruitcadenaconUltimasLetras1Click
      end
      object CargarPalabraInvertida1: TMenuItem
        Caption = 'Cargar Palabra Invertida'
        OnClick = CargarPalabraInvertida1Click
      end
      object VectoraNmero1: TMenuItem
        Caption = 'Vector a N'#250'mero'
        OnClick = VectoraNmero1Click
      end
      object ElimnarElementos1: TMenuItem
        Caption = 'Eliminar Elementos'
        OnClick = ElimnarElementos1Click
      end
      object SumaDigitosPares2: TMenuItem
        Caption = 'Suma Digitos Pares'
        OnClick = SumaDigitosPares2Click
      end
      object InsertionSort2: TMenuItem
        Caption = 'InsertionSort'
        OnClick = InsertionSort2Click
      end
    end
    object Matrices1: TMenuItem
      Caption = 'Matrices'
      object CargarTodasLasFilas1: TMenuItem
        Caption = 'Cargar Todas Las Filas'
        OnClick = CargarTodasLasFilas1Click
      end
      object CargarTodasLasColumnas1: TMenuItem
        Caption = 'Cargar Todas Las Columnas'
        OnClick = CargarTodasLasColumnas1Click
      end
      object CargarDiagonalSecundariaInferioe1: TMenuItem
        Caption = 'Cargar Diagonal Secundaria Inferior'
        OnClick = CargarDiagonalSecundariaInferioe1Click
      end
      object CargarExterior1: TMenuItem
        Caption = 'Cargar Exterior'
        OnClick = CargarExterior1Click
      end
      object CargarDiagonalSecundaria21: TMenuItem
        Caption = 'Cargar Diagonal Secundaria Inferior de 2'
        OnClick = CargarDiagonalSecundaria21Click
      end
      object CargarDiagonalSuperior1: TMenuItem
        Caption = 'Cargar Diagonal Superior  1, 1 -> C'
        OnClick = CargarDiagonalSuperior1Click
      end
      object CargarCaracol1: TMenuItem
        Caption = 'Cargar Caracol'
        OnClick = CargarCaracol1Click
      end
      object CargarCaracol21: TMenuItem
        Caption = 'Cargar Caracol 2'
        OnClick = CargarCaracol21Click
      end
      object CargarPalabra1: TMenuItem
        Caption = 'Cargar Palabra'
        OnClick = CargarPalabra1Click
      end
      object CargarEspiral1: TMenuItem
        Caption = 'Cargar Espiral'
        OnClick = CargarEspiral1Click
      end
      object CargarFraccin1: TMenuItem
        Caption = 'Cargar Fracciones'
        OnClick = CargarFraccin1Click
      end
      object CargarMatrizSerpiente1: TMenuItem
        Caption = 'Cargar Matriz Serpiente'
        OnClick = CargarMatrizSerpiente1Click
      end
      object CargarDiagonalSuperior2: TMenuItem
        Caption = 'Cargar Diagonal Superior'
        OnClick = CargarDiagonalSuperior2Click
      end
      object c1: TMenuItem
        Caption = 'Cargar en Forma Diagonal'
        OnClick = c1Click
      end
      object CargarCaracol31: TMenuItem
        Caption = 'Cargar Caracol 3'
        OnClick = CargarCaracol31Click
      end
      object CargarDiagonalInferiorcon11: TMenuItem
        Caption = 'Cargar Diagonal Inferior con 1'
        OnClick = CargarDiagonalInferiorcon11Click
      end
      object CargarMatrizSerpiente21: TMenuItem
        Caption = 'Cargar Matriz Serpiente 2'
        OnClick = CargarMatrizSerpiente21Click
      end
      object CargarCadena1: TMenuItem
        Caption = 'Cargar Cadena '
        OnClick = CargarCadena1Click
      end
      object CargarCadena21: TMenuItem
        Caption = 'Cargar Cadena 2'
        OnClick = CargarCadena21Click
      end
      object Cargardiagonalsuperior3: TMenuItem
        Caption = 'Cargar Triangular Superior'
        OnClick = Cargardiagonalsuperior3Click
      end
      object CargarCadena31: TMenuItem
        Caption = 'Cargar Cadena 3'
        OnClick = CargarCadena31Click
      end
      object CargarporFilas1: TMenuItem
        Caption = 'Cargar por Filas'
        OnClick = CargarporFilas1Click
      end
      object CargarMatriz1: TMenuItem
        Caption = 'Cargar Matriz '
        OnClick = CargarMatriz1Click
      end
      object CargarEspiral21: TMenuItem
        Caption = 'Cargar Espiral 2'
        OnClick = CargarEspiral21Click
      end
      object CargarDona1: TMenuItem
        Caption = 'Cargar Dona'
        OnClick = CargarDona1Click
      end
      object CuadradoMgico1: TMenuItem
        Caption = 'Cuadrado M'#225'gico'
        OnClick = CuadradoMgico1Click
      end
      object CargarMatrizExamen1: TMenuItem
        Caption = 'Cargar Matriz Examen'
        OnClick = CargarMatrizExamen1Click
      end
      object CargarTriangularInferior1: TMenuItem
        Caption = 'Cargar Triangular Inferior'
        OnClick = CargarTriangularInferior1Click
      end
      object CargarCadenaenSerpiente1: TMenuItem
        Caption = 'Cargar Cadena en Serpiente'
        OnClick = CargarCadenaenSerpiente1Click
      end
      object CargarColumnasInvertido1: TMenuItem
        Caption = 'Cargar Columnas Invertido'
        OnClick = CargarColumnasInvertido1Click
      end
      object Navidad1: TMenuItem
        Caption = 'Navidad'
        OnClick = Navidad1Click
      end
      object CargarTriangularSuperior1: TMenuItem
        Caption = 'Cargar Triangular Superior'
        OnClick = CargarTriangularSuperior1Click
      end
      object CargarTriangularInferiorP11: TMenuItem
        Caption = 'Cargar Triangular Inferior P1'
        OnClick = CargarTriangularInferiorP11Click
      end
      object CargarMatrizSerpienteColumnas1: TMenuItem
        Caption = 'Cargar Matriz Serpiente Columnas'
        OnClick = CargarMatrizSerpienteColumnas1Click
      end
      object CargarTriangularInferiorColumnas1: TMenuItem
        Caption = 'Cargar Triangular Inferior Columnas'
        OnClick = CargarTriangularInferiorColumnas1Click
      end
      object CargarDiagonales1: TMenuItem
        Caption = 'Cargar Diagonales'
        OnClick = CargarDiagonales1Click
      end
    end
  end
end
