/*
    Registro: 218056419 
      Nombre: Luis Fernando Vargas Estrada
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsLisCola
    {
        class Nodo
        {
            public int Dato;
            public Nodo link;
            public Nodo(int x)
            {
                Dato = x;
                link = null;
            }
        }
        private Nodo P;
        private Nodo U;
        private int n;

        public clsLisCola()
        {
            P = null;
            n = 0;
        }
        public bool isVacia()
        {
            return P == null;
        }
        public void Add(int x)
        {
            Nodo nuevo = new Nodo(x);
            if (P == null)
            {
                U = nuevo;
                P = nuevo;
            }
            else
            {
                U.link = nuevo;
                U = nuevo;
            }
            n++;
        }
        public void Del()
        {
            if (P != null)
            {
                if (n == 1)
                {
                    U = P = null;
                }
                else
                {
                    Nodo ant = P;
                    P = P.link;
                    ant.link = null;
                }
                n--;
            }
        }
        public int Cant()
        {
            return n;
        }
        public int PrimerEle()
        {
            if (P != null)
                return P.Dato;
            return -1;
        }
        public int UltimoEle()
        {
            if (U != null)
                return U.Dato;
            return -1;
        }
        public string Imprimir()
        {
            string cad = "";
            Nodo L = P;
            while (L != null)
            {
                cad = cad + "_" + L.Dato;
                L = L.link;
            }
            return cad;
        }

    }
}
