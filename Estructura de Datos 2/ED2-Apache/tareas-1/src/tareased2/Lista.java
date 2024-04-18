/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tareased2;
import tareased2.Nodo;
import java.util.Random;
/**
 *
 * @author DCDS
 */

public class Lista {
    Nodo prim;
    Nodo ult;
    int cantElem;
    
    public Lista(){
        this.prim=this.ult=null;
        this.cantElem=0;
    }
    
    private boolean vacia(){
        return this.cantElem==0;
    }
        
    @Override
    public String toString(){
        String cad="L1->";
        Nodo puntero=this.prim;
        while(puntero!=null){
            cad=cad+"["+puntero.elem+"]->";
            puntero=puntero.prox;
        }
        cad=cad+"null";
        return cad;
    }
    
    /***TAREA-1. EJERCICIOS BÁSICOS SOBRE LISTAS ENCADENADAS SIMPLES***/
    
    //1
    /*public String toString(){
        String s1="[";
        Nodo p=prim;
        while (p!=null){
            s1=s1+p.elem;
            if(p.prox!=null)
                s1=s1+" ";
        }
        p=p.prox;
        s1=s1+"]";
        return s1;
    }*/
    
    
    //2
    public void insertarPrim(int x)
    {
        if(vacia())
            prim=ult=new Nodo(x,null);
        else 
            prim=new Nodo(x, prim);
        cantElem++;
    }
    
    //3
    public void insertarUlt(int x){
        if (vacia())
            prim=ult=new Nodo(x,null);
        else 
            ult=ult.prox=new Nodo(x, null);
        cantElem++;
    }

    //4
    
    public void agregarElemento(int elemento) {
        Nodo nuevoNodo = new Nodo(elemento);
        if (prim == null) {
            prim = nuevoNodo;
        } else {
            Nodo nodoActual = prim;
            while (nodoActual.prox != null) {
                nodoActual = nodoActual.prox;
            }
            nodoActual.prox = nuevoNodo;
        }
    }
    
    public boolean iguales(){
        Nodo p=this.prim;
        while (p!=null && p.prox != null){
            if (p.elem != p.prox.elem){
                return false;
            }
            p=p.prox;
        }
        return true;
    }
    
    //5
    /*public boolean diferentes(){
        if (this.prim==null){
            return true;
        }
        Nodo actu=this.prim;
        while (actu!=null){
            while(sig!=null){
                if (actu.elem==sig.elem){
                    return false;
                }
                sig=sig.prox;
            }
            actu=actu.prox;
        }
        return true;
    }*/

    //6
    public int mayorElem(){
        int mayor=this.prim.elem;
        Nodo actu = this.prim.prox;
        while(actu!=null){
            if(actu.elem>mayor){
                mayor=actu.elem;
            }
            actu=actu.prox;
        }
        return mayor;
    }
    
    //7
    public int menorElem(){
        int men = this.prim.elem;
        Nodo actu = this.prim.prox;
        while(actu!=null){
            if(actu.elem<men){
                men=actu.elem;
            }
            actu=actu.prox;
        }
        return men;
    }
    
    //8
    public boolean ordenado(){
        if (this.prim==null || this.prim.prox==null){
            return true;
        } 
        Nodo actu = this.prim;
        boolean ascendente = false;
        boolean descendente = false;
        while (actu.prox!=null){
            if(actu.elem>actu.prox.elem){
                break;
            }
            actu=actu.prox;
        }
        if (actu.prox==null){
            ascendente=true;
        }
        actu=this.prim;
        while (actu.prox!=null){
            if(actu.elem<actu.prox.elem){
                break;
            }
            actu=actu.prox;
        }
        if(actu.prox==null){
            descendente=true;
        }
        return ascendente || descendente;
    }
    
    //9
    public boolean pares(){
        Nodo p=prim;
        while(p!=null){
            if (p.getElem()%2 != 0){
                return false;
            }
            p=p.getProximo();
        }
        return true;
    }
    
