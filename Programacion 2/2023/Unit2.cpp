//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
/**************CADENAS***************/

/*Escribir una funcion que devuelva la cantidad de digitos
  pares que estan inmediaamente antes de uno impar
  Ej. CantDigPares(3827435)== 2*/

  byte  CantDigPares (Cardinal n)
{  byte r;
   if (n<10){
	r=0;
   } else {  // asumimos que hay mas de 2 digitos
	   r=CantDigPares (n/10);
	   byte izq = (n/10) % 10;
	   byte der = (n%10);
	   if ((izq % 2==0) && (der % 2==1)){
			r = r +1 ;
	   }
   }
   return r;

}

void __fastcall TForm1::CantDigParesDif1Click(TObject *Sender)
{
    Edit2->Text=CantDigPares(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Escribir una funcion que muestre la cantidad de digitos
  pares que estan inmediaamente antes de uno impar
  Ej. GetDigPares(3827435)== 2,4*/

Cardinal GetDigPares(Cardinal n){
	Cardinal r;
	if(n<10){
		r=0;
	}else{
		r=GetDigPares(n/10);
		byte izq=(n/10)%10;
		byte der=(n%10);
		if ((izq%2==0)&&(der%2==1)){
			r=r*10+izq;
		}
	}
	return r;
}

void __fastcall TForm1::GetDigPares1Click(TObject *Sender)
{
	Edit2->Text=GetDigPares(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

//Ej. MayorMenor(23164) --> 61

byte MayorMenor(Cardinal n)
{ 	byte a, b;
	if (n<10) {
		a=b=n;
	} else {
		byte p=MayorMenor(n/10);
		b=p%10;
		a=p/10;
		if(n%10>a){
			a=n%10;
		}
		if(n%10<b){
			b=n%10;
		}
	}
	return a * 10 + b;
}

void __fastcall TForm1::GetDigPares2Click(TObject *Sender)
{
	Edit2->Text=MayorMenor(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

//Ej. MayorMenor(23164) --> 61, solo que me muestra en diferente Edit

void mayorMenor2(Cardinal n, byte &may, byte &men)
{ 	byte a, b;
	if (n < 10) { //n = 1
		may = n;
		men = n;
	} else {
		mayorMenor2(n / 10, may, men);
		if ((n % 10) > may) {
			may = n %10;
		}
		if ((n %10) < men) {
			men = n %10;
		}
	}
}

void __fastcall TForm1::MayorMenor21Click(TObject *Sender)
{
	byte may, men;
	mayorMenor2(StrToInt(Edit1->Text),may,men);
	Edit2->Text=may;
	Edit3->Text=men;
}
//---------------------------------------------------------------------------

/*Escribir un proceso para eliminar el primer numero de una cadena
  Ej. x="Hola45como46estas" -> "Holacomo46estas"*/

bool EsDigito(char c)
{
  return (c>='0') && (c<='9');
}

void EliminarPrimerNumero(AnsiString &x)
{ if (x != "") {
	char c = x[1];
	x.Delete(1,1);
	if (!EsDigito(c)) {
		EliminarPrimerNumero(x);
		x = (AnsiString)c + x;
	} else {
	   if ((x != "") && (EsDigito(x[1]))) {
	   EliminarPrimerNumero(x);
	   }
	}

  }
}

void __fastcall TForm1::ElimPrimNum1Click(TObject *Sender)
{
	AnsiString cadena=Edit1->Text;
	EliminarPrimerNumero(cadena);
	Edit2->Text=cadena;
}
//---------------------------------------------------------------------------

/*Escribir una funcion que devuelva la palabra mas larga de una cadena
  Ej. CadenaMasLarga("Esta es una prueba mas") -> "prueba"*/

String PalabraMasLarga(String x )
{
  String PalabraLarga;
  x = x.Trim();
  byte n = x.Length();
  if (n == 0) {
	PalabraLarga = "";
  } else {
	byte p = x.LastDelimiter(' ');
	String UltimaPalabra = x.SubString(p+1, n-p);
	//ShowMessage(UltimaPalabra);
	x.SetLength(p - 1);
	PalabraLarga = PalabraMasLarga(x);
	if (UltimaPalabra.Length() > PalabraLarga.Length()) {
		PalabraLarga = UltimaPalabra;
	}
  }
  return PalabraLarga;
}

void __fastcall TForm1::PalMasLarga1Click(TObject *Sender)
{
	String cadena = Edit1->Text;
	Edit2->Text = PalabraMasLarga(cadena);
}
//---------------------------------------------------------------------------

/*Escribir un proceso que lleve el menor de los digitos al inicio
  de un numero Ej. x=382731 -> x=138273*/

void MoverMenor(Cardinal &x)
{ if (x>9){
	byte d=x%10;
	x=x/10;
	if((x%10)>d){
	  byte aux=d;
	  d=x%10;
	  x=(x/10)*10+aux;
	}
	MoverMenor(x);
	x=x*10+d;
  }

}

void MoverMenor(Cardinal &n, Cardinal m)
{
   n=100;
   m=200;
}

void __fastcall TForm1::MoverMenor1Click(TObject *Sender)
{
    Cardinal n=StrToInt(Edit1->Text);
	MoverMenor(n);
	Edit2->Text=n;
}
//---------------------------------------------------------------------------

/*Escribir una funcion que devuelva una cadena formada por los
  digitos de un numero repetidos la cantidad de veces que el
  digito representa, max 2 funciones.
  Ej. CadDeDig(5021)->"55555221"*/

String CadDeDig(Cardinal n)
{
	String s;
	if(n==0){
	  s="";
	}else{
	   s=CadDeDig(n/10);
	   if (n%10>0){
		 Cardinal p=(n%10)*((pow10(n%10)-1)/9);
		 s=s+p;
	   }
	}
	return s;
}

void __fastcall TForm1::CadenaDeDig1Click(TObject *Sender)
{
	Cardinal n=StrToInt(Edit1->Text);
	Edit2->Text=CadDeDig(n);
}
//---------------------------------------------------------------------------

/*Escribir una funcion que sume los numeros de una cadena
  Ej. SumaNumeros("20Hola 10Como")->30*/

bool  EsDigito(wchar_t x)
{
   String nro="0123456789";
   return nro.Pos(x)>0;
}

String UltimoNro(String cad)
{
   String r;
   if (cad==""){
	  r="";
   }else{
	   wchar_t x=cad[cad.Length()];
	   cad.SetLength(cad.Length()-1);
	   if (!EsDigito(x)){
		 r=UltimoNro(cad);
	   }else{
		   if ((cad!="")&&EsDigito(cad[cad.Length()])){
			  r=UltimoNro(cad)+ String(x);
		   }else{
			   r=(String)x;
		   }
	   }
   }
   return r;
}

Cardinal SumaNumeros(String cad)
{
	Cardinal nro;
	if (cad==""){
	  nro=0;
	}else{
		String ultNro=UltimoNro(cad);
		if (ultNro==""){
		  nro=0;
		}else{
			byte p=cad.LastDelimiter(ultNro);
			cad.SetLength(p-ultNro.Length()-1);
			nro=StrToInt(ultNro)+SumaNumeros(cad);
		}
	}
	return nro;
}

void __fastcall TForm1::SumaNum1Click(TObject *Sender)
{
	Edit2->Text=SumaNumeros(Edit1->Text);
}
//---------------------------------------------------------------------------

//Ej: x=123456 --> 135

void ElimPares (Cardinal &n)
{   if (n < 10){
		if (n%2 == 0)
		 n=0;
	}else{
		byte d;
		d = n%10;
		n = n/10;
		ElimPares(n);
		if (d%2==1)
			n = n*10+d;
	}
}
void __fastcall TForm1::ElimPares1Click(TObject *Sender)
{
	Cardinal a=StrToInt(Edit1->Text);
	ElimPares(a);
	Edit2->Text=a;
}
//---------------------------------------------------------------------------

/*Funcion o proceso que cuente la cantidad qeu signos que hay despues de una
  palabra. Ej. ContadorConSignos(hola@comoestas*pero#)->3*/

Byte ContadorDeSignos (AnsiString &x){
	byte r;
	x=x.Trim();
	Byte c=x.LastDelimiter("~!@#$%^&*()_+1 234567890");
	Byte L=x.LastDelimiter("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");
	Byte len=x.Length();
	if (x!="") {
		if (isalpha(x[x.Length()])) {
			x.Delete(c+1,len-c+1);
			r=ContadorDeSignos (x);
			r++;
		}else{
			x.Delete(L+1,len-L+1);
			r=ContadorDeSignos (x);
		}
	}else{
		r=0;
	}
return r;
}

void __fastcall TForm1::ContadorDeSignos1Click(TObject *Sender)
{
    AnsiString x=Edit1->Text;
	Edit2->Text=ContadorDeSignos (x);
}
//---------------------------------------------------------------------------

/*Proceso para eliminar el ultimo numero de una cadena
  Ej. x("Hola45como46estas") -> "Hola45comoestas"*/

void ElimUltNum (AnsiString &x)
{
	byte n=x.Length();
	if(x!=""){
	  char c=x[n];
	  x.Delete(n,1);
	  if(!EsDigito(c)){
		ElimUltNum(x);
		x=x+AnsiString(c);
	  }else{
		if((x!="")&&(EsDigito(x[n-1])))
		  ElimUltNum(x);
	  }
	}
}

void __fastcall TForm1::ElimUltNum1Click(TObject *Sender)
{
    AnsiString x= Edit1->Text;
	ElimUltNum(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

//Ej. x(12345)-> 54321

void invertir(String &x) {
	int n = x.Length();
	if (x != "") {
		if (n > 1) {
			wchar_t a = x[1];
			wchar_t b = x[n];
			x.Delete(n, 1);
			x.Delete(1, 1);
			invertir(x);
			x = String(b) + x + a;
		}
	}
}

void __fastcall TForm1::InvertirCad1Click(TObject *Sender)
{
	/*String x = InputBox("Invertir", "cad :", "");
	invertir(x);
	ShowMessage(x)*/

	String x= Edit1->Text;
	invertir(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

//Ej.  x = hola mundo => 2

byte contarPalabras(String x) {
	byte c;
	if (x == "") {
		c = 0;
	}
	else if (x.Length() == 1) {
		c = 0;
		if (x[1] != ' ') {
			c++;
		}
	}
	else {
		c = 0;
		if (x[1] != ' ' && x[2] == ' ') {
			c++;
		}
		x.Delete(1, 1);
		c += contarPalabras(x);
	}
	return c;
}

void __fastcall TForm1::ContadorPalabras1Click(TObject *Sender)
{
	 /*
	 if (x[i] != ' ' y x[i+1] == ' ')
	 c++
	 x = hola_mundo_ ?? => 2       //ojooo!!!!
	 */
	/*String x = InputBox("ContarPalabras", "cad :", "");
	byte c = contarPalabras(x);
	ShowMessage(c);*/

	String x= Edit1->Text;
	byte c = contarPalabras(x);
	Edit2->Text=c;
}
//---------------------------------------------------------------------------

//Ej. Hola --> Hl

bool esVocal(wchar_t z) {
	/*
	 z = m   >> w.Pos(z) = 0
	 z = p   >> w.Pos(z) = 0
	 z = A   >> w.Pos(z) = 6
	 z = a   >> w.Pos(z) = 1
	 */
	String w = "aeiouAEIOU";
	return w.Pos(z) > 0;
}
void eliminarVocales(String &x) {
	if (x != "") {
		wchar_t z = x[1];
		x.Delete(1, 1);
		eliminarVocales(x);
		if (!esVocal(z)) {
			x = String(z) + x;
		}
	}
}

void __fastcall TForm1::ElimVocales1Click(TObject *Sender)
{
	/*
	 ""  ==>     ""
	 "a" ==>     ""
	 "hola " =>   "hl "
	 x = ho_
	 c = h
	 c??esVocal
	 x=h_
	 ----------------
	 x = o_
	 c = o
	 c??esVocal
	 => x=_
	 ----------------
	 x = _
	 c = _
	 c??esVocal
	 => x=_
	 ----------------
	 x = ""
	 */
	/*String x = InputBox("EliminarVocales", "cad :", "");
	eliminarVocales(x);
	ShowMessage(x);*/

	String x= Edit1->Text;
	eliminarVocales(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

// Ej. Hola como --> ola omo

void eliminarPrimerLetra(String &x) {
	byte n = x.Length();
	if (x != "") {
		byte p = x.LastDelimiter(" ");
		String w = x.SubString(p + 1, n - p);
		x.SetLength(p - 1);
		eliminarPrimerLetra(x);
		if (w != "") {
			w.Delete(1, 1);
		}
		x = x + " " + w;
	}
}

void __fastcall TForm1::ElimPrimerLetra1Click(TObject *Sender)
{
    /*String x = InputBox("Eliminar1erLetra", "cad :", "");
	eliminarPrimerLetra(x);
	ShowMessage(x);      */

	String x= Edit1->Text;
	eliminarPrimerLetra(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

//Ej. como --> omoc

void invertirPalabras(String &x) {
	byte n = x.Length();
	if (n > 0) {
		byte p = x.LastDelimiter(" ");
		String w = x.SubString(p + 1, n - p);
		x.SetLength(p - 1);
		invertirPalabras(x);
		invertir(w);
		x = x + " " + w;
	}
}

void __fastcall TForm1::InvertirPalabra1Click(TObject *Sender)
{
    /*String x = InputBox("Invertir Palabras", "cad :", "");
	invertirPalabras(x);
	ShowMessage(x);*/

	String x= Edit1->Text;
	invertirPalabras(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

// Algoritmo que carga una matriz por filas de izquierda a derecha
/*
	 1  2  3  4
	 5  6  7  8
	 9 10 11 12
	13 14 15 16
*/

void LlenarFila(TStringGrid *A, byte m, byte n, byte num) {
	if (n > 0) {
		LlenarFila(A, m, n - 1, num - 1);
		A->Cells[n - 1][m] = num;
	}
}

void CargarFilas(TStringGrid *A, byte m, byte n) {
	if (m > 0) {
		CargarFilas(A, m - 1, n);
		LlenarFila(A, m - 1, n, m * n);
	}
}

void __fastcall TForm1::Matrices2Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	byte m = StringGrid1->RowCount;
	byte n = StringGrid1->ColCount;
	CargarFilas(StringGrid1, m, n);
}
//---------------------------------------------------------------------------

// Algoritmo que carga una matriz por filas de derecha a izquierda
/*
	4  3  2  1
	8  7  6  5
	12 11 10 9
	16 15 14 13
*/

void Llenar_HDI(TStringGrid *v, byte row, byte col, byte &serie) {
	if (col == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
		Llenar_HDI(v, row, col - 1, serie);
    }
}

void Matriz_DIAB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		Llenar_HDI(M, row, col, serie);
	} else {
		Matriz_DIAB(M, row - 1, col, serie);
		Llenar_HDI(M, row, col, serie);
	}
}

void __fastcall TForm1::N21Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_DIAB(StringGrid1, row, col, serie);
	Llenar_HDI(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

// Algoritmo que carga una matriz por columnas de arriba a abajo
/*
	 1 5 9  13
	 2 6 10 14
	 3 7 11 15
	 4 8 12 16
*/

void Llenar_VAB(TStringGrid *v, byte row, byte col, byte &serie) {
	if (row == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		Llenar_VAB(v, row - 1, col, serie);
		v->Cells[col - 1][row - 1] = serie;
		serie++;
    }
}

void Matriz_ABID(TStringGrid *M, byte row, byte col, byte &serie) {
	if (col == 1) {
		Llenar_VAB(M, row, col, serie);
	} else {
		Matriz_ABID(M, row, col - 1, serie);
		Llenar_VAB(M, row, col, serie);
    }
}

void __fastcall TForm1::N22Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_ABID(StringGrid1, row, col, serie);
//	Llenar_VAB(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

// Algoritmo que carga una matriz en serpiente de izq a der
/*
	 1   2   3   4
	 8   7   6   5
	 9   10  11  12
	 16  15  14  13
*/

void Llenar_HID(TStringGrid *v, byte row, byte col, byte &serie) {
	if (col == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		Llenar_HID(v, row, col - 1, serie);
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	}
}

void Matriz_Serpiente_IDDI_AB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		Llenar_HID(M, row, col, serie);
	} else {
		Matriz_Serpiente_IDDI_AB(M, row - 1, col, serie);
		if (row % 2 == 0) {
			Llenar_HDI(M, row, col, serie);
		} else {
			Llenar_HID(M, row, col, serie);
        }
    }
}

void __fastcall TForm1::N41Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_Serpiente_IDDI_AB(StringGrid1, row, col, serie);
}

//---------------------------------------------------------------------------

// Algoritmo que carga una matriz en serpiente de izq a der
/*
	 13 14 15 16
	 12 11 10 9
	 5  6  7  8
	 4  3  2  1
*/

/*void Llenar_HID(TStringGrid *v, byte row, byte col, byte &serie) {
	if (col == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		Llenar_HID(v, row, col - 1, serie);
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	}
}*/

void Matriz_Serpiente_DIID_BA(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		if ((col - row) % 2 == 0) {
			Llenar_HDI(M, row, col, serie);
		} else {
			Llenar_HID(M, row, col, serie);
		}
	} else {
		if ((col - row) % 2 == 0) {
			Llenar_HDI(M, row, col, serie);
		} else {
			Llenar_HID(M, row, col, serie);
		}
		Matriz_Serpiente_DIID_BA(M, row - 1, col, serie);
	}
}

void __fastcall TForm1::N42Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Matriz_Serpiente_DIID_BA(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

// Algoritmo que carga una matriz triangular de izq a der
/*
	 1  2 3 4
	 5  6 7
	 8  9
	 10
*/

void Triangular_SI_IDAB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row == 1) {
		Llenar_HID(M, row, col, serie);
	} else {
		Triangular_SI_IDAB(M, row - 1, col, serie);
		Llenar_HID(M, row, col - (row - 1), serie);
	}
}

void __fastcall TForm1::N61Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Triangular_SI_IDAB(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------


// Algoritmo que carga una matriz triangular de der a izq
/*
	 4 3 2 1
	   7 6 5
		 9 8
		  10
*/

void Llenar_HDI_Diagonal(TStringGrid *v, byte row, byte col, byte &serie) {
	if (col <= row) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
		Llenar_HDI_Diagonal(v, row, col - 1, serie);
	}
}

void Triangular_SD_DIAB(TStringGrid *M, byte row, byte col, byte &serie) {
	if (row <= 1) {
		Llenar_HDI_Diagonal(M, row, col, serie);
	} else {
    	Triangular_SD_DIAB(M, row - 1, col, serie);
		Llenar_HDI_Diagonal(M, row, col, serie);
    }
}

void __fastcall TForm1::N62Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Triangular_SD_DIAB(StringGrid1, row, col, serie);
//	Llenar_HDI_Diagonal(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

/*
	 1 5 8 10
	 2 6 9
	 3 7
	 4
*/

void Triangular_SI_ABID(TStringGrid *M, byte row, byte col, byte &serie) {
	if (col <= 1) {
		Llenar_VAB(M, row, col, serie);
	} else {
		Triangular_SI_ABID(M, row, col - 1, serie);
		Llenar_VAB(M, row - (col - 1), col, serie);
    }
}

void __fastcall TForm1::N81Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	byte row = StringGrid1->RowCount;
	byte col = StringGrid1->ColCount;
	byte serie = 1;
	Triangular_SI_ABID(StringGrid1, row, col, serie);
}
//---------------------------------------------------------------------------

/* Algoritmo para cargar una matriz m*n   (hipótesis m-1, n-1)

 1  2  3  4
 2  2  3  4
 3  3  3  4
 4  4  4  4
 */

void Llenar_FilaColumna(TStringGrid *A, Word f, Word n) {
	if (n > 0) { // caso general
		Llenar_FilaColumna(A, f, n - 1);
		A->Cells[n - 1][f] = f + 1;
		A->Cells[f][n - 1] = f + 1;
	}
}

void Cargar_Matriz2(TStringGrid *A, Word m, Word n) {
	if (m > 0) { // caso general
		Cargar_Matriz2(A, m - 1, n - 1);
		Llenar_FilaColumna(A, m - 1, n);
	}
}

void __fastcall TForm1::N82Click(TObject *Sender)
{
	StringGrid1->ColCount = StrToInt(Edit1->Text);
	StringGrid1->RowCount = StrToInt(Edit2->Text);
	Cargar_Matriz2(StringGrid1, StringGrid1->RowCount, StringGrid1->ColCount);
}

//---------------------------------------------------------------------------

/* Cargar una matriz por filas

 16  15  14  13
 12  11  10   9
 8   7   6   5
 4   3   2   1
 */

void cargarCol(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (c > 0) {
		m->Cells[c - 1][f - 1] = v;
		v++;
		cargarCol(m, f, c - 1, v);
	}
}

void cargarTodoFila(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		cargarCol(m, f, c, v);
		cargarTodoFila(m, f - 1, c, v);
	}
}

void __fastcall TForm1::N101Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	Cardinal v = 1;
	cargarTodoFila(StringGrid1, f, c, v);

}
//---------------------------------------------------------------------------

/* Cargar una matriz por columnas

 16  12  8  4
 15  11  7  3
 14  10  6  2
 13   9  5  1
 */

void cargarFil(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		m->Cells[c - 1][f - 1] = v;
		v++;
		cargarFil(m, f - 1, c, v);
	}
}

void cargarTodoCol(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (c > 0) {
		cargarFil(m, f, c, v);
		cargarTodoCol(m, f, c - 1, v);
	}
}

void __fastcall TForm1::N11Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	Cardinal v = 1;
	cargarTodoCol(StringGrid1, f, c, v);
}
//---------------------------------------------------------------------------

/* Cargar diagonal secundaria inferior de una matriz

		  10
	   9  8
    7  6  5
 4  3  2  1
 */

void aux_sec_inf(TStringGrid* m, Byte f, Byte lc, Byte c, Cardinal &v) {
	if (c > lc) {
		Byte fil = f - 1;
		Byte col = c - 1;
		m->Cells[col][fil] = v;
		v++;
		aux_sec_inf(m, f, lc, c - 1, v);
	}
}

void diag_sec_inf(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		Byte lc = c - f;
		aux_sec_inf(m, f, lc, c, v);
		diag_sec_inf(m, f - 1, c, v);
	}
}


void __fastcall TForm1::N12Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	Cardinal v = 1;
	diag_sec_inf(StringGrid1, f, c, v);
}
//---------------------------------------------------------------------------

/* Cargar el exterior de una matriz

 1  2  3  4
 5        5
 4        6
 3  2  1  7
 */

void ext_fila(TStringGrid* m, Byte f, Byte c, Cardinal &v, bool sube) {
	if (sube) {
		if (c <= m->ColCount) {
			m->Cells[c - 1][f - 1] = v;
			v++;
			ext_fila(m, f, c + 1, v, sube);
		}
	}
	else {
		if (c > 0) {
			m->Cells[c - 1][f - 1] = v;
			v++;
			ext_fila(m, f, c - 1, v, sube);
		}
	}
}

void ext_col(TStringGrid* m, Byte f, Byte c, Cardinal &v, bool sube) {
	if (sube) {
		if (f <= m->RowCount) {
			m->Cells[c - 1][f - 1] = v;
			v++;
			ext_col(m, f + 1, c, v, sube);
		}
	}
	else {
		if (f > 1) {
			m->Cells[c - 1][f - 1] = v;
			v++;
			ext_col(m, f - 1, c, v, sube);
		}
	}
}

void cargar_exterior(TStringGrid* m, int f, int c) {
	if (f != -1) {
		Byte i = m->RowCount;
		Byte j = m->ColCount;
		bool subeFila = f == 1;
		bool subeCol = c == 1;
		Cardinal v = 1;
		Byte proxFil, proxCol;
		if (f == 1)
			proxFil = f + 1;
		else
			proxFil = f - 1;
		if (c == 1)
			proxCol = j;
		else
			proxCol = 1;
		ext_fila(m, f, c, v, subeFila);
		ext_col(m, proxFil, proxCol, v, subeCol);
		if (f == m->RowCount)
			cargar_exterior(m, -1, -1);
		else
			cargar_exterior(m, i, j - 1);
	}
}

void __fastcall TForm1::N131Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	cargar_exterior(StringGrid1, 1, 1);
}
//---------------------------------------------------------------------------

/* Cargar la matriz diagonal inferior A(n)

			1
		 3  5
	 7   9  11
 13 15  17  19
 */

void aux_matriz1(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (c > 0) {
		Byte fil = m->RowCount - f;
		Byte col = m->ColCount - c;
		m->Cells[col][fil] = v;
		v += 2;
		aux_matriz1(m, f, c - 1, v);
	}
}

void cargar_matriz1(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		Byte col = m->ColCount - c + 1;
		aux_matriz1(m, f, col, v);
		cargar_matriz1(m, f - 1, c - 1, v);
	}
}

