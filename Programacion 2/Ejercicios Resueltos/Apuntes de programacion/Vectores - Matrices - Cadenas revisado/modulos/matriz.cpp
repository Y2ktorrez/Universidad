//---------------------------------------------------------------------------

#pragma hdrstop

#include "matriz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void cargarTipoVector(TStringGrid*v, byte N){
  if (N > 0) {
	cargarTipoVector(v,N-1);
	byte m=v->ColCount;
	v->Cells[(N-1)%m][(N-1)/m] = N;
  }
}
//---------------------------------------------------------------------------
//	17	24	1	8	15
//	23	5	7	14	16
//	4	6	13	20	22
//	10	12	19	21	3
//	11	18	25	2	9
void Magico(TStringGrid *A, byte m, byte n, byte &f, byte &c){
 if(n>0) { //1er caso base
   if(n==1) { //2do caso base
	 A->Cells[m/2][0]=1;
	 c = m/2;
	 f = 0;
   } else { //caso general
	 Magico(A,m,n-1,f,c);
	 if((n-1)%m==0)
	   f++;
	 else {
	   f = (f==0)? (m-1) : f-1;
	   c=(c+1)%m;
	 }
	  A->Cells[c][f]=n;
   }
  }
}

void Magicov1(TStringGrid *A, byte m,byte k, byte &i,byte &j){
  if (m%2==0) //pre: debe ser dimension impar
	throw new Exception ("Error:dimension par");
  else {
	if (k==1){ //caso base
	  i=0;
	  j=m/2;
	  A->Cells[j][i] = k;
	}else{//caso general
	  Magicov1(A,m,k-1,i,j);
	  if((k-1)%m==0) //multiplo de m
		i++;
	  else{//no multip
		i = (i==0)? (m-1):(i-1); //contado
		j = (j+1)%m; //contador circular ascendente
	  }
	  A->Cells[j][i] = k;
	}
  }
}
//---------------------------------------------------------------------------
void cargarDentroToFueraCol(TStringGrid *v, byte f, byte ca, byte cb, byte x){
  byte c = cb-ca+1;
  if (c > 0) {
	cargarDentroToFueraCol(v, f, ca+1, cb, x);
	v->Cells[ca][f] = x;
	v->Cells[f][ca] = x;
  }
}

void cargarDentroToFuera(TStringGrid *v, byte fa,byte fb){
  byte f = fb-fa+1;
  if (f > 0) {
	if (f == 1) 
	  v->Cells[fa][fb]=1;	
	else {
	  cargarDentroToFuera(v, fa+1,fb-1);
	  cargarDentroToFueraCol(v, fa, fa, fb,(f+1)/2);
	  cargarDentroToFueraCol(v, fb, fa, fb,(f+1)/2);
	}
  }
}
//---------------------------------------------------------------------------

void llenarf1(TStringGrid*v,byte f,byte ca,byte cb,byte &k){
  byte c = cb-ca+1;
  if (c> 0) {
	llenarf1(v,f,ca,cb-1,k);
	v->Cells[cb][f]=k;
  }
}
void llenarc2(TStringGrid*v,byte fa,byte fb,byte cb,byte &k){
  byte f = fb-fa+1;
  if (f > 0) {
	llenarc2(v,fa,fb-1,cb,k);
	v->Cells[cb][fb]=k;
  }
}
void llenarf2(TStringGrid*v,byte fa,byte ca,byte cb,byte &k){
  byte c = cb-ca+1;
  if (c> 0) {
	llenarf2(v,fa,ca+1,cb,k);
	v->Cells[ca][fa]=k;
  }
}
void llenarc1(TStringGrid*v,byte fa,byte fb,byte ca,byte &k){
	byte f = fb-fa+1;
   if (f > 0) {
	llenarc1(v,fa+1,fb,ca,k);
	v->Cells[ca][fa]=k;
   }
}
void cargar2019_2B(TStringGrid*v,byte fa,byte fb,byte ca,byte cb,byte &k){
  byte f = fb-fa+1;
  byte c = cb-ca+1;
  if (f*c>0) {
	if (f*c == 1)
	  v->Cells[ca][fa]=k;
	else{
	  llenarf1(v,fa,ca,cb-1,k);
	  llenarc2(v,fa,fb-1,cb,k);
	  k++;
	  llenarf2(v,fb,ca+1,cb,k);
	  llenarc1(v,fa+1,fb,ca,k);
	  k++;
	  cargar2019_2B(v,fa+1,fb-1,ca+1,cb-1,k);
	}
  }
}
//-------------------------------------------------------------
//					1
//				2	3
//			6	5	4
//		7	8	9   10
//	15  14  13	12	11
void cargarCol2019_32(TStringGrid *v, byte ca, byte cb, byte f, byte &z){
	byte c = cb - ca + 1;
	if (c > 0) {
	  if (f % 2 == 0) {
		c = cb;
		cb--;
	  }else {
		c = ca;
		ca++;
	  }
	  v->Cells[c][f] = z;
	  z++;
	  cargarCol2019_32(v,ca, cb, f, z);
	}
}


