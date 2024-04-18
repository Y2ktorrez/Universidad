/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tareas.pkg2;
import java.util.Random;
import  tareas.pkg2.Nodo;
/**
 *
 * @author DCDS
 */
public class ListaDoble {
    Nodo prim;
    Nodo ult;
    int cantElem;
    
    public ListaDoble(){
        this.prim=this.ult=null;
        this.cantElem=0;
    }
    
    private boolean vacia(){
        return this.cantElem==0;
    }
    
    @Override
    public String toString(){
        StringBuilder cad=new StringBuilder("L1->");
        Nodo p=this.prim;
        while(p!=null){
            cad.append("[").append(p.elem).append("]<->");
            p=p.prox;
        }
        cad.append("null");
        return cad.toString();
    }
    
    //Agregar
    public void agregar(int x) {
        Nodo p = new Nodo(null, x, null);
        if (vacia()) {
            prim = ult = p;
        } else {
            p.ant = ult;
            ult.prox = p;
            ult = p;
        }
        cantElem++;
    }    
    
    /*
    * Insertar y Eliminar Nodo
    */
    public void insertarNodo(Nodo ap, Nodo p, int x){
        if(this.vacia()){
            this.insertarPrim(x);
            return;
        }
        if(p==null){
            this.insertarUlt(x);
            return;
        }
        ap.prox=p.ant=new Nodo(ap,x,p);
    }
    
    /*private Nodo eliminarNodo(Nodo ap, Nodo p){
        if(ap!=null){
            this.eliminarPrim();
            return prim;
        }
        if(p.prox==null){
            this.eliminarUlt();
            return null;
        }
        ap.prox=p.prox;
        p.prox.ant=ap;
        this.cantElem--;
        return ap.prox;
    }*/
   
    
    /****LAB-5 LISTA DOBLES****/
    
    /*1. L1.insertarPrim(x) : Método que insertar el elemento x, al inicio de la lista L1.*/
    public void insertarPrim(int x){
        if(this.vacia())
            this.prim=this.ult=new Nodo(null,x,null);
        else
            this.prim=this.prim.ant=new Nodo(null, x, prim);
        
        this.cantElem++;
    }
    
    /*2. L1.insertarUlt(x) : Método que inserta el elemento x, al final de la lista L1*/
    public void insertarUlt(int x){
        if(this.vacia())
            this.prim=this.ult=new Nodo(null,x,null);
        else
            this.ult=this.ult.prox=new Nodo(ult,x,null);
        
        this.cantElem++;
    }
    
    /*3. L1.insertarIesimo(x, i) : Método que inserta el elemento x, en la posición i, de la lista L1, 
         asumir cero la primera posición y si i es mayor a la última posición, insertar al final.*/
    public void insertarIesimo(int x, int i){
        int k=0;
        Nodo p=this.prim, ap=null;
        while(k<i && p!=null){
            k++;
            ap=p;
            p=p.prox;
        }
        this.insertarNodo(ap, p, x);
    }
    
    /*4. L1.insertarIesimo(L2, i): Método que inserta los elementos de la Lista L2, en la Lista L1 a partir de la 
         i-esimo posición.*/
    public void insertarIesimoL2(ListaDoble L2, int pos){
        Nodo p=L2.prim;
        while (p!=null){
            insertarIesimo(p.elem, pos);
            pos++;
        }
    }
    
    /*5. L1.eliminarPrim() : Método que elimina el elemento de la primer posición.*/
    public void eliminarPrim(){
        if(this.vacia())
            return;
        if(prim==null)
            prim=ult=null;
        else{
            prim.prox.ant=null;
            prim=prim.prox;
        }
        this.cantElem--;
    }
    
    /*6. L1.eliminarUlt() : Método que elimina el último elemento de la lista L1.*/
    public void eliminarUlt(){
        if(this.vacia())
            return;
        if(prim==ult)
            prim=ult=null;
        else{
            ult.ant.prox=null;
            ult=ult.ant;
        }
        this.cantElem--;
    }
    
    /*7. L1.mostrarIzqDer() : Método que muestra los elementos de la lista L1, de izquierda a derecha.*/ 
    public void mostrarIzqDer() {
        Nodo p = prim;
        System.out.println("Izq-Der: ");
        while(p!=null){
            System.out.println(p.elem + "\t");
            p=p.prox;
        }
        System.out.println();
    }
    
    /*8. L1.mostrarDerIzq() : Método que muestra los elementos de la lista L1, de derecha a izquierda. 
         Utilizar esto métodos para verificar si las inserciones y eliminaciones de elementos son correctas.*/ 
    public void mostrarDerIzq(){
        Nodo p=ult;
        System.out.println("Der-Izq: ");
        while(p!=null){
            System.out.println(p.elem+"\t");
            p=p.ant;
        }
        System.out.println();
    }
    
