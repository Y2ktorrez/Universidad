// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recursi�n.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Literal1Click(TObject *Sender) {
	Edit2->Text = Literal(StrToInt(Edit1->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CantidadParantesdeImpar1Click(TObject *Sender) {
	//Edit2->Text = Cantidad_Pares(StrToInt(Edit1->Text));
	Edit2->Text = CantDigPares(StrToInt(Edit1->Text));
	// Edit2->Text = parAntesImpar(StrToInt(Edit1->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::EliminarPrimeraLetra1Click(TObject *Sender) {
	// AnsiString resultado = Edit3->Text;
	// Eliminar_Primera_Letra(resultado);
	String resultado = Edit3->Text;
	eliminarPrimerLetra(resultado);
	// Eliminar_Primera_Letra(resultado);
	Edit4->Text = resultado;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::LeerConjunto1Click(TObject *Sender) {
	String conjunto = InputBox("Titulo", "Conjunto", "");
	String res = leerConjunto(conjunto);
	Edit4->Text = res;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::EsPalndrome1Click(TObject *Sender) {
	String cad = Edit3->Text;
	bool b = esPalindrome(cad);
	if (b)
		Edit4->Text = "Si es";
	else
		Edit4->Text = "No es";
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::DimencionarClick(TObject *Sender) {
	String cad = Txt_Dimension->Text;
	Byte len = StrToInt(cad);
	StringGrid1->ColCount = len;
	// StringGrid1->RowCount = len;
	// StringGrid1->Cells[col][fil];
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Invertir1Click(TObject *Sender) {
	// Invertir_Vector(StringGrid1,StrToInt(Edit5->Text),StrToInt(Edit6->Text));

	Byte a = StrToInt(InputBox("Titulo", "Posici�n a:", ""));
	Byte b = StrToInt(InputBox("Titulo", "Posici�n b:", ""));
	invertir(StringGrid1, a, b);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::InsertionSort1Click(TObject *Sender) {
	InsertionSort(StringGrid1, 0);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarSerie11Click(TObject *Sender) {
	byte n = StrToInt(InputBox("Longitud", "N�mero: ", ""));
	// Cardinal n = StringGrid1->ColCount;
	StringGrid1->ColCount = n;
	cargarSerie1(StringGrid1, n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::MoverMayoralFinal1Click(TObject *Sender) {
	Cardinal x = StrToInt(Edit1->Text);
	Mover_Mayor(x);
	Edit2->Text = x;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::VerificarOrden1Click(TObject *Sender) {
	bool b = Verificar_Orden(StringGrid1, StringGrid1->ColCount);
	if (b)
		ShowMessage("Esta Ordenado");
	else
		ShowMessage("No esta Ordenado");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SumadeDigitos1Click(TObject *Sender) {
	Byte n = StringGrid2->ColCount;
	Cardinal suma = sumaDigitos(StringGrid2, n);
	ShowMessage("Suma de digitos: " + String(suma));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarOrdenadoCadena1Click(TObject *Sender) {
	String cad = Edit5->Text;
	StringGrid1->ColCount = cad.Length();
	cargarOrdAsc(StringGrid1, cad);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit7Change(TObject *Sender) {
	if (Edit7->Text != "") {
		Cardinal filas = StrToInt(Edit7->Text);
		StringGrid3->RowCount = filas;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Edit8Change(TObject *Sender) {
	if (Edit8->Text != "") {
		Cardinal columnas = StrToInt(Edit8->Text);
		StringGrid3->ColCount = columnas;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarTodasLasFilas1Click(TObject *Sender) {
	Cardinal v = 1;
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	cargarTodoFila(StringGrid3, f, c, v);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarTodasLasColumnas1Click(TObject *Sender) {
	Cardinal v = 1;
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	cargarTodoCol(StringGrid3, f, c, v);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			StringGrid3->Cells[j][i] = "";
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarDiagonalSecundariaInferioe1Click(TObject *Sender)
{
	Cardinal v = 1;
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	diag_sec_inf(StringGrid3, f, c, v);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OrdenBurbuja1Click(TObject *Sender) {
	Cardinal n = StringGrid1->ColCount;
	// ord_burbuja(StringGrid1, n);
	BubbleSort(StringGrid1, n);
	// bubbleSort(StringGrid1, n);
}
// ---------------------------------------------------------------------------

void Cargar_Random(TStringGrid *v, byte n) {
	if (n > 0) {
		Cargar_Random(v, n - 1);
		v->Cells[n - 1][0] = Random(20);
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender) {
	// StringGrid1->ColCount = StrToInt(Txt_Dimension->Text);
	// Cargar_Random(StringGrid1, StringGrid1->ColCount);
	byte n = StrToInt(InputBox("Dimensi�n", "Nro Elementos:", ""));
	StringGrid1->ColCount = n;
	Cargar_Random(StringGrid1, n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarExterior1Click(TObject * Sender) {
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	cargar_exterior(StringGrid3, 1, 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SumadeBinarios1Click(TObject * Sender) {
	Cardinal a = StrToInt(Edit1->Text);
	Cardinal b = StrToInt(Edit9->Text);
	Cardinal suma = suma_binarios(a, b);
	Edit2->Text = suma;
	// ShowMessage("Suma: " + String(suma));
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::CargarDiagonalSecundaria21Click(TObject * Sender) {
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	Cardinal v = 1;
	cargar_matriz1(StringGrid3, f, c, v);

	/* byte n = StrToInt(InputBox("ORDEN", "N�mero: ", ""));
	 StringGrid3->RowCount = n;
	 StringGrid3->ColCount = n;
	 byte k = 1;
	 filaTriangular2(StringGrid3, 0, n - 1, n - 1, n - 1, k); */
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarDiagonalSuperior1Click(TObject * Sender) {
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	cargar_matriz2(StringGrid3, f, c);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarCaracol1Click(TObject * Sender) {
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	Cardinal v = 1;
	caracol(StringGrid3, 1, f, 1, c, v);

	/* int n = StrToInt(InputBox("Dimensi�n","N�mero:",""));
	 StringGrid3->ColCount = n;
	 StringGrid3->RowCount = n;
	 espiral(StringGrid3, 0, n - 1, 1); */
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarCaracol21Click(TObject * Sender) {
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	Cardinal v = 1;
	caracol2(StringGrid3, 1, f, 1, c, v);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::InsertarVectorenOtrov2v2p1Click(TObject * Sender) {
	Cardinal p = StrToInt(InputBox("Titulo", "Posicion: ", ""));
	insertar(StringGrid2, StringGrid1, p);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject * Sender) {
	String cad = Txt_Dimension2->Text;
	Byte len = StrToInt(cad);
	StringGrid2->ColCount = len;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::NmeroMayor1Click(TObject * Sender) {
	// String cad = InputBox("", "Cadena:", "");
	Edit4->Text = numMayor(Edit3->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarFraseenunVector1Click(TObject * Sender) {
	/* StringGrid2->ColCount = 1;
	 String frase = InputBox("", "Frase:", "");
	 cargarVectorCadena(frase, StringGrid2);
	 StringGrid2->ColCount -= 1; */

	String x = InputBox("Cadena", "Frase :", "");
	byte n = contarPalabras(x);
	StringGrid2->ColCount = n;
	cargarVectorCadena(StringGrid2, n, x);
	// ShowMessage(n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarPalabra1Click(TObject * Sender) {
	String frase = InputBox("", "Palabra:", "");
	cargar_cad(StringGrid3, frase, 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::EliminarElemento1Click(TObject * Sender) {
	Cardinal z = StrToInt(InputBox("", "Numero:", ""));
	eliminar_elemento(StringGrid1, z, StringGrid1->ColCount);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarEspiral1Click(TObject * Sender) {
	byte n = StrToInt(InputBox("ORDEN", "nro: ", ""));
	StringGrid3->RowCount = n;
	StringGrid3->ColCount = n;
	cargarCuadrado(StringGrid3, 0, n - 1, 0, n - 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarVocaeles1Click(TObject * Sender) {
	StringGrid2->ColCount = 1;
	String cad = Edit5->Text;
	// String cad = InputBox("", "Cadena:", "");
	cargar_vocales(cad, StringGrid2);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarFraccin1Click(TObject * Sender) {
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	Cardinal num = 1;
	Cardinal den = 64;
	cargar_frac(StringGrid3, f, c, num, den);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarFrecuencias1Click(TObject * Sender) {
	String cad = Edit5->Text;
	StringGrid1->ColCount = cad.Length();
	StringGrid2->ColCount = cad.Length();
	cargar_frec(cad, StringGrid1, StringGrid2, cad.Length());
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Invertir2Click(TObject * Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	Invertir(n);
	// InvertirNumero(n);
	Edit2->Text = n;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::MoverMayoralFinal2Click(TObject * Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	Mover_Mayor_Final(n);
	Edit2->Text = n;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Ordenar1Click(TObject * Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	Ordenar(n);
	Edit2->Text = n;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::DecimalaBinario1Click(TObject * Sender) {
	Edit2->Text = Conversion_Binario(StrToInt(Edit1->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ConversindeBases1Click(TObject * Sender) {
	Edit2->Text = Conversion_Bases(StrToInt(Edit1->Text),
		StrToInt(Edit9->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Invertir3Click(TObject * Sender) {
	String cadena = Edit3->Text;
	Invertir(cadena);
	Edit4->Text = cadena;

	// Edit4->Text = Invertir_Cadena(Edit3->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::EliminarVocale1Click(TObject * Sender) {
	String cadena = Edit3->Text;
	eliminarVocales(cadena);
	Edit4->Text = cadena;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::PalabramsLarga1Click(TObject * Sender) {
	Edit4->Text = palabraMasLarga(Edit3->Text);
	// Edit4->Text = Palabra_Larga(Edit3->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::InvertirPalabra1Click(TObject * Sender) {
	// AnsiString cadena = Edit3->Text;
	// Invertir_Cada_Palabra(cadena);
	String cadena = Edit3->Text;
	invertirPalabras(cadena);
	Edit4->Text = cadena;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Fibonacci1Click(TObject * Sender) {
	Edit11->Text = fibonacci(StrToInt(Edit10->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Serie1Click(TObject * Sender) {
	Edit11->Text = serie1(StrToInt(Edit10->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SumaSerie1Click(TObject * Sender) {
	Cardinal s = 0;
	Cardinal r = sumaSerie2(StrToInt(Edit10->Text), s);
	Edit11->Text = s;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::SumadeElementosPres1Click(TObject *Sender) {
	// suponemos que el vector esta cargado
	Cardinal s = sumaPares(StringGrid1, StringGrid1->ColCount);
	ShowMessage(s);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ContarPalabras1Click(TObject *Sender) {
	/* String x = InputBox("ContarPalabras", "cad :", "");
	 byte c = contarPalabras(x);
	 ShowMessage(c); */

	// Edit4->Text = contarPalabras(Edit3->Text);
	Edit4->Text = contar_palabras(Edit3->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Cargar1Click(TObject *Sender) {
	Cardinal nro = StrToInt(Edit5->Text);
	byte c = Cantidad_Digitos(nro);
	c = (c - 1) / 2 + 1;
	StringGrid1->ColCount = c;
	cargarVector100(StringGrid1, c, nro);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CadenaconNmerosInvertidosdeunvector1Click
	(TObject *Sender) {
	byte n = StringGrid1->ColCount;
	// String s = generarCadenaNroInv(StringGrid1, n);
	String s = GenerarCadenaNroInv(StringGrid1, 0, n - 1);
	ShowMessage(s);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarSerie1Click(TObject *Sender) {
	byte n = StrToInt(InputBox("Longitud", "N�mero: ", ""));
	StringGrid1->ColCount = n;
	Cardinal t = CargarSerie(StringGrid1, n);
	// ShowMessage(t);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarMatrizSerpiente1Click(TObject *Sender) {
	byte m = StrToInt(Edit7->Text);
	byte n = StrToInt(Edit8->Text);
	byte k = 1;
	StringGrid3->RowCount = m;
	StringGrid3->ColCount = n;
	filaSerpiente(StringGrid3, 0, m - 1, 0, n - 1, k);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarDiagonalSuperior2Click(TObject *Sender) {
	byte n = StrToInt(InputBox("ORDEN", "N�mero: ", ""));
	StringGrid3->RowCount = n;
	StringGrid3->ColCount = n;
	filaTriangular1(StringGrid3, 0, n - 1, 0, n - 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::s1Click(TObject *Sender) {
	Word n = StrToInt(Edit10->Text);
	Edit11->Text = sumaSerie(n);

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Serie13571531631Click(TObject *Sender) {
	Word n = StrToInt(Edit10->Text);
	Edit11->Text = serie2(n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Suma1Click(TObject *Sender) {
	// byte n = StrToInt(InputBox("SUMA", "N�mero: ", ""));
	byte n = StringGrid1->ColCount;
	Cardinal s = suma(StringGrid1, n);
	// Cardinal s = Sumar_Vectores(StringGrid1, n);
	ShowMessage(s);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarCaracteresdeCadena1Click(TObject *Sender) {
	String cad = Edit5->Text;
	byte n = cad.Length();
	StringGrid1->ColCount = n;
	Cargar_Cadena(StringGrid1, n, cad);

	/* String cadena = InputBox("","","");
	 StringGrid1->ColCount = cadena.Length();
	 cargarConCadena(cadena, StringGrid1);
	 for (int i = 0; i < 500; i++) {
	 v[i] = i * 5;
	 } */
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Factorial1Click(TObject *Sender) {
	byte n = StrToInt(Edit1->Text);
	Cardinal f = factorial(n);
	Edit2->Text = f;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Potencia1Click(TObject *Sender) {
	/* Cardinal n = StrToInt(Edit1->Text);
	 Cardinal f = potencia(n);
	 Edit2->Text = f; */
	Edit2->Text = Potencia(StrToInt(Edit1->Text), StrToInt(Edit9->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::GitioMayoryMenor1Click(TObject *Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	Edit2->Text = digitoMayorMenor(n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::DigitoMayor1Click(TObject *Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	Edit2->Text = DigitoMayor(n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::VerificarOrdenAscendente1Click(TObject *Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	bool b = estaOrdenadoAsc(n);
	if (b) {
		Edit2->Text = "True";
	}
	else {
		Edit2->Text = "False";
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::VerificarOrdenDescendente1Click(TObject *Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	bool b = estaOrdenadoDesc(n);
	if (b) {
		Edit2->Text = "True";
	}
	else {
		Edit2->Text = "False";
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeDigitosPares1Click(TObject *Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	Edit2->Text = cantidadPares(n);
	// Edit2->Text = CantidadPares(n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SumadeDigitosPares1Click(TObject *Sender) {
	Cardinal n = StrToInt(Edit1->Text);
	Edit2->Text = sumaPares(n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::c1Click(TObject *Sender) {
	/* byte m = StrToInt(Edit7->Text);
	 byte n = StrToInt(Edit8->Text);
	 StringGrid3->RowCount = m;
	 StringGrid3->ColCount = n;
	 cargarD1(StringGrid3, 0, m - 1, 0, n - 1, 1); */

	/* int nf = StrToInt(Edit7->Text);
	 int nc = StrToInt(Edit8->Text);
	 StringGrid3->ColCount = nc;
	 StringGrid3->RowCount = nf;
	 principal(StringGrid3, nf, nc, nf); */

	int nf = StrToInt(Edit7->Text);
	int nc = StrToInt(Edit8->Text);
	StringGrid3->ColCount = nc;
	StringGrid3->RowCount = nf;
	cargarDiagonales(StringGrid3, nf + nc - 1, nf, nc);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarCaracol31Click(TObject *Sender) {
	byte m = StrToInt(Edit7->Text);
	byte n = StrToInt(Edit8->Text);
	StringGrid3->RowCount = m;
	StringGrid3->ColCount = n;
	byte k = 1;
	cargarCaracol(StringGrid3, 0, m - 1, 0, n - 1, k);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarDiagonalInferiorcon11Click(TObject *Sender) {
	// byte m = StrToInt(Edit7->Text);
	// byte n = StrToInt(Edit8->Text);
	byte n = StrToInt(InputBox("ORDEN", "N�mero: ", ""));
	StringGrid3->RowCount = n;
	StringGrid3->ColCount = n;
	cargarFilaTri3(StringGrid3, 0, n - 1, 0, n - 1, n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarMatrizSerpiente21Click(TObject *Sender) {
	byte m = StrToInt(Edit7->Text);
	byte n = StrToInt(Edit8->Text);
	StringGrid3->RowCount = m;
	StringGrid3->ColCount = n;
	colSerpiente2(StringGrid3, 0, m - 1, 0, n - 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarCadena1Click(TObject *Sender) {
	byte m = StrToInt(Edit7->Text);
	byte n = StrToInt(Edit8->Text);
	StringGrid3->RowCount = m;
	StringGrid3->ColCount = n;
	String x = InputBox("CADENA", "Cadena:", "");
	if (x.Length() <= m * n) {
		cargarColCad1(StringGrid3, 0, m - 1, 0, n - 1, x);
	}
	else {
		ShowMessage("No carga la cadena");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarCadena21Click(TObject *Sender) {
	byte m = StrToInt(InputBox("FILAS", "N�mero: ", ""));
	byte n = StrToInt(InputBox("COLUMNAS", "N�mero: ", ""));
	StringGrid3->RowCount = m;
	StringGrid3->ColCount = n;
	String x = InputBox("CADENA", "cad:", "");
	if (x.Length() <= m * n) {
		cargarCadena2(StringGrid3, 0, m*n - 1, x);
	}
	else {
		ShowMessage("No carga la cadena");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Cargardiagonalsuperior3Click(TObject *Sender) {
	byte n = StrToInt(InputBox("ORDEN", "N�mero: ", ""));
	byte k = 1;
	StringGrid3->RowCount = n;
	StringGrid3->ColCount = n;
	triangular3(StringGrid3, 1, n, k);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarCadena31Click(TObject *Sender) {
	String x = InputBox("Cadena", "String: ", "");
	if (x != "") {
		byte n = (int)sqrt(x.Length() - 1) + 1;
		StringGrid3->ColCount = n;
		StringGrid3->RowCount = n;
		cargarCadenaMatrizVector(StringGrid3, 0, n*n - 1, x);
	}
	else {
		ShowMessage("Cadena Vacia -> Matriz []");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::DigitodelaSerie24681Click(TObject *Sender) {
	Edit11->Text = Serie(StrToInt(Edit10->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeDigitosa1Click(TObject *Sender) {
	Edit2->Text = Cantidad_Digitos(StrToInt(Edit1->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SumaDigitosPares1Click(TObject *Sender) {
	Edit2->Text = Suma_Digitos_Pares(StrToInt(Edit1->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::DiferenciaentrePareseImpares1Click(TObject *Sender) {
	Edit2->Text = DifParImpar(StrToInt(Edit1->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ContarEspacios1Click(TObject *Sender) {
	Edit4->Text = Cantidad_Espacios(Edit3->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ContarVocales1Click(TObject *Sender) {
	Edit4->Text = Contar_Vocales(Edit3->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BusquedaBinaria1Click(TObject *Sender) {
	bool resultado;
	// Word b = StringGrid1->ColCount;
	resultado = Busqueda_Binaria(StringGrid1, StrToInt(Edit5->Text), 0,
		StrToInt(Edit6->Text));
	if (resultado) {
		ShowMessage("SI est� en el vector");
	}
	else {
		ShowMessage("NO est� en el vector");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarporFilas1Click(TObject *Sender) {
	StringGrid3->ColCount = StrToInt(Edit8->Text);
	StringGrid3->RowCount = StrToInt(Edit7->Text);
	Cargar_Matriz(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarMatriz1Click(TObject *Sender) {
	StringGrid3->ColCount = StrToInt(Edit8->Text);
	StringGrid3->RowCount = StrToInt(Edit7->Text);
	Cargar_Matriz2(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarEspiral21Click(TObject *Sender) {
	StringGrid3->RowCount = StrToInt(Edit7->Text);
	StringGrid3->ColCount = StringGrid3->RowCount;
	Cargar_Espiral(StringGrid3, 0, StringGrid3->RowCount - 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarDona1Click(TObject *Sender) {
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	dona(StringGrid3, f, c, 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CuadradoMgico1Click(TObject *Sender) {
	Word a, b, m = StrToInt(Edit7->Text);
	StringGrid3->RowCount = m;
	StringGrid3->ColCount = m;
	Cuadrado_Magico(StringGrid3, m, m*m, a, b);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarOrdenado1Click(TObject *Sender) {
	byte n;
	CargarOrden(StrToInt(Edit5->Text), StringGrid1, n);
	StringGrid1->ColCount = n;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::NmeroMayordeunaCadena1Click(TObject *Sender) {
	Edit4->Text = NumeroMayor(Edit3->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarMatrizExamen1Click(TObject *Sender) {
	byte f, c, m = StrToInt(Edit7->Text);
	StringGrid3->ColCount = m;
	StringGrid3->RowCount = m;
	Cargar(StringGrid3, m, m * m, f, c);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarSerie012367141Click(TObject *Sender) {
	int n = StrToInt(InputBox("Serie: 0, 1, 2, 3, 6, 7, 14, 15, 30, 31, ...",
		"Cant N�meros:", ""));
	StringGrid1->ColCount = n;
	cargarSerie(StringGrid1, n);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::QuickSort1Click(TObject *Sender) {
	quickSort(StringGrid1, 0, StringGrid1->ColCount - 1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarTriangularInferior1Click(TObject *Sender) {
	int n = StrToInt(InputBox("Dimensi�n", "N�mero", ""));
	StringGrid3->RowCount = n;
	StringGrid3->ColCount = n;
	cargarMatriz(StringGrid3, n, n);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::SumadeDigitosPrimos1Click(TObject *Sender) {
	Cardinal numero = StrToInt(Edit1->Text);
	Edit2->Text = sumaDigitosPrimos(numero);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::InvertirCadena1Click(TObject *Sender) {
	String cadena = Edit3->Text;
	Edit4->Text = invertirN2(cadena);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SumadeDigitos2Click(TObject *Sender) {
	Cardinal numero = StrToInt(Edit1->Text);
	Edit2->Text = sumaDigitos(numero);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeDigitoaImpares1Click(TObject *Sender) {
	Cardinal numero = StrToInt(Edit1->Text);
	Edit2->Text = CantidadImpares(numero);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeDigitosPrimos1Click(TObject *Sender) {
	Cardinal numero = StrToInt(Edit1->Text);
	Edit2->Text = CantidadPrimos(numero);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::EliminarDigitosPares1Click(TObject *Sender) {
	Cardinal numero = StrToInt(Edit1->Text);
	eliminar_digito_par(numero);
	Edit2->Text = numero;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::InsertarDigito1Click(TObject *Sender) {
	Cardinal numero = StrToInt(Edit1->Text);
	byte digito = StrToInt(Edit9->Text);
	byte pos = StrToInt(InputBox("Insertar", "Posici�n:", ""));
	insertar_digito(numero, digito, pos);
	Edit2->Text = numero;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::RotarelprimerDigito1Click(TObject *Sender) {
	Cardinal numero = StrToInt(Edit1->Text);
	Rotar(numero);
	Edit2->Text = numero;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarAscendentemente1Click(TObject *Sender) {
	Cardinal numero = StrToInt(Edit1->Text);
	ordenarNumero(numero);
	Edit2->Text = numero;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SumaDigitosenu1Click(TObject *Sender) {
	String cad = Edit3->Text;
	Edit4->Text = suma_digitos_cadena(cad); ;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ConstruirCadenaconDigitos1Click(TObject *Sender) {
	String cad = Edit3->Text;
	construir_cadena_digitos(cad);
	Edit4->Text = cad;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddeLetras1Click(TObject *Sender) {
	String cad = Edit3->Text;
	Edit4->Text = contar_letras(cad);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::CargarPalabrassinVocales1Click(TObject *Sender) {
	StringGrid2->RowCount = 1;
	StringGrid2->ColCount = 1;
	String cadena = Edit5->Text;
	cargar_palabras_sin_vocales(StringGrid2, cadena);
	StringGrid2->ColCount--;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarNmeroRetonarSuma1Click(TObject *Sender) {
	StringGrid2->RowCount = 1;
	StringGrid2->ColCount = 1;

	String cadena = Edit5->Text;
	construir_cadena_digitos(cadena);

	Cardinal resultado = cargar_numero_retornar_suma(StringGrid2, cadena);
	StringGrid2->ColCount--;
	ShowMessage("Suma: " + String(resultado));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ConstruitcadenaconUltimasLetras1Click(TObject *Sender) {
	String resultado = construir_con_ultima_letra(StringGrid2,
		StringGrid2->ColCount);
	ShowMessage("Cadena:   " + resultado);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarPalabraInvertida1Click(TObject *Sender) {
	String cadena = Edit5->Text;
	cargar_inverso_con_letras(StringGrid1, cadena);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::InvertirFrase1Click(TObject *Sender) {
	/* String cadena = Edit3->Text;
	 invertir_frase(cadena);
	 Edit4->Text = cadena; */
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::VectoraNmero1Click(TObject *Sender) {
	long x = generar_num(StringGrid1, StringGrid1->ColCount);
	Edit6->Text = x;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarCadenaenSerpiente1Click(TObject *Sender) {
	String cad = InputBox("Cargar Cadena", "Cadena:", "");
	serpiente_cadena(StringGrid3, 1, cad);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarColumnasInvertido1Click(TObject *Sender) {
	cargar_cols(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount,
		(StringGrid3->ColCount + 1) / 2);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Navidad1Click(TObject *Sender) {
	navidad(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarTriangularSuperior1Click(TObject *Sender) {
	matriz(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarTriangularInferiorP11Click(TObject *Sender) {
	Cardinal v = 1;
	Cardinal f = StringGrid3->RowCount;
	Cardinal c = StringGrid3->ColCount;
	diag_sec_inf2(StringGrid3, f, c, v);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarMatrizSerpienteColumnas1Click(TObject *Sender) {
	byte m = StrToInt(Edit7->Text);
	byte n = StrToInt(Edit8->Text);
	StringGrid3->RowCount = m;
	StringGrid3->ColCount = n;
	Cardinal val = 1;
	colSerpiente3(StringGrid3, 0, m - 1, 0, n - 1, val);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarTriangularInferiorColumnas1Click(TObject *Sender)
{
	/* int n = StrToInt(InputBox("Dimensi�n", "N�mero", ""));
	 StringGrid3->RowCount = n;
	 StringGrid3->ColCount = n;
	 cargarMatriz2(StringGrid3, n, n); */
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CadenadeDigitos1Click(TObject *Sender) {
	Edit2->Text = Cadena_De_Digitos(StrToInt(Edit1->Text));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CargarDiagonales1Click(TObject *Sender) {
	/* byte m = StrToInt(Edit7->Text);
	 byte n = StrToInt(Edit8->Text);
	 StringGrid3->RowCount = m;
	 StringGrid3->ColCount = n;
	 cargarD2(StringGrid3, 0, m - 1, 0, n - 1, 1); */

	/* int nf = StrToInt(Edit7->Text);
	 int nc = StrToInt(Edit8->Text);
	 StringGrid3->ColCount = nc;
	 StringGrid3->RowCount = nf;
	 principal2(StringGrid3, nf, nc, nf);

	 int nf = StrToInt(Edit7->Text);
	 int nc = StrToInt(Edit8->Text);
	 StringGrid3->ColCount = nc;
	 StringGrid3->RowCount = nf;
	 cargarDiagonales(StringGrid3, nf + nc - 1, nf, nc); */

	byte f = StrToInt(Edit7->Text);
	byte c = StrToInt(Edit8->Text);
	CargarMatriz5(StringGrid3, f, c);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ElimnarElementos1Click(TObject *Sender) {
	Cardinal z = StrToInt(InputBox("", "Numero:", ""));
	eliminar_elemento2(StringGrid1, z, StringGrid1->ColCount);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SumaDigitosPares2Click(TObject *Sender) {
	byte n = StrToInt(Edit5->Text);
	// byte n = StringGrid1->ColCount;
	Cardinal resultado = Suma_Pares2(StringGrid1, n);
	ShowMessage("Suma Digitos Pares: " + String(resultado));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::InsertionSort2Click(TObject *Sender) {
	byte n = StringGrid1->ColCount;
	// InsertionSort2(StringGrid1, n);
}
// ---------------------------------------------------------------------------