void cargarFila2019_32(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &z){
  byte f = fb - fa + 1;
  if (f > 0) {
	cargarCol2019_32(v, fb-fa, cb, fa, z);
	cargarFila2019_32(v, fa+1, fb, ca, cb, z);
  }
}
//-------------------------------------------------------------
//	15
//	14  13
//	10	11	12
//	9   8   7	6
//	1	2	3	4	5
void cargar2020_1Segunda(TStringGrid *v, byte m, byte k, byte &f, byte &c){
  if (k == 1) {
	f = m-1;
	c = 0;
  } else {
	cargar2020_1Segunda(v,m,k-1,f,c); 
	if ((m-1)%2 == (f%2)) {
	  if (c==f){
		f = f-1;
		c = c - 1;
	  } else{
		c = c + 1;								  
	  }
	} else {
	  if (c == 0) (f--); else  (c--);
	}
  }
  v->Cells[c][f] = k;
  //IFEB
}
//-------------------------------------------------------------
//  1   3	6   10	15
//  2	5	9   14	19
//  4	8   13  18	22
//  7	12  17	21  24
//  11  16	20	23	25
void cargar2020_2(TStringGrid *v, byte m, byte k, byte &f, byte &c){
	if (k == 1) {
		f = 0;
		c = 0;
	} else {
	   cargar2020_2(v, m, k-1, f, c);
	   if (c == m-1) {  //ESQUINA
		c = f + 1;
		f = m - 1;
	   } else{
		  if (f == 0) { //FILA INICIAL
			 f =c + 1;
			 c = 0;
		 } else { //   CARGADO DIAGONA;
			 c++;
			 f--;
		 }
	   }
	}
	v->Cells[c][f] = k;
}
//---------------------------------------------------------------------------
//	1	2	3	4	5
//	2	3   4	5	6
//	3	4	5	6   7
//	4	5	6   7	8
//	5	6   7	8	9
void cargarCol2021_1(TStringGrid *v, byte f, byte ca, byte cb, byte x){
  byte c = cb - ca + 1;
  if (c > 0) {
	cargarCol2021_1(v, f, ca+1, cb, x+1);
	v->Cells[ca][f] = x;
  }
}

void cargarFila2021_1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb){
  byte f = fb-fa+1;
  if (f > 0) {
	cargarCol2021_1(v, fa, ca, cb, fa+1);
	cargarFila2021_1(v, fa+1, fb, ca, cb);
  }
}

//---------------------------------------------------------------------------
//	12	15	20  40
//	6	5	2	30
//	35	27  9	21
//	may=40, men = 2  maximo 2 procesos
void MayorMenorCol2021_2(TStringGrid *v,byte f, byte c, byte &men, byte &may){
	if (c == 0){
		may = 0;
		men = 0;
	}else {
	   byte x = v->Cells[c-1][f].ToInt();
	   if (c == 1) {
		   if (x > may) may = x;
		   if (x < men) men = x;
	   }else {
		   MayorMenorCol2021_2(v, f, c-1, men, may);
		   if (x > may) may = x;
		   if (x < men) men = x;
       }
    }
}

