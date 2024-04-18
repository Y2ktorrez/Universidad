using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CApp
{
    class Program
    {
       public static void Main(string[] args)
       {
            clsLista L = new clsLista();
            L.AddPrimero(5);
            L.AddPrimero(4);
            L.AddPrimero(2);
            L.AddPrimero(1);
            Console.WriteLine(L.View());
            L.AdicionarAntes(4, 3);
            Console.WriteLine("Adiconando 3 antes de 4" );
            Console.WriteLine(""+L.View());
            Console.ReadKey();

        }
    }
}