void __fastcall TForm1::N141Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	Cardinal v = 1;
	cargar_matriz1(StringGrid1, f, c, v);
}
//---------------------------------------------------------------------------

/* Cargar la matriz diagonal superior A(n)

 1  1  2  3
	1  2  3
	   1  3
          1
 */

void aux_matriz2(TStringGrid* m, Byte f, Byte c, Byte lim) {
	if (c > lim) {
		Byte fil = m->RowCount - f;
		if (c == lim + 1)
			m->Cells[c - 1][fil] = 1;
		else
			m->Cells[c - 1][fil] = (c - 1);
		aux_matriz2(m, f, c - 1, lim);
	}
}

void cargar_matriz2(TStringGrid* m, Byte f, Byte c) {
	if (f > 0) {
		Byte lim = m->ColCount - c;
		aux_matriz2(m, f, m->ColCount, lim);
		cargar_matriz2(m, f - 1, c - 1);
	}
}

void __fastcall TForm1::N142Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	cargar_matriz2(StringGrid1, f, c);
}
//---------------------------------------------------------------------------

/* Cargar la matriz caracol A(m*n)

 1    2    3  4
 12   13   14  5
 11   16   15  6
 10    9    8  7
 */

void arriba(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v) {
	if (ca < cb) {
		m->Cells[ca - 1][f - 1] = v;
		v++;
		arriba(m, f, ca + 1, cb, v);
	}
}

