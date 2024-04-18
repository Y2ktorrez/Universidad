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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TStringGrid *StringGrid1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
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
	TMenuItem *N111;
	TMenuItem *N112;
	TMenuItem *N131;
	TMenuItem *N132;
	TMenuItem *N151;
	TMenuItem *N152;
	TMenuItem *N171;
	TMenuItem *N172;
	TMenuItem *N191;
	TMenuItem *N192;
	TMenuItem *Seguimos1;
	TMenuItem *Seguimos2;
	TMenuItem *N221;
	TMenuItem *N222;
	TMenuItem *N251;
	TMenuItem *N252;
	TMenuItem *N261;
	TMenuItem *N262;
	TMenuItem *N281;
	TMenuItem *N282;
	TMenuItem *N301;
	TMenuItem *Seguimos3;
	TMenuItem *Seguimos4;
	TMenuItem *N321;
	TMenuItem *N322;
	TMenuItem *N341;
	TMenuItem *N342;
	TMenuItem *N361;
	TMenuItem *N362;
	TMenuItem *N381;
	TMenuItem *N382;
	TMenuItem *N401;
	TButton *Button1;
	TButton *Button2;
	TMenuItem *Seguimos5;
	TMenuItem *Seguimos6;
	TMenuItem *N421;
	TMenuItem *N422;
	TMenuItem *N441;
	TMenuItem *N442;
	TMenuItem *N461;
	TMenuItem *N471;
	TMenuItem *N472;
	TMenuItem *N491;
	TMenuItem *N492;
	TMenuItem *Seguimos7;
	TMenuItem *Seguimos8;
	TMenuItem *N521;
	TMenuItem *N522;
	TMenuItem *N541;
	TMenuItem *N542;
	TMenuItem *N561;
	TMenuItem *N562;
	TMenuItem *N581;
	TMenuItem *N582;
	TMenuItem *N601;
	TMenuItem *Seguimos9;
	TMenuItem *N611;
	TMenuItem *N612;
	TMenuItem *N631;
	TMenuItem *N632;
	TMenuItem *N651;
	TMenuItem *N661;
	TMenuItem *N662;
	TMenuItem *N681;
	TMenuItem *N682;
	TMenuItem *N701;
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
	void __fastcall N111Click(TObject *Sender);
	void __fastcall N112Click(TObject *Sender);
	void __fastcall N131Click(TObject *Sender);
	void __fastcall N132Click(TObject *Sender);
	void __fastcall N151Click(TObject *Sender);
	void __fastcall N152Click(TObject *Sender);
	void __fastcall N171Click(TObject *Sender);
	void __fastcall N172Click(TObject *Sender);
	void __fastcall N191Click(TObject *Sender);
	void __fastcall N192Click(TObject *Sender);
	void __fastcall Seguimos2Click(TObject *Sender);
	void __fastcall N221Click(TObject *Sender);
	void __fastcall N222Click(TObject *Sender);
	void __fastcall N251Click(TObject *Sender);
	void __fastcall N252Click(TObject *Sender);
	void __fastcall N261Click(TObject *Sender);
	void __fastcall N262Click(TObject *Sender);
	void __fastcall N281Click(TObject *Sender);
	void __fastcall N282Click(TObject *Sender);
	void __fastcall N301Click(TObject *Sender);
	void __fastcall Seguimos4Click(TObject *Sender);
	void __fastcall N321Click(TObject *Sender);
	void __fastcall N322Click(TObject *Sender);
	void __fastcall N341Click(TObject *Sender);
	void __fastcall N342Click(TObject *Sender);
	void __fastcall N361Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall N362Click(TObject *Sender);
	void __fastcall N381Click(TObject *Sender);
	void __fastcall N382Click(TObject *Sender);
	void __fastcall N401Click(TObject *Sender);
	void __fastcall Seguimos6Click(TObject *Sender);
	void __fastcall N421Click(TObject *Sender);
	void __fastcall N422Click(TObject *Sender);
	void __fastcall N441Click(TObject *Sender);
	void __fastcall N442Click(TObject *Sender);
	void __fastcall N461Click(TObject *Sender);
	void __fastcall N471Click(TObject *Sender);
	void __fastcall N472Click(TObject *Sender);
	void __fastcall N491Click(TObject *Sender);
	void __fastcall N492Click(TObject *Sender);
	void __fastcall Seguimos8Click(TObject *Sender);
	void __fastcall N521Click(TObject *Sender);
	void __fastcall N522Click(TObject *Sender);
	void __fastcall N541Click(TObject *Sender);
	void __fastcall N542Click(TObject *Sender);
	void __fastcall N561Click(TObject *Sender);
	void __fastcall N562Click(TObject *Sender);
	void __fastcall N581Click(TObject *Sender);
	void __fastcall N582Click(TObject *Sender);
	void __fastcall N601Click(TObject *Sender);
	void __fastcall N611Click(TObject *Sender);
	void __fastcall N612Click(TObject *Sender);
	void __fastcall N631Click(TObject *Sender);
	void __fastcall N632Click(TObject *Sender);
	void __fastcall N651Click(TObject *Sender);
	void __fastcall N661Click(TObject *Sender);
	void __fastcall N662Click(TObject *Sender);
	void __fastcall N681Click(TObject *Sender);
	void __fastcall N682Click(TObject *Sender);
	void __fastcall N701Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
