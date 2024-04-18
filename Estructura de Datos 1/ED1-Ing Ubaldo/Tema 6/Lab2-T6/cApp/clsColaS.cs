using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsColaS
    {
        public const int MAX = 60;        
        public const int n = 3;                
        public const int t = MAX / n;          
        private int[] _Colas;            
        private int[] _B;             
        private int[] _F;          
        private int[] _R;             

        public clsColaS()
        {
            _Colas = new int[MAX];
            _B = new int[n + 1];
            _F = new int[n];
            _R = new int[n];
            for (int i = 0; i < n; i++)
            {
                _B[i] = (t * i) - 1;
                _F[i] = (t * i) - 1;
                _R[i] = (t * i) - 1;
            }
            _B[n] = MAX - 1;
        }
        public clsColaS(clsColaS p)
        {
            _Colas = new int[MAX];
            _B = new int[n + 1];
            _F = new int[n];
            _F = new int[n];
            for (int i = 0; i < MAX; i++)
            {
                _Colas[i] = p._Colas[i];
            }
            for (int i = 0; i < n + 1; i++)
            {
                _B[i] = p._B[i];
            }
            for (int i = 0; i < n; i++)
            {
                _F[i] = p._F[i];
                _R[i] = p._R[i];
            }
        }
        public int[] Colas
        {
            get { return _Colas; }
            set { _Colas = value; }
        }
        public void Drop(int i)
        {
            _B[i] = (t * (i )) - 1;
            _F[i] = (t * (i )) - 1;
            _R[i] = (t * (i )) - 1;
            if (i == n - 1)
                _B[i + 1] = MAX - 1;
        }
        public void Add(int i, int e)
        {          
            if (Llena(i) != true)
            {
               _R[i]++;
               _Colas[_R[i]] = e;
            }         
        }
        public void Delete(int i)
        {
            if (Vacia(i) != true)
                _F[i]++;
        }
        public Boolean Vacia(int i){ return (_R[i] == _F[i]);}
        public Boolean Llena(int i){ return (_R[i] == _B[i + 1]) ;}
        public int Frente(int i)
        {
            if (Vacia(i) != true)
                return _Colas[_F[i] + 1];
            return -1;
        }
        public int Atras(int i)
        {
            if (Vacia(i) != true)
                return _Colas[_R[i]];
            return -1;
        }
        public int Long(int i){ return (_R[i] - _F[i]);}
        public string Imprimir(int i)
        {
            string salida = "";
            int k = _F[i] + 1; 
            int l = _R[i];
            while (k <= l)
            {
                salida += "[ " + _Colas[k].ToString() + " ]";
                k++;
            }
            return salida;
        }
        public string PrintB()
        {
            string salida = "";

            for (int k = 0; k < n + 1; k++)
            {
                salida += "[ " + _B[k].ToString() + " ]";
            }
            return salida;
        }
        public string PrintF()
        {
            string salida = "";

            for (int k = 0; k < n; k++)
            {
                salida += "[ " + _F[k].ToString() + " ]";
            }
            return salida;
        }
        public string PrintR()
        {
            string salida = "";

            for (int k = 0; k < n; k++)
            {
                salida += "[ " + _R[k].ToString() + " ]";
            }
            return salida;
        }
    }
}
