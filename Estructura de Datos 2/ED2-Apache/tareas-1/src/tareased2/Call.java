/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package tareased2;

/**
 *
 * @author DCDS
 */
public class Call {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

 
        Lista lista1 = new Lista();

        lista1.agregarElemento(4);
        lista1.agregarElemento(2);
        lista1.agregarElemento(1);
        lista1.agregarElemento(3);
             
        /*System.out.println("Lista original:");
        lista1.imprimir();*/

        int menor = lista1.menorElem();
        System.out.println("El menor elemento en la lista es: " + menor);

    }

}