    /*9. L1.rotarIzqDer(n): Método que hacer rotar los elementos de la Lista L1, n veces de Izquierda a Derecha.*/
    public void desplazarIz(){
        Nodo p=prim, auz=prim;
        if(!this.vacia() && this.cantElem>1){
            prim=prim.prox;
            auz.prox=null;
            ult.prox=auz;
        }
    }
    
    public void rotarIzqdDer(int n){
        for (int i = 0; i < n; i++) {
            this.desplazarIz();
        }
    }
    
    /*10. L1.rotarDerIzq(n): Método que hacer rotar los elementos de la Lista L1, n veces de Deerecha a Izquierda.*/
    public void desplazarDer(){
        Nodo p=prim, ap=prim, aux=prim;
        if(!this.vacia() && this.cantElem>1){
            while(p.prox!=null){
                ap=p;
                p=p.prox;
            }
            ap.prox=null;
            prim=p;
            ult.prox=aux;
        }
    }
    
    public void rotarDerIzq(int n){
        for (int i = 0; i < n; i++) {
            this.desplazarDer();
        }
    }
    
    /*11. L1.eliminarIesimo(i): Método que elimina el i-ésimo elemento de la lista L1. 
          Asumir el primer elemento lugar cero y así sucesivamente. Si i se encuentra mas allá de la cantidad de 
          elementos de la lista, no elimina ningún elemento.*/
    public void eliminarIesimo(int i){
        if(i>=this.cantElem)
            return;
        int k=0;
        Nodo p=prim, ap=null;
        while(k<i && p!=null){
            k++;
            ap=p;
            p=p.prox;
        }
        this.eliminarNodo(ap, ap);
    }
    
    /*12. L1.eliminarNodo(ap, p) : Método que elimina el nodo p, y devuelve el nuevo nodo p.*/
    private Nodo eliminarNodo(Nodo ap, Nodo p){
        if(ap!=null){
            this.eliminarPrim();
            return prim;
        }
        if(p.prox==null){
            this.eliminarUlt();
            return null;
        }
        ap.prox=p.prox;
        p.prox.ant=ap;
        this.cantElem--;
        return ap.prox;
    }
    
    /*13. L1.eliminarTodo( x ) : Método que elimina todos los elementos x de la lista L1.*/
    public void eliminarTodo(int x){
        Nodo p=prim, ap=null;
        while(p!=null){
            if(p.elem==x)
                p=this.eliminarNodo(ap, ap);
            else{
                ap=p;
                p=p.prox;
            }
        }    
    }
    
    /*14. L1.eliminarPares() : Método que elimina los elementos pares de la lista L1.*/    
    public void eliminarPares(int x){
        Nodo p=prim, ap=null;
        while(p!=null){
            if(p.elem%2==0)
                p=this.eliminarNodo(ap, ap);
            else{
                ap=p;
                p=p.prox;
            }
        }    
    }     
    
/*-------------------------------------------------------------------------------------------------------------*/

    /****TAREA-5 LISTA DOBLES****/
    
    /*1. L1.insertarPrim(x) : Método que insertar el elemento x, al inicio de la lista L1.*/
    public void insertarPrimT5(int x){
        if(this.vacia())
            this.prim=this.ult=new Nodo(null,x,null);
        else
            this.prim=this.prim.ant=new Nodo(null, x, prim);
        
        this.cantElem++;
    }    
    
    /*2. L1.insertarUlt(x) : Método que inserta el elemento x, al final de la lista L1*/
    public void insertarUltT5(int x){
        if(this.vacia())
            this.prim=this.ult=new Nodo(null,x,null);
        else
            this.ult=this.ult.prox=new Nodo(ult,x,null);
        
        this.cantElem++;
    }    
    
    /*3. L1.insertarIesimo(x, i) : Método que inserta el elemento x, en la posición i, de la lista L1, 
         asumir cero la primera posición y si i es mayor a la última posición, insertar al final.*/
    public void insertarIesimoT5(int x, int i){
        int k=0;
        Nodo p=this.prim, ap=null;
        while(k<i && p!=null){
            k++;
            ap=p;
            p=p.prox;
        }
        this.insertarNodo(ap, p, x);
    }    
    
    /*4. L1.insertarIesimo(L2, i): Método que inserta los elementos de la Lista L2, en la Lista L1 a 
         partir de la i-esimo posición.*/
    public void insertarIesimoL2T5(ListaDoble L2, int pos){
        Nodo p=L2.prim;
        while (p!=null){
            insertarIesimo(p.elem, pos);
            pos++;
        }
    }    
    
    /*5. L1.insertarPrim(L2) : Método que inserta los elementos de la Lista L2 en al principio de la Lista L1.*/
    public void insertarPrimT5(ListaDoble L2) {
        Nodo q = L2.ult;
        while (q != null) {
            this.insertarPrim(q.elem);
            q = q.ant;
        }
    }
    
