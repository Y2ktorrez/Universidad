object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 373
  ClientWidth = 663
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
    Left = 112
    Top = 8
    Width = 265
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 112
    Top = 56
    Width = 265
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 112
    Top = 112
    Width = 265
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object StringGrid1: TStringGrid
    Left = 112
    Top = 161
    Width = 465
    Height = 184
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
  object Button1: TButton
    Left = 8
    Top = 161
    Width = 75
    Height = 25
    Caption = 'Eliminar'
    TabOrder = 4
    OnClick = Button1Click
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 8
    object Numeros1: TMenuItem
      Caption = 'Numeros'
      object Numeros2: TMenuItem
        Caption = 'CantDigParesDif'
        OnClick = Numeros2Click
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
      object ElimPrimDig1: TMenuItem
        Caption = 'ElimPrimDig'
        OnClick = ElimPrimDig1Click
      end
      object PalabraMasLarga1: TMenuItem
        Caption = 'PalabraMasLarga'
        OnClick = PalabraMasLarga1Click
      end
      object MoverMenor1: TMenuItem
        Caption = 'MoverMenor'
        OnClick = MoverMenor1Click
      end
      object CadDeDig1: TMenuItem
        Caption = 'CadDeDig'
        OnClick = CadDeDig1Click
      end
      object SumaNumeros1: TMenuItem
        Caption = 'SumaNumeros'
        OnClick = SumaNumeros1Click
      end
    end
    object Vectores1: TMenuItem
      Caption = ' Vectores YA REVISADOS'
      object EliminarPos1: TMenuItem
        Caption = 'EliminarPos'
        OnClick = EliminarPos1Click
      end
      object Cargar1: TMenuItem
        Caption = 'Cargar'
        OnClick = Cargar1Click
      end
      object EliminarCant1: TMenuItem
        Caption = 'EliminarCant'
        OnClick = EliminarCant1Click
      end
      object GenerarNumero1: TMenuItem
        Caption = 'GenerarNumero'
        OnClick = GenerarNumero1Click
      end
    end
    object Matrices1: TMenuItem
      Caption = 'Matrices'
      object Cargar11: TMenuItem
        Caption = 'Escalera'
        OnClick = Cargar11Click
      end
      object MatrizAmxm1: TMenuItem
        Caption = 'Matriz A^mxm'
        OnClick = MatrizAmxm1Click
      end
      object MatrisSuperior1: TMenuItem
        Caption = 'Triangular Superior'
        OnClick = MatrisSuperior1Click
      end
      object MatrizInferior1: TMenuItem
        Caption = 'Triangular Inferior'
        OnClick = MatrizInferior1Click
      end
      object MatrisTriangularDerecho1: TMenuItem
        Caption = 'Triangular Derecho'
        OnClick = MatrisTriangularDerecho1Click
      end
      object MatrizEspiral1: TMenuItem
        Caption = 'Matriz Espiral'
        OnClick = MatrizEspiral1Click
      end
      object MatrizCaracolTriangular1: TMenuItem
        Caption = 'Matriz Caracol Triangular'
        OnClick = MatrizCaracolTriangular1Click
      end
      object MatrizModelodeExamen1: TMenuItem
        Caption = 'Matriz Modelo de Examen'
        OnClick = MatrizModelodeExamen1Click
      end
      object djwjd1: TMenuItem
      end
    end
    object djwjd2: TMenuItem
      Caption = 'Matrices'
      object Orden1: TMenuItem
        Caption = 'Orden'
        OnClick = Orden1Click
      end
      object prueba1: TMenuItem
        Caption = 'prueba'
        OnClick = prueba1Click
      end
    end
  end
end
