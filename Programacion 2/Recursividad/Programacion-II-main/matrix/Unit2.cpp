//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// cargar una matrix ramdon
void llenarFila(TStringGrid *m,byte c,byte f){
if (c>0) {
	   llenarFila(m,c-1,f);
	   m->Cells[c-1][f-1]=Random(10);
}

}
void cargar(TStringGrid *m,byte c,byte f){
if (f>0) {
	   cargar(m,c,f-1);
	   llenarFila(m,c,f);
}
}
void __fastcall TForm2::cargarrnd1Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	cargar(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------
//cargar matriz de 1 en 1
// 1 8 9  16     0
// 2 7 10 15      1
// 3 6 11 14       2
// 4 5 12 13        3
void llenarcolumna(TStringGrid *m,byte c,byte f,byte k){
  if (f>0) {
			llenarcolumna(m,c,f-1,k-1);
			m->Cells[c-1][f-1]=k;
  }
}
void llenarcolumna2(TStringGrid *m,byte c,byte f,byte k){
	if (f>0) {
			llenarcolumna2(m,c,f-1,k+1);
			m->Cells[c-1][f-1]=k;
  }
}
void cargar1en1(TStringGrid *m,byte c,byte f){
  if (c>0) {
		  cargar1en1(m,c-1,f);
		  if (c%2==0) {
			llenarcolumna2(m,c,f,((f*c)-(f-1)));
		  }else{
			llenarcolumna(m,c,f,f*c);
		  }

  }
}
void __fastcall TForm2::cargar11Click(TObject *Sender)
{
		StringGrid1->ColCount=StrToInt(Edit1->Text);
		StringGrid1->RowCount=StrToInt(Edit2->Text);
		cargar1en1(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------
//generar un triangulo
void llenarTRI(TStringGrid *m,byte c,byte f,byte k){
if (c>0){
	llenarTRI(m,c-1,f,k+1);
	m->Cells [c-1][f-1]=k;
	}
}
void ejer1(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   ejer1(m,c-1,f-1,k+(c-1));
	   llenarTRI(m,c,f,k-(c-1));
}
}

void __fastcall TForm2::generartriangulo1Click(TObject *Sender)
{
		StringGrid1->ColCount=StrToInt(Edit1->Text);
		StringGrid1->RowCount=StrToInt(Edit2->Text);
		byte i=StringGrid1->ColCount;
		ejer1(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,i);
}
//---------------------------------------------------------------------------
//limpiar matriz
void limiparcolumna(TStringGrid *m,byte c,byte f){
   if (f>0) {
		   limiparcolumna(m,c,f-1);
		   m->Cells[c-1][f-1]="";
   }
}
void limpiar(TStringGrid *m,byte c,byte f){
  if (c>0){
		   limpiar(m,c-1,f);
		   limiparcolumna(m,c,f);

  }
}
void __fastcall TForm2::Button1Click(TObject *Sender)
{ byte c=StringGrid1->ColCount;
  byte f=StringGrid1->RowCount;
	  limpiar(StringGrid1,c,f);
}
//---------------------------------------------------------------------------
//cargar matriz ejercicio 2 del practico
//void llenarejer2(TStringGrid *m,byte c,byte f,byte i){
 //  if (f>=c) {
 //		  llenarejer2(m,c,f-1,i-1);
//		  m->Cells[c-1][f-1]=i;
 //  }
//}
void llenarCo(TStringGrid *m,byte c,byte f,byte k){
if (f>(c-1)){
	llenarCo(m,c,f-1,k-1);
	m->Cells [c-1][f-1]=k;
}
}
void ejer2(TStringGrid *m,byte ac,byte bc,byte bf,byte k){
if (bc>=ac) {
   ejer2(m,ac+1,bc,bf-1,k+(bf-1));
   llenarCo(m,ac,bc,k);
}
}
//void ejer2(TStringGrid *m,byte c,byte f,byte i,byte k){
// if (k<=c) {
//  ejer2(m,c,f,(i+(c-k)),k+1);
//	  llenarejer2(m,k,f,i);
//  }
//}
void __fastcall TForm2::generartri21Click(TObject *Sender)
{
	 StringGrid1->ColCount=StrToInt(Edit1->Text);
	 StringGrid1->RowCount=StrToInt(Edit2->Text);
	 byte i=StringGrid1->RowCount;
	 ejer2(StringGrid1,1,StringGrid1->ColCount,StringGrid1->RowCount,i);

}
//---------------------------------------------------------------------------
//generar ejercicio 5
void llenar5(TStringGrid *m,byte c,byte g,byte f,byte &k,byte &p,byte &w){
if (g<=c){
	llenar5(m,c,g+1,f,k,p,w);
   if (p<w){
		k++;
		m->Cells[g-1][f-1]=k;
		p++;
   }else{
		m->Cells[g-1][f-1]=k;
   }
}

}
void ejer5(TStringGrid *m,byte c,byte f,byte k,byte d,byte p,byte w){
if (d<=f) {
	 ejer5(m,c,f,k,d+1,p,w-1);
	 llenar5(m,c,1,d,k,p,w);
}
}
void __fastcall TForm2::genrarejer51Click(TObject *Sender)
{
	 StringGrid1->ColCount=StrToInt(Edit1->Text);
	 StringGrid1->RowCount=StrToInt(Edit2->Text);
	 byte k=0;
	 byte w=StringGrid1->ColCount;
	 ejer5(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,k,1,k,w);
}
//---------------------------------------------------------------------------
void llenarL(TStringGrid *m,byte f,byte d,byte n){
 if (n>0) {
	 llenarL(m,f,d,n-1);
	 m->Cells[n-1][f-1]=d;
	 m->Cells[f-1][n-1]=d;
 }
}
void ejer5ing(TStringGrid *m,byte c,byte f,byte d){
  if (f>0) {
		ejer5ing(m,c,f-1,d+1);
		llenarL(m,f,d,c);
  }
}
//
void __fastcall TForm2::generarejer6ing1Click(TObject *Sender)
{
	 StringGrid1->ColCount=StrToInt(Edit1->Text);
	 StringGrid1->RowCount=StrToInt(Edit2->Text);
	 ejer5ing(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,1);

}
//---------------------------------------------------------------------------
void magico(TStringGrid *m,byte p,byte n,byte &c,byte &f){
if (n==1) {
	f=0;c=p/2;
	m->Cells[c][f]=n;
}else{
	  magico(m,p,n-1,c,f);
	  if ((n-1)%p==0)
		  f++;
	   else{
		  f--;
		  if (c==0)
			 c=p;
		  if (f==p)
			 f=0;
		  else
			c--;
	   }
	   m->Cells[c][f]=n;
}
}
void __fastcall TForm2::cuadradomagico1Click(TObject *Sender)
{   byte a,b,m=StrToInt(Edit1->Text);
	StringGrid1->ColCount=m;
	StringGrid1->RowCount=m;
	magico(StringGrid1,m,m*m,a,b);
}
//---------------------------------------------------------------------------
//rellenar matriz
//brian nahuel zalazar villca
//registro=219060193
void llenarida(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
 if (ac<=bc) {
		 m->Cells[ac][af]=k++;
		 llenarida(m,af,bf,ac+1,bc,k);
 }
}
void llenarvuelta(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
 byte n=bc-ac+1;
 if (n>0) {
		 m->Cells[bc][af]=k++;
		 llenarvuelta(m,af,bf,ac,bc-1,k);
 }
}
void llenar(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
	byte n=bf-af+1;
	if (n>0){
		if (n%2!=0) {
			 llenarida(m,af,bf,ac,bc,k);
		}else{
			 llenarvuelta(m,af,bf,ac,bc,k);
		}
		  llenar(m,af+1,bf,ac,bc,k);
	}
}
void __fastcall TForm2::seremod1Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	llenar(StringGrid1,0,(StringGrid1->RowCount)-1,0,(StringGrid1->ColCount)-1,k);
}
//---------------------------------------------------------------------------
//cagar vector con digitos impares
//1 3 5 7 9 11 13 15 17 19 21 23
//dar vuelta la hipotesis hace que todo lo generado se de la vuelta
void llenarfila(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
 if (ac<=bc) {
		m->Cells[ac][af]=k;
		k=k+2;
		llenarfila(m,af,bf,ac+1,bc,k);
 }
}
 void generarM(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
 if (af<=bf) {
			llenarfila(m,af,bf,ac,bc,k);
			generarM(m,af+1,bf,ac-1,bc,k);
 }
 }
void __fastcall TForm2::generarimpares1Click(TObject *Sender)
{       StringGrid1->ColCount=StrToInt(Edit1->Text);
		StringGrid1->RowCount=StrToInt(Edit2->Text);
		byte k=1;
		generarM(StringGrid1,0,(StringGrid1->RowCount)-1,(StringGrid1->ColCount)-1,(StringGrid1->ColCount)-1,k);
}
//---------------------------------------------------------------------------
//generar gusano de L
void llenarLF(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
	if (af<=bf){
			m->Cells[ac][af]=k;
			llenarLF(m,af+1,bf,ac,bc,k);
	}
}
void llenarLC(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
	if (ac<=bc){
			m->Cells[ac][bf]=k;
			llenarLC(m,af,bf,ac+1,bc,k);
	}
}
void llenarLFA(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
	if (af<=bf){
			m->Cells[bc][af]=k;
			llenarLFA(m,af+1,bf,ac,bc,k);
	}
}
void llenarLCB(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
	 if (ac<=bc){
			m->Cells[ac][af]=k;
			llenarLCB(m,af,bf,ac+1,bc,k);
	}
}

void generarLL(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k,byte n){
 if (n>=k) {
	if (n>=k) {
       llenarLF(m,af,bf,ac,bc,k);
	   llenarLC(m,af,bf,ac,bc-1,k);
	   k++;
	}
	 if (n>=k){
	   llenarLFA(m,af,bf,ac,bc,k);
	   llenarLCB(m,af,bf,ac+1,bc,k);
	   k++;
	   }
	   generarLL(m,af+1,bf-1,ac+1,bc-1,k,n);

 }
}
void __fastcall TForm2::enerarl1Click(TObject *Sender)
{
		StringGrid1->ColCount=StrToInt(Edit1->Text);
		StringGrid1->RowCount=StrToInt(Edit2->Text);
		byte k=1;
		generarLL(StringGrid1,0,(StringGrid1->RowCount)-1,0,(StringGrid1->ColCount)-1,k,StringGrid1->RowCount);
	 // llenarLF(StringGrid1,0,(StringGrid1->RowCount)-1,0,(StringGrid1->ColCount)-1,k);
	//llenarLC(StringGrid1,0,(StringGrid1->RowCount)-1,0,(StringGrid1->ColCount)-2,k);
	 // llenarLFA(StringGrid1,0,(StringGrid1->RowCount)-1,0,(StringGrid1->ColCount)-1,k);
	//  llenarLCB(StringGrid1,0,(StringGrid1->RowCount)-1,1,(StringGrid1->ColCount)-1,k);
}
//---------------------------------------------------------------------------
//brian nahuel zalazar villca
//registro=219060193
//brian nahuel zalazar villca
//registro=219060193
void llenarida2(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
 if (ac<=bc) {
		 m->Cells[bc][bf]=k++;
		 llenarida2(m,af,bf,ac+1,bc,k);
 }
}

void llenarvuelta2(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k){
 byte n=bc-ac+1;
 if (bc>=ac) {
		 m->Cells[ac][bf]=k++;
		 llenarvuelta2(m,af,bf,ac,bc-1,k);
 }
}

void llenar2(TStringGrid *m,byte af,byte bf,byte ac,byte bc,byte &k,byte p){
	byte n=bf-af+1;
	if (bf>=af){
		if (p==1) {
			 llenarvuelta2(m,af,bf,ac,bc,k);
			 p=2;
		}else{
			 llenarida2(m,af,bf,ac,bc,k);
			 p=1;
		}
		  llenar2(m,af,bf-1,ac,bc-1,k,p);
	}
}
void __fastcall TForm2::cadamat1Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	byte p=1;
	llenar2(StringGrid1,0,(StringGrid1->RowCount)-1,0,(StringGrid1->ColCount)-1,k,p);
}
//---------------------------------------------------------------------------






