//---------------------------------------------------------------------------

#ifndef matrizH
#define matrizH
//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>

#include <System.Classes.hpp>
#include <Vcl.Grids.hpp>
//contreras

void cargarTipoVector(TStringGrid*v,byte N);

void Magico(TStringGrid *A, byte m, byte n, byte &f, byte &c);
void Magicov1(TStringGrid *A, byte m,byte k, byte &i,byte &j);

void cargarDentroToFueraCol(TStringGrid *v, byte f, byte ca, byte cb, byte x);
void cargarDentroToFuera(TStringGrid *v, byte fa,byte fb);

void llenarf1(TStringGrid*v,byte f,byte ca,byte cb,byte &k);
void llenarc2(TStringGrid*v,byte fa,byte fb,byte cb,byte &k);
void llenarf2(TStringGrid*v,byte fa,byte ca,byte cb,byte &k);
void llenarc1(TStringGrid*v,byte fa,byte fb,byte ca,byte &k);
void cargar2019_2B(TStringGrid*v,byte fa,byte fb,byte ca,byte cb,byte &k);

void cargarFila2019_32(TStringGrid *v, byte fa, byte fb, byte ca, byte cb, byte &z);
void cargarCol2019_32(TStringGrid *v, byte ca, byte cb, byte f, byte &z);

void cargar2020_1Segunda(TStringGrid *v, byte m, byte k, byte &f, byte &c);

void cargar2020_2(TStringGrid *v, byte m, byte k, byte &f, byte &c);

void cargarCol2021_1(TStringGrid *v, byte f, byte ca, byte cb, byte x);
void cargarFila2021_1(TStringGrid *v, byte fa, byte fb, byte ca, byte cb);

void MayorMenorFil2021_2(TStringGrid *v,byte f, byte c, byte &men, byte &may);
void MayorMenorCol2021_2(TStringGrid *v,byte f, byte c, byte &men, byte &may);
//2021-3 ^ 2022-1
void cargarCol2022_1(TStringGrid *v, byte f, byte ca, byte cb);
void cargarFila2022_1(TStringGrid *v, byte f, byte c);
//2022-1B
void cargarCol2022_1B(TStringGrid *v, byte i, byte j, byte fa, byte fb);
void cargarFila2022_1B(TStringGrid *v, byte f, byte c);
//caracol
void cargarCaracol(TStringGrid*v,byte fa,byte fb,byte ca,byte cb,byte &k);
void llenarc1Inf(TStringGrid*v,byte c,byte fa,byte fb,byte &k);
void llenarf2Der(TStringGrid*v,byte f,byte ca,byte cb,byte &k);
void llenarc2Sup(TStringGrid*v,byte c, byte fa,byte fb,byte &k);
void llenarf1Izq(TStringGrid*v,byte f,byte ca,byte cb,byte &k);

//dunnia
void cargarM1(TStringGrid * v, int f, int c, int m, int x);
void cargarM2(TStringGrid * v, int f, int c, int m, int x);
void cargarM(TStringGrid * v,int m, int f, int ca, int k);
void cargar2022_1(TStringGrid * M,int m, int f, int c, int &x);

//---------------------------------------------------------------------------

#endif