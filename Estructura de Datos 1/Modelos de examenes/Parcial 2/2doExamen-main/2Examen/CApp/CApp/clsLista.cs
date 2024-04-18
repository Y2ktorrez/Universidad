using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CApp
{
    public class clsLista
    {
        // Se define la clase Nodo
        public class Nodo
        {
            public int info;
            public Nodo sig;
        }
        // Se define los nodos tope (primero) y rear (ultimo)
        private Nodo tope, rear;
        // Constructor de la Clase Lista
        public clsLista()
        {
            tope = null;
            rear = null;
        }
        public clsLista Lista
        {
            get { return Lista; }
            set { Lista = value; }
        }
        public bool Vacia()
        {
            return tope == null;
        }
        public clsLista AddPrimero(int elemento)
        {
            clsLista L = new clsLista();
            Nodo nuevo;
            nuevo = new Nodo();
            nuevo.info = elemento;
            nuevo.sig = tope;
            if (Vacia())  //caso1 si la lista esta vacia
            {
                tope = nuevo;
                rear = nuevo;
            }
            else// caso 2 si no esta vacia
            {
                tope = nuevo;
            }
            L.tope = tope;
            L.rear = rear;
            return L;
        }
        public clsLista AddUltimo(int elemento)
        {
            clsLista L = new clsLista();
            Nodo nuevo = new Nodo();
            nuevo.info = elemento;
            nuevo.sig = null;
            if (Vacia())//caso1 si la lista esta vacia
            {
                tope = nuevo;
                rear = nuevo;
            }
            else// caso 2 si no esta vacia
            {
                rear.sig = nuevo;
                rear = nuevo;
            }
            L.tope = tope;
            L.rear = rear;
            return L;
        }
        public clsLista AdicionarAntes(int infoX, int info)
        {
            clsLista
            NL = new clsLista();               // se define una nueva lista con el nombre NL
            Nodo anterior=null;     // se define un nodo con nombre anterior y se asigna valor nulo
            Nodo actual = tope; // se define un nodo con nombre actual y se asigna el puntero y el valor del nodo tope  
            while(actual != null) // recorrer toda la lista desde el nodo Tope hasta el nodo Rear
            {
                if (actual.info == infoX) // Valida si el nodo leído contiene el valor "infoX"
                {
                    Nodo nuevo;
                    nuevo = new Nodo(); // Se declara un nodo con el nombre nuevo
                    nuevo.info = info; // Al nodo nuevo se le asigna el valor "info"
                    nuevo.sig = actual; // El nuevo Nodo apunta al actual Nodo
                    anterior.sig = nuevo; // El anterior Nodo apunta al Nuevo nodo
                }
                anterior = actual;// El anterior nodo toma el puntero y el valor del nodo actual
                actual = actual.sig; // el actual nodo toma el puntero y el valor del nodo sucesor del nodo actual
            }
            NL.tope = tope;// El tope del nueva lista toma los valores del nodo tope
            NL.rear = rear; // El rear del nuevo lista toma los valores del tope rear
                return  NL;// Retorna el valor y el puntero del nuevo nodo
        }
    


    public String View()
        {
            String cad = "";
            Nodo pos = tope;//puntero
            while (pos != null)//recorrer una lista
            {
                cad = cad + "[" + pos.info + "| ]->";
                pos = pos.sig;//cambiamos de nodo
            }
            return cad + "null";
        }
    }
    

}

