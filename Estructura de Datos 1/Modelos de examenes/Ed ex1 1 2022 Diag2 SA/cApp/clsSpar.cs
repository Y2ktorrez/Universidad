using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsSpar
    {
        /*ZTRIBUTOS*/

        const int Max = 85;                         // Maxima Cantidad de elementos en el arreglo PS alternativo
        public int[,] PS = new int[Max, 3];         // Arreglo donde se almacena los datos mayores a cero de las Matris Z original
        public int Cant = 0;                        // Cantidad de celdas llenas en el arreglo PS
        public int n = 0;                           // Cantidad de filas de la Matriz Z original
        public int m = 0;                           // Cantidad de columnas de la Matriz Z original


        /*CONSTRUCTORES*/
        public clsSpar()
        {
            Cant = 0; n = 0; m = 0;
            int i = 0;
            while (i < Max)
            {
                PS[i, 0] = 0; PS[i, 1] = 0; PS[i, 2] = 0;
                i++;
            }
        }

        public clsSpar(clsSpar x)
        {
            Cant = x.Cant; n = x.n; m = x.m;
            int i = 0;
            while (i < Max)
            {
                PS[i, 0] = x.PS[i, 0]; PS[i, 1] = x.PS[i, 1]; PS[i, 2] = x.PS[i, 2];
                i++;
            }
        }

        // Limpiar el Arreglo PS
        public void ClearArreglo()
        {
            int i = 0; Cant = 0;
            while (i < Max)
            {
                PS[i, 0] = 0; PS[i, 1] = 0; PS[i, 2] = 0;
                i++;
            }
        }

        // Funcion para mostrarla Matriz esparcida Z
        public string MostraArreglo(int[,] Z)
        {
            int i, j = 0;
            string cad = "";
            for (i = 0; i < n; i++)
            {
                cad += "\n";
                for (j = 0; j < m; j++)
                    cad += "[" + Z[i, j] + "]";
            }
            return cad;
        }


        // Funcion para mostrar arreglo PS(t,3)
        public string MostrarVector()
        {
            string s = "";

            for (int i = 0; i < Cant; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    s += "[" + PS[i, j] + "]";
                }
                s += "\n";
            }
            return s;
        }



        // Aqui escriba el codigo de la funciones
        //Sparce(Z) --> PS          //Funcion para pasar los datos de la matriz Z esparcida a un arreglo PS(t,3)
        public clsSpar CopyZtoPS(int[,] Z)
        {
            clsSpar P = new clsSpar();
            P.n = Z.GetLength(0);
            P.m = Z.GetLength(1);

            P.PS[0, 0] = n;
            P.PS[0, 1] = m;
            P.Cant = 1;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (Z[i, j] > 0) //Aqui se pone que es mayor a 0
                    //Ahora si pide distinto de 0, seria ( != )
                    {
                        P.PS[P.Cant, 0] = j;//Columna
                        P.PS[P.Cant, 1] = i;//fila
                        P.PS[P.Cant, 2] = Z[i, j];
                        P.Cant++;
                    }
                }
            }
            P.PS[0, 2] = P.Cant - 1;
            return P;
        }


        //DiagonalSecundaria(PS) --> S       //Funcion para pasar obtener en una pila S los datos de la diagonal secundaria de Z a partir de PS

        public clsPila DiagonalSegunda(int[,] PS)//Hacia arriba
        {
            clsPila S = new clsPila();
            int cantidad = PS[0, 2];
            int columna = PS[0, 0];

            for (int i = cantidad; i >= 1; i--)
            {
                if (PS[i, 0] + PS[i, 1] == (columna - 1))
                {
                    S.Add(PS[i, 2]);
                }
            }

            return S;
        }

        public clsPila DiagonalSegunda2(int[,] PS) //Hacia abajo
        {
            clsPila S = new clsPila();
            int cantidad = PS[0, 2];
            int columna = PS[0, 0];

            for (int i = 1; i <= cantidad; i++)
            {
                if (PS[i, 0] + PS[i, 1] == (columna - 1))
                {
                    S.Add(PS[i, 2]);
                }
            }

            return S;
        }

        public clsPila DiagonalPrimera(int[,] PS)
        {
            clsPila S = new clsPila();
            int cantidad = PS[0, 2];
            int columna = PS[0, 0];

            for (int i = cantidad; i >= 1; i--)
            {
                if (PS[i, 0] == PS[i, 1])
                {
                    S.Add(PS[i, 2]);
                }
            }
            return S;
        }

        public clsPila DiagonalPrimera2(int[,] PS)
        {
            clsPila S = new clsPila();
            int cantidad = PS[0, 2];
            int columna = PS[0, 0];

            for (int i = 1; i <= cantidad; i++)
            {
                if (PS[i, 0] == PS[i, 1])
                {
                    S.Add(PS[i, 2]);
                }
            }
            return S;
        }
    }

    }


