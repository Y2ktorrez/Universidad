object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 319
  ClientWidth = 578
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
    Left = 56
    Top = 8
    Width = 121
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 199
    Top = 8
    Width = 121
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 342
    Top = 8
    Width = 121
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    Text = 'Edit3'
  end
  object StringGrid1: TStringGrid
    Left = 40
    Top = 72
    Width = 441
    Height = 209
    DefaultColWidth = 40
    FixedCols = 0
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    ParentFont = False
    TabOrder = 3
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 8
    object Apuntedeclase1: TMenuItem
      Caption = 'Clase1'
      object Apuntedeclase2: TMenuItem
        Caption = 'Suma'
        OnClick = Apuntedeclase2Click
      end
      object Mayor1: TMenuItem
        Caption = 'Mayor'
        OnClick = Mayor1Click
      end
      object SumaDIgImp1: TMenuItem
        Caption = 'SumaDIgImp'
        OnClick = SumaDIgImp1Click
      end
    end
    object Clase21: TMenuItem
      Caption = 'Clase 2'
      object Clase22: TMenuItem
        Caption = 'ElimDigImp'
        OnClick = Clase22Click
      end
      object MayorMenor1: TMenuItem
        Caption = 'MayorMenor'
        OnClick = MayorMenor1Click
      end
    end
    object Clase31: TMenuItem
      Caption = 'Clase 3'
      object Clase32: TMenuItem
        Caption = 'Invertir'
        OnClick = Clase32Click
      end
    end
    object Clase41: TMenuItem
      Caption = 'Clase 4'
      object Clase42: TMenuItem
        Caption = 'Cargar'
        OnClick = Clase42Click
      end
      object Sumar1: TMenuItem
        Caption = 'Sumar'
        OnClick = Sumar1Click
      end
    end
    object Clase51: TMenuItem
      Caption = 'Clase 5'
    end
    object Clase52: TMenuItem
      Caption = 'Clase 6'
      object Cargar1: TMenuItem
        Caption = 'Cargar'
        OnClick = Cargar1Click
      end
      object Cargar2: TMenuItem
        Caption = 'Cargar2'
        OnClick = Cargar2Click
      end
      object Cargar31: TMenuItem
        Caption = 'Cargar3'
        OnClick = Cargar31Click
      end
    end
    object Clase71: TMenuItem
      Caption = 'Clase 7'
      object Clase72: TMenuItem
        Caption = 'Matriz Cuadrada'
        OnClick = Clase72Click
      end
      object MatrizSodok1: TMenuItem
        Caption = 'Matriz Sodok'
        OnClick = MatrizSodok1Click
      end
    end
  end
end
