using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cApp
{
    public class clsPila2
    {
        public const int MAX = 50;
        private int tope1;
        private int tope2;
        public int cant;
        private int[] pila = new int[MAX];
   
        public clsPila2() //Constructor
        {
            tope1 = -1;
            tope2 = MAX;
            cant = 0;
            for (int i = 1; i < MAX; i++)
            {
                pila[i] = 0;
            }
        }

        public clsPila2(clsPila2 p)
        {
            tope1 = p.tope1;
            tope2 = p.tope2;
            cant = p.cant;
            for (int i = 1; i < MAX; i++)
            {
                pila[i] = p.pila[i];
            }
        }
        public void Add(int S, int x)
        {
            if (S == 0)
            {
                if (Llena(S) == false)
                {
                    tope1++;
                    pila[tope1] = x;
                    cant++;
                }
            }
            else
            {
                if (Llena(S) == false)
                {
                    tope2--;
                    pila[tope2] = x;
                    cant++;
                }
            }
        }
        public int TopeS(int S)
        {
            if (S == 0)
            {
                if(!Vacia(S))
                    return pila[tope1];
            }
            else
            {
                if(!Vacia(S))
                    return pila[tope2];
            }
            return 0;
        }
        public void Delete(int S)
        {
            if (S == 0)
            {
                if (Vacia(S) == false)
                    tope1--;
            }
            else
            {
                if (Vacia(S) == false)
                    tope2++;
            }
        }
        public bool Vacia(int S)
        {
            bool b = false;
            if (S == 0)
            {
                if (tope1 == -1)
                    b = true;
            }
            else
            {
                if (tope2 == MAX)
                    b = true;
            }
            return b;
        }
        public bool Llena(int S)
        {
            bool b = false;
            if (S == 0)
            {
                if (tope1 + 1 == (MAX / 2))
                    b = true;
            }
            else
            {
                if (tope2 - 1 == (MAX / 2))
                    b = true;
            }
            return b;
        }

        public string Mostrar()
        {
            string s = "P[";
            for (int i = 0; i <= tope1; i++)
            {
                s += pila[i] + ",";
            }
            for (int i = tope2; i < MAX; i++)
            {
                s += pila[i] + ",";
            }
            s += "]";
            return s;
        }
    }
}
