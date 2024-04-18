//---------------------------------------------------------------------------

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

/*Proceso adicional para Eliminar la cantidad de elementos de un
  vector, o tambien eliminar posisicon de un vector
  Ej. v(1,2,3,4,5), pos=2 -> v(1,2,4,5)*/

void EliminarPos(TStringGrid *v, byte &n, byte p)
{ if (n>p){
	if ((n-1)==p){
	  n=n-1;
	} else{
		byte e=StrToInt(v->Cells[n-1][0]);
		n=n-1;
		EliminarPos(v,n,p);
		v->Cells[n][0]=e;
		n=n+1;
	}
  }
}

/*Escribir un proceso para eliminar m datos de un vector de n numeros
  desde la posicion p. Pueden escribir hasta dos procesos
  Ej. Eliminar(1,4,3,2,6,7,8,1,9)->n=9,m=3,p=5 -> v(1,4,3,2,6,9)*/

// v[1, 2, 3, 4, 5] --> pos(1) cantidad a eliminar(2) --> v[1,4,5]

void EliminarCant(TStringGrid *v, byte &n, byte p, byte cant){
	if(cant>0){
			EliminarPos(v,n,p);
			EliminarCant(v,n,p,cant-1);
	}
}

void __fastcall TForm1::N12Click(TObject *Sender)
{
	 /**Llamado de la Funcion Auxiliar**/
	/*byte n=StringGrid1->ColCount;
	byte pos=StrToInt(Edit2->Text);
	EliminarPos(StringGrid1,n,pos);
	StringGrid1->ColCount=n; */

	byte n=StringGrid1->ColCount;
	byte pos=StrToInt(Edit2->Text);
	byte cant=StrToInt(Edit3->Text);
	EliminarCant(StringGrid1,n,pos,cant);
	StringGrid1->ColCount=n;
}
//---------------------------------------------------------------------------

/*Escribir un proceso que genere un numero con los elementos de un
  vector de numeros. El numero generado debe ser del ultimo al
  primero MAXIMO UN PROCESO Ej. General(8,27,3,12)n=4,x
								 x=123278*/
// generar de forma descenciente
// ej: v[ 1, 2, 3, 3, 4, 5] --> v[5, 4, 3, 3, 2, 1] no importa si es mayor o menor

void GenerarNumero(TStringGrid *v, Word n, Cardinal &x){
	if (n==0){
		x=0;
	} else if (n==1){
	   x=StrToInt(v->Cells[0][0]);
	} else {
		Word act= StrToInt(v->Cells[n-1][0]);
		GenerarNumero(v,n-1,x);
		Word CantDig=(log10((double)x)+1);
		x=act*(pow10(CantDig))+x;
	}
}

void __fastcall TForm1::N13Click(TObject *Sender)
{
	Word n=StringGrid1->ColCount;
	Cardinal x;
	GenerarNumero(StringGrid1,n,x);
	//ShowMessage(x);
	Edit2->Text=(x);
}
//---------------------------------------------------------------------------

//Carga Randomicamente

void Cargar(TStringGrid *v,byte n)
{ if (n>0){  //caso general
	 Cargar(v,n-1);
	 v->Cells[n-1][0]=Random(20);
  }
}

