/*************************************************************
Institución:    Universidad Gabriel Rene Moreno
Proyecto:       TAD Rectángulo en C# 
Descripción:    Implementar el TAD Rectángulo en C# en un clase Rectangulo.cs 
                Implementar la interfaz para usar las operaciones del TAD Rectangulo (wApp)
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
    public class clsRect
    {
        //--- Atributos 
        public const int Max = 100;
        public int F = 0;
        public int C = 0;
        public int[,] Sparce = new int[Max, 30];
        public int cant = 0;

        //--- Constructores

        public clsRect()
        {
            F = 0;
            C = 0;
            cant = 0;
            for (int i = 0; i < Max; i++)
            {
                Sparce[i, 0] = 0;
                Sparce[i, 1] = 0;
                Sparce[i, 2] = 0;
            }
        }

        public clsRect(clsRect m)
        {
            F = 0;
            C = 0;
            cant = m.cant;
            for (int i = 0; i < Max; i++)
            {
                Sparce[i, 0] = m.Sparce[i, 0];
                Sparce[i, 1] = m.Sparce[i, 1];
                Sparce[i, 2] = m.Sparce[i, 2];
            }
        }

        public void CargarSparce(int[,] m)
        {
            F = m.GetLength(0);
            C = m.GetLength(1);
            Sparce[0, 0] = F;
            Sparce[0, 1] = C;
            cant = 1;
            for (int i = 1; i < F; i++)
            {
                for (int j = 1; j < C; j++)
                {
                    if (m[i, j] != 0)
                    {
                        Sparce[cant, 0] = i;
                        Sparce[cant, 1] = j;
                        Sparce[cant, 2] = m[i, j];
                        cant++;
                    }
                }
            }
            /*cant--;*/
            Sparce[0, 2] = cant;
        }

        public String MostrarM(int[,] m)
        {
            F = m.GetLength(0);
            String S = "";
            for (int i = 0; i < F; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    S = S + "[" + m[i, j] + "]";
                }
                S = S + "\n";
                /*S += "\n";*/
            }
            return S;
        }

        public String Mostrar()
        {
            String S = "";
            for (int i = 0; i < cant; i++)
            {
                S = S + "[" + Sparce[i, 0] + "," + Sparce[i, 1] + "]";
                S = S + "\n";
            }
            return S;
        }

        public int valor(int x, int y)
        {
            int a = 0;
            for (int i = 1; i < cant; i++)
            {
                if ((Sparce[i, 0] == x) && (Sparce[i, 1] == y))
                {
                    a = Sparce[1, 2];
                }
            }
            return a;
        }

        public String MostrarF()
        {
            F = Sparce[0, 0];
            C = Sparce[0, 1];
            String m = "";
            if (cant == 0)
            {
                return m;
            }
            else
            {
                for (int i = 0; i < F; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        int s = valor(i, j);
                        m = m + "[" + s + "]";
                    }
                    m = m + "\n";
                }
            }
            return m;
        }

        public void MovIzq()
        {
            if (Sparce[1, 1] > 0)
            {
                for (int i = 1; i < cant; i++)
                {
                    Sparce[i, 1]--;
                    /*Sparce[i,1] = Sparce[i,1] - 1;*/
                }
            }
        }

        public void MovDere()
        {
            if (Sparce[cant - 1, 1] < Sparce[0, 1] - 1)
            {
                for (int i = 1; i < cant; i++)
                {
                    Sparce[i, 1]++;
                    /*Sparce[i,1] = Sparce[i,1] + 1;*/
                }
            }
        }

        public void MovArriba()
        {
            if (Sparce[1, 0] > 0)
            {
                for (int i = 1; i < cant; i++)
                {
                    Sparce[i, 0]--;
                    /*Sparce[i,0] = Sparce[i,0] - 1;*/
                }
            }
        }

        public void MovAbajo()
        {
            if (Sparce[cant - 1, 0] < Sparce[0, 0] - 1)
            {
                for (int i = 1; i < cant; i++)
                {
                    Sparce[i, 0]++;
                    /*Sparce[i,0] = Sparce[i,0] + 1;*/
                }
            }
        }
    }
}
