/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package arbol;
import java.io.*;

/**
 *
 * @author DCDS
 */
public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ListaArbol l1= new ListaArbol(50);
        
        l1.insertar("abc");
        l1.insertar("xyz");
        l1.insertar("i");
        l1.insertar("pq");
        l1.insertar("a");
        l1.insertar("bc");
        l1.insertar("xy");
        l1.insertar("e");
        l1.insertar("stu");
        l1.insertar("ef");
        l1.insertar("o");
        l1.insertar("st");
        l1.insertar("bcd");
        l1.insertar("vw");
        l1.insertar("mno");
        l1.insertar("rs");
        l1.insertar("def");
        l1.insertar("u");
        //l1.insertar("u");
        
//        l1.palabrasAscDes();
//        l1.palabrasDesAsc();
//        l1.palabrasDesDes();
//        l1.palabrasAscAsc();
        

        
        ListaArbolFrec l2 = new ListaArbolFrec(1000);
        l2.arboleda(l1);
        l2.mayorMenor();
        l2.menorMayor(); 
        
        // ARCHIVOS
        PrintStream console = System.out;
        
        try {
            //String rutaArchivo = "C:\\Users\\Benitez\\Desktop\\output.txt";
            String rutaArchivo = "C:\\Users\\DCDS\\Desktop\\output1.txt";
            File file = new File(rutaArchivo);
            FileOutputStream fos = new FileOutputStream(file);
            PrintStream ps = new PrintStream(fos);
            System.setOut(ps);

            //l1.convert("C:\\Users\\Benitez\\Downloads\\The Call of Cthulhu.txt");
            l1.convert("C:\\Users\\DCDS\\Desktop\\The Call of Cthulhu.txt");
            l2.arboleda(l1);
            System.out.println("ArrayTree palabrasAscAsc");
            l1.palabrasAscAsc();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTreeFrec menorMayor");
            l2.menorMayor();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTreeFrec mayorMenor");
            l2.mayorMenor();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTree palabrasAscDes");
            l1.palabrasAscDes();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTree palabrasDesAsc");
            l1.palabrasDesAsc();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTree palabrasDesDes");
            l1.palabrasDesDes();
            System.setOut(console);

            fos.close();

            System.out.println("ArrayTree palabrasAscAsc");
            l1.palabrasAscAsc();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTreeFrec menorMayor");
            l2.menorMayor();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTreeFrec mayorMenor");
            l2.mayorMenor();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTree palabrasAscDes");
            l1.palabrasAscDes();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTree palabrasDesAsc");
            l1.palabrasDesAsc();
            System.out.println();
            System.out.println();
            System.out.println("ArrayTree palabrasDesDes");
            l1.palabrasDesDes();
        } catch (IOException e) {
            e.printStackTrace();
        }


       
        
        
        
        
        
        
        
        

    

        
               
        
    }
    
}
