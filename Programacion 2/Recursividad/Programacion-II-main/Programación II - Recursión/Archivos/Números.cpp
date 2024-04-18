// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Números.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// Factorial de un n�mero

Cardinal factorial(byte n) {
	Cardinal f;
	if (n == 0) {
		f = 1;
	}
	else {
		f = n * factorial(n - 1);
	}
	return f;
}
// ---------------------------------------------------------------------------
// Potencia de un n�mero  (no funcina bien)

Cardinal auxPotencia(byte n) {
	return (int)(pow(10, n) - 1) / 9 * n;
}

Cardinal potencia(Cardinal n) {
	Cardinal p;
	if (n < 10) {
		p = auxPotencia(n);
	}
	else {
		p = potencia(n / 10);
		Cardinal d = auxPotencia(n % 10);
		p = p * (int)pow(10, n % 10) + d;
	}
	return p;
}
// ---------------------------------------------------------------------------
// Potencia de un N�mero

Cardinal Potencia(int numero, byte exp) {
	Cardinal resultado;
	if (exp == 0) {
		resultado = 1;
	}
	else {
		resultado = Potencia(numero, exp / 2);
		if (exp % 2 == 0)
			resultado = resultado * resultado;
		else
			resultado = numero * resultado * resultado;
	}
	return resultado;
}
// ---------------------------------------------------------------------------
/* Repetir el mismo numero su misma cantidad

 Ej: n = 22331
 r = 22223333331
 */

String Repetir(Cardinal n, Cardinal v) {
	String resultado;
	if (n == 0) {
		resultado = "";
	}
	else {
		resultado = Repetir(n - 1, v);
		resultado = resultado + String(v);
	}
	return resultado;
}

String Literal(Cardinal n) {
	String resultado;
	if (n < 10) {
		resultado = Repetir(n, n);
	}
	else {
		byte digito = n % 10;
		resultado = Literal(n / 10);
		resultado = resultado + Repetir(digito, digito);
	}
	return resultado;
}

// ---------------------------------------------------------------------------
/* Escribir una funci�n que devuelva la cantidad de d�gitos pares
 que est�n inmediatamente antes de uno impar.

 Ej. CantDigPares(3827435) ==> 2 */

Byte Cantidad_Pares(Cardinal n) {
	byte cantidad;
	if (n < 10) {
		cantidad = 0;
	}
	else {
		byte der = n % 10;
		n = n / 10;
		cantidad = Cantidad_Pares(n);
		byte izq = n % 10;
		if (izq % 2 == 0 && der % 2 == 1) {
			cantidad++;
		}
	}
	return cantidad;
}
// ---------------------------------------------------------------------------

byte CantDigPares(Cardinal numero) {
	byte cantidad;
	if (numero < 10) {
		cantidad = 0;
	}
	else {
		byte digito = numero % 10;
		cantidad = CantDigPares(numero / 10);
		if ((((numero / 10) % 2) == 0) & ((digito % 2) != 0)){
			cantidad++;
		}
	}
	return cantidad;
}
// ---------------------------------------------------------------------------

byte parAntesImpar(Cardinal n) {
	byte c;
	if (n < 10) {
		c = 0;
	}
	else if (n < 100) {
		if ((n / 10) % 2 == 0 && (n % 10) % 2 == 1) {
			c = 1;
		}
		else {
			c = 0;
		}
	}
	else {
		c = parAntesImpar(n / 10) + parAntesImpar(n % 100);
	}
	return c;
}
// ---------------------------------------------------------------------------
/* Escribir un proceso que lleve el mayor de los d�gitos al final de
 un n�mero.

 Ej.   x=382731;

 MoverMayor(x);
 // x=327318 */

void Recorrer(Cardinal &n, Cardinal pos) {
	Cardinal len = log10(n) + 1;
	Cardinal div = pow(10, len - pos);
	Cardinal der = n % div;
	Cardinal izq = n / div;
	Cardinal may = izq % 10;
	izq = izq / 10;
	Cardinal lenDer = log10(der) + 1;
	Cardinal pot1 = pow(10, lenDer);
	izq = izq * pot1 + der;
	Cardinal pot2 = pow(10, len - 1);
	n = may * pot2 + izq;
}

Cardinal Posicion_Mayor(Cardinal n) {
	Cardinal pos;
	if (n < 10)
		pos = 1;
	else {
		Cardinal dig = n % 10;
		// n = n / 10;
		pos = Posicion_Mayor(n / 10);
		Cardinal aux = n;
		Cardinal lenAux = log10(aux) + 1;
		Cardinal divisor = pow(10, lenAux - pos);
		aux = aux / divisor;
		Cardinal digMayor = aux % 10;
		if (dig > digMayor)
			pos = log10(n) + 1;
	}
	return pos;
}

