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
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	//StringGrid1->ColCount = Edit1->Text.ToInt();

	/*Vectores*/
	StringGrid1->ColCount = StrToInt(Edit1->Text);
	StringGrid1->RowCount = 1;

	/*Matrices*/
	/*StringGrid1->ColCount = StrToInt(Edit1->Text);
	StringGrid1->RowCount = StrToInt (Edit2->Text);*/
}
//---------------------------------------------------------------------------

Cardinal SumaPro(TStringGrid *v, byte n){
 Cardinal sum,d ;
  if (n==0) {
	 sum=0;
  }else {
	   sum =  SumaPro(v,n-1);
		sum = sum +StrToInt(v->Cells[n-1][0]);;
  }
  return sum;
}

int sumaDeImparRestaPar(TStringGrid *v,byte col){
	if(col<=v->ColCount-1){
		int s=sumaDeImparRestaPar(v,col+1);
		if((StrToInt(v->Cells[col][0])%2)==0){
			return s-StrToInt(v->Cells[col][0]);
		}else{
			return s+StrToInt(v->Cells[col][0]);
		}
	}
	return 0;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Edit1->Text=(sumaDeImparRestaPar(StringGrid1,0));

}
//---------------------------------------------------------------------------

/*Matriz*/

void Fila(TStringGrid *v, byte columI,byte columF,byte row,byte num){

	if(columI<=columF){
		v->Cells[columI][row]=num;
		Fila(v,columI+1,columF,row,num);
	}
}
void Matriz(TStringGrid *v,byte columF,byte row,byte num){
	if(row<=v->RowCount-1){
		Fila(v,0,columF,row,num);
		Matriz(v,columF-1,row+1,num+1);
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{

		if(StringGrid1->ColCount==StringGrid1->RowCount)
		Matriz(StringGrid1,StringGrid1->ColCount-1,0,1);
}
//---------------------------------------------------------------------------


