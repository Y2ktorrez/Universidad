/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package arboles;
import java.util.LinkedList;

/**
 *
 * @author DCDS
 */
public class Arboles {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
//        Arbol a1 = new Arbol();
//        
//        a1.insertarT1(5);
//        a1.insertarT1(3);
//        a1.insertarT1(8); 
//        a1.insertarT1(2);
//        a1.insertarT1(6);
//        a1.insertarT1(9);    
//        

        //a1.preOrdenT1();
        
        //a1.inOrderT1();
        
        //a1.postOrdenT1();
        
        /*System.out.println(a1.seEncuentraT1(4));
        System.out.println(a1.seEncuentraT1(5));*/
       
        /*int cant = a1.cantidadT1();
        System.out.println(cant);*/
        
        /*int suma = a1.sumaT1();
        System.out.println(suma);*/
        
        /*int menor = a1.menorT1();
        System.out.println(menor);*/
        
        /*int mayor = a1.mayorT1();
        System.out.println(mayor);*/
        
        //a1.mostrarTermT1();
        
        //System.out.println(a1.cantidadTermT1()); //3
        
        /*boolean b=a1.linealT1(); //false
        System.out.println(b);*/
                
        /*System.out.println(a1.esLinealT1()); //false
        int x = 6;
        int sup = a1.inmediatoSupT1(x);
        System.out.println(x+sup);*/
        
        /*System.out.println(a1.esLinealT1()); //false
        int x = 6;
        int inf = a1.inmediatoInfT1(x);
        System.out.println(x+inf);*/
        
    /*-------------------------------------------------------------------------------------------------------------*/
    
        //LinkedList<Integer> L1 = new LinkedList();
        //a1.niveles(); // encuentra inOrden en L1.
        //System.out.println(L1); // muestra L1, de menor a mayor.
        
        Arbol2 a1 = new Arbol2();
        a1.generar(10, 1, 10);
        a1.OrdDes();
        
        
        
    }
    
}
