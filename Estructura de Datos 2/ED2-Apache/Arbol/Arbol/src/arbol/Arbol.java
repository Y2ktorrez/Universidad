/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package arbol;

/**
 *
 * @author DCDS
 */
public class Arbol {
    public Nodo raiz;
    
    public Arbol(){
        raiz=null;
    }
    
    
    //metodos de insercion
    public void insertar(String str){
        raiz=insertar(raiz, str);
    }
    
    private Nodo insertar(Nodo p, String str){
        if(p==null)
            return new Nodo(str);
        
          if(str.equals(p.str)){ 
            p.frec++;
            return p;
        }
          
        if(str.compareTo(p.str)<0)
            p.izq=insertar(p.izq, str);
        else
            p.der=insertar(p.der,str);
        
        return p;
    }
    
    
    public void insertar(String str, int frec){
        raiz=insertar(raiz, str, frec);
    }
    
    private Nodo insertar(Nodo p, String cad, int frec){
        if(p==null)
            return new Nodo(cad, frec);
        
       if(CompareMenor(p.str, cad))
            p.der=insertar(p.der, cad, frec);
        else
            p.izq=insertar(p.izq,cad, frec);
        
        return p;
    }
    
    private boolean CompareMenor(String cad, String canto){
        if(cad.length()>canto.length())
            return false;
        
        if(cad.length()<canto.length())
            return true;
        
        if(cad.length()==canto.length()){
            for (int i = 0; i < cad.length(); i++) {
                if(cad.charAt(i)<canto.charAt(i))
                    return true;
                
                if(cad.charAt(i)>canto.charAt(i))
                    return false;
            }
        }
        return true;
    }
    
    //Ordenamientos
    //1
    public void inOrden(){
        inOrden(raiz);
    }
   
    private void inOrden(Nodo p){
        if(p==null)
            return ;
        
        inOrden(p.izq);
        System.out.print("["+p.str+"]");
        inOrden(p.der);
    }
    
    //2
    public void inOrdenRev(){
        inOrdenRev(raiz);
    }
    
    public void inOrdenRev(Nodo p){
        if(p==null)
            return ;
        
        inOrdenRev(p.der);
        System.out.print("["+p.str+"]");
        inOrdenRev(p.izq);
    }
}
    
    
    
