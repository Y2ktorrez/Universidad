using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsCadena
    {
        string c;
        public clsCadena() //constructor
        {
            c = "";
        }

        public void cargar(string cad) 
        {
            c = cad;
        }

        public string mostrar()
        {
            return c;
        }

        public string set
        {
            set { c = value; }
        }

        public string Getcadena
        {
            get { return c; }
        }

        public int Longcadena()
        {
            return c.Length;
        }

        public bool Verifmayus()
        {
            int i;
            i = 0;
            bool b;
            b = false;
            while ((i < c.Length) && (b == false))
            {
                if ((c[i] >= 'A') && (c[i] <= 'Z'))
                {
                    b = true;
                }
                else
                {
                    b = false;
                }
                i = i + 1;
            }
            return b;
        }

        public string RetornaMayu()
        {
            int i;
            string n = "";
            i = 0;
            while (i < c.Length)
            {
                if ((c[i] >= 'A') && (c[i] <= 'Z'))
                {
                    n = n + c[i];
                }
                i = i + 1;
            }
            return n;
        }

        public string invertir()
        {
            string cad = "";
            for (int i = 0; i < c.Length; i++)
            {
                cad = c[i] + cad;
            }
            return cad;
        }

        public bool verfi_palim()
        {
            return c == invertir();
        }

        public bool verifIg(clsCadena a, clsCadena d)
        {
            return a.Getcadena == d.Getcadena;
        }
    }
}
