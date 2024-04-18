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
using System.Threading.Tasks;

namespace cApp
{
    public class clsCola2
    {
        public const int MAX = 100;
        private int tope1;
        private int tope2;
        private int rear1;
        private int rear2;
        public int cant;
        private int[] cola = new int[MAX];

        public clsCola2() //Constructor
        {
            tope1 = -1;
            tope2 = MAX;
            rear1 = -1;
            rear2 = MAX;
            cant = 0;
            for (int i = 1; i < MAX; i++)
            {
                cola[i] = 0;
            }
        }

        //-- Add(S,x)  -->S Adiciona el elemento x la cola
        public void Add(int S, int x)
        {
            if (S == 0)
            {
                if (Llena(S) == false)
                {
                    tope1++;
                    cola[tope1] = x;
                    cant++;
                }
            }
            else
            {
                if (Llena(S) == false)
                {
                    tope2--;
                    cola[tope2] = x;
                    cant++;
                }
            }
        }

        public int TopeS(int S)
        {
            if (S == 0)
            {
                if (!Vacia(S))
                    return cola[tope1];
            }
            else
            {
                if (!Vacia(S))
                    return cola[tope2];
            }
            return 0;
        }

        public int RearS(int S)
        {
            if (S == 0)
            {
                if (!Vacia(S))
                    return cola[rear1 + 1];
            }
            else
            {
                if (!Vacia(S))
                    return cola[rear2 - 1];
            }
            return 0;
        }

        //-- Delete(S) -->S Elimina el elemento tope de la cola
        public void Delete(int S)
        {
            if (S == 0)
            {
                if (Vacia(S) == false)
                    rear1++;
            }
            else
            {
                if (Vacia(S) == false)
                    rear2--;
            }
        }

        //-- Vacia(S) --> Boolean Retorna TRUE si S esta vacía de lo contrario FALSE
        public bool Vacia(int S)
        {
            bool b = false;
            if (S == 0)
            {
                if (tope1 == rear1)
                    b = true;
            }
            else
            {
                if (tope2 == rear2)
                    b = true;
            }
            return b;
        }

        //-- Llena(S) -->  Boolean Retorna TRUE si S esta llena de lo contrario FALSE
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

        //-- Mostrar
        public string Mostrar()
        {
            string s = "P[";
            for (int i = rear1 + 1; i <= tope1; i++)
            {
                s += cola[i] + ",";
            }
            for (int i = tope2; i < rear2; i++)
            {
                s += cola[i] + ",";
            }
            s += "]";
            return s;
        }
    }
}
