/*************************************************************
Institución:    Universidad Gabriel Rene Moreno
Proyecto:       TAD Natu (Numeros Naturales) 
Descripción:    Método para numeros Naturales.
Creador:        Ing. Ubaldo Perez.
Lenguaje:       C#
Aplicación:     Visual Studio 2010 - Windows Aplications
*************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsNatu
    {

    public int Cero()
     {
          return 0;
     }
    public bool EsCero(int x)
        {
            if (x==0) 
            {
                return true;
            }
           return false;
        }
    public int Sucesor(int x)
        {
            x = x + 1;
            return x;
        }
    public int Predecesor(int x)
     {
         if (EsCero(x) == true)
             return x;

         if (EsCero(x) == false)
         {
             x = x - 1;
         }
         return x;
     }
    public bool Igual(int x, int y)
     {
         if (EsCero(x) == true & EsCero(y) == false)
             return false;

         if (EsCero(x) == false & EsCero(y) == true)
             return false;

         if (x == y)
             return true;
         return false;
     }
    public int Suma(int a,int b)
        {
            if (EsCero(a) == true & EsCero(b) == false)
                return b;
            if (EsCero(a) == false & EsCero(b) == true)
                return a;
            int s = 0;
            s = a + b;
            return s;
        }

       
    }

}
