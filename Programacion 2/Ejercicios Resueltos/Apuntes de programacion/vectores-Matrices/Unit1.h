//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TMainMenu *MainMenu1;
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit1;
	TMenuItem *menu1;
	TMenuItem *modex11;
	TMenuItem *insertarcadadigdenenunvector1;
	TMenuItem *serieenv012361;
	TMenuItem *verif1;
	TMenuItem *fibo1;
	TMenuItem *seriefibov321101;
	TMenuItem *segmentar2vectores1;
	TStringGrid *StringGrid2;
	TStringGrid *StringGrid3;
	TButton *Button3;
	TButton *Button4;
	TMenuItem *intercalar2vectores1;
	TMenuItem *ordenarvector1;
	TMenuItem *cantdig1;
	TMenuItem *cadenas1;
	TMenuItem *eliminarprimyultletradeunapalenunacad1;
	TMenuItem *eliminartodasmenoslaprimylaultletraenunacad1;
	TMenuItem *deunvectorponercadainicialenunacad1;
	TMenuItem *palabramasgrande1;
	TMenuItem *insereleenposdeunvect1;
	TMenuItem *esnumero1;
	TMenuItem *sumadedigdeunacadena1;
	TMenuItem *retodepedro1;
	TMenuItem *decabase2al161;
	TMenuItem *contarpalabras1;
	TMenuItem *intercalar2vect201;
	TMenuItem *insertardigprimoenVdeunacad1;
	TMenuItem *convertirnonumerosaespacios1;
	TMenuItem *limpiarsoloprimos1;
	TMenuItem *vocalesdepalabrasenvector1;
	TMenuItem *dejarvocale1;
	TMenuItem *practica1;
	TMenuItem *vectorastringprimos1;
	TMenuItem *insertarvectorenotroenunapos1;
	TMenuItem *vectorastring1;
	TMenuItem *invertir1;
	TMenuItem *vectorastringnrosvolcados1;
	TMenuItem *decadenasolodigfibo1;
	TMenuItem *examenverano1;
	TMenuItem *pre11;
	TMenuItem *pre21;
	TMenuItem *pre31;
	TMenuItem *auxonline1;
	TMenuItem *ejer1deexamendeprueba1;
	TMenuItem *ejer2deexamdeprueba1;
	TMenuItem *para1;
	TMenuItem *moverdigdenalfinaldeunvector1;
	TMenuItem *digitosdenenunvector1;
	TMenuItem *eliminarmelementosdesdeunposdeunvector1;
	TMenuItem *contarpalabras2;
	TMenuItem *posi1;
	TMenuItem *invertirvector1;
	TMenuItem *palinvertenvect1;
	TMenuItem *invertircadena1;
	TMenuItem *ordmargeshort1;
	TMenuItem *promediodeelementos1;
	TMenuItem *interseccion1;
	TMenuItem *serie1;
	TMenuItem *mayorqueelpromedio1;
	TMenuItem *elminarelementodeunapos1;
	TMenuItem *verificarsitodosloselementosdelvectorsonpalindromes1;
	TMenuItem *vectorpalindrome1;
	TMenuItem *insertarelemento1;
	TMenuItem *eliminarprimernumerodeunaca1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall modex11Click(TObject *Sender);
	void __fastcall insertarcadadigdenenunvector1Click(TObject *Sender);
	void __fastcall serieenv012361Click(TObject *Sender);
	void __fastcall fibo1Click(TObject *Sender);
	void __fastcall seriefibov321101Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall intercalar2vectores1Click(TObject *Sender);
	void __fastcall segmentar2vectores1Click(TObject *Sender);
	void __fastcall ordenarvector1Click(TObject *Sender);
	void __fastcall cantdig1Click(TObject *Sender);
	void __fastcall eliminarprimyultletradeunapalenunacad1Click(TObject *Sender);
	void __fastcall eliminartodasmenoslaprimylaultletraenunacad1Click(TObject *Sender);
	void __fastcall deunvectorponercadainicialenunacad1Click(TObject *Sender);
	void __fastcall palabramasgrande1Click(TObject *Sender);
	void __fastcall insereleenposdeunvect1Click(TObject *Sender);
	void __fastcall esnumero1Click(TObject *Sender);
	void __fastcall sumadedigdeunacadena1Click(TObject *Sender);
	void __fastcall decabase2al161Click(TObject *Sender);
	void __fastcall contarpalabras1Click(TObject *Sender);
	void __fastcall intercalar2vect201Click(TObject *Sender);
	void __fastcall convertirnonumerosaespacios1Click(TObject *Sender);
	void __fastcall insertardigprimoenVdeunacad1Click(TObject *Sender);
	void __fastcall limpiarsoloprimos1Click(TObject *Sender);
	void __fastcall dejarvocale1Click(TObject *Sender);
	void __fastcall vocalesdepalabrasenvector1Click(TObject *Sender);
	void __fastcall vectorastringprimos1Click(TObject *Sender);
	void __fastcall insertarvectorenotroenunapos1Click(TObject *Sender);
	void __fastcall vectorastring1Click(TObject *Sender);
	void __fastcall invertir1Click(TObject *Sender);
	void __fastcall vectorastringnrosvolcados1Click(TObject *Sender);
	void __fastcall decadenasolodigfibo1Click(TObject *Sender);
	void __fastcall pre21Click(TObject *Sender);
	void __fastcall pre31Click(TObject *Sender);
	void __fastcall ejer1deexamendeprueba1Click(TObject *Sender);
	void __fastcall ejer2deexamdeprueba1Click(TObject *Sender);
	void __fastcall moverdigdenalfinaldeunvector1Click(TObject *Sender);
	void __fastcall digitosdenenunvector1Click(TObject *Sender);
	void __fastcall eliminarmelementosdesdeunposdeunvector1Click(TObject *Sender);
	void __fastcall contarpalabras2Click(TObject *Sender);
	void __fastcall invertirvector1Click(TObject *Sender);
	void __fastcall palinvertenvect1Click(TObject *Sender);
	void __fastcall invertircadena1Click(TObject *Sender);
	void __fastcall ordmargeshort1Click(TObject *Sender);
	void __fastcall promediodeelementos1Click(TObject *Sender);
	void __fastcall interseccion1Click(TObject *Sender);
	void __fastcall serie1Click(TObject *Sender);
	void __fastcall mayorqueelpromedio1Click(TObject *Sender);
	void __fastcall elminarelementodeunapos1Click(TObject *Sender);
	void __fastcall verificarsitodosloselementosdelvectorsonpalindromes1Click(TObject *Sender);
	void __fastcall vectorpalindrome1Click(TObject *Sender);
	void __fastcall insertarelemento1Click(TObject *Sender);
	void __fastcall eliminarprimernumerodeunaca1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