void derecha(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v) {
	if (fa < fb) {
		m->Cells[c - 1][fb - 1] = v;
		v++;
		derecha(m, fa, fb - 1, c, v);
	}
}

void abajo(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v) {
	if (ca < cb) {
		m->Cells[cb - 1][f - 1] = v;
		v++;
		abajo(m, f, ca, cb - 1, v);
	}
}

void izquierda(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v) {
	if (fa < fb) {
		m->Cells[c - 1][fa - 1] = v;
		v++;
		izquierda(m, fa + 1, fb, c, v);
	}
}

void caracol(TStringGrid* m, Byte fa, Byte fb, Byte ca, Byte cb, Cardinal &v) {
	if (fa <= fb && ca <= cb) {
		if (fa == fb && ca == cb)
			m->Cells[fa - 1][ca - 1] = v;
		else {
			arriba(m, fa, ca, cb, v);
			izquierda(m, fa, fb, cb, v);
			abajo(m, fb, ca, cb, v);
			derecha(m, fa, fb, ca, v);
		}
		caracol(m, fa + 1, fb - 1, ca + 1, cb - 1, v);
	}
}

void __fastcall TForm1::N161Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	Cardinal v = 1;
	caracol(StringGrid1, 1, f, 1, c, v);
}
//---------------------------------------------------------------------------