void MayorMenorFil2021_2(TStringGrid *v,byte f, byte c, byte &men, byte &may){
  if (f == 0){
	may = 0;
	men = 0;
  }else {
	if (f == 1) {
	  may = v->Cells[0][0].ToInt();
	  men = v->Cells[0][0].ToInt();
	}else {
	  MayorMenorFil2021_2(v, f-1, c, men, may);
	}
	MayorMenorCol2021_2(v, f-1, c, men, may);
  }
}
//---------------------------------------------------------------------------
//	1	1	1   1
//	1	2	2	2
//	1   2	3	3
//	1	2	3	4     matriz cuadrada
void cargarCol2022_1(TStringGrid *v, byte f, byte ca, byte cb){
  byte c = cb-ca+1;
  if (c > 0) {
	cargarCol2022_1(v, f, ca+1, cb);
	v->Cells[ca][f] = f+1;
	v->Cells[f][ca] = f+1;
  }
}
void cargarFila2022_1(TStringGrid *v, byte f, byte c){
  if (f > 0) {
	cargarFila2022_1(v, f-1, c);
	cargarCol2022_1(v, f-1, f-1, c-1);
  }
}
//---------------------------------------------------------------------------
void cargarCol2022_1B(TStringGrid *v, byte i, byte j, byte fa, byte fb){
  byte f = fb-fa+1;
  if (f > 0) {
	cargarCol2022_1B(v, i, j, fa, fb-1);
	v->Cells[j][fb] = i+1;
	v->Cells[j+fb][i] = i+1;
  }
}
void cargarFila2022_1B(TStringGrid *v, byte f, byte m){
  if (f > 0) {
	cargarFila2022_1B(v, f-1, m);
//	ShowMessage(IntToStr(f-1) +","+ IntToStr(0)+","+ IntToStr(f-1));
	cargarCol2022_1B(v, f-1,m-f, 0, f-1);
  }
}
//---------------------------------------------------------------------------
//caracol
void llenarf1Izq(TStringGrid*v,byte f,byte ca,byte cb,byte &k){
  byte c = cb-ca+1;
  if (c > 0) {
	llenarf1Izq(v,f,ca,cb-1,k);
	v->Cells[cb][f]=k;
	k++;
  }
}
void llenarc2Sup(TStringGrid*v,byte c, byte fa,byte fb,byte &k){
  byte f = fb-fa+1;
  if (f > 0) {
	llenarc2Sup(v,c,fa,fb-1,k);
	v->Cells[c][fb]=k;
	k++;
  }
}
void llenarf2Der(TStringGrid*v,byte f,byte ca,byte cb,byte &k){
  byte c = cb-ca+1;
  if (c> 0) {
	llenarf2Der(v,f,ca+1,cb,k);
	v->Cells[ca][f]=k;
	k++;
  }
}
void llenarc1Inf(TStringGrid*v,byte c,byte fa,byte fb,byte &k){
	byte f = fb-fa+1;
   if (f > 0) {
	llenarc1Inf(v,c,fa+1,fb,k);
	v->Cells[c][fa]=k;
	k++;
   }
}
void cargarCaracol(TStringGrid*v,byte fa,byte fb,byte ca,byte cb,byte &k){
  byte f = fb-fa+1;
  byte c = cb-ca+1;
  if (f*c>0) {
	if (f*c == 1)
	  v->Cells[ca][fa]=k;
	else{
	  llenarf1Izq(v,fa,ca,cb-1,k);
	  llenarc2Sup(v,cb,fa,fb-1,k);
	  llenarf2Der(v,fb,ca+1,cb,k);
	  llenarc1Inf(v,ca,fa+1,fb,k);
	  cargarCaracol(v,fa+1,fb-1,ca+1,cb-1,k);
	}
  }
}
//---------------------------------------------------------------------------




//dunnia-------------------------------------------------------
//	0	0	0   0   1
//	0	0	0	1   2
//	0	0	1	2   3
//	0	1	2	3	4
//	1	2	3	4   5
void cargarM1(TStringGrid * v, int f, int c, int m, int x){
		if (f < m) {
			  v->Cells[c][f] = x;
			if (c == (m - 1)) {
					f = f + 1;
					c = c - f - 1;
					x = 0;
			}
			cargarM1(v, f, c + 1 , m, x + 1);
		}
}


//	0	0	0   0   1
//	0	0	0	1   2
//	0	0	1	2   3
//	0	1	2	3	4
//	1	2	3	4   5
void cargarM2(TStringGrid * v, int f, int c, int m, int x){
  if (f < m) {
	v->Cells[c][f] = x;
	if ((f==0)||(f==(m-1))) {
	 v->Cells[c][f] = x++;
	 c = c + 1;
		if (c == (m)) {
		 c = 0;
		 f = f + 1;
		 x = 1;
		}
	} else {
	  v->Cells[0][f] = 1;
	  v->Cells[m-1][f] = m;
	  f = f + 1;
	}
	cargarM2(v, f, c , m, x);
  }
}


void cargarM(TStringGrid * v,int m, int f, int ca, int k){
  if (f < m) {
	 if (ca == m) {
		f++;
		ca = f;
		k = m-1;
	 }
	 v->Cells[ca][f] = k;
	 cargarM(v, m, f, ca + 1, k - 1);
  }
}

//	1	2	3	4
//	0	1	2	3
//	0	0	1	2
//	0	0	0	1
void cargar2022_1(TStringGrid * M,int m, int f, int c, int &x){
  if (f < m) {
	if (c == m) {
	  c = 0;
	  f = f + 1;
	} else {
	  if ( f > c)
		M->Cells[c][f] = 0;
	  else {
		M->Cells[c][f] = x;
		x = (c == (m-1))?  (1) : (x + 1);
	  }
	  c++;
	}
	cargar2022_1(M, m, f, c, x);
  }
}