void __fastcall TForm1::N31Click(TObject *Sender)
{
   StringGrid1->ColCount=StrToInt(Edit1->Text);
	Cargar(StringGrid1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

// Edit1(123456) --> v[1, 2, 3, 4, 5, 6]
void modex2(TStringGrid *v,int &n)  //dig de n en vector
{   v->ColCount =0;
	if (n>0){
	byte dig=n % 10;
	n=n / 10;
	modex2(v,n);
	v->Cells [v->ColCount -1][0]=StrToInt(dig);
	v->ColCount ++;
	}
}

void __fastcall TForm1::N32Click(TObject *Sender)
{
   int n=StrToInt(Edit1->Text);
	  modex2(StringGrid1,n);
	  StringGrid1->ColCount --;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	  /*****Redimencionar*****/

	  //StringGrid1->ColCount = Edit1->Text.ToInt();
	  /*Vectores*/
	  StringGrid1->ColCount = StrToInt(Edit1->Text);
	  StringGrid1->RowCount = 1;
}
//---------------------------------------------------------------------------

// De vector acumular en una Cadena  con cada inicial de las palabrasdel vector
//ej: V[hola/que/haces] --> ShowMessage = hqh

String modex6(TStringGrid *v,byte i){
String s;
	if (i<=v->ColCount-1 ) {
		String x=v->Cells [i][0];
		s=String(x[1])+ modex6(v,i+1); }
	else s="";
	return s;
}

void __fastcall TForm1::N51Click(TObject *Sender)
{
   //ShowMessage(modex6(StringGrid1,0));
   Edit1->Text=modex6(StringGrid1,0);
}
//---------------------------------------------------------------------------

// poner digitos al vector y mostrar en la cadena PRIMOS
// ej: v[1, 2, 3, 4, 5] --> Cadena(Edit) = 1235

int digitosPrimos(int n){
	int np=0;
	if (n>0) {
		byte d=n%10;
		np=digitosPrimos(n/10);
		if (d==1 || d==2 || d==3|| d==5 ||d==7) {
			np=np*10+d;
		}
	}
	return np;
}
int nroDigPrimos(TStringGrid *v,int n){
	int x=0;
	if (n>0) {
		int d=v->Cells[n-1][0].ToInt();
		x=nroDigPrimos(v,n-1);
		int dp=digitosPrimos(d);
		if (dp>0) {
			x=x*pow(10,(int)log10(dp)+1)+dp;
		}
	}
	return x;
}


void __fastcall TForm1::N52Click(TObject *Sender)
{
   int n=StringGrid1->ColCount;
	int nprimo=nroDigPrimos(StringGrid1,n);
	Edit2->Text=IntToStr(nprimo);
}
//---------------------------------------------------------------------------

//Escribis palabras en un Edit y muestra en el Vector

////funciona asi, dimencionar en 1 y luego en el edit (hola como)--> V[hola , como]

void LoadVec(TStringGrid *vectorcito,String cad){
cad=cad.Trim();
int x;
int L=cad.Length();
	if (L>0) {
	int p=cad.LastDelimiter(' ');
	String ultpal=cad.SubString(p+1,L-p);
	cad.Delete(p+1,L-p);
	LoadVec(vectorcito,cad);
	x=vectorcito->ColCount;
	vectorcito->Cells[x-1][0]=ultpal;
	vectorcito->ColCount++;
	}
}

void __fastcall TForm1::N71Click(TObject *Sender)
{
	String cad=Edit3->Text;
	LoadVec(StringGrid1,cad);
	StringGrid1->ColCount--;  //  SGVector->ColCount=SGVector->ColCount-1
}
//---------------------------------------------------------------------------

//Escribis palabras en un Edit y muestra en el Vector 2

//lo mismo de arriba pero repite dos beses

void CargarPal(TStringGrid *V,String cad){
cad=cad.Trim();
int x;
int L=cad.Length();
	if (L>0) {
	int p=cad.LastDelimiter(' ');
	String ultpal=cad.SubString(p+1,L-p);
	cad.Delete(p+1,L-p);
	CargarPal(V,cad);
	x=V->ColCount;
	V->Cells[x-1][0]=ultpal;
	V->ColCount++;
	}
}

void __fastcall TForm1::N72Click(TObject *Sender)
{
	String cad=Edit3->Text;
	CargarPal(StringGrid1 ,cad);
	CargarPal(StringGrid1,cad);
	StringGrid1->ColCount--;
}
//---------------------------------------------------------------------------

//cadena al vector
//funciona asi, dimencionar en 1 y luego en el edit (1 2 3 )--> V[1 , 2, 3]

void CargarString(TStringGrid *V,String cad){
cad=cad.Trim();
int x;
int L=cad.Length();
	if (L>0) {
	int p=cad.LastDelimiter(' ');
	String ultpal=cad.SubString(p+1,L-p);
	cad.Delete(p+1,L-p);
	CargarString(V,cad);
	char c = ultpal[1];
	ultpal.Delete(1,1);
	ultpal=  String(UpperCase(c))+ultpal;

	x=V->ColCount;
	V->Cells[x-1][0]=ultpal;
	V->ColCount++;
	}
}

void __fastcall TForm1::N91Click(TObject *Sender)
{
	String cad=Edit3->Text;
	CargarString(StringGrid1,cad);
	StringGrid1->ColCount--;
}
//---------------------------------------------------------------------------

/*Escribir una funci�n que devuelva true si un vector contiene �nicamente cadenas pal�ndromas. Una cadena es pal�ndroma si se leen igual de izquierda a derecha como de derecha a izquierda .(20 Ptos)
	Ej.1 v["oso", "oruro", "reconocer", "arenera"] ==>  true
	Ej2. v["rotor", "aibofobia","sala",�"ala"]�==>false*/

void InvertirCad(String &Cad){
byte L=Cad.Length();
 if ((L<=1)||(Cad=="")){
    Cad=Cad;
 }else {
         String c=Cad.SubString(1,2);
         Cad.Delete(1,2);
         InvertirCad(Cad);
         Cad=Cad+c[2]+c[1];
       }
}
bool Pal�ndromas(TStringGrid *Vec,byte Dim){
Boolean B=true;
 if (Dim>=1) {
 B=Pal�ndromas(Vec,Dim-1);
  String C1=Vec->Cells[Dim-1][0];
  String C2=Vec->Cells[Dim-1][0];
  InvertirCad(C2);
   if (C1!=C2){
   B=false;
   }
 }
 return B;
}


void __fastcall TForm1::N92Click(TObject *Sender)
{
    Boolean B=Pal�ndromas(StringGrid1,StringGrid1->ColCount);
	 if (B==true){
		Edit1->Text="true";
	 }else Edit1->Text="false";
}
//---------------------------------------------------------------------------

//ej: v[1, 2, 3, 4, 5] --> Edit3 = 5 => Edit = 15

int sumarV(TStringGrid *v,Byte n){
int s;
	if (n==0){ //caso base
		s=0;
	}else{//caso general
		s=sumarV(v,n-1);
		s=s+StrToInt(v->Cells[n-1][0]);
	}
	return s;
}

void __fastcall TForm1::Seguimos2Click(TObject *Sender)
{
	Edit2->Text=sumarV(StringGrid1,StrToInt(Edit3->Text));
}
//---------------------------------------------------------------------------

//cantidad de numeros pares del vector
// ej: v[1, 2, 3, 4, 5] --> 2
byte cantPar(TStringGrid *v,byte n){
	byte c;
	if (n==0)
		c=0;
	else{
		byte d=StrToInt(v->Cells[n-1][0]);
		c=cantPar(v,n-1);
		if (d%2==0)
			c++;
	}
	return c;
}

void __fastcall TForm1::N121Click(TObject *Sender)
{
		byte n=StringGrid1->ColCount;
		Edit3->Text=StrToInt(cantPar(StringGrid1,n));
}
//---------------------------------------------------------------------------

//eliminar un numero ej: v[1, 2, 2, 3, 4 ] --> v[1, 3, 4]

void Recorrer(TStringGrid *v,byte a,byte b){
	byte n=b-a+1;
	if (n>0){
		v->Cells[a][0]= v->Cells[a+1][0];
		Recorrer(v,a+1,b);
	}
}

void EliminarX(TStringGrid *v,byte a,byte b,byte x){
	byte n=b-a+1;
	if (n>0){
		byte d=StrToInt(v->Cells[a][0]);
		EliminarX(v,a+1,b,x);
		if (d==x){
			Recorrer(v,a,b);
			v->ColCount --;
		}
	}
}

void __fastcall TForm1::N122Click(TObject *Sender)
{
	byte b=StringGrid1->ColCount-1;
	EliminarX(StringGrid1,0,b,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

//invertir un vector
// ej: v[1, 2, 3, 4, 5] edit1(1), edit2(3) --> v[1, 4, 3, 2, 5]
void invertir(TStringGrid *v,byte a,byte b){
	byte n=b-a+1;
	if (n>0) {
		if ((a!=b)&&(a<b)){
			invertir(v,a+1,b-1);
			String aux=v->Cells[a][0];
			v->Cells[a][0]=v->Cells[b][0];
			v->Cells[b][0]=aux;
		}
	}
}

void __fastcall TForm1::N141Click(TObject *Sender)
{
	byte a=(StrToInt(Edit1->Text));
   byte b=(StrToInt(Edit2->Text));
   invertir(StringGrid1,a,b);
}
//---------------------------------------------------------------------------


//insertar x en una posicion , Primero dimencionar luego escribir en el vector
// v = [65515]   x=9 p=2
// v = [65 9515]
void anadir(TStringGrid *v,byte p,byte nu){
if (nu>p) {
  v->Cells[nu][0]=v->Cells[nu-1][0];
  anadir(v,p,nu-1);
}

}
void insertarx(TStringGrid *v,byte n,byte x,byte p,byte nu){
  if (n>0) {
	   if (n-1==p) {
				anadir(v,p,nu);
				v->Cells[p][0]=StrToInt(x);
	   }
	   insertarx(v,n-1,x,p,nu);
  }

}

void __fastcall TForm1::N142Click(TObject *Sender)
{
	byte n=StrToInt(Edit1->Text);
  byte x=StrToInt(Edit2->Text);
  byte p=StrToInt(Edit3->Text);
  insertarx(StringGrid1,n,x,p,n);
   //	anadir(StringGrid1,n,x);
}
//---------------------------------------------------------------------------

//Medio raro, veferificar

//cargar serie
//7 12 20 31 45
//0 5  8  11 14
byte serie(byte n,byte &k){
byte s;
   if (n==1) {
	   s=7;
   }else{
	   s=serie(n-1,k);
	   k=k+3;
	   s=s+k;
   }
   return s;
}
void cargarVEC(TStringGrid *v,byte n){
byte k=2;
   if (n>0) {
		  cargarVEC(v,n-1);
		  byte d=serie(n,k);
		  v->Cells[n-1][0]=d;
   }
}

void __fastcall TForm1::N161Click(TObject *Sender)
{
   cargarVEC(StringGrid1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

//VERIFICAR

// 125450
// 12545 0
// 1254 0 5
 void burbojear(TStringGrid *v,byte n){
 if (n>1){ //caso general
	int m=StrToInt(v->Cells[n-1][0]);
	burbojear(v,n-1);
	if (m < (StrToInt(v->Cells[n-2][0])) ){
				String aux=v->Cells[n-1][0];
				v->Cells[n-1][0]=v->Cells[n-2][0];
				v->Cells[n-2][0]=aux;
	}
 }
 }


//dado 2 vectores ordenarlos en otro vector
void unir2VEc(TStringGrid *v,TStringGrid *v3,byte n,byte &n3){
 if (n>0) {
		unir2VEc(v,v3,n-1,n3);
		n3++;
		v3->Cells[n3-1][0]=v->Cells[n-1][0];
 }
}
void ordenar2VEC(TStringGrid *v3,byte n){
  if (n>1) {
	   burbojear(v3,n);
	   ordenar2VEC(v3,n-1);
  }
}


void __fastcall TForm1::N162Click(TObject *Sender)
{
	/*burbojear(StringGrid1,StrToInt(Edit1->Text));*/

	/*byte n3=0;
	unir2VEc(StringGrid1,StringGrid3,(StrToInt(Edit1->Text)),n3);
	unir2VEc(StringGrid2,StringGrid3,(StrToInt(Edit2->Text)),n3);
	StringGrid3->ColCount=n3;
	ordenar(StringGrid3,StringGrid3->ColCount); */
}
//---------------------------------------------------------------------------

//colocar una cadena en vectores
// ej: Edit1(Hola)  V[h, o, l, a]

//Tambien funciona como cadena a vector invertida, si quito los comentarios

bool verifVOl(char x){
	String z="aeiouAEIOU";
	return z.Pos(x)>0;
}

void eliminarvocal(String &s){
	if (s=="") {
		s=s ;
	}else{
		byte p=s.Length();
		char z=s[p];
		s.Delete(p,1);
		eliminarvocal(s);
		if (verifVOl(z)==false) {
			s=s+z;
		}
	}
}

/*void InvertirString(String &x){  //como funcion
	byte l=x.Length();
	String s;
	if (l<2) {
		s=x;
	}else{
		char z=x[1];
		x.Delete(1,1);
		InvertirString(x);
		x=x+z;
	}
}*/

bool veriflet(char x){
	String z="qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
	return z.Pos(x)>0;
}

void insertarcad(TStringGrid *v,String &s,byte n,byte t,byte r){
if (t >= n){
		   char z=s[1];
		   if (veriflet(z)==true) {
				v->Cells[r][0]=z;
				r++;
		   }
		   s.Delete(1,1);
		   insertarcad(v,s,n+1,t,r);
}
}

void __fastcall TForm1::N181Click(TObject *Sender)
{
	String s=Edit1->Text;
	//InvertirString(s);
	StringGrid1->ColCount=s.Length();
	insertarcad(StringGrid1,s,1,s.Length(),0);
}
//---------------------------------------------------------------------------

//No entiendo como funciona

void invertir(int &n){
 if (n>0){
   byte d=n%10;
   n=n/10;
   invertir(n);
   n=n*10+d ;
}
}

void  insertvec(TStringGrid *v,byte n,int k){
	 if (k!=0) {
			byte d=k%100;
			k=k/100;
			v->Cells[n][0]=d;
			insertvec(v,n+1,k);
	 }
}

void __fastcall TForm1::N182Click(TObject *Sender)
{
   int k=StrToInt(Edit1->Text);//numero
   insertvec(StringGrid1,0,k);
	invertir(k);
	Edit2->Text=StrToInt(k);
}
//---------------------------------------------------------------------------

//Cadena a Vector, ej: edit(Hola) == v[h, o, l, a]


void cadavec(TStringGrid *v,byte n,AnsiString x){
byte c=x.Length();
if (x>0) {
	  char z=x[c];
	  x.Delete(c,1);
	  cadavec(v,n,x);
	  v->Cells[c-1][0]=z;
}
}

void __fastcall TForm1::N201Click(TObject *Sender)
{
    AnsiString m=Edit1->Text;
	byte c=m.Length();
	cadavec(StringGrid1,c,m);
	StringGrid1->ColCount=m.Length();
}
//---------------------------------------------------------------------------

//eliminar un numero
//V[5265] --> Edit1(5)
//v[264]

void recorrer(TStringGrid *v,byte a,byte b){
	byte n=b-a+1;
	if (n>0){
		v->Cells[a][0]= v->Cells[a+1][0];
		recorrer(v,a+1,b);
	}
}

void eliminarX(TStringGrid *v,byte a,byte b,byte x){
	byte n=b-a+1;
	if (n>0){
		byte d=StrToInt(v->Cells[a][0]);
		eliminarX(v,a+1,b,x);
		if (d==x){
			recorrer(v,a,b);
			v->ColCount --;
		}
	}
}

void __fastcall TForm1::Seguimos4Click(TObject *Sender)
{
	//Funcion Auxiliar
	/*Recorrer(StringGrid1,StrToInt(Edit1->Text),StrToInt(Edit2->Text));*/

	 byte b=StringGrid1->ColCount-1;
	 eliminarX(StringGrid1,0,b,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

//Cuenta la cantidad de digitos que se repiten en el vector
//ej: v[1, 2, 2] edit1(2) --> se repite 2 vecces

byte cantidad(TStringGrid *v,byte a,byte b,byte d){
 byte n=b-a+1;
 byte c;
 if (n==0) {
	 c=0;
 }else{
	 byte k=StrToInt(v->Cells [a][0]);
	 c=cantidad(v,a+1,b,d);
	 if (k==d) {
		 c++;
	 }
 }
 return c;
}

void __fastcall TForm1::N221Click(TObject *Sender)
{
	Edit3->Text=StrToInt(cantidad(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(Edit1->Text)));
}
//---------------------------------------------------------------------------

//Elimina un dig del vector dependiendo de la posicon donde se encuentre y recorre
//ej: v[1, 2, 3, 4, 5] --> edit1(2) => v[1, 2, 4, 5]

void RRecorrer(TStringGrid *v,byte a,byte b){
byte n=b-a+1;
if (n>0) {
	v->Cells [a][0]=v->Cells [a+1][0];
	recorrer(v,a+1,b);
}
}

void __fastcall TForm1::N222Click(TObject *Sender)
{
	RRecorrer(StringGrid1,StrToInt(Edit1->Text),StringGrid1->ColCount-1);
	StringGrid1->ColCount--;
}
//---------------------------------------------------------------------------

//A�ade un dig en el vector dependiendo la posicion
// v[1, 2, 3, 4] --> Edit1(0), Edit2(4) => v[4, 1, 2, 3, 4]

void anadir(TStringGrid *v,byte a,int b,byte d){
	byte n=b-a+1;
	if (n>0) {
		v->Cells [b+1][0]=v->Cells [b][0];
		anadir(v,a,b-1,d);
		if (b==a) {
			v->Cells [a][0]=d;
		}
	}
}

void __fastcall TForm1::N241Click(TObject *Sender)
{
	anadir(StringGrid1 ,StrToInt(Edit1->Text),StringGrid1->ColCount-1,StrToInt(Edit2->Text));
	StringGrid1->ColCount++;
}
//---------------------------------------------------------------------------

//Vector a Cadena
//Muestra las iniciales de cada palabra del vector a una cadena
//ej: v(hola, como estan)  edit3(hce)

String pasarPLDVaC(TStringGrid *v,byte a,int b){
	String s;
	if (a>b)
		s="" ;
	else{
		String x=v->Cells [b][0];
		char z=x[1];
		s=pasarPLDVaC(v,a,b-1);
		s=s+z;
	}
	return s;
}

void __fastcall TForm1::N242Click(TObject *Sender)
{
	if (StringGrid1->Cells [0][0]!=""){
		Edit3->Text=pasarPLDVaC(StringGrid1,0,StringGrid1->ColCount-1);
	}else{
		Edit3->Text="";
	}
}
//---------------------------------------------------------------------------

//No invierte los digitos en la cadena

String invertirS(String s){
String x;
if (s=="") {
		x=s;
}else{
	char z=s[1];
	s.Delete(1,1);
	x=invertirS(s);
	x=x+z;
	}
	return x;
}
String deVecaNum(TStringGrid *v,byte a,int b){
String s;
	if (a==b){
		s=invertirS(v->Cells [b][0]);
	}else{
		String z=invertirS(v->Cells [b][0]);
		s=deVecaNum(v,a,b-1);
		s=s+z;
	}
	return s;
}

void __fastcall TForm1::N261Click(TObject *Sender)
{
  Edit2->Text=(deVecaNum(StringGrid1,0,StringGrid1->ColCount-1));
}
//---------------------------------------------------------------------------

// Algoritmo que devuelve la suma de los elementos de un vector
// Ejemplo: v[1,2,3,4,5] ==> 15
Cardinal Suma(TStringGrid *v, Word n) {
	Cardinal suma;
	if (n == 0) {
		suma = 0;
	} else {
		suma = Suma(v, n - 1);
		suma = suma + StrToInt(v->Cells[n - 1][0]);
    }
	return suma;
}

void __fastcall TForm1::N262Click(TObject *Sender)
{
	Word n = StringGrid1->ColCount;
	Edit1->Text = Suma(StringGrid1, n);
}
//---------------------------------------------------------------------------

// Algoritmo que devuelve la suma de los elementos pares de un vector
// Ejemplo: v[1,2,3,4,5] ==> 6
Cardinal SumaPares(TStringGrid *v, Word n){
	Cardinal suma;
	if (n == 0) {
		suma = 0;
	} else if (n == 1) {
		byte num = StrToInt(v->Cells[0][0]);
		if (num % 2 == 0) {
			suma = num;
		} else {
			suma = 0;
        }
	} else {
		suma = SumaPares(v, n - 1);
		byte ult = StrToInt(v->Cells[n - 1][0]);
		if (ult % 2 == 0) {
			suma = suma + ult;
		}
    }
	return suma;
}

// Algoritmo que devuelve la suma de los elementos impares de un vector
// Ejemplo: v[1,2,3,4,5] ==> 9
Cardinal SumaImpares(TStringGrid *v, Word n) {
	Cardinal suma;
	if (n == 0) {
		suma = 0;
	} else if (n == 1) {
		suma = StrToInt(v->Cells[0][0]);
		if (suma % 2 == 0) {
			suma = 0;
		}
	} else {
		suma = SumaImpares(v, n - 1);
		byte ult = StrToInt(v->Cells[n - 1][0]);
		if (ult % 2 != 0) {
			suma = suma + ult;
        }
    }
	return suma;
}

void __fastcall TForm1::N281Click(TObject *Sender)
{
	//	Word n = StrToInt(Edit8->Text);
	//	Edit9->Text = SumaPares(Vector1, n);
	Word n = StrToInt(Edit1->Text);
	Edit2->Text = SumaImpares(StringGrid1, n);
}
//---------------------------------------------------------------------------

// Algoritmo que verifica si un elemento esta en el vector
// Ejemplo: v[2, 21, 34, 55, 8]; x = 34 ==> true
bool ExisteElemento(TStringGrid *v, Word a, Word b, Word elemento) {
	bool result;
	Word n = b - a + 1;
	if (n == 0) {
		result = false;
	} else if (n == 1) {
		Word num = StrToInt(v->Cells[a][0]);
		if (num == elemento) {
			result = true;
		} else {
			result = false;
        }
	} else {
		result = ExisteElemento(v, a, b - 1,elemento);
		Word ult = StrToInt(v->Cells[b - 1][0]);
		if (ult == elemento) {
			result = true;
        }
    }
	return result;
}

void __fastcall TForm1::N291Click(TObject *Sender)
{
	Word a = StrToInt(Edit1->Text);
	Word b = StrToInt(Edit2->Text);
	Word elemento = StrToInt(Edit3->Text);
	bool result = ExisteElemento(StringGrid1, a, b, elemento);
	if (result) {
		ShowMessage("SI est� en el vector");
	} else {
		ShowMessage("NO est� en el vector");
	}
}
//---------------------------------------------------------------------------

// Algoritmo que devuelve un vector cargado con las vocales de
// cada palabra de una cadena
// Ejemplo: x = "Buenos dias a todos" ==> v[ueo, ia, a, oo,]
AnsiString Vocales(AnsiString cadena) {
	AnsiString vocales;
	AnsiString alf = "aeiouAEIOU������������";
	if (cadena.IsEmpty()) {
		vocales = "";
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		byte pos = alf.Pos(z);
		vocales = Vocales(cadena);
		if (pos > 0) {
			vocales = AnsiString(z) + vocales;
        }
    }
	return vocales;
}
void CargarVocales(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		AnsiString vocales = Vocales(palabra);
		if (!vocales.IsEmpty()) {
			byte n = v->ColCount;
			v->Cells[n - 1][0] = vocales;
			v->ColCount++;
		}
		CargarVocales(v, cadena);
	}
}
void CargarVocales_2(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		cadena = cadena.Trim();
		byte len = cadena.Length();
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, len - pos);
		cadena.SetLength(pos - 1);
		AnsiString vocales = Vocales(palabra);
		CargarVocales_2(v, cadena);
		if (!vocales.IsEmpty()) {
			byte n = v->ColCount;
			v->Cells[n - 1][0] = vocales;
			v->ColCount++;
		}
	}
}

void __fastcall TForm1::N292Click(TObject *Sender)
{
	StringGrid1->ColCount = 1;
	AnsiString cadena = Edit1->Text;
	CargarVocales(StringGrid1, cadena);
//	CargarVocales_2(Vector2, cadena);
}
//---------------------------------------------------------------------------

// Algoritmo que devuelve una cadena con el ultimo caracter de cada palabra del vector
// Ejemplo: v[hola,como,estas,hoy,dia] ==> aosya
AnsiString UltimasLetras(TStringGrid *v, Word n) {
	AnsiString resultado;
	AnsiString palabra;
	byte len;
	if (n == 0) {
		resultado = "";
	} else if (n == 1) {
		palabra = v->Cells[0][0];
		palabra = palabra.Trim();
		if (palabra != "" && palabra != " ") {
			len = palabra.Length();
			resultado = palabra[len];
		}
	} else {
		palabra = v->Cells[n - 1][0];
		palabra = palabra.Trim();
		if (palabra != "" && palabra != " ") {
			len = palabra.Length();
			resultado = UltimasLetras(v, n - 1);
			resultado = resultado + palabra[len];
		} else {
			resultado = resultado + UltimasLetras(v, n - 1);
        }
	}
	return resultado;
}

void __fastcall TForm1::Seguimos6Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	Edit2->Text = UltimasLetras(StringGrid1, n);
}
//---------------------------------------------------------------------------

/* Algoritmo que carga un vector con las palabrs de una cadena
   donde la primera letra de cada palabra este en Mayuscula */
// Ejemplo: x = "buenos dias a todos" => v[Buenos, Dias, A, Todos]
AnsiString LetraMayuscula(AnsiString cadena) {
	AnsiString palabra;
	if (cadena.IsEmpty()) {
		palabra = "";
	} else {
		char z = toupper(cadena[1]);
		cadena.Delete(1, 1);
		palabra = LetraMayuscula(cadena);
		palabra = AnsiString(z) + cadena;
	}
	return palabra;
}
void CargarPalabras(TStringGrid *v, AnsiString cadena) {
	if(cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		AnsiString newPalabra = LetraMayuscula(palabra);
		byte n = v->ColCount;
		v->Cells[n - 1][0] = newPalabra;
		v->ColCount++;
		CargarPalabras(v, cadena);
	}
}

void __fastcall TForm1::N321Click(TObject *Sender)
{
	StringGrid1->ColCount = 1;
	AnsiString cadena = Edit1->Text;
	CargarPalabras(StringGrid1, cadena);
	//Edit9->Text = LetraMayuscula(cadena);
}
//---------------------------------------------------------------------------

// Algoritmo para cargar un vector con las palabras de una cadena
// Ejemplo: x = "Hola a todos" ==> v[Hola, a, todos]
void CargarPalabra(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		CargarPalabra(v, cadena);
		byte n = v->ColCount;
		v->Cells[n - 1][0] = palabra;
		v->ColCount++;
    }
}

void __fastcall TForm1::N322Click(TObject *Sender)
{
	StringGrid1->ColCount = 1;
	AnsiString cadena = Edit1->Text;
	CargarPalabra(StringGrid1, cadena);
}
//---------------------------------------------------------------------------

/* Algoritmo que devuelve una cadena con las primeras letras
   de las palabras de un vector */
// Ejemplo: v[Feliz, navidad, a, todos] ==> Fnat
AnsiString PrimerasLetras(TStringGrid *v, Word n) {
	AnsiString cad;
	if (n == 0) {
		cad = "";
	} else {
		AnsiString palabra = v->Cells[n - 1][0];
		palabra = palabra.Trim();
		if (palabra !="" && palabra != " ") {
			cad = PrimerasLetras(v, n - 1);
			cad = cad + palabra[1];
		} else {
			cad = PrimerasLetras(v, n - 1);
        }
    }
	return cad;
}

void __fastcall TForm1::N341Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	Edit2->Text = PrimerasLetras(StringGrid1, n);
}
//---------------------------------------------------------------------------

// Algoritmo que carga un vector con las vocales de una cadena
// Ejemplo: x = "hola mundo genial" ==> v[o, a, u, o, e, i, a]
void Cargar_Vocales(TStringGrid *v, AnsiString cadena) {
	AnsiString vocales = "aeiouAEIOU������������";
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		if (vocales.Pos(z) > 0) {
			byte n = v->ColCount;
			v->Cells[n - 1][0] = AnsiString(z);
			v->ColCount++;
		}
		Cargar_Vocales(v, cadena);
	}
}

void __fastcall TForm1::N342Click(TObject *Sender)
{
	StringGrid1->ColCount = 1;
	AnsiString cadena = Edit1->Text;
	Cargar_Vocales(StringGrid1, cadena);
}
//---------------------------------------------------------------------------

/* Algoritmo que carga un vector con palabras invertidas de una
   cadena letra por letra */
// Ejemplo: x = "Hola mundo" ==> v[o, d, n, u, , m, a, l, o, H]
void CargarCadenaInvertida(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		byte len = cadena.Length();
		char z = cadena[len];
		cadena.SetLength(len - 1);
		byte n = v->ColCount;
		v->Cells[n - 1][0] = AnsiString(z);
		v->ColCount++;
		CargarCadenaInvertida(v, cadena);
	}
}
//

