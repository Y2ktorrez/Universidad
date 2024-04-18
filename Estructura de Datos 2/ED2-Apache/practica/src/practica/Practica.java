/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package practica;

/**
 *
 * @author DCDS
 */
public class Practica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        ListaArbol l1 = new ListaArbol(30);
        
        l1.insertar("ae");
        l1.insertar("ai");
        l1.insertar("ao");
        l1.insertar("au");
        l1.insertar("aei");
        l1.insertar("aeo");
        l1.insertar("aeu");
        l1.insertar("aeio");
        l1.insertar("aeiu");
        l1.insertar("aeiou");
        
        System.out.print("Ordenado de Forma Ascendente, Ascendente");
        
        l1.AscAsc();
        System.out.println();
        System.out.print("Ordenado de Forma Descendente, Descendente");
        l1.DesDes();
        
        System.out.println();
        System.out.print("Es Ascendente: ");
        System.out.println(l1.ascendente());
        
        System.out.print("Tiene Mismos Terminos: ");
        System.out.println(l1.mismosTerm());
        
        System.out.println();
        l1.arbolGrande();
        
        
    }
    
}
