/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arboles;
import java.util.Random;
import java.util.LinkedList;


/**
 *
 * @author DCDS
 */
public class Arbol {
    public Nodo raiz;
    
    public Arbol(){
        this.raiz=null;
    }
        
/*-------------------------------------------------------------------------------------------------------------*/
    
    /*****LAB1- Arboles Binarios de Busqueda*****/
   
    //1. A1.insertar(x) : Método que inserta el elemento x, en el árbol A1 en su lugar correspondiente.
    public void insertar(int x){
        this.raiz=this.insertar(this.raiz, x);
    }
    
    private Nodo insertar(Nodo p, int x){
        if(p==null) 
            return new Nodo(x);
        if(x<p.elem)
            p.izq=this.insertar(p.izq, x);
        else
            p.der=this.insertar(p.der, x);
      
        return p;
    }
    
    //2. A1.preOrden() : Método que muestra los elementos del árbol A1 en preOrden.
    public void preOrden(){
        this.preOrden(this.raiz);
    }
    
    private void preOrden(Nodo p){
        if(p==null)
            return;
        System.out.println(p.elem);
        this.preOrden(p.izq);
        this.preOrden(p.der); 
    }
    
    //3. A1.inOrden() : Método que muestra los elementos del árbol A1 en inOrden.
    public void inOrder(){
        this.inOrder(this.raiz);
    }
    
    private void inOrder(Nodo p){
        if(p==null)
            return;
        
        this.inOrder(p.izq);
        System.out.println(p.elem);
        this.inOrder(p.der);
    }
    
    //4. A1.postOrden() : Método que muestra los elementos del árbol A1 en postOrden.
    public void postOrden(){
        this.postOrden(this.raiz);
    }
    
    private void postOrden(Nodo p){
        if(p==null)
            return;
        this.postOrden(p.izq);
        this.postOrden(p.der);
        System.out.println(p.elem);
                    
    }
    //5. A1.seEncuentra(x) : Métodos lógico que devuelve True, si el elemento x, se encuentra en el árbol A1.
    public boolean seEncuentra(int x) {
        return seEncuentra(raiz, x);
    }

    private boolean seEncuentra(Nodo p, int x) {
        if (p == null) {
            return false;
        }
        if (p.elem == x) {
            return true;
        }
        return seEncuentra(p.izq, x) || seEncuentra(p.der, x);
    }
    
    //6. A1.cantidad() : Método que devuelve la cantidad de nodos del árbol A1. 
    public int cantidad() {
        return cantidad(raiz);
    }

    private int cantidad(Nodo p) {
        if (p == null) {
            return 0;
        }
        int cizq = cantidad(p.izq);
        int cder = cantidad(p.der);
        return 1 + cizq + cder;
    }
    
    //7. A1.suma() : Método que devuelve la suma de los elementos del árbol A1.
    public int suma(){
        return this.suma(this.raiz);
    }
    
    private int suma(Nodo p){
        if(p==null)
            return 0;
        else
            return suma(p.izq) + suma(p.der)+p.elem;
    }
    
    //8. A1.menor() : Método que devuelve el elemento menor del árbol A1.
    public int menor() {
        if (raiz == null) {
            return 0;
        }
        Nodo menor = menor(raiz);
        return menor.elem;
    }

    private Nodo menor(Nodo p) {
        if (p.izq == null) {
            return p;
        }
        return menor(p.izq);
    }
    
    //9. A1.mayor() : Método que devuelve el elemento mayor del árbol A1.
    public int mayor() {
        if (raiz == null) {
            return 0;
        }
        Nodo mayor = mayor(raiz);
        return mayor.elem;
    }

    private Nodo mayor(Nodo p) {
        if (p.der == null) {
            return p;
        }
        return mayor(p.der);
    }
    
    //10. A1.cantidadTerm() : Método que devuelve la cantidad de nodos terminales del árbol A1.
    public int cantidadTerm() {
        return cantidadTerm(raiz);
    }

