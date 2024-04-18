
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace cApp
{

    public class clsRectangulo
    {
        //ATRIBUTOS

        const int Max = 1000;
        public int[,] S = new int[Max, 3];
        public int Cant = 0;

        // Puntero que indica la ubicacion del elemnto posterior de la cola en el arreglo

        //CONSTRUCTOR
        public clsRectangulo()
        {
            Cant = 0;
            int i = 0; int j = 0;
            while (i <= Max - 1)
            {
                j = 0;
                while (j <= 2)
                {
                    S[i, j] = 0;
                    j++;
                }
                i++;
            }

        }

        public clsRectangulo(clsRectangulo x)
        {
            Cant = x.Cant;
            int i = 0; int j = 0;
            while (i <= Max - 1)
            {
                j = 0;
                while (j <= 2)
                {
                    S[i, j] = x.S[i, j];
                    i++;
                }
                j++;
            }
        }
        //Muestra los datos almacenados en el arreglo S donde estan los valores<>0 de la Matriz Sparcida

        public string MostrarS()
        {
            int i;
            string strSA;
            strSA = "";
            for (i = 0; i <= Cant - 1; i++)
            {
                strSA += "[" + S[i, 0] + "," + S[i, 1] + "]";
                strSA += "\n";
            }
            return strSA;
        }

        //Muestra la figura apartir deñ arreglo S en un string

        public string Dibujar()
        {
            string strSA = "";
            int i, j, k, n, m = 0;

            if (Cant == 0) return strSA;

            n = S[0, 0];
            m = S[0, 1];
            for (i = 0; i < n; i++)
            {
                strSA += "\n";
                for (j = 0; j < m; j++)
                {
                    k = BuscarSA(i, j);
                    if (k >= 1)
                        strSA += "[" + S[k, 2] + "]";
                    else
                        strSA += "[" + "_" + "]";
                }
            }
            strSA += "\n";
            return strSA;

        }

        // Busca si existe la fila y columna de A en S

        public int BuscarSA(int i, int j)
        {
            int k = 1;
            for (k = 1; k < Cant; k++)
            {
                if ((i == S[k, 0]) && (j == S[k, 1]))
                    return k;
            }
            return -1;
        }
        // Funcion para pasar los datos de la matriz esparcida A al arreglo S

        public void CreateFigura(int[,] A)
        {
            // dim A
            int n = 0;
            int m = 0;
            n = A.GetLength(0);
            m = A.GetLength(1);
            S[0, 0] = n;
            S[0, 1] = m;
            Cant = 1;
            // dim A el nro de filas y el nro de columnas
            int i = 0;
            while (i < n)
            {
                int j = 0;
                while (j < m)
                {
                    if (A[i, j] != 0)
                    {
                        S[Cant, 0] = i;
                        S[Cant, 1] = j;
                        S[Cant, 2] = A[i, j];
                        Cant++;
                    }
                    j++;
                }
                i++;
            }
        }
        //BUSCA UNA COORDENADA EN LA MATRIZ SPARCIDA
        public bool BuscadorCoordenada( int x, int y)
        {
            int i = 1;
            while ((i <= Cant - 1) && (S[i, 0] <= x))
            {
                if ((S[i, 0] == x) && (S[i, 1] == y))
                    return true;
                i++;
            }
            return false;
        }
        //Mover la figura hacia arriba 
        public void MovUp()
        {
            /*for (int k = 1; k <= Cant; k++)
            {
                if (S[k, 0] == 0)
                    return;
            }

            for (int k = 1; k <= Cant; k++)
                S[k, 0] = S[k, 0] - 1;
            */
            int k = 1;
            bool b = true;
            while ((k <= Cant) && (b == true))
            {
                if (S[k, 0] <= 0)
                    b = false;
                else
                    S[k, 0] = S[k, 0] - 1; k++;

            }
        }

        //Mover la figura hacia abajo
        public void MovDown()
        {
            for (int k = 1; k <= Cant; k++)
            {
                if (S[k, 0] == 9)
                    return;
            }

            for (int k = 1; k <= Cant; k++)
                S[k, 0] = S[k, 0] + 1;
            
        }

        //Mover la figura hacia la Izquierda

        public void MovIzq()
        {

            int k = 1;
            bool b = true;
            while ((k <= Cant) && (b == true))
            {
                if (S[k, 1] <= 0)
                    b = false;
                else
                    S[k, 1] = S[k, 1] - 1; k++;
               
            }
        }

        //Mover la figura hacia la derecha

        public void MovDer()
        {
            for (int k = 1; k <= Cant; k++)
            {
                if (S[k, 1] == 9)
                    return;
            }
            for (int k = 1; k <= Cant; k++)
                if ((S[k, 1] + 1) < 10)
                    S[k, 1] = S[k, 1] + 1;
            //S[k, 1] = S[k, 1] + 1;
 
        }       

    }

}