/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package binarios;

/**
 *
 * @author DCDS
 */
public class Binarios {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
           
        
        
    Arbol a1 = new Arbol();
    
    a1.insertar(5);
    a1.insertar(3);
    a1.insertar(7);
    a1.insertar(2);
    a1.insertar(4);
    a1.insertar(3);
    a1.insertar(1);
    a1.insertar(8);
    a1.insertar(2);

    a1.inOrder();

    Arbol arbolpequeño = a1.arbolpequeño();

    System.out.println("Mas Chiquito");
    
    arbolpequeño.inOrder();
        
        
        
        
        
        
        
        
    
    }
   
}