    private int cantidadTerm(Nodo p) {
        if (p == null) 
            return 0;
        if (p.izq == null && p.der == null) return 1;
        return cantidadTerm(p.der) + cantidadTerm(p.der);
    }
    
/*-------------------------------------------------------------------------------------------------------------*/    
    
    /**TAREA-1. Arboles Binarios de Busqueda**/
    
    //1.  A1.generarElem(n, a, b) : Método que genera n elementos aleatorios enteros diferentes entre a y b inclusive.
    
    public void generarElem(int n, int a, int b) {
        if (n <= 0) {
            return;
        }   
        Random random = new Random();
        int elemento = random.nextInt(b - a + 1) + a;
        insertarT1(elemento); 
        generarElem(n - 1, a, b);
    }
    
    //2. A1.insertar(x) : Método que inserta el elemento x, en el árbol A1 en su lugar correspondiente.
    public void insertarT1(int x){
        this.raiz=this.insertarT1(this.raiz, x);
    }
    
    private Nodo insertarT1(Nodo p, int x){
        if(p==null) 
            return new Nodo(x);
        if(x<p.elem)
            p.izq=this.insertarT1(p.izq, x);
        else
            p.der=this.insertarT1(p.der, x);
      
        return p;
    }
    
    //3. A1.preOrden() : Método que muestra los elementos del árbol A1 en preOrden.
    public void preOrdenT1(){
        this.preOrdenT1(this.raiz);
    }
    
    private void preOrdenT1(Nodo p){
        if(p==null)
            return;
        System.out.println(p.elem);
        this.preOrdenT1(p.izq);
        this.preOrdenT1(p.der); 
    } 
    
    //4. A1.inOrden() : Método que muestra los elementos del árbol A1 en inOrden.
    public void inOrderT1(){
        this.inOrderT1(this.raiz);
    }
    
    private void inOrderT1(Nodo p){
        if(p==null)
            return;
        
        this.inOrderT1(p.izq);
        System.out.println(p.elem);
        this.inOrderT1(p.der);
    }
    
    //5. A1.postOrden() : Método que muestra los elementos del árbol A1 en postOrden.
    public void postOrdenT1(){
        this.postOrdenT1(this.raiz);
    }
    
    private void postOrdenT1(Nodo p){
        if(p==null)
            return;
        this.postOrdenT1(p.izq);
        this.postOrdenT1(p.der);
        System.out.println(p.elem);            
    }
    
    //6. A1.desc(): Método que muestra los elementos del árbol A1 de mayor a menor.
    public void descT1() {
        descT1(this.raiz);
    }

    private void descT1(Nodo p) {
        if (p == null) {
            return;
        }
        descT1(p.der);
        System.out.println(p.elem);
        descT1(p.izq);
    }

    //7. A1.seEncuentra(x) : Métodos lógico que devuelve True, si el elemento x, se encuentra en el árbol A1.
    public boolean seEncuentraT1(int x) {
        return seEncuentra(raiz, x);
    }

    private boolean seEncuentraT1(Nodo p, int x) {
        if (p == null) {
            return false;
        }
        if (p.elem == x) {
            return true;
        }
        if (x < p.elem) {
            return seEncuentraT1(p.izq, x);
        } else {
            return seEncuentraT1(p.der, x);
        }
    }
    
    //8. A1.cantidad() : Método que devuelve la cantidad de nodos del árbol A1.
    public int cantidadT1() {
        return cantidadT2(raiz);
    }

    private int cantidadT2(Nodo p) {
        if (p == null) {
            return 0;
        }
        int cizq = cantidadT2(p.izq);
        int cder = cantidadT2(p.der);
        return 1 + cizq + cder;
    }
    
    //9. A1.suma() : Método que devuelve la suma de los elementos del árbol A1.
    public int sumaT1(){ 
        return this.sumat2(this.raiz);
    }
    