/* Cargar la matriz caracol A(m*n)

 1   12   11  10
 2   13   16   9
 3   14   15   8
 4    5    6   7
 */

void abajo3(TStringGrid *v, byte fa, byte fb, byte c, byte &k) {
	byte m = fb - fa + 1;
	if (m > 0) {
		v->Cells[c][fa] = k++;
		abajo3(v, fa + 1, fb, c, k);
	}
}

void derecha3(TStringGrid *v, byte ca, byte cb, byte f, byte &k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][f] = k++;
		derecha3(v, ca + 1, cb, f, k);
	}
}

void arriba3(TStringGrid *v, byte fa, byte fb, byte c, byte &k) {
	byte m = fb - fa + 1;
	if (m > 0) {
		v->Cells[c][fb] = k++;
		arriba3(v, fa, fb - 1, c, k);
	}
}

void izquierda3(TStringGrid *v, byte ca, byte cb, byte f, byte &k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[cb][f] = k++;
		izquierda3(v, ca, cb - 1, f, k);
	}
}

void cargarCaracol(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &k)
{
	byte m = fb - fa + 1;
	byte n = cb - ca + 1;
	if (m * n != 0) {
		if (m * n == 1) {
			v->Cells[ca][fa] = k;
		}
		else {
			abajo3(v, fa, fb - 1, ca, k);
			derecha3(v, ca, cb - 1, fb, k);
			arriba3(v, fa + 1, fb, cb, k);
			izquierda3(v, ca + 1, cb, fa, k);
			cargarCaracol(v, fa + 1, fb - 1, ca + 1, cb - 1, k);
		}
	}
}

