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

void __fastcall TForm1::Numeros2Click(TObject *Sender)
{
    Edit2->Text=CantDigPares(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Escribir una funcion que muestre la cantidad de digitos
  pares que estan inmediaamente antes de uno impar
  Ej. CantDigPares(3827435)== 2,4*/


Cardinal  GetDigPares (Cardinal n)
{  Cardinal r;
   if (n<10){
	r=0;
   } else {  // asumimos que hay mas de 2 digitos
	   r=GetDigPares (n/10);
	   byte izq = (n/10) % 10;
	   byte der = (n%10);
	   if ((izq % 2==0) && (der % 2==1)){
			//r = r +1 ;
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

void __fastcall TForm1::ElimPrimDig1Click(TObject *Sender)
{  AnsiString cadena=Edit1->Text;
   EliminarPrimerNumero(cadena);
   Edit2->Text=cadena;
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

void __fastcall TForm1::EliminarPos1Click(TObject *Sender)
{
  byte n=StringGrid1->ColCount;
  byte pos=StrToInt(Edit2->Text);
  EliminarPos(StringGrid1,n,pos);
  StringGrid1->ColCount=n;
}
//---------------------------------------------------------------------------

/*Funcion que carge el vector Randomicamente*/

void Cargar(TStringGrid *v,byte n)
{ if (n>0){  //caso general
	 Cargar(v,n-1);
	 v->Cells[n-1][0]=Random(20);
  }
}

void __fastcall TForm1::Cargar1Click(TObject *Sender)
{
  StringGrid1->ColCount=StrToInt(Edit1->Text);
  Cargar(StringGrid1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Escribir un proceso para eliminar m datos de un vector de n numeros
  desde la posicion p. Pueden escribir hasta dos procesos
  Ej. Eliminar(1,4,3,2,6,7,8,1,9)->n=9,m=3,p=5 -> v(1,4,3,2,6,9)*/

void EliminarCant(TStringGrid *v, byte &n, byte p, byte cant){
	if(cant>0){
			EliminarPos(v,n,p);
			EliminarCant(v,n,p,cant-1);
	}
}

void __fastcall TForm1::EliminarCant1Click(TObject *Sender)
{
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
								 x=123728*/

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

void __fastcall TForm1::GenerarNumero1Click(TObject *Sender)
{
	Word n=StringGrid1->ColCount;
	Cardinal x;
	GenerarNumero(StringGrid1,n,x);
	ShowMessage(x);
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
	ShowMessage(UltimaPalabra);
	x.SetLength(p - 1);
	PalabraLarga = PalabraMasLarga(x);
	if (UltimaPalabra.Length() > PalabraLarga.Length()) {
		PalabraLarga = UltimaPalabra;
	}
  }
  return PalabraLarga;
}

void __fastcall TForm1::PalabraMasLarga1Click(TObject *Sender)
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

void __fastcall TForm1::CadDeDig1Click(TObject *Sender)
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

void __fastcall TForm1::SumaNumeros1Click(TObject *Sender)
{
   Edit2->Text=SumaNumeros(Edit1->Text);
}
//---------------------------------------------------------------------------

/*Cargar una matriz en con forma de escalera
  1
  22
  333
  4444*/

void Llenar(TStringGrid *A,byte f,byte n)
{
	if (n>0){
	  Llenar(A,f,n-1);
	  A->Cells[n-1][f]=f+1;
	}
}

void Escalera(TStringGrid *A,byte m)
{
   if (m>0){
	 Escalera(A,m-1);
	 Llenar(A,m-1,m);
   }
}

void __fastcall TForm1::Cargar11Click(TObject *Sender)
{
  StringGrid1->RowCount=StrToInt(Edit1->Text);
  StringGrid1->ColCount=StrToInt(Edit2->Text);
  Escalera(StringGrid1,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------

/*Escribir procesos(pueden escribir hasta 2 procesos) para cargar
  una matriz cuadrada de la siguiente forma:   12345
											   23456
											   34567*/

void CargarCol(TStringGrid *m, byte f,byte c,byte k)
{
   if (c>0){
	  CargarCol(m,f,c-1,k);
	  m->Cells[c-1][f]=k+c-1;
   }
}


void CargarFil(TStringGrid *m,byte f,byte c)
{
   if (f>0){
	  CargarFil(m,f-1,c);
	  CargarCol(m,f-1,c,f);
   }
}

void __fastcall TForm1::MatrizAmxm1Click(TObject *Sender)
{
   byte f,c,m=StrToInt(Edit1->Text);
   StringGrid1->ColCount=m;
   StringGrid1->RowCount=m;
   CargarFil(StringGrid1,m,m);
}
//---------------------------------------------------------------------------

/*vaciar una matriz*/

void EliminarF(TStringGrid *v,byte fa, byte fb, byte ca,byte cb)
{   byte n= cb-ca+1;
	if (n>0){
	   v->Cells[ca][fa]="";
	   EliminarF(v,fa,fb,ca+1,cb);}
}

void EliminarC(TStringGrid *v,byte fa, byte fb, byte ca,byte cb)
{	byte m=fb-fa+1;
	if (m>0){
	   EliminarF(v,fa,fb,ca,cb);
	   EliminarC(v,fa+1,fb,ca,cb);}
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	EliminarC(StringGrid1,0,StringGrid1->RowCount ,0,StringGrid1->ColCount );
	StringGrid1->ColCount =1;
	StringGrid1->RowCount =1;
}
//---------------------------------------------------------------------------

/*Matriz Triangular Superior*/

void CargarF(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &k)
{
  byte m=cb-ca+1;
  if (m>0){
	v->Cells[ca][fa]=k;
	k++;
	CargarF(v,fa,fb,ca+1,cb,k);
  }
}

void TriangularSup(TStringGrid *v,byte fa,byte fb,byte ca,byte cb,byte &k)
{
   byte n=fb-fa+1;
   if (n>0){
	   CargarF(v,fa,fb,ca,cb,k);
	   TriangularSup(v,fa+1,fb,ca+1,cb,k);
   }
}

void __fastcall TForm1::MatrisSuperior1Click(TObject *Sender)
{
   EliminarC(StringGrid1,0,StringGrid1->RowCount ,0,StringGrid1->ColCount );
   byte m=StrToInt(InputBox("","","5"));
   StringGrid1->RowCount =m ;
   StringGrid1->ColCount =m;
   byte k=1;
   TriangularSup(StringGrid1,0,m-1,0,m-1,k);
}
//---------------------------------------------------------------------------

/*Matriz Triangular Inferior*/

void CargarFil(TStringGrid *v,byte fa,byte fb,byte ca,byte cb,byte &k)
{
	byte m=fb-fa +1;
	if (m>0) {
		v->Cells [ca][fa]=k;
		k++;
		CargarFil(v,fa+1,fb,ca,cb,k);
	}
}

void TriangularInf(TStringGrid *v,byte fa,byte fb,byte ca,byte cb,byte &k)
{
	byte n= cb-ca +1;
	if (n>0) {
		CargarFil(v,fa,fb,ca,cb,k);
		TriangularInf(v,fa+1,fb,ca+1,cb,k);
	}
}


void __fastcall TForm1::MatrizInferior1Click(TObject *Sender)
{
  EliminarC(StringGrid1,0,StringGrid1->RowCount ,0,StringGrid1->ColCount );
  byte m=StrToInt(InputBox("","","5"));
  StringGrid1->RowCount =m ;
  StringGrid1->ColCount =m;
  byte k=1;
  TriangularInf(StringGrid1,0,m-1,0,m-1,k);
}
//---------------------------------------------------------------------------

/*Matriz espiral*/

void LlenarF1(TStringGrid *a,byte fa,byte ca,byte cb,byte &k)
{
	if (cb>=ca) {
	   a->Cells [ca][fa]=k++;
	   LlenarF1(a,fa,ca+1,cb,k);
	}
}

void LlenarC2(TStringGrid *a,byte cb,byte fa,byte fb,byte &k)
{
	if (fb>=fa) {
	   a->Cells [cb][fa]=k++;
	   LlenarC2(a,cb,fa+1,fb,k);
	}
}

void LlenarF2(TStringGrid *a,byte fb,byte ca,byte cb,byte &k)
{
	if (cb>ca) {
	   a->Cells [cb][fb]=k++;
	   LlenarF2(a,fb,ca,cb-1,k);
	}
}
void LlenarC1(TStringGrid *a,byte ca,byte fa,byte fb,byte &k)
{
	if (fb>fa) {
	   a->Cells [ca][fb]=k++;
	   LlenarC1(a,ca,fa,fb-1,k);
	}
}

typedef TStringGrid mat;
void CargarEsp(mat *a,byte fa, byte fb, byte ca, byte cb,byte &k)
{ byte m=fb-fa+1;
  byte n=cb-ca+1;
	if (m*n>0) {//caso base m=0 o n=0
		if (m*n==1) //2do caso base
			a->Cells[ca][fb]=k;
		else {//caso general
		LlenarF1(a,fa,ca,cb,k);//k= dato inicial
		LlenarC2(a,cb,fa+1,fb,k);
		LlenarF2(a,fb,ca,cb-1,k);
		LlenarC1(a,ca,fa,fb,k);
		CargarEsp(a,fa+1,fb-1,ca+1,cb-1,k);
		}
	}
}

void __fastcall TForm1::MatrizEspiral1Click(TObject *Sender)
{
	EliminarC(StringGrid1,0,StringGrid1->RowCount ,0,StringGrid1->ColCount );
	byte m=StrToInt(InputBox("","","5"));
	StringGrid1->RowCount =m;
	StringGrid1->ColCount =m;
	byte k=1;
	CargarEsp(StringGrid1,0,m-1,0,m-1,k);
}
//---------------------------------------------------------------------------

//1111111
//244443
//25773
//2563
//253
//23
//2

void LlenaTriangEsp(TStringGrid *A, Word fa, Word fb, Word ca, Word cb, Word k)
{
   byte n=cb-ca+1;
   if (n>0) {
	 A->Cells[cb][fa]=k;
	 LlenaTriangEsp(A,fa,fb,ca,cb-1,k);
   }
}

void Llena1TriangEsp(TStringGrid *A, Word fa, Word fb, Word ca, Word cb, Word k)
{
  byte n=fb-fa+1;
  if (n>0) {
	 A->Cells[ca][fa]=k;
	 Llena1TriangEsp(A,fa+1,fb,ca,cb,k);
  }
}

void Llena2TriangEsp(TStringGrid *A, Word fa, Word fb, Word ca, Word cb, Word k)
{
  byte n=cb-ca+1;
  if (n>0) {
	A->Cells[ca][fb]=k;
	Llena2TriangEsp(A,fa,fb-1,ca+1,cb,k);
  }
}

void MatrizCaracol(TStringGrid *A, Word fa, Word fb, Word ca, Word cb, Word &k)
{
   byte n=(A->ColCount %2==0)?0:1;
   if (fa<cb) {
	 LlenaTriangEsp(A,fa,fb,ca,cb,k);
	 k++;
	 Llena1TriangEsp(A,fa+1,fb,ca,cb,k);
	 k++;
	 Llena2TriangEsp(A,fa+1,fb-1,ca+1,cb-1,k);
	 k++;
	 MatrizCaracol(A,fa+1,fb-2,ca+1,cb-2,k);
   }
}

void __fastcall TForm1::MatrizCaracolTriangular1Click(TObject *Sender)
{
   byte m=StrToInt(InputBox("","Inserte la cantidad de filas y columnas",""));
   StringGrid1->RowCount=m;
   StringGrid1->ColCount=m;
   Word k=1;
   MatrizCaracol(StringGrid1,0,m-1,0,m-1,k);
}
//---------------------------------------------------------------------------

/*45678
  34567
  23456
  12345*/

void Cargar_Fila(TStringGrid*m,byte f,byte ca,byte cb,byte k)
{
   byte n=cb-ca+1;
	 if (n>0) {
		m->Cells [ca][f]=k;
		Cargar_Fila(m,f,ca+1,cb,k+1);
	 }
}

void MatrizModelodeExamen(TStringGrid*m,byte fa,byte fb,byte ca,byte cb,byte &k)
{
	byte n=fb-fa+1;
	if (n>0) {
	   Cargar_Fila(m,fb,ca,cb,k);
	   k++;
	   MatrizModelodeExamen(m,fa,fb-1,ca,cb,k);
	}
}

void __fastcall TForm1::MatrizModelodeExamen1Click(TObject *Sender)
{
	byte m=StrToInt(InputBox("","",""));
	StringGrid1->ColCount =m;
	StringGrid1->RowCount =m;
	byte k=1;
	MatrizModelodeExamen(StringGrid1,0,m-1,0,m-1,k);
}
//---------------------------------------------------------------------------


void LlenarC(TStringGrid *m,byte fa,byte fb,byte ca,byte cb,byte k){
	byte n=fb-fa+1;
	if (n>0) {
		   m->Cells[cb][fa]=k;
		   LlenarC(m,fa+1,fb,ca,cb,k+1);
	}
}
void LlenarC2(TStringGrid *m,byte fa,byte fb,byte ca,byte cb,byte k){
	byte n=fb-fa+1;
	if (n>0) {
		   m->Cells[cb][fb]=k;
		   LlenarC2(m,fa,fb-1,ca,cb,k+1);
	}
}
  void TriangularDer(TStringGrid *m,byte fa,byte fb,byte ca,byte cb,byte k){
	byte n=fb-fa+1;
	if (n>0) {
		   if (fa%2==0)
				LlenarC(m,fa,fb,ca,cb,k);
		   else
				LlenarC2(m,fa,fb,ca,cb,k);
		   k=k+fb-fa+1;
		   TriangularDer(m,fa+1,fb,ca,cb-1,k);
	}
}

void __fastcall TForm1::MatrisTriangularDerecho1Click(TObject *Sender)
{
	byte m=StrToInt(InputBox("","dimencion",""));
	StringGrid1->ColCount = m;
	StringGrid1->RowCount =m;
	TriangularDer(StringGrid1,0,m-1,0,m-1,1);
}
//---------------------------------------------------------------------------


void OrdCol(TStringGrid *A, int f, int c, int cont){
	if ((A->ColCount*A->RowCount)>=cont){
		A->Cells[c][f]=cont;
		f--;
		cont++;
		if (f<0){
			c--;
			f=A->RowCount-1;
		}
		OrdCol(A,f,c,cont);
	}
}

void OrdCol(TStringGrid *A){
	OrdCol(A, A->RowCount-1, A->ColCount-1,1);
}

void __fastcall TForm1::Orden1Click(TObject *Sender)
{
   int m=StrToInt((InputBox("","filas","0")));
	int n=StrToInt((InputBox("","Columnas","0")));
	StringGrid1->ColCount=n;
	StringGrid1->RowCount=m;
	OrdCol(StringGrid1);
}
//---------------------------------------------------------------------------

void llenarc2(TStringGrid*v,byte fa,byte fb,byte cb,byte &k){
  byte f = fb-fa+1;
  if (f > 0) {
	llenarc2(v,fa,fb-1,cb,k);
	v->Cells[cb][fb]=k;
  }
}

void CargarFil(TStringGrid *v, byte f, byte ca, byte cb, byte &x)
{
	byte c=cb-ca+1;
	if (c>0){
		v->Cells[ca][f]=x;
		x=x+1;
		CargarFil(v,f,ca+1,cb,x);
	}
}

void CargarFil1(TStringGrid *v, byte f, byte ca, byte cb, byte &x)
{
	byte c=cb-ca+1;
	if (c>0){
		v->Cells[cb][f]=x;
		x=x+1;
		CargarFil1(v,f,ca,cb-1,x);
	}
}

void Caracoliho(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &x)
{
	byte c=cb-ca+1;
	byte f=fb-fa+1;
	if (f*c>0){
		if (f*c==1){
			v->Cells[cb][ca]=x;
		}else{
			CargarFil(v,fa,ca,cb-1,x);
			llenarc2(v,fa,fb-1,cb,x);
			CargarFil1(v,fb,ca+1,cb,x);
            llenarc2(v,fa+1,fb,ca,x);
			Caracoliho(v,fa+1,fb-1,ca+1,cb-1,x);
		}
	}
}

void __fastcall TForm1::prueba1Click(TObject *Sender)
{
	byte f, c, m=StrToInt(Edit1->Text);
	StringGrid1->ColCount=m;
	StringGrid1->RowCount=m;
	byte x=1;
	/*CargarFil(StringGrid1,0,0,m-1,x);
	  CargarFil1(StringGrid1,m-1,0,m-1,x);*/
	Caracoliho(StringGrid1,0,m-1,0,m-1,x);
}
//---------------------------------------------------------------------------



