/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package parcial;

/**
 *
 * @author DCDS
 */
public class Arbol {
    Nodo raiz;     

    public Arbol(){
        raiz=null;
    }
          
    public void insertar(String x){
        raiz=insertar(raiz, x);
    }
    
    private Nodo insertar(Nodo p, String x){
        if(p==null)
            return new Nodo(x);
        
        if(x.length()<p.str.length())
            p.izq=insertar(p.izq, x);
        else
            p.der=insertar(p.der, x);
        
        return p;
    }
 
    public void inOrden(){
        inOrden(raiz);
    }
   
    private void inOrden(Nodo p){
        if(p==null)
            return ;
        
        inOrden(p.izq);
        System.out.print("["+p.str+"]");
        inOrden(p.der);
    }
    
    //2
    public void inOrdenRev(){
        inOrdenRev(raiz);
    }
    
    public void inOrdenRev(Nodo p){
        if(p==null)
            return ;
        
        inOrdenRev(p.der);
        System.out.print("["+p.str+"]");
        inOrdenRev(p.izq);
    }
     
    //3
    public int cantidad(){
        return cantidad(raiz);
    }
    
    private int cantidad(Nodo p){
        if(p==null){
            return 0;
        }
        return cantidad(p.izq) + cantidad(p.der) + 1;
    }
    
    

}