void __fastcall TForm1::N162Click(TObject *Sender)
{
	byte m = StrToInt(Edit1->Text);
	byte n = StrToInt(Edit2->Text);
	StringGrid1->RowCount = m;
	StringGrid1->ColCount = n;
	byte k = 1;
	cargarCaracol(StringGrid1, 0, m - 1, 0, n - 1, k);
}
//---------------------------------------------------------------------------

/* Cargar la matriz caracol A(m*n)

 1  1  1  2
 4  5  6  2
 4  8  7  2
 4  3  3  3
 */

void arriba2(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v) {
	if (ca < cb) {
		m->Cells[ca - 1][f - 1] = v;
		arriba2(m, f, ca + 1, cb, v);
	}
}

void derecha2(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v) {
	if (fa < fb) {
		m->Cells[c - 1][fb - 1] = v;
		derecha2(m, fa, fb - 1, c, v);
	}
}

void abajo2(TStringGrid* m, Byte f, Byte ca, Byte cb, Cardinal &v) {
	if (ca < cb) {
		m->Cells[cb - 1][f - 1] = v;
		abajo2(m, f, ca, cb - 1, v);
	}
}

void izquierda2(TStringGrid* m, Byte fa, Byte fb, Byte c, Cardinal &v) {
	if (fa < fb) {
		m->Cells[c - 1][fa - 1] = v;
		izquierda2(m, fa + 1, fb, c, v);
	}
}

