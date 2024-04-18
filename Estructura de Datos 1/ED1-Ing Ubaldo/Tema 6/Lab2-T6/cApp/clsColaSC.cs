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

namespace cApp
{
    public class clsColaSC
    {
        public const int MAX = 36;
        public const int n = 3;
        public const int t = MAX / n;
        private int[] _Colas;
        private int[] _B;
        private int[] _F;
        private int[] _R;
        private int[] _C;

        public clsColaSC()
        {
            _Colas = new int[MAX];
            _B = new int[n + 1];
            _F = new int[n];
            _R = new int[n];
            _C = new int[n];
            for (int i = 0; i < n; i++)
            {
                _B[i] = (t * i) - 1;
                _F[i] = (t * i) - 1;
                _R[i] = (t * i) - 1;
                _C[i] = 0;
            }
            _B[n] = MAX - 1;
        }
        public clsColaSC(clsColaSC P)
        {
            _Colas = new int[MAX];
            _B = new int[n + 1];
            _F = new int[n];
            _R = new int[n];
            _C = new int[n];
            for (int i = 0; i < n; i++)
            {
                _B[i] = P._B[i];
                _F[i] = P._F[i];
                _R[i] = P._R[i];
                _C[i] = P._C[i];
            }
            _B[n] = MAX - 1;
            for(int i = 0;i < MAX; i++)
            {
                _Colas[i] = P._Colas[i];
            }
        }

        public int[] Colas
        {
            get { return _Colas; }
            set { _Colas = value; }
        }
        public void Drop(int i)
        {
            _B[i] = (t * (i)) - 1;
            _F[i] = (t * (i)) - 1;
            _R[i] = (t * (i)) - 1;
            _C[i] = 0;
            if (i == n - 1)
                _B[i + 1] = MAX - 1;
        }
        public bool Llena(int i)
        {
            return _C[i] == (_B[i + 1] - _B[i]);
        }
        public bool Vacia(int i)
        {
            return _C[i] == 0;
        }
        public int Frente(int i)
        {
            if(Vacia(i) != true)
            {
                if (_F[i] == _B[i + 1])
                    return _Colas[_B[i] + 1];
                else
                    return _Colas[_F[i] + 1];
            } 
            return -1;
        }
        public int Atras(int i)
        {
            if (Vacia(i) != true)
                return _Colas[_R[i]];
            return -1;
        }
        public void Add(int i, int e)
        {
            if (Llena(i) != true)
            {
                if(_R[i] == _B[i + 1])
                {
                    _R[i] = _B[i] + 1; 
                    _Colas[_R[i]] = e;
                    _C[i]++;
                }
                else
                {
                    _R[i]++;
                    _Colas[_R[i]] = e;
                    _C[i]++;
                }
            }
        }
        public void Delete(int i)
        {
            if (Vacia(i) != true)
            {
                if(_F[i] == _B[i + 1])
                {
                    _F[i] = _B[i] + 1;
                    _C[i]--;
                }
                else
                {
                    _F[i]++;
                    _C[i]--;
                }
            }
        }
        public string Imprimir3(int i)
        {
            string salida = "";
            if (Vacia(i) != true)
            {
                int c = 1;
                int ini = _F[i];
                while (c <= _C[i])
                {
                    if (ini == _B[i + 1])
                    {
                        ini = _B[i] + 1;
                        salida += "[ " + _Colas[ini].ToString() + " ]";
                        c++;
                    }
                    else
                    {
                        ini++;
                        salida += "[ " + _Colas[ini].ToString() + " ]";
                        c++;
                    }
                }

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
        public string PrintC()
        {
            string salida = "";

            for (int k = 0; k < n; k++)
            {
                salida += "[ " + _C[k].ToString() + " ]";
            }
            return salida;
        }
        /*-----------------------------Lab---------------------------------*/

        //long(Qi) --> N  Calcula el numero de elementos de una  cola circular Qi.
        public int Long(int i)
        {
            return _C[i];
        }

        //descola(Qi, n) -->Qi  Elimina los primeros n elementos en una cola circular Qi si los hay.
        public void descola(int i,int Nelemento)
        {
            for(int j = 1;j <= Nelemento; j++)
            {
                Delete(i);
            }
        }

        //inversa(Qi)  -->C   Genera la inversa de una cola circular Qi.
        public void inversa(int i)
        {
            int f = _F[i];
            int r = _R[i];
            int aux;
            int cont = 1;
            int L = (Long(i) / 2);
            while (cont <= L)
            {
                if (f + 1 == _B[i + 1])
                    f = _B[i] + 1;
                else
                    f++;
                aux = _Colas[f];
                _Colas[f] = _Colas[r];
                _Colas[r] = aux;
                cont++;
                if (r - 1 == _B[i])
                    r = _B[i + 1];
                else
                    r--;
            }
        }

        //duplica(Qi) --> C Duplica una cola circular Qi de forma que cada elemento de Qi aparezca dos veces seguidas conservando el mismo orden relativo que en Qi.
        public void duplica(int i)
        {
            clsColaSC CS = new clsColaSC();
            int f = _F[i];
            while (!Vacia(i))
            {
                int x = Frente(i);
                CS.Add(i,x);
                Delete(i);
            }
            _R[i] = f;
            _F[i] = f;          
            while (!CS.Vacia(i))
            {
                int x = CS.Frente(i);
                Add(i, x);
                Add(i, x);
                CS.Delete(i);
            }
        }

        //concatena(Pi, Qi) -->C   Genera la cola circular C resultante de unir los elementos de Pi, y Qi desde el primero hacia el último.
        public clsColaC concatena(clsColaSC SC, int Pi,int Qi)
        {
            clsColaSC P = new clsColaSC(SC);
            clsColaC C = new clsColaC();
            while (!P.Vacia(Pi))
            {
                int x = P.Frente(Pi);
                C.Add(x);
                P.Delete(Pi);
            }
            while (!P.Vacia(Qi))
            {
                int x = P.Frente(Qi);
                C.Add(x);
                P.Delete(Qi);
            }
            return C;
        }

        //mezcla(Pj, Qi) -->C Genera la cola circular C resultante de ir uniendo  alternativamente los elementos de Pi, y Qi desde el primero elemento hacia el ultimo
        public clsColaC mezcla(clsColaSC SC, int Pi, int Qi)
        {
            clsColaSC P = new clsColaSC(SC);
            clsColaC C = new clsColaC();
            int x;
            while (!P.Vacia(Pi) || !P.Vacia(Qi))
            {
                if (!P.Vacia(Pi))
                {
                    x = P.Frente(Pi);
                    P.Delete(Pi);
                    C.Add(x);
                }
                if (!P.Vacia(Qi))
                {
                    x = P.Frente(Qi);
                    P.Delete(Qi);
                    C.Add(x);
                }
            }
            return C;
        }
    }
}
