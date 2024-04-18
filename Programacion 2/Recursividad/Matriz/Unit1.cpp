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

/*void Llenar_VAB(TStringGrid *v, byte row, byte col, byte &serie) {
	if (row == 1) {
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	} else {
		Llenar_VAB(v, row - 1, col, serie);
		v->Cells[col - 1][row - 1] = serie;
		serie++;
	}
}*/

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

void __fastcall TForm1::N111Click(TObject *Sender)
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

void __fastcall TForm1::N112Click(TObject *Sender)
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

void __fastcall TForm1::N132Click(TObject *Sender)
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

void __fastcall TForm1::N151Click(TObject *Sender)
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

void __fastcall TForm1::N152Click(TObject *Sender)
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

void __fastcall TForm1::N171Click(TObject *Sender)
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

void __fastcall TForm1::N172Click(TObject *Sender)
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

void __fastcall TForm1::N191Click(TObject *Sender)
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

void __fastcall TForm1::N192Click(TObject *Sender)
{

	//byte m = StrToInt(InputBox("FILAS", "N�mero: ", ""));
	//byte n = StrToInt(InputBox("COLUMNAS", "N�mero: ", ""));
	 Cardinal m = StringGrid1->RowCount;
	Cardinal n = StringGrid1->ColCount;
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
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

void __fastcall TForm1::N222Click(TObject *Sender)
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

void __fastcall TForm1::N251Click(TObject *Sender)
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

void __fastcall TForm1::N252Click(TObject *Sender)
{
	byte m = StrToInt(Edit1->Text);
	byte n = StrToInt(Edit2->Text);
	StringGrid1->RowCount = m;
	StringGrid1->ColCount = n;
	//byte n = StrToInt(InputBox("ORDEN", "N�mero: ", ""));
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

void llenarf1(TStringGrid*v,byte fa,byte ca,byte cb,byte &k){
  byte c = cb-ca+1;
  if (c> 0) {
	llenarf1(v,fa,ca,cb-1,k);
	v->Cells[cb][fa]=k;
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
void cargar(TStringGrid*v,byte fa,byte fb,byte ca,byte cb,byte &k){
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
	  cargar(v,fa+1,fb-1,ca+1,cb-1,k);
	}
  }
}

void __fastcall TForm1::N262Click(TObject *Sender)
{
	byte fa = 0;
	byte fb = StrToInt(Edit1->Text)-1;
	StringGrid1->RowCount=fb+1;
	byte ca = 0;
	byte cb = StrToInt(Edit2->Text)-1;
	StringGrid1->ColCount=cb+1;
	byte k = 1;
	cargar(StringGrid1, fa, fb, ca, cb, k);
}
//---------------------------------------------------------------------------

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

void __fastcall TForm1::N281Click(TObject *Sender)
{
	StringGrid1->RowCount=StrToInt(Edit1->Text);
	StringGrid1->ColCount=StrToInt(Edit2->Text);
	Escalera(StringGrid1,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------

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

void __fastcall TForm1::N282Click(TObject *Sender)
{
	byte f,c,m=StrToInt(Edit1->Text);
	StringGrid1->ColCount=m;
	StringGrid1->RowCount=m;
    CargarFil(StringGrid1,m,m);
}
//---------------------------------------------------------------------------

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

void __fastcall TForm1::N301Click(TObject *Sender)
{
	byte m=StrToInt(Edit1->Text);
	StringGrid1->RowCount =m ;
	StringGrid1->ColCount =m;
	byte k=1;
	TriangularSup(StringGrid1,0,m-1,0,m-1,k);
}
//---------------------------------------------------------------------------

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

void __fastcall TForm1::Seguimos4Click(TObject *Sender)
{
   byte m=StrToInt(Edit1->Text);
   StringGrid1->RowCount =m ;
   StringGrid1->ColCount =m;
   byte k=1;
   TriangularInf(StringGrid1,0,m-1,0,m-1,k);
}
//---------------------------------------------------------------------------

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

void __fastcall TForm1::N321Click(TObject *Sender)
{
   byte m=StrToInt(Edit1->Text);
   StringGrid1->RowCount=m;
   StringGrid1->ColCount=m;
   Word k=1;
   MatrizCaracol(StringGrid1,0,m-1,0,m-1,k);
}
//---------------------------------------------------------------------------

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

void __fastcall TForm1::N322Click(TObject *Sender)
{
	byte m=StrToInt(Edit1->Text);
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


void __fastcall TForm1::N341Click(TObject *Sender)
{
	byte m=StrToInt(Edit1->Text);
	StringGrid1->ColCount = m;
	StringGrid1->RowCount =m;
	TriangularDer(StringGrid1,0,m-1,0,m-1,1);
}
//---------------------------------------------------------------------------

void llenarc_2(TStringGrid*v,byte fa,byte fb,byte cb,byte &k){
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
			llenarc_2(v,fa,fb-1,cb,x);
			CargarFil1(v,fb,ca+1,cb,x);
			llenarc_2(v,fa+1,fb,ca,x);
			Caracoliho(v,fa+1,fb-1,ca+1,cb-1,x);
		}
	}
}

void __fastcall TForm1::N342Click(TObject *Sender)
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

//RANDOM

void LlenarF(TStringGrid *A, byte f, byte n)
{
	if (n>0){ //caso general
		LlenarF(A, f, n-1);
		A->Cells[n-1][f]=Random(20);
	}
}

void CargarA(TStringGrid *A, byte m, byte n)
{
	if (m>0){ //caso general
		CargarA(A, m-1, n);
		LlenarF(A, m-1, n);
	}
}

//FUNCION

void MayorDeUnaMatrizCarlos (TStringGrid *v,Byte n,byte &num){
	if (n>0) {
		byte N=v->ColCount;
		MayorDeUnaMatrizCarlos (v,n-1,num);
		byte c=(n-1)%N;
		byte f=(n-1)/N;
		byte k=StrToInt(v->Cells[c][f]);
		if (k>num)
			num=k;
	}
}
void MenorDeUnaMatriz (TStringGrid *v,Byte n,Byte &num){
	if (n>0) {
		Byte N=v->ColCount;
		MenorDeUnaMatriz (v,n-1,num);
		byte c=(n-1)%N;
		byte f=(n-1)/N;
		byte k=StrToInt(v->Cells[c][f]);
		if (k<num)
			num=k;
	}
}


void __fastcall TForm1::N361Click(TObject *Sender)
{
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	byte mayor=StrToInt(StringGrid1->Cells[0][0]);
	byte menor=StrToInt(StringGrid1->Cells[0][0]);
	MenorDeUnaMatriz (StringGrid1,n,menor);
	MayorDeUnaMatrizCarlos (StringGrid1,n,mayor);
	Edit1->Text=("El mayor es :"+IntToStr(mayor));
	Edit2->Text=("El menor es :"+IntToStr(menor));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	CargarA(StringGrid1, StringGrid1->RowCount, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------

void SerieFilasExamenA (TStringGrid *v,Byte ca,byte cb,Byte f,Byte num){
	if (ca==cb) {
		v->Cells[ca][f]=num;
	}else{
		v->Cells[ca][f]=num;
		num++;
		SerieFilasExamenA (v,ca+1,cb,f,num);
	}
}
void SerieExamenMadre(TStringGrid *m,Byte ca,byte f){
	if (f==0) {
		SerieFilasExamenA (m,ca,m->ColCount-1,f,1);
	}else{
		SerieFilasExamenA (m,ca,m->ColCount-1,f,1);
		SerieExamenMadre(m,ca+1,f-1);
	}
}

void __fastcall TForm1::N362Click(TObject *Sender)
{
	byte m=StrToInt(Edit1->Text);
	StringGrid1->ColCount = m;
	StringGrid1->RowCount =m;
	SerieExamenMadre(StringGrid1,0,StringGrid1->RowCount-1);
}
//---------------------------------------------------------------------------

void matrixFila( TStringGrid *A, short m, short n, short f, short c );
void matrixFila( TStringGrid *A, short m, short n ) {
  matrixFila( A, m, n, m - 1, n - 1 );
}
void matrixFila( TStringGrid *A, short m, short n, short f, short c ) {
  int k;
  short fa,ca;
  k = f * n + c + 1;                  //1  2  3  4  5
  if ( k > 0 ) {                     // 6  7  8  9 10
    if ( c == 0 ) {                 // 11 12 13 14 15
      fa = f - 1;                  //  16 17 18 19 20
      ca = n - 1;                 //   21 22 23 24 25
    }
    else {
      ca = c - 1;
      fa = f;
    }
    matrixFila( A, m, n, fa, ca );
    A->Cells[ c ][ f ] = k;
  }
}

void __fastcall TForm1::N381Click(TObject *Sender)
{
	int m = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = m;
	matrixFila(StringGrid1, m, n );
}
//---------------------------------------------------------------------------

void llenarMatrix3( TStringGrid *A, int f, int c, int k ) {
  int n;
  n = A->ColCount*A->RowCount-k;        //1 8  9 16
  A->Cells[c][f] = k;                  // 2 7 10 15
  if ( n > 0 ) {                      //  3 6 11 14
    if ( ( c % 2 ) == 0 ) {          //   4 5 12 13
      f++;
      if ( f == A->ColCount ) {
        c++;
        f = A->ColCount-1;
      }
    }
    else {
      f--;
      if ( f == - 1 ) {
        f = 0;
        c++;
      }
    }
    llenarMatrix3( A, f, c, k + 1 );
  }
}

void __fastcall TForm1::N382Click(TObject *Sender)
{
	int m = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = m;
	llenarMatrix3(StringGrid1, 0, 0, 1 );
}
//---------------------------------------------------------------------------

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

void __fastcall TForm1::N401Click(TObject *Sender)
{
   byte f,c,m=StrToInt(Edit1->Text);
   StringGrid1->ColCount=m;
   StringGrid1->RowCount=m;
   cargar2020_2(StringGrid1,m,m*m,f,c);
}
//---------------------------------------------------------------------------

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

void __fastcall TForm1::Seguimos6Click(TObject *Sender)
{
	int m = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = m;
	llenarMatrix(StringGrid1, 0, 0, 1 );
}
//---------------------------------------------------------------------------

void LlenarDesdeAvajo(TStringGrid *A,short m,short n,short f,short c,short k) {
  int p=m*n-k+1;
  if(p>0) {                    //4 5 12 13
    A->Cells[c][f]=k;         // 3 6 11 14
    if(c%2==0) {             //  2 7 10 15
      f--;                  //   1 8  9 16
      if(f<0) {
        f++;
        c++;
      }
    }
    else {
      f++;
      if(f==m) {
        f--;
        c++;
      }
    }
    LlenarDesdeAvajo(A,m,n,f,c,k+1);
  }
}

void LlenarDesdeAvajo(TStringGrid *A,short m,short n) {
  LlenarDesdeAvajo(A,m,n,m-1,0,1);
}

void __fastcall TForm1::N421Click(TObject *Sender)
{
	int m = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	StringGrid1->ColCount=n;
	StringGrid1->RowCount=m;
	LlenarDesdeAvajo(StringGrid1,m,n);
}
//---------------------------------------------------------------------------

void llenar_1( TStringGrid *A , int fila, int col ) {
    if(fila>0) {                                  //1 2 3 4 5
       llenar_1(A,fila-1,col);                   // 2 3 4 5
        for (int j=0;j<fila ;j++) {             //  3 4 5
          A->Cells[ fila - j - 1 ][ j ] = fila;//   4 5
        }                                     //    5
    }
}


void __fastcall TForm1::N422Click(TObject *Sender)
{
	int m = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = m;
	llenar_1(StringGrid1,m,n);
}
//---------------------------------------------------------------------------

void llenar_2( TStringGrid *A, int fila, int col ) {
    if(fila>0) {                                //1 2 3 4 5
        llenar_2(A,fila-1,col);                // 2 2 3 4 5
        for (int j=0;j<fila ;j++) {           //  3 3 3 4 5
          A->Cells[ j ][ fila - 1 ] = fila;  //   4 4 4 4 5
          A->Cells[ fila - 1 ][ j ] = fila; //    5 5 5 5 5
        }
    }
}

void __fastcall TForm1::N441Click(TObject *Sender)
{
	int m = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = m;
	llenar_2(StringGrid1,m,n);
}
//---------------------------------------------------------------------------

void llenar_3(TStringGrid *M,int n,int m) {
   if (n > 0) {                                //4 4 4 4
     llenar_3(M,n-1,m);                       // 4 3 3 3
     for (int j = 0; j < n; j++ ) {          //  4 3 2 2
       M->Cells[j][n - 1]= IntToStr(m - j); //   4 3 2 1
       M->Cells[n - 1][j]= IntToStr(m - j);
     }
   }
}

void __fastcall TForm1::N442Click(TObject *Sender)
{
  	int m = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = m;
	llenar_3(StringGrid1,m,n);
}
//---------------------------------------------------------------------------

void llenar_4(TStringGrid *M,int n,int m) {    //1 2 3 4 5
  if (n > 0)				                  // 2 1 2 3 4
	llenar_4(M,n-1, m);			             //	 3 2 1 2 3
	for (int j = 0; j < n; j++ ) { 	        //	 4 3 2 1 2
      M->Cells[j][n - 1]= IntToStr(n - j); //    5 4 3 2 1
      M->Cells[n - 1][j]= IntToStr(n - j);
    }
}
void llenar_4(TStringGrid *M,int n) {
  llenar_4(M,n,3);
}

void __fastcall TForm1::N461Click(TObject *Sender)
{
	int m = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	StringGrid1->ColCount = n;
	StringGrid1->RowCount = m;
	llenar_4(StringGrid1,m,n);
}
//---------------------------------------------------------------------------

/* Cargar la matriz A(m*n)

 4  3  2  1
 3  2  1  1
 2  1  1  1
 1  1  1  1
 */

void cargarColTri3(TStringGrid *v, byte f, byte ca, byte cb, byte k) {
	byte n = cb - ca + 1;
	if (n > 0) {
		v->Cells[ca][f] = k;
		if (k == 1) {
			cargarColTri3(v, f, ca + 1, cb, k);
		}
		else {
			cargarColTri3(v, f, ca + 1, cb, k - 1);
		}
	}
}

void cargarFilaTri3(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte k)
{
	byte m = fb - fa + 1;
	if (m > 0) {
		cargarColTri3(v, fa, ca, cb, k);
		cargarFilaTri3(v, fa + 1, fb, ca, cb, k - 1);
	}
}

void __fastcall TForm1::N471Click(TObject *Sender)
{
	 byte m = StrToInt(Edit1->Text);
	 byte n = StrToInt(Edit2->Text);
	//byte n = StrToInt(InputBox("ORDEN", "N�mero: ", ""));
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;
	cargarFilaTri3(StringGrid1, 0, n - 1, 0, n - 1, n);
}
//---------------------------------------------------------------------------

/* Cargar diagonal superior de una matriz serpiente

 1  7  8  10
 2  6  9
 3  5
 4
 */

void triangularFila3(TStringGrid *v, byte c, byte m, byte &k) {
	if (m > 0) {
		if (c % 2 == 1) {
			v->Cells[c][m - 1] = k++;
			triangularFila3(v, c, m - 1, k);
		}
		else {
			triangularFila3(v, c, m - 1, k);
			v->Cells[c][m - 1] = k++;
		}
	}
}

void triangular3(TStringGrid *v, byte m, byte n, byte &k) {
	if (n > 0) {
		triangular3(v, m + 1, n - 1, k);
		triangularFila3(v, n - 1, m, k);
	}
}

void __fastcall TForm1::N472Click(TObject *Sender)
{
	byte m = StrToInt(Edit1->Text);
	byte n = StrToInt(Edit2->Text);
	//byte n = StrToInt(InputBox("ORDEN", "N�mero: ", ""));
	byte k = 1;
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;
	triangular3(StringGrid1, 1, n, k);
}
//---------------------------------------------------------------------------

/* Cargar la matriz inferior A(n)

 10
 9   6
 8   5  3
 7   4  2  1
 */

int sumatoria(int n) {
	return n * (n + 1) / 2;
}

void cargarColumna(TStringGrid *SG, int col, int n, int k) {
	if (n > 0) {
		SG->Cells[col][col + n - 1] = sumatoria(k - col) - n + 1;
		cargarColumna(SG, col, n - 1, k);
	}
}

void cargarMatriz(TStringGrid *SG, int n, int k) {
	if (n > 0) {
		cargarMatriz(SG, n - 1, k);
		cargarColumna(SG, n - 1, k - n + 1, k);
	}
}

void __fastcall TForm1::N491Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text);
	StringGrid1->RowCount = n;
	StringGrid1->ColCount = n;
	cargarMatriz(StringGrid1, n, n);
}
//---------------------------------------------------------------------------

/* Cargar columnas A(n)

 3  2  1  2  3
 3  2  1  2  3
 3  2  1  2  3
 3  2  1  2  3
 3  2  1  2  3
 */

void aux_cargar_cols(TStringGrid *m, int f, int c, int v) {
	if (f > 0) {
		m->Cells[c - 1][f - 1] = v;
		m->Cells[m->ColCount - c][f - 1] = v;
		aux_cargar_cols(m, f - 1, c, v);
	}
}

void cargar_cols(TStringGrid *m, int f, int c, int v) {
	if (c > m->ColCount / 2) {
		aux_cargar_cols(m, f, c, v);
		cargar_cols(m, f, c - 1, v - 1);
	}
}

void __fastcall TForm1::N492Click(TObject *Sender)
{
	cargar_cols(StringGrid1, StringGrid1->RowCount, StringGrid1->ColCount,
	(StringGrid1->ColCount + 1) / 2);
}
//---------------------------------------------------------------------------

/* Cargar la navidad A(n)

	   1
	1  1  1
 1  1  1  1  1
	   1
	   1
 */

void aux_navidad(TStringGrid *m, int f, int ca, int cb) {
	if (ca < cb) {
		m->Cells[ca][f - 1] = 1;
		aux_navidad(m, f, ca + 1, cb);
	}
}

void navidad(TStringGrid *m, int f, int c) {
	if (f > 0) {
		if (f > (m->RowCount + 1) / 2) {
			int mitad = m->ColCount / 2;
			m->Cells[mitad][f - 1] = 1;
		}
		else {
			int nc = f * 2 - 1;
			int au = (m->ColCount - nc) / 2;
			int ca = au;
			int cb = au + nc;
			aux_navidad(m, f, ca, cb);
		}
		navidad(m, f - 1, c);
	}
}

void __fastcall TForm1::Seguimos8Click(TObject *Sender)
{
	navidad(StringGrid1, StringGrid1->RowCount, StringGrid1->ColCount);

}
//---------------------------------------------------------------------------

/* Cargar la triangular superior A(n)

 1  2  3  4
	1  2  3
	   1  2
		  1
 */

void aux_matriz(TStringGrid *m, int f, int c, int lim, int v) {
	if (c > lim) {
		m->Cells[c - 1][f - 1] = v;
		aux_matriz(m, f, c - 1, lim, v - 1);
	}
}

void matriz(TStringGrid *m, int f, int c) {
	if (f > 0) {
		int v = m->ColCount - f + 1;
		int lim = m->ColCount - v;
		aux_matriz(m, f, c, lim, v);
		matriz(m, f - 1, c);
	}
}

void __fastcall TForm1::N521Click(TObject *Sender)
{
	matriz(StringGrid1, StringGrid1->RowCount, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------

/* Escribir procesos para cargar una matriz de la siguiente forma:

 10
 9  8
 7  6  5
 4  3  2  1
 */

void aux_sec_inf2(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (c > 0) {
		Byte fil = f - 1;
		Byte col = c - 1;
		m->Cells[col][fil] = v;
		v++;
		aux_sec_inf2(m, f, c - 1, v);
	}
}

void diag_sec_inf2(TStringGrid* m, Byte f, Byte c, Cardinal &v) {
	if (f > 0) {
		aux_sec_inf2(m, f, c, v);
		diag_sec_inf2(m, f - 1, c - 1, v);
	}
}

void __fastcall TForm1::N522Click(TObject *Sender)
{
	StringGrid1->RowCount = StrToInt(Edit1->Text);
	StringGrid1->ColCount = StrToInt(Edit2->Text);
	Cardinal v = 1;
	Cardinal f = StringGrid1->RowCount;
	Cardinal c = StringGrid1->ColCount;
	diag_sec_inf2(StringGrid1, f, c, v);
}
//---------------------------------------------------------------------------

void llenarE1(TStringGrid *m,byte ac,int bc,byte af,byte k){
	if (ac<=bc) {
		m->Cells [bc][af]=k;
		llenarE1(m,ac,bc-1,af,k+1);
	}
}
void ejerE1(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (af<=bf) {
	llenarE1(m,ac,bc,af,k);
	ejerE1(m,ac,bc,af+1,bf,k+1);
}
}

void __fastcall TForm1::N541Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejerE1(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);

}
//---------------------------------------------------------------------------

void llenarE3(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenarE3(m,ac,bc-1,af,k);
}
}
void llenarE23(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenarE23(m,ac+1,bc,af,k);
}
}
void ejerE3(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (af<=bf) {
	if (b==true) {
		llenarE3(m,bc,bf,af,k);
		b=false;
	}else{
		llenarE23(m,bc,bf,af,k);
		b=true;
	}
	ejerE3(m,ac,bc-1,af+1,bf,k,b);
}
}
void ejer2E3(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (af<=bf) {
	if (b==true) {
		llenarE3(m,ac,bc,af,k);
		b=false;
	}else{
		llenarE23(m,ac,bc,af,k);
		b=true;
	}
	ejer2E3(m,ac-1,bc,af+1,bf,k,b);
}
}

void __fastcall TForm1::N542Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
   //	ejer2E3(StringGrid1,StringGrid1->ColCount-1,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
	ejerE3(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);

}
//---------------------------------------------------------------------------

void llenarEC5(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (af<=bf) {
	m->Cells [ac][af]=k;
	llenarEC5(m,ac,af+1,bf,k);
}
}
void llenarEF5(TStringGrid *m,byte ac,byte bc,byte bf,byte k){
if (ac<=bc) {
	m->Cells [ac][bf]=k;
	llenarEF5(m,ac+1,bc,bf,k);
}
}
void ejerE5(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (ac<=bc) {
	llenarEC5(m,ac,af,bf,k);
	llenarEF5(m,ac,bc-1,bf,k);
	if (ac!=bc) {
		k++;
		llenarEC5(m,bc,af,bf,k);
		llenarEF5(m,ac+1,bc,af,k);
	}
	ejerE5(m,ac+1,bc-1,af+1,bf-1,k+1);
}
}

void __fastcall TForm1::N561Click(TObject *Sender)
{
  StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	if (StrToInt(Edit1->Text)==1) {
		 StringGrid1->Cells [0][0]=1;
	}else{
	ejerE5(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);
	}
}
//---------------------------------------------------------------------------

void llenarT1(TStringGrid *m,byte k,int j,byte n,byte &c){
if (k<=n) {
	m->Cells [j][k]=c;
	c++;
	llenarT1(m,k+1,j-1,n,c);
}
}
void ejerT1(TStringGrid *m,byte ac,byte bc,byte &k){
if (ac<=bc){
		llenarT1(m,0,ac,ac,k);
		ejerT1(m,ac+1,bc,k);
}
}

void __fastcall TForm1::N562Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT1(StringGrid1,0,StringGrid1->ColCount-1,k);

}
//---------------------------------------------------------------------------

