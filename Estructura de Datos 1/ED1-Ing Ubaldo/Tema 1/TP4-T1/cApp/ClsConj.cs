using System;
using System.Net;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class ClsConj
    {
        const int MAX = 100;
        int[] elem;
        string[] elemc;
        int N;

       
        public ClsConj()
        {
            elem = new int[MAX];
            elemc = new string[15];
            N = 0;
        }

        public int N1
        {
            get { return N; }
            set { N = value; }
        }

        public void cargar(int n1)//cargar el conjunto
        {
            if (!pertenece(n1))
            {
                N++;
                elem[N] = n1;
            }
               
        }

        public void cargarCad(string a) //carga cadena de caracteres
        {      
            N++;
            elemc[N] = a;
        }

        public override string ToString()//descarga el conjunto
        {
            String cad;
            cad = "";
            for (int i = 1; i <= N; i++)
            {
                cad = cad + " " + elem[i] + " ";
            }
            return cad;
        }

        public string Mostrar()//descarga el conjunto de cadenas
        {
            string cad;
            cad = "";
            for (int i = 1; i <= N; i++)
            {
                cad = cad + " " + elemc[i] + " ";
            }
            return cad;
        }

        public bool Conjvacio()//verifica si el conjunto esta vacio
        {
            bool b = false;
            if (N == 0)
            {
                b = true;
            }
            return b;
        }

        public bool pertenece(int x)//verifica si el elemento esta en el conjunto
        {
            bool b = false;
            int i = 1;
            while (b == false && i <= N)
            {
                if (elem[i] == x)
                    b = true;
                else
                    i++;
            }
            return b;
        }

        private void inter(int a, int b)
        {
            int aux;
            aux = elem[a];
            elem[a] = elem[b];
            elem[b] = aux;

        }

        public void ordenar()//ordena el conjunto
        {
            for (int i = 1; i <= N - 1; i++)
            {
                for (int j = i + 1; j <= N; j++)
                {
                    if (elem[i] < elem[j])
                    {
                        inter(i, j);
                    }
                }
            }
        }

        public void elimna( ClsConj a,int pos)//elimina la posicion de un conjunto
        {
            if (a.Conjvacio() == false)
            {
                for (int i = pos; i <= a.N1 - 1; i++)
                {
                    a.elem[i] = a.elem[i + 1];
                }
                a.N1--;
            }       
        }
    }
}
