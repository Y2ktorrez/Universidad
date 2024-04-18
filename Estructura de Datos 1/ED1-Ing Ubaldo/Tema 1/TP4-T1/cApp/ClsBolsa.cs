
using System;
using System.Net;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class ClsBolsa
    {
        public int[] ele;
        private int N;

        public ClsBolsa()
        {
            ele = new int[50];
            N = 0;
        }

        public int N1
        {
            get { return N; }
            set { N = value; }
        }

        public void cargar(int n1, int r1)//carga los elementos a la bolsa
        {
            Random r = new Random();
            N = n1;
            for (int i = 1; i <= N; i++)
            {
                ele[i] = r.Next(r1);
            }

        }

        public override string ToString()//descarga la bolsa
        {
            string cad;
            cad = " ";
            int p = N - 1;
            for (int i = 1; i <= N; i++)
            {
                cad = cad + ele[i] + "  " + " ";
            }
            return "{ " + cad + "}";
        }

        public bool pertenece(int x)//verifica si un elemento pertenece a la bolsa
        {
            bool b = false;
            for (int i = 1; i <= N; i++)
                if (ele[i] == x)
                {
                    b = true;
                }
            return b;
        }

        public bool vacio()//verifica si la bolsa esta vacia
        {
            bool b;
            if (N == 0)
            {
                b = true;
            }
            else
            {
                b = false;
            }
            return b;
        }


        private void intercambio(int a, int b)
        {
            int aux;
            aux = ele[a];
            ele[a] = ele[b];
            ele[b] = aux;

        }

        public void ordenar()//ordena la bolsa
        {
            for (int i = 1; i <= N - 1; i++)
                for (int j = i + 1; j <= N; j++)
                {
                    if (ele[i] > ele[j])
                    {
                        intercambio(i, j);
                    }
                }
        }

        public int frecuencia(int nro)//devuelve la frecuencia de un numero de la bolsa
        {
            int fr;
            fr = 0;
            for (int i = 1; i <= N; i++)
                if (ele[i] == nro)
                {
                    fr = fr + 1;
                }
            return fr;
        }


    }
}
