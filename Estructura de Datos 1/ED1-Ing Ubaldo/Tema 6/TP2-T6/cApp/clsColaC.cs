using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{

    public class clsColaC
    {
        public const int MAX = 10;  
        private int[] _cola;         
        private int _front;      
        private int _rear;        
        private int _cant;              

        public clsColaC()
        {
            _front = -1;
            _rear = -1;
            _cant = 0;
            _cola = new int[MAX];
        }
        public clsColaC(clsColaC p)
        {
            _front = p._front;
            _rear = p._rear;
            _cant = p._cant;
            _cola = new int[MAX];
            for (int i = 0; i < p._front; i++)
            {
                _cola[i] = p._cola[i];
            }
        }
        public int Front
        {
            get { return _front; }
            set { _front = value; }
        }
        public int Rear
        {
            get { return _rear; }
            set { _rear = value; }
        }
        public int Cant
        {
            get { return _cant; }
            set { _cant = value; }
        }
        public int[] Cola
        {
            get { return _cola; }
            set { _cola = value; }
        }
        public void Drop()
        {
            _front = -1;
            _rear = -1;
            _cant = 0;
        }
        public void Add(int e)
        {
            if (Llena() != true)
            {
                _rear = ((_rear + 1) % MAX);
                _cant++;
                _cola[_rear] = e;
            }
        }
        public void Delete()
        {
            if (Vacia() != true)
            {
                _front = ((_front + 1) % MAX);
                _cant--;
            }
        }
        public bool Vacia()
        {
            return (_cant == 0);
        }
        public bool Llena()
        {
            return (_cant == MAX);
        }
        public int CeldasLibres()
        {
            return (MAX - _cant);
        }
        public int Frente()
        {
            if (Vacia() != true)
            {
                if (_front + 1 == MAX)
                    return _cola[0];
                return _cola[_front + 1];
            }
            return -1;
        }
        public int Atras()
        {
            if (Vacia() != true)
                return _cola[_rear];
            return -1;
        }
        public int Long()
        {
            return (_cant);
        }
        public string Imprimir()
        {
            string salida = "";
            if (Vacia() != true)
            {
                if (_front + 1 == MAX)
                {
                    int i = 0;
                    int c = 1;
                    while (c <= _cant)
                    {
                        salida += "[ " + _cola[i].ToString() + " ]";
                        i++;
                        i = (i % MAX);
                        c++;
                    }
                }
                else
                {
                    int i = _front + 1;
                    int c = 1;
                    while (c <= _cant)
                    {
                        salida += "[ " + _cola[i].ToString() + " ]";
                        i++;
                        i = (i % MAX);
                        c++;
                    }
                }
            }
            return salida;
        }        
    }
}
