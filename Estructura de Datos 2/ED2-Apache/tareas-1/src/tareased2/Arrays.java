/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tareased2;

/**
 *
 * @author DCDS
 */
public class Arrays {
    
     int elem[];//int n;
     int max; //const int max  =10;
     int cantElem;
     //constructor
     public Arrays(int capacidad){
         this.max=capacidad;
         this.elem=new int[capacidad];
         this.cantElem=0;
     }
     public boolean vacia(){return cantElem==0;}
     public boolean llena(){return cantElem==max;}
     
     //1
     public String toAString(){
         String s="[";
         for (int i = 0; i < cantElem; i++) {
             s+=elem[i];
             if(i!=cantElem-1)
                 s+=", ";
         }
         s+="]";
         return s;
     }
     //2
     public void insertarPrim(int x){
         if(llena()){
             System.out.print("El array esta lleno");
         }
         for (int i = cantElem-1; i >=0; i--) {
             elem[i+1]=elem[i];
         }
         elem[0]=x;
         cantElem++;
     }
     //3
     public void insertarUlt(int x){
         if(llena()){
             System.out.print("El array esta lleno");
         }
         elem[cantElem]=x;
         cantElem++;
     }
     //4
     public boolean iguales(){
         boolean b=true;
         for (int i = 1; i < cantElem; i++) {
             if(elem[0]!=elem[i]){
                 b=false;
                 break;
             }
         }
         return b;
     }
     //5
     public boolean diferentes(){
         boolean b=true;
         for (int i = 1; i < cantElem; i++) {
             if(elem[0]==elem[i]){
                 b=false;
                 break;
             }
         }
         return b;
     }
     public boolean diferentes2(){
         return !iguales();
     }
     //6
     public int mayorElem(){
         int may=elem[0];
         for (int i = 1; i < cantElem; i++) {
             if(may<elem[i])
                 may=elem[i];
             
         }
         return  may;
     }
     //7
     public int menorElem(){
         int men=elem[0];
         for (int i = 1; i < cantElem; i++) {
             if(men>elem[i])
                 men=elem[i];
             
         }
         return  men;
     }
     //8
     private boolean ordAsc(){
         boolean b=true;
         int o=elem[0];
         for (int i = 1; i < cantElem; i++) {
             if(o>i){
                 b=false;
                 break;
             }
             o=elem[i];
         }
         return b;
     }
     private boolean ordDes(){
         boolean b=true;
         int o=elem[0];
         for (int i = 1; i < cantElem; i++) {
             if(o<i){
                 b=false;
                 break;
             }
             o=elem[i];
         }
         return b;
     }
     public boolean ordenado(){
         boolean b;
         if(cantElem==1){
             b=true;
             return b;
         }
         if(elem[0]>elem[1])
             b=ordDes();
         else
             b=ordAsc();
         
         return b;
     }
     //9
     public boolean pares(){
         boolean b=true;
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]%2!=0){
                 b=false;
                 break;
             }
         }
         return b;
     }
     //10
     public boolean parImpar(){
         boolean b=false;
         byte par=0;
         byte imp=0;
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]%2==0)
                 par++;
             else
                 imp++;
             
             if(par>0 && imp>0){
                 b=true;
                 break;
             }
         }
         return b;
     }
     //11
     public void reemplazar(int x, int y){
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]==x){
                 elem[i]=y;
             }
         }
     }
     //12
     public boolean seEncuentra(int x){
         boolean b=false;
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]==x){
                 return true;
             }
         }
         return b;
     }
     //13
     public int frecuencia(int x){
         int frec=0;
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]==x)
                 frec++;
         }
         return frec;
     }
     //14
     public boolean existeFrec(int x){
         boolean b=false;
         int frec;
         for (int i = 0; i < cantElem; i++) {
             frec=frecuencia(elem[i]);
             if(frec==x){
                b=true;
                break;
             }
         }
         return b;
     }
     //15
     public boolean mismasFrec(){
         boolean b=true;
         int frec;
         int aux=frecuencia(elem[0]);
         for (int i = 1; i < cantElem; i++) {
             frec=frecuencia(elem[i]);
             if(frec!=aux){
                 b=false;
                 break;
             }
         }
         return b;
     }
     //16
     public boolean poker(){
        boolean b=true; 
        int frec=0;
         for (int i = 1; i < cantElem; i++) {
             if(elem[i-1]!=elem[i])
                 frec++;
             
             if(frec>2){
                 b=false;
                 break;
             }
         }
        return b;
     }
     //17
     public boolean existePar(){
         boolean b=false;
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]%2==0){
                 return true;
             }
         }
         return b;
     }
     //18
     public boolean existeImpar(){
         boolean b=false;
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]%2==1){
                 return true;
             }
         }
         return b;
     }
     //19
     public boolean todoPares(){
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]%2==1){
                 return false;
             }
         }
         return true;
     }
     //20
     public boolean todoImpares(){
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]%2==0)
                 return false;
         }
         return true;
     }
     //21
     public boolean existeParImpar(){
         byte par=0;
         byte imp=0;
         for (int i = 0; i < cantElem; i++) {
             if(elem[i]%2==0)
                 par++;
             else
                 imp++;
             
             if(par>0 && imp>0)
                 return true;
         }
         return false;
     }
     //22
     private boolean ordParImp(byte ban){
         for (int i = 0; i < cantElem; i++) {
             if(ban==0){
                 if(elem[i]%2!=0){
                     return false;
                 }
                 ban++;
             }else{
                 if(elem[i]%2!=1){
                     return false;
                 }
                 ban--;
             }
         }
         return true;
     }
     public boolean alternos(){
         byte ban=0;
         if(elem[0]%2==0)
             return ordParImp(ban);
         else{
             ban++;
             return ordParImp(ban);
         }
     }
     //23
     public void insertarAsc(int x){
         if(vacia())
             insertarUlt(x);
         
         if(llena()){
             System.out.print("El array esta lleno");
         }else{
            for (int i = 0; i < cantElem; i++) {
                if(elem[i]>x){
                    insertIesimo(x, i);
                    break;
                }
            }
         }
     }
     //24
     public void insertarDes(int x){
         if(vacia())
             insertarUlt(x);
         
         if(llena()){
             System.out.print("El array esta lleno");
         }else{
            for (int i = 0; i < cantElem; i++) {
                if(elem[i]<x){
                    insertIesimo(x, i);
                    break;
                }
            }
         }
     }
     //25
     public void insertIesimo(int x, int pos){
         for (int i = cantElem-1; i >=pos ; i--) {
             elem[i+1]=elem[i];
         }
         //System.arraycopy(elem, pos, elem, pos + 1, cantElem - pos);
         elem[pos]=x;
         cantElem++;
     }
     //26
     public void insertarPenultimo(int x){
         insertIesimo(x, cantElem-1);
     }
     //27
     public void insertarJuntoPrim(int x){
         if (seEncuentra(x)==false)
           insertarUlt(x);
         else{
             for (int i = 0; i < cantElem; i++) {
                 if(elem[i]==x){
                     insertIesimo(x, i);
                 }
             }
         }
     }
     //28
     public void insertarJuntoUlt(int x){
         if (seEncuentra(x)==false)
           insertarUlt(x);
         else{
             int frec=frecuencia(x);
             int ayu=0;
             for (int i = 0; i < cantElem; i++) {
                 if(elem[i]==x)
                     ayu++;
                 
                 if(ayu==frec){
                     insertIesimo(x, i);
                     break;
                 }
             }
         }
     }
     //29
     public void concatenar(Arrays ar){
         for (int i = 0; i < ar.cantElem; i++) {
             insertarUlt(ar.elem[i]);
             cantElem++;
         }
     }
     //30
     public void intercalar(Arrays ar, Arrays aar){
         int pa=0;
         int paa=0;
         while(ar.cantElem!=pa && aar.cantElem!=paa){
             insertarUlt(ar.elem[pa]);
             insertarUlt(aar.elem[paa]);
             cantElem+=2;
         }
         if(ar.cantElem==pa){
             concatenar(aar);
         }
         if (aar.cantElem==paa) {
             concatenar(ar);
         }
     }
     //31
     public void merge(Arrays ar, Arrays aar){
         int pa=0;
         while(ar.cantElem!=pa && aar.cantElem!=pa){
             insertarUlt(ar.elem[pa]);
             insertarUlt(aar.elem[pa]);
             cantElem+=2;
         }
         if(ar.cantElem==pa){
             concatenar(aar);
         }
         if (aar.cantElem==pa) {
             concatenar(ar);
         }
     }
     
     //eliminacion en los arrays
     //1
     public void eliminarPrim(){
         if(vacia())
             return;
         
         for (int i = 0; i < cantElem; i++) {
             elem[i]=elem[i+1];
         }
         cantElem--;
     }
     //2
     public void eliminarUlt(){
         cantElem--;
     }
     //3
     public void eliminarIesimo(int pos){
         if(pos>cantElem)
             return;
         
         for (int i = pos; i < cantElem; i++) {
             elem[i]=elem[i+1];
         }
         cantElem--;
     }
     //4
     public void eliminarTodo(int x){
         for (int i = cantElem; i >= 0; i--) {
             if(elem[i]==x)
                 eliminarIesimo(i);
         }
     }
     //5
     //con sobrecarga
     public void eliminarPrim(int canti){
         for (int i = 0; i < canti; i++) {
             eliminarPrim();
         }
     }
     //6
     public void eliminarEntre(int ini, int fini){
         for (int i = fini-1; i > ini; i--) {
             eliminarIesimo(i);
         }
     }
     //7
     public void eliminarDuplicados(){
         for (int i = cantElem; i > 0; i--) {
             if(frecuencia(elem[i])>1)
                 eliminarIesimo(i);
         }
     }
     //8
     public void eliminar(Arrays ar){
         for (int i = 0; i < ar.cantElem; i++) {
             if(seEncuentra(ar.elem[i]))
                 eliminarTodo(ar.elem[i]);
         }
     }
     //9
     public void eliminarDesde(int ini, int fini){
         for (int i = fini; i > ini-1; i--) {
             eliminarIesimo(i);
         }
     }
     //10
     public void eliminarUnicos(){
         for (int i = cantElem; i > 0; i--) {
             if(frecuencia(elem[i])==1)
                 eliminarIesimo(i);
         }
     }
    
     

     
   //Arreglo
    public boolean iguales(Arrays ar1, Arrays ar2) {
        if (ar1.cantElem != ar2.cantElem) {
            return false;
        }
        for (int i = 0; i < ar1.cantElem; i++) {
            if (ar1.elem[i] != ar2.elem[i]) {
                return false;
            }
        }
        return true;
    } 
    
}