void llenarT2(TStringGrid *m,byte k,byte j,byte n,byte &c){
	if (n>0) {
		m->Cells[k][j]=c;
		c++;
		llenarT2(m,k-1,j+1,n-1,c);
}
}
void ejerT2(TStringGrid *m,byte ac,byte bc,byte bf,byte &k){
if (ac<=(bf)) {
		llenarT2(m,bf,ac,bc+1,k);
		ejerT2(m,ac+1,bc-1,bf,k);
}
}

void __fastcall TForm1::N581Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT2(StringGrid1,0,StringGrid1->ColCount-1,StringGrid1->ColCount-1,k);

}
//---------------------------------------------------------------------------

void llenar4C(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   llenar4C(m,c,f-1,k+1);
	   m->Cells [c-1][f-1]=k;
}
}
void ejer4(TStringGrid *m,byte ac,byte bc,byte f,byte k){
if (bc>=ac) {
	   ejer4(m,ac+1,bc,f,k-1);
	   llenar4C(m,ac,f,((f*k)-(f-1)));
}
}

void __fastcall TForm1::N582Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer4(StringGrid1,1,StringGrid1->ColCount,StringGrid1->RowCount,StringGrid1->ColCount);

}
//---------------------------------------------------------------------------

void llenar5C(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   llenar5C(m,c,f-1,k);
	   m->Cells[c-1][f-1]=k;
}
}
void ejer5(TStringGrid *m,byte c,byte f,byte k){
if (c>0) {
		ejer5(m,c-1,f,k-1);
		llenar5C(m,c,f,k);
}
}

