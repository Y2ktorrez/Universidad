//---------------------------------------------------------------------------

#ifndef MainCodeH
#define MainCodeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMyForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *txtEntrada;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TLabel *Label2;
	TEdit *txtSalida;
	TMenuItem *ALGORITMOS1;
	TMenuItem *Ejercicio11;
	TMenuItem *Ejercicio21;
	TMenuItem *Ejercicio31;
	TMenuItem *Ejercicio41;
	TMenuItem *Ejercicio51;
	TMenuItem *STRING1;
	TMenuItem *Delete1;
	TMenuItem *Pos1;
	TMenuItem *rim1;
	TMenuItem *LastDelimiter1;
	TMenuItem *rim2;
	TMenuItem *SubString1;
	TListBox *Cajita;
	TMenuItem *CADENAS1;
	TMenuItem *Imprimirpalabrasdeunacadena1;
	TEdit *txtAuxiliar;
	TLabel *Label3;
	TMenuItem *Verificarsiuncaracterestaenunacadena1;
	TMenuItem *ConstruirNumero1;
	TMenuItem *Verificarsiesunaconsonante1;
	TMenuItem *Dejarsoloconsonantes1;
	TMenuItem *Verificarcuantaspalabrascomienzanyterminanenu1;
	TStringGrid *SGVector;
	TScrollBar *SBVector;
	TLabel *lblColumnas;
	TLabel *Label4;
	TMenuItem *VECTORES1;
	TMenuItem *Jugandoconlasceldas1;
	TMenuItem *CargarPalabrasalVector1;
	TMenuItem *FormatoCadena1;
	TMenuItem *CargarPalabrasalvector21;
	TMenuItem *CargarPalabrasconelprimercaracterenmayuscula1;
	void __fastcall Ejercicio11Click(TObject *Sender);
	void __fastcall Ejercicio21Click(TObject *Sender);
	void __fastcall Delete1Click(TObject *Sender);
	void __fastcall Pos1Click(TObject *Sender);
	void __fastcall LastDelimiter1Click(TObject *Sender);
	void __fastcall rim2Click(TObject *Sender);
	void __fastcall SubString1Click(TObject *Sender);
	void __fastcall Imprimirpalabrasdeunacadena1Click(TObject *Sender);
	void __fastcall Verificarsiuncaracterestaenunacadena1Click(TObject *Sender);
	void __fastcall ConstruirNumero1Click(TObject *Sender);
	void __fastcall Verificarsiesunaconsonante1Click(TObject *Sender);
	void __fastcall Dejarsoloconsonantes1Click(TObject *Sender);
	void __fastcall Verificarcuantaspalabrascomienzanyterminanenu1Click(TObject *Sender);
	void __fastcall SBVectorChange(TObject *Sender);
	void __fastcall Jugandoconlasceldas1Click(TObject *Sender);
	void __fastcall CargarPalabrasalVector1Click(TObject *Sender);
	void __fastcall FormatoCadena1Click(TObject *Sender);
	void __fastcall CargarPalabrasalvector21Click(TObject *Sender);
	void __fastcall CargarPalabrasconelprimercaracterenmayuscula1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TMyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyForm *MyForm;
//---------------------------------------------------------------------------
#endif
