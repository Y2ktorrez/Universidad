//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//
//
//  APRENDE MAS!!! ONICHAN
//
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void cargar(TStringGrid *v,byte n) //jose Daniel Soliz
{
	if (n>0){
	cargar(v,n-1);
	v->Cells[n-1][0]=Random(30);

	}

}
void cargarv2(TStringGrid *v,byte n)
{
	if (n>0){
	cargarv2(v,n-1);
	v->Cells[n-1][0]=Random(30);
	}
}
void cargarv3(TStringGrid *v,byte n)
{
	if (n>0){
	cargarv3(v,n-1);
	v->Cells[n-1][0]=Random(30);
	}
}
void limpiar(TStringGrid *v,byte n)
{
	if (n>0){
	limpiar(v,n-1);
	v->Cells[n-1][0]="";
	v->ColCount --;
	}
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   byte n =StrToInt(InputBox("","","3"));
   StringGrid1->ColCount =n;
   cargar(StringGrid1,n);
}
//---------------------------------------------------------------------------
void cargarmanual(TStringGrid *v,byte n)
{
	if (n>0){
	cargarmanual(v,n-1);
	v->Cells[n-1][0]=InputBox("","Inserte un Elemento","");
	}
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	byte n =StrToInt(InputBox("","","3"));
	StringGrid1->ColCount =n;
	cargarmanual(StringGrid1,n);
}
//---------------------------------------------------------------------------
void modex1(TStringGrid *v,byte n)
{int d=n;
String s;
	if (n>0){
	modex1(v,n-1);
	d=int(pow(d,2));
	if (n%2==0)
		 s="-1/"+IntToStr(d);
	else
		s="1/"+IntToStr(d);
		v->Cells [n-1][0]=s;
	}
	}
void modex12(TStringGrid *v,byte n)
{int d=n;
	if (n>0){
	modex1(v,n-1);
	d=int(pow(d,2));
	String s=(n%2==0)?s="-1/"+IntToStr(d): s="1/"+IntToStr(d);
	v->Cells [n-1][0]=s;
	}
	}

void __fastcall TForm1::modex11Click(TObject *Sender)
{
  byte x=StrToInt(InputBox("","",""));
  StringGrid1->ColCount =x;
  modex12(StringGrid1,x);

}
//---------------------------------------------------------------------------
void modex2(TStringGrid *v,int &n)  //dig de n en vector
{   v->ColCount =0;
	if (n>0){
	byte dig=n % 10;
	n=n / 10;
	modex2(v,n);
	v->Cells [v->ColCount -1][0]=StrToInt(dig);
	v->ColCount ++;
	}
}
void __fastcall TForm1::insertarcadadigdenenunvector1Click(TObject *Sender)
{
	  int n=StrToInt(InputBox("","",""));
	  modex2(StringGrid1,n);
	  StringGrid1->ColCount --;
}
//---------------------------------------------------------------------------
//0 1 2 3 6 7 14 15 30 31 62 63
void modex3(TStringGrid *v,byte n,int &s)
{   v->ColCount =0;
	if (n>0){
	modex3(v,n-1,s);
		if (n%2==0)
		s=s+1;
		else
		s=s*2;
	v->Cells[v->ColCount-1][0]=IntToStr(s);
	v->ColCount++;
	}
	else
	return;
}

void __fastcall TForm1::serieenv012361Click(TObject *Sender)
{int s=0;
modex3(StringGrid1,StrToInt(InputBox("","","")),s);
	StringGrid1->ColCount --;
}
//---------------------------------------------------------------------------
//13,8,5,3,2,1,1,0
byte fibo(int n)
{int c;
  if (n==1){
  c=0;}
  else{if (n==2) {
	c=1;}
else{
c=fibo(n-1)+fibo(n-2);}
}
return c ;
}
void modex4(TStringGrid *v,byte n)
{
if (n>0) {
  int s=fibo(n);
	modex4(v,n-1);
	v->Cells [v->ColCount -n][0]=s;
}
else
return ;
}