    //10
    public boolean existeParImpar(){
        boolean hayPar=false;
        boolean hayImpar=false;
        Nodo p=prim;
        while (p!=null){
            if (p.getElem()%2==0){
                hayPar=true;
            }else{
                hayImpar=true;
            }
            if(hayPar && hayImpar){
                return true;
            }
            p=p.getProximo();
        }
        return false;
    }
    
    //11
    public void reemplazar(int x, int y){
        Nodo p=prim;
        while (p!=null){
            if(p.elem==x){
                p.elem=y;
            }
            p=p.prox;
        }
    }
    
    //12
    public boolean seEncuentra(int x){
        Nodo actu=this.prim;
        while(actu!=null){
            if(actu.elem==x){
                return true;
            }
            actu=actu.prox;
        }
        return false;
    }
    
    //13
    public int frecuencia(int x){
        int cont=0;
        Nodo p=this.prim;
        while (p!=null){
            if(p.elem==x){
                cont++;
            }
            p=p.prox;
        }
        return cont;
    }
    
    //14
    public boolean existeFrec(int k){
        Nodo p=this.prim;
        if (p==null){
            return false;
        }else{
            while(p!=null){
                if(frecuencia(p.elem)==k){
                    return true;
                }
                p=p.prox;
            }
        }
        return false;
    }
    
