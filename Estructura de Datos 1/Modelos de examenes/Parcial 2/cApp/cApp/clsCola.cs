using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cApp
{
    public class clsCola
    {
        public const int MAX = 10;
        private int _front;
        private int _rear;
        private int[] _cola;

        //CONSTRUCTOR
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
            for (int i = 0; i < p._front; i++)
            {
                _cola[i] = p._cola[i];
            }
        }

        public int Top
        {
            get { return _front; }
            set { _front = value; }
        }
        public int[] Cola
        {
            get { return _cola; }
            set { _cola = value; }
        }

        //METODOS
        public void Drop()
        {
            _front = -1;
            _rear = -1;
        }

        // Adiciona un elemento en la parte posterior de la Cola
        public void Add(int e)
        {
            if (Llena() != true)
            {
                _rear++;
                _cola[_rear] = e;
            }
        }

        //Borra el elemento de la parte del frente de la Cola
        public void Delete()
        {
            if (Vacia() != true)
                _front++;
        }

        // Valida si Cola esta Vacia
        public Boolean Vacia()
        {
            if (_front == _rear)
            {
                return true;
            }
            return false;
        }

        // Valida si la Cola esta llena
        public Boolean Llena()
        {
            if (_rear + 1 == MAX)
                return true;

            return false;
        }


        // Obtiene el Primer Elelemeto de la Cola
        public int Front()
        {
            if (Vacia() != true)
                return _cola[_front + 1];
            return 0;
        }


        // Obtiene el Ultimo Elemento de la Cola
        public int Rear()
        {
            if (Vacia() != true)
                return _cola[_rear];
            return 0;
        }

        // Obtiene la cantidad de elementos de la Cola
        public int Long()
        {
            return (_rear - _front);
        }

        // Imprime la Cola en un String
        public string Imprimir()
        {
            string salida = "";
            if (Vacia() != true)
            {
                for (int i = _front + 1; i <= _rear; i++)
                {
                    salida += "[ " + _cola[i].ToString() + " ]";
                }
            }
            return salida;
        }
    }
}
