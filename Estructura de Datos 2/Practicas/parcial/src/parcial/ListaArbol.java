/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package parcial;

/**
 *
 * @author DCDS
 */
public class ListaArbol {
    public int max;
    public Arbol arbol[];
    
    public ListaArbol(int max){
        this.max=max;
        this.arbol = new Arbol[max];
        for (int i = 0; i < max; i++) {
            arbol[i] = new Arbol();
        }
    }
    
    public void insertar(String str){
        arbol[str.length()].insertar(str);
    }
    
    //1
    public void ascasc(){
        for (int i = 0; i < max; i++) {
            if(arbol[i].raiz!=null){
                System.out.println();
                System.out.print("Longitud: " + i + ".-");
                arbol[i].inOrden();
                System.out.println();
            }
        }
    }

    //2 
    public void desdes(){
        for (int i = max-1; i > 0; i--) {
            if(arbol[i].raiz!=null){
                System.out.println();
                System.out.print("Longitud: " + i + ".-");
                arbol[i].inOrdenRev();
                System.out.println();
            }
        }
    }
    
    //3
    public void arbolGrande(){
        int may = arbol[1].cantidad();
        int pos=1;
        for (int i = 2; i < max; i++) {
            if(arbol[i].raiz!=null){
                if(arbol[i].cantidad()>may){
                    may = arbol[i].cantidad();
                }
            }
        }
        System.out.print("Longitud " + pos + " con " +may+ " elementos " );
        arbol[pos].inOrden();
    }
    
    //4
    public boolean mismosTermino(){
        int may = arbol[1].cantidad();
        for (int i = 0; i < max; i++) {
            if(arbol[i].raiz!=null){
                if(may != arbol[i].cantidad()){
                    return false;
                }
            }
        }
        return true;
    }
    
    //5
    public boolean Ascendente(){
        int men = arbol[1].cantidad();
        for (int i = 0; i < max; i++) {
            if(arbol[i].raiz!=null){
                if(arbol[i].cantidad()<men){
                    return false;
                }
                men = arbol[i].cantidad();
            }
        }
        return true;
    }
    
}