    /*6. L1.insertarUlt(L2) : Método que inserta los elementos de la Lista L2 en al final de la Lista L1.*/
    public void insertarUltT5(ListaDoble L2) {
        Nodo p = L2.prim;
        while (p != null) {
            this.insertarUlt(p.elem);
            p = p.prox;
        }
    }

    
    /*7. L1.insertarLugarAsc(x) : Método que inserta el elemento x en su lugar correspondiente, 
         en la Lista ascendente L1.*/
    public void insertarLugarAscT5(int x) {
        Nodo p = this.prim;
        Nodo ap = null;
        while (p != null && p.elem < x) {
            ap = p;
            p = p.prox; 
        }
        this.insertarNodo(ap, p, x); 
    }
    
    /*8. L1.insertarLugarDesc(x) : Método que inserta el elemento x en su lugar correspondiente, 
         en la Lista descendente L1.*/
    public void insertarLugarDescT5(int x) {
        Nodo p = this.prim;
        Nodo ap = null;
        while (p != null && p.elem > x) {
            ap = p;
            p = p.prox;
        }
        this.insertarNodo(ap, p, x);
    }
   
    /*9. L1.eliminarPrim() : Método que elimina el elemento de la primer posición.*/
   public void eliminarPrimT5(){
        if(this.vacia())
            return;
        if(prim==null)
            prim=ult=null;
        else{
            prim.prox.ant=null;
            prim=prim.prox;
        }
        this.cantElem--;
    }    
    
    /*10. L1.eliminarUlt() : Método que elimina el último elemento de la lista L1.*/
    public void eliminarUltT5(){
        if(this.vacia())
            return;
        if(prim==ult)
            prim=ult=null;
        else{
            ult.ant.prox=null;
            ult=ult.ant;
        }
        this.cantElem--;
    }    
    
    /*11. L1.mostrarIzqDer() : Método que muestra los elementos de la lista L1, de izquierda a derecha. */
    public void mostrarIzqDerT5() {
        Nodo p = prim;
        System.out.println("Izq-Der: ");
        while(p!=null){
            System.out.println(p.elem + "\t");
            p=p.prox;
        }
        System.out.println();
    }    
    
    /*12. L1.mostrarDerIzq() : Método que muestra los elementos de la lista L1, de derecha a izquierda. 
          Utilizar esto métodos para verificar si las inserciones y eliminaciones de elementos son correctas. */
    public void mostrarDerIzqT5(){
        Nodo p=ult;
        System.out.println("Der-Izq: ");
        while(p!=null){
            System.out.println(p.elem+"\t");
            p=p.ant;
        }
        System.out.println();
    }
    
    /*13. L1.rotarIzqDer( n ): Método que hacer rotar los elementos de la Lista L1, n veces de Izquierda a Derecha.*/
    public void rotarIzqDerT5(int n) {
        if (vacia() || n <= 0) {
            return;
        }
        n = n % cantElem; 
        for (int i = 0; i < n; i++) {
            Nodo temp = ult;
            ult = ult.ant;
            ult.prox = null;
            
            temp.prox = prim;
            temp.ant = null;
            prim.ant = temp;
            prim = temp;
        }
    }

    /*14. L1.rotarDerIzq( n ) : Método que hacer rotar los elementos de la Lista L1, n veces de Deerecha a Izquierda.*/
    public void rotarDerIzqT5(int n) {
        if (vacia() || n <= 0) {
            return;
        }
        n = n % cantElem; 
        for (int i = 0; i < n; i++) {
            Nodo temp = prim;
            prim = prim.prox;
            prim.ant = null;

            temp.ant = ult;
            temp.prox = null;
            ult.prox = temp;
            ult = temp;
        }
    }

    /*15. L1.eliminarIesimo(i): Método que elimina el i-ésimo elemento de la lista L1. Asumir el primer elemento 
          lugar cero y así sucesivamente. Si i se encuentra mas allá de la cantidad de elementos de la lista, 
          no elimina ningún elemento.*/
    public void eliminarIesimoT5(int i){
        if(i>=this.cantElem)
            return;
        int k=0;
        Nodo p=prim, ap=null;
        while(k<i && p!=null){
            k++;
            ap=p;
            p=p.prox;
        }
        this.eliminarNodo(ap, ap);
    }
    
    /*16. L1.eliminarNodo(ap, p) : Método que elimina el nodo p, y devuelve el nuevo nodo p.*/
    private Nodo eliminarNodoT5(Nodo ap, Nodo p){
        if(ap!=null){
            this.eliminarPrim();
            return prim;
        }
        if(p.prox==null){
            this.eliminarUlt();
            return null;
        }
        ap.prox=p.prox;
        p.prox.ant=ap;
        this.cantElem--;
        return ap.prox;
    }
    