void __fastcall TForm1::N601Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer5(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,StringGrid1->ColCount);

}
//---------------------------------------------------------------------------

void llenar6F(TStringGrid *m,byte c,byte f,byte k){
if (c>0) {
	   llenar6F(m,c-1,f,k);
	   m->Cells [c-1][f-1]=k;
}
}
void ejer6(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   ejer6(m,c,f-1,k-1);
	   llenar6F(m,c,f,k);
}
}

void __fastcall TForm1::N611Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer6(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,StringGrid1->ColCount);

}
//---------------------------------------------------------------------------

void llenar7C(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   llenar7C(m,c,f-1,k);
	   m->Cells [c-1][f-1]=k;
}
}
void ejer7(TStringGrid *m,byte c,byte f,byte k){
if (c>0) {
	   ejer7(m,c-1,f,k+1);
	   llenar7C(m,c,f,k);
}
}

void __fastcall TForm1::N612Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer7(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,1);

}
//---------------------------------------------------------------------------

void llenar8F(TStringGrid *m,byte c,byte f,byte k){
if (c>0) {
	llenar8F(m,c-1,f,k);
	m->Cells[c-1][f-1]=k;
}
}
void ejer8(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   ejer8(m,c,f-1,k+1);
	   llenar8F(m,c,f,k);
}
}

