//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//							MATRICES
//---------------------------------------------------------------------------
void limpiarColumna(TStringGrid *m,byte c,byte f){
if (f>0){
	limpiarColumna(m,c,f-1);
	m->Cells[c-1][f-1]="";
}
}
void limpiar(TStringGrid *m,byte c,byte f){
if (c>0) {
	   limpiar(m,c-1,f);
	   limpiarColumna(m,c,f);
}
}
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	 limpiar(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
	 StringGrid1->ColCount=1;
	 StringGrid1->RowCount=1;
}
//---------------------------------------------------------------------------
//cargar columna mxn ramdom
void llenarfila(TStringGrid *m,byte c,byte f){
if (c>0){
	llenarfila(m,c-1,f);
	m->Cells[c-1][f-1]=Random(20);
}
}
void cargarRandom(TStringGrid *m,byte c,byte f){
if (f>0){
	cargarRandom(m,c,f-1);
	llenarfila(m,c,f);
}
}
void __fastcall TForm2::Button2Click(TObject *Sender)
{
  StringGrid1->ColCount=StrToInt(Edit1->Text);
  StringGrid1->RowCount=StrToInt(Edit2->Text);
  cargarRandom(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------
//ejemplo 1
void llenar1F(TStringGrid *m,byte c,byte f,byte k){
 if (c>0) {
	  m->Cells[c-1][f-1]=k;
	  k--;
	  llenar1F(m,c-1,f,k);
 }
}
void ejer1(TStringGrid *m,byte c,byte f){
if (f>0) {
	ejer1(m,c,f-1);
	llenar1F(m,c,f,f*c);
}
}
void __fastcall TForm2::N11Click(TObject *Sender)
{
  StringGrid1->ColCount=StrToInt(Edit1->Text);
  StringGrid1->RowCount=StrToInt(Edit2->Text);
  ejer1(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------
//ejemplo 2
void llenar2F(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	m->Cells[ac][af]=k;
	llenar2F(m,ac+1,bc,af,k-1);

}
}
void ejer2(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (bf>=af) {
	   k=k-(bc+1);
	   ejer2(m,ac,bc,af+1,bf,k);
	   llenar2F(m,ac,bc,af,k);
}
}
void __fastcall TForm2::N21Click(TObject *Sender)
{
  StringGrid1->ColCount=StrToInt(Edit1->Text);
  StringGrid1->RowCount=StrToInt(Edit2->Text);
  byte k=(StringGrid1->ColCount*StringGrid1->RowCount)+StringGrid1->ColCount;
  ejer2(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenar3C(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   llenar3C(m,c,f-1,k-1);
	   m->Cells [c-1][f-1]=k;
}
}
void ejer3(TStringGrid *m,byte c,byte f){
if (c>0) {
	   ejer3(m,c-1,f);
	   llenar3C(m,c,f,f*c);
}
}
void __fastcall TForm2::N31Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer3(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
}
//---------------------------------------------------------------------------
void llenar4C(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   llenar4C(m,c,f-1,k+1);
	   m->Cells [c-1][f-1]=k;
}
}
void ejer4(TStringGrid *m,byte ac,byte bc,byte f,byte k){
if (bc>=ac) {
	   ejer4(m,ac+1,bc,f,k-1);
	   llenar4C(m,ac,f,((f*k)-(f-1)));
}
}
void __fastcall TForm2::N41Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer4(StringGrid1,1,StringGrid1->ColCount,StringGrid1->RowCount,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void llenar5C(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   llenar5C(m,c,f-1,k);
	   m->Cells[c-1][f-1]=k;
}
}
void ejer5(TStringGrid *m,byte c,byte f,byte k){
if (c>0) {
		ejer5(m,c-1,f,k-1);
		llenar5C(m,c,f,k);
}
}
void __fastcall TForm2::N51Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer5(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,StringGrid1->ColCount);

}
//---------------------------------------------------------------------------
void llenar6F(TStringGrid *m,byte c,byte f,byte k){
if (c>0) {
	   llenar6F(m,c-1,f,k);
	   m->Cells [c-1][f-1]=k;
}
}
void ejer6(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   ejer6(m,c,f-1,k-1);
	   llenar6F(m,c,f,k);
}
}
void __fastcall TForm2::N61Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer6(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void llenar7C(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   llenar7C(m,c,f-1,k);
	   m->Cells [c-1][f-1]=k;
}
}
void ejer7(TStringGrid *m,byte c,byte f,byte k){
if (c>0) {
	   ejer7(m,c-1,f,k+1);
	   llenar7C(m,c,f,k);
}
}

void __fastcall TForm2::N71Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer7(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,1);
}
//---------------------------------------------------------------------------
void llenar8F(TStringGrid *m,byte c,byte f,byte k){
if (c>0) {
	llenar8F(m,c-1,f,k);
	m->Cells[c-1][f-1]=k;
}
}
void ejer8(TStringGrid *m,byte c,byte f,byte k){
if (f>0) {
	   ejer8(m,c,f-1,k+1);
	   llenar8F(m,c,f,k);
}
}
void __fastcall TForm2::N81Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer8(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount,1);
}
//---------------------------------------------------------------------------
void llenar1L9(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (bf>=af){
		 llenar1L9(m,ac,af+1,bf,k);
		 m->Cells[ac][af]=k;
}
}
void llenar2l9(TStringGrid *m,byte ac,byte bc,byte bf,byte k){
if (bc>=ac){
	llenar2l9(m,ac+1,bc,bf,k);
	m->Cells [ac][bf]=k;
}
}
void ejer9(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k,byte n){
if (n>0){
	ejer9(m,ac+1,bc,af,bf-1,k+1,n-1);
	llenar1L9(m,ac,af,bf,k);
	llenar2l9(m,ac,bc,bf,k);
}
}
void __fastcall TForm2::N91Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer9(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void llenarF10(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	   llenarF10(m,ac+1,bc,af,k);
	   m->Cells [ac][af]=k;
}
}
void llenarC10(TStringGrid *m,byte bc,byte af,byte bf,byte k){
if (bf>=af) {
		llenarC10(m,bc,af+1,bf,k);
		m->Cells [bc][af]=k;

}
}
void ejer10(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte k){
if (n>0) {
	   ejer10(m,ac,bc-1,af+1,bf,n-1,k+1);
	   llenarF10(m,ac,bc,af,k);
	   llenarC10(m,bc,af,bf,k);
}
}
void __fastcall TForm2::N101Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer10(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,StringGrid1->ColCount,1);
}
//---------------------------------------------------------------------------
void llenarF11(TStringGrid *m,byte ac,byte bc,byte bf,byte k){
if (bc>=ac){
	llenarF11(m,ac+1,bc,bf,k);
	m->Cells[ac][bf]=k;
}
}
void llenarC11(TStringGrid *m,byte bc,byte af,byte bf,byte k){
 if (bf>=af) {
	llenarC11(m,bc,af+1,bf,k);
	m->Cells [bc][af]=k;
 }
}
void ejer11(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte k){
if (n>0) {
	ejer11(m,ac,bc-1,af,bf-1,n-1,k+1);
	llenarF11(m,ac,bc,bf,k);
	llenarC11(m,bc,af,bf,k);
}
}
void __fastcall TForm2::N111Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer11(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,StringGrid1->ColCount,1);
}
//---------------------------------------------------------------------------
void llenarF12(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	llenarF12(m,ac+1,bc,af,k);
	m->Cells [ac][af]=k;
}
}
void llenarC12(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (bf>=af){
	llenarC12(m,ac,af+1,bf,k);
	m->Cells[ac][af]=k;
}
}
void ejer12(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte k){
if (n>0) {
	ejer12(m,ac+1,bc,af+1,bf,n-1,k+1);
	llenarF12(m,ac,bc,af,k);
	llenarC12(m,ac,af,bf,k);
}
}

