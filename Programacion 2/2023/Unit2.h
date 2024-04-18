//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TMainMenu *MainMenu1;
	TStringGrid *StringGrid1;
	TMenuItem *Numeros1;
	TMenuItem *CantDigParesDif1;
	TMenuItem *GetDigPares1;
	TMenuItem *GetDigPares2;
	TMenuItem *MayorMenor21;
	TMenuItem *ElimPrimNum1;
	TMenuItem *PalMasLarga1;
	TMenuItem *MoverMenor1;
	TMenuItem *CadenaDeDig1;
	TMenuItem *SumaNum1;
	TMenuItem *ElimPares1;
	TMenuItem *ContadorDeSignos1;
	TMenuItem *ElimUltNum1;
	TMenuItem *InvertirCad1;
	TMenuItem *ContadorPalabras1;
	TMenuItem *ElimVocales1;
	TMenuItem *ElimPrimerLetra1;
	TMenuItem *InvertirPalabra1;
	TMenuItem *Matrices1;
	TMenuItem *Matrices2;
	TMenuItem *N21;
	TMenuItem *N22;
	TMenuItem *N41;
	TMenuItem *N42;
	TMenuItem *N61;
	TMenuItem *N62;
	TMenuItem *N81;
	TMenuItem *N82;
	TMenuItem *N101;
	TMenuItem *N102;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N131;
	TMenuItem *N141;
	TMenuItem *N142;
	TMenuItem *N161;
	TMenuItem *N162;
	TMenuItem *N181;
	TMenuItem *N182;
	TMenuItem *N201;
	TMenuItem *Seguimos1;
	TMenuItem *Seguimos2;
	TMenuItem *N221;
	TMenuItem *N231;
	TMenuItem *N241;
	TMenuItem *N242;
	TMenuItem *N261;
	TMenuItem *N262;
	TMenuItem *N281;
	TMenuItem *N282;
	TMenuItem *N301;
	void __fastcall CantDigParesDif1Click(TObject *Sender);
	void __fastcall GetDigPares1Click(TObject *Sender);
	void __fastcall GetDigPares2Click(TObject *Sender);
	void __fastcall MayorMenor21Click(TObject *Sender);
	void __fastcall ElimPrimNum1Click(TObject *Sender);
	void __fastcall PalMasLarga1Click(TObject *Sender);
	void __fastcall MoverMenor1Click(TObject *Sender);
	void __fastcall CadenaDeDig1Click(TObject *Sender);
	void __fastcall SumaNum1Click(TObject *Sender);
	void __fastcall ElimPares1Click(TObject *Sender);
	void __fastcall ContadorDeSignos1Click(TObject *Sender);
	void __fastcall ElimUltNum1Click(TObject *Sender);
	void __fastcall InvertirCad1Click(TObject *Sender);
	void __fastcall ContadorPalabras1Click(TObject *Sender);
	void __fastcall ElimVocales1Click(TObject *Sender);
	void __fastcall ElimPrimerLetra1Click(TObject *Sender);
	void __fastcall InvertirPalabra1Click(TObject *Sender);
	void __fastcall Matrices2Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall N22Click(TObject *Sender);
	void __fastcall N41Click(TObject *Sender);
	void __fastcall N42Click(TObject *Sender);
	void __fastcall N61Click(TObject *Sender);
	void __fastcall N62Click(TObject *Sender);
	void __fastcall N81Click(TObject *Sender);
	void __fastcall N82Click(TObject *Sender);
	void __fastcall N101Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall N131Click(TObject *Sender);
	void __fastcall N141Click(TObject *Sender);
	void __fastcall N142Click(TObject *Sender);
	void __fastcall N161Click(TObject *Sender);
	void __fastcall N162Click(TObject *Sender);
	void __fastcall N181Click(TObject *Sender);
	void __fastcall N182Click(TObject *Sender);
	void __fastcall N201Click(TObject *Sender);
	void __fastcall Seguimos2Click(TObject *Sender);
	void __fastcall N221Click(TObject *Sender);
	void __fastcall N231Click(TObject *Sender);
	void __fastcall N241Click(TObject *Sender);
	void __fastcall N242Click(TObject *Sender);
	void __fastcall N261Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
