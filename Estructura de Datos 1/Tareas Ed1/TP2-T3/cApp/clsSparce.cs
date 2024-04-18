using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cApp
{
    public class clsSparce
    {
        //Atributos
        const int Max = 30;  //Maximo de filas 
        public int F; //filas de la matriz
        public int C; //columnas de la matriz
        public int cant; //cantidad de elementos de la matriz espacida
        public int[,] Sparce = new int[Max, 3]; //  [filas=Max,columnas=3]
        //public *int[fila,columa]; //Java

        //Constructor
        public clsSparce()
        {
            this.F = 0;
            this.C = 0;
            this.cant = 0;
            int i = 0;
            while (i < Max)
            {
                this.Sparce[i, 0] = 0;
                this.Sparce[i, 1] = 0;
                this.Sparce[i, 2] = 0;
                i++;
            }
        }

        //Constructor de copia
        public clsSparce(clsSparce m)
        {
            this.F = m.F;
            this.C = m.C;
            this.cant = m.cant;
            int i = 0;ce
            while (i < Max)
            {
                this.Sparce[i, 0] = m.Sparce[i, 0];
                this.Sparce[i, 1] = m.Sparce[i, 1];
                this.Sparce[i, 2] = m.Sparce[i, 2];
                i++;
            }
        }

        public void clearMatrizSparce()
        {
            cant = 0;
            int i = 0;
            while (i < Max)
            {
                this.Sparce[i, 0] = 0;
                this.Sparce[i, 1] = 0;
                this.Sparce[i, 2] = 0;
                i++;
            }
        }

        //Mostrar la Matriz Original 
        public String MostrarMatriz(int[,] A)
        {
            String S = "";
            F = A.GetLength(0);
            C = A.GetLength(1);
            for (int i = 0; i < F; i++)
            {
                S = S + "\n";
                for (int j = 0; j < C; j++) 
                {
                    S = S + "[" + A[i, j] + "]";
                }
            }
            return S;
        }
        
        public void Cargar(int[,] A)
        {
            this.F = A.GetLength(0);//numero de filas de la M.O.
            this.C = A.GetLength(1);//numero de columas de la M.O.
            this.cant = 1;
            Sparce[0, 0] = F;//Filas de la Matriz Original
            Sparce[0, 1] = C;//Columnas de la Matriz Original
            int i = 0;
            while (i < F)
            {
                int j = 0;
                while (j < C)
                {
                    if (A[i, j] != 0)
                    {
                        Sparce[cant, 0] = i;
                        Sparce[cant, 1] = j;
                        Sparce[cant, 2] = A[i, j];
                        cant++;
                    }
                    j++;
                }
                i++;
            }
            cant--;
            Sparce[0, 2] = cant;
        }

        public String MostrarMatrizSparce()
        {
            String S = "";
            for (int i = 0; i <= cant; i++)//Fila
            {
                for (int j = 0; j < 3; j++) //columnas
                {
                    S = S + "[" + Sparce[i, j] + "]";
                }
                S = S + "\n";//Salto de Linea
            }
            return S;
        }

        //C = A + B usando matrices normales
        public String SumaAB(int[,] A, int[,] B)
        {
            int sumadeValores = 0;
            String sum = "";
            for (int i = 0; i < A.GetLength(0); i++)//Fila 
            {
                sum = sum + "\n";//salto de linea se pasa a la 
                for (int j = 0; j < A.GetLength(1); j++)// columnas
                {
                    sumadeValores = A[i, j] + B[i, j];
                    sum = sum + "[" + sumadeValores + "]";
                }
            }
            return sum;
        }

        public int[,] SumaAB2(int[,] A, int[,] B, int[,] suma)
        {
            for (int i = 0; i < A.GetLength(0); i++)//Fila 
            {
                for (int j = 0; j < A.GetLength(1); j++)// columnas
                {
                    suma[i, j] = A[i, j] + B[i, j];
                }
            }
            return suma;
        }

        //C = A + B usando matrices sparce

        public clsSparce sumaDeMatrices(clsSparce A, clsSparce B)
        {
            int i = 1;
            clsSparce R = new clsSparce();
            //        A.F==B.F                   A.C==B.C
            if ((A.Sparce[0, 0] == B.Sparce[0, 0]) && (A.Sparce[0, 1] == B.Sparce[0, 1]))
            {
                R.Sparce[0, 0] = A.Sparce[0, 0];
                R.Sparce[0, 1] = A.Sparce[0, 1];
                R.F = A.F;
                R.C = A.C;
                R.cant = 0;
                while ((i <= A.cant) && (i <= B.cant))
                {
                    if ((A.Sparce[i, 0] == B.Sparce[i, 0]) && (A.Sparce[i, 1] == B.Sparce[i, 1]))
                    {   

                        if (A.Sparce[i, 2] + B.Sparce[i, 2] != 0)
                        {
                            R.Sparce[i, 0] = A.Sparce[i, 0]; //Fila
                            R.Sparce[i, 1] = A.Sparce[i, 1]; //columna
                            R.Sparce[i, 2] = A.Sparce[i, 2] + B.Sparce[i, 2];
                            R.cant++;
                        }

                        i++;
                    }
                    else
                    {
                        R.Sparce[i, 0] = A.Sparce[i, 0]; //Fila
                        R.Sparce[i, 1] = A.Sparce[i, 1]; //columna
                        R.Sparce[i, 2] = A.Sparce[i, 2];
                        i++;
                    }
                }
            }
            R.Sparce[0, 2] = R.cant;
            return R;
        }
    }
}
