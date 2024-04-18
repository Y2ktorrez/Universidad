using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsSpar
    {
         /*ATRIBUTOS*/
       
        const int Max=1000;                         // Maxima Cantidad de elementos en el arreglo V alternativo
        public int[,] V = new int[Max,3];           // Vector donde se almacena los datos de las Matris A original
        public int Cant = 0;                        // Cantidad de celdas llenas en el vector V
        public int n = 0;                           // Cantidad de filas de la Matriz A original
        public int m = 0;                           // Cantidad de columnas de la Matriz A original

        /*CONSTRUCTORES*/
        public clsSpar() 
        { 
            Cant = 0;
            n= 0;
            m = 0;
            int i = 0;
            while (i < Max)
            {
               V[i, 0] = 0;
               V[i, 1] = 0;
               V[i, 2] = 0;  
               i++;
            }
        }
        
        public clsSpar(clsSpar x)
        {
            Cant = x.Cant;
            n = x.n;
            m = x.m;
            int i = 0;  
            while (i < Max)
            {
               V[i, 0] = x.V[i, 0];
               V[i, 1] = x.V[i, 1];
               V[i, 2] = x.V[i, 2];
               i++;
            }
        }

        // Limpiar el Arreglo V 
        public void ClearArreglo()
        {
            int i = 0; Cant = 0;
            while (i < Max)
            {
                V[i, 0] = 0;
                V[i, 1] = 0;
                V[i, 2] = 0;  
                i++;
            }
        }
     
        // Funcion para mostrar la Matriz A 
        public string MostraArreglo(int[,] M)
        {
            int i, j = 0;
            string cad = "";
            for (i = 0; i < n; i++)
            {
                cad += "\n";
                for (j = 0; j < m; j++)
                    cad += "[" + M[i, j] + "]";
            }
            return cad;
        }


 	// Funcion para mostrar Vector V 
        public string MostrarVector()
        {
            string s = "";
            
            for (int i = 0; i < Cant; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                s += " [" + V[i,j] + "]" ; 
                }
                s += "\n";
            }
            return s;
        }

        //Funcion para pasar los datos de la matriz A al vector V
        public void CargarMatrizToVector(int[,] A)
        {
            // dim A
            n = A.GetLength(0);
            m = A.GetLength(1);
            V[0, 0] = n;
            V[0, 1] = m;
            Cant = 1;
            // dim A el nro de filas y el nro de columnas 
            int i = 0;
            while (i < n) 
            {
                int j=0;
                while (j < m) 
                {
                    if (A[i,j]!=0)
                    {
                        V[Cant, 0] = i;
                        V[Cant, 1] = j;
                        V[Cant, 2] = A[i, j];
                        Cant++;
                    }
                    j++;
                }
                i++;
            }
            V[0, 2] = Cant;
        }

        // Funcion calcular la sumatoria los elementos mayores a cero que estan en A a partir de V.

        public double Suma()
        {
            double s = 0;

            for (int i = 1; i <= Cant;i++ )
            {
                if (V[i,2]>0)
                {
                    s+=V[i,2];
                }
            }
            return s;
        }
        // Funcion para pasar los datos de la matriz A a la matriz Sparce SP(t,3)
        public clsSpar Sparce(int[,] A)
        {
            clsSpar P = new clsSpar();
            // dim A
            P.n = A.GetLength(0);
            P.m = A.GetLength(1);
            P.V[0, 0] = P.n;
            P.V[0, 1] = P.m;
            P.Cant = 1;
            // dim A el nro de filas y el nro de columnas 
            int i = 0;
            while (i < n)
            {
                int j = 0;
                while (j < m)
                {
                    if (A[i, j] != 0)
                    {
                        P.V[P.Cant, 0] = i;
                        P.V[P.Cant, 1] = j;
                        P.V[P.Cant, 2] = A[i, j];
                        P.Cant++;
                    }
                    j++;
                }
                i++;
            }
            P.V[0, 2] = P.Cant-1;
            return P;
        }
        public void MatrixSum(int[,] matA, int[,] matB, int[,] matC)

        {
            if ((matA.GetLength(0) == matB.GetLength(0)) && (matA.GetLength(1) == matB.GetLength(1)))
            {
                int rows = matA.GetLength(0);
                int colums = matA.GetLength(1);

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < colums; j++)
                    {
                        if (matA[i, j] > 0 || matB[i, j] > 0)
                            matC[i, j] = matA[i, j] + matB[i, j];
                        else
                            matC[i, j] = 0;
                    }

                }
            }
        }      
        public bool BuscadorCoordenada(clsSpar P, int x, int y)
        {
            int i = 1;
            while ((i <= P.Cant-1) && (P.V[i,0] <= x))
            {
                if ((P.V[i, 0] == x) && (P.V[i, 1] == y))
                    return true;
                i++;
            }
            return false;
        }
        public int BuscadorFila(clsSpar P, int x, int y)
        {
            int i = 1;
            while ((i <= P.Cant - 1) && (P.V[i, 0] <= x))
            {
                if ((P.V[i, 0] == x) && (P.V[i, 1] == y))
                    break;
                i++;
            }
            return i;
        }
        //MULTIPLICA DOS MATRICES ESPARCIDAS
        public clsSpar MultMatrizSpar(clsSpar A, clsSpar B)
        {
            clsSpar C = new clsSpar();
            C.V[0, 0] = A.n;
            C.V[0, 1] = B.m;
            C.Cant = 1;
            for (int i = 0; i < A.n; i++)
            {
                for (int j = 0; j < B.m; j++)
                {
                    int suma = 0;
                    for (int k = 0; k < A.m; k++)
                    {
                        if (BuscadorCoordenada(A,i,k) && BuscadorCoordenada(B, k, j))
                        {
                            int FilaA = BuscadorFila(A, i, k);
                            int FilaB = BuscadorFila(B, k, j);
                            suma = suma + (A.V[FilaA, 2] * B.V[FilaB, 2]);
                        }
                    }
                    C.V[C.Cant, 0] = i;
                    C.V[C.Cant, 1] = j;
                    C.V[C.Cant, 2] = suma;
                    C.Cant++;
                }
            }
            C.V[0, 2] = C.Cant - 1;
            return C;
        }
        //SUMA DOS MATRICES ESPARCIDAS
        public clsSpar SumaMatrizSpar2(clsSpar A, clsSpar B)
        {
            clsSpar C = new clsSpar();
            C.V[0, 0] = A.n;
            C.V[0, 1] = B.n;
            C.Cant = 1;

            for (int i = 0; i < A.n; i++)
            {
                for (int j = 0; j < A.m; j++)
                {
                    if (BuscadorCoordenada(A, i, j) && BuscadorCoordenada(B, i, j))
                    {
                        int FilaA = BuscadorFila(A, i, j);
                        int FilaB = BuscadorFila(B, i, j);
                        C.V[C.Cant, 0] = i;
                        C.V[C.Cant, 1] = j;
                        C.V[C.Cant, 2] = A.V[FilaA, 2] + B.V[FilaB, 2];
                        C.Cant++;
                    }
                    else
                    {
                        if (BuscadorCoordenada(A, i, j))
                        {
                            int FilaA = BuscadorFila(A, i, j);
                            C.V[C.Cant, 0] = i;
                            C.V[C.Cant, 1] = j;
                            C.V[C.Cant, 2] = A.V[FilaA, 2];
                            C.Cant++;
                        }
                        if (BuscadorCoordenada(B, i, j))
                        {
                            int FilaB = BuscadorFila(B, i, j);
                            C.V[C.Cant, 0] = i;
                            C.V[C.Cant, 1] = j;
                            C.V[C.Cant, 2] = B.V[FilaB, 2];
                            C.Cant++;
                        }

                    }
                }
            }
            C.V[0, 2] = C.Cant - 1;
            return C;
        }
        //LOS ELEMENTOS DE LA DIAGONAL PRINCIPAL DE LA MATRIZ ESPARCIDA
        public string DiagonalPrincipal(clsSpar A)
        {
            string cad = "";
            for(int i = 1; i <= A.Cant-1; i++)
            {
                if (A.V[i, 0] == A.V[i, 1])
                    cad = cad + "," + A.V[i, 2];
            }
            return cad;
        }
        //TRASPOSE   
        public clsSpar Traspose(clsSpar A)
        {
            clsSpar C = new clsSpar();
            C.V[0, 0] = A.n;
            C.V[0, 1] = A.m;
            C.Cant = A.Cant;
            for (int i = 1; i <= A.Cant-1; i++) //i=2
            {
                int x = A.V[i, 0];//0
                int y = A.V[i, 1];//1
                int aux = BuscadorFila(A, y, x);//(1,0) -> 4
                C.V[aux, 0] = y;//1
                C.V[aux, 1] = x;//0
                C.V[aux, 2] = A.V[i, 2];//19
            }
            C.V[0, 2] = C.Cant - 1;
            return C;
        }

    }
}
