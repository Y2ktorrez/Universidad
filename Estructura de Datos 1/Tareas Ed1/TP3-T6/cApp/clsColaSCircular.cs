using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cApp
{
    internal class clsColaSCircular
    {
        public const int MAX = 18;
        public const int n = 3;
        public const int t = MAX / n;
        private int[] _Colas;
        private int[] _B;
        private int[] _F;
        private int[] _R;
        private int[] _C;

        public clsColaSCircular()
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

        public int Long(int i)
        {
            return _C[i];
        }

        public int Frente(int i)
        {
            if (Vacia(i) != true)
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
                if (_R[i] == _B[i + 1])
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
                if (_F[i] == _B[i + 1])
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
    }
}