void caracol2(TStringGrid* m, Byte fa, Byte fb, Byte ca, Byte cb, Cardinal &v) {
	if (fa <= fb && ca <= cb) {
		if (fa == fb && ca == cb)
			m->Cells[fa - 1][ca - 1] = v;
		else {
			arriba2(m, fa, ca, cb, v);
			v++;
			izquierda2(m, fa, fb, cb, v);
			v++;
			abajo2(m, fb, ca, cb, v);
			v++;
			derecha2(m, fa, fb, ca, v);
			v++;
		}
		caracol2(m, fa + 1, fb - 1, ca + 1, cb - 1, v);
	}
}

void __fastcall TForm1::N181Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	Cardinal v = 1;
	caracol2(StringGrid1, 1, f, 1, c, v);
}
//---------------------------------------------------------------------------

/* Cargar palabra en una matriz A(n)

 p  r  d
 r  a
 o  m  r
 g  a
 */

void aux_cad(TStringGrid* m, String &cad, Byte f, Byte c) {
	if (f <= m->RowCount && cad.Length() > 0) {
		char x = cad[1];
		cad.Delete(1, 1);
		m->Cells[c - 1][f - 1] = x;
		aux_cad(m, cad, f + 1, c);
	}
}

void cargar_cad(TStringGrid* m, String &cad, Byte c) {
	if (c <= m->ColCount) {
		aux_cad(m, cad, 1, c);
		cargar_cad(m, cad, c + 1);
	}
}