void __fastcall TForm1::N351Click(TObject *Sender)
{
	StringGrid1->ColCount = 1;
	AnsiString cadena = Edit1->Text;
	CargarCadenaInvertida(StringGrid1, cadena);
}
//---------------------------------------------------------------------------

// Algoritmo que carga las palabras de una cadena sin vocales
// Ejemplo: x = "el mundo es grande" ==> v[l, mnd, s, grnd]
AnsiString SinVocales(AnsiString cadena) {
	AnsiString palabra;
	AnsiString vocales = "aeiouAEIOU������������";
	if (cadena.IsEmpty()) {
		palabra = "";
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		palabra = SinVocales(cadena);
		if (vocales.Pos(z) == 0) {
			palabra = AnsiString(z) + palabra;
        }
    }
	return palabra;
}
void CargarSinVocales(TStringGrid *v, AnsiString cadena) {
	if (cadena.IsEmpty()) {
		v->ColCount--;
	} else {
		cadena = cadena.Trim();
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		AnsiString newPalabra = SinVocales(palabra);
		if (newPalabra != "") {
			byte n = v->ColCount;
			v->Cells[n - 1][0] = newPalabra;
			v->ColCount++;
		}
		CargarSinVocales(v, cadena);
    }
}

void __fastcall TForm1::N371Click(TObject *Sender)
{
	StringGrid1->ColCount = 1;
	AnsiString cadena = Edit1->Text;
	CargarSinVocales(StringGrid1, cadena);
}
//---------------------------------------------------------------------------