void __fastcall TForm1::fibo1Click(TObject *Sender)
{
Edit1->Text =((fibo(StrToInt(InputBox("","","")))));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::seriefibov321101Click(TObject *Sender)
{
	byte n=StrToInt(InputBox("","",""));
	StringGrid1->ColCount =n;
	modex4(StringGrid1,n);
}
//---------------------------------------------------------------------------
	  //cargar vector 2
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	 byte n =StrToInt(InputBox("","","3"));
   StringGrid2->ColCount =n;
   cargarv2(StringGrid2,n);
}
//---------------------------------------------------------------------------
	//cargar vector 3
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   byte n =StrToInt(InputBox("","","3"));
   StringGrid3->ColCount =n;
   cargarv3(StringGrid3,n);
}
//---------------------------------------------------------------------------
//intercalar 2 vectores
void intercalar(TStringGrid *v ,TStringGrid *v2,TStringGrid *v3,byte &n1,byte &n2){
if ((n1<=v->ColCount)||(n2<=v2->ColCount )) {
	if (n1<=v->ColCount) {
	v3->Cells [v3->ColCount-1][0]=v->Cells [n1-1][0];
	v3->ColCount++;
	n1++;
	}
	if (n2<=v2->ColCount) {
	v3->Cells [v3->ColCount-1][0]=v2->Cells [n2-1][0];
	v3->ColCount++;
	n2++;
	}
	intercalar(v,v2,v3,n1,n2);
	}
}
void __fastcall TForm1::intercalar2vectores1Click(TObject *Sender)
{
byte n1=1;
byte n2=1;
StringGrid3->ColCount=1;
intercalar(StringGrid1,StringGrid2,StringGrid3,n1,n2);
StringGrid3->ColCount =StringGrid3->ColCount-1;
}
//intercalar 2 vectores 2.0 sin indices
void intercalar2(TStringGrid *v ,TStringGrid *v2,TStringGrid *v3){
if ((v->ColCount>1)||(v2->ColCount>1)) {
	if (v->ColCount>1) {
	v3->Cells [v3->ColCount-1][0]=v->Cells [v->ColCount-1][0];
	v3->ColCount++;
	v->ColCount--;
	if (v->ColCount ==1) {
	 v3->Cells [v3->ColCount-1][0]=v->Cells [0][0];
	 v3->ColCount++;}
	}
	if (v2->ColCount>1) {
	v3->Cells [v3->ColCount-1][0]=v2->Cells [v2->ColCount-1][0];
	v3->ColCount++;
	v2->ColCount--;
	if (v2->ColCount ==1){
	 v3->Cells [v3->ColCount-1][0]=v2->Cells [0][0];
	 v3->ColCount++;}
	}
	intercalar2(v,v2,v3);
	}

}
void __fastcall TForm1::intercalar2vect201Click(TObject *Sender)
{
StringGrid3->ColCount=1;
byte a=StringGrid1->ColCount ;
byte b=StringGrid2->ColCount ;
intercalar2(StringGrid1,StringGrid2,StringGrid3);
StringGrid3->ColCount =StringGrid3->ColCount-1;
StringGrid1->ColCount =a;
StringGrid2->ColCount =b;

}



//---------------------------------------------------------------------------
//Segmentar 2 vectores en un tercero
void segmentar(TStringGrid *v ,TStringGrid *v2,TStringGrid *v3,byte &n1,byte &n2)
{
if ((n1<=v->ColCount)||(n2<=v2->ColCount )) {
	if (n1<=v->ColCount) {
	v3->Cells [v3->ColCount-1][0]=v->Cells [n1-1][0];
	v3->ColCount++;
	n1++;
	}
	else {
	v3->Cells [v3->ColCount-1][0]=v2->Cells [n2-1][0];
	v3->ColCount++;
	n2++;
	}
	segmentar(v,v2,v3,n1,n2);
}

}


void __fastcall TForm1::segmentar2vectores1Click(TObject *Sender)
{
byte n1=1;
byte n2=1;
StringGrid3->ColCount=1;
segmentar(StringGrid1,StringGrid2,StringGrid3,n1,n2);
StringGrid3->ColCount =StringGrid3->ColCount-1;
}
//---------------------------------------------------------------------------
void ordenar(TStringGrid *v,byte &i , byte &j){
	byte n=v->ColCount-1;
	if (i<=n-1) {
	if (j<=n) {
		String a= v->Cells [i][0];
		String b= v->Cells [j][0];
		if (StrToInt(a)>b) {
			String aux= v->Cells [i][0];
			v->Cells [i][0]=v->Cells [j][0];
			v->Cells [j][0]=aux;
		}
		j++;
		}
		else{
			i++;
			j=i+1;
		}
		ordenar(v,i,j);
	}
}

void __fastcall TForm1::ordenarvector1Click(TObject *Sender)
{
byte i=0;
byte j=0;
ordenar(StringGrid1,i,j);
}
//---------------------------------------------------------------------------
byte cantdig2(Cardinal n){
byte i;
if (n<10)
	i=1;
	else {
		i=cantdig2(n/10);
		i++;
	}
	return i;
}
byte cantdig(Cardinal n){
		   byte i=(n<10)?1:cantdig(n/10)+1;
		   return i;
}

void __fastcall TForm1::cantdig1Click(TObject *Sender)
{
ShowMessage(cantdig(StrToInt(InputBox("","inserte n: ","") )));
}
//---------------------------------------------------------------------------
//eliminar primera y ultima letra de cada palabra de una cadena
// eje hola daniel = ol anie

void modex5(String &cad){
cad=cad.Trim() ;
int l=cad.Length();
	if (l>0) {
		int p=cad.LastDelimiter(' ');
		String ultpal=cad.SubString(p+2,l-(p+2)); //o String ultpal=cad.SubString(p+1,l-p);
		cad.Delete(p+1,l-p); //ultpal.Delete(1,1);  //ultpal.Delete(ultpal.Length(),1);
		modex5(cad);
		cad=cad+ultpal+' ';
	}
}
void __fastcall TForm1::eliminarprimyultletradeunapalenunacad1Click(TObject *Sender)

