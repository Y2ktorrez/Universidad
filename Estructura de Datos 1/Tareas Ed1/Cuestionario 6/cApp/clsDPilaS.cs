using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cApp
{
    public class clsDPilaS
    {
        //Atributos 
        private const int max = 20; //el maximo del arreglo 
        private const int n = 4; //la cantidad de pilas
        private const int u = max / n; //la cantidad de elementos de cada pila 
        private int[] V; //arreglo de la pila 
        private int[] B; //almacena el inicio y fin de cada pila 
        private int[] S; //el tamaño de cualquier S
        private int[] T; //almacena el TOP  

        //Create()-->Pila  Crea una DoblePila

        public clsDPilaS()
        {
            V = new int[max];
            B = new int[n+1];
            S = new int[n];
            T = new int[n];
            for (int j = 0; j < max; j++)
            {
                V[j] = 0;
            }
            int i = 0;
            while (i < n)
            {
                B[i] = (u * i);
                T[i] = (u * i)-1;
                B[i] = (u * i)-1;
                i++;
            }
            B[i] = max;
        }

        //Add(i,x)-->Pila  Adiciona el elemento x a la Pila i (10 ptos)
        public void Add(int i, int x)
        {
            if (!IsFull(i)) //si no esta llena Pila1
            {
                T[i]++;
                V[T[i]] = x;
            }
        }

        /*DelFon(i)-->Pila  Borra el elemento del tope de la Pila i, la cantidad de elementos de la Pila i debe ser
          mayor acero(20 ptos)*/

        public void DelFon(int i)
        {
            if (!IsVacia(i)) //si no esta vacia la pila i=1
            {
                T[i]--;
            }
        }

        /*DelFonN(i,n)-->Pila  Borra los n elemento del fondo de la Pila i*/

        /*DelFonN(i)-->Pila  //Borra el elemento del fondo de la Pila i*/

        public void DelFonN(int i)
        {
            if (!IsVacia(i)) //si no esta vacia la pila i=1
            {
                S[i]++;
            }
        }

        /*sVacia(i)-->Boolean  // Es TRUE si la Pila i esta vacía, de lo contrario es FALSE*/
        public bool IsVacia(int i)
        {
            return S[i] == T[i];
        }

        /*IsFull(i)--> Boolean  //Es TRUE si la Pila i esta llena, de lo contrsrio esta vacia*/
        public bool IsFull(int i)
        {
            return T[i] == B[i+1];
        }

        /*LongEle(i) --> N // Cuantos elemento tiene la Pila i*/
        public int LongEle(int i)
        {
            return (T[i] - B[i]) - (S[i] - B[i]);
        }
    }
}