// Algoritmo que devuelve un numero con los elementos de un vector
// Ejemplo: v[10, 2, 30, 65, 9] ==> 96530210
void GenerarNumeros(TStringGrid *v, Word n, unsigned long long &num) {
	byte cantidad;
	if (n == 0) {
		throw new Exception("Error: Vector vacio");
	} else if (n == 1) {
		num = StrToInt(v->Cells[0][0]);
	} else {
		GenerarNumeros(v, n - 1, num);
		Cardinal numero = StrToInt(v->Cells[n - 1][0]);
		cantidad = String(num).Length();
		num = numero * pow(10, cantidad) + num;
	}
}

void __fastcall TForm1::N372Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	unsigned long long num = 0;
	GenerarNumeros(StringGrid1, n, num);
	Edit2->Text = num;
}
//---------------------------------------------------------------------------

// Algoritmo que ordena un vector en orden ascendente
// Ejemplo: v[95, 21,67, 3, 78] ==> v[3, 21, 67, 78, 95]
void MayorAlFinal(TStringGrid *v, Word n) {
	if (n > 1) {
		MayorAlFinal(v, n - 1);
		String x = v->Cells[n - 1][0];
		String y = v->Cells[n - 2][0];
		if (StrToInt(x) < StrToInt(y)) {
			v->Cells[n - 1][0] = v->Cells[n - 2][0];
			v->Cells[n - 2][0] = x;
		}
	}
}
void OrdenarAsc(TStringGrid *v, Word n) {
	if (n > 1) {
		MayorAlFinal(v, n);
		OrdenarAsc(v, n - 1);
	}
}