void __fastcall TForm1::N182Click(TObject *Sender)
{
	String frase = InputBox("", "Palabra:", "");
	cargar_cad(StringGrid1, frase, 1);

}
//---------------------------------------------------------------------------

void cargarCadena2(TStringGrid *v, byte a, byte b, String x) {
	byte N = v->ColCount;
	byte n = b - a + 1;
	if (n > 0) {
		if (x != "") {
			v->Cells[a % N][a / N] = String(x[1]);
			cargarCadena2(v, a + 1, b, x.Delete(1, 1));
		}
		else {
			v->Cells[a % N][a / N] = "";
			cargarCadena2(v, a + 1, b, x);
		}
	}
}

void __fastcall TForm1::N201Click(TObject *Sender)
{
	byte m = StrToInt(InputBox("FILAS", "N�mero: ", ""));
	byte n = StrToInt(InputBox("COLUMNAS", "N�mero: ", ""));
	StringGrid1->RowCount = m;
	StringGrid1->ColCount = n;
	String x = InputBox("CADENA", "cad:", "");
	if (x.Length() <= m * n) {
		cargarCadena2(StringGrid1, 0, m*n - 1, x);
	}
	else {
		ShowMessage("No carga la cadena");
	}
}
//---------------------------------------------------------------------------

/* Cargar la matriz espiral o dona A(m*n)

 1  1  1  1  1
 1  2  2  2  1
 1  2  3  2  1
 1  2  2  2  1
 1  1  1  1  1
 */

void aux_dona(TStringGrid* m, Byte f, Byte c, Byte l, Cardinal v) {
	if (c > l) {
		int nf = m->RowCount;
		int nc = m->RowCount;
		m->Cells[c - 1][f - 1] = v;
		m->Cells[f - 1][c - 1] = v;
		m->Cells[nc - c][nf - f] = v;
		m->Cells[nf - f][nc - c] = v;
		aux_dona(m, f, c - 1, l, v);
	}
}

void dona(TStringGrid* m, Byte f, Byte c, Cardinal v) {
	if (f > m->RowCount / 2) {
		Byte l = m->ColCount - c;
		aux_dona(m, f, c, l, v);
		dona(m, f - 1, c - 1, v + 1);
	}
}

void __fastcall TForm1::Seguimos2Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	dona(StringGrid1, f, c, 1);
}
//---------------------------------------------------------------------------

/* Cargar la matriz espiral o dona A(m*n)

 3  3  3  3  3
 3  2  2  2  3
 3  2  1  2  3
 3  2  2  2  3
 3  3  3  3  3
 */