{
	String cad=Edit1->Text ;
	modex5(cad);
	ShowMessage(cad);
}
//---------------------------------------------------------------------------
//la inversa del modex5
void modex5_1(String &cad){
cad=cad.Trim() ;
int l=cad.Length();
	if (l>0) {
		int p=cad.LastDelimiter(' ');
		String ultpal=cad.SubString(p+1,l-p);
		cad.Delete(p+1,l-p);
		int n=ultpal.Length() ;
		ultpal.Delete(2,n-2);
		modex5_1(cad);
		cad=cad+ultpal+' ';
	}
}

void __fastcall TForm1::eliminartodasmenoslaprimylaultletraenunacad1Click(TObject *Sender)

{
	String cad=Edit1->Text ;
	modex5_1(cad);
	ShowMessage(cad);
}
//---------------------------------------------------------------------------
// de palabras de un vector acumular en una cad cada inicial de las pal del vector
// ej hola/que/haces = cad= hqh

String modex6(TStringGrid *v,byte i){
String s;
	if (i<=v->ColCount-1 ) {
		String x=v->Cells [i][0];
		s=String(x[1])+ modex6(v,i+1); }
	else s="";
	return s;
}
void __fastcall TForm1::deunvectorponercadainicialenunacad1Click(TObject *Sender)
{
ShowMessage(modex6(StringGrid1,0));
}
//---------------------------------------------------------------------------
// encontrar la palabra mas larga de una cadena
String modex7(String &cad)
{String s;
cad=cad.Trim() ;
int l=cad.Length();
	if (l>0) {
		int p=cad.LastDelimiter(' ');
		String ultpal=cad.SubString(p+1,l-p);
		cad.Delete(p+1,l-p);
		s=modex7(cad);
			if (ultpal.Length()>s.Length() )
				s=ultpal;
		}
	else s="";
	return s;
}

void __fastcall TForm1::palabramasgrande1Click(TObject *Sender)
{
	String cad=Edit1->Text ;
	ShowMessage(modex7(cad));
}
//---------------------------------------------------------------------------
//insertar un elemento x en un posicion p de un vector
void modex8(TStringGrid *v,int x , byte p,int &i)
{
	if (i>0) {
		if (i!=p)
			   v->Cells [i-1][0]= v->Cells [abs(i-2)][0];
		else
			 v->Cells [i-1][0]=IntToStr(x);
			 i--;
			 modex8(v,x,p,i);
	}
}
void __fastcall TForm1::insereleenposdeunvect1Click(TObject *Sender)
{    StringGrid1->ColCount ++;
	 int i=StringGrid1->ColCount;
	 int x=StrToInt(InputBox("","Elemento x ",""));
	 byte p=StrToInt(InputBox("","Posicion p ",""));
	 modex8(StringGrid1,x,p,i);
}
//---------------------------------------------------------------------------
bool esdig(char ele){
String cad="0123456789";
return cad.Pos(ele)>0;
}

void __fastcall TForm1::esnumero1Click(TObject *Sender)
{
	Edit1->Text = BoolToStr(esdig(Edit1->Text [1]),true);
}
//---------------------------------------------------------------------------
int modex9(String &Cad){
int s;
byte n=Cad.Length() ;
	if (n>0) {
		char ele=Cad[n];
		Cad.Delete(n,1);
		s=modex9(Cad);
		if (esdig(ele))
			s=s+StrToInt(ele);
	}
	else s=0;
	return s;
}

void __fastcall TForm1::sumadedigdeunacadena1Click(TObject *Sender)
{
	String cad=Edit1->Text;
	ShowMessage(modex9(cad));
}
//---------------------------------------------------------------------------
//reto de caricari
// convectir un decimal a cualquier base
String convbase(Cardinal n,byte b)
{	String cad="0123456789ABCDEF";
	String n2;
	byte d;
	if (n==0){
		n2="0";d=0;}
	else{
	byte dig=n%b;
	n2=convbase(n/b,b);
	n2=n2+cad[dig+1];
	d++;
	}
	if (d>1)
		 n2.Delete(1,1);
	return n2;
}
void __fastcall TForm1::decabase2al161Click(TObject *Sender)
{
	//Cardinal n=StrToInt(InputBox("","numero a convertir: ",""));
	Cardinal n=StrToInt(Edit1->Text) ;
	byte b=StrToInt(InputBox("","A base: ",""));
	ShowMessage(convbase(n,b));
}
//---------------------------------------------------------------------------
//contar palabras
int cpal(String &cad){
int d;
	if (cad=="")
	d=0;
	else {
	wchar_t a=cad[1];
	wchar_t b=(cad.Length() ==1)?' ':cad[2];
	cad.Delete(1,1);
	d=cpal(cad);
		if ((a!=' ')&&(b==' '))
		d++;
	}
	return d;
}