void __fastcall TForm1::N391Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	OrdenarAsc(StringGrid1, n);
}
//---------------------------------------------------------------------------

// Algoritmo que ordena un vector en orden Descendente
// Ejemplo: v[95, 21,67, 3, 78] ==> v[5, 78, 67, 21, 3]
void MayorAlInicio(TStringGrid *v, Word n) {
	if (n > 1) {
		MayorAlInicio(v, n - 1);
		String x = v->Cells[n - 1][0];
		String y = v->Cells[n - 2][0];
		if (StrToInt(x) > StrToInt(y)) {
			v->Cells[n - 1][0] = v->Cells[n - 2][0];
			v->Cells[n - 2][0] = x;
		}
	}
}
void OrdenarDesc(TStringGrid *v, Word n) {
	if (n > 1) {
		MayorAlInicio(v, n);
		OrdenarDesc(v, n - 1);
	}
}

void __fastcall TForm1::N392Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	OrdenarDesc(StringGrid1, n);
}
//---------------------------------------------------------------------------

// Ordenar un vector en forma Ascendente en un segmento (a, b)
// Ejemplo: v[10, 2, 45, 31, 7, 18]   a = 2, b = 5
//          v[10, 2, 7, 31, 45, 18]
void MayorAlFinalSeg(TStringGrid *v, Word a, Word b) {
	Word n = b - a + 1;
	if (n > 1) {
		MayorAlFinalSeg(v, a, b - 1);
		String x = v->Cells[b - 1][0];
		String y = v->Cells[b - 2][0];
		if (StrToInt(x) < StrToInt(y)) {
		   v->Cells[b - 1][0] = v->Cells[b - 2][0];
		   v->Cells[b - 2][0] = x;
        }
    }
}
void OrdenarSegmentoAsc(TStringGrid *v, Word a, Word b) {
 	Word n = b - a + 1;
	if (n > 1) {
		MayorAlFinalSeg(v, a, b);
		OrdenarSegmentoAsc(v, a, b - 1);
    }
}

