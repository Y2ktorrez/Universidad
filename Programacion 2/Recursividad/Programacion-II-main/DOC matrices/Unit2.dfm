object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 530
  ClientWidth = 626
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
    Left = 120
    Top = 80
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 304
    Top = 80
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 88
    Top = 117
    Width = 385
    Height = 21
    TabOrder = 2
    Text = 'Edit3'
  end
  object Button1: TButton
    Left = 166
    Top = 161
    Width = 75
    Height = 25
    Caption = 'limpiar'
    TabOrder = 3
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 57
    Top = 248
    Width = 480
    Height = 257
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 4
  end
  object Button2: TButton
    Left = 304
    Top = 161
    Width = 75
    Height = 25
    Caption = 'cargar RND'
    TabOrder = 5
    OnClick = Button2Click
  end
  object StringGrid2: TStringGrid
    Left = 80
    Top = 192
    Width = 417
    Height = 25
    TabOrder = 6
  end
  object MainMenu1: TMainMenu
    Left = 8
    object matrixcomplet1: TMenuItem
      Caption = 'matrix complet'
      object N11: TMenuItem
        Caption = '1'
        OnClick = N11Click
      end
      object N21: TMenuItem
        Caption = '2'
        OnClick = N21Click
      end
      object N31: TMenuItem
        Caption = '3'
        OnClick = N31Click
      end
      object N41: TMenuItem
        Caption = '4'
        OnClick = N41Click
      end
      object N51: TMenuItem
        Caption = '5'
        OnClick = N51Click
      end
      object N61: TMenuItem
        Caption = '6'
        OnClick = N61Click
      end
      object N71: TMenuItem
        Caption = '7'
        OnClick = N71Click
      end
      object N81: TMenuItem
        Caption = '8'
        OnClick = N81Click
      end
      object N91: TMenuItem
        Caption = '9'
        OnClick = N91Click
      end
      object N101: TMenuItem
        Caption = '10'
        OnClick = N101Click
      end
      object N111: TMenuItem
        Caption = '11'
        OnClick = N111Click
      end
      object N121: TMenuItem
        Caption = '12'
        OnClick = N121Click
      end
      object N131: TMenuItem
        Caption = '13'
        OnClick = N131Click
      end
      object N141: TMenuItem
        Caption = '14'
        OnClick = N141Click
      end
      object N151: TMenuItem
        Caption = '15'
        OnClick = N151Click
      end
      object N161: TMenuItem
        Caption = '16'
        OnClick = N161Click
      end
      object N171: TMenuItem
        Caption = '17'
        OnClick = N171Click
      end
      object N181: TMenuItem
        Caption = '18'
        OnClick = N181Click
      end
      object N191: TMenuItem
        Caption = '19'
        OnClick = N191Click
      end
      object N201: TMenuItem
        Caption = '20'
        OnClick = N201Click
      end
      object N211: TMenuItem
        Caption = '21'
        OnClick = N211Click
      end
      object N221: TMenuItem
        Caption = '22'
        OnClick = N221Click
      end
      object N231: TMenuItem
        Caption = '23'
        OnClick = N231Click
      end
      object N142: TMenuItem
        Caption = '24'
        OnClick = N142Click
      end
      object N251: TMenuItem
        Caption = '25'
        OnClick = N251Click
      end
      object N261: TMenuItem
        Caption = '26'
        OnClick = N261Click
      end
    end
    object triangular1: TMenuItem
      Caption = 'triangular'
      object N12: TMenuItem
        Caption = '1'
        OnClick = N12Click
      end
      object N22: TMenuItem
        Caption = '2'
        OnClick = N22Click
      end
      object N32: TMenuItem
        Caption = '3'
        OnClick = N32Click
      end
      object N42: TMenuItem
        Caption = '4'
        OnClick = N42Click
      end
      object N52: TMenuItem
        Caption = '5'
        OnClick = N52Click
      end
      object N62: TMenuItem
        Caption = '6'
        OnClick = N62Click
      end
      object N72: TMenuItem
        Caption = '7'
        OnClick = N72Click
      end
      object N82: TMenuItem
        Caption = '8'
        OnClick = N82Click
      end
      object N92: TMenuItem
        Caption = '9'
        OnClick = N92Click
      end
      object N102: TMenuItem
        Caption = '10'
        OnClick = N102Click
      end
      object N112: TMenuItem
        Caption = '11'
        OnClick = N112Click
      end
      object N122: TMenuItem
        Caption = '12'
        OnClick = N122Click
      end
      object N132: TMenuItem
        Caption = '13'
        OnClick = N132Click
      end
      object N143: TMenuItem
        Caption = '14'
        OnClick = N143Click
      end
      object N152: TMenuItem
        Caption = '15'
        OnClick = N152Click
      end
      object N162: TMenuItem
        Caption = '16'
        OnClick = N162Click
      end
      object N172: TMenuItem
        Caption = '17'
        OnClick = N172Click
      end
      object N182: TMenuItem
        Caption = '18'
        OnClick = N182Click
      end
      object N192: TMenuItem
        Caption = '19'
        OnClick = N192Click
      end
      object N202: TMenuItem
        Caption = '20'
        OnClick = N202Click
      end
      object N212: TMenuItem
        Caption = '21'
        OnClick = N212Click
      end
      object N222: TMenuItem
        Caption = '22'
        OnClick = N222Click
      end
      object N232: TMenuItem
        Caption = '23'
        OnClick = N232Click
      end
      object N144: TMenuItem
        Caption = '24'
        OnClick = N144Click
      end
      object N252: TMenuItem
        Caption = '25'
        OnClick = N252Click
      end
      object N262: TMenuItem
        Caption = '26'
        OnClick = N262Click
      end
      object N271: TMenuItem
        Caption = '27'
        OnClick = N271Click
      end
    end
    object cadMtx1: TMenuItem
      Caption = 'mod exam'
      object N13: TMenuItem
        Caption = '1'
        OnClick = N13Click
      end
      object N23: TMenuItem
        Caption = '2'
        OnClick = N23Click
      end
      object cadamatrix1: TMenuItem
        Caption = 'cad a matrix'
        OnClick = cadamatrix1Click
      end
      object N33: TMenuItem
        Caption = '3'
        OnClick = N33Click
      end
      object N43: TMenuItem
        Caption = '4'
        OnClick = N43Click
      end
      object N53: TMenuItem
        Caption = '5'
        OnClick = N53Click
      end
      object N63: TMenuItem
        Caption = '6'
        OnClick = N63Click
      end
      object llenarde1losvacios1: TMenuItem
        Caption = 'llenar de 1 los vacios'
        OnClick = llenarde1losvacios1Click
      end
    end
    object vectores1: TMenuItem
      Caption = 'vectores'
      object cargarRND1: TMenuItem
        Caption = 'cargarRND'
        OnClick = cargarRND1Click
      end
      object cargar2RND1: TMenuItem
        Caption = 'cargar 2RND'
        OnClick = cargar2RND1Click
      end
      object N14: TMenuItem
        Caption = 'buscar'
        OnClick = N14Click
      end
      object cantidad1: TMenuItem
        Caption = 'cantidad'
        OnClick = cantidad1Click
      end
      object recorrer1: TMenuItem
        Caption = 'recorrer'
        OnClick = recorrer1Click
      end
      object anadirenp1: TMenuItem
        Caption = 'anadir en p'
        OnClick = anadirenp1Click
      end
      object eliminar1: TMenuItem
        Caption = 'eliminar'
        OnClick = eliminar1Click
      end
      object invertir1: TMenuItem
        Caption = 'invertir'
        OnClick = invertir1Click
      end
      object ordenar1: TMenuItem
        Caption = 'ordenar'
        OnClick = ordenar1Click
      end
      object cargarveccondig1001: TMenuItem
        Caption = 'cargar vec con dig -100'
        OnClick = cargarveccondig1001Click
      end
      object devecatnuminvertido1: TMenuItem
        Caption = 'de vec at num invertido'
        OnClick = devecatnuminvertido1Click
      end
      object eliminarmdatosdeunap1: TMenuItem
        Caption = 'eliminar m datos de una p'
        OnClick = eliminarmdatosdeunap1Click
      end
      object insertar1letraenunap1: TMenuItem
        Caption = 'insertar 1 letra en una p'
        OnClick = insertar1letraenunap1Click
      end
      object movermulde3alfinal1: TMenuItem
        Caption = 'mover mul de 3 al final'
        OnClick = movermulde3alfinal1Click
      end
      object insertar1vecaotroenp1: TMenuItem
        Caption = 'insertar 1 vec a otro en p'
        OnClick = insertar1vecaotroenp1Click
      end
      object sumadelsegmetno1: TMenuItem
        Caption = 'suma del segmetno'
        OnClick = sumadelsegmetno1Click
      end
      object cadavector1: TMenuItem
        Caption = 'cad a vector'
        OnClick = cadavector1Click
      end
      object pasarprimeraletradelvectoracadena1: TMenuItem
        Caption = 'pasar primera letra del vector a cadena'
        OnClick = pasarprimeraletradelvectoracadena1Click
      end
      object verifpalindromo1: TMenuItem
        Caption = 'verif palindromo'
        OnClick = verifpalindromo1Click
      end
    end
    object cadenas1: TMenuItem
      Caption = 'cadenas'
      object invertir2: TMenuItem
        Caption = 'invertir '
        OnClick = invertir2Click
      end
      object verifpalindrome1: TMenuItem
        Caption = 'verifpalindrome'
        OnClick = verifpalindrome1Click
      end
      object denumacadrepnum1: TMenuItem
        Caption = 'de num a cad rep num'
        OnClick = denumacadrepnum1Click
      end
    end
    object numeros1: TMenuItem
      Caption = 'numeros'
      object sumabinarios1: TMenuItem
        Caption = 'suma binarios'
        OnClick = sumabinarios1Click
      end
      object sumaoctales1: TMenuItem
        Caption = 'suma octales'
        OnClick = sumaoctales1Click
      end
      object factorial1: TMenuItem
        Caption = 'factorial'
        OnClick = factorial1Click
      end
    end
  end
end