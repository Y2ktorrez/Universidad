﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cadenas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Algoritmo que devuelve la cantidad de vocales de una cadena
// Ejemplo: x = "Hola a todos" ==> 5

bool EsVocal(char z) {
	AnsiString vocales = "aeiouAEIOU������������";
	return vocales.Pos(z) > 0;
}

byte CantidadVocales(AnsiString cadena) {
	byte cantidad;
	if (cadena == "") {
		cantidad = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		cantidad = CantidadVocales(cadena);
		if (EsVocal(z)) {
			cantidad++;
		}
	}
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo para invertir una cadena
// Ejemplo: x = "Anita lava la tina" ==> x = "anit al aval atinA"

void InvertirCadena(AnsiString &cadena) {
	if (cadena == "") {

	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		InvertirCadena(cadena);
		cadena = cadena + z;
	}
}

void InvertirCadena_2(AnsiString &cadena) {
	byte n = cadena.Length();
	if (cadena.IsEmpty()) {
		cadena = "";
	} else {
		char z = cadena[n];
		cadena.Delete(n, 1);
		InvertirCadena_2(cadena);
		cadena = AnsiString(z) + cadena;
	}
}

void InvertirCadena_3(AnsiString &cadena) {
	byte n = cadena.Length();
	if (!cadena.IsEmpty()) {
		if (n > 1) {
			char z1 = cadena[1];
			char z2 = cadena[n];
			cadena.Delete(n, 1);
			cadena.Delete(1, 1);
			InvertirCadena_3(cadena);
			cadena = AnsiString(z2) + cadena + z1;
		}
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que invierte cada palabra de una cadena
// Ejemplo: x = "Esta es una prueba m�s" ==> x = "atsE se anu abeurp s�m"

void InvertirPalabras(AnsiString &cadena) {
	if (cadena.IsEmpty()) {

	} else {
		byte n = cadena.Length();
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		InvertirPalabras(cadena);
		InvertirCadena(palabra);
		cadena = cadena + palabra + " ";
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la palabra mas larga de una cadena
// Ejemplo: x = "Esta fant�stico esto" ==> fant�stico

AnsiString PalabraMasLarga(AnsiString cadena) {
	byte n = cadena.Length();
	AnsiString palabraLarga;
	if (cadena.IsEmpty()) {
		palabraLarga = "";
	} else {
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		palabraLarga = PalabraMasLarga(cadena);
		if (palabra.Length() > palabraLarga.Length()) {
			palabraLarga = palabra;
        }
	}
	return palabraLarga;
}
// ---------------------------------------------------------------------------
// Algoritmo para eliminar la primera letra de cada palabra
// Ejemplo: x = "hola como estas" ==> x = "ola omo stas"

void EliminarPrimerLetra(AnsiString &cadena) {
	if (cadena.IsEmpty()) {
		cadena = "";
	} else {
		byte n = cadena.Length();
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		EliminarPrimerLetra(cadena);
		palabra.Delete(1,1);
		cadena = cadena + " " + palabra;
		cadena = cadena.TrimLeft();
    }
}

void EliminarPrimerLetra_2(AnsiString &cadena) {
	if (cadena == "") {

	} else {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
		}
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		EliminarPrimerLetra_2(cadena);
		palabra.Delete(1,1);
		cadena = palabra + " " + cadena;
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que verifica si una palabra es palindrome
// Ejemplo: x = "somos" ==> true

bool EsPalindrome(AnsiString cadena) {
	bool result;
	byte n = cadena.Length();
	if (n <= 1) {
		result = true;
	} else {
		char izq = cadena[1];
		char der = cadena[n];
		if (izq != der) {
			result = false;
		} else {
			AnsiString nueva = cadena.SubString(2, n - 2);
			result = EsPalindrome(nueva);
		}
	}
	return result;
}
// ---------------------------------------------------------------------------
// Algoritmo que invierte el orden de las palabras en una cadena
// Ejemplo: x = "Esta es una prueba" ==> x = "prueba una es Esta"

void InvertirOrden(AnsiString &cadena) {
	byte n = cadena.Length();
	if (cadena.IsEmpty()) {
		cadena = "";
	} else {
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		InvertirOrden(cadena);
		cadena = palabra + " " + cadena;
		cadena = cadena.TrimRight();
	}
}

void InvertirOrden_2(AnsiString &cadena) {
	if (cadena != "") {
		byte pos = cadena.Pos(" ");
		if (pos == 0) {
			pos = cadena.Length() + 1;
        }
		AnsiString palabra = cadena.SubString(1, pos - 1);
		cadena.Delete(1, pos);
		InvertirOrden_2(cadena);
		cadena = cadena + " " + palabra;
		cadena = cadena.TrimLeft();
	}
}
// ---------------------------------------------------------------------------
// Algoritmo para verificar si una palabra pertenece a una cadena
// Ejemplo: x = "Hola como estan", p = "como" ==> true

bool ExistePalabra(AnsiString cadena, AnsiString palabra) {
	byte n = cadena.Length();
	bool result;
	if (cadena.IsEmpty()) {
		result = false;
	} else {
		byte pos = cadena.LastDelimiter(" ");
		AnsiString pal = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		result = ExistePalabra(cadena, palabra);
		if (palabra == pal ) {
			result = true;
        }
	}
	return result;
}
// ---------------------------------------------------------------------------
// Algoritmo que elimina la primera y ultima letra de una palabra
// Ejemplo: x = "Buenos dias a todos" ==> x = "ueno ia a odo"

void EliminarPriUltLetra(AnsiString &cadena) {
	byte n = cadena.Length();
	if (cadena.IsEmpty()) {

	} else {
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		EliminarPriUltLetra(cadena);
		byte x = palabra.Length();
		if (x > 1) {
			palabra.Delete(x, 1);
			palabra.Delete(1, 1);
		}
		cadena = cadena + " " + palabra;
		cadena = cadena.Trim();
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve el numero mayor de una cadena
// Ejemplo: x = "hola104 mundo54 como1 estan" ==> 104

bool EsDigito(char z) {
	return (z >= '0') && (z <= '9');
}

AnsiString PrimerNumero(AnsiString cadena) {
	AnsiString numero;
	if (cadena.IsEmpty()) {
		numero = "";
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		if (!EsDigito(z)) {
			numero = PrimerNumero(cadena);
		} else {
			if ((cadena != "") && (EsDigito(cadena[1]))) {
				numero = AnsiString(z) + PrimerNumero(cadena);
			} else {
				numero = AnsiString(z);
			}
		}
	}
	return numero;
}

Cardinal NumeroMayor(AnsiString cadena) {
	Cardinal mayor;
	if (cadena.IsEmpty()) {
		mayor = 0;
	} else {
		AnsiString z = PrimerNumero(cadena);
		if (!z.IsEmpty()) {
			cadena.Delete(1, cadena.Pos(z) + z.Length() - 1);
			mayor = NumeroMayor(cadena);
			if (StrToInt(z) > mayor) {
				mayor = StrToInt(z);
			}
		} else {
			mayor = 0;
		}
	}
	return mayor;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve el numero menor de una cadena
// Ejemplo: x = "hola104 mundo54 como1 estan" ==> 1

AnsiString UltimoNumero(AnsiString cadena) {   // no funciona
	AnsiString numero;
	byte n = cadena.Length();
	if (cadena.IsEmpty()) {
		numero = "";
	} else {
		char z = cadena[n];
		cadena.SetLength(n - 1);
		if (!EsDigito(z)) {
			numero = UltimoNumero(cadena);
		} else {
			byte x = cadena.Length();
			if ((cadena != "") && EsDigito(cadena[x])) {
				numero = UltimoNumero(cadena) + z;
			} else {
				numero = AnsiString(z);
			}
        }
    }
	return numero;
}

Cardinal NumeroMenor(AnsiString cadena) {
	Cardinal menor;
	byte n = cadena.Length();
	if (cadena.IsEmpty()) {
		menor = 0;
	} else {
		AnsiString z = PrimerNumero(cadena);
		if (!z.IsEmpty()) {
			cadena.Delete(1, cadena.Pos(z) + z.Length() - 1);
			menor = NumeroMenor(cadena);
			if (StrToInt(z) < menor) {
				menor = StrToInt(z);
			}
		} else {
			menor = 0;
		}
    }
	return menor;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la cantidad de palabras
//Ejemplo: x = "Hola mundo genial" ==> 3

byte CantidadPalabras(AnsiString cadena) {
	byte cantidad;
	byte n = cadena.Length();
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		 byte pos = cadena.LastDelimiter(" ");
		 AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		 cadena.SetLength(pos - 1);
		 cantidad = CantidadPalabras(cadena);
		 if (!(palabra >= '0' && palabra <= '9')) {
			  cantidad++;
		 }
	}
	return cantidad;
}
// ---------------------------------------------------------------------------



// Algoritmo que devuelve la cantidad de letras de una cadena
// Ejemplo: x = "Hola a todos" ==> 10

Word CantidadLetras(AnsiString cadena) {
	Word cantidad;
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		cantidad = CantidadLetras(cadena);
		if (!(z >= '0' && z <= '9') && z != ' ') {
			cantidad++;
		}
	}
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve una cadena con los digitos de una cadena
// Ejemplo: x = "hola54 como12 estan" ==> 5412

void CadenaDigitos(AnsiString &cadena) {
	if (cadena.IsEmpty()) {

	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		CadenaDigitos(cadena);
		if (z >= '0' && z <= '9') {
			cadena = AnsiString(z) + cadena;
        }
    }
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la cantidad de espacios de una cadena
// Ejemplo: x = "hola como estan todos " ==> 4

byte CantidadEspacios(AnsiString cadena) {
	byte cantidad;
	byte n = cadena.Length();
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		byte pos = cadena.LastDelimiter(" ");
		cadena.SetLength(pos - 1);
		cantidad = CantidadEspacios(cadena);
		if (pos > 0) {
			cantidad++;
		}
    }
	return cantidad;
}

byte CantidadEspacios_2(AnsiString cadena) {
	byte cantidad;
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		cantidad = CantidadEspacios_2(cadena);
		if (z == ' ') {
			cantidad++;
        }
    }
	return cantidad;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la suma de los digitos de una cadena
// Ejemplo: x "hola123 como4 es4tas2" ==> 16

Word SumaDigitos(AnsiString cadena) {
	Word suma;
	if (cadena.IsEmpty()) {
		suma = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		suma = SumaDigitos(cadena);
		if (z >= '0' && z <= '9') {
			suma = suma + StrToInt(z);
		}
	}
	return suma;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve una cadena de digitos pares y digitos impares
// Ejemplo: x = "hola723 co5mo 8 esta1s4" ==> 284

void CadenaPares(AnsiString &cadena) {
	AnsiString pares;
	if (!cadena.IsEmpty()) {
		char z = cadena[1];
		cadena.Delete(1, 1);
		CadenaPares(cadena);
        if ((z >= '0' && z <= '9') && (StrToInt(z) % 2 == 0)) {
			pares = pares + z;
		}
		cadena = pares + cadena;
	}
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve la palabra mas corta de una cadena
// Ejemplo: x = "Este milenio es complicado" ==> es

AnsiString PalabraMasCorta(AnsiString cadena) {
	AnsiString palabraCorta;
	byte n = cadena.Length();
	cadena = cadena.Trim();
	if (cadena.IsEmpty()) {
		palabraCorta = "";
	} else {
		byte pos = cadena.LastDelimiter(" ");
		AnsiString palabra = cadena.SubString(pos + 1, n - pos);
		cadena.SetLength(pos - 1);
		palabraCorta = PalabraMasCorta(cadena);
		if (palabraCorta.Length() == 0) {
			palabraCorta = palabra;
		}
		if (palabraCorta.Length() > palabra.Length()) {
			palabraCorta = palabra;
		}
	}
	return palabraCorta;
}
// ---------------------------------------------------------------------------
// Algoritmo que devuelve el numero de caracteres que no son
// del alfabeto, digitos numericos o espacio
// Ejemplo: x = "Hola-& mund0 -#123" ==> 4

Cardinal CantidadCaracter(AnsiString cadena) {
	Cardinal cantidad;
	if (cadena.IsEmpty()) {
		cantidad = 0;
	} else {
		char z = cadena[1];
		cadena.Delete(1, 1);
		cantidad = CantidadCaracter(cadena);
		if (!(tolower(z) >= 'a' && tolower(z) <= 'z')
			&& !(z >= '0' && z <= '9') && (z != ' ')) {
			cantidad++;
		}
    }
	return cantidad;
}
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
