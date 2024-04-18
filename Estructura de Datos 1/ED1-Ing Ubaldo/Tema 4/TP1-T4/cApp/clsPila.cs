
//Implementacion del TAD Pila utilizando Arreglos.


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp {
    public class clsPila {

        //ATRIBUTOS
        public const int MAX = 10;
        private int _top;
        private int[] _pila;

        public clsPila( ) { //CONSTRUCTOR
            _top = -1;
            _pila = new int[MAX];
        }

        //METODOS
        public clsPila( clsPila p ) {
            _top = p._top;
            _pila = new int[MAX];
            for ( int i = 0 ; i < p._top ; i++ ) {
                _pila[i] = p._pila[i];
            }
        }

        public int Top {
            get { return _top; }
            set { _top = value; }
        }
        public int[] Pila {
            get { return _pila; }
            set { _pila = value; }
        }

        // Destruye la Pila
        public void Drop()
        {
            _top = -1;
        }

        // Valida si la Pila esta vacia
        public Boolean Vacia()
        {
            if (_top == -1)
            {
                return true;
            }
            return false;
        }

        // Obtiene el elemento de la Cima de la Pila 
        public int Tope()
        {
            if (Vacia() != true)
                return _pila[_top];
            return 0;
        }

        // Adiciona un elemento en la cima de la Pila
        public clsPila Add(clsPila P, int e){
            
                if (Llena() != true)
                {
                    P._top++;
                    P._pila[_top] = e;
                }
            return P;
        }

        // Elimina el elemento de la cima de la Pila
        public clsPila Delete(clsPila P)
        {
            if (!P.Vacia())
                P._top--;
            return P;
        }

               // Valida si la Pila esta llena
        public Boolean Llena()
        {
            if (_top+1 == MAX)
            {
                return true;
            }
            return false;
        }

       
        // Obtiene la cantidad de elementos en la Pila 
        public int Long()
        {
            return _top+1;
        }

        // Imprime los elementos de la Pila 
        public string Imprimir( ) {
            string salida = "";
            for ( int i = 0 ; i <= _top ; i++ ) {
                salida += "[ " + _pila[i].ToString( ) + " ]";
            }
            return salida;
        }
        public int Rear(clsPila P){ //// retorna el elemento del fondo de la pila
            if (!P.Vacia())
                return P._pila[0];
            return 0;
        }
        public double Avg(clsPila P) { //// retorna el promedio de los elementos de la pila
            if (!P.Vacia())
            {
                double sum = 0;
                double promedio;
                for (int i = 0; i <= P._top; i++)
                {
                    sum = P._pila[i] + sum;
                }
                promedio = sum / P.Long();
                return promedio;
            }
            return 0;
        }
        public int Suma(clsPila P) { ////retorna la suma de los 
            if (!P.Vacia())
            {
                int sum = 0;
                for (int i = 0; i <= P._top; i++)
                {
                    sum = P._pila[i] + sum;
                }
                return sum;
            }
            return 0;
        }
        public clsPila Ivertir(clsPila P)
        {
            clsPila Q = new clsPila();

            for (int i = P.Long(); i > 0; i--)
            {
                int e = P._pila[i-1];
                Q.Add(Q,e);
            }
            return Q;
        }




    }

}