void __fastcall TForm1::contarpalabras1Click(TObject *Sender)
{
	String cad=Edit1->Text;
	ShowMessage(cpal(cad));
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void convertir(String &cad){
	String dig="0123456789";
	byte l=cad.Length() ;
	if (l>0) {
		wchar_t ele=cad[l];
		cad.Delete(l,1);
		convertir(cad);
		if (dig.Pos(ele)>0 )
			cad=cad+ele;
			else
			cad=cad+' ';
	}
}
void __fastcall TForm1::convertirnonumerosaespacios1Click(TObject *Sender)
{
	String cad=Edit1->Text ;
	convertir(cad);
	ShowMessage(cad);
}
void limpiar(String &cad){
	String dig="2357";
	byte l=cad.Length() ;
	if (l>0) {
		wchar_t ele=cad[l];
		cad.Delete(l,1);
		limpiar(cad);
		if (dig.Pos(ele)>0 )
			cad=cad+ele;
	}
}
void __fastcall TForm1::limpiarsoloprimos1Click(TObject *Sender)
{
	String cad=Edit1->Text ;
	limpiar(cad);
	ShowMessage(cad);
}
//---------------------------------------------------------------------------
//easy
void vdigprimo(TStringGrid *v,String &cad)
{   convertir(cad);
	cad=cad.Trim() ;
	byte l=cad.Length();
	if (l>0) {
		byte p=cad.LastDelimiter(' ');
		String pal=cad.SubString(p+1,l-p);
		cad.Delete(p+1,l-p);
		limpiar(pal);
		vdigprimo(v,cad);
		v->Cells [v->ColCount -1][0]=pal;
		v->ColCount ++;
	}
}

//---------------------------------------------------------------------------


void __fastcall TForm1::insertardigprimoenVdeunacad1Click(TObject *Sender)
{StringGrid1->ColCount =0;
String cad=Edit1->Text ;
vdigprimo(StringGrid1,cad);
StringGrid1->ColCount--;
}
//---------------------------------------------------------------------------

//sacar vocales y poner en vector
void limpiar23(String &cad)
{
String vocales="AEIOU";
if (cad.Length() ) {
	wchar_t ele=cad[cad.Length() ];
	cad.Delete(cad.Length() ,1);
	limpiar23(cad);
	if (vocales.Pos(UpperCase(ele) ) ) {
		cad=cad+ele;
	}
}
}
void __fastcall TForm1::dejarvocale1Click(TObject *Sender)
{
String cad=Edit1->Text ;
limpiar23(cad);
ShowMessage(cad);
}
//---------------------------------------------------------------------------
void pract1(TStringGrid *v,String &cad){
	cad=cad.Trim() ;
	byte l=cad.Length();
	if (l>0) {
		byte p=cad.LastDelimiter(' ');
		String pal=cad.SubString(p+1,l-p);
		cad.Delete(p+1,l-p);
		pract1(v,cad);
		limpiar23(pal);
		v->Cells [v->ColCount -1][0]=pal;
		v->ColCount ++;
	}
}

void __fastcall TForm1::vocalesdepalabrasenvector1Click(TObject *Sender)
{
	String cad=Edit1 ->Text ;
	pract1(StringGrid1,cad);
	StringGrid1->ColCount --;
}
//---------------------------------------------------------------------------
String pract2(TStringGrid* v,String cad,byte i){
	if (i<=v->ColCount -1) {
		String pal=v->Cells [i][0];
		limpiar(pal);
		cad=cad+pal;
		cad=pract2(v,cad,i+1);
	}
	return cad;
}
void __fastcall TForm1::vectorastringprimos1Click(TObject *Sender)
{
	String cad="";
	String cad2=pract2(StringGrid1,cad,0);
	ShowMessage(cad2);
}
//---------------------------------------------------------------------------
//insertar un vector en otro a partir de una posicion
void campo(TStringGrid *v1,byte pos, byte n)
{
	if (n>=pos) {
	   byte n1=(n==1)?0:n-2;
	   v1->Cells[n-1][0]=v1->Cells [n1][0];
	   campo(v1,pos,n-1);
	}
}
void juntar2(TStringGrid *v1,TStringGrid *v2,byte &i,byte pos,byte n)
{
	if (n>0){
		v1->ColCount ++;
		campo(v1,pos,v1->ColCount );
		v1->Cells [pos-1][0]=v2->Cells [i][0];
		i++;
		juntar2(v1,v2,i,pos+1,n-1);
	}
	}
void __fastcall TForm1::insertarvectorenotroenunapos1Click(TObject *Sender)
{
	byte pos=StrToInt(InputBox("","",""));
	byte i=0;
	byte n=StringGrid2->ColCount ;
	juntar2(StringGrid1,StringGrid2,i,pos,n);
}
//---------------------------------------------------------------------------

//vector a String
String vastring(TStringGrid*v,byte i)
{String a,s;
	if (i<=v->ColCount -1) {
		String a=v->Cells [i][0];
		s=vastring(v,i+1);
		s=a+' '+s;
	} else {
	s=""; }
	return s;
}
void __fastcall TForm1::vectorastring1Click(TObject *Sender)
{
String cad=vastring(StringGrid1,0);
ShowMessage(cad) ;
}
//---------------------------------------------------------------------------
//INVERTIR UN NRO

void invertir(Cardinal &n,Cardinal &pos){
	if (n>9) {
		  byte dig= n %10;
		  n=n/10;
		  invertir(n,pos);
		  n=n+(dig*pos);
		  pos=pos*10;
	}
}
void invertir2(Cardinal &n){
	if (n>9) {
		  byte dig= n %10;
		  n=n/10;
		  invertir2(n);
		  n=n+dig*pow(10,cantdig(n));
	}
}
void __fastcall TForm1::invertir1Click(TObject *Sender)
{
	Cardinal n=StrToInt(Edit1->Text );
   //	Cardinal pos=10;
	invertir2(n);
	ShowMessage(StrToInt(n));
}
//---------------------------------------------------------------------------
String pract3(TStringGrid* v,String cad,byte i){
	if (i<=v->ColCount -1) {
		Cardinal n=StrToInt(v->Cells [i][0]);
		invertir2(n);
		cad=cad+String(n);
		cad=pract3(v,cad,i+1);
	}
	return cad;
}


void __fastcall TForm1::vectorastringnrosvolcados1Click(TObject *Sender)
{
	String cad="";
	String cad2=pract3(StringGrid1,cad,0);
	ShowMessage(cad2);
}
//---------------------------------------------------------------------------

//cadena dejar solo caracteres dig de fibonacci
void solofibo(String &cad){
	String fibo="012358";
	int l=cad.Length() ;
	if (l>0) {
		wchar_t ele=cad[l];
		cad.Delete(l,1);
		solofibo(cad);
		if (fibo.Pos(ele)>0 )
			cad=cad+ele;
	}
}

void __fastcall TForm1::decadenasolodigfibo1Click(TObject *Sender)
{
  String cad=InputBox("","","");
  solofibo(cad);
  ShowMessage(cad);
}
//---------------------------------------------------------------------------
void invertircad(String &cad){
	int l=cad.Length() ;
	if (l>0) {
	  wchar_t ele=cad[l];
	  cad.Delete(l,1);
	  invertircad(cad);
	  cad=String(ele)+cad;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pre21Click(TObject *Sender)
{
   String cad=InputBox("","","");
  String cad2=cad;
  bool b=false;
	invertircad(cad);
	if (cad.UpperCase() ==cad2.UpperCase() ) {
		 b=true;
	}
  ShowMessage(BoolToStr(b,true));
}
//---------------------------------------------------------------------------
//ex
//la inversa del modex5
void examen1(String &cad,int i,byte pos,byte n){
	if (i>0) {
		if ((i>=n)||(i<=pos)) {
			 cad.Delete(i,1);
		}
		i--;
		examen1(cad,i,pos,n);
	}
}
void examen5(String &cad,byte pos,byte n){
 byte l=cad.Length() ;
	 wchar_t ele;
	if (l>0) {
		if ((l>=pos)&&(l<=n))
		 ele=cad[l];

		cad.Delete(l,1);
		examen5(cad,pos,n);
			if ((l>=pos)&&(l<=n))
		cad=cad+ele;
	}
}

  void __fastcall TForm1::pre31Click(TObject *Sender)
{
	  String cad=InputBox("","","");
	  byte pos=StrToInt(InputBox("","",""));
	  byte n=StrToInt(InputBox("","",""));
  examen5(cad,pos,n);
  ShowMessage(cad);
}
int Exprueba(TStringGrid *v,byte n)
{ int s;
	if (n>0) {//caso general
		  s=Exprueba(v,n-1);
		  s=s+StrToInt(v->Cells [n-1][0]);
	}else //caso base
	s=0;
	return s;
}
void __fastcall TForm1::ejer1deexamendeprueba1Click(TObject *Sender)
{  //limpiar(StringGrid1,StringGrid1->ColCount );
   byte n=StringGrid1->ColCount;
   Edit1->Text =Exprueba(StringGrid1,n);
}
//---------------------------------------------------------------------------

byte Exprueba2(int n){
byte s;
	if (n<10)   //caso base
	   s=1;
	else    //caso general
	   s=Exprueba2(n/10)+1;
	return s;
}

byte Exprueba22(int n){
	byte s=(n<10)?1:Exprueba22(n/10)+1;
return s;
}

void __fastcall TForm1::ejer2deexamdeprueba1Click(TObject *Sender)
{
	int n=StrToInt(Edit1->Text);
	ShowMessage(IntToStr(Exprueba22(n)));
}
//---------------------------------------------------------------------------


//mover digitos de n al final , los demas dejarlos normal

//n=234356	->	v= 2,4,5,3,3,6

void insertarInicio(TStringGrid *v,byte n,byte d){
	if (n==1) {
		v->Cells [n-1][0]=d;
	}else{
		v->Cells [n-1][0]=v->Cells[n-2][0];
		insertarInicio(v,n-1,d);
		  }
}
void matoneo(TStringGrid *v,byte &n,Cardinal x){
if (x>0) {
	byte d=x%10;
	if (d%3==0) {
		v->Cells [n-1][0]=d;
	}else{
		insertarInicio(v,n,d);
	}
	n++;
	matoneo(v,n,x/10);
}
}
void __fastcall TForm1::moverdigdenalfinaldeunvector1Click(TObject *Sender)
{
Cardinal x=StrToInt(InputBox("","",""));
byte n=1;
matoneo(StringGrid1,n,x);
StringGrid1->ColCount =n-1;
}
//---------------------------------------------------------------------------

// mover los digitos de un nro a un vector
//n=123 -> v=1,2,3
void matoneo2(TStringGrid *v,Cardinal n)
{
	if (n>0) {
		   byte d= n%10;
		   matoneo2(v,n/10);
		   v->Cells [v->ColCount -1][0]=d;
		   v->ColCount ++;
	}
}
void __fastcall TForm1::digitosdenenunvector1Click(TObject *Sender)
{
limpiar(StringGrid1,StringGrid1->ColCount);
Cardinal x=StrToInt(InputBox("","",""));
matoneo2(StringGrid1,x);
StringGrid1->ColCount--;
}
//---------------------------------------------------------------------------

//eliminar desde una posicion p , m elementos
// v=1,2,3,4,5  , p=2,m=2 -> v=1,4,5
void matoneo3(TStringGrid *v,byte n,byte pos,byte m){
if (n>0) {
	matoneo3(v,n-1,pos,m);
	if (n>pos+m-1)
	v->Cells [(n-m)-1][0]=v->Cells [n-1][0];
}
}
//
//eliminar desde una posicion p , m elementos
// v=1,2,3,4,5  , pos1=1,pos2=2 -> v=3,4,5
void matoneo4(TStringGrid *v,byte n,byte pos1,byte pos2){
if (n>0) {
	matoneo4(v,n-1,pos1,pos2);
	if (n>pos1+(pos2-pos1+1)-1)
	v->Cells [(n-(pos2-pos1+1))-1][0]=v->Cells [n-1][0];
}
}
void __fastcall TForm1::eliminarmelementosdesdeunposdeunvector1Click(TObject *Sender)
{

byte pos=StrToInt(InputBox("","",""));
byte m=StrToInt(InputBox("","",""));
matoneo4(StringGrid1,StringGrid1->ColCount ,pos,m);
StringGrid1->ColCount=StringGrid1->ColCount -(m-pos+1);
}
//---------------------------------------------------------------------------
void preguntas2(String &cad){
	String dig="abcdefghijklmn�opqrstuvwxyzABCDEFGHIJKLMN�OPQRSTUVWXYZ";
	if (cad.Length() >0) {
		wchar_t ele=cad[cad.Length() ];
		cad.Delete(cad.Length() ,1);
		preguntas2(cad);
		if (dig.Pos(ele)>0 )
			cad=cad+ele;
			else
			cad=cad+' ';
	}
}
int cpalabras(String &cad){
int d;
preguntas2(cad);
cad=cad.Trim() ;
int l=cad.Length() ;
	if (l==0)
	d=0;
	else {
	int p=cad.LastDelimiter(' ');
	String ultpal=cad.SubString(p+1,l-p);
	cad.Delete(p+1,l-p);
	d=cpalabras(cad);
		d++;
	}
	return d;
}
int cpala(String &cad){
int d;
wchar_t b;

	if (cad=="")
	d=0;
	else {
	preguntas2(cad);
	wchar_t a=cad[1];
	if (cad.Length() ==1)
		b=' ';
	   else
		b=cad[2];
	cad.Delete(1,1);
	d=cpala(cad);
		if ((a!=' ')&&(b==' '))
		d++;
	}
	return d;
}


void __fastcall TForm1::contarpalabras2Click(TObject *Sender)
{
	 String cad=Edit1->Text ;
	 byte c=cpala(cad);
	 ShowMessage(c);
}
//---------------------------------------------------------------------------
void invertir(TStringGrid *v,byte n){
if (n>0) {
	byte dig =StrToInt(v->Cells [n-1][0]);
	invertir(v,n-1);
	v->Cells [v->ColCount-n-1][0]=dig;
	}
}

void __fastcall TForm1::invertirvector1Click(TObject *Sender)
{
byte n=StringGrid1->ColCount ;
invertir(StringGrid1 ,n);
}
//---------------------------------------------------------------------------
void Invertir2(String &cad)
{
	if (cad.Length() >0) {
		wchar_t c=cad[cad.Length()];
		cad.Delete(cad.Length(),1);
		Invertir2(cad);
		cad=String(c)+cad;
	}
}
void cadenaInvVec(TStringGrid *v,String &cad){
cad=cad.Trim();
	if (cad.Length() >0) {
		byte pos=cad.LastDelimiter(' ');
		 String pal=cad.SubString(pos+1,cad.Length()-pos);
		 Invertir2(pal);
		 cad.Delete(pos+1,cad.Length()-pos);
		 v->Cells [v->ColCount -1][0]=pal;
		 v->ColCount ++;
		 cadenaInvVec(v,cad);
	}
}
void __fastcall TForm1::palinvertenvect1Click(TObject *Sender)
{
	limpiar(StringGrid1,StringGrid1->ColCount);
	String cad=InputBox("","","");
	cadenaInvVec(StringGrid1,cad);
	 StringGrid1->ColCount --;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::invertircadena1Click(TObject *Sender)
{
 //
  String cad=InputBox("","","");
  Invertir2(cad);
  ShowMessage(cad);

}
//---------------------------------------------------------------------------
void ordenar(TStringGrid *v,TStringGrid *v2,TStringGrid *v3,byte n,byte a,byte b){

}

void MergeSort(TStringGrid *v,TStringGrid *v2,TStringGrid *v3,byte n,byte &a,byte &b){
	if (n>2) {
	v2->ColCount =n/2;
	v3->ColCount =n/2+n%2;
	MergeSort(v,v2,v3,n/2,a,b);
	if (a<v2->ColCount ) {
	  v2->Cells [a][0]=v->Cells [a][0];
	  a++;
	}
	if (b<v3->ColCount ) {
	  v3->Cells [b][0]=v->Cells [v2->ColCount +b][0];
	  b++;
	}
	}
}

void __fastcall TForm1::ordmargeshort1Click(TObject *Sender)
{
	byte a=0;
	byte b=0;
   MergeSort(StringGrid1,StringGrid2,StringGrid3,StringGrid1->ColCount ,a,b);
}
//---------------------------------------------------------------------------
float media(TStringGrid *v,int n){
float s;
	if (n>0) {
		int ele=StrToInt(v->Cells [n-1][0]);
		s=media(v,n-1);
		s=s+ele;
	}  else
	s=0;
	return s;
}
String mayormedia(TStringGrid *v,int n){
String s;
int k=v->ColCount;
	if (n>0) {
		int ele=StrToInt(v->Cells [n-1][0]);
		s=mayormedia(v,n-1);
		if (ele>media(v,k)/k) {
				s=s+" "+ele;
		}
	}  else
	s="";
	return s;
}


void __fastcall TForm1::promediodeelementos1Click(TObject *Sender)
{
	 int n=media(StringGrid1,StringGrid1->ColCount);
	 ShowMessage(n/StringGrid1->ColCount );
}
//---------------------------------------------------------------------------
bool buscar(TStringGrid*v,byte n,int ele){
bool b;
	if (n>0) {
	int x=StrToInt(v->Cells [n-1][0]);
	  b=buscar(v,n-1,ele);
	  if (ele==x)
		b=true;
	}
	else
	b=false;
	return b;
}
void interseccion(TStringGrid *v,TStringGrid *v2,TStringGrid *v3,byte &n,byte &n2){
	if ((n<=v->ColCount)||(n2<=v2->ColCount )) {

	if (n<=v->ColCount) {
	int x=StrToInt(v->Cells [n-1][0]);
	if (!buscar(v,v->ColCount,x )) {
		v3->Cells [v3->ColCount-1][0]=v->Cells [n-1][0];
		v3->ColCount++;
	}
	n++;
	}
	if (n2<=v2->ColCount) {
	int x=StrToInt(v2->Cells [n2-1][0]);
	if (!buscar(v2,v2->ColCount,x)) {
		v3->Cells [v3->ColCount-1][0]=v2->Cells [n2-1][0];
		v3->ColCount++;
	}
	n2++;
	}
	interseccion(v,v2,v3,n,n2);
	}
}

void __fastcall TForm1::interseccion1Click(TObject *Sender)
{
	byte n1=1;
byte n2=1;
StringGrid3->ColCount=1;
interseccion(StringGrid1,StringGrid2,StringGrid3,n1,n2);
StringGrid3->ColCount =StringGrid3->ColCount-1;
}
//---------------------------------------------------------------------------
String serie(int n,byte &k,byte &c)
{String s;
	if (n>1) {
	s=serie(n-1,k,c);
	k=k+c;
	s=s+","+k;
	c=c+2;
	}else if (n==1) {
		s="2";
		  }
		  else
		  s="";

return s;
}
void __fastcall TForm1::serie1Click(TObject *Sender)
{
	byte k=2;
	byte c=3;
	int n=StrToInt(InputBox("","inserte n",""));
	Edit1->Text =serie(n,k,c);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::mayorqueelpromedio1Click(TObject *Sender)
{
	// int n=media(StringGrid1,StringGrid1->ColCount);
	 Edit1->Text =mayormedia(StringGrid1,StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void recorrer(TStringGrid *v,int n,int p,int m)
{
	if (n-m>0) {
		 v->Cells [p][0]=v->Cells [p+1][0];
		 recorrer(v,n-1,p+1,m);
	}
}
void recorrer2(TStringGrid *v,int n,int p,int m)
{
	if (n-m>0) {
		 recorrer2(v,n-1,p,m);
		 //recorrer3(v,n-1,p+1,m);
	}
}


void __fastcall TForm1::elminarelementodeunapos1Click(TObject *Sender)
{

	 int i=StringGrid1->ColCount;
	 byte p=StrToInt(InputBox("","Posicion p ",""));
	 recorrer(StringGrid1,i,p,i);
	 StringGrid1->ColCount --;
}
//---------------------------------------------------------------------------
String invertirCad(String cad){
String s;
	   if (cad.Length() ==0) {
		 s="";
	   }else{
	   char c=cad[cad.Length()];
	   cad=cad.Delete(cad.Length(),1);
	   s=String(c)+invertirCad(cad);
	   }
	   return s;
}
bool elepalindrome(TStringGrid *v,byte n){
bool b=true;
	if (n==0) {
		return false;
	}
	String cad=v->Cells [n-1][0];
	if (n==1 && CompareText(cad,invertirCad(cad))==0) {
		return true;
	}
	bool b2=elepalindrome(v,n-1);
	if (CompareText(cad,invertirCad(cad))!=0)
		b=false;
	if (!b2)
		return false;
return b;
}

void __fastcall TForm1::verificarsitodosloselementosdelvectorsonpalindromes1Click(TObject *Sender)

{           //String cad=InputBox("","","") ;
		  Edit1->Text =BoolToStr(elepalindrome(StringGrid1,StringGrid1->ColCount),true);
			//Edit1->Text =IntToStr(CompareText(cad,invertirCad(cad)));
		   //Edit1->Text=invertirCad(cad);
}
//---------------------------------------------------------------------------
bool vectCapicua(TStringGrid *v,byte i,byte n){
bool b=true;
	if (n==0) {
		return false;
	}
	if (n==1) {
		return true;
	}
	if (i>n-1) {
		 return true;
	}
		bool b2=vectCapicua(v,i+1,n-1);
		int ele=StrToInt(v->Cells [i][0]);
		int ele2=StrToInt(v->Cells [n-1][0]);
		if (ele!=ele2)
			b=false;
		if (!b2)
			return false;
return b;
}
//cambiado
bool capicuaVect(TStringGrid *v,byte i,byte n){
bool b=true;
	if (n==0) {
		b=false;
	}else if (n==1) {
		b=true;
	}else if (i<=n-1) {
		bool b2=capicuaVect(v,i+1,n-1);
		if (b2==false){
			b=false;
		}
		int ele1=StrToInt(v->Cells [i][0]);
		int ele2=StrToInt(v->Cells [n-1][0]);
		if (ele1!=ele2)
			b=false;
	}
return b;
}

void __fastcall TForm1::vectorpalindrome1Click(TObject *Sender)
{
	   Edit1->Text =BoolToStr(capicuaVect(StringGrid1,0,StringGrid1->ColCount),true);
}
//---------------------------------------------------------------------------
bool isNumero(String Cad){
	if (Cad.Length() ==0) {
		return false;
	}
return true;
}


void recorrerV(TStringGrid *v,int n,int p)
{
	if (n>p) {
		 v->Cells [n][0]=v->Cells [n-1][0];
		 recorrerV(v,n-1,p);
	}
}
void veranovector(TStringGrid *v,byte n,int x){
if (n>0) {
	int ele1=StrToInt(v->Cells [n][0]);
	if (x>ele1) {
		  v->ColCount ++;
		  recorrerV(v,v->ColCount-1,n);
		  v->Cells [n+1][0]=x;
		  return;
	}else if (n==1){
		  v->ColCount ++;
		  recorrerV(v,v->ColCount-1,0);
		  v->Cells [0][0]=x;
		  return;
	}

	veranovector(v,n-1,x);
}
}



void __fastcall TForm1::insertarelemento1Click(TObject *Sender)
{
	int n=StringGrid1->ColCount;
	 byte x=StrToInt(InputBox("","elemento x ",""));
	 veranovector(StringGrid1,n-1,x);
}
//---------------------------------------------------------------------------
bool esnumero (String cad){
int n=cad.Length() ;
	if (n >0) {
		char ele=cad[n];
		cad.Delete(n,1);
		bool b=esnumero(cad);
		if (!esdig(ele) )
			return false;
	}else{
	return true;
	}
}
void eliminardig (String &cad){
int n=cad.Length() ;
	if (n >0) {
		char ele=cad[n];
		cad.Delete(n,1);
		eliminardig(cad);
		if (!esdig(ele) ){
			cad=cad+ele;
		}
	}
}
bool tienedig (String cad){
int n=cad.Length() ;
	if (n >0) {
		char ele=cad[n];
		cad.Delete(n,1);
		bool b=esnumero(cad);
		if (esdig(ele) )
			return true;
	}else{
	return false;
	}
}
void verano2(String &cad, bool &b){
cad=cad.Trim() ;
int l=cad.Length();
	if (l>0) {
		int p=cad.LastDelimiter(' ');
		String ultpal=cad.SubString(p+1,l-p);
		cad.Delete(p+1,l-p);
		int n=ultpal.Length() ;
		verano2(cad,b);
		if (tienedig(ultpal) && b) {
			 eliminardig(ultpal);
			 b=false;
		}
		cad=cad+ultpal+' ';
	}
}

void __fastcall TForm1::eliminarprimernumerodeunaca1Click(TObject *Sender)
{
String cad=Edit1->Text;
bool b=true;
verano2(cad,b);
ShowMessage(cad);
}
//---------------------------------------------------------------------------

