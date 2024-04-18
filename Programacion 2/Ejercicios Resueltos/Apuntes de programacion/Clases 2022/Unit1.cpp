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

/*Escribir una funcion que devuelva la suma de los digitos de un
  numero Ej: x=2473845 -> 33*/

byte Suma(Cardinal x)
{ byte s;
  if (x<10){ //caso base
	 s=x;
  } else{ // caso general
	 s=Suma(x/10);
	 s=s + x%10;
  }
  return s;
}

void __fastcall TForm1::Apuntedeclase2Click(TObject *Sender)
{
  Edit2->Text=Suma(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Funcion que devuelva el mayor de los digitos de un numero
  Ej: x=243753 -> 7*/

byte Mayor(Cardinal x)
{  byte m;
   if (x<10){ //caso base
	  m=x;
   } else{    //caso general
	  m=Mayor(x/10);
	  if (x%10 > m)
		 m=x%10;
   }
   return m;
}


void __fastcall TForm1::Mayor1Click(TObject *Sender)
{
  Edit2->Text=Mayor(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Funcion que devulvala suma de los digitos impares de un numero
  Ej: x=4525637 -> 20*/

byte SumaDigImp (Cardinal x)
{ byte sum;
  if (x<10){   //caso base
	 if(x%2 == 1)
	  sum= x;
	 else
	  sum=0;
  } else{      //caso general
	  sum = SumaDigImp(x/10);
	  if(((x%10)%2)==1)
		sum=sum+(x%10);
  }
  return sum;
}


void __fastcall TForm1::SumaDIgImp1Click(TObject *Sender)
{
   Edit2->Text=SumaDigImp(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Proceso para eliminar los digitos impares de un numero
  Ej: x=34875261 ->4826*/

void ElimDigImp(Cardinal &x)
{ if (x<10){ //caso base
	if (x%2==1)
	 x=0;
  } else{ //caso general
	byte d=x%10;
	x=x/10;
	ElimDigImp(x);
	if (d%2==0)
		x=x*10+d;
  }
}

void __fastcall TForm1::Clase22Click(TObject *Sender)
{ Cardinal z;
  z=StrToInt(Edit1->Text);
  ElimDigImp(z);
  Edit1->Text=z;
}
//---------------------------------------------------------------------------

/*Proceso que devuelva el digito Mayor y el digito menor de un numero
  Ej: x=425376 -> menor=2, mayor=7*/

void MayorMenor(Cardinal x, byte &M, byte &m)
{ if (x<10){ //caso base
	m=x;
	M=x;
  } else{ //caso general
	byte d=x%10;
	MayorMenor(x/10,M,m);
	if (d<m)
		m=d;
	if (d>M)
		M=d;
  }
}

void __fastcall TForm1::MayorMenor1Click(TObject *Sender)
{ byte a,b;
  MayorMenor(StrToInt(Edit1->Text),a,b);
  Edit2->Text=a;
  Edit3->Text=b;

}
//---------------------------------------------------------------------------

/*Escribir un proceso para invertir un cadena
  Ej: x=Hola todos -> sodot aloh*/

void Invertir(AnsiString &x)
{ byte n=x.Length();
  if (n<2){  //caso base n=0, n=1
   //nada, nose hace nada
  } else {   //caso general n>1
	  AnsiString y=x.SubString(1,2);
	  x.Delete(1,2);
	  Invertir(x);
	  x=x+y[2]+y[1];
  }
}

/*void Invertir2(AnsiString &x)
{ byte n=x.Length();
   if (n>1){
	  AnsiString y=x.SubString(1,2);
	  x.Delete(1,2);
	  Invertir2(x);
	  x=x+y[2]+y[1];
  }
} */

/*void Invertir3(AnsiString &x)
{ byte n=x.Length();
   if (n>1){ //caso general
	  AnsiString y=x.SubString(1,n/2);
	  x.Delete(1,n/2);
	  Invertir3(x);
	  Invertir3(y);
	  x=x+y;
  }
} */

void __fastcall TForm1::Clase32Click(TObject *Sender)
{ AnsiString a;
  a=Edit1->Text;
  Invertir(a);
  Edit1->Text=a;

}
//---------------------------------------------------------------------------

/*Cargar un vector Randomicamente*/

void Cargar(TStringGrid *v,byte n)
{ if (n>0){  //caso general
	 Cargar(v,n-1);
	 v->Cells[n-1][0]=Random(20);
  }
}

void __fastcall TForm1::Clase42Click(TObject *Sender)
{ StringGrid1->ColCount=StrToInt(Edit1->Text);
  Cargar(StringGrid1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

/*Sumar los elementos de un vector*/

/*Word Suma1(TStringGrid *v,byte n)
{ Word s;
  if (n==0) //caso base
	s=0;
  else //caso general
	s=Suma1(v,n-1)+ StrToInt(v->Cells[n-1][0]);
  return s;
}*/

/*Word Suma2(TStringGrid *v,byte a,byte b)
{ Word s; byte n=b-a+1;
  if (n==0) //1er caso base
	s=0;
  else if(n==1) //2do caso base
	s=StrToInt(v->Cells[b][0]);
  else //caso general
	s=Suma2(v,a+1,b-1)+StrToInt(v->Cells[a][0])+StrToInt(v->Cells[b][0]);
  return s;
}*/

Word Suma3(TStringGrid *v,byte a,byte n)
{ Word s;
  if (n==0)
	s=0;
  else if (n==1)
	s=StrToInt(v->Cells[a][0]);
  else
	s=Suma3(v,a+2,n-2)+StrToInt(v->Cells[a][0])+StrToInt(v->Cells[a+1][0]);
  return s;
}



void __fastcall TForm1::Sumar1Click(TObject *Sender)
{
	//Edit3->Text=Suma1(StringGrid1,StringGrid1->ColCount);
	//Edit3->Text=Suma2(StringGrid1,0,StringGrid1->ColCount-1);
	//Edit3->Text=Suma3(StringGrid1,0,StringGrid1->ColCount);
	/*Edit3->Text=Suma3(StringGrid1,StrToInt(Edit1->Text),StrToInt(Edit2->Text));
	  este ultimo no funciona*/
}
//---------------------------------------------------------------------------

/*Matriz que cargue  12345
					 678910*/
void LlenarF(TStringGrid *A,byte f,byte n)
{
  if (n==1)
	A->Cells[0][f]=f*A->ColCount+1;
  else if (n>1){
	LlenarF(A,f,n-1);
	A->Cells[n-1][f]=StrToInt(A->Cells[n-2][f])+1;
  }
}

void Cargar(TStringGrid *A,byte m,byte n)
{
   if (m>0){
		Cargar(A,m-1,n);
		LlenarF(A,m-1,n);
   }
}

void __fastcall TForm1::Cargar1Click(TObject *Sender)
{
   StringGrid1->RowCount=StrToInt(Edit1->Text);
   StringGrid1->ColCount=StrToInt(Edit2->Text);
   Cargar(StringGrid1,StringGrid1->RowCount,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------

/*Cargar una Matriz 1234
					8765*/

void LlenarF2(TStringGrid *A,byte f,byte n)
{
  if (n>0){
	LlenarF2(A,f,n-1);
	A->Cells[n-1][f]=f*A->ColCount+A->ColCount-n+1;
  }
}

void Cargar3(TStringGrid *A,byte m,byte n)
{
  if (m>0){
	Cargar3(A,m-1,n);
	if ((m-1)%2==0)
		LlenarF(A,m-1,n);
	else
		LlenarF2(A,m-1,n);
  }
}

void __fastcall TForm1::Cargar2Click(TObject *Sender)
{
   StringGrid1->RowCount=StrToInt(Edit1->Text);
   StringGrid1->ColCount=StrToInt(Edit2->Text);
   Cargar3(StringGrid1,StringGrid1->RowCount,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------

/*Cargar Matriz 1
				22
				333
				4444*/

void LlenarF3(TStringGrid *A,byte f,byte n)
{
	if (n>0){
	  LlenarF3(A,f,n-1);
	  A->Cells[n-1][f]=f+1;
	}
}

void Cargar4(TStringGrid *A,byte m)
{
   if (m>0){
	 Cargar4(A,m-1);
	 LlenarF3(A,m-1,m);
   }
}

void __fastcall TForm1::Cargar31Click(TObject *Sender)
{
  StringGrid1->RowCount=StrToInt(Edit1->Text);
  StringGrid1->ColCount=StrToInt(Edit2->Text);
  Cargar4(StringGrid1,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------

/*3 3 3 3 3
  3 2 2 2 3      tiene dos casos base
  3 2 1 2 3      por que usamos la
  3 2 2 2 3      hipotesis "n-2"
  3 3 3 3 3*/

 void LlenarF5(TStringGrid *A, byte f, byte a, byte b, byte d)
 {
	byte n=b-a+1;
	if (n>0){
		LlenarF5(A,f,a+1,b,d);
		A->Cells[a][f]=d;
		A->Cells[f][a]=d;
	}
 }

void matriz(TStringGrid *A,byte fa,byte fb)
{
   byte m=fb-fa+1;
   if (m==1) //caso base
	  A->Cells[fa][fa]=1;
   else if (m>1){ //caso general
		matriz(A,fa+1,fb-1);
		LlenarF5(A,fb,fa,fb,(m+1)/2);
		LlenarF5(A,fa,fa,fb,(m+1)/2);
   }
}

void __fastcall TForm1::Clase72Click(TObject *Sender)
{
	StringGrid1->RowCount=StrToInt(Edit1->Text);
	StringGrid1->ColCount=StringGrid1->RowCount;
	matriz(StringGrid1,0,StringGrid1->RowCount-1);
}
//---------------------------------------------------------------------------

void Magicol(TStringGrid *A, byte m, byte k, byte &i, byte &j)
{
   if (m%2==0)
   throw new Exception("Error: dimension par");
   else{
	   if (k==1){
		  i=0; j=m/2; A->Cells[j][i]=k;
	   } else {
		   Magicol(A,m,k-1,i,j);
		   if ((k-1)%m==0)
			i++;
		   else {
			  i=i==0?m-1:i-1;
			  j=(j+1)%m;
		   }
		   A->Cells[j][i]=k;
	   }
   }
}

void __fastcall TForm1::MatrizSodok1Click(TObject *Sender)
{
	byte k,i,j;
	StringGrid1->RowCount=StrToInt(Edit1->Text);
	StringGrid1->ColCount=StringGrid1->RowCount;
	k=StringGrid1->RowCount*StringGrid1->ColCount;
	Magicol(StringGrid1,StringGrid1->RowCount,k,i,j);

}
//---------------------------------------------------------------------------
