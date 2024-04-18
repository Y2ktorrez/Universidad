using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cApp
{
    public class clsLista
    {
        class Nodo
        {
            public int info;
            public Nodo sig;
        }

        // Se define los nodos tope (primero) y rear (ultimo)
        // se puede implementar con un solo puntero pero 
        // cada vez tenemos que recorrer todo la lista para encontrar el ultimo

        private Nodo tope, rear;

        // Constructor de la Clase Lista
        public clsLista()
        {
            tope = null;
            rear = null;
        }

        // Valida si la lista esta vacia
        public bool Vacia()
        {
            if (tope == null)
                return true;
            else
                return false;
        }

        // Adiciona un Nodo al inicio de la Lista
        public void AddPrimero(int info)
        {

            Nodo nuevo;
            nuevo = new Nodo();
            nuevo.info = info;
            nuevo.sig = tope;

            if (Vacia())
            {
                tope = nuevo;
                rear = nuevo;
            }
            else
            {
                tope = nuevo;
            }
        }

        //Adiciona una Nodo al Final de la Lista
        public void AddUltimo(int info)
        {
            Nodo nuevo;
            nuevo = new Nodo();
            nuevo.info = info;
            nuevo.sig = null;
            if (Vacia())
            {
                tope = nuevo;
                rear = nuevo;
            }
            else
            {
                rear.sig = nuevo;
                rear = nuevo;
            }
        }

        // Adciona un Nodo Antes de un Nodo X dado
        public bool AddAntes(int info, int infoX)
        {
            // Buscamo el Nodo X en la Lista
            // recorremos toda la lista desde el Tope hasta el Rear

            Nodo anterior = null;       // El anterior parte en Nulo
            Nodo actual = tope;         // El Actual es igual al Primero

            while (actual != null)
            {
                if (actual.info == infoX)   // Encontro el nodo y se inserta el nuevo antes de
                {
                    Nodo nuevo;
                    nuevo = new Nodo();
                    nuevo.info = info;
                    nuevo.sig = actual;     // El nuevo Nodo apunta al actual Nodo
                    anterior.sig = nuevo;   // El anterior Nodo apunta al Nuevo nodo
                    return true;
                }
                anterior = actual;          // Anterior es igual al nodo actual
                actual = actual.sig;        // Recorremos el Siguiente Nodo
            }
            return false;
        }

        // Adciona Un Nodo Despues de un Nodo X dado
        public bool AddDespues(int info, int infoX)
        {
            // Buscamo el Nodo X en la Lista
            // recorremos toda la lista desde el Tope hasta el Rear

            Nodo siguiente = tope;      // El siguienete Nodo es igual al tope
            Nodo actual = tope;         // El nodo actual es igual al Tope
            siguiente = siguiente.sig;  // Recorremos el siguiente un nodo mas
            while (actual != null)
            {
                if (actual.info == infoX)
                {
                    Nodo nuevo;
                    nuevo = new Nodo();
                    nuevo.info = info;
                    nuevo.sig = siguiente;  // El nuevo Nodo apunta al siguiente
                    actual.sig = nuevo;     // El actual Nodo apunta al nuevo

                    return true;
                }
                actual = actual.sig;
                siguiente = siguiente.sig;
            }
            return false;
        }


        // Borrar un nodo dado X
        public void Delete(int info)
        {
            Nodo anterior, nodo;
            nodo = tope;
            anterior = null;
            Boolean existe = false;
            while (nodo != null && existe == false)     // recorremos la lista hasta encontrar el nodo
            {
                if (nodo.info == info)
                    existe = true;
                else
                {
                    anterior = nodo;
                    nodo = nodo.sig;
                }
            }


            if (existe == false)       // no se encuentra el nodo
                return;

            if (nodo == tope)           // si el nodo es el primero
            {
                tope = nodo.sig;        // se actualiza el puntero que apunta al primero
                nodo = null;
                return;
            }

            if (nodo == rear)           // si el nodo es el ultimo
            {
                anterior.sig = null;
                rear = anterior;        // se actualiza el puntero que apunta al ultimo
                nodo = null;
                return;
            }

            anterior.sig = nodo.sig;    // el nodo esta en medio de dos nodos
        }


        // Borrar el ultimo nodo de la lista
        public void DelUltimo()
        {
            Nodo anterior, nodo;
            nodo = tope;
            anterior = null;
            Boolean existe = false;
            while (nodo != null)        // recorremos la lista hasta encontrar el nodo
            {
                if (nodo == rear)
                    existe = true;
                else
                {
                    anterior = nodo;
                    nodo = nodo.sig;
                }
            }

            if (existe == false)
                return;

            anterior.sig = null;
            rear = anterior;         // se actualiza el puntero que apunta al ultimo
            nodo = null;
        }

        // Borra el Primero de la Lista
        public void DelPrimero()
        {
            Nodo nodo;
            nodo = tope;

            if (nodo == null)
                return;
            tope = nodo.sig;        // se actualiza el puntero que apunta al primero
            nodo = null;
        }

        // Buscar un nodo x dado
        public bool Buscar(int info)
        {
            Nodo reco = tope;
            while (reco != null)
            {
                if (reco.info == info)
                    return true;
                reco = reco.sig;
            }
            return false;
        }

        // Recorre la Lista
        public string View()
        {
            string cad = "";
            Nodo reco = tope;
            while (reco != null)
            {
                cad += reco.info + "->";
                reco = reco.sig;
            }
            return cad;
        }
        public void CargarDesde2Pilas(clsPila p1, clsPila p2)
        {
            bool b = true;
            while (!p1.Vacia() || !p2.Vacia())
            {
                if (b && !p1.Vacia())
                {
                    AddUltimo(p1.Tope());
                    p1.Delete();
                    b = false;
                }
                else { b = false; }

                if(!b && !p2.Vacia())
                {
                    AddUltimo(p2.Tope());
                    p2.Delete();
                    b = true;
                }
                else { b = true; }
            }
            
        }
        public void CargarDesde2Colas(clsCola Q1, clsCola Q2)
        {
            bool b = true;
            while (!Q1.Vacia() || !Q2.Vacia())
            {
                if (b && !Q1.Vacia())
                {
                    AddUltimo(Q1.Front());
                    Q1.Delete();
                    b = false;
                }
                else { b = false; }

                if (!b && !Q2.Vacia())
                {
                    AddUltimo(Q2.Front());
                    Q2.Delete();
                    b = true;
                }
                else { b = true; }
            }

        }
        public void CargarDesdePilayCola(clsPila P1, clsCola Q1)
        {
            bool b = true;
            while (!P1.Vacia() || !Q1.Vacia())
            {
                if (b && !P1.Vacia())
                {
                    AddUltimo(P1.Tope());
                    P1.Delete();
                    b = false;
                }
                else { b = false; }

                if (!b && !Q1.Vacia())
                {
                    AddUltimo(Q1.Front());
                    Q1.Delete();
                    b = true;
                }
                else { b = true; }
            }

        }
    }
}