    /*17. L1.eliminarTodo( x ) : Método que elimina todos los elementos x de la lista L1.*/
    public void eliminarTodoT5(int x){
        Nodo p=prim, ap=null;
        while(p!=null){
            if(p.elem==x)
                p=this.eliminarNodo(ap, ap);
            else{
                ap=p;
                p=p.prox;
            }
        }    
    }
    
    /*18. L1.eliminarEntreElem(a, b) : Método que eliminar los elementos entre a y b inclusive, de la Lista L1.*/
    public void eliminarEntreElemT5(int a, int b) {
        Nodo p = this.prim;
        while (p != null && p.elem <= b) {
            if (p.elem >= a && p.elem <= b) {
                Nodo temp = p.prox;
                this.eliminarNodo(p.ant, p);
                p = temp;
            } else {
                p = p.prox;
            }   
        } 
    }    
    
    /*19. L1.eliminarEntrePos(i, j) : Método que elimina los elementos de la Lista L1, que se encuentre entre el 
          i-esimo y j-esimo lugar.*/
    public void eliminarEntrePosT5(int i, int j) {
        int k = 0;
        Nodo p = this.prim;
        while (k <= j && p != null) {
            if (k >= i && k <= j) {
                Nodo temp = p.prox;
                this.eliminarNodo(p.ant, p);
                p = temp;
            } else {
                p = p.prox;
            }
            k++;
        }
    }
    
    /*20. L1.eliminarPares() : Método que elimina los elementos pares de la lista L1.*/
    public void eliminarParesT5(int x){
        Nodo p=prim, ap=null;
        while(p!=null){
            if(p.elem%2==0)
                p=this.eliminarNodo(ap, ap);
            else{
                ap=p;
                p=p.prox;
            }
        }    
    }   
    
    /*21. L1.eliminarExtremos( n ): Método que elimina n-elementos de cada extremos de la lista L1.*/
    public void eliminarExtremosT5(int n) {
        if (n > 0 && !this.vacia()) {
            this.eliminarPrim();
            this.eliminarUlt();
            eliminarExtremosT5(n - 1);
        }
    }   
    
    /*22. L1.eliminarDup() : Método que elimina los elementos duplicados de la Lista L1. Después de eliminar, 
          no existen elementos repetidos.*/
    public void eliminarDupT5() {
        Nodo p = this.prim;
        while (p != null) {
            Nodo q = p.prox;
            while (q != null) {
                if (p.elem == q.elem) {
                    this.eliminarNodo(p.ant, p);
                    break; 
                }
                q = q.prox;
            }
            p = p.prox;
        }
    }
    
    /*23. L1.eliminarUnicos() : Método que elimina los elementos que no se repiten el la Lista L1.*/
    public void eliminarUnicosT5() {
        Nodo p = prim;
        Nodo ap = null;
        while (p != null) {
            boolean encontrado = false;
            Nodo q = prim;
            while (q != null) {
                if (p != q && p.elem == q.elem) {
                    encontrado = true;
                    break;
                }
                q = q.prox;
            }
            if (!encontrado) {
                p = eliminarNodoT5(ap, p);
            } else {
                ap = p;
                p = p.prox;
            }
        }
    }  
    
    /*24.  L1.iguales() : Método Lógico que devuelve True, si todos los elementos de la lista L1 son iguales.*/
    public boolean igualesT5() {
        Nodo p = prim;
        while (p != null && p.prox != null) {
            if (p.elem != p.prox.elem) {
                return false;
            }
            p = p.prox;
        }
        return true;
    }
    
    /*25.  L1.diferentes() : Método Lógico que devuelve True, si todos los elementos de la lista L1 son diferentes.*/
    public boolean diferentesT5() {
        Nodo p = prim;
        while (p != null) {
            Nodo q = p.prox;
            while (q != null) {
                if (p.elem == q.elem) {
                    return false;
                }
                q = q.prox;
            }
            p = p.prox;
        }
        return true;
    }
    
    /*26.  L1.mayorElem() : Método que devuelve el mayor elemento de la lista L1.*/
    public int mayorElemT5() {
        if (vacia()) {
            System.out.println("La lista esta vacia");
        }
        int max = prim.elem;
        Nodo p = prim.prox;
        while (p != null) {
            if (p.elem > max) {
                max = p.elem;
            }
            p = p.prox;
        }
        return max; 
    }
    
    /*27.  L1.menorElem() : Método que devuelve el mayor elemento de la lista L1.*/
    public int menorElemT5() {
        if (vacia()) {
            System.out.println("Lista esta vacia");
        }
        int min = prim.elem;
        Nodo p = prim.prox;
        while (p != null) {
            if (p.elem < min) { 
                min = p.elem;
            }
            p = p.prox;
        }
        return min;
    }
    
    /*28.  L1.ordenado()  : Método Lógico que devuelve True, si todos los elementos de la lista L1 están 
           ordenados en forma ascendente o descendente.*/
    public boolean ordenado() {
        if (vacia()) {
            return true;    
        }
        Nodo p = this.prim;
        while (p.prox != null) {
            if (p.elem > p.prox.elem) {
                return false; 
            }
            p = p.prox; 
        }
        return true; 
    }
    