void __fastcall TForm1::N411Click(TObject *Sender)
{
		Word a = StrToInt(Edit1->Text);
		Word b = StrToInt(Edit2->Text);
		OrdenarSegmentoAsc(StringGrid1, a, b);
}
//---------------------------------------------------------------------------

// Algoitmo que invierte un vector en segmento (a, b)
// Ejemplo: v[1, 2, 3, 4, 5, 6] ==> v[1, 5, 4, 3, 2, 6]
void InvertirSegmento(TStringGrid *v, Word a, Word b) {
	byte n = b - a + 1;
	if (n > 1) {
		InvertirSegmento(v, a + 1, b - 1);
		String x = v->Cells[b - 1][0];
		v->Cells[b - 1][0] = v->Cells[a - 1][0];
		v->Cells[a - 1][0] = x;
    }
}

void __fastcall TForm1::N412Click(TObject *Sender)
{
		Word a = StrToInt(Edit1->Text);
		Word b = StrToInt(Edit2->Text);
		InvertirSegmento(StringGrid1, a, b);
}
//---------------------------------------------------------------------------

// Algoritmo que elimina un elemento de un vector
// Ejemplo: v[1, 2, 3, 4, 5] x = 2  ==> v[1, 3, 4, 5]
void Eliminar(TStringGrid* v, Cardinal pos) {
	if (pos < v->ColCount) {
		v->Cells[pos][0] = v->Cells[pos + 1][0];
		Eliminar(v, pos + 1);
	}
}
void EliminarElemento(TStringGrid *v, Word n, Word elemento) {
	if (n >= 1) {
		Word num = StrToInt(v->Cells[n - 1][0]);
		if (num == elemento) {
			Eliminar(v, n - 1);
			v->ColCount--;
			EliminarElemento(v, n - 1, elemento);
		} else {
			EliminarElemento(v, n - 1, elemento);
		}
	}
}

void __fastcall TForm1::N431Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	Word elemento = StrToInt(Edit2->Text);
	EliminarElemento(StringGrid1, n, elemento);
}
//---------------------------------------------------------------------------

// Algoritmo que elimina los elementos de un segmento del vector
// Ejemplo: v[1, 2, 3, 4, 5] a = 2, b = 4  ==> v[1, 5]
void EliminarElementos(TStringGrid *v, byte a, byte b){
	byte n = b - a + 1;
	if (n >= 1) {
		if (b > b - 1) {
			Eliminar(v, b - 1);
			v->ColCount--;
		}
		EliminarElementos(v, a, b - 1);
	}
}

void __fastcall TForm1::N432Click(TObject *Sender)
{
	byte a = StrToInt(Edit1->Text);
	byte b = StrToInt(Edit2->Text);
	EliminarElementos(StringGrid1, a, b);
}
//---------------------------------------------------------------------------

byte CantidadVocales(AnsiString cadena) {
	AnsiString vocales = "aeiouAEIOU������������";
	byte cantidad;
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		cantidad = CantidadVocales(cadena);
		if (vocales.Pos(z) > 0) {
			cantidad++;
		}
	}
	return cantidad;
}
Cardinal Cantidad_Vocales(TStringGrid *v, Word n) {
	Cardinal cantidad = 0;
	if (n == 0) {
		cantidad = 0;
	} else {
		AnsiString palabra = v->Cells[n - 1][0];
		byte num = CantidadVocales(palabra);
		cantidad = Cantidad_Vocales(v, n - 1);
		cantidad = cantidad + num;
	}
	return cantidad;
}

void __fastcall TForm1::N451Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	Edit2->Text = Cantidad_Vocales(StringGrid1, n);
}
//---------------------------------------------------------------------------

