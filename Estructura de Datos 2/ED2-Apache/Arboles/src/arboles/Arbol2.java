/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arboles;
import java.util.LinkedList;

import java.util.Random;

/**
 *
 * @author DCDS
 */
public class Arbol2 {
    public Nodo raiz;
    
    public Arbol2(){
        raiz=null;
    }
    
    //Insertar
    public void insertar(int x){
        raiz=insertar(raiz, x);
    }
    
    private Nodo insertar(Nodo p, int x){
        if(p==null)
            return new Nodo(x);
        if(p.elem==x){
            p.frec++;
            return p;
        }
        if(x<p.elem)
            p.izq=insertar(p.izq, x);
        else
            p.der=insertar(p.der, x);
        
        return p;
    }
    
    //1
    public void OrdAsc(){
        ordAsc(raiz);
    }
    private void ordAsc(Nodo p){
        if(p==null)
            return;
        
        ordAsc(p.izq);
        //System.out.println("["+p.elem+", "+p.frec+"]");
        System.out.println(p.elem+ " [" + p.frec + "]");
        ordAsc(p.der);
    }
    
    //2
    public void OrdDes(){
        ordDes(raiz);
    }
    private void ordDes(Nodo p){
        if(p==null)
            return;
        
        ordDes(p.der);
        //System.out.println("["+p.elem+", "+p.frec+"]");
        System.out.println(p.elem+ " [" + p.frec + "]");
        ordDes(p.izq);
    }
     
    /*Crear otro ABB, con los elementos del árbol anterior, organizados por frecuencia de ocurrencia y elemento. */
    
    //3
    public void ordFrecAsc(Arbol2 ar){
        ordFrecAsc(ar, raiz);
        ordFrecAsc(ar.raiz);
    }
    
    private void ordFrecAsc(Arbol ar, Nodo p){
        if(p==null)
            return;
        
        ordFrecAsc(ar, p.izq);
        ar.insertar(p.elem, p.frec);
        //System.out.println("["+q.elem+", "+q.frec+"]");
        ordFrecAsc(ar, p.der);
    }
    
    private void ordFrecAsc(Nodo p){
        if(p==null)
            return;
        
        ordFrecAsc(p.izq);
        System.out.println("["+p.elem+", "+p.frec+"]");
        ordFrecAsc(p.der);
    }
    
    //generar n-elementos enteros entre a y b inclusive
    public void generar(int n, int a, int b){
        if(n<=0){
            return;
        }
        Random random= new Random();
        int elemento = random.nextInt(b - a + 1) + a;
        insertar(elemento); 
        generar(n - 1, a, b);
    }
    
    
    
    
    
    

    
    
}