    /*29.  L1.indexOf(x) : Método que devuelve la posición (lugar) de la primera ocurrencia del elemento x. 
           Si x no se encuentra en la lista L1, el método devuelve –1.*/
    public int indexOfT5(int x) {
        int index = 0;
        Nodo p = prim;
        while (p != null) {
            if (p.elem == x) {
                return index;
            }
            p = p.prox;
            index++;
        }
        return -1;
    }
    
    /*30.  L1.lastIndexOf(x) : Método que devuelve la posición (lugar) de la última ocurrencia del elemento x. 
           Si x no se encuentra en la lista L1, el método devuelve –1.*/
    public int lastIndexOfT5(int x) {
        int index = cantElem - 1;
        Nodo p = ult;
        while (p != null) {
            if (p.elem == x) {
                return index;
            }
            p = p.ant;
            index--;
        }
        return -1;
    }
    
    /*31.  L1.reemplazar(x, y) : Método que reemplaza todas las ocurrencias del elemento x por el elemento y en 
           la lista L1.*/
    public void reemplazarT5(int x, int y) {
        Nodo p = prim;
        while (p != null) {
            if (p.elem == x) {
                p.elem = y;
            }
            p = p.prox;
        }
    }
    
    /*32.  L1.seEncuentra(x) : Método Lógico que devuelve True, si el elemento x, se encuentra en la lista L1.*/
    public boolean seEncuentraT5(int x) {
        Nodo p = prim;
        while (p != null) {
            if (p.elem == x) {
                return true;
            }
            p = p.prox;
        }
        return false;
    }
    
    /*33.  L1.frecuencia(x) : Método que devuelve la cantidad de veces que aparece el elemento x en la lista L1.*/
    public int frecuenciaT5(int x) {
        int cont = 0;
        Nodo p = prim;
        while (p != null) {
            if (p.elem == x) {
                cont++;
            }
            p = p.prox;
        }
        return cont;
    } 
    
    /*34.  L1.existeFrec(k) : Método Lógico que devuelve True, si existe algún elemento que se repite exactamente 
           k-veces en la lista L1.*/
    public boolean existeFrec(int k) {
        Nodo p = this.prim;
        while (p != null) {
            int ap = frecuenciaT5(p.elem);
            if (ap == k) {
                return true;
            }
            p = p.prox;
        }
        return false;
    }

    /*35. L1.mismasFrec() : Método Lógico que devuelve True, si los elementos de la lista L1 tienen la misma frecuencia.*/
    public boolean mismasFrec() {
        Nodo p = this.prim;
        while (p != null) {
            int fx = frecuenciaT5(p.elem);
            Nodo ap = this.prim;
            while (ap != null) {
                int fy = frecuenciaT5(ap.elem);
                if (fx != fy) {
                    return false;
                } 
                ap = ap.prox;
            }
            p = p.prox;
        }
        return true;
    }

    /*36.  L1.poker() : Método Lógico que devuelve True, si los elementos de la lista L1 forman poker. 
           (Todos los elementos son iguales excepto uno)*/
    public boolean pokerT5() {
        if (vacia()) {
            return false;
        }
        int elemPoker = prim.elem;
        Nodo p = prim.prox;
        while (p != null) {
            if (p.elem != elemPoker) {
                return false;
            }
            p = p.prox;
        } 
        return true;
    }
    
    /*37.  L1.palindrome() : Método lógico que devuelve True, si la lista L1 contiene elementos que forma un palíndrome.*/
    public boolean palindromeT5() {
        if (vacia()) {
            return false;
        }
        Nodo pInicio = prim;
        Nodo pFin = ult;
        while (pInicio != pFin && pInicio.ant != pFin) {
            if (pInicio.elem != pFin.elem) {
                return false;
            }
            pInicio = pInicio.prox;
            pFin = pFin.ant;
        }
        return true;
    }
    
    /*38.  Adicionar al menos 5 métodos de consulta interesantes.*/
    //**38.1. intercambiarExtremos()
    public void intercambiarExtremos() {
        if (cantElem >= 2) {
            Nodo temp = prim;
            prim = ult;
            ult = temp;
            prim.ant = null;
            ult.prox = null;
            prim.prox.ant = prim;
            ult.ant.prox = ult;
        }
    }
    
    //**38.2. insertarDespues(int x, int nuevoElem)
    public void insertarDespues(int x, int elem) {
        Nodo p = prim;
        while (p != null && p.elem != x) {
            p = p.prox;
        }
        if (p != null) {
            Nodo ap = new Nodo(p, elem, p.prox);
            if (p.prox != null) {
                p.prox.ant = ap;
            } else {
                ult = ap;
            }
            p.prox = ap;
            cantElem++;
        }
    }
    