void Llenar_Alrededor(TStringGrid *A, Word fa, Word fb, Word ca, Word cb,
	Word n, Word k) {
	if (n > 0) {
		Llenar_Alrededor(A, fa, fb, ca, cb, n - 1, k);
		A->Cells[ca + n - 1][fa] = k;
		A->Cells[ca + n - 1][fb] = k;
		A->Cells[ca][fa + n - 1] = k;
		A->Cells[cb][fa + n - 1] = k;
	}
}

void Cargar_Espiral(TStringGrid *A, Word fa, Word fb) {
	Word m = fb - fa + 1;
	if (m > 0) { // primer caso base no hace nada
		if (m == 1) // segundo caso base
				A->Cells[fa][fa] = 1;
		else { // caso general
			Cargar_Espiral(A, fa + 1, fb - 1);
			Llenar_Alrededor(A, fa, fb, fa, fb, m, (m + 1) / 2);
		}
	}
}

void __fastcall TForm1::N221Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StringGrid1->RowCount;
	Cargar_Espiral(StringGrid1, 0, StringGrid1->RowCount - 1);
}

//---------------------------------------------------------------------------

/* Cargar la matriz diagonal superior con fracciones A(m*n)

 8   4     2     1
	1/2   1/4   1/8
	     1/16  1/32
			   1/64
 */

void aux_frac(TStringGrid* m, Byte f, Byte c, Byte lim, Cardinal& num,
	Cardinal& den) {
	if (c > lim) {
		if (den == 1)
			m->Cells[c - 1][f - 1] = String(num);
		else
			m->Cells[c - 1][f - 1] = String(num) + "/" + String(den);
		if (den > 1)
			den /= 2;
		else if (den == 1)
			num *= 2;
		aux_frac(m, f, c - 1, lim, num, den);
	}
}

void cargar_frac(TStringGrid* m, Byte f, Byte c, Cardinal& num, Cardinal& den) {
	if (f > 0) {
		aux_frac(m, f, m->ColCount, c - 1, num, den);
		cargar_frac(m, f - 1, c - 1, num, den);
	}
}

void __fastcall TForm1::N231Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	Cardinal num = 1;
	Cardinal den = 64;
	cargar_frac(StringGrid1, f, c, num, den);
}
//---------------------------------------------------------------------------

/* Cargar la matriz serpiente A(m*n)

 4   3   2   1
 5   6   7   8
 12  11  10  9
 13  14  15  16
 */

void columnaSerpiente(TStringGrid *v, byte fa, byte fb, byte ca, byte cb,
	byte &k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		if (fa % 2 == 1) {
			v->Cells[ca][fa] = k++;
			columnaSerpiente(v, fa, fb, ca + 1, cb, k);
		}
		else {
			v->Cells[cb][fa] = k++;
			columnaSerpiente(v, fa, fb, ca, cb - 1, k);
		}
	}
}

void filaSerpiente(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &k)
{
	byte m = fb - fa + 1;
	if (m > 0) {
		columnaSerpiente(v, fa, fb, ca, cb, k);
		filaSerpiente(v, fa + 1, fb, ca, cb, k);
	}
}

void __fastcall TForm1::N241Click(TObject *Sender)
{
	byte m = StrToInt(Edit1->Text);
	byte n = StrToInt(Edit2->Text);
	byte k = 1;
	StringGrid1->RowCount = m;
	StringGrid1->ColCount = n;
	filaSerpiente(StringGrid1, 0, m - 1, 0, n - 1, k);
}
//---------------------------------------------------------------------------

/* Cargar la matriz diagonal A(n)

 1  1  1  1
	2  2  2
	   3  3
	      4
 */

void colTriangular1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][fa] = fa + 1;
		colTriangular1(v, fa, fb, ca + 1, cb);
	}
}

void filaTriangular1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb) {
	byte m = fb - fa + 1;
	if (m > 0) {
		colTriangular1(v, fa, fb, ca, cb);
		filaTriangular1(v, fa + 1, fb, ca + 1, cb);
	}
}

void __fastcall TForm1::N242Click(TObject *Sender)
{
	byte n = StrToInt(InputBox("ORDEN", "N�mero: ", ""));
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;
	filaTriangular1(StringGrid1, 0, n - 1, 0, n - 1);
}

//---------------------------------------------------------------------------
 /* Cargar la matriz en forma diagonal A(m*n)

 4  5  6  7
 3  4  5  6
 2  3  4  5
 1  2  3  4
 */

void cargarFilD1(TStringGrid *v, byte f, byte ca, byte cb, byte k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][f] = k;
		cargarFilD1(v, f, ca + 1, cb, k + 1);
	}
}

void cargarD1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte k) {
	byte m = fb - fa + 1;
	if (m > 0) {
		cargarFilD1(v, fb, ca, cb, k);
		cargarD1(v, fa, fb - 1, ca, cb, k + 1);
	}
}

void __fastcall TForm1::N261Click(TObject *Sender)
{
	byte m = StrToInt(Edit1->Text);
	 byte n = StrToInt(Edit2->Text);
	 StringGrid1->RowCount = m;
	 StringGrid1->ColCount = n;
	 cargarD1(StringGrid1, 0, m - 1, 0, n - 1, 1);
}
//---------------------------------------------------------------------------