    //15
    public boolean mismaFrec(){
        Nodo p=this.prim;
        int frec = frecuencia(p.elem);
        if (p==null){
            return false;
        }else{
            while(p!=null){
                if (frec==frecuencia(p.elem)||(p==null)){
                    p=p.prox;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    
    //16
    public boolean poker(){
        Nodo p=prim;
        if(cantElem==1 || cantElem==2){
            return false;
        }else{
            if(frecuencia(p.getElem())==1 && cantElem==frecuencia(p.prox.getElem())){
                return true;
            }else{
                if(cantElem-1==frecuencia(p.getElem())){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
    
    //17
    public boolean existePar(){
        Nodo p=prim;
        while (p!=null){
            if(p.getElem()%2==0){
                return true;
            }
            p=p.getProximo();
        }
        return false;
    }
    
    //18
    public boolean existeImpar(){
        Nodo p=prim;
        while(p!=null){
            if (p.getElem()%2!=0){
                return true;
            }
            p=p.getProximo();
        }
        return false;
    }
    
    //19
    public boolean todoPares(){
        Nodo p=prim;
        while(p!=null){
            if (p.getElem()% 2 !=0){
                return false;
            }
            p=p.getProximo();
        }
        return true;
    }
    
    //20
    public boolean todoImPares(){
        Nodo p=prim;
        while (p!=null){
            if (p.getElem()%2!=0){
                return false;
            }
            p=p.getProximo();
        }
        return true;
    }
    
    //21
    public boolean existParImpar(){
        boolean hayPar=false;
        boolean hayImpar=false;
        Nodo p=prim;
        while(p!=null){
            if(p.getElem()%2==0){
                hayPar=true;
            }else{
                hayImpar=true;
            }
            if(hayPar && hayImpar){
                return true;
            }
            p=p.getProximo();
        }
        return false;
    }
    
    //22
    public boolean alternos() {
        boolean esPar = false;
        Nodo p = prim;
        while (p != null) {
            if ((esPar && p.getElem() % 2 != 0) || (!esPar && p.getElem()
                    % 2 == 0)) {
                return false;
            }
            esPar = !esPar;
            p = p.getProximo();
        }
        return true;
    }

    
    
    /*lab-2*/
    
    //1
    /*@Override
    public String toString(){
        String s1="[";
        Nodo p=prim;
        while (p!=null){
            s1=s1+p.elem;
            if(p.prox!=null)
                s1=s1+" ";
        }
        p=p.prox;
        s1=s1+"]";
        return s1;
    }*/
    
    //2
    /*public void insertarPrim(int x) {
        if (vacia()) {
            prim = ult = new Nodo(x, null);
        } else {
            prim = new Nodo(x, prim);
        }
        cantElem++;
    }*/
    
    //3
    /*public void insertarUlt(int x){
        if (vacia())
            prim=ult=new Nodo(x,null);
        else 
            ult=ult.prox=new Nodo(x, null);
        cantElem++;
    }*/    
    
    //4 
    /*public void insertarNodo(int x, Nodo ap, Nodo p){
        if (ap==null){
            insertarPrim(x);
            return;
        }
        if(p==null){
            insertarUlt(x);
            return;
        }
        ap.prox=new Nodo(x,p);
        cantElem++;
    }*/
    
    //5
    /*public void insertarAsc(int x){
        if (prim==null || x<prim.valor){
            insertarPrim(x);
        }else{
            if(x>ult.valor){
                insertarUlt(x);
            }else{
                Nodo ap=prim;
                Nodo p=prim.sig;
                while (p!=null && p.valor<x){
                    ap=p;
                    p=p.sig;
                }
                insertarNodo(x,ap,p);
            }
        }
    }*/
    
    //6
    /*public void insertarDesc(int x){
        if(prim==null || x>prim.valor){
            insertarPrim(x);
        }else{
            if(x<ult.valor){
                insertarUlt(x);
            }else{
                Nodo ap=prim;
                Nodo p=prim.sig;
                while (p!=null && p.valor>x){
                    ap=p;
                    p=p.sig;
                }
                insertarNodo(x,ap,p);
            }
        }
    }*/
    
    //7
    /*public void insertarIesimo(int x, int i){
        Nodo p=prim, ap=null;
        int k=0;
        while (p!=null && k<i){
            ap=p;
            p=p.prox;
            k=k+1;
        }
        insertarNodo(x,ap,p);
    }*/    
    
    //8 insertarPenultimo
    //9 insertarJuntoPrim
    //10 insertarJuntoUlt
    
    
    
    /*Tarea-2*/
    
    public void insertarLugar(int x){
        Nodo p=prim, ap=null;
        while (p!=null && x>p.elem){
            ap=p;
            p=p.prox;
        }
        insertarNodo(x, ap, p);
    }
    
    //23
    public void insertarNodo(int x, Nodo ap, Nodo p){
        if (ap==null){
            insertarPrim(x);
            return;
        }
        if(p==null){
            insertarUlt(x);
            return;
        }
        ap.prox=new Nodo(x,p);
        cantElem++;
    }
    
    //24
    public void insertarAsc(int x){
        if(prim==null || x<prim.valor){
            insertarPrim(x);
        }else if(x>ult.valor){
            insertarUlt(x);
        }else{
            Nodo ap=prim;
            Nodo p=prim.sig;
            while(p!=null && p.valor<x){
                ap=p;
                p=p.sig;
            }
            insertarNodo(x,ap,p);
        }
    }
    
    //25
    public void insertarDesc(int x){
        if(prim==null || x>prim.valor){
            insertarPrim(x);
        }else if(x<ult.valor){
            insertarUlt(x);
        }else{
            Nodo ap=prim;
            Nodo p=prim.sig;
            while(p!=null && p.valor>x){
                ap=p;
                p=p.sig;
            }
            insertarNodo(x,ap,p);
        }
    }
    
    //26
    public void insertarIesimo(int x, int i){
        Nodo p=prim, ap=null;
        int k=0;
        while (p!=null && k<i){
            ap=p;
            p=p.prox;
            k=k+1;
        }
        insertarNodo(x,ap,p);
    }    
    
    //27
    //28
    //29
    //30
    //31
    //32
    
    
    
    /*Lab-3*/
    
    private Nodo eliminarNodo(Nodo ap, Nodo p){
        if(ap==null){
            eliminarPrim();
            return prim;
        }
        ap.prox=p.prox;
        if(ult==p)
            ult=ap;
        cantElem--;
        return ap.prox; 
    }
    
    //1
    /*public void eliminarPrim(){
        if(vacia())
            return;
        prim=prim.prox;
        cantElem--;
    }*/
    
    //2
    /*public void eliminarUlt(){
        if(vacia())
            return;
        if(cantElem==1){
            inicializar();
            return;
        }
        Nodo p=prim, ap=null;
        while(p.prox!=null){
            ap=p;
            p=p.prox;
        }
        ap.prox=null;
        ult=ap;
        cantElem--;
    }*/
    
    //3
    /*public void eliminarIesimo(int i){
        int k = 0;
        Nodo p=prim, ap=null;
        while(p!=null && k<i){
            ap=p;
            p=p.prox;
            k++;
        }
        eliminarNodo(ap,p);
    }*/
    
    //4
    /*public void eliminarTodo(int x){
        Nodo p=prim; ap=null;
        while(p!=null){
            if(p.elem==x)
                p=eliminarNodo(ap,p);
            else{
                ap=p;
                p=p.prox;
            }
        }
    }*/
    
    //5
    /*public void eliminarPrim(int n){
        Nodo p=prim, ap=null;
        int k=1;
        while(p!=null && k<=n){
            p=this.eliminarNodo(ap, p);
            k++;
        }
    }*/
    
    
    
    /*Tarea-3*/
    //1
    public void eliminarPrim(){
        if(vacia())
            return;
        prim=prim.prox;
        cantElem--;
    }
    
    //2
    /*public void eliminarUlt(){
        if(vacia())
            return;
        if(cantElem==1){
            inicializar();
            return;
        }
        Nodo p=prim, ap=null;
        while(p.prox!=null){
            ap=p;
            p=p.prox;
        }
        ap.prox=null;
        ult=ap;
        cantElem--;
    }*/
    
    //3
    public void eliminarIesimo(int i){
        int k = 0;
        Nodo p=prim, ap=null;
        while(p!=null && k<i){
            ap=p;
            p=p.prox;
            k++;
        }
        eliminarNodo(ap,p);
    }
    
    //4
    public void eliminarTodo(int x){
        Nodo p=prim; Object ap = null;
        while(p!=null){
            if(p.elem==x)
                p=eliminarNodo((Nodo) ap,p);
            else{
                ap=p;
                p=p.prox;
            }
        }
    }
    
    //5
    public void eliminarPrim(int n){
        Nodo p=prim, ap=null;
        int k=1;
        while(p!=null && k<=n){
            p=this.eliminarNodo(ap, p);
            k++;
        }
    } 
    
    //6
    public void eliminarEntre(int ini, int fini){//para intervalo abierto 
        for (int i = fini-1; i > ini; i--) {
            eliminarIesimo(i);
        }
    }
    
    //7
    public void eliminarDuplicados(){
        Nodo p=prim, ap=null;
        while(p!=null){
            if(frecuencia(p.elem)>1)
                p=eliminarNodo(ap, p);
            else{
                ap=p;
                p=p.prox;
            }
        }
    }
    
    //8
    public void eliminar(Lista lis){
        Nodo pLis=lis.prim;
        while(pLis!=null){
            if(seEncuentra(pLis.elem))
                eliminarTodo(pLis.elem);
           
            pLis=pLis.prox;  
        }
    }
    
    //9
    public void eliminarDesde(int ini, int fini){//para intervalo cerrado
        for (int i = fini; i > ini-1; i--) {
            eliminarIesimo(i);
        }
    }
    
    //10
    
    
    
    /*Lab-4*/
    
    //1
    /*public boolean iguales(Lista lis){
        if(cantElem!=lis.cantElem)
            return false;
        Nodo p=prim, pp=lis.prim;
        while(p!=null){
            if(p.elem!=pp.elem)
                return false;
            p=p.prox;
            pp=pp.prox;
        }
        return true;
    }*/
    
    //2
    /*public boolean mismosElem(Lista lis){
        byte ban=0;
        Nodo p;
        if(cantElem>lis.cantElem){
            p=prim;
        }else{
            p=lis.prim;
            ban++;
        }
        while(p!=null){
            if(ban==0){
                if(lis.seEncuentra(p.elem)==false)
                    return false;
            }else{
                if(seEncuentra(p.elem)==false)
                    return false;
            }
            p=p.prox;
        }
        return true;
    }*/
    
    //3
    /*public void digitos(int num){
        while (num!=0){
            int ayu=num%10;
            num/=10;
            insertarPrim(ayu);
        }
    }*/
    
    //4
    /*public void distribuir(int x, Lista lis, Lista los){
        Nodo p=prim;
        while (p!=null){
            if(p.elem>=x){
                los.insertarPrim(p.elem);
            }else{
                lis.eliminarPrim(p.elem);
            }
            p=p.prox;
        }
    }*/
    
    //5
    /*public void generarAleatorio(int canti, int ea, int eb){
        Random ran=new Random();
        for (int i =0; i<canti; i++){
            int alea=ran.nextInt(eb-ea+1)+ea;
            insertarUlt(alea);
        }
    }*/
    
    //6
    /*public void eliminarMen(int x){
        Nodo p=prim, ap=null;
        while(p!=null){
            if(p.elem<x){
                if(p==prim)
                    eliminarPrim();
                else{
                    p=eliminarNodo(ap,p);
                    p=ap;
                }
            }
            ap=p;
            p=p.prox;
        }
    }*/
    
    //7
    /*public void eliminarExtremos(int canti){
        for(int i=0; i<canti; i++){
            eliminarPrim();
            eliminarUlt();
        }
    }*/
    
    //8
    /*public void eliminar(int pos, int canti){
        if(pos>cantElem)
            return;
        Nodo p=prim;
        while(p!=null){
            if(canti>0){
                eliminarIesimo(pos);
                canti--;
            }
            p=p.prox;
        }
    }*/
    
    
    
    /*Tarea-4*/
    
    
        public void eliminarUlt(int n){
        int j=1;
        while(j<=n){
            j++;
            this.cantElem--;
        }
    }
    
    public void eliminarUlt1(int n){
        int i=1;
        while(i<=n){
            this.eliminarUlt(n);
            i++;
        }
    }

    //1
    public boolean iguales(Lista lis){
        if(cantElem!=lis.cantElem)
            return false;
        Nodo p=prim, pp=lis.prim;
        while(p!=null){
            if(p.elem!=pp.elem)
                return false;
            p=p.prox;
            pp=pp.prox;
        }
        return true;
    }    
    
    //2
    public boolean mismosElem(Lista lis){
        byte ban=0;
        Nodo p;
        if(cantElem>lis.cantElem){
            p=prim;
        }else{
            p=lis.prim;
            ban++;
        }
        while(p!=null){
            if(ban==0){
                if(lis.seEncuentra(p.elem)==false)
                    return false;
            }else{
                if(seEncuentra(p.elem)==false)
                    return false;
            }
            p=p.prox;
        }
        return true;
    }    
    
    //3
    public void digitos(int num){
        while (num!=0){
            int ayu=num%10;
            num/=10;
            insertarPrim(ayu);
        }
    }    
    
    //4
    public void distribuir(int x, Lista lis, Lista los){
        Nodo p=prim;
        while (p!=null){
            if(p.elem>=x){
                los.insertarPrim(p.elem);
            }else{
                lis.eliminarPrim(p.elem);
            }
            p=p.prox;
        }
    }    
    
    //5
    public void generarAleatorio(int canti, int ea, int eb){
        Random ran=new Random();
        for (int i =0; i<canti; i++){
            int alea=ran.nextInt(eb-ea+1)+ea;
            insertarUlt(alea);
        }
    }    
    
    //6
    public void eliminarMen(int x){
        Nodo p=prim, ap=null;
        while(p!=null){
            if(p.elem<x){
                if(p==prim)
                    eliminarPrim();
                else{
                    p=eliminarNodo(ap,p);
                    p=ap;
                }
            }
            ap=p;
            p=p.prox;
        }
    }
    
    //7
    public void eliminarExtremos(int canti){
        for(int i=0; i<canti; i++){
            eliminarPrim();
            eliminarUlt();
        }
    }
    
    //8
    public void eliminar(int pos, int canti){
        if(pos>cantElem)
            return;
        Nodo p=prim;
        while(p!=null){
            if(canti>0){
                eliminarIesimo(pos);
                canti--;
            }
            p=p.prox;
        }
    }    
    //9.1
        public void eliminarMay(int x){
        Nodo p=prim, ap=null;
        while(p!=null){
            if(p.elem>x){
                if(p==prim)
                    eliminarPrim();
                else{
                    p=eliminarNodo(ap,p);
                    p=ap;
                }
            }
            ap=p;
            p=p.prox;
        }
    }
    
    //9.2

    void iguales(int i) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
        



    







    
}

    
    
    
    
    
    
    
    
    
    