    private int sumat2(Nodo p){
        if(p==null)
            return 0;
        else
            return sumat2(p.izq) + sumat2(p.der)+p.elem;
    }
    
    //10. A1.menor() : Método que devuelve el elemento menor del árbol A1.
    public int menorT1() {
        if (raiz == null) {
            return 0;
        }
        Nodo menorT1 = menorT1(raiz);
        return menorT1.elem;
    }

    private Nodo menorT1(Nodo p) {
        if (p.izq == null) {
            return p;
        }
        return menorT1(p.izq);
    }
    
    //11. A1.mayor() : Método que devuelve el elemento mayor del árbol A1.
    public int mayorT1() {
        if (raiz == null) {
            return 0;
        }
        Nodo mayorT1 = mayorT1(raiz);
        return mayorT1.elem;
    }

    private Nodo mayorT1(Nodo p) {
        if (p.der == null) {
            return p;
        }
        return mayorT1(p.der);
    }
    
    //12. A1.mostrarTerm(): Método que muestra los elementos de los nodos terminales del árbol A1. Mostrar los elementos de menor a mayor.
    public void mostrarTermT1() {
        mostrarTermT1(this.raiz);
    }

    private void mostrarTermT1(Nodo p) {
        if (p == null) {
            return;
        }
        if (p.izq == null && p.der == null) {
            System.out.println(p.elem);
        }
        mostrarTermT1(p.izq);
        mostrarTermT1(p.der);
    }

    //13. A1.cantidadTerm(): Método que devuelve la cantidad de nodos terminales del árbol A1.
    public int cantidadTermT1() {
        return cantidadTermT1(raiz);
    }

    private int cantidadTermT1(Nodo p) {
        if (p == null)  
            return 0;
        if (p.izq == null && p.der == null) return 1;
        return cantidadTermT1(p.izq) + cantidadTermT1(p.der);
    }
       
    //14. A1.lineal() : Método lógico que devuelve True, si el árbol A1 es un árbol degenerado o lIneal. (Se puede dar cuando se genera el árbol con una secuencia ordenada de elementos)
    public boolean linealT1(){
        return linealT1(raiz, raiz);
    }
    
    private boolean linealT1(Nodo p, Nodo q){
        if(p.der==null && p.izq==null)
            return true;
        
        if(p.der==null && p.izq!=null && q.elem>=p.elem && (q.elem-p.elem==0 || q.elem-p.elem==1)){
            return linealT1(p.izq, p);
        }
        
        if(p.izq==null && p.der!=null && q.elem<=p.elem && (q.elem-p.elem==0 || q.elem-p.elem==1))
            return linealT1(p.der, p);
        
        return false;
    }

    //15. A1.inmediatoSup(x) : Método que devuelve el elemento inmediato superior a x, si x se encuentra en A1, caso contrario devuelve el mismo elemento.
    public int inmediatoSupT1(int x){
        int auz;
        if(seEncuentra(x)){
            auz= inmediatoSupT1(x, raiz);
            if(auz==0)
                return x;
            
            return auz;
        }else
            return x;
    }
    
    private int inmediatoSupT1(int x, Nodo p){
        if(p==null)
            return 0;
        
        if(p.elem-x==1 )
            return p.elem;
        
        return inmediatoSupT1(x,p.der)+inmediatoSupT1(x, p.izq);
    }

    //16. A1.inmediatoInf(x) : Método que devuelve el elemento inmediato inferior a x, si x se encuentra en A1, caso contrario devuelve el mismo elemento.
    public int inmediatoInfT1(int x) {
        return inmediatoInfT1(raiz, x);
    }

    private int inmediatoInfT1(Nodo p, int x) {
        if (p == null) {
            return x;
        }
        if (x > p.elem) {
            return Math.max(p.elem, inmediatoInfT1(p.der, x));
        } else {
            return inmediatoInfT1(p.izq, x);
        }
    }

