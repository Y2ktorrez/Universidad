/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package binarios;

/**
 *
 * @author DCDS
 */
public class Arbol {
        public Nodo raiz;
    
    public Arbol(){
        this.raiz=null;
    }
    
    //Metodo de Insertar 
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
    
    public int cantidad(){
        return cantidad(raiz);
    }
    
    private int cantidad(Nodo p){
        if(p==null)
            return 0;
        
        int canti=cantidad(p.izq);
        int canto=cantidad(p.der);
        
        return 1+canti+canto;
    }
    
    
    public Arbol arbolpequeño() {
        Arbol arbolpequeño = new Arbol();
        arbolpequeño.raiz = arbolpequeño(raiz);
        return arbolpequeño;
    }

    private Nodo arbolpequeño(Nodo p) {
        if (p == null) return null;
        Nodo n = new Nodo(p.elem);
        n.izq = arbolpequeño(p.izq);
        return n;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    //Elimnar
    public Nodo eliminar(Nodo p, int x){
        if(p==null){
            return null;
        }
        
        if(x==p.elem){
            return eliminarNodo(p);
        }
        
        if(x<p.elem){
            p.izq=eliminar(p.izq, x);
        }else{
            p.der=eliminar(p.der,x);
        }
        return p;
    }
    
    public Nodo eliminarNodo(Nodo p){
        if(p.izq == null && p.der == null)
            return null;
        if(p.izq == null && p.der != null)
            return p.der;
        if(p.izq != null && p.der == null)
            return p.izq;
        
        Nodo q=p.der;
        while(q.izq != null){
            q=q.izq;
        }
        q.izq=p.izq;
        return p.der;
    }
    
    
    //A1.eliminarHojas() : Método que elimina los nodos hoja de árbol A1.
    
    public void esHoja(Nodo p){
       if(p.izq==null && p.der==null){
           return ;
       }
    }
    
    
    
    public void eliminarHojas(){
        eliminarHoja(raiz);
    }
    public void eliminarHoja(Nodo p){
        if(p==null)
           return ;
           if(p.esHoja())//if(p.izq==null && p.der==null)
            eliminar(p.elem);
        eliminarHoja(p.izq);      
        eliminarHoja(p.der);

    }
    
    //A1.eliminarPares() : Método que elimina los elementos pares del árbol A1.
    public void eliminarPares(){
        eliminarPares(raiz);
    }
    public void eliminarPares(Nodo p){
        if(p==null)
            return;
        if(p.elem%2==0)
            eliminar(p.elem);
        eliminarPares(p.izq);
        eliminarPares(p.der);
    }

    
*/    

    

    
    
    
    
}