    //**38.3. copiarLista()
    public ListaDoble copiarLista() {
        ListaDoble ap = new ListaDoble();
        Nodo p = prim;
        while (p != null) {
            ap.agregar(p.elem);
            p = p.prox;
        }
        return ap;
    }

    //**38.4. invertirLista()
    public void invertirLista() {
        Nodo temp = null;
        Nodo act = prim; 
        while (act != null) {
            temp = act.ant;
            act.ant = act.prox;
            act.prox = temp;
            act = act.ant;
        }
        if (temp != null) {
            prim = temp.ant;
        }
    }
    
    //**38.5. insertarDespuesDe(int x, int y)
    public void insertarDespuesDe(int x, int y) {
        Nodo ap = new Nodo(null, x, null);
        Nodo p = prim;
        while (p != null) {
            if (p.elem == y) {
                ap.ant = p;
                ap.prox = p.prox;
                if (p.prox != null) {
                    p.prox.ant = ap;
                } else {
                    ult = ap;
                }
                p.prox = ap;
                cantElem++;
                return; 
            }
            p = p.prox;
        }
    }

    /*--------------------------------------------------------------------------------------------------------*/  

    /****LAB-6 Numeros Extremadamente Grandes****/
    
    /*1. sumar(L1, L2, L3) : Procedimiento que suma L2 con L3 en L1. L1 = L2 + L3.*/   
    public static void sumar(ListaDoble l1, ListaDoble l2, ListaDoble l3){
        Nodo p=l2.ult, q=l2.ult;
        int carry =0;
        while(p!=null && q!=null){
            int sum = p.elem + q.elem+carry;
            l1.insertarPrim(sum%10);
            carry=sum/10;
            p=p.ant;
            q=q.ant;
        }
        while(p!=null){
            int sum=p.elem+carry;
            l1.insertarPrim(sum%10);
            carry=sum/10;
            p=p.ant;
        }
        while(q!=null){
            int sum = q.elem+carry;
            l1.insertarPrim(sum%10);
            carry=sum/10;
            q=q.ant;
        }
        if(carry!=0)
            l1.insertarPrim(carry);
    }

    public static void sumar2(ListaDoble l1, ListaDoble l2, ListaDoble l3){
        Nodo p=l2.ult, q=l3.ult;
        int carry=0;
        while(p!=null || q!=null){
            int sum=0;
            if(p!=null){
                sum=sum+p.elem;
                p=p.ant;
            }
            if(q != null){
                sum=sum+q.elem;
                q=q.ant;
            }
            sum=sum+carry;
            l1.insertarPrim(sum%10);
            carry=sum/10;
        }
        if(carry!=0)
            l1.insertarPrim(carry);
    }    
    
    /*2. igual(L1, L2) : Función Lógica que devuelve True, si el entero L1 es igual al entero L2.  L1 == L2.*/
    public boolean igual(ListaDoble L1, ListaDoble L2){
        if(L2.cantElem!=L1.cantElem)
            return false;
        Nodo p=L1.prim, q=L2.prim;
        while(p!=null){
            if(p.elem!=q.elem)
                return false;
            p=p.prox;
            q=q.prox;
        } 
        return true;
    }
    
    /*3. menor(L1, L2) : Función Lógica que devuelve True, si el entero L1 es menor que el entero L2.  L1 < L2.*/
    public boolean menor(ListaDoble L1, ListaDoble L2){
        if(L1.cantElem<L2.cantElem)
            return true;
        if(L1.cantElem>L2.cantElem)
            return true;
        if(L1.cantElem==L2.cantElem){
            Nodo p=L1.prim, q=L2.prim;
            while(p!=null){
                if(p.elem>q.elem)
                    return false;
                 p=p.prox;
                q=q.prox;  
            }
        }
        return true;
    }
    
    /*4. mayor(L1, L2) : Función Lógica que devuelve True, si el entero L1 es mayor que el entero L2.  L1 > L2.*/
    public boolean mayor(ListaDoble L1, ListaDoble L2){
        if(L1.cantElem<L2.cantElem)
            return false;
        if(L1.cantElem>L2.cantElem)
            return true;
        if(L1.cantElem==L2.cantElem){
            Nodo p=L1.prim, q=L2.prim;
            while(p!=null){
                if(p.elem<q.elem)
                    return false;
                p=p.prox;
                q=q.prox;  
            }
        }
        return true;
    }
        
    /*5. diferente(L1, L2) : Función Lógica que devuelve True, si los entero L1 y L2 son diferentes.*/
    public boolean diferentes(ListaDoble L1, ListaDoble L2){
        if(L2.cantElem!=L1.cantElem)
            return false;
        Nodo p=L1.prim, q=L2.prim;
        while(p!=null){
            if(p.elem==q.elem)
                return false;
            p=p.prox;
            q=q.prox;
        }
        return true;
    }
    