    //17. Implementar al menos 5 Ejercicios adicionales cualesquiera, de consultas sobre uno o más árboles binarios de búsqueda. Citar fuentes.

    //17.1. Buscar el K-ésimo elemento más pequeño
    public int kthSmallestT1(int k) {
        int[] count = {0};
        return kthSmallestT1(raiz, k, count);
    }

    private int kthSmallestT1(Nodo p, int k, int[] count) {
        if (p == null) {
            return 0;
        }
        int izquierda = kthSmallestT1(p.izq, k, count);
        if (izquierda != 0) {
            return izquierda;
        }
        count[0]++;
        if (count[0] == k) {
            return p.elem;
        }
        return kthSmallestT1(p.der, k, count);
    }
    
    //17.2. Verificar si dos árboles son iguales
    public boolean sonIgualesT1(Arbol otroArbol) {
        return sonIgualesT1(this.raiz, otroArbol.raiz);
    }

    private boolean sonIgualesT1(Nodo p, Nodo q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        return (p.elem == q.elem) && sonIgualesT1(p.izq, q.izq) && sonIgualesT1(p.der, q.der);
    }
    
    //17.3. Calcular la altura del árbol
    public int alturaT1() {
        return alturaT1(this.raiz);
    }

    private int alturaT1(Nodo p) {
        if (p == null) {
            return -1;
        }
        int alturaIzq = alturaT1(p.izq);
        int alturaDer = alturaT1(p.der);
        return 1 + Math.max(alturaIzq, alturaDer);
    }
    
    //17.4. Verificar si el árbol es equilibrado
    public boolean esEquilibradoT1() {
        return esEquilibradoT1(this.raiz);
    }

    private boolean esEquilibradoT1(Nodo p) {
        if (p == null) {
            return true;
        }
        int alturaIzq = alturaT1(p.izq);
        int alturaDer = alturaT1(p.der);
        if (Math.abs(alturaIzq - alturaDer) > 1) {
            return false;
        }
        return esEquilibradoT1(p.izq) && esEquilibradoT1(p.der);
    }
    
    //17.5. Contar el número de nodos en un nivel específico
    public int contarNodosEnNivelT1(int nivel) {
        return contarNodosEnNivelT1(this.raiz, nivel);
    }

    private int contarNodosEnNivelT1(Nodo p, int nivel) {
        if (p == null) {
            return 0;
        }
        if (nivel == 0) {
            return 1;
        }
        return contarNodosEnNivelT1(p.izq, nivel - 1) + contarNodosEnNivelT1(p.der, nivel - 1);
    }

/*-------------------------------------------------------------------------------------------------------------*/    
    
    //A1.niveles(): Método que muestra los elementos del árbol A1, por niveles.
    public void niveles() {
        LinkedList<Nodo> L1 = new LinkedList();
        L1.add(raiz);
        while (!L1.isEmpty()) {
            Nodo q = L1.getFirst();
            if (q.izq != null) {
                L1.add(q.izq);
            }
            if (q.der != null) {
                L1.add(q.der);
            }
            L1.removeFirst();
            System.out.println(q.elem);
        }
    }
 
    public void niveles1(){
        niveles1 (raiz, 0);
    }
        
    private void niveles1(Nodo p, int nivel){
        if(p==null) 
            return;
        niveles1(p.izq, nivel + 1);
        System.out.println(p.elem+" ," + nivel);
        niveles1(p.der, nivel+1);
    }
    
    /*Dado una secuencia de n-elementos, encontrar la frecuencia de cada elemento. Mostrar los elementos de menor
      a mayor con sus respectivas frecuencias. Utilizar un ABB, para devolver 
     
        50, 20, 30, 70, 50, 10, 20
        30, 60, 50, 70, 10, 15, 90*/
    
    
    
    
    
    
}