void __fastcall TForm1::N631Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer8(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,1);

}
//---------------------------------------------------------------------------

void llenar1L9(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (bf>=af){
		 llenar1L9(m,ac,af+1,bf,k);
		 m->Cells[ac][af]=k;
}
}
void llenar2l9(TStringGrid *m,byte ac,byte bc,byte bf,byte k){
if (bc>=ac){
	llenar2l9(m,ac+1,bc,bf,k);
	m->Cells [ac][bf]=k;
}
}
void ejer9(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k,byte n){
if (n>0){
	ejer9(m,ac+1,bc,af,bf-1,k+1,n-1);
	llenar1L9(m,ac,af,bf,k);
	llenar2l9(m,ac,bc,bf,k);
}
}

void __fastcall TForm1::N632Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer9(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1,StringGrid1->ColCount);

}
//---------------------------------------------------------------------------

void llenarF10(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	   llenarF10(m,ac+1,bc,af,k);
	   m->Cells [ac][af]=k;
}
}
void llenarC10(TStringGrid *m,byte bc,byte af,byte bf,byte k){
if (bf>=af) {
		llenarC10(m,bc,af+1,bf,k);
		m->Cells [bc][af]=k;

}
}
void ejer10(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte k){
if (n>0) {
	   ejer10(m,ac,bc-1,af+1,bf,n-1,k+1);
	   llenarF10(m,ac,bc,af,k);
	   llenarC10(m,bc,af,bf,k);
}
}

