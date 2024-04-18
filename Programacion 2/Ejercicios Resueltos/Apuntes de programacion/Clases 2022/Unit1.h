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
	TMenuItem *Apuntedeclase1;
	TMenuItem *Apuntedeclase2;
	TMenuItem *Mayor1;
	TMenuItem *SumaDIgImp1;
	TMenuItem *Clase21;
	TMenuItem *Clase22;
	TMenuItem *MayorMenor1;
	TMenuItem *Clase31;
	TMenuItem *Clase32;
	TStringGrid *StringGrid1;
	TMenuItem *Clase41;
	TMenuItem *Clase42;
	TMenuItem *Sumar1;
	TMenuItem *Clase51;
	TMenuItem *Clase52;
	TMenuItem *Cargar1;
	TMenuItem *Cargar2;
	TMenuItem *Cargar31;
	TMenuItem *Clase71;
	TMenuItem *Clase72;
	TMenuItem *MatrizSodok1;
	void __fastcall Apuntedeclase2Click(TObject *Sender);
	void __fastcall Mayor1Click(TObject *Sender);
	void __fastcall SumaDIgImp1Click(TObject *Sender);
	void __fastcall Clase22Click(TObject *Sender);
	void __fastcall MayorMenor1Click(TObject *Sender);
	void __fastcall Clase32Click(TObject *Sender);
	void __fastcall Clase42Click(TObject *Sender);
	void __fastcall Sumar1Click(TObject *Sender);
	void __fastcall Cargar1Click(TObject *Sender);
	void __fastcall Cargar2Click(TObject *Sender);
	void __fastcall Cargar31Click(TObject *Sender);
	void __fastcall Clase72Click(TObject *Sender);
	void __fastcall MatrizSodok1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