    /*6. diferencia(L1, L2, L3) : Procedimiento que encuentra la diferencia en L1 del mayor entre L2 y L3.*/
    public void diferencial(ListaDoble L1, ListaDoble L2, ListaDoble L3){
        if(L1.igual(L2, L3)){
            L1.insertarPrim(0);
            return ;
        }
        Nodo p=L2.ult, q=L3.ult; 
        if(L1.menor(L2, L3)){
            p=L3.ult; q=L2.ult;  
        }
        while(q!=null){
                if(p.elem<q.elem){
                    p.elem+=10;
                    p.prox.elem--;
                    L1.insertarPrim(p.elem-q.elem);
                }else{
                    L1.insertarPrim(p.elem-q.elem);
                }
                p=p.ant;
                q=q.ant;
            }
        while(p!=null){
            L1.insertarPrim(p.elem);
            p=p.ant;
        }
    }
    
    /*7. Incluir al menos 3 operaciones adicionales cualesquiera.*/
    
    /*7.1. concatenar(ListaDoble l1, ListaDoble l2)*/
    public void concatenar(ListaDoble l1, ListaDoble l2) {
        Nodo p = l1.prim;
        while (p != null) {
            this.agregar(p.elem);
            p = p.prox;
        }
        p = l2.prim;
        while (p != null) {
            this.agregar(p.elem);
            p = p.prox;
        }
    }
    
    /*7.2. esPalindromo(ListaDoble l1)*/
    public boolean esPalindromo(ListaDoble l1) {
        Nodo p = l1.prim;
        Nodo q = l1.ult;
        while (p != null && q != null) {
            if (p.elem != q.elem) {
                return false;
            }
            p = p.prox;
            q = q.ant;
        }
        return true;
    }
    
    /*7.3. multiplicarElementos(ListaDoble l1)*/
    public int multiplicarElementos(ListaDoble l1) {
        int producto = 1;
        Nodo p = l1.prim;
        while (p != null) {
            producto *= p.elem;
            p = p.prox;
        }
        return producto;
    }

    /*--------------------------------------------------------------------------------------------------------*/
    
    /****TAREA-6 Numeros Extremadamente Grandes****/
    
    /*1. sumar(L1, L2, L3) : Procedimiento que suma L2 con L3 en L1. L1 = L2 + L3.*/
    public static void sumarT6(ListaDoble l1, ListaDoble l2, ListaDoble l3){
        Nodo p=l2.ult, q=l3.ult;
        int carry=0;
        while(p!=null || q!=null){
            int sum=0;
            if(p!=null){
                sum=sum+p.elem;
                p=p.ant;
            }
            if(q != null){
                sum=sum+q.elem;
                q=q.ant;
            }
            sum=sum+carry;
            l1.insertarPrim(sum%10);
            carry=sum/10;
        }
        if(carry!=0)
            l1.insertarPrim(carry);
    }    
    
    /*2. igual(L1, L2) : Función Lógica que devuelve True, si el entero L1 es igual al entero L2.  L1 == L2.*/
    public boolean igualT6(ListaDoble L1, ListaDoble L2){
        if(L2.cantElem!=L1.cantElem)
            return false;
        Nodo p=L1.prim, q=L2.prim;
        while(p!=null){
            if(p.elem!=q.elem)
                return false;
            p=p.prox;
            q=q.prox;
        } 
        return true;
    }
    
    /*3. menor(L1, L2) : Función Lógica que devuelve True, si el entero L1 es menor que el entero L2.  L1 < L2.*/
    public boolean menorT6(ListaDoble L1, ListaDoble L2){
        if(L1.cantElem<L2.cantElem)
            return true;
        if(L1.cantElem>L2.cantElem)
            return true;
        if(L1.cantElem==L2.cantElem){
            Nodo p=L1.prim, q=L2.prim;
            while(p!=null){
                if(p.elem>q.elem)
                    return false;
                 p=p.prox;
                q=q.prox;  
            }
        }
        return true;
    }
    
    /*4. mayor(L1, L2) : Función Lógica que devuelve True, si el entero L1 es mayor que el entero L2.  L1 > L2.*/
    public boolean mayorT6(ListaDoble L1, ListaDoble L2){
        if(L1.cantElem<L2.cantElem)
            return false;
        if(L1.cantElem>L2.cantElem)
            return true;
        if(L1.cantElem==L2.cantElem){
            Nodo p=L1.prim, q=L2.prim;
            while(p!=null){
                if(p.elem<q.elem)
                    return false;
                p=p.prox;
                q=q.prox;  
            }
        }
        return true;
    }
    
    /*5. diferente(L1, L2) : Función Lógica que devuelve True, si los entero L1 y L2 son diferentes.*/
    public boolean diferentesT6(ListaDoble L1, ListaDoble L2){
        if(L2.cantElem!=L1.cantElem)
            return false;
        Nodo p=L1.prim, q=L2.prim;
        while(p!=null){
            if(p.elem==q.elem)
                return false;
            p=p.prox;
            q=q.prox;
        }
        return true;
    }
    
