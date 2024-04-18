//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TMenuItem *Nmeros1;
	TMenuItem *Nmeros2;
	TMenuItem *SumaDigPrim1;
	TMenuItem *SumaDigPrim2;
	TMenuItem *Mayor1;
	TMenuItem *ManorAlFinal1;
	TMenuItem *Ordenar1;
	TMenuItem *Cadenas1;
	TMenuItem *Cadenas2;
	TMenuItem *CantVocales1;
	TMenuItem *Invertir1;
	TMenuItem *ElimNoAlfabticos1;
	TButton *Button1;
	TStringGrid *StringGrid1;
	TMenuItem *N11;
	TMenuItem *BusBin1;
	TMenuItem *Ordenamiento1;
	TMenuItem *Martices1;
	TMenuItem *Martices2;
	TStringGrid *StringGrid2;
	TMenuItem *Clase1;
	TMenuItem *Clase2;
	TMenuItem *MatricescomoVectores1;
	TMenuItem *ContarlaCantidaddeDatosxenlamatriz1;
	TMenuItem *BusquedaBinaria1;
	void __fastcall Nmeros2Click(TObject *Sender);
	void __fastcall SumaDigPrim1Click(TObject *Sender);
	void __fastcall SumaDigPrim2Click(TObject *Sender);
	void __fastcall Mayor1Click(TObject *Sender);
	void __fastcall ManorAlFinal1Click(TObject *Sender);
	void __fastcall Ordenar1Click(TObject *Sender);
	void __fastcall CantVocales1Click(TObject *Sender);
	void __fastcall Invertir1Click(TObject *Sender);
	void __fastcall ElimNoAlfabticos1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall BusBin1Click(TObject *Sender);
	void __fastcall Ordenamiento1Click(TObject *Sender);
	void __fastcall Martices2Click(TObject *Sender);
	void __fastcall MatricescomoVectores1Click(TObject *Sender);
	void __fastcall ContarlaCantidaddeDatosxenlamatriz1Click(TObject *Sender);
	void __fastcall BusquedaBinaria1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