void __fastcall TForm1::N651Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer10(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,StringGrid1->ColCount,1);

}
//---------------------------------------------------------------------------

void llenarF11(TStringGrid *m,byte ac,byte bc,byte bf,byte k){
if (bc>=ac){
	llenarF11(m,ac+1,bc,bf,k);
	m->Cells[ac][bf]=k;
}
}
void llenarC11(TStringGrid *m,byte bc,byte af,byte bf,byte k){
 if (bf>=af) {
	llenarC11(m,bc,af+1,bf,k);
	m->Cells [bc][af]=k;
 }
}
void ejer11(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte k){
if (n>0) {
	ejer11(m,ac,bc-1,af,bf-1,n-1,k+1);
	llenarF11(m,ac,bc,bf,k);
	llenarC11(m,bc,af,bf,k);
}
}

void __fastcall TForm1::N661Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer11(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,StringGrid1->ColCount,1);

}
//---------------------------------------------------------------------------

void llenarF12(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	llenarF12(m,ac+1,bc,af,k);
	m->Cells [ac][af]=k;
}
}
void llenarC12(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (bf>=af){
	llenarC12(m,ac,af+1,bf,k);
	m->Cells[ac][af]=k;
}
}
void ejer12(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte k){
if (n>0) {
	ejer12(m,ac+1,bc,af+1,bf,n-1,k+1);
	llenarF12(m,ac,bc,af,k);
	llenarC12(m,ac,af,bf,k);
}
}

