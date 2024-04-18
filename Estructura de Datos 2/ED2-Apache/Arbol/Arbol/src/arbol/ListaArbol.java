/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arbol;
import java.io.*;

/**
 *
 * @author DCDS
 */
public class ListaArbol {
    public int max;
    public Arbol arbol[];
    
    public ListaArbol(int max){
        this.max=max;
        this.arbol=new Arbol[max];
        for (int i = 0; i < max; i++) {
            arbol[i]=new Arbol();
        }
    }
    
    public void insertar(String str){//asc asc
        arbol[str.length()].insertar(str);
    }
    
    public void inOrden(){
        for (int i = 0; i < max; i++) {
            arbol[i].inOrden();
            if(arbol[i].raiz!=null)
                System.out.println();
        }
    }
    
    //1    
    public void palabrasAscAsc(){
        for (int i = 1; i < max; i++) {
            if(arbol[i].raiz!=null){
                System.out.println();
                System.out.print("Longitud: "+i+".-");
                arbol[i].inOrden();
                System.out.println();
            }
        }
    }
    
    //2
    public void palabrasAscDes(){
        for (int i = 1; i < max; i++) {
            if(arbol[i].raiz!=null){
                System.out.println();
                System.out.print("Longitud: "+i+".-");
                arbol[i].inOrdenRev();
                System.out.println();
            }
        }
    }
    
    //3
    public void palabrasDesAsc(){
        for (int i = max-1; i > 0; i--) {
            if(arbol[i].raiz!=null){
                System.out.println();
                System.out.print("Longitud: "+i+".-");
                arbol[i].inOrden();
                System.out.println();
            }
        }
    }
    
    //4
    public void palabrasDesDes(){
        for (int i = max-1; i > 0; i--) {
            if(arbol[i].raiz!=null){
                System.out.println();
                System.out.print("Longitud: "+i+".-");
                arbol[i].inOrdenRev();
                System.out.println();
            }
        }
    }
    
    //Procesamiento de archivos
    public void tokenizer(String cad){
        String[] tokens=cad.split("\\s+");
        for (String token : tokens) {
            insertar(token.toLowerCase());
        }
    }
    
    public void convert(String ruta){
               
       try {
            File file = new File(ruta); 
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;            
            while ((line = bufferedReader.readLine()) != null) {     
                tokenizer(line);
            }            
            bufferedReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
     
}
    
    

    

