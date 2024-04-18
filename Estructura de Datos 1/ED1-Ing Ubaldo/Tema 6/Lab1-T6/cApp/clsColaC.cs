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
            _front = -1;
            _rear = p._cant - 1;
            _cant = p._cant;
            _cola = new int[MAX];
            int f = p._front;
            for (int i = 0; i < p._cant; i++)
            {
                if((f + 1 ) == MAX)
                {
                    f = 0;
                    _cola[i] = p._cola[f];
                }
                else
                {
                    f++;
                    _cola[i] = p._cola[f];
                }
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
        private void DelRear()
        {
            if(Vacia() != true)
            {
                if(_rear != 0)
                {
                    _rear--;
                    _cant--;
                }
                else
                {
                    _rear = MAX - 1;
                    _cant--;
                }
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
        /*--------------------  Lab1-T6  ----------------*/

        //long(Q) --> N        //Calcul el numero de elementos de una cola circular.
        public int Long()
        {
            return (_cant);
        }
        //descola(Q, n) -->Q   //Elimina los primeros n elementos en una cola circular p si los hay.
        public void descola(int n)
        {
            if (!Vacia())
            {
                for(int i = 1; i <= n; i++)
                {
                    Delete();
                }
            }
        }
        //inversa(Q)  -->      //Genera la inversa de una cola circular Q.
        public clsColaC inversa(clsColaC Q)
        {
            clsColaC P = new clsColaC();
            while (!Q.Vacia())
            {
                int x = Q.Atras();
                Q.DelRear();
                P.Add(x);
            }
            return P;
        }
        //duplica(Q)  --> Q //Duplica una cola circular Q de forma que cada elemento de Q aparezca dos veces seguidas conservando el mismo orden relativo que en Q.
        public clsColaC duplica(clsColaC Q)
        {
            clsColaC P = new clsColaC();
            while (!Q.Vacia())
            {
                int x = Q.Frente();
                Q.Delete();
                P.Add(x);
                P.Add(x);
            }
            return P;
        }
        //concatena(P, Q) -->C   //Genera la cola circular  C resultante de unir los elementos de P y Q desde el primero hacia el último.
        public clsColaC concatena(clsColaC P, clsColaC Q)
        {
            clsColaC C = new clsColaC(P);
            clsColaC DQ = new clsColaC(Q);
            while (!DQ.Vacia())
            {
                int x = DQ.Frente();
                DQ.Delete();
                C.Add(x);
            }
            return C;
        }
        //mezcla(P,Q) -->C          //Genera la cola circular C resultante de ir uniendo  alternativamente los elementos de P y Q desde el primero elemento hacia el ultimo
        public clsColaC mezcla(clsColaC P,clsColaC Q)
        {
            clsColaC DP = new clsColaC(P);
            clsColaC DQ = new clsColaC(Q);
            clsColaC C = new clsColaC();
            int x;
            while(!DP.Vacia() || !DQ.Vacia())
            {
                if (!DP.Vacia())
                {
                    x = DP.Frente();
                    DP.Delete();
                    C.Add(x);
                }
                if (!DQ.Vacia())
                {
                    x = DQ.Frente();
                    DQ.Delete();
                    C.Add(x);
                }
            }
            return C;
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
