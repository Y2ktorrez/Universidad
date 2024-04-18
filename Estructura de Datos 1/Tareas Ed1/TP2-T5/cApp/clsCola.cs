/*************************************************************
Institución:    Universidad Gabriel Rene Moreno
Proyecto:       TAD  Cola en el lenguaje C# 
Creador:        Andres Torrez Vaca.
Registro:       220153914
Lenguaje:       C#
Aplicación:     Visual Studio 2022 - Windows Aplications
*************************************************************/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cApp
{
    public class clsCola
    {
        //--- ATRIBUTOS
        private int[] _cola;            // Arreglo para alamcenar los elementos de la cola
        public const int MAX = 50;      // Cantidad celdas del arreglo _cola
        private int _front;             // Puntero que indica la ubicacion del elemento del frente de la cola en el arreglo
        private int _rear;              // Puntero que indica la ubicacion del elemnto posterior de la cola en el arreglo

        //--- CONSTRUCTOR
        public clsCola()
        {
            _front = -1;
            _rear = -1;
            _cola = new int[MAX];
        }

        public clsCola(clsCola p)
        {
            _front = p._front;
            _rear = p._rear;
            _cola = new int[MAX];
            for (int i = p._front + 1; i <= p._rear; i++)
            {
                _cola[i] = p._cola[i];
            }
        }

        public int front
        {
            get { return _front; }
            set { _front = value; }
        }

        public int rear
        {
            get { return _rear; }
            set { _rear = value; }
        }

        public int[] cola
        {
            get { return _cola; }
            set { _cola = value; }
        }

        //--- OPERACIONES

        //--- Destruye la Cola
        public void Drop()
        {
            front = -1;
            rear = -1;
        }

        //--- Adiciona un elemento en la parte posterior de la Cola
        public void Add(int e)
        {
            if (!Llena())
            {
                rear++;
                cola[rear] = e;
            }
        }

        //--- Borra el elemento de la parte del frente de la Cola
        public void Delete()
        {
            if (!Vacia())
                front++;
        }


        //--- Valida si Cola esta Vacia
        public Boolean Vacia()
        {
            return (front == rear);

        }

        //--- Valida si la Cola esta llena
        public Boolean Llena()
        {
            return (rear + 1 == MAX);
        }

        //--- Obtiene el Primer Elelemeto de la Cola
        public int Front()
        {
            if (!Vacia())
                return cola[front + 1];
            return 0;
        }

        //--- Obtiene el Ultimo Elemento de la Cola
        public int Rear()
        {
            if (!Vacia())
                return cola[rear];
            return 0;
        }

        //--- Obtiene la cantidad de elementos de la Cola
        public int Long()
        {
            return (rear - front);
        }

        //--- Imprime la Cola en un String
        public string Imprimir()
        {
            string salida = "";
            if (!Vacia())
            {
                for (int i = _front + 1; i <= _rear; i++)
                {
                    salida += "[ " + _cola[i].ToString() + " ]";
                }
            }
            return salida;
        }

        //--- descola(p, n) que elimine los primeros n elementos en una cola p si los hay.
        public void descola(int n)
        {
            for (int i = 0; i < n; i++)
            {
                Delete();
                if (Vacia())
                    return;
            }
        }

        //--- duplica(p) que duplique una cola p de forma que cada elemento de p aparezca dos veces seguidas conservando el mismo orden relativo que en p.
        public clsCola duplica(clsCola Q)
        {
            if (Q.Vacia())
                return Q;
            clsCola P = new clsCola();
            while (!Q.Vacia())
            {
                if (P.Llena())
                    return P;
                P.Add(Q.Front());
                P.Add(Q.Front());
                Q.Delete();
            }
            return P;
        }

        //--- concatena(p,q) que genere la cola C resultante de unir los elementos de p y q desde el primero hacia el ultimo.
        public clsCola concatena(clsCola P, clsCola Q)
        {
            if (P.Vacia())
                return Q;
            if (Q.Vacia())
                return P;
            clsCola C = new clsCola(P);
            clsCola copiaQ = new clsCola(Q);
            while (!copiaQ.Vacia())
            {
                if (C.Llena())
                    return C;
                C.Add(copiaQ.Front());
                copiaQ.Delete();
            }
            return C;
        }

        //--- mezcla(p,q) que genere la cola resultante de ir uniendo  alternativamente los elementos de p y q desde sus respectivos primero hacia el ultimo
        public clsCola mezcla(clsCola P, clsCola Q)
        {
            if (P.Vacia())
                return Q;
            if (Q.Vacia())
                return P;
            clsCola copiaP = new clsCola(P);
            clsCola copiaQ = new clsCola(Q);
            clsCola C = new clsCola();
            while (!copiaP.Vacia() || !copiaQ.Vacia())
            {
                if (C.Llena())
                    return C;
                if (!copiaP.Vacia())
                {
                    C.Add(copiaP.Front());
                    copiaP.Delete();
                }
                if (!copiaQ.Vacia())
                {
                    C.Add(copiaQ.Front());
                    copiaQ.Delete();
                }
            }
            return C;
        }
    }
}