void Mover_Mayor(Cardinal &n) {
	Cardinal pos = Posicion_Mayor(n);
	Recorrer(n, pos);
}
// ---------------------------------------------------------------------------

void MoverMayor(Cardinal &numero) {
	if (numero > 9) {
		byte ultimo = numero % 10;
		Cardinal aux = numero / 10;
		Mover_Mayor(aux);
		byte digitoFinal = aux % 10;
		if (ultimo < digitoFinal) {
			numero = aux / 10;
			numero = numero * 10 + ultimo;
			numero = numero * 10 + digitoFinal;
		}
		else {
			numero = aux * 10 + ultimo;
		}
	}
}

// ---------------------------------------------------------------------------
// Suma de N�meros Binarios

Cardinal suma_bin(Cardinal a, Cardinal b, Cardinal carry, Cardinal r) {
	Cardinal sumaBin = 0;
	if (a > 0 || b > 0 || carry > 0) {
		Cardinal da = a % 10;
		Cardinal db = b % 10;
		Cardinal sum = da + db + carry;
		if (sum == 2)
			sum = 10;
		else if (sum == 3)
			sum = 11;
		Cardinal dig = sum % 10;
		carry = sum / 10;
		Cardinal p = r * dig;
		Cardinal bin = suma_bin(a / 10, b / 10, carry, r * 10);
		sumaBin = bin + p;
		// sumaBin = suma_bin(a / 10, b / 10, carry, r * 10) + (r * dig);
	}
	return sumaBin;
}

Cardinal suma_binarios(Cardinal a, Cardinal b) {
	return suma_bin(a, b, 0, 1);
}
// ----------------------------------------------------------------------------

byte sumaDigitosBinarios(byte a, byte b) {
	return (a + b) / 2 * 10 + (a + b) % 2;
}

Cardinal sumaBinaria(Cardinal a, Cardinal b, byte c = 0) {
	Cardinal s;
	byte d = sumaDigitosBinarios(a % 10, b % 10);
	d = (d / 10) * 10 + sumaDigitosBinarios(d % 10, c);
	if (a < 2 && b < 2) {
		s = d;
	}
	else {
		s = sumaBinaria(a / 10, b / 10, d / 10);
		s = s * 10 + d % 10;
	}
	return s;
}
// ---------------------------------------------------------------------------
// Invertir un N�mero

byte Cantidad_Digitos(Cardinal n) {
	byte cantidad;
	if (n == 0) {
		cantidad = 1;
	}
	else {
		cantidad = (int)log10(10 * n);
	}
	return cantidad;
}

void Invertir(Cardinal &n) {
	if (n > 9) {
		Cardinal dig = n % 10;
		n = n / 10;
		Invertir(n);
		n = dig * (int)pow(10, Cantidad_Digitos(n)) + n;
	}
}
// ---------------------------------------------------------------------------
// falla algo

void InvertirNumero(Cardinal &n) {
	byte dig, cantidad_digitos;
	if (n > 0) {
		dig = n % 10;
		n = n / 10;
		cantidad_digitos = int(log10(10 * n));
		InvertirNumero(n);
		n = n + pow(10, cantidad_digitos) * dig;
	}
}

// ---------------------------------------------------------------------------
// Cantidad de Digitos que tiene un N�mero

int Cantidad_Digitos(int numero) {
	int resultado;
	if (numero < 10) {
		resultado = 1;
	}
	else {
		resultado = Cantidad_Digitos(numero / 10) + 1;
	}
	return resultado;
}

// ---------------------------------------------------------------------------
// Mover el digito mayor al inicio

void Mover_Mayor_Final(Cardinal & n) {
	if (n > 9) {
		byte dig = n % 10;
		n = n / 10;
		Mover_Mayor_Final(n);
		if (n % 10 > dig) {
			n = (n / 10) * 100 + dig * 10 + n % 10;
		}
		else {
			n = n * 10 + dig;
		}
	}
}
// ---------------------------------------------------------------------------
// Ordena un n�mero en forma ascendente

void Mover_Menor_Final(Cardinal & n) {
	if (n > 9) {
		byte dig = n % 10;
		n = n / 10;
		Mover_Menor_Final(n);
		if (n % 10 < dig) {
			n = (n / 10) * 100 + dig * 10 + n % 10;
		}
		else {
			n = n * 10 + dig;
		}
	}
}

