object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 336
  ClientWidth = 632
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
    Left = 32
    Top = 8
    Width = 497
    Height = 49
    ColCount = 1
    DefaultColWidth = 40
    DefaultRowHeight = 20
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 535
    Top = 22
    Width = 75
    Height = 25
    Caption = 'Cargar v1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 269
    Top = 214
    Width = 100
    Height = 25
    Caption = 'cargar manual 1'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 240
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit1'
  end
  object StringGrid2: TStringGrid
    Left = 32
    Top = 63
    Width = 497
    Height = 50
    ColCount = 1
    DefaultColWidth = 40
    DefaultRowHeight = 25
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    ParentFont = False
    TabOrder = 4
  end
  object StringGrid3: TStringGrid
    Left = 32
    Top = 127
    Width = 497
    Height = 50
    ColCount = 1
    DefaultColWidth = 40
    DefaultRowHeight = 20
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
  end
  object Button3: TButton
    Left = 535
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Cargar v2'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 535
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Cargar v3'
    TabOrder = 7
    OnClick = Button4Click
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 288
    object menu1: TMenuItem
      Caption = 'menu'
      object modex11: TMenuItem
        Caption = 'modex 1 serie '
        OnClick = modex11Click
      end
      object insertarcadadigdenenunvector1: TMenuItem
        Caption = 'insertar cada dig de n en un vector'
        OnClick = insertarcadadigdenenunvector1Click
      end
      object serieenv012361: TMenuItem
        Caption = 'serie en v 0,1,2,3,6,,'
        OnClick = serieenv012361Click
      end
      object seriefibov321101: TMenuItem
        Caption = 'serie fibo v 3,2,1,1,0'
        OnClick = seriefibov321101Click
      end
      object segmentar2vectores1: TMenuItem
        Caption = 'segmentar 2 vectores'
        OnClick = segmentar2vectores1Click
      end
      object intercalar2vectores1: TMenuItem
        Caption = 'intercalar 2 vectores'
        OnClick = intercalar2vectores1Click
      end
      object intercalar2vect201: TMenuItem
        Caption = 'intercalar 2 vect 2.0'
        OnClick = intercalar2vect201Click
      end
      object ordenarvector1: TMenuItem
        Caption = 'ordenar vector'
        OnClick = ordenarvector1Click
      end
      object insereleenposdeunvect1: TMenuItem
        Caption = 'inser ele en pos de un vect'
        OnClick = insereleenposdeunvect1Click
      end
      object insertarvectorenotroenunapos1: TMenuItem
        Caption = 'insertar vector en otro en una pos'
        OnClick = insertarvectorenotroenunapos1Click
      end
      object serie1: TMenuItem
        Caption = 'serie'
        OnClick = serie1Click
      end
    end
    object verif1: TMenuItem
      Caption = 'verif'
      object fibo1: TMenuItem
        Caption = 'fibo'
        OnClick = fibo1Click
      end
      object cantdig1: TMenuItem
        Caption = 'cant dig'
        OnClick = cantdig1Click
      end
      object esnumero1: TMenuItem
        Caption = 'es numero'
        OnClick = esnumero1Click
      end
      object dejarvocale1: TMenuItem
        Caption = 'dejar vocale'
        OnClick = dejarvocale1Click
      end
      object invertir1: TMenuItem
        Caption = 'invertir un nro'
        OnClick = invertir1Click
      end
    end
    object cadenas1: TMenuItem
      Caption = 'cadenas'
      object eliminarprimyultletradeunapalenunacad1: TMenuItem
        Caption = 'eliminar prim y ult letra de una pal en una cad'
        OnClick = eliminarprimyultletradeunapalenunacad1Click
      end
      object eliminartodasmenoslaprimylaultletraenunacad1: TMenuItem
        Caption = 'eliminar todas menos la prim y la ult letra en una cad'
        OnClick = eliminartodasmenoslaprimylaultletraenunacad1Click
      end
      object deunvectorponercadainicialenunacad1: TMenuItem
        Caption = 'de un vector poner cada inicial en una cad'
        OnClick = deunvectorponercadainicialenunacad1Click
      end
      object palabramasgrande1: TMenuItem
        Caption = 'palabra mas grande de una cadena'
        OnClick = palabramasgrande1Click
      end
      object sumadedigdeunacadena1: TMenuItem
        Caption = 'suma de dig de una cadena'
        OnClick = sumadedigdeunacadena1Click
      end
      object contarpalabras1: TMenuItem
        Caption = 'contar palabras'
        OnClick = contarpalabras1Click
      end
      object insertardigprimoenVdeunacad1: TMenuItem
        Caption = 'insertar dig primo en V de una cad-reto de mauri'
        OnClick = insertardigprimoenVdeunacad1Click
      end
      object convertirnonumerosaespacios1: TMenuItem
        Caption = 'convertir no numeros a espacios'
        OnClick = convertirnonumerosaespacios1Click
      end
      object limpiarsoloprimos1: TMenuItem
        Caption = 'limpiar numeros a solo primos'
        OnClick = limpiarsoloprimos1Click
      end
      object vocalesdepalabrasenvector1: TMenuItem
        Caption = 'vocales de palabras en vector'
        OnClick = vocalesdepalabrasenvector1Click
      end
      object vectorastring1: TMenuItem
        Caption = 'vector a string'
        OnClick = vectorastring1Click
      end
      object decadenasolodigfibo1: TMenuItem
        Caption = 'de cadena solo dig fibo'
        OnClick = decadenasolodigfibo1Click
      end
    end
    object retodepedro1: TMenuItem
      Caption = 'reto de caricari'
      object decabase2al161: TMenuItem
        Caption = 'dec a base 2 al 16'
        OnClick = decabase2al161Click
      end
    end
    object practica1: TMenuItem
      Caption = 'practica'
      object vectorastringprimos1: TMenuItem
        Caption = 'vector a string primos'
        OnClick = vectorastringprimos1Click
      end
      object vectorastringnrosvolcados1: TMenuItem
        Caption = 'vector a string nros volcados'
        OnClick = vectorastringnrosvolcados1Click
      end
    end
    object examenverano1: TMenuItem
      Caption = 'examen verano'
      object pre11: TMenuItem
        Caption = 'pre1'
      end
      object pre21: TMenuItem
        Caption = 'pre2'
        OnClick = pre21Click
      end
      object pre31: TMenuItem
        Caption = 'pre3'
        OnClick = pre31Click
      end
      object promediodeelementos1: TMenuItem
        Caption = 'promedio de elementos'
        OnClick = promediodeelementos1Click
      end
      object mayorqueelpromedio1: TMenuItem
        Caption = 'mayor que el promedio'
        OnClick = mayorqueelpromedio1Click
      end
      object insertarelemento1: TMenuItem
        Caption = 'insertar elemento'
        OnClick = insertarelemento1Click
      end
      object eliminarprimernumerodeunaca1: TMenuItem
        Caption = 'eliminar primer numero de una ca'
        OnClick = eliminarprimernumerodeunaca1Click
      end
    end
    object auxonline1: TMenuItem
      Caption = 'aux online'
      object ejer1deexamendeprueba1: TMenuItem
        Caption = 'ejer1 de examen de prueba'
        OnClick = ejer1deexamendeprueba1Click
      end
      object ejer2deexamdeprueba1: TMenuItem
        Caption = 'ejer2 de exam de prueba'
        OnClick = ejer2deexamdeprueba1Click
      end
    end
    object para1: TMenuItem
      Caption = 'para matoneo'
      object moverdigdenalfinaldeunvector1: TMenuItem
        Caption = 'de n mover dig mult de 3 al final de un vector'
        OnClick = moverdigdenalfinaldeunvector1Click
      end
      object digitosdenenunvector1: TMenuItem
        Caption = 'digitos de n en un vector'
        OnClick = digitosdenenunvector1Click
      end
      object eliminarmelementosdesdeunposdeunvector1: TMenuItem
        Caption = 'eliminar m elementos desde un pos de un vector'
        OnClick = eliminarmelementosdesdeunposdeunvector1Click
      end
      object contarpalabras2: TMenuItem
        Caption = 'contar palabras'
        OnClick = contarpalabras2Click
      end
      object elminarelementodeunapos1: TMenuItem
        Caption = 'elminar elemento de una pos'
        OnClick = elminarelementodeunapos1Click
      end
      object verificarsitodosloselementosdelvectorsonpalindromes1: TMenuItem
        Caption = 'verificar si todos los elementos del vector son palindromes'
        OnClick = verificarsitodosloselementosdelvectorsonpalindromes1Click
      end
      object vectorpalindrome1: TMenuItem
        Caption = 'vector palindrome'
        OnClick = vectorpalindrome1Click
      end
    end
    object posi1: TMenuItem
      Caption = 'posi'
      object invertirvector1: TMenuItem
        Caption = 'invertir vector'
        OnClick = invertirvector1Click
      end
      object palinvertenvect1: TMenuItem
        Caption = 'pal invert en vect'
        OnClick = palinvertenvect1Click
      end
      object invertircadena1: TMenuItem
        Caption = 'invertir cadena'
        OnClick = invertircadena1Click
      end
      object ordmargeshort1: TMenuItem
        Caption = 'ord marge short'
        OnClick = ordmargeshort1Click
      end
      object interseccion1: TMenuItem
        Caption = 'interseccion'
        OnClick = interseccion1Click
      end
    end
  end
end
