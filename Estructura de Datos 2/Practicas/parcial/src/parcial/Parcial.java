/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package parcial;

/**
 *
 * @author DCDS
 */
public class Parcial {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        ListaArbol l1 = new ListaArbol(50);
        
        l1.insertar("a");
        l1.insertar("e");
        l1.insertar("i");
        l1.insertar("ae");
        l1.insertar("ai");
        l1.insertar("ea");
        l1.insertar("ei");
        l1.insertar("ia");
        l1.insertar("ie");
        l1.insertar("aei");
        l1.insertar("eai");
        l1.insertar("aeio");
        
        System.out.print("Ordenado de Forma Ascendente, Ascendente");
        
        l1.ascasc();
        System.out.println();
        System.out.print("Ordenado de Forma Descendente, Descendente");
        l1.desdes();
        
        System.out.println();
        System.out.print("Es Ascendente: ");
        System.out.println(l1.Ascendente());
        
        System.out.print("Tiene Mismos Terminos: ");
        System.out.println(l1.mismosTermino());
        
        System.out.println();
        l1.arbolGrande();
        
        
    }
}
