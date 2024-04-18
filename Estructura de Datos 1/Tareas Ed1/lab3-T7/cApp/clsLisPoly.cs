/*************************************************************
Institución:    Universidad Gabriel Rene Moreno
Materia:        Estructura de Datos I
Creador:        Ing. Ubaldo Perez.
Lenguaje:       C#
Herramienta:    Visual Studio 2022 - Windows Aplications
Nombre:         Andres Torrez Vaca
Registro:       220153914
*************************************************************/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsLisPoly
    {
        class Nodo
        {
            public int exp;
            public int coef;
            public Nodo link;
            public Nodo(int e, int c)
            {
                exp = e;
                coef = c;
                link = null;
            }
        }
        private Nodo P;
        private int n;

        public clsLisPoly()
        {
            P = null;
            n = 0;
        }
        public clsLisPoly(clsLisPoly R)
        {
            Nodo LR = R.P;
            while (LR != null)
            {
                int e = LR.exp;
                int c = LR.coef;
                Add(e, c);
                LR = LR.link;
            }
        }
        public bool isVacia()
        {
            return P == null;
        }
        public int Cant()
        {
            return n;
        }
        public void Add(int e, int c)
        {
            Nodo L = P;
            Nodo ant = null;
            while ((L != null) && (L.exp <= e))
            {
                if (L.exp == e)
                {
                    L.coef += c;
                    if (L.coef == 0)
                    {
                        Delete(L.exp);
                    }
                    return;
                }
                ant = L;
                L = L.link;
            }
            Nodo nuevo = new Nodo(e, c);
            if (ant == null)
            {
                nuevo.link = L;
                P = nuevo;
                n++;
            }
            else
            {
                nuevo.link = L;
                ant.link = nuevo;
                n++;
            }
        }
        public void Delete(int e)
        {
            Nodo L = P;
            Nodo ant = null;
            while ((L != null) && (L.exp <= e))
            {
                if (e == L.exp)
                {
                    if (ant == null)
                    {
                        ant = P;
                        P = P.link;
                        ant.link = null;
                    }
                    else
                    {
                        ant.link = L.link;
                        L.link = null;
                    }
                    n--;
                }
                ant = L;
                L = L.link;
            }
        }
        public void DeletePrimero()
        {
            if (P != null)
            {
                P = P.link;
                n--;
            }
        }

        public clsLisPoly Suma(clsLisPoly X, clsLisPoly Y)
        {
            clsLisPoly CX = new clsLisPoly(X);
            clsLisPoly CY = new clsLisPoly(Y);
            clsLisPoly R = new clsLisPoly();
            Nodo PX = CX.P;
            Nodo PY = CY.P;
            int e, c;
            while ((CX != null) || (CY != null))
            {
                if (CX != null)
                {
                    e = PX.exp;
                    c = PX.coef;
                    R.Add(e, c);
                    CX.DeletePrimero();
                }
                if (CY != null)
                {
                    e = PY.exp;
                    c = PY.coef;
                    R.Add(e, c);
                    CY.DeletePrimero();
                }
            }
            return R;
        }
        public string Imprimir()
        {
            string cad = "";
            Nodo L = P;
            while (L != null)
            {
                if(L.coef > 0)
                    cad = cad + " +" + L.coef + "X" + L.exp;
                else
                    cad = cad + "  " + L.coef + "X" + L.exp;
                L = L.link;
            }
            return cad;
        }

    }

}