void __fastcall TForm2::N121Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer12(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,StringGrid1->ColCount,1);
}
//---------------------------------------------------------------------------
void llenar1C13(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (bf>=af) {
	llenar1C13(m,ac,af+1,bf,k+1);
	m->Cells [ac][af]=k;
}
}
void llenar2C13(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (bf>=af) {
	 llenar2C13(m,ac,af+1,bf,k-1);
	 m->Cells [ac][af]=k;
}
}
void ejer13(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (ac<=bc){
	ejer13(m,ac+1,bc,af,bf,k+(bf+1));     //k+(2*(bf+1)));
	   if (ac%2==0){
	   llenar1C13(m,ac,af,bf,k);
	   }else{
	   llenar2C13(m,ac,af,bf,k+(bf));     //k+((2*(bf+1))-1));
		}
}
}
void __fastcall TForm2::N131Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer13(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);
}
//---------------------------------------------------------------------------
void llenar1C14(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (bf>=af){
	llenar1C14(m,ac,af+1,bf,k-1);
	m->Cells [ac][af]=k;
}
}
void llenar2C14(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (bf>=af) {
	llenar2C14(m,ac,af+1,bf,k+1);
	m->Cells [ac][af]=k;
}
}
void ejer14(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
 if (bc>=ac) {
	 ejer14(m,ac+1,bc,af,bf,k+(bf+1));
	 if (ac%2==0) {
		 llenar1C14(m,ac,af,bf,k+bf);
	 }else{
		 llenar2C14(m,ac,af,bf,k);
	 }
 }
}
void __fastcall TForm2::N141Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer14(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);
}
//---------------------------------------------------------------------------
void llenar1F15(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	llenar1F15(m,ac+1,bc,af,k+1);
	m->Cells [ac][af]=k;
}
}
void llenar2F15(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	llenar2F15(m,ac+1,bc,af,k-1);
	m->Cells [ac][af]=k;
}
}
void ejer15(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (bf>=af) {
	ejer15(m,ac,bc,af+1,bf,k+(bc+1));
	if (af%2==0) {
		llenar1F15(m,ac,bc,af,k);
	}else{
		llenar2F15(m,ac,bc,af,k+(bc));
	}
}
}
void __fastcall TForm2::N151Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer15(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);
}
//---------------------------------------------------------------------------
void llenar1F16(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	llenar1F16(m,ac+1,bc,af,k-1);
	m->Cells [ac][af]=k;
}
}
void llenar2F16(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (bc>=ac) {
	llenar2F16(m,ac+1,bc,af,k+1);
	m->Cells [ac][af]=k;
}
}
void ejer16(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (af<=bf) {
	   ejer16(m,ac,bc,af+1,bf,k+(bc+1));
	   if (af%2==0) {
		   llenar1F16(m,ac,bc,af,k+bc);
	   }else{
		   llenar2F16(m,ac,bc,af,k);
	   }
}
}
void __fastcall TForm2::N161Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejer16(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);
}
//---------------------------------------------------------------------------
//solo para matrices nxn
void llenar1F17(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenar1F17(m,ac+1,bc,af,k);
}
}
void llenar1C17(TStringGrid *m,byte bc,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [bc][af]=k;
	k++;
	llenar1C17(m,bc,af+1,bf,k);
}
}
void llenar2F17(TStringGrid *m,byte ac,int bc,byte bf,byte &k){
if (ac<=bc) {
	m->Cells [bc][bf]=k;
	k++;
	llenar2F17(m,ac,bc-1,bf,k);
}
}
void llenar2C17(TStringGrid *m,byte ac,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [ac][bf]=k;
	k++;
	llenar2C17(m,ac,af,bf-1,k);
}
}
void ejer17(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte &k){
if (n>=k) {
	llenar1F17(m,ac,bc,af,k);
	llenar1C17(m,bc,af+1,bf,k);
	llenar2F17(m,ac,bc-1,bf,k);
	llenar2C17(m,ac,af+1,bf-1,k);
	ejer17(m,ac+1,bc-1,af+1,bf-1,n,k);
}
}
void __fastcall TForm2::N171Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	ejer17(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,n,k);
}
//---------------------------------------------------------------------------
void llenar1F18(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenar1F18(m,ac,bc-1,af,k);
}
}
void llenar1C18(TStringGrid *m,byte ac,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [ac][af]=k;
	k++;
	llenar1C18(m,ac,af+1,bf,k);
}
}
void llenar2F18(TStringGrid *m,byte ac,byte bc,byte bf,byte &k){
if (ac<=bc) {
	m->Cells [ac][bf]=k;
	k++;
	llenar2F18(m,ac+1,bc,bf,k);
}
}
void llenar2C18(TStringGrid *m,byte bc,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [bc][bf]=k;
	k++;
	llenar2C18(m,bc,af,bf-1,k);
}
}
void ejer18(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte &k){
if (n>=k) {
	llenar1F18(m,ac,bc,af,k);
	llenar1C18(m,ac,af+1,bf,k);
	llenar2F18(m,ac+1,bc,bf,k);
	llenar2C18(m,bc,af+1,bf-1,k);
	ejer18(m,ac+1,bc-1,af+1,bf-1,n,k);
}
}
void __fastcall TForm2::N181Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	ejer18(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,n,k);
}
//---------------------------------------------------------------------------
 void llenar1C19(TStringGrid *m,byte ac,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [ac][bf]=k;
	k++;
	llenar1C19(m,ac,af,bf-1,k);
}
}
void llenar1F19(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenar1F19(m,ac+1,bc,af,k);
}
}
void llenar2C19(TStringGrid *m,byte bc,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [bc][af]=k;
	k++;
	llenar2C19(m,bc,af+1,bf,k);
}
}
void llenar2F19(TStringGrid *m,byte ac,int bc,byte bf,byte &k){
if (ac<=bc) {
	m->Cells [bc][bf]=k;
	k++;
	llenar2F19(m,ac,bc-1,bf,k);
}
}
void ejer19(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte &k){
if (n>=k) {
	llenar1C19(m,ac,af,bf,k);
	llenar1F19(m,ac+1,bc,af,k);
	llenar2C19(m,bc,af+1,bf,k);
	llenar2F19(m,ac+1,bc-1,bf,k);
	ejer19(m,ac+1,bc-1,af+1,bf-1,n,k);
}
}
void __fastcall TForm2::N191Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	ejer19(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,n,k);
}
//---------------------------------------------------------------------------
 void llenar1C20(TStringGrid *m,byte ac,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [ac][af]=k;
	k++;
	llenar1C20(m,ac,af+1,bf,k);
}
}
void llenar1F20(TStringGrid *m,byte ac,byte bc,byte bf,byte &k){
if (ac<=bc) {
	m->Cells [ac][bf]=k;
	k++;
	llenar1F20(m,ac+1,bc,bf,k);
}
}
void llenar2C20(TStringGrid *m,byte bc,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [bc][bf]=k;
	k++;
	llenar2C20(m,bc,af,bf-1,k);
}
}
void llenar2F20(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenar2F20(m,ac,bc-1,af,k);
}
}
void ejer20(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte &k){
if (n>=k) {
	llenar1C20(m,ac,af,bf,k);
	llenar1F20(m,ac+1,bc,bf,k);
	llenar2C20(m,bc,af,bf-1,k);
	llenar2F20(m,ac+1,bc-1,af,k);
	ejer20(m,ac+1,bc-1,af+1,bf-1,n,k);
}
}
void __fastcall TForm2::N201Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	ejer20(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,n,k);
}
//---------------------------------------------------------------------------
 void llenar1F21(TStringGrid *m,byte ac,int bc,byte bf,byte &k){
if (ac<=bc) {
	m->Cells [bc][bf]=k;
	k++;
	llenar1F21(m,ac,bc-1,bf,k);
}
}
void llenar1C21(TStringGrid *m,byte ac,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [ac][bf]=k;
	k++;
	llenar1C21(m,ac,af,bf-1,k);
}
}
void llenar2F21(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenar2F21(m,ac+1,bc,af,k);
}
}
void llenar2C21(TStringGrid *m,byte bc,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [bc][af]=k;
	k++;
	llenar2C21(m,bc,af+1,bf,k);
}
}
void ejer21(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte n,byte &k){
if (n>=k) {
	llenar1F21(m,ac,bc,bf,k);
	llenar1C21(m,ac,af,bf-1,k);
	llenar2F21(m,ac+1,bc,af,k);
	llenar2C21(m,bc,af+1,bf-1,k);
	ejer21(m,ac+1,bc-1,af+1,bf-1,n,k);
}
}
void __fastcall TForm2::N211Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	byte n=StringGrid1->ColCount*StringGrid1->RowCount;
	ejer21(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,n,k);
}
//---------------------------------------------------------------------------
void llenar1C22(TStringGrid *m,byte ac,byte af,byte bf,byte k){
 if (af<=bf) {
	 m->Cells [ac][af]=k;
	 llenar1C22(m,ac,af+1,bf,k);
 }
}
void llenar1F22(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	llenar1F22(m,ac+1,bc,af,k);
}
}
void ejer22(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (ac<=bc) {
	llenar1C22(m,ac,af,bf,k);
	llenar1F22(m,ac+1,bc,bf,k+1);
	llenar1C22(m,bc,af,bf-1,k+2);
	llenar1F22(m,ac+1,bc-1,af,k+3);
	ejer22(m,ac+1,bc-1,af+1,bf-1,k+4);
}
}
void __fastcall TForm2::N221Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejer22(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenar1F23(TStringGrid *m,byte ac,byte bc,byte af,byte k){
   if (ac<=bc){
	m->Cells [ac][af]=k;
	llenar1F23(m,ac+1,bc,af,k);
	}
}
void llenar1C23(TStringGrid *m,byte bc,byte af,byte bf,byte k){
  if (af<=bf) {
	  m->Cells [bc][af]=k;
	  llenar1C23(m,bc,af+1,bf,k);
  }
}
void ejer23(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
	if (ac<=bc) {
		llenar1F23(m,ac,bc,af,k);
		llenar1C23(m,bc,af,bf,k);
		llenar1F23(m,ac,bc-1,bf,k+1);
		llenar1C23(m,ac,af+1,bf,k+1);
		ejer23(m,ac+1,bc-1,af+1,bf-1,k+2);
	}
}
void __fastcall TForm2::N231Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejer23(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenar1F24(TStringGrid *m,byte ac,byte bc,byte af,byte k){
   if (ac<=bc){
	m->Cells [ac][af]=k;
	llenar1F24(m,ac+1,bc,af,k);
	}
}
void llenar1C24(TStringGrid *m,byte bc,byte af,byte bf,byte k){
  if (af<=bf) {
	  m->Cells [bc][af]=k;
	  llenar1C24(m,bc,af+1,bf,k);
  }
}
void ejer24(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
	if (ac<=bc) {
		llenar1C24(m,ac,af,bf,k);
		llenar1F24(m,ac,bc,bf,k);
		llenar1C24(m,bc,af,bf-1,k+1);
		llenar1F24(m,ac+1,bc,af,k+1);
		ejer24(m,ac+1,bc-1,af+1,bf-1,k+2);
	}
}

void __fastcall TForm2::N142Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejer24(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenar125(TStringGrid *m,byte k,int j,byte n,byte &c){
if (k<=n) {
	m->Cells [j][k]=c;
	c++;
	llenar125(m,k+1,j-1,n,c);
}
}
void llenar225(TStringGrid *m,byte k,byte j,byte n,byte &c){
	if (n>0) {
		m->Cells[k][j]=c;
		c++;
		llenar225(m,k-1,j+1,n-1,c);
}
}
void ejer25(TStringGrid *m,byte ac,int bc,byte af,int bf,byte &k,byte n){
 if (n>0) {
	 if (bf>=0) {
	   llenar125(m,0,af,af,k);
	   ejer25(m,ac,bc,af+1,bf-1,k,n-1);
	 }else{
	   llenar225(m,bc,ac,n,k);
	   ejer25(m,ac+1,bc,af,bf,k,n-1);
	}
}
}
void __fastcall TForm2::N251Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte n=(StringGrid1->ColCount*2)-1;
	byte k=1;
	ejer25(StringGrid1,1,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,n);
}
//---------------------------------------------------------------------------
void llenar126(TStringGrid *m,byte k,int j,byte n,byte &c){
if (k<=n) {
	m->Cells [k][j]=c;
	c++;
	llenar126(m,k+1,j-1,n,c);
}
}
void llenar226(TStringGrid *m,byte k,byte j,byte n,byte &c){
	if (n>0) {
		m->Cells[j][k]=c;
		c++;
		llenar226(m,k-1,j+1,n-1,c);
}
}
void ejer26(TStringGrid *m,byte ac,int bc,byte af,int bf,byte &k,byte n){
 if (n>0) {
	 if (bf>=0) {
	   llenar126(m,0,af,af,k);
	   ejer26(m,ac,bc,af+1,bf-1,k,n-1);
	 }else{
	   llenar226(m,bc,ac,n,k);
	   ejer26(m,ac+1,bc,af,bf,k,n-1);
	}
}
}
void __fastcall TForm2::N261Click(TObject *Sender)
{
    StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte n=(StringGrid1->ColCount*2)-1;
	byte k=1;
	ejer26(StringGrid1,1,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,n);
}
//---------------------------------------------------------------------------
void llenarT1(TStringGrid *m,byte k,int j,byte n,byte &c){
if (k<=n) {
	m->Cells [j][k]=c;
	c++;
	llenarT1(m,k+1,j-1,n,c);
}
}
void ejerT1(TStringGrid *m,byte ac,byte bc,byte &k){
if (ac<=bc){
		llenarT1(m,0,ac,ac,k);
		ejerT1(m,ac+1,bc,k);
}
}

void __fastcall TForm2::N12Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT1(StringGrid1,0,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT2(TStringGrid *m,byte k,byte j,byte n,byte &c){
	if (n>0) {
		m->Cells[k][j]=c;
		c++;
		llenarT2(m,k-1,j+1,n-1,c);
}
}
void ejerT2(TStringGrid *m,byte ac,byte bc,byte bf,byte &k){
if (ac<=(bf)) {
		llenarT2(m,bf,ac,bc+1,k);
		ejerT2(m,ac+1,bc-1,bf,k);
}
}
void __fastcall TForm2::N22Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT2(StringGrid1,0,StringGrid1->ColCount-1,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT3(TStringGrid *m,int k,byte j,byte &c){
if (k>=0) {
	m->Cells [k][j]=c;
	c++;
	llenarT3(m,k-1,j+1,c);
}
}
void ejerT3(TStringGrid *m,byte ac,int bc,byte &k){
if (bc>=0) {
	llenarT3(m,bc,ac,k);
	ejerT3(m,ac,bc-1,k);
}
}
void __fastcall TForm2::N32Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT3(StringGrid1,0,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT4(TStringGrid *m,int k,byte j,byte &c){
if (k>=0) {
	m->Cells [j][k]=c;
	c++;
	llenarT4(m,k-1,j+1,c);
}
}
void ejerT4(TStringGrid *m,byte ac,int bc,byte &k){
if (bc>=0) {
	llenarT4(m,bc,ac,k);
	ejerT4(m,ac,bc-1,k);
}
}
void __fastcall TForm2::N42Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT4(StringGrid1,0,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT5(TStringGrid *m,byte k,byte j,byte n,byte &c){
if (n>0) {
	m->Cells [k][j]=c;
	c++;
	llenarT5(m,k+1,j-1,n-1,c);
}
}
void ejerT5(TStringGrid *m,byte ac,int bc,byte af,byte &k){
   if (bc>=0) {
	   llenarT5(m,bc,af,ac,k);
	   ejerT5(m,ac+1,bc-1,af,k);
   }
}
void __fastcall TForm2::N52Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT5(StringGrid1,1,StringGrid1->ColCount-1,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT6(TStringGrid *m,byte k,byte j,byte n,byte &c){
if (n>0) {
	m->Cells [j][k]=c;
	c++;
	llenarT6(m,k+1,j-1,n-1,c);
}
}
void ejerT6(TStringGrid *m,byte ac,int bc,byte af,byte &k){
   if (bc>=0) {
	   llenarT6(m,bc,af,ac,k);
	   ejerT6(m,ac+1,bc-1,af,k);
   }
}
void __fastcall TForm2::N62Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT6(StringGrid1,1,StringGrid1->ColCount-1,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
 void llenarT7(TStringGrid *m,byte k,byte j,byte n,byte &c){
	if (n>0) {
	m->Cells [j][k]=c;
	c++;
	llenarT7(m,k+1,j-1,n-1,c);
	}
}
 void llenar2T7(TStringGrid *m,byte k,byte j,byte n,byte &c){
	if (n>0) {
	m->Cells [k][j]=c;
	c++;
	llenar2T7(m,k+1,j-1,n-1,c);
	}
}
void ejerT7(TStringGrid *m,byte ac,int bc,byte af,byte &k){
   if (bc>=0) {
	  if(bc%2==0){
	   llenarT7(m,bc,af,ac,k);
	   }else{
	   llenar2T7(m,bc,af,ac,k);
	   }
	   ejerT7(m,ac+1,bc-1,af,k);
   }
}
void __fastcall TForm2::N72Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT7(StringGrid1,1,StringGrid1->ColCount-1,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT8(TStringGrid *m,byte k,byte j,byte n,byte &c){
	if (n>0) {
	m->Cells [k][j]=c;
	c++;
	llenarT8(m,k+1,j-1,n-1,c);
	}
}
 void llenar2T8(TStringGrid *m,byte k,byte j,byte n,byte &c){
	if (n>0) {
	m->Cells [j][k]=c;
	c++;
	llenar2T8(m,k+1,j-1,n-1,c);
	}
}
void ejerT8(TStringGrid *m,byte ac,int bc,byte af,byte &k){
   if (bc>=0) {
	  if(bc%2==0){
	   llenarT8(m,bc,af,ac,k);
	   }else{
	   llenar2T8(m,bc,af,ac,k);
	   }
	   ejerT8(m,ac+1,bc-1,af,k);
   }
}
void __fastcall TForm2::N82Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT8(StringGrid1,1,StringGrid1->ColCount-1,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT9(TStringGrid *m,byte k,int j,byte n,byte &c){
if (k<=n) {
	m->Cells [j][k]=c;
	c++;
	llenarT9(m,k+1,j-1,n,c);
}
}
void llenar2T9(TStringGrid *m,byte k,int j,byte n,byte &c){
if (k<=n) {
	m->Cells [k][j]=c;
	c++;
	llenar2T9(m,k+1,j-1,n,c);
}
}
void ejerT9(TStringGrid *m,byte ac,byte bc,byte &k){
if (ac<=bc){
		if (ac%2==0) {
			llenarT9(m,0,ac,ac,k);
		}else{
			llenar2T9(m,0,ac,ac,k);
		}
		ejerT9(m,ac+1,bc,k);
}
}
void __fastcall TForm2::N92Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT9(StringGrid1,0,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT10(TStringGrid *m,byte k,int j,byte n,byte &c){
if (k<=n) {
	m->Cells [k][j]=c;
	c++;
	llenarT10(m,k+1,j-1,n,c);
}
}
void llenar2T10(TStringGrid *m,byte k,int j,byte n,byte &c){
if (k<=n) {
	m->Cells [j][k]=c;
	c++;
	llenar2T10(m,k+1,j-1,n,c);
}
}
void ejerT10(TStringGrid *m,byte ac,byte bc,byte &k){
if (ac<=bc){
		if (ac%2==0) {
			llenarT10(m,0,ac,ac,k);
		}else{
			llenar2T10(m,0,ac,ac,k);
		}
		ejerT10(m,ac+1,bc,k);
}
}
void __fastcall TForm2::N102Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT10(StringGrid1,0,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarTF11(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (bc>=ac) {
	m->Cells[ac][af]=k;
	k++;
	llenarTF11(m,ac+1,bc,af,k);
}
}
void ejerT11(TStringGrid *m,byte ac,int bc,byte af,byte bf,byte &k){
if (bc>=ac) {
	llenarTF11(m,ac,bc,af,k);
	ejerT11(m,ac,bc-1,af+1,bf,k);
}
}
void __fastcall TForm2::N112Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT11(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenarTF12(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (bc>=ac) {
	m->Cells[bc][af]=k;
	k++;
	llenarTF12(m,ac,bc-1,af,k);
}
}
void ejerT12(TStringGrid *m,byte ac,int bc,byte af,byte bf,byte &k){
if (bf>=af) {
	llenarTF12(m,ac,bc,af,k);
	ejerT12(m,ac,bc-1,af+1,bf,k);
}
}
void __fastcall TForm2::N122Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT12(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenarTF13(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenarTF13(m,ac,bc-1,af,k);
}
}
void ejerT13(TStringGrid *m,byte ac,int bc,byte af,byte bf,byte &k){
if (af<=bf) {
	llenarTF13(m,bc,bf,af,k);
	ejerT13(m,ac,bc-1,af+1,bf,k);
}
}
void __fastcall TForm2::N132Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT13(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenarTF14(TStringGrid *m,byte ac,int bc,byte bf,byte &k){
if (ac<=bc) {
	m->Cells [bc][bf]=k;
	k++;
	llenarTF14(m,ac,bc-1,bf,k);
}
}
void ejerT14(TStringGrid *m,byte ac,int bc,byte af,int bf,byte &k){
if (af<=bf) {
	llenarTF14(m,ac,bc,bf,k);
	ejerT14(m,ac+1,bc,af,bf-1,k);
}
}
void __fastcall TForm2::N143Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT14(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenarTD15(TStringGrid *m,byte k,byte j,byte n,byte c){
 if (k<=n){
	m->Cells [k][j]=c;
	llenarTD15(m,k+1,j+1,n,c);
 }
}
void ejerT15(TStringGrid *m,byte ac,byte bc,byte bf,byte k){
if (ac<=bc){
	llenarTD15(m,ac,0,bf,k);
	ejerT15(m,ac+1,bc,bf,k+1);
}
}
void __fastcall TForm2::N152Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT15(StringGrid1,0,StringGrid1->ColCount-1,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenarTD16(TStringGrid *m,byte k,int j,byte c){
if (0<=j) {
		m->Cells [k][j]=c;
		llenarTD16(m,k+1,j-1,c);
}
}
void ejerT16(TStringGrid *m,byte ac,int bc,byte k){
if (ac<=bc) {
	llenarTD16(m,ac,bc,k);
	ejerT16(m,ac,bc-1,k+1);
}
}
void __fastcall TForm2::N162Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT16(StringGrid1,0,StringGrid1->ColCount-1,k);
}
//---------------------------------------------------------------------------
void llenarTF17(TStringGrid *m,byte ac,byte bc,byte bf,byte &k){
	  if (ac<=bc) {
			m->Cells [ac][bf]=k;
			k++;
			llenarTF17(m,ac+1,bc,bf,k);
	  }
}
void llenarT2F17(TStringGrid *m,byte ac,int bc,byte bf,byte &k){
	  if (ac<=bc) {
			m->Cells [bc][bf]=k;
			k++;
			llenarT2F17(m,ac,bc-1,bf,k);
	  }
}
void ejerT17(TStringGrid *m,byte ac,byte bc,byte af,int bf,byte &k,bool &b){
	if (af<=bf) {
		if (b==true) {
			llenarTF17(m,ac,bc,bf,k);
			b=false;
		}else{
			llenarT2F17(m,ac,bc,bf,k);
			b=true;
		}
		ejerT17(m,ac+1,bc,af,bf-1,k,b);
		}
}

void __fastcall TForm2::N172Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT17(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);

}
//---------------------------------------------------------------------------
void llenarT18(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenarT18(m,ac+1,bc,af,k);
}
}
void llenarT218(TStringGrid *m,byte ac,int bc,byte af,byte &k){
	if (ac<=bc) {
		m->Cells [bc][af]=k;
		k++;
		llenarT218(m,ac,bc-1,af,k);
	}
}
void ejerT18(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (af<=bf) {
	if (b==true) {
		llenarT18(m,ac,bc,af,k);
		b=false;
	}else{
		llenarT218(m,ac,bc,af,k);
		b=true;
	}
	ejerT18(m,ac,bc-1,af+1,bf,k,b);
}
}
void __fastcall TForm2::N182Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT18(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}
//---------------------------------------------------------------------------
void llenarT19(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenarT19(m,ac,bc-1,af,k);
}
}
void llenarT219(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
	if (ac<=bc) {
		m->Cells [ac][af]=k;
		k++;
		llenarT219(m,ac+1,bc,af,k);
	}
}
void ejerT19(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (af<=bf) {
	if (b==true) {
		llenarT19(m,ac,bc,af,k);
		b=false;
	}else{
		llenarT219(m,ac,bc,af,k);
		b=true;
	}
	ejerT19(m,ac,bc-1,af+1,bf,k,b);
}
}
void __fastcall TForm2::N192Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT19(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}
//---------------------------------------------------------------------------
void llenarT20(TStringGrid *m,byte ac,int bc,byte bf,byte &k){
	if (ac<=bc) {
		m->Cells [bc][bf]=k;
		k++;
		llenarT20(m,ac,bc-1,bf,k);

	}
}
void llenarT220(TStringGrid *m,byte ac,byte bc,byte bf,byte &k){
	 if (ac<=bc) {
			   m->Cells [ac][bf]=k;
			   k++;
			   llenarT220(m,ac+1,bc,bf,k);
	 }
}
void ejerT20(TStringGrid *m,byte ac,byte bc,byte af,int bf,byte &k,bool &b){
	if (af<=bf) {
		if (b==true) {
			llenarT20(m,ac,bc,bf,k);
			b=false;
		}else{
			llenarT220(m,ac,bc,bf,k);
			b=true;
		}
		ejerT20(m,ac+1,bc,af,bf-1,k,b);
	}
}
void __fastcall TForm2::N202Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT20(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}

//---------------------------------------------------------------------------
void llenarT21(TStringGrid *m,byte bc,byte af,int bf,byte &k){
if (af<=bf) {
	  m->Cells [bc][bf]=k;
	  k++;
	  llenarT21(m,bc,af,bf-1,k);
}
}
void llenarT221(TStringGrid *m,byte bc,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [bc][af]=k;
	k++;
	llenarT221(m,bc,af+1,bf,k);
}
}
void ejerT21(TStringGrid *m,byte ac,int bc,byte af,byte bf,byte &k,bool &b){
if (ac<=bc) {
	if (b==true) {
		llenarT21(m,bc,af,bf,k);
		b=false;
	}else{
		llenarT221(m,bc,af,bf,k);
		b=true;
	}
	ejerT21(m,ac,bc-1,af+1,bf,k,b);
}
}
void __fastcall TForm2::N212Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT21(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}

//---------------------------------------------------------------------------
void llenarT22(TStringGrid *m,byte ac,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [ac][af]=k;
	k++;
	llenarT22(m,ac,af+1,bf,k);
}
}
void llenarT222(TStringGrid *m,byte ac,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [ac][bf]=k;
	k++;
	llenarT222(m,ac,af,bf-1,k);
}
}
void ejerT22(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (ac<=bc) {
	if (b==true) {
		llenarT22(m,ac,af,bf,k);
		b=false;
	}else{
		llenarT222(m,ac,af,bf,k);
		b=true;
	}
	ejerT22(m,ac+1,bc,af+1,bf,k,b);
}
}
void __fastcall TForm2::N222Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT22(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}
//---------------------------------------------------------------------------
void llenarT23(TStringGrid *m,byte bc,byte af,byte bf,byte &k){
	if (af<=bf) {
		m->Cells [bc][af]=k;
		k++;
		llenarT23(m,bc,af+1,bf,k);
	}
}
void llenarT223(TStringGrid *m,byte bc,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [bc][bf]=k;
	k++;
	llenarT223(m,bc,af,bf-1,k);
}
}
void ejerT23(TStringGrid *m,byte ac,int bc,byte af,byte bf,byte &k,bool &b){
if (ac<=bc) {
	if (b==true) {
		llenarT23(m,bc,af,bf,k);
		b=false;
	}else{
	  llenarT223(m,bc,af,bf,k);
	  b=true;
	}
	ejerT23(m,ac,bc-1,af+1,bf,k,b);
}
}
void __fastcall TForm2::N232Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT23(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}

//---------------------------------------------------------------------------
void llenarT24(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenarT24(m,ac+1,bc,af,k);
}
}
void llenarT224(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenarT224(m,ac,bc-1,af,k);
}
}
void ejerT24(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (af<=bf) {
		if (b==true) {
			llenarT224(m,0,ac,af,k);
			b=false;
		}else{
			llenarT24(m,0,ac,af,k);
			b=true;
		}
		ejerT24(m,ac+1,bc,af+1,bf,k,b);
}
}
void __fastcall TForm2::N144Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT24(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}
//---------------------------------------------------------------------------
//caracol forma triangular
void llenarT25(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
  //	k++;
	llenarT25(m,ac+1,bc,af,k);
}
}
void llenarT225(TStringGrid *m,byte ac,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [ac][af]=k;
   //	k++;
	llenarT225(m,ac,af+1,bf,k);
}
}
void llenarT325(TStringGrid *m,byte k,byte j,byte n,byte &c){
if (n>0) {
	m->Cells [k][j]=c;
	//c++;
	llenarT325(m,k+1,j-1,n-1,c);
}
}
void ejerT25(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,byte n){
if (n>0) {
	llenarT25(m,ac,bc,af,k);
	llenarT225(m,ac,af,bf,k);
	llenarT325(m,ac,bc,bc,k);
	k++;
	ejerT25(m,ac+1,bc-2,af+1,bf-2,k,n-1);
}
}
void __fastcall TForm2::N252Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT25(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,3);
}
//---------------------------------------------------------------------------
void llenarT26(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	llenarT26(m,ac+1,bc,af,k);
}
}
void llenarT226(TStringGrid *m,byte ac,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [ac][af]=k;
	llenarT226(m,ac,af+1,bf,k);
}
}
void ejerT26(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
	if (ac<=bc) {
		llenarT26(m,ac,bc,af,k);
		llenarT226(m,ac,af,bf,k);
		ejerT26(m,ac+1,bc-1,af+1,bf-1,k+1);
	}
}
void __fastcall TForm2::N262Click(TObject *Sender)
{
	limpiar(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	ejerT26(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k);
}
//---------------------------------------------------------------------------
void llenarT27(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenarT27(m,ac,bc-1,af,k);
}
}
void llenarT227(TStringGrid *m,byte ac,byte af,byte bf,byte &k){
if (af<=bf) {
	m->Cells [ac][af]=k;
	k++;
	llenarT227(m,ac,af+1,bf,k);
}
}
void llenarT327(TStringGrid *m,byte ac,byte af,int bf,byte &k){
if (af<=bf) {
	m->Cells [ac][bf]=k;
	k++;
	llenarT327(m,ac,af,bf-1,k);
}
}
void llenarT427(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenarT427(m,ac+1,bc,af,k);
}
}
void ejerT27(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
	if (ac<=bc) {
	if (b==true) {
       llenarT27(m,ac,bc,af,k);
	   llenarT227(m,ac,af+1,bf,k);
	   b=false;
	}else{
		llenarT327(m,ac,af,bf,k);
		llenarT427(m,ac+1,bc,af,k);
		b=true;
	}
	ejerT27(m,ac+1,bc-1,af+1,bf-1,k,b);
	}
}
void __fastcall TForm2::N271Click(TObject *Sender)
{
	limpiar(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
	ejerT27(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}
//---------------------------------------------------------------------------
void llenarE1(TStringGrid *m,byte ac,int bc,byte af,byte k){
	if (ac<=bc) {
		m->Cells [bc][af]=k;
		llenarE1(m,ac,bc-1,af,k+1);
	}
}
void ejerE1(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (af<=bf) {
	llenarE1(m,ac,bc,af,k);
	ejerE1(m,ac,bc,af+1,bf,k+1);
}
}
void __fastcall TForm2::N13Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejerE1(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);
}
//---------------------------------------------------------------------------
void llenarE2(TStringGrid *m,byte ac,byte bc,byte af,byte k){
	if (ac<=bc) {
		m->Cells [ac][af]=k;
		llenarE2(m,ac+1,bc,af,k+1);
	}
}
void ejerE2(TStringGrid *m,byte ac,byte bc,byte af,byte bf){
if (ac<=bc) {
	llenarE2(m,ac,bc,af,1);
	ejerE2(m,ac+1,bc,af+1,bf);
}
}
void __fastcall TForm2::N23Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	ejerE2(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1);
}
//---------------------------------------------------------------------------
void modex13_1(TStringGrid *v,byte fa,byte fb, byte ca, byte cb,String &cad)
{   byte m=fb-fa+1;
	if ((m>0)&&(cad.Length()>0)){
		v->Cells [ca][fa]=cad[1];
		cad.Delete(1,1);
		modex13_1(v,fa+1,fb,ca,cb,cad);}
	}
