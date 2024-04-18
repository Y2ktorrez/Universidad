/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arboles;

/**
 *
 * @author DCDS
 */
public class Nodo {    
    public Nodo izq;
    public Nodo der;
    public int elem;
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
    
    public Nodo(int x){
        elem=x;
        izq=der=null;
        
    }
    
}