byte CantidadPrimos(Cardinal x) {
	String primos = "12357";
	byte cantidad = 0;
	if (x < 10) {
		if (primos.Pos(String(x)) > 0) {
			cantidad = 1;
		}
	} else {
		byte dig = x % 10;
		cantidad = CantidadPrimos(x / 10);
		if (primos.Pos(String(dig)) > 0) {
			cantidad++;
		}
	}
	return cantidad;
}
Cardinal Cantidad_Primos(TStringGrid *v, Word n) {
	Cardinal cantidad;
	if (n == 0) {
		cantidad = 0;
	} else {
		Cardinal numero = StrToInt(v->Cells[n - 1][0]);
		byte num = CantidadPrimos(numero);
		cantidad = Cantidad_Primos(v, n - 1);
		cantidad = cantidad + num;
	}
	return cantidad;
}

void __fastcall TForm1::N452Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	Edit2->Text = Cantidad_Primos(StringGrid1, n);
}
//---------------------------------------------------------------------------

byte SumaParesIterativo(TStringGrid *v, Word n) {
	byte suma, i, col;
	suma = 0, i = 0, col = n - 1;
	while (i < n) {
		if (StrToInt(v->Cells[col][0]) % 2 == 0) {
			suma = suma + StrToInt(v->Cells[col][0]);
		}
		col--;
		i++;
	}
	return suma;
}

byte SumaParesRecursivo(TStringGrid *v, Word n) {
	byte suma;
	if (n == 0) {
		suma = 0;
	} else {
		byte num = StrToInt(v->Cells[n - 1][0]);
		suma = SumaParesRecursivo(v, n - 1);
		if (num % 2 == 0) {
			suma = suma + num;
		}
	}
	return suma;
}

void __fastcall TForm1::N471Click(TObject *Sender)
{
	Word n = StrToInt(Edit1->Text);
	// Edit9->Text = SumaParesIterativo(Vector1, n);
	Edit2->Text = SumaParesRecursivo(StringGrid1, n);
}
//---------------------------------------------------------------------------


/* Escribir un proceso para invertir una parte de un vector
   (la parte comprendida entre a y b)
	Ej. v[2,5,65,23,45,2,13,45]
	Invetir (v, 2, 6)  ==>     v[2,5, 13, 2, 45, 23, 65, 45]
	Nota. Un solo proceso */
void Invertir_Vector(TStringGrid *v, Word a, Word b) {
	Word n;
	String x;
	n = b - a + 1;
	if (n > 1) {
		Invertir_Vector(v, a + 1, b - 1);
		x = v->Cells[b][0];
		v->Cells[b][0] = v->Cells[a][0];
		v->Cells[a][0] = x;
	}
}
/*void invert( TStringGrid *v ) {
  invVector( v, 0, v->ColCount - 1 );
}*/

void __fastcall TForm1::N481Click(TObject *Sender)
{
	Invertir_Vector(StringGrid1,StrToInt(Edit1->Text),StrToInt(Edit2->Text));
}

//---------------------------------------------------------------------------

// Cargar la siguiente Serie: 2, 4, 16, 22, 176, 186, ...

Cardinal auxSerie1(Cardinal n) {
	Cardinal t;
	if (n == 1)
		t = 2;
	else {
		if (n % 2 == 0)
			t = auxSerie1(n - 1) + ((n - 1) * 2);
		else
			t = auxSerie1(n - 1) * ((n - 1) * 2);
	}
	return t;
}
void cargarSerie1(TStringGrid* v, int n) {
	if (n == 1) {
		Cardinal termino = auxSerie1(1);
		v->Cells[0][0] = termino;
	}
	else {
		Cardinal termino = auxSerie1(n);
		v->Cells[n - 1][0] = termino;
		cargarSerie1(v, n - 1);
	}
}

void __fastcall TForm1::N482Click(TObject *Sender)
{
	byte n = StrToInt(InputBox("Longitud", "N�mero: ", ""));
	// Cardinal n = StringGrid1->ColCount;
	StringGrid1->ColCount = n;
	cargarSerie1(StringGrid1, n);
}
//---------------------------------------------------------------------------

// Verificar si un vector esta ordenado ascendentemente
//ej: v[1, 2, 3, 4, 5] --> ShowMessage(Esta Ordenado)

bool Verificar_Orden(TStringGrid* v, int n) {
	bool x;
	if (n == 1) {
		x = true;
	}
	else {
		String sa = v->Cells[n - 2][0];
		String sb = v->Cells[n - 1][0];
		Cardinal a = StrToInt(sa);
		Cardinal b = StrToInt(sb);
		if (a > b)
			x = false;
		else
			x = Verificar_Orden(v, n - 1);
	}
	return x;
}

void __fastcall TForm1::N501Click(TObject *Sender)
{
    bool b = Verificar_Orden(StringGrid1, StringGrid1->ColCount);
	if (b)
		ShowMessage("Esta Ordenado");
	else
		ShowMessage("No esta Ordenado");
}
//---------------------------------------------------------------------------

// Sumar los digitos de un vector (no importa si es cadena)

Cardinal auxSumaDigitos(String cad) {
	Cardinal s = 0;
	if (cad.Length() > 0) {
		char c = cad[1];
		if (c >= '0' && c <= '9') {
			s += (c - 48);
		}
		cad.Delete(1, 1);
		s += auxSumaDigitos(cad);
	}
	return s;
}
Cardinal sumaDigitos(TStringGrid* v, Byte n) {
	Cardinal s = 0;
	if (n > 0) {
		String cad = v->Cells[n - 1][0];
		s = auxSumaDigitos(cad);
		s += sumaDigitos(v, n - 1);
	}
	return s;
}

void __fastcall TForm1::N511Click(TObject *Sender)
{
	Byte n = StringGrid1->ColCount;
	Cardinal suma = sumaDigitos(StringGrid1, n);
	ShowMessage("Suma de digitos: " + String(suma));
}
//---------------------------------------------------------------------------

// Cargar en orden los caracteres de una cadena
// ej: edit(12345) --> v[1, 2, 3, 4, 5]

Cardinal posMayor(String cad) {
	Cardinal p;
	Word n = cad.Length();
	if (n == 1) {
		p = 1;
	}
	else {
		char c = cad[n];
		cad.Delete(n, 1);
		p = posMayor(cad);
		if (c > cad[p])
			p = n;
	}
	return p;
}
void cargarOrdAsc(TStringGrid* v, String cad) {
	if (cad.Length() > 0) {
		Cardinal posMay = posMayor(cad);
		char c = cad[posMay];
		v->Cells[cad.Length() - 1][0] = c;
		cad.Delete(posMay, 1);
		cargarOrdAsc(v, cad);
	}
}

void __fastcall TForm1::N521Click(TObject *Sender)
{
	String cad = Edit1->Text;
	StringGrid1->ColCount = cad.Length();
	cargarOrdAsc(StringGrid1, cad);
}
//---------------------------------------------------------------------------

/* Insertar un vector2 dentro de otro vector1

 v1 -> 1, 2, 3, 4, 5
 v2 -> 6, 7
 pos -> 2
 v1 -> 1, 2, 6, 7, 3, 4, 5
 */