void modex13(TStringGrid *v,byte fa,byte fb, byte ca, byte cb,String &cad)
{
	if (cad.Length()>0 ){
		modex13_1(v,fa,fb,ca,cb,cad);
		modex13(v,fa,fb,ca+1,cb,cad);
	}
}

//void __fastcall TForm1::cadenaamatriz1Click(TObject *Sender)
//{   eliminarc(StringGrid1,0,StringGrid1->RowCount ,0,StringGrid1->ColCount );
////	String cad=Edit1->Text;
 //	byte k=cad.Length() ;
//	byte m=floor(sqrt(k))+1;
 //	byte n=(k%2!=0)?ceil(sqrt(k)):floor(sqrt(k));
  //	StringGrid1->ColCount =m;
 //	StringGrid1->RowCount =n;
//	modex13(StringGrid1,0,n-1,0,m-1,cad);
//}
//-------------------------------------------------------------------------------
void llenarColumna(TStringGrid *m,byte ac,byte af,byte bf,String &s){
	if ((af<=bf)&&(s.Length()>0)) {
			 m->Cells [ac][af]=s[1];
			 s.Delete(1,1);
			 llenarColumna(m,ac,af+1,bf,s);
	}
}
void cadamtr(TStringGrid *m,byte ac,byte bc,byte af,byte bf,String &s){
	if (ac<=bc) {
		  llenarColumna(m,ac,af,bf,s);
		  cadamtr(m,ac+1,bc,af,bf,s);
	}
}
void __fastcall TForm2::cadamatrix1Click(TObject *Sender)
{
   String s=Edit1->Text;
   byte l=s.Length();
   byte c=floor(sqrt(l))+1;
   byte f;
   if (l%2==0) {
		f=floor(sqrt(l));
   }else{
		f=ceil(sqrt(l));
   }
   StringGrid1->ColCount =c;
   StringGrid1->RowCount =f;
   cadamtr(StringGrid1,0,c-1,0,f-1,s);
}
//---------------------------------------------------------------------------
void llenarE3(TStringGrid *m,byte ac,int bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	k++;
	llenarE3(m,ac,bc-1,af,k);
}
}
void llenarE23(TStringGrid *m,byte ac,byte bc,byte af,byte &k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	k++;
	llenarE23(m,ac+1,bc,af,k);
}
}
void ejerE3(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (af<=bf) {
	if (b==true) {
		llenarE3(m,bc,bf,af,k);
		b=false;
	}else{
		llenarE23(m,bc,bf,af,k);
		b=true;
	}
	ejerE3(m,ac,bc-1,af+1,bf,k,b);
}
}
void ejer2E3(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte &k,bool &b){
if (af<=bf) {
	if (b==true) {
		llenarE3(m,ac,bc,af,k);
		b=false;
	}else{
		llenarE23(m,ac,bc,af,k);
		b=true;
	}
	ejer2E3(m,ac-1,bc,af+1,bf,k,b);
}
}
void __fastcall TForm2::N33Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	byte k=1;
	bool b=true;
   //	ejer2E3(StringGrid1,StringGrid1->ColCount-1,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
	ejerE3(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,k,b);
}
//---------------------------------------------------------------------------
void llenarE4(TStringGrid *m,byte ac,byte bc,byte af,byte k){
if (ac<=bc) {
	m->Cells [ac][af]=k;
	llenarE4(m,ac+1,bc,af,k);
}
}
void llenarCE4(TStringGrid *m,byte bc,byte af,byte bf,byte k){
if (af<=bf) {
	m->Cells [bc][af]=k;
	llenarCE4(m,bc,af+1,bf,k);
}
}
void ejerE4(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (ac<=bc) {
	llenarE4(m,ac,bc,af,k);
	llenarCE4(m,bc,af,bf-1,k);
	if (ac!=bc){
	k++;
	llenarE4(m,ac,bc,bf,k);
	llenarCE4(m,ac,af+1,bf,k);
	}
	ejerE4(m,ac+1,bc-1,af+1,bf-1,k+1);
}
}
void __fastcall TForm2::N43Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	if (StrToInt(Edit1->Text)==1) {
		 StringGrid1->Cells [0][0]=1;
	}else{
	ejerE4(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);
	}
}
//---------------------------------------------------------------------------
void llenarEC5(TStringGrid *m,byte ac,byte af,byte bf,byte k){
if (af<=bf) {
	m->Cells [ac][af]=k;
	llenarEC5(m,ac,af+1,bf,k);
}
}
void llenarEF5(TStringGrid *m,byte ac,byte bc,byte bf,byte k){
if (ac<=bc) {
	m->Cells [ac][bf]=k;
	llenarEF5(m,ac+1,bc,bf,k);
}
}
void ejerE5(TStringGrid *m,byte ac,byte bc,byte af,byte bf,byte k){
if (ac<=bc) {
	llenarEC5(m,ac,af,bf,k);
	llenarEF5(m,ac,bc-1,bf,k);
	if (ac!=bc) {
		k++;
		llenarEC5(m,bc,af,bf,k);
		llenarEF5(m,ac+1,bc,af,k);
	}
	ejerE5(m,ac+1,bc-1,af+1,bf-1,k+1);
}
}
void __fastcall TForm2::N53Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	if (StrToInt(Edit1->Text)==1) {
		 StringGrid1->Cells [0][0]=1;
	}else{
	ejerE5(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1,1);
	}
}
//---------------------------------------------------------------------------
void llenarE6(TStringGrid *m,byte ac,int bc,byte af,byte k){
if (ac<=bc) {
	m->Cells [bc][af]=k;
	llenarE6(m,ac,bc-1,af,k+1);
}
}
void llenarE26(TStringGrid *m,byte ac,byte bc,byte af){
if (ac<=bc) {
	m->Cells [ac][af]=1;
	llenarE26(m,ac+1,bc,af);
}
}
void ejerE6(TStringGrid *m,byte ac,byte bc,byte af,byte bf){
if (af<=bf) {
	llenarE6(m,ac,bc,af,1);
	ejerE6(m,ac,bc-1,af+1,bf);
}
}
void ejer2E6(TStringGrid *m,byte ac,byte bc,byte af,int bf){
if (ac<=bc) {
	llenarE26(m,ac,bc,bf);
	ejer2E6(m,ac+1,bc,af,bf-1);
}
}
void __fastcall TForm2::N63Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	StringGrid1->RowCount=StrToInt(Edit2->Text);
	if (StrToInt(Edit1->Text)==1) {
		 StringGrid1->Cells [0][0]=1;
	}else{
	ejerE6(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1);
	ejer2E6(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1);
	}
}
//-----------------------------------------------------------------------------
void llenarde1(TStringGrid *m,byte ac,byte bc,byte af){
if (ac<=bc) {
	if (m->Cells [ac][af]== ""){
		m->Cells [ac][af]=1;
	}
	llenarde1(m,ac+1,bc,af);
}
}
void expe(TStringGrid *m,byte ac,byte bc,byte af,byte bf){
if (af<=bf) {
	llenarde1(m,ac,bc,af);
	expe(m,ac,bc,af+1,bf);
}
}
void __fastcall TForm2::llenarde1losvacios1Click(TObject *Sender)
{
	expe(StringGrid1,0,StringGrid1->ColCount-1,0,StringGrid1->RowCount-1);
}
//------------------------------------------------------------------------------
//							VECTORES
//------------------------------------------------------------------------------
void cargarVECTOR(TStringGrid *v,byte a,byte b){
byte n=b-a+1;
if (n>0) {
	   v->Cells [a][0]=Random(20);
	   cargarVECTOR(v,a+1,b);
}
}
void __fastcall TForm2::cargarRND1Click(TObject *Sender)
{
	StringGrid1->ColCount=StrToInt(Edit1->Text);
	cargarVECTOR(StringGrid1,0,StringGrid1->ColCount-1);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::cargar2RND1Click(TObject *Sender)
{
	StringGrid2->ColCount=StrToInt(Edit2->Text);
	cargarVECTOR(StringGrid2,0,StringGrid1->ColCount-1);
}
//---------------------------------------------------------------------------
bool buscarD(TStringGrid *v,byte a,byte b,byte d){
 byte n=b-a+1;
 bool t;
 if (n==0){
	 t=false;
 }else{
	 byte l=StrToInt(v->Cells [a][0]);
	 t=buscarD(v,a+1,b,d);
	 if (l==d) {
		 t=true;
	 }
 }
 return t;
}
void __fastcall TForm2::N14Click(TObject *Sender)
{
 Edit3->Text=BoolToStr(buscarD(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(Edit1->Text)));
}
//---------------------------------------------------------------------------
byte cantidad(TStringGrid *v,byte a,byte b,byte d){
 byte n=b-a+1;
 byte c;
 if (n==0) {
	 c=0;
 }else{
	 byte k=StrToInt(v->Cells [a][0]);
	 c=cantidad(v,a+1,b,d);
	 if (k==d) {
		 c++;
	 }
 }
 return c;
}
void __fastcall TForm2::cantidad1Click(TObject *Sender)
{
 Edit3->Text=StrToInt(cantidad(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(Edit1->Text)));
}
//---------------------------------------------------------------------------
void recorrer(TStringGrid *v,byte a,byte b){
byte n=b-a+1;
if (n>0) {
	v->Cells [a][0]=v->Cells [a+1][0];
	recorrer(v,a+1,b);
}
}
void __fastcall TForm2::recorrer1Click(TObject *Sender)
{
	 recorrer(StringGrid1,StrToInt(Edit1->Text),StringGrid1->ColCount-1);
	 StringGrid1->ColCount--;
}
//---------------------------------------------------------------------------
void anadir(TStringGrid *v,byte a,int b,byte d){
byte n=b-a+1;
if (n>0) {
		v->Cells [b+1][0]=v->Cells [b][0];
		anadir(v,a,b-1,d);
		if (b==a) {
			v->Cells [a][0]=d;
		}
}
}
void __fastcall TForm2::anadirenp1Click(TObject *Sender)
{
	 anadir(StringGrid1 ,StrToInt(Edit1->Text),StringGrid1->ColCount-1,StrToInt(Edit2->Text));
	 StringGrid1->ColCount++;
}
//---------------------------------------------------------------------------
void eliminarX(TStringGrid *v,byte a,byte b,byte x){
byte n=b-a+1;
if (n>0) {
	   byte k=StrToInt(v->Cells [a][0]);
	   eliminarX(v,a+1,b,x);
	   if (x==k) {
		   recorrer(v,a,b);
		   v->ColCount --;
	   }
}
}
void __fastcall TForm2::eliminar1Click(TObject *Sender)
{
 //	byte c= cantidad(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(Edit1->Text));
	eliminarX(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(Edit1->Text));
  //	StringGrid1->ColCount=StringGrid1->ColCount-c;
}
//---------------------------------------------------------------------------
void invertir(TStringGrid *v,byte a,byte b){
	if ((a!=b)&&(a<b)){
		invertir(v,a+1,b-1);
				String aux=v->Cells[a][0];
				v->Cells[a][0]=v->Cells[b][0];
				v->Cells[b][0]=aux;
	}
}

void __fastcall TForm2::invertir1Click(TObject *Sender)
{
	invertir(StringGrid1,0,StringGrid1->ColCount-1);
}
//---------------------------------------------------------------------------
void Burbojear(TStringGrid *v,byte a,byte b){
 byte n=b-a+1 ;
 if (n>1){ //caso general
	byte m=StrToInt(v->Cells[n-1][0]);
	Burbojear(v,a,b-1);
	if (m < (StrToInt(v->Cells[n-2][0])) ){
			String aux=v->Cells[n-1][0];
			v->Cells[n-1][0]=v->Cells[n-2][0];
			v->Cells[n-2][0]=aux;
	}
 }
 }
 void ordenar(TStringGrid *v,byte a,byte b){
  byte n=b-a+1;
  if (n>1) {
		 Burbojear(v,a,b);
		 ordenar(v,a+1,b);
  }
}
void __fastcall TForm2::ordenar1Click(TObject *Sender)
{
	   ordenar(StringGrid1,0,StringGrid1->ColCount-1);
}
//---------------------------------------------------------------------------
byte cantidadDIG(Cardinal x){
byte s;
if (x<10){
	s=1;
}else {
	s=cantidadDIG(x/10);
	s=s+1;
}
return s;
}
void pasarNaV(TStringGrid *v,byte a,int b,Cardinal x){
	if (a<=b) {
		v->Cells [b][0]=x%100;
		x=x/100;
		pasarNaV(v,a,b-1,x);
	}
}
void __fastcall TForm2::cargarveccondig1001Click(TObject *Sender)
{
 byte x=cantidadDIG(StrToInt(Edit1->Text));
 StringGrid1->ColCount=(x+1)/2;
 pasarNaV(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
String invertirS(String s){
String x;
if (s=="") {
		x=s;
}else{
	char z=s[1];
	s.Delete(1,1);
	x=invertirS(s);
	x=x+z;
	}
	return x;
}
String deVecaNum(TStringGrid *v,byte a,int b){
String s;
	if (a==b){
		s=invertirS(v->Cells [b][0]);
	}else{
		String z=invertirS(v->Cells [b][0]);
		s=deVecaNum(v,a,b-1);
		s=s+z;
	}
	return s;
}
void __fastcall TForm2::devecatnuminvertido1Click(TObject *Sender)
{
	Edit2->Text=(deVecaNum(StringGrid1,0,StringGrid1->ColCount-1));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::invertir2Click(TObject *Sender)
{
	Edit3->Text=invertirS(Edit2->Text);
}
//---------------------------------------------------------------------------
void eliminarMdatos(TStringGrid *v,byte a,byte b,byte m){
if (m>0) {
	recorrer(v,a,b);
	eliminarMdatos(v,a,b,m-1);
}
}
void __fastcall TForm2::eliminarmdatosdeunap1Click(TObject *Sender)
{
	eliminarMdatos(StringGrid1,StrToInt(Edit1->Text),StringGrid1->ColCount-1,StrToInt(Edit2->Text));
	StringGrid1->ColCount =  StringGrid1->ColCount-StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------
String sepmultiplos(String s){
String f;
if (s=="") {
	f="";
}else{
	 byte p=s.Length();
	 String d=s[p];
	 s.Delete(p,1);
	 f=sepmultiplos(s);
	 if ((StrToInt(d)%3)==0)
		 f=f+d;
}
return f;
}
String sepnomultiplos(String s){
String f;
if (s=="") {
	f="";
}else{
	 byte p=s.Length();
	 String d=s[p];
	 s.Delete(p,1);
	 f=sepnomultiplos(s);
	 if ((StrToInt(d)%3)!=0)
		 f=f+d;
}
return f;
}
void moverMUL(TStringGrid *v,byte a,byte b,Cardinal n){
if (n>0) {
	v->Cells [b][0]=n%10;
	moverMUL(v,a,b-1,n/10);
}
}
void __fastcall TForm2::movermulde3alfinal1Click(TObject *Sender)
{
	  String s=Edit3->Text;
	  String k=sepmultiplos(s);
	  String l=sepnomultiplos(s);
	  s=l+k;
	  StringGrid1->ColCount=s.Length();
	  moverMUL(StringGrid1,0,StringGrid1->ColCount-1,StrToInt(s));
}
//---------------------------------------------------------------------------
//void anadir(TStringGrid *v,byte a,int b,byte d){
///byte n=b-a+1;
//if (n>0) {
//		v->Cells [b+1][0]=v->Cells [b][0];
//		anadir(v,a,b-1,d);
//		if (b==a) {
//			v->Cells [a][0]=d;
//		}
//}
//}
void insertarV2aV1(TStringGrid *v,TStringGrid *v2,byte a,byte b,byte a2,byte b2,byte p){
if (a2<=b2) {
	byte d=StrToInt(v2->Cells [a2][0]);
	anadir(v,p,b,d);
	insertarV2aV1(v,v2,a,b+1,a2+1,b2,p+1);
}
}
void __fastcall TForm2::insertar1vecaotroenp1Click(TObject *Sender)
{

	insertarV2aV1(StringGrid1,StringGrid2,0,StringGrid1->ColCount-1,0,StringGrid2->ColCount-1,StrToInt(Edit1->Text));
	StringGrid1->ColCount=StringGrid1->ColCount+StringGrid2->ColCount;
}
//---------------------------------------------------------------------------
int sumaSEG(TStringGrid *v,byte a ,byte b){
int s;
if (a==b) {
	  s=StrToInt(v->Cells [a][0]);
   }else{
	Cardinal d=StrToInt(v->Cells [a][0]);
	s=sumaSEG(v,a+1,b);
	s=s+d;
}
return s;
}
void __fastcall TForm2::sumadelsegmetno1Click(TObject *Sender)
{
	Edit3->Text=StrToInt(sumaSEG(StringGrid1,StrToInt(Edit1->Text),StrToInt(Edit2->Text)));
}
//---------------------------------------------------------------------------
byte cantidadPAL(String s){
s=s.Trim();
byte c=s.Length();
byte k;
if (c>0) {
	   int d=s.LastDelimiter(' ');
	   String mas= s.SubString(d+1,c-d);
	   s.Delete(d+1,c-d);
	   k=cantidadPAL(s);
	   k++;
}else k=0;
return k;
}
void pasarcadaM(TStringGrid *v,int b,String s){
s=s.Trim();
byte c=s.Length();
if (c>0) {
	int d=s.LastDelimiter(' ');
	String x=s.SubString(d+1,c-d);
	s.Delete(d+1,c-d);
	v->Cells [b][0]=x;
	pasarcadaM(v,b-1,s);
}
}
void __fastcall TForm2::cadavector1Click(TObject *Sender)
{
  String s=Edit1->Text;
  if (s!="") {
      StringGrid1->ColCount=cantidadPAL(s);
	  pasarcadaM(StringGrid1,StringGrid1->ColCount-1,s);
  }else{
	  limpiar(StringGrid1,StringGrid1->ColCount,StringGrid1->RowCount);
	  StringGrid1->ColCount=1;
	  StringGrid1->RowCount=1;
  }
}
//---------------------------------------------------------------------------
String pasarPLDVaC(TStringGrid *v,byte a,int b){
String s;
if (a>b)
	s="" ;
	else{
	String x=v->Cells [b][0];
	char z=x[1];
	s=pasarPLDVaC(v,a,b-1);
	s=s+z;
}
return s;
}
void __fastcall TForm2::pasarprimeraletradelvectoracadena1Click(TObject *Sender)
{
	 if (StringGrid1->Cells [0][0]!=""){
	 Edit3->Text=pasarPLDVaC(StringGrid1,0,StringGrid1->ColCount-1);
	 }else{
	 Edit3->Text="";
	 }
}
//---------------------------------------------------------------------------
bool verifpalindromo(TStringGrid *v,byte a,int b){
bool d=true;
if ((a<=b)&&(d==true)) {
		   String x=v->Cells [a][0];
		   String z=v->Cells [b][0];
		   d=verifpalindromo(v,a+1,b-1);
		   if (x!=z) {
				d=false;
		   }
}
return d;
}
void __fastcall TForm2::verifpalindromo1Click(TObject *Sender)
{
	Edit3->Text=BoolToStr(verifpalindromo(StringGrid1,0,StringGrid1->ColCount-1));
}
//---------------------------------------------------------------------------
void anadircad(TStringGrid *v,byte a,int b,char d){
byte n=b-a+1;
if (n>0) {
		v->Cells [b+1][0]=v->Cells [b][0];
		anadircad(v,a,b-1,d);
		if (b==a) {
			v->Cells [a][0]=d;
		}
}
}
void anadirunacadenaenp(TStringGrid *v,byte a,byte b,String s){
	byte c=s.Length();
	if (c>0) {
		char z=s[c];
		s.Delete(c,1);
		anadircad(v,a,b,z);
		anadirunacadenaenp(v,a,b+1,s);
	}
}
void __fastcall TForm2::insertar1letraenunap1Click(TObject *Sender)
{
 String s=Edit2->Text;
 anadirunacadenaenp(StringGrid1,StrToInt(Edit1->Text),StringGrid1->ColCount-1,s);
 StringGrid1->ColCount=StringGrid1->ColCount+s.Length();
}
//---------------------------------------------------------------------------
bool cadpalindrome(String s){
bool d=true;
byte c=s.Length();
if ((c>0)) {
	String x=s[1];
	String z=s[c];
	s.Delete(1,1);
	s.Delete(c-1,1);
	d=cadpalindrome(s);
	if (x != z ) {
		d=false;
	}
}
return d;
}
void __fastcall TForm2::verifpalindrome1Click(TObject *Sender)
{
	  Edit3->Text=BoolToStr(cadpalindrome(Edit1->Text));
}
//---------------------------------------------------------------------------
String repet(byte n,byte p){
String s;
	if (p>0) {
		s=repet(n,p-1);
		s=s+StrToInt(n);
	}else s="";
	return s;
}
String juntarrep(Cardinal n){
String s;
 if (n>0) {
	  byte d=n%10;
	  String z=repet(d,d);
	  s=juntarrep(n/10);
	  s=s+z;
}else s="";
return s;
}
void __fastcall TForm2::denumacadrepnum1Click(TObject *Sender)
{
	Edit3->Text=juntarrep(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
byte sumaDigitosBinarios(byte a, byte b) {
	return (a+b)/2*10+(a+b)%2;
}
Cardinal sumaBinaria(Cardinal a, Cardinal b, byte c) {
	Cardinal s;
	byte d=sumaDigitosBinarios(a%10,b%10);
	d = (d/10)*10+sumaDigitosBinarios(d%10,c);
	if (a<2 &b<2) {
		s = d;
	}
	else {
		s=sumaBinaria(a/10,b/10,d/10);
		s=s*10+d%10;
	}
	return s;
}
void __fastcall TForm2::sumabinarios1Click(TObject *Sender)
{
	 Edit3->Text=StrToInt(sumaBinaria(StrToInt(Edit1->Text),StrToInt(Edit2->Text),0));
}
//---------------------------------------------------------------------------
byte sdOctales(byte a, byte b) {
	return (a+b)/8*10+(a+b)%8;
}
Cardinal SOctales(Cardinal a, Cardinal b, byte c) {
Cardinal k;
	byte d=sdOctales(a%10,b%10);
	d = (d/10)*10+sdOctales(d%10,c);
	if ((a<8)&&(b<8)) {
		k = d;
	}else{
		k=SOctales(a/10,b/10,d/10);
		k=k*10+d%10;
	}
	return k;
}
void __fastcall TForm2::sumaoctales1Click(TObject *Sender)
{
	Edit3->Text=StrToInt(SOctales(StrToInt(Edit1->Text),StrToInt(Edit2->Text),0));
}
//---------------------------------------------------------------------------
Cardinal factorial(Cardinal n){
  Cardinal k;
	if (n<2){
		k=1;
	}else{
	  k=factorial(n-1);
	  k=k*n;
	}
    return k;
	}
void __fastcall TForm2::factorial1Click(TObject *Sender)
{
	Edit3->Text=StrToInt(factorial(StrToInt(Edit1->Text)));
}
//---------------------------------------------------------------------------

