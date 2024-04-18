/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arbol;

/**
 *
 * @author DCDS
 */
public class ListaArbolFrec {
    public int max;
    public Arbol arbol[];
    
    public ListaArbolFrec(int max){
        this.max=max;
        this.arbol=new Arbol[max];
        for (int i = 0; i < max; i++) {
            arbol[i]=new Arbol();
        }
    }
    
    public void insertar(String str, int frec){//asc asc
        arbol[frec].insertar(str, frec);
    }
    

    public void arboleda(ListaArbol arr){
        for (int i = 0; i < arr.max; i++) {
            if(arr.arbol[i].raiz!=null){
                recorrido(arr.arbol[i]);
            }
        }
    }
    
    public void recorrido(Arbol ar){
        recorrido(ar.raiz);
    }
    
    private void recorrido(Nodo p){
        if(p==null)
            return;
        
        insertar(p.str, p.frec);
        recorrido(p.izq);
        recorrido(p.der);
    }
    
    public void menorMayor(){
        for (int i = 0; i < max; i++) {
            if(arbol[i].raiz!=null){
                System.out.println();
                System.out.print("Frecuencia: "+(i+1)+".-");
                arbol[i].inOrden();
                System.out.println();
            }
        }
    }
    
    public void mayorMenor(){
        for (int i = 0; i < max; i++) {
            if(arbol[i].raiz!=null){
                System.out.println();
                System.out.print("Frecuencia: "+(i+1)+".-");
                arbol[i].inOrdenRev();
                System.out.println();
            }
        }
    }
    

    
    

    
    
}

