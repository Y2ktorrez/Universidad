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

byte SumaD(Cardinal x)
{ 	byte s;
	if (x<10)//caso base  n=1 (si tiene un digito)
		s=x;
	else //caso general
		s=SumaD(x/10); //quita el ultimo digito
		s=s+x%10;
	return s;
}

void __fastcall TForm1::Nmeros2Click(TObject *Sender)
{
	Edit2->Text=SumaD(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

byte SumaDigPrim(Cardinal x)
{	byte sp;
	if (x<10){ //caso base n=1
		if ((x==1) || (x==2)|| (x==3) || (x==5) || (x==7))
			sp=x;
		else
			sp=0;
	}else{  //caso general n>1
		sp=SumaDigPrim(x/10);
		x=x%10;
		if ((x==1) || (x==2)|| (x==3) || (x==5) || (x==7))
			sp=sp+x;
	}
	return sp;
}

void __fastcall TForm1::SumaDigPrim1Click(TObject *Sender)
{
		Edit2->Text=SumaDigPrim(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

byte Menor (Cardinal n)
{ byte a;
	if(n<10){   //caso base
		a=n;
	}else{  //caso general
		byte p=Menor(n/10); //quitas el ultimo numero
		a=p%10;
		if(n%10<a){ //que numero es menor?
			a=n%10;
		}
	}
	return a;
}
void __fastcall TForm1::SumaDigPrim2Click(TObject *Sender)
{
	Edit2->Text=Menor(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

byte Mayor(Cardinal n)
{
	byte a;
	if(n<10){   //caso base
		a=n;
	}else{  //caso general
		byte p=Menor(n/10); //quitas el ultimo numero
		a=p%10;
		if(n%10>a){ //que numero es mayor?
			a=n%10;
		}
	}
	return a;
}
void __fastcall TForm1::Mayor1Click(TObject *Sender)
{
	Edit2->Text=Mayor(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Proceso para mover el digito menor al final
  Ej: x=372654 --> 376542*/

/*Manda el menor al final, pero desordena todo lo demas
  Ej: x=372654 --> 736542 */
void MenorAlFinal(Cardinal &x)
{   if (x<10){ //caso base n=1
		//nada
	}else{ //caso general n>1
		byte a=x%10;
		x=x/10;
		MenorAlFinal(x);
		byte b=x%10;
		if(a<=b)
			x=x*10+a;
		else{
			b=x%10; //recuperar b
			x=x/10; //eliminar ultimo digito
			x=x*10+a;
			x=x*10+b;
		}
	}

}
/*si la entrada es lo mismo que la salida, es paramatro por referencia(&x)*/

void __fastcall TForm1::ManorAlFinal1Click(TObject *Sender)
{
	Cardinal z=StrToInt(Edit1->Text);
	MenorAlFinal(z);
	Edit2->Text=z;
}
//---------------------------------------------------------------------------

/*Proceso para ordenar un numero de mayor a menor
  Ej: x=37265 --> 76532*/
void Ordenar(Cardinal &x)
{ 	if(x>=10){  //caso general n>1
		MenorAlFinal(x);
		byte a=x%10;
		x=x/10;
		Ordenar(x);
		x=x*10+a;
	}
}

void __fastcall TForm1::Ordenar1Click(TObject *Sender)
{
	Cardinal z=StrToInt(Edit1->Text);
	Ordenar(z);
	Edit2->Text=z;
}

/*********** CADENAS ***********/

/*Funcion que devuelva la cantidad de vocales que hay en una cadena
  Ej: x= "Buenos dias @12434#" --> 5*/

bool EsVocal(Char a)
{
	AnsiString voc="aeiouAEIOU����������";
	return voc.Pos(a)>0;  //compara caracter por caracter
}

byte CantVocales(AnsiString x)
{   byte c;
		if (x==""){ //caso base
			c=0;
		}else{ //caso general
			char a=x[1]; //elimina el primer carcter
			x.Delete(1,1); //posicion a eliminar
			c=CantVocales(x);
			if(EsVocal(a))
				c++;
		}
	return c;
}

void __fastcall TForm1::CantVocales1Click(TObject *Sender)
{
	Edit2->Text=CantVocales(Edit1->Text);
}
//---------------------------------------------------------------------------

/*Funcion que devuelva el inverso de una cadena*/

//****menos el primero****//

/*AnsiString Invertir(AnsiString x)
{
	AnsiString y;
	if (x=="")//1er caso base
		y="";
	else{ //caso general
		char z=x[1];
		x.Delete(1,1);
		y=Invertir(x);
		y=y+z;
	}

	return y;
}*/

//****tarea menos el ultimo****//

/*AnsiString Invertir2(AnsiString x)
{
	AnsiString y;

	return y;
}*/

//****menos los dos primeros k=n-2****//

AnsiString Invertir3(AnsiString x)
{
	AnsiString y; byte n=x.Length();
	if (n<2)/*(n<1)da error  ***TE ESTAS COMIENDO EL CASO BASE***
			  (n==1)da error*/   //caso base n=0, n=1
		y=x;
	else{ //caso general
		AnsiString z=x.SubString(1,2);
		x.Delete(1,2);
		y=Invertir3(x);
		y=y+z[2]+ z[1];
	}
	return y;
}

//****menos los dos ultimos k=n-2****//

/*AnsiString Invertir4(AnsiString x)
{
	AnsiString y;

	return y;
}*/

//****menos el primero y el ultimo k=n-2****//

AnsiString Invertir5(AnsiString x)
{
	AnsiString y; byte n=x.Length();
	if(n<2) //caso base n=0,n=1
		y=x;
	else{ //caso general
		char z1=x[1];
		char z2=x[n];
		x.Delete(n,1);
		x.Delete(1,1);
		y=AnsiString(z2) + Invertir5(x) + (z1);
		/*Uso un operador como AnsiString en (z2) porque tiene
		  el char z2=x[n]*/
	}
	return y;
}

//*****lado izq corto k=n/2****//

/*AnsiString Invertir6(AnsiString x)
{
	AnsiString y;

	return y;
}*/

//****lado der corto k=n/2****//

AnsiString Invertir7(AnsiString x)
{
	AnsiString y; byte n=x.Length();
	if (n<2) //caso base
		y=x;
	else{ //caso general
		AnsiString z=x.SubString(n-n/2+1,n/2);
		x.Delete(n-n/2+1,n/2);
		y=Invertir7(z)+ Invertir7(x);
	}
	return y;
}

void __fastcall TForm1::Invertir1Click(TObject *Sender)
{
	//Edit1->Text=Invertir(Edit1->Text);
	//Edit1->Text=Invertir2(Edit1->Text);
	//Edit1->Text=Invertir3(Edit1->Text);
	//Edit1->Text=Invertir4(Edit1->Text);
	//Edit1->Text=Invertir5(Edit1->Text);
	//Edit1->Text=Invertir6(Edit1->Text);
	Edit1->Text=Invertir7(Edit1->Text);
}
//---------------------------------------------------------------------------

/*Escribir un algoritmo para eleminar todos los caracteres NO  alfabeticos ecepto el espacio de una cadena
  Ej. x = "@$#hola 425 chau" --> x = "Hola Chau"*/

bool EsLetra (char z)
{
	bool es; byte p;
	String letras = "qwertyuiopasdfghjkl�zxcvbnmQWERTYUIOPASDFGHJKL�ZXCVBNM";
	p = letras.Pos(z);
	es = letras.Pos(z)>0;
	return es;
}

void ElimNoLetras(AnsiString &x)
{
	byte n=x.Length();
	if (n==1){ //segundo caso general
		if (!(EsLetra(x[1])||(x==" ")))
			x = "";
	}else if (n>1){ //caso general n>1
		char a=x[1];
		char b=x[n];
		x.Delete(n,1);
		x.Delete(1,1);
		ElimNoLetras(x);
		if (EsLetra(a) || a==' ')
			x = AnsiString(a) + x;
		if (EsLetra(b) || b== ' ')
			x = x + b;
	}
}

void __fastcall TForm1::ElimNoAlfabticos1Click(TObject *Sender)
{
	/*cuado el parametro (&x) es por referiencia exige que
	  aqui tambien sea declarado de es manera*/
	AnsiString z=Edit1->Text;
	ElimNoLetras(z);
	Edit2->Text=z;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	  /*****Redimencionar*****/

	  //StringGrid1->ColCount = Edit1->Text.ToInt();
	  /*Vectores*/
	  StringGrid1->ColCount = StrToInt(Edit1->Text);
	  StringGrid1->RowCount = 1;
	  /*Matrices*/
	  StringGrid2->ColCount = StrToInt(Edit1->Text);
	  StringGrid2->RowCount = StrToInt (Edit2->Text);

}
//---------------------------------------------------------------------------

//Copiar los codigos implemantados en clases

void __fastcall TForm1::N11Click(TObject *Sender)
{
	//Llamado
}
//---------------------------------------------------------------------------

/*Busqueda Binaria*/ //Hipo K=n/2 (dos casos bases)

int BusBin(TStringGrid *v, int x, byte a, byte b)
{
	int p; byte n=b-a+1;
	if (n==0)             //caso base
		p =-1;
	else if (n==1){      //Segundo caso base
		if (x==StrToInt(v->Cells[a][0]))
			p=a;
		else
			p=-1;
	}else { //caso general
		byte c = (a+b)/2;
		if (x==StrToInt(v->Cells[c][0]))
			p=c;
		else if (x<StrToInt(v->Cells[c][0]))
			p=BusBin(v,x,a,c-1);
		else
			p=BusBin(v,x,c+1,b);
	}

	return p;
}


void __fastcall TForm1::BusBin1Click(TObject *Sender)
{
	Edit3->Text=BusBin(StringGrid1, StrToInt(Edit2->Text),0,StringGrid1->ColCount-1);
}
//---------------------------------------------------------------------------

/*Funcion que devuelva la posicion Mayor*/
byte PosMayor(TStringGrid *v, byte n)
{
	byte p;
	if (n==0) //pre: n>0
		throw  new Exception("Error: Vector Vacio");
	else if (n==1)//primer caso base
		p=0;
	else{ //caso general
		p=PosMayor(v,n-1);
		if(StrToInt(v->Cells[p][0]) < StrToInt(v->Cells[n-1][0]))
			p=n-1;
	}
	return p;
}

void SelectionSort(TStringGrid *v, byte n)
{
	if (n>1){//caso general
		byte p = PosMayor(v,n);
		String x = v->Cells[n-1][0];
		v->Cells[n-1][0] = v->Cells[p][0];
		v->Cells[p][0]=x;
		SelectionSort(v,n-1);
	}

}

void __fastcall TForm1::Ordenamiento1Click(TObject *Sender)
{
	SelectionSort(StringGrid1, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------

void LlenarF(TStringGrid *A, byte f, byte n)
{
	if (n>0){ //caso general
		LlenarF(A, f, n-1);
		A->Cells[n-1][f]=Random(20);
	}
}

/*void CargarA(TStringGrid *A, byte m, byte n)
{
	if (m>0){ //caso general
		CargarA(A, m-1, n);
		LlenarF(A, m-1, n);
	}
} */



void LlenarC(TStringGrid *A, byte c, byte n)
{
	if (n>0){
		LlenarC(A, c, n-1);
		A->Cells[c][n-1]=Random(20);
	}
}

/*void CargarB(TStringGrid *A, byte m, byte n)
{
	if (n>0){ //caso general
		CargarB(A, m, n-1);
		LlenarC(A, n-1, m);
	}
}*/



/*void CargarC(TStringGrid *A, byte m, byte n)
{
	if ((m>0) && (n>0)){ //caso general
		CargarC(A, m-1, n-1);
		LlenarF(A, m-1, n);
		LlenarC(A, n-1, m);
	}
}*/



void CargarD(TStringGrid *A, byte k, byte f, byte c)
{
	if (k>0){ //caso general
		A->Cells[c][f]= k ; //Random(20);
		if (c==0){
			c=A->ColCount-1;
			f--;
		}else{
			c=c-1;
		}
		CargarD(A, k-1, f, c);
	}
}

void __fastcall TForm1::Martices2Click(TObject *Sender)
{
	//CargarA(StringGrid2, StringGrid2->RowCount, StringGrid2->ColCount);
	//CargarB(StringGrid2, StringGrid2->RowCount, StringGrid2->ColCount);
	//CargarC(StringGrid2, StringGrid2->RowCount, StringGrid2->ColCount);

	byte m = StringGrid2->RowCount, n = StringGrid2->ColCount;
	CargarD(StringGrid2, m*n, m-1, n-1);
}
//---------------------------------------------------------------------------

/*CargarVectorDeUnaMatriz*/

void CargarV(TStringGrid *v, byte N)
{
	if (N>0){ //caso general
		byte n = v->ColCount;
		CargarV(v, N-1);
		v->Cells[(N-1%n)][(N-1)/n] = N;//v[N-1] = N;
	}
}

void __fastcall TForm1::MatricescomoVectores1Click(TObject *Sender)
{
	CargarV(StringGrid2, StringGrid2->RowCount*StringGrid2->ColCount);
}
//---------------------------------------------------------------------------

byte ContarX(TStringGrid *v, byte N, int x)
{
	byte r;
	if(N==0)
		r=0;
	else{
		byte n=v->ColCount;
		r=ContarX(v,N-1,x);
		if (x==v->Cells[(N-1)%n][(N-1)/n])
			r++;
	}
	return r;
}

void __fastcall TForm1::ContarlaCantidaddeDatosxenlamatriz1Click(TObject *Sender)

{
	Edit3->Text=ContarX(StringGrid2, StringGrid2->RowCount*StringGrid2->ColCount, StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------

bool BusBin(TStringGrid *v, byte a, byte b, int x)
{
	bool h; byte N = b-a+1; byte n=v->ColCount;
	if(N==0)
		h=false;
	else if (N==1)
		h = x==v->Cells[a%n][a/n];
	else{
		byte c = (a+b)/2;
		if (x==v->Cells[c%n][c/n])
			h=true;
		else if (x>v->Cells[c%n][c/n])
			h=BusBin(v, c+1, b, x);
		else
			h=BusBin(v,  a, c-1, x);
	}
	return h;
}

void __fastcall TForm1::BusquedaBinaria1Click(TObject *Sender)
{
	if (BusBin(StringGrid2,0,StringGrid2->RowCount*StringGrid2->ColCount-1,StrToInt(Edit2->Text) ));
		Edit3->Text="te pille";
	else
		Edit3->Text="No esta";

}
//---------------------------------------------------------------------------

