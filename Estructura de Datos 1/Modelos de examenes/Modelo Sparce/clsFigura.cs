using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsFigura
    {
         /*ATRIBUTOS*/
       
        const int Max=3;                     // Maxima Cantidad de Maxima de filas del Arreglo S
        public int[,] S = new int[Max, 3];   //  S es un arreglo donde se almacena los valores<>0 de una Matriz Esparcida A 
        public int Cant = 0;                 //  Cantidad de celdas con valores<>0 de la Matriz Esparcida A 

        /*CONSTRUCTORES*/
        public clsFigura() 
        { 
            Cant = 0; 
            int i = 0; int j = 0;
            while (i <= Max-1)

            {
                j = 0;
                while (j <= 2)
                {
                    S[i,j]=0;  
                    j++;
                }
                i++;
            }
        }
        
        public clsFigura(clsFigura x)
        {
            Cant = x.Cant;
            int i = 0; int j = 0;
            while (i <= Max - 1)
            {
                j = 0;
                while (j <= 2)
                {
                    S[i, j] = x.S[i,j];
                    i++;
                }
                j++;
            }
        }

        // Funcion que dibuja en una cadena los datos almacenados en un arreglo cualquiera
        public string DibujaArreglo(int[,] A)
        {
            int n = A.GetLength(0);
            int m = A.GetLength(1);             
            string texto = "";
            int i = 0;
            while (i < n)
            {
                int j = 0;
                texto += "\n";
                while (j < m)
                {
                    if (A[i, j] != 0)
                        texto += "[" + A[i, j] + "]";
                    else
                        texto += "[_]";
                    j++;
                }
                i++;
            }
            texto += "\n";
            return texto;
        }
        //1. PasarAtoS(A) - - > S //Pasa los datos de Anxn a S3x3 bajo los siguientes criterios: (30 ptos)
        // Funcion que pasa los valores de la matriz esparcida A a S
        /*
         S(0,0)=n, S(0,1)=n, S(0,2)=t, donde n es la cantidad de filas y columnas de A, t es la cantidad de números diferentes de cero
en A.
S(1,0) = la fila de la esquina superior izquierda de la figura, 
S(1,1) = la coluna de la esquina superior izquierda de la figura y
S(1,2) = el número diferente de cero.
        -------------------------------------------
S(2,0) = la fila de la esquina inferior derecha de la figura, 
S(2,1) = la coluna de la esquina inferior derecha de la figura y en
S(2,2) = el número diferente de cero.

         */
        public void PasarAtoS(int[,] A)
        {
            int n = A.GetLength(0);//15 fila
            int m = A.GetLength(1);//15 columna
            Cant = 0;
            int sw = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (A[i,j]!=0)//A[8,7]=2  
                    {
                        if (sw == 0)
                        {
                            S[1, 0] = i; S[1, 1] = j; S[1, 2] = A[i, j];
                            sw = 1;
                        }
                        else
                        {  //aqui
                           // Console.WriteLine("i="+i+ "j=" + j+ "A["+i+","+j+"]=" + A[i, j]);
                            S[2, 0] = i; S[2, 1] = j; S[2, 2] = A[i,j];
                        }
                        Cant++;
                    }
                }
            }
            S[0, 0] = n; S[0, 1] = m; S[0, 2] = Cant;


        }

        // Dibuja en una cadena la figura dentro de las celas de A, para dibujar la figura se debe utilizar los datos del arreglo S
        
        public string DibujarFiguraFronS()
        {
            int fil = S[0, 0]; int Col = S[0, 1];
            string str = "";
            int f1 = S[1, 0]; int c1 = S[1, 1];
            int f2 = S[2, 0]; int c2 = S[2, 1];
            for (int i = 0; i < fil; i++)
            {
                str = str + "\n";
                for (int j = 0; j < Col; j++)
                {
                    string strs = "[_]";//2 (i=2,j=3)
                    if (i==S[1,0] && j>=S[1,1] && j <= S[2, 1])
                    {
                        strs = "[" + 2 + "]";                            
                    }
                    if (i == S[2, 0] && j >= S[1, 1] && j <= S[2, 1])
                    {
                        strs = "[" + 2 + "]";
                    }
                    //fila =i
                    if (j == S[1, 1] && i >= S[1, 0] && i <= S[2, 0])
                    {
                        strs = "[" + 2 + "]";
                    }
                    if (j == S[2, 1] && i >= S[1, 0] && i <= S[2, 0])
                    {
                        strs = "[" + 2 + "]";
                    }
                    str += strs;

                }
            }
            str = str + "\n";
            return str;
        }

        // Funciones para los movimientos de la figura dentro de A utlizando los datos de S
          
        // Funcion que actualiza los datos S para mover la figura hacia arriba
        public void MovUp()
        {
            S[1, 0] = S[1, 0] - 1;//(1,3)
            S[2, 0] = S[2, 0] - 1;//(7,7)
        }

        // Funcion que actualiza los datos S para mover la figura hacia abajo
        public void MovDown()
        {
            S[1, 0] = S[1, 0] + 1;//(1,3)
            S[2, 0] = S[2, 0] + 1;//(7,7)
        }

        // Funcion que actualiza los datos S para mover la figura hacia la Izquierda
        public void MovIzq()
        {
            S[1, 1] = S[1, 1] - 1;//(2,3)->(2,2)
            S[2, 1] = S[2, 1] - 1;//(8,7)->(8,6)
        }

        // Funcion que actualiza los datos S para mover la figura hacia la derecha
        public void MovDer()
        {
            
          
            S[1, 1] = S[1, 1] + 1;//(2,3)->(2,4)
            S[2, 1] = S[2, 1] + 1;//(8,7)->(8,8)
        }

    }

}
