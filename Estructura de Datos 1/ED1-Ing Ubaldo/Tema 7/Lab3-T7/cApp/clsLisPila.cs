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
    public class clsLisPila
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
        private int n;

        public clsLisPila()
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
            nuevo.link = P;
            P = nuevo;
            n++;
        }
        public void Del()
        {
            if (P != null)
            {
                Nodo ant = P;
                P = P.link;
                ant.link = null;
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
            if (P != null)
            {
                Nodo L = P;
                Nodo ant = null;
                while (L != null)
                {
                    ant = L;
                    L = L.link;
                }
                return ant.Dato;
            }
            return -1;
        }
        public string Imprimir()
        {
            string cad = "█";
            Nodo L = P;
            while (L != null)
            {
                cad = cad + L.Dato + "█";
                L = L.link;
            }
            return cad;
        }

    }
}