void ecorrer(TStringGrid* v, Byte p, Byte n) {
	if (p < n) {
		v->Cells[n][0] = v->Cells[n - 1][0];
		ecorrer(v, p, n - 1);
	}
}
void insertar_aux(TStringGrid* v2, TStringGrid* v1, Byte p, Byte i) {
	if (i < v2->ColCount) {
		v1->ColCount = v1->ColCount + 1;
		ecorrer(v1, p, v1->ColCount);
		v1->Cells[p][0] = v2->Cells[i][0];
		insertar_aux(v2, v1, p + 1, i + 1);
	}
}
void insertar(TStringGrid* v2, TStringGrid* v1, Byte p) {
	insertar_aux(v2, v1, p, 0);
}
void __fastcall TForm1::N522Click(TObject *Sender)
{
	Cardinal p = StrToInt(InputBox("Titulo", "Posicion: ", ""));
	insertar(StringGrid2, StringGrid1, p);
}
//---------------------------------------------------------------------------

// Eliminar un elemento de un vector
//ej: v[1, 2, 3, 4, 5] --> eliminar(3) => v[1, 2, 4, 5]

void eliminar(TStringGrid* v, Cardinal p) {
	if (p < v->ColCount) {
		v->Cells[p][0] = v->Cells[p + 1][0];
		eliminar(v, p + 1);
	}
}
void eliminar_elemento(TStringGrid* v, Cardinal z, Cardinal n) {
	if (n > 0) {
		Cardinal num = StrToInt(v->Cells[n - 1][0]);
		if (num == z) {
			eliminar(v, n - 1);
			v->ColCount -= 1;
		}
		else {
			eliminar_elemento(v, z, n - 1);
		}
	}
}

void __fastcall TForm1::N541Click(TObject *Sender)
{
    	Cardinal z = StrToInt(InputBox("", "Numero:", ""));
		eliminar_elemento(StringGrid1, z, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------

// Cargar las vocales de una cadena en un vector
//ej: edit(hola como estan) --> v[oa, oo, ea]
String vocales(String cad) {
	String r;
	if (cad.Length() == 0)
		r = "";
	else {
		String alf = "aeiouAEIOU";
		char c = cad[1];
		cad.Delete(1, 1);
		Byte pos = alf.Pos(c);
		if (pos > 0)
			r = c;
		r += vocales(cad);
	}
	return r;
}
void cargar_vocales(String cad, TStringGrid* v) {
	if (cad.Length() == 0)
		v->ColCount--;
	else {
		Byte pos = cad.Pos(" ");
		if (pos == 0)
			pos = cad.Length() + 1;
		String pal = cad.SubString(0, pos - 1);
		cad.Delete(1, pos);
		String voc = vocales(pal);
		Cardinal n = v->ColCount;
		v->Cells[n - 1][0] = voc;
		v->ColCount++;
		cargar_vocales(cad, v);
	}
}

void __fastcall TForm1::N542Click(TObject *Sender)
{
   StringGrid2->ColCount = 1;
	String cad = Edit1->Text;
	// String cad = InputBox("", "Cadena:", "");
	cargar_vocales(cad, StringGrid2);
}
//---------------------------------------------------------------------------

// Cargar caracteres de una cadena en un vector
// ej: edit1(123456) --> v[1, 2, 3, 4, 5, 6]

void Cargar_Cadena(TStringGrid *v, byte n, String cad) {
	if (n > 0) {
		v->Cells[n - 1][0] = cad[n];
		Cargar_Cadena(v, n - 1, cad);
	}

}

void __fastcall TForm1::N561Click(TObject *Sender)
{
	String cad = Edit1->Text;
	byte n = cad.Length();
	StringGrid1->ColCount = n;
	Cargar_Cadena(StringGrid1, n, cad);
}
//---------------------------------------------------------------------------

// Eliminar vocales de una palabra y cargarlas en un vector
//ej: edit(hola como) --> v[hl, cm]

bool esVocal(wchar_t z) {
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
void cargar_palabras_sin_vocales(TStringGrid *v, String cad) {
	String pal;
	byte p, col, len;
	cad = cad.Trim();
	len = cad.Length();
	if (len > 1) {
		p = cad.LastDelimiter(' ');
		pal = cad.SubString(p + 1, len - p);
		cad.Delete(p + 1, len - p);
		cargar_palabras_sin_vocales(v, cad);
		eliminarVocales(pal);
		if (pal != "") {
			col = v->ColCount;
			v->Cells[col - 1][0] = pal;
			v->ColCount++;
		}
	}
	else {
		if (len == 1 && !esVocal(cad[1])) {
			v->Cells[0][0] = cad;
			v->ColCount++;
		}
	}
}

void __fastcall TForm1::N562Click(TObject *Sender)
{
	  StringGrid2->RowCount = 1;
	StringGrid2->ColCount = 1;
	String cadena = Edit1->Text;
	cargar_palabras_sin_vocales(StringGrid2, cadena);
	StringGrid2->ColCount--;
}
//---------------------------------------------------------------------------

// Cargar palabra de manera invertida al vector

bool EsLetra(char z) {
	AnsiString letras =
		"abcdefghijklmn�opqrstuvwxyzABCDEFGHIJKLMN�OPQRSTUVWXYZ";
	return letras.Pos(z) > 0;
}
void cargar_inverso_con_letras(TStringGrid *v, String cad) {
	char caracter;
	int len;
	byte col;
	len = cad.Length();
	if (len > 1) {
		caracter = cad[len];
		cad.Delete(len, 1);
		col = v->ColCount;
		if (EsLetra(caracter) > 0) {
			v->Cells[col - 1][0] = caracter;
			v->ColCount++;
		}
		cargar_inverso_con_letras(v, cad);
	}
	else {
		col = v->ColCount;
		if (EsLetra(cad[1]) > 0) {
			v->Cells[col - 1][0] = cad;
		}
		else {
			v->ColCount--;
		}
	}
}

void __fastcall TForm1::N581Click(TObject *Sender)
{
	String cadena = Edit1->Text;
	cargar_inverso_con_letras(StringGrid2, cadena);
}
//---------------------------------------------------------------------------

//de vector a cadena

long generar_num(TStringGrid *v, byte n) {
	long x;
	if (n == 1) {
		x = StrToInt(v->Cells[n - 1][0]);
	}
	else {
		long num = StrToInt(v->Cells[n - 1][0]);
		long len;
		if (num == 0) {
			len = 1;
		}
		else {
			len = log10(num) + 1;
		}
		x = generar_num(v, n - 1);
		x = x * pow(10, len) + num;
	}
	return x;
}

void __fastcall TForm1::N582Click(TObject *Sender)
{
	long x = generar_num(StringGrid1, StringGrid1->ColCount);
	Edit1->Text = x;
}
//---------------------------------------------------------------------------

void limpiarColumna(TStringGrid *m,byte c,byte f)
{
	if (f>0){
		limpiarColumna(m,c,f-1);
		m->Cells[c-1][f-1]="";
	}
}

void limpiar(TStringGrid *m,byte c,byte f)
{
	if (c>0) {
	   limpiar(m,c-1,f);
	   limpiarColumna(m,c,f);
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 limpiar(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
	 StringGrid1->ColCount=1;
	 StringGrid1->RowCount=1;
}
//---------------------------------------------------------------------------