void __fastcall TForm1::N662Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer12(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,StringGrid1->ColCount,1);

}
//---------------------------------------------------------------------------

void llenar1F18(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenar1F18(m,ac,bc-1,af,k);
}
}
void llenar1C18(TStringGrid *m,byte ac,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [ac][af]=k;
	k++;
	llenar1C18(m,ac,af+1,bf,k);
}
}
void llenar2F18(TStringGrid *m,byte ac,byte bc,byte bf,byte &k){
if (ac<=bc) {
	m->Cells [ac][bf]=k;
	k++;
	llenar2F18(m,ac+1,bc,bf,k);
}
}
void llenar2C18(TStringGrid *m,byte bc,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [bc][bf]=k;
	k++;
	llenar2C18(m,bc,af,bf-1,k);
}
}
void ejer18(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte &k){
if (n>=k) {
	llenar1F18(m,ac,bc,af,k);
	llenar1C18(m,ac,af+1,bf,k);
	llenar2F18(m,ac+1,bc,bf,k);
	llenar2C18(m,bc,af+1,bf-1,k);
	ejer18(m,ac+1,bc-1,af+1,bf-1,n,k);
}
}

void __fastcall TForm1::N681Click(TObject *Sender)
{
 	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	ejer18(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,n,k);

}
//---------------------------------------------------------------------------

 void llenar1C19(TStringGrid *m,byte ac,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [ac][bf]=k;
	k++;
	llenar1C19(m,ac,af,bf-1,k);
}
}
void llenar1F19(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenar1F19(m,ac+1,bc,af,k);
}
}
void llenar2C19(TStringGrid *m,byte bc,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [bc][af]=k;
	k++;
	llenar2C19(m,bc,af+1,bf,k);
}
}
void llenar2F19(TStringGrid *m,byte ac,int bc,byte bf,byte &k){
if (ac<=bc) {
	m->Cells [bc][bf]=k;
	k++;
	llenar2F19(m,ac,bc-1,bf,k);
}
}
void ejer19(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte &k){
if (n>=k) {
	llenar1C19(m,ac,af,bf,k);
	llenar1F19(m,ac+1,bc,af,k);
	llenar2C19(m,bc,af+1,bf,k);
	llenar2F19(m,ac+1,bc-1,bf,k);
	ejer19(m,ac+1,bc-1,af+1,bf-1,n,k);
}
}

void __fastcall TForm1::N682Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	ejer19(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,n,k);

}
//---------------------------------------------------------------------------

void llenarT19(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenarT19(m,ac,bc-1,af,k);
}
}
void llenarT219(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
	if (ac<=bc) {
		m->Cells [ac][af]=k;
		k++;
		llenarT219(m,ac+1,bc,af,k);
	}
}
void ejerT19(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (af<=bf) {
	if (b==true) {
		llenarT19(m,ac,bc,af,k);
		b=false;
	}else{
		llenarT219(m,ac,bc,af,k);
		b=true;
	}
	ejerT19(m,ac,bc-1,af+1,bf,k,b);
}
}

void __fastcall TForm1::N701Click(TObject *Sender)
{
 	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT19(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);

}
//---------------------------------------------------------------------------
