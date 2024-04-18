﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

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


void __fastcall TForm1::Cadenas2Click(TObject *Sender)
{
	Edit2->Text=CantDigPares(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Escribir una funcion que muestre la cantidad de digitos
  pares que estan inmediaamente antes de uno impar
  Ej. GetDigPares(3827435)== 2,4*/

Cardinal GetDigPares(Cardinal n)
{
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

void __fastcall TForm1::N21Click(TObject *Sender)
{
	Edit2->Text=GetDigPares(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Funcion que muestre el digito mayor y el digito menos
  Ej. GetMayorMenor(23164) --> 61 */

byte GetMayorMenor(Cardinal n)
{ 	byte a, b;
	if (n<10) {
		a=b=n;
	} else {
		byte p=GetMayorMenor(n/10);
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

void __fastcall TForm1::N22Click(TObject *Sender)
{
	Edit2->Text=GetMayorMenor(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Funcion que muestre el digito mayor y el digito menos, solo que muestra
  en diferente Edit
  Ej. GetMayorMenor(23164) --> 61 */

void GetmayorMenor2(Cardinal n, byte &may, byte &men)
{ 	byte a, b;
	if (n < 10) { //n = 1
		may = n;
		men = n;
	} else {
		GetmayorMenor2(n / 10, may, men);
		if ((n % 10) > may) {
			may = n %10;
		}
		if ((n %10) < men) {
			men = n %10;
		}
	}
}

void __fastcall TForm1::N41Click(TObject *Sender)
{
	byte may, men;
	GetmayorMenor2(StrToInt(Edit1->Text),may,men);
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

void __fastcall TForm1::N42Click(TObject *Sender)
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

void __fastcall TForm1::N61Click(TObject *Sender)
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

void __fastcall TForm1::N62Click(TObject *Sender)
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


void __fastcall TForm1::N81Click(TObject *Sender)
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

void __fastcall TForm1::N82Click(TObject *Sender)
{
	Edit2->Text=SumaNumeros(Edit1->Text);
}
//---------------------------------------------------------------------------

/*Funcion que elimine los numeros pares de un digito
  Ej: x=123456 --> 135*/

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

void __fastcall TForm1::N101Click(TObject *Sender)
{
	Cardinal a=StrToInt(Edit1->Text);
	ElimPares(a);
	Edit2->Text=a;
}
//---------------------------------------------------------------------------

/*Funcion o proceso que cuente la cantidad qeu signos que hay despues de una
  palabra. Ej. ContadorConSignos(hola@comoestas*pero#)->3*/

Byte ContadorDeSignos (AnsiString &x)
{
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

void __fastcall TForm1::N111Click(TObject *Sender)
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

void __fastcall TForm1::N112Click(TObject *Sender)
{
	AnsiString x= Edit1->Text;
	ElimUltNum(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

/*Funcion que invierta una cadena de numeros
  Ej. x(12345)-> 54321*/

void invertir(String &x)
{
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

void __fastcall TForm1::N131Click(TObject *Sender)
{
	String x= Edit1->Text;
	invertir(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

/*Funcion o proceso que cuente la cantidad de palabras en una cadena
  Ej.  x = "hola mundo" => 2*/

byte contarPalabras(String x)
{
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

void __fastcall TForm1::N132Click(TObject *Sender)
{
	String x= Edit1->Text;
	byte c = contarPalabras(x);
	Edit2->Text=c;
}
//---------------------------------------------------------------------------

/*Funcion o proceso que elimine las vocales de una cadena
  Ej. Hola --> Hl*/

bool esVocal(wchar_t z)
{
	String w = "aeiouAEIOU";
	return w.Pos(z) > 0;
}

void eliminarVocales(String &x)
{
	if (x != "") {
		wchar_t z = x[1];
		x.Delete(1, 1);
		eliminarVocales(x);
		if (!esVocal(z)) {
			x = String(z) + x;
		}
	}
}

void __fastcall TForm1::N151Click(TObject *Sender)
{
	String x= Edit1->Text;
	eliminarVocales(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

/*Funcion o proceso que elimine la primera letra de una Palabra
  Ej. Hola como --> ola omo*/

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

void __fastcall TForm1::N152Click(TObject *Sender)
{
	String x= Edit1->Text;
	eliminarPrimerLetra(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

/*Funcion que invierta las palabras de una cadena
  Ej. como --> omoc*/

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

void __fastcall TForm1::N171Click(TObject *Sender)
{
	String x= Edit1->Text;
	invertirPalabras(x);
	Edit2->Text=x;
}
//---------------------------------------------------------------------------

/*Funcion o Proceso que elimine todas las letras y vocales de una
  cadena sin borrar el espacio
  ej: x = "hola23como21" --> x = "    23    21"*/

void convertir(String &cad){
	String dig="0123456789";
	byte l=cad.Length() ;
	if (l>0) {
		wchar_t ele=cad[l];
		cad.Delete(l,1);
		convertir(cad);
		if (dig.Pos(ele)>0 )
			cad=cad+ele;
			else
			cad=cad+' ';
	}
}

void __fastcall TForm1::N172Click(TObject *Sender)
{
	String cad=Edit1->Text ;
	convertir(cad);
	Edit2->Text=cad;
}
//---------------------------------------------------------------------------


/*Funcion o proceso que elimine la primera y ultima letra de una cadena
  ej: hola daniel = ol anie*/

void modex5(String &cad){
cad=cad.Trim() ;
int l=cad.Length();
	if (l>0) {
		int p=cad.LastDelimiter(' ');
		String ultpal=cad.SubString(p+2,l-(p+2));
		cad.Delete(p+1,l-p);
		modex5(cad);
		cad=cad+ultpal+' ';
	}
}

void __fastcall TForm1::N191Click(TObject *Sender)
{
	String cad=Edit1->Text ;
	modex5(cad);
	Edit2->Text=cad;
}
//---------------------------------------------------------------------------

/*Funcion o proceso que elimine menos la primera y ultima letra
  de una cadena
  ej: hola daniel --> ha dl*/

void modex5_1(String &cad){
cad=cad.Trim() ;
int l=cad.Length();
	if (l>0) {
		int p=cad.LastDelimiter(' ');
		String ultpal=cad.SubString(p+1,l-p);
		cad.Delete(p+1,l-p);
		int n=ultpal.Length() ;
		ultpal.Delete(2,n-2);
		modex5_1(cad);
		cad=cad+ultpal+' ';
	}
}

void __fastcall TForm1::N192Click(TObject *Sender)
{
	String cad=Edit1->Text ;
	modex5_1(cad);
	Edit2->Text=cad;
}
//---------------------------------------------------------------------------


/* Algoritmo para invertir una cadena
   Ejemplo: x = "Anita lava la tina" ==> x = "anit al aval atinA"*/

void InvertirCadena(AnsiString &cadena) {
	byte n = cadena.Length();
	if (!cadena.IsEmpty()) {
		if (n > 1) {
			char z1 = cadena[1];
			char z2 = cadena[n];
			cadena.Delete(n, 1);
			cadena.Delete(1, 1);
			InvertirCadena(cadena);
			cadena = AnsiString(z2) + cadena + z1;
		}
	}
}


void __fastcall TForm1::Seguimos2Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	InvertirCadena(cadena);
	Edit2->Text = cadena;
}
//---------------------------------------------------------------------------

/* Algoritmo que invierte cada palabra de una cadena
Ej: x = "Esta es una prueba mas" ==> x = "atsE se anu abeurp sam"*/
void InvertirPalabras(AnsiString &cadena) {
	if (cadena.IsEmpty()) {
	} else {
		byte n = cadena.Length();
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		InvertirPalabras(cadena);
		InvertirCadena(palabra);
		cadena = cadena + palabra + " ";
	}
}

void __fastcall TForm1::N221Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	InvertirPalabras(cadena);
	Edit2->Text = cadena;
}
//---------------------------------------------------------------------------

/* Algoritmo que verifica si una palabra es palindrome
   Ej: x = "somos" ==> true*/
bool EsPalindrome(AnsiString cadena) {
	bool result;
	byte n = cadena.Length();
	if (n <= 1) {
		result = true;
	} else {
		char izq = cadena[1];
		char der = cadena[n];
		if (izq != der) {
			result = false;
		} else {
			AnsiString nueva = cadena.SubString(2, n - 2);
			result = EsPalindrome(nueva);
		}
	}
	return result;
}

void __fastcall TForm1::N222Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	bool result = EsPalindrome(cadena);
	if (result) {
		Edit2->Text = "True";
	} else {
		Edit2->Text = "False";
	}
}
//---------------------------------------------------------------------------

/* Algoritmo que invierte el orden de las palabras en una cadena
   Ej: x = "Esta es una prueba" ==> x = "prueba una es Esta"*/
void InvertirOrden(AnsiString &cadena) {
	byte n = cadena.Length();
	if (cadena.IsEmpty()) {
		cadena = "";
	} else {
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		InvertirOrden(cadena);
		cadena = palabra + " " + cadena;
		cadena = cadena.TrimRight();
	}
}
void __fastcall TForm1::N241Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	InvertirOrden(cadena);
	Edit2->Text = cadena;
}
//---------------------------------------------------------------------------

/* Algoritmo que devuelve el numero mayor de una cadena
   Ej: x = "hola104 mundo54 como1 estan" ==> 104*/

/*bool EsDigito(char z) {
	return (z >= '0') && (z <= '9');
}*/
AnsiString PrimerNumero(AnsiString cadena) {
	AnsiString numero;
	if (cadena.IsEmpty()) {
		numero = "";
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		if (!EsDigito(z)) {
			numero = PrimerNumero(cadena);
		} else {
			if ((cadena != "") && (EsDigito(cadena[1]))) {
				numero = AnsiString(z) + PrimerNumero(cadena);
			} else {
				numero = AnsiString(z);
			}
		}
	}
	return numero;
}
Cardinal NumeroMayor(AnsiString cadena) {
	Cardinal mayor;
	if (cadena.IsEmpty()) {
		mayor = 0;
	} else {
		AnsiString z = PrimerNumero(cadena);
		if (!z.IsEmpty()) {
			cadena.Delete(1, cadena.Pos(z) + z.Length() - 1);
			mayor = NumeroMayor(cadena);
			if (StrToInt(z) > mayor) {
				mayor = StrToInt(z);
			}
		} else {
			mayor = 0;
		}
	}
	return mayor;
}

void __fastcall TForm1::N242Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	Edit2->Text = NumeroMayor(cadena);
}
//---------------------------------------------------------------------------

/*Algoritmo que devuelve la cantidad de letras de una cadena
  Ej: x = "Hola a todos" ==> 10*/
Word CantidadLetras(AnsiString cadena) {
	Word cantidad;
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		cantidad = CantidadLetras(cadena);
		if (!(z >= '0' && z <= '9') && z != ' ') {
			cantidad++;
		}
	}
	return cantidad;
}

void __fastcall TForm1::N261Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	Edit2->Text = CantidadLetras(cadena);
}
//---------------------------------------------------------------------------

/*Algoritmo que devuelve una cadena con los digitos de una cadena
  Ej: x = "hola54 como12 estan" ==> 5412*/
void CadenaDigitos(AnsiString &cadena) {
	if (cadena.IsEmpty()) {
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		CadenaDigitos(cadena);
		if (z >= '0' && z <= '9') {
			cadena = AnsiString(z) + cadena;
		}
	}
}

void __fastcall TForm1::N262Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	CadenaDigitos(cadena);
	Edit2->Text = cadena;
}
//---------------------------------------------------------------------------

/*Algoritmo que devuelve la cantidad de espacios de una cadena
  Ej: x = "hola como estan todos " ==> 4*/

byte CantidadEspacios(AnsiString cadena) {
	byte cantidad;
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		cantidad = CantidadEspacios(cadena);
		if (z == ' ') {
			cantidad++;
		}
	}
	return cantidad;
}

void __fastcall TForm1::N281Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	Edit2->Text = CantidadEspacios(cadena);
}
//---------------------------------------------------------------------------

/*Algoritmo que devuelve la suma de los digitos de una cadena
  Ej: x "hola123 como4 es4tas2" ==> 16*/
Word SumaDigitos(AnsiString cadena) {
	Word suma;
	if (cadena.IsEmpty()) {
		suma = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		suma = SumaDigitos(cadena);
		if (z >= '0' && z <= '9') {
			suma = suma + StrToInt(z);
		}
	}
	return suma;
}

void __fastcall TForm1::N282Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	Edit2->Text = SumaDigitos(cadena);
}
//---------------------------------------------------------------------------

// Algoritmo que devuelve la palabra mas corta de una cadena
// Ejemplo: x = "Este milenio es complicado" ==> es
AnsiString PalabraMasCorta(AnsiString cadena) {
	AnsiString palabraCorta;
	byte n = cadena.Length();
	cadena = cadena.Trim();
	if (cadena.IsEmpty()) {
		palabraCorta = "";
	} else {
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		palabraCorta = PalabraMasCorta(cadena);
		if (palabraCorta.Length() == 0) {
			palabraCorta = palabra;
		}
		if (palabraCorta.Length() > palabra.Length()) {
			palabraCorta = palabra;
		}
	}
	return palabraCorta;
}

void __fastcall TForm1::N301Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	Edit2->Text = PalabraMasCorta(cadena);
}
//---------------------------------------------------------------------------

/*Algoritmo que devuelve una cadena de digitos pares y digitos impares
  Ej: x = "hola723 co5mo 8 esta1s4" ==> 284*/
void CadenaPares(AnsiString &cadena) {
	AnsiString pares;
	if (!cadena.IsEmpty()) {
		char z = cadena[1];
		cadena.Delete(1, 1);
		CadenaPares(cadena);
        if ((z >= '0' && z <= '9') && (StrToInt(z) % 2 == 0)) {
			pares = pares + z;
		}
		cadena = pares + cadena;
	}
}

void __fastcall TForm1::Seguimos4Click(TObject *Sender)
{
	AnsiString cadena = Edit1->Text;
	CadenaPares(cadena);
	Edit2->Text = cadena;
}
//---------------------------------------------------------------------------


/* Escribir un proceso que lleve el mayor de los d�gitos al final de
   un numero.
   Ej.   x=382731; MoverMayor(x);x=327318*/

void Mover_Mayor(Cardinal &numero) {
	if (numero > 9) { // caso general
		byte ultimo = numero % 10; // ultimo = 1
		Cardinal aux = numero / 10; // aux = 38273
		Mover_Mayor(aux); // aux = 32738
		byte digitoFinal = aux % 10; // digitoFinal = 8
		if (ultimo < digitoFinal) { // 1 > 8 = false
			numero = aux / 10; // numero = 3273
			numero = numero * 10 + ultimo; // numero = 32731
			numero = numero * 10 + digitoFinal; // numero = 327318
		} else {
			numero = aux * 10 + ultimo;
		}
	}
}


void __fastcall TForm1::N321Click(TObject *Sender)
{
	Cardinal numero = StrToInt(Edit1->Text);
	Mover_Mayor(numero);
	Edit2->Text = StrToInt(numero);
}
//---------------------------------------------------------------------------

/* Algoritmo para contar las vocales de una cadena
   Ej: "Hola a todos, como estan" ==> 9*/

bool Es_Vocal(char z) {
	AnsiString vocales = "aeiouAEIOUáéíóúÁÉÍÓÚ";
	return vocales.Pos(z) > 0;
}

byte Contar_Vocales(AnsiString x) {
	byte contador;
	if (x == "") { // caso base
		contador = 0;
	} else { // caso general
		char z = x[1]; // z="H"
		x.Delete(1, 1); // x="ola a todos, como est�n"
		contador = Contar_Vocales(x); // contador=9
		if (Es_Vocal(z)) {
			contador++;
		}
	}
	return contador;
}

void __fastcall TForm1::N322Click(TObject *Sender)
{
	Edit2->Text = Contar_Vocales(Edit1->Text);
}
//---------------------------------------------------------------------------




