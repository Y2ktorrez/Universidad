//---------------------------------------------------------------------------

#ifndef VectoresH
#define VectoresH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Vcl.Grids.hpp>

Cardinal Suma(TStringGrid *v, Word n);

Cardinal SumaPares(TStringGrid *v, Word n);
Cardinal SumaImpares(TStringGrid *v, Word n);

bool ExisteElemento(TStringGrid *v, Word a, Word b, Word elemento);

AnsiString Vocales(AnsiString cadena);
void CargarVocales(TStringGrid *v, AnsiString cadena);
void CargarVocales_2(TStringGrid *v, AnsiString cadena);

AnsiString UltimasLetras(TStringGrid *v, Word n);

AnsiString LetraMayuscula(AnsiString cadena);
void CargarPalabras(TStringGrid *v, AnsiString cadena);

void CargarPalabra(TStringGrid *v, AnsiString cadena);

AnsiString PrimerasLetras(TStringGrid *v, Word n);

void Cargar_Vocales(TStringGrid *v, AnsiString cadena);

void CargarCadenaInvertida(TStringGrid *v, AnsiString cadena);

AnsiString SinVocales(AnsiString cadena);
void CargarSinVocales(TStringGrid *v, AnsiString cadena);

void GenerarNumeros(TStringGrid *v, Word n, unsigned long long &num);

void MayorAlFinal(TStringGrid *v, Word n);
void OrdenarAsc(TStringGrid *v, Word n);

void MayorAlInicio(TStringGrid *v, Word n);
void OrdenarDesc(TStringGrid *v, Word n);

void MayorAlFinalSeg(TStringGrid *v, Word a, Word b);
void OrdenarSegmentoAsc(TStringGrid *v, Word a, Word b);

void InvertirSegmento(TStringGrid *v, Word a, Word b);

void Eliminar(TStringGrid* v, Cardinal pos);
void EliminarElemento(TStringGrid *v, Word n, Word elemento);

void EliminarElementos(TStringGrid *v, byte a, byte b);

byte CantidadVocales(AnsiString cadena);
Cardinal Cantidad_Vocales(TStringGrid *v, Word n);

byte CantidadPrimos(Cardinal x);
Cardinal Cantidad_Primos(TStringGrid *v, Word n);

byte SumaParesIterativo(TStringGrid *v, Word n);
byte SumaParesRecursivo(TStringGrid *v, Word n);

#endif