void Ordenar(Cardinal & n) {
	if (n > 9) {
		Mover_Mayor_Final(n);
		byte dig = n % 10;
		n = n / 10;
		Ordenar(n);
		n = n * 10 + dig;
	}
}
// ---------------------------------------------------------------------------
// Convertir base decimal a binario

Cardinal Conversion_Binario(Cardinal n) {
	Cardinal resultado;
	if (n < 2) {
		resultado = n;
	}
	else {
		resultado = Conversion_Binario(n / 2);
		resultado = resultado * 10 + n % 2;
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Conversi�n de bases

String w = "0123456789ABCDEF";

String Conversion_Bases(Cardinal n, byte base) {
	String r;
	if (n < base) {
		r = String(w[n + 1]);
	}
	else {
		r = Conversion_Bases(n / base, base) + w[n % base + 1];
	}
	return r;
}
// ---------------------------------------------------------------------------
/* Devolver el digito mayor y menor de un n�mero

 Ej: n = 72145
 r = 71
 */

byte digitoMayorMenor(Cardinal n) {
	byte m;
	if (n < 10) {
		m = n * 11;
	}
	else {
		m = digitoMayorMenor(n / 10);
		byte d = n % 10;
		if (d < m % 10) {
			m = (m / 10) * 10 + d;
		}
		if (d > m / 10) {
			m = d * 10 + m % 10;
		}
	}
	return m;
}
// ---------------------------------------------------------------------------
// Digito mayor de un n�mero

byte digitoMayor(Cardinal n) {
	byte d;
	if (n < 10) {
		d = n;
	}
	else {
		d = digitoMayor(n / 10);
		if (n % 10 > d) {
			d = n % 10;
		}
	}
	return d;
}
// ---------------------------------------------------------------------------

byte DigitoMayor(Cardinal x) {
	byte resultado;
	if (x < 10) { // Caso Base
		resultado = x;
	}
	else { // Caso General
		resultado = DigitoMayor(x / 10);
		if (x % 10 > resultado) {
			resultado = x % 10;
		}
	}
	return resultado;
}

// ---------------------------------------------------------------------------
// Verificar si un n�mero esta ordenado ascendentemente

bool estaOrdenadoAsc(Cardinal n) {
	bool h;
	if (n < 10) {
		h = true;
	}
	else {
		byte d = n % 10;
		n /= 10;
		// h = estaOrdenadoAsc(n) && !(n%10 > d);
		h = estaOrdenadoAsc(n);
		if (n % 10 > d) {
			h = false;
		}
	}
	return h;
}
// ---------------------------------------------------------------------------
// Verificar si un n�mero esta ordenado descendentemente

bool estaOrdenadoDesc(Cardinal n) {
	bool h;
	if (n < 10) {
		h = true;
	}
	else {
		byte d = n % 10;
		n /= 10;
		// h = estaOrdenadoAsc(n) && !(n%10 > d);
		h = estaOrdenadoDesc(n);
		if (n % 10 < d) {
			h = false;
		}
	}
	return h;
}
// ---------------------------------------------------------------------------
// Cantidad de digitos pares de un n�mero

byte cantidadPares(Cardinal n) {
	byte c;
	if (n < 10) {
		c = (n % 2 == 0) ? 1 : 0;
	}
	else {
		c = cantidadPares(n / 10) + cantidadPares(n % 10);
	}
	return c;
}
// ---------------------------------------------------------------------------

byte CantidadPares(Cardinal x) {
	byte resultado;
	if (x < 10) {
		if (x % 2 == 0) {
			resultado = 1;
		}
		else {
			resultado = 0;
		}
	}
	else {
		resultado = CantidadPares(x / 10);
		if (x % 2 == 0) {
			resultado = resultado + 1;
		}
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Cantidad de digitos impares de un n�mero

byte CantidadImpares(Cardinal x) {
	byte resultado;
	if (x < 10) {
		if (x % 2 == 1) {
			resultado = 1;
		}
		else {
			resultado = 0;
		}
	}
	else {
		resultado = CantidadImpares(x / 10);
		if (x % 2 == 1) {
			resultado = resultado + 1;
		}
	}
	return resultado;
}

// ---------------------------------------------------------------------------
// Suma de los digitos de un n�mero

Word sumaDigitos(Cardinal numero) {
	Word suma;
	if (numero < 9) {
		suma = numero;
	}
	else {
		byte dig = numero % 10;
		numero = numero / 10;
		suma = sumaDigitos(numero);
		suma += dig;
	}
	return suma;
}

// ---------------------------------------------------------------------------
// Suma de los digitos pares de un n�mero

Word sumaPares(Cardinal n) {
	Word s;
	if (n < 10) {
		s = (n % 2 == 0) ? n : 0;
	}
	else {
		s = sumaPares(n / 10) + sumaPares(n % 10);
	}
	return s;
}
// ---------------------------------------------------------------------------

byte Suma_Digitos_Pares(Cardinal numero) {
	byte resultado;
	if (numero < 10) {
		if (numero % 2 == 0)
			resultado = numero;
		else
			resultado = 0;
	}
	else {
		resultado = Suma_Digitos_Pares(numero / 10);
		if (numero % 2 == 0)
			resultado = resultado + numero % 10;
	}
	return resultado;
}
// Suma de los digitos primos de un n�mero

Word sumaDigitosPrimos(Cardinal numero) {
	if (numero >= 0) {
		if (numero == 0) {
			return 0;
		}
		else {
			int ultimoDigito = numero % 10;
			int result = sumaDigitosPrimos(numero / 10);
			if ((ultimoDigito == 2) || (ultimoDigito == 3) ||
				(ultimoDigito == 5) || (ultimoDigito == 7)) {
				result += ultimoDigito;
			}
			return result;
		}
	}
	else {
		return -1;
	}
}
// ---------------------------------------------------------------------------
// Cantidad de digitos primos en un numero

Word CantidadPrimos(Cardinal num) {
	String primos = "12357";
	byte contador;
	if (num < 10) {
		if (num == 1 || num == 2 || num == 3 || num == 5 || num == 7) {
			contador = 1;
		}
		else {
			contador = 0;
		}
	}
	else {
		byte dig = num % 10;
		num = num / 10;
		contador = CantidadPrimos(num);
		byte pos = primos.Pos(String(dig));
		if (pos > 0) {
			contador++;
		}
	}
	return contador;
}

// ---------------------------------------------------------------------------
// Diferencia entre Digitos Pares y Digitos Impares

short int DifParImpar(Cardinal numero) {
	short int resultado;
	if (numero < 10) {
		if (numero % 2 == 0)
			resultado = numero;
		else
			resultado = -numero;
	}
	else {
		resultado = DifParImpar(numero / 10);
		if (numero % 2 == 0)
			resultado = resultado + numero % 10;
		else
			resultado = resultado - numero % 10;
	}
	return resultado;
}
// ---------------------------------------------------------------------------
// Eliminar los digitos pares de un numero

void eliminar_digito_par(Cardinal &n) {
	byte dig;
	if (n < 10) {
		if (n % 2 == 0) {
			n = 0;
		}
	}
	else {
		dig = n % 10;
		n = n / 10;
		eliminar_digito_par(n);
		if (dig % 2 == 1) {
			n = n * 10 + dig;
		}
	}
}
// ---------------------------------------------------------------------------
// Insertar un digito en una posicion de un n�mero
// algo falla

void insertar_digito(Cardinal n, byte digito, byte pos) {
	byte dig;
	if (n < 10) {
		n = n * 10 + digito;
	}
	else {
		dig = n % 10;
		n = n / 10;
		insertar_digito(n, digito, --pos);
		n = n * 10 + dig;
	}
}
// ---------------------------------------------------------------------------
// Rotar un primer digito de un numero

void Rotar(Cardinal &n) {
	byte dig, ultdig;
	if (n > 9) {
		dig = n % 10;
		n = n / 10;
		Rotar(n);
		ultdig = n % 10;
		n = n / 10;
		n = (n * 10 + dig) * 10 + ultdig;
	}
}

// ---------------------------------------------------------------------------
// Ordenar un numero ascendentemente

void ordenarNumero(Cardinal &n) {
	if (n > 9) {
		Mover_Mayor_Final(n);
		byte dig = n % 10;
		n = n / 10;
		ordenarNumero(n);
		n = n * 10 + dig;
	}
}

// ---------------------------------------------------------------------------
/* Escribir una funci�n que devuelva una cadena formada por los d�gitos
 de un n�mero repetidos la cantidad de veces que el d�gito representa.
 M�ximo 2 funciones.

 Ej. CadDeDigitos(521)=>"55555221"
 */



String Repetir_Digito(Cardinal n, Cardinal v) {
	String resultado;
	if (n == 0) {
		resultado = "";
	}
	else {
		resultado = Repetir_Digito(n - 1, v);
		resultado = resultado + String(v);
	}
	return resultado;
}

String Cadena_De_Digitos(Cardinal n) {
	String resultado;
	if (n < 10) {
		resultado = Repetir(n, n);
	}
	else {
		byte digito = n % 10;
		resultado = Cadena_De_Digitos(n / 10);
		resultado = resultado + Repetir_Digito(digito, digito);
	}
	return resultado;
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
