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

/*Matriz
  1  3  6  10
  2  5  9  13
  4  8  12 15
  7 11  14 16*/
void cargar2020_2(TStringGrid *v,byte m,byte k,byte &f,byte &c){
	if (k == 1) {
		f = 0;
		c = 0;
	} else {
	   cargar2020_2(v, m, k-1, f, c);
	   if (c == m-1) {
		c = f + 1;
		f = m - 1;
	   } else{
		  if (f == 0) {
			 f =c + 1;
			 c = 0;
		 } else { //
			 c++;
			 f--;
		 }
	   }
	}
	v->Cells[c][f] = k;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   byte f,c,m=StrToInt(Edit1->Text);
   StringGrid1->ColCount=m;
   StringGrid1->RowCount=m;
   cargar2020_2(StringGrid1,m,m*m,f,c);
}
//---------------------------------------------------------------------------



/*void Cargar_Fila(TStringGrid*m,byte f,byte ca,byte cb,byte k)
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
  */


void llenarMatrix( TStringGrid *A, int f, int c, int k ) {
  int n;
  n = A->ColCount*(A->ColCount+1)/2-k;
  A->Cells[c][f] = k;
  if ( n > 0 ) {
	if ( f == 0 ) {
	  f = c + 1;
	  c = 0;
	}
	else {
	  f--;
	  c++;
	}
	llenarMatrix(A,f,c,k+1);
  }
}


/*void llenarMatrix( TStringGrid *A, int f, int c, int k ) {
  int n;
  n = A->ColCount*(A->ColCount+1)/2-k;
  A->Cells[c][f] = k;
  if ( n > 0 ) {
	if ( f == 0 ) {
	  f = c + 1;
	  c = 0;
	}
	else {
	  f--;
	  c++;
	}
	llenarMatrix(A,f,c,k+1);
  }
}*/



/*void inser(TStringGrid *v,byte fa, byte fb,byte ca, byte cb,byte &k)
{
	if (fa<=fb) {
		v->Cells [cb][fa]=k++;
		inser(v,fa+1,fb,ca,cb-1,k);
	}
}
void modex1(TStringGrid *v,byte fa, byte fb,byte ca, byte cb,byte &k)
{
	byte m=fb-fa+1;
	if (m>0) {
		inser(v,fa,fb,ca,cb,k);
		modex1(v,fa+1,fb,ca,cb,k);
	}
} */

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  int m = StrToInt(Edit1->Text);
  int n = StrToInt(Edit2->Text);
  StringGrid1->ColCount = n;
  StringGrid1->RowCount = m;
  llenarMatrix(StringGrid1, 0, 0, 1 );
   /*	byte m=StrToInt(InputBox("","","5"));
	StringGrid1->RowCount =m ;
	StringGrid1->ColCount =m;
	byte k=1;
	modex1(StringGrid1,0,m-1,0,m-1,k);*/
}
//---------------------------------------------------------------------------

void LlenarDeCero (TStringGrid *v,Byte n)
{
	if (n>0){
		Byte N=v->ColCount;
		LlenarDeCero (v,n-1);
		v->Cells[(n-1)%N][(n-1)/N]=0;
	}
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	LlenarDeCero (StringGrid1,n);
}
//---------------------------------------------------------------------------
