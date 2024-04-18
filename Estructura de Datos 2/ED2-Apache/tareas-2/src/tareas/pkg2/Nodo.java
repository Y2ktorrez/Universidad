/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tareas.pkg2;

/**
 *
 * @author DCDS
 */
public class Nodo {
    public Nodo ant;
    public int elem;
    public Nodo prox;
    
    public Nodo(Nodo ant, int x, Nodo prox){
        this.ant=ant;
        this.elem=x;
        this.prox=prox;
    }
}
