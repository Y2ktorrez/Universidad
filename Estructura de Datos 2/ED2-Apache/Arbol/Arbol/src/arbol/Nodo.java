/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arbol;

/**
 *
 * @author DCDS
 */
public class Nodo {
    public Nodo izq;
    public Nodo der;
    public String str;
    public int frec;

    public Nodo(String x, int frecc){
        this.str=x;
        if(frecc!=0)
            this.frec=frecc;
        else
            this.frec=1;
        this.izq=this.der=null;
    }
    
    
    public Nodo(String str){
        this.str=str;
        izq=der=null;
    }
    
} 
