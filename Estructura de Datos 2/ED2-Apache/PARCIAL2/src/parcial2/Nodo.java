/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package parcial2;

/**
 *
 * @author DCDS
 */
public class Nodo {
    public Nodo izq;
    public Nodo der;
    public int elem;
    
    public Nodo(int elem){
        izq=der=null;
        this.elem=elem;
    }
}