    /*6. generarNumero(L1, n) : procedimiento que genera en L1, aleatoriamente n-dígitos de un entero extremadamente grado.*/
    public void generarNumeroT6(int n) {
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            int digito = random.nextInt(10); // Generar un dígito aleatorio (0-9)
            if (!(this.vacia() && digito == 0)) {
                this.agregar(digito); // Agregar el dígito a la lista (excepto si es el primer dígito y es 0)
            }
        }
    }
    
    /*7. eliminarCeros(L1) : Procedimiento que elimina los dígitos ceros del inicio de la Lista L1.*/
    public void eliminarCerosT6() {
        Nodo p = this.prim;
        while (p != null && p.elem == 0) {
            this.prim = p.prox;
            p = p.prox;
            this.cantElem--;
        }
    }
    
    /*8. diferencia(L1, L2, L3) : Procedimiento que encuentra la diferencia en L1 del mayor entre L2 y L3. */
    public void diferencialT6(ListaDoble L1, ListaDoble L2, ListaDoble L3){
        if(L1.igual(L2, L3)){
            L1.insertarPrim(0);
            return ;
        }
        Nodo p=L2.ult, q=L3.ult; 
        if(L1.menor(L2, L3)){
            p=L3.ult; q=L2.ult;  
        }
        while(q!=null){
                if(p.elem<q.elem){
                    p.elem+=10;
                    p.prox.elem--;
                    L1.insertarPrim(p.elem-q.elem);
                }else{
                    L1.insertarPrim(p.elem-q.elem);
                }
                p=p.ant;
                q=q.ant;
            }
        while(p!=null){
            L1.insertarPrim(p.elem);
            p=p.ant;
        }
    }
    
    /*9. multiplicar(L1, L2, L3) : Procedimiento que encuentra la multiplicación de L2 con L3 en L1. L1 = L2 * L3.*/
    public void multiplicarT6(ListaDoble L2, ListaDoble L3) {
        ListaDoble resultado = new ListaDoble();
        Nodo p = L2.prim;
        int i = 0;
        while (p != null) {
            ListaDoble parcial = new ListaDoble();
            int carry = 0;
            Nodo q = L3.prim;
            for (int j = 0; j < i; j++) {
                parcial.agregar(0);
            }
            while (q != null) {
                int mult = p.elem * q.elem + carry;
                parcial.agregar(mult % 10);
                carry = mult / 10;
                q = q.prox;
            }
            if (carry != 0) {
                parcial.agregar(carry);
            }
            //resultado.sumarT6(resultado, parcial);
            p = p.prox;
            i++;
        }
        this.copiarLista(resultado);
    }

    private void copiarLista(ListaDoble lista) {
        this.prim = lista.prim;
        this.ult = lista.ult;
        this.cantElem = lista.cantElem;
    }    
    
    /*10. Incluir al menos 5 operaciones adicionales cualesquiera.*/
    
    /*10.1. reversa*/
    public void reversa() {
        Nodo temp = null;
        Nodo current = prim;
        while (current != null) {
            temp = current.ant;
            current.ant = current.prox;
            current.prox = temp;
            current = current.ant;
        }
        if (temp != null) {
            prim = temp.ant;
        }
    }

    /*10.2. eliminarEnPosicion*/
    public void eliminarEnPosicion(int posicion) {
        if (posicion < 0 || posicion >= cantElem) {
            return;
        }
        Nodo current = prim;
        for (int i = 0; i < posicion; i++) {
            current = current.prox;
        }
        if (current.ant != null) {
            current.ant.prox = current.prox;
        } else {
            prim = current.prox;
        }
        if (current.prox != null) {
            current.prox.ant = current.ant;
        } else {
            ult = current.ant;
        }
        cantElem--;
    }

    /*10.3. concatenar */
    /*public static ListaDoble concatenar(ListaDoble l1, ListaDoble l2) {
        ListaDoble nuevaLista = new ListaDoble();
        Nodo current = lista1.prim;
        while (current != null) {
            nuevaLista.insertarUlt(current.elem);
            current = current.prox;
        }
        current = lista2.prim;
        while (current != null) {
            nuevaLista.insertarUlt(current.elem);
            current = current.prox;
        }
        return nuevaLista;
    }*/

    /*10.4. buscarElemento*/
    public int buscarElemento(int elemento) {
        Nodo current = prim;
        int posicion = 0;
        while (current != null) {
            if (current.elem == elemento) {
                return posicion;
            }
            current = current.prox;
            posicion++;
        }
        return -1; // Si el elemento no se encuentra en la lista
    }

    /*10.5.obtenerTamaño */
    public int obtenerTamaño() {
        return cantElem;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}


