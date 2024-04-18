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
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TStringGrid *StringGrid1;
	TMainMenu *MainMenu1;
	TMenuItem *menu1;
	TMenuItem *cargarrnd1;
	TMenuItem *cargar11;
	TMenuItem *generartriangulo1;
	TMenuItem *generartri21;
	TButton *Button1;
	TMenuItem *genrarejer51;
	TMenuItem *generarejer6ing1;
	TMenuItem *cuadradomagico1;
	TMenuItem *sumadelvectir1;
	TMenuItem *seremod1;
	TMenuItem *generarimpares1;
	TMenuItem *modex1;
	TMenuItem *enerarl1;
	TMenuItem *cadamat1;
	TMenuItem *clase1;
	TMenuItem *ejer11;
	void __fastcall cargarrnd1Click(TObject *Sender);
	void __fastcall cargar11Click(TObject *Sender);
	void __fastcall generartriangulo1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall generartri21Click(TObject *Sender);
	void __fastcall genrarejer51Click(TObject *Sender);
	void __fastcall generarejer6ing1Click(TObject *Sender);
	void __fastcall cuadradomagico1Click(TObject *Sender);
	void __fastcall seremod1Click(TObject *Sender);
	void __fastcall generarimpares1Click(TObject *Sender);
	void __fastcall enerarl1Click(TObject *Sender);
	void __fastcall cadamat1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
