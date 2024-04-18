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
	TMenuItem *Numeros1;
	TMenuItem *Numeros2;
	TMenuItem *GetDigPares1;
	TMenuItem *GetDigPares2;
	TMenuItem *MayorMenor21;
	TMenuItem *ElimPrimDig1;
	TMenuItem *Vectores1;
	TStringGrid *StringGrid1;
	TMenuItem *EliminarPos1;
	TMenuItem *Cargar1;
	TMenuItem *EliminarCant1;
	TMenuItem *GenerarNumero1;
	TMenuItem *PalabraMasLarga1;
	TMenuItem *MoverMenor1;
	TMenuItem *CadDeDig1;
	TMenuItem *SumaNumeros1;
	TMenuItem *Matrices1;
	TMenuItem *Cargar11;
	TMenuItem *MatrizAmxm1;
	TButton *Button1;
	TMenuItem *MatrisSuperior1;
	TMenuItem *MatrizInferior1;
	TMenuItem *MatrizEspiral1;
	TMenuItem *MatrizCaracolTriangular1;
	TMenuItem *MatrizModelodeExamen1;
	TMenuItem *MatrisTriangularDerecho1;
	TMenuItem *djwjd1;
	TMenuItem *djwjd2;
	TMenuItem *Orden1;
	TMenuItem *prueba1;
	void __fastcall Numeros2Click(TObject *Sender);
	void __fastcall GetDigPares1Click(TObject *Sender);
	void __fastcall GetDigPares2Click(TObject *Sender);
	void __fastcall MayorMenor21Click(TObject *Sender);
	void __fastcall ElimPrimDig1Click(TObject *Sender);
	void __fastcall EliminarPos1Click(TObject *Sender);
	void __fastcall Cargar1Click(TObject *Sender);
	void __fastcall EliminarCant1Click(TObject *Sender);
	void __fastcall GenerarNumero1Click(TObject *Sender);
	void __fastcall PalabraMasLarga1Click(TObject *Sender);
	void __fastcall MoverMenor1Click(TObject *Sender);
	void __fastcall CadDeDig1Click(TObject *Sender);
	void __fastcall SumaNumeros1Click(TObject *Sender);
	void __fastcall Cargar11Click(TObject *Sender);
	void __fastcall MatrizAmxm1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall MatrisSuperior1Click(TObject *Sender);
	void __fastcall MatrizInferior1Click(TObject *Sender);
	void __fastcall MatrizEspiral1Click(TObject *Sender);
	void __fastcall MatrizCaracolTriangular1Click(TObject *Sender);
	void __fastcall MatrizModelodeExamen1Click(TObject *Sender);
	void __fastcall MatrisTriangularDerecho1Click(TObject *Sender);
	void __fastcall Orden1Click(TObject *Sender);
	void __fastcall prueba1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
