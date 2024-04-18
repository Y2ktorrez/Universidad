using System;
//using cApp; /*Dependiendo de la version de Visual*/

namespace vApp
{
    class Program
    {
        static void Main(string[] args)
        {
            // Leer los datos necesarios para crear el objeto persona
            /* Console.Write("Ingrese nombre de la persona:");
             string xnombre = Console.ReadLine();
             Console.Write("Ingrese direccion de la persona:");
             string xdireccion = Console.ReadLine();
             Console.Write("Ingrese telefono de la persona:");
             string xtelefono = Console.ReadLine();
             Console.Write("Ingrese correo de la persona:");
             string xcorreo = Console.ReadLine();
             Console.Write("Ingrese la fecha de Nacimiento de la persona:");
             string xfechanac = Console.ReadLine();
            */

            // Instanciamos la clase clsPersona en la variable xper
            clsPersona xper = new clsPersona();
            string xnombre = "Andres";
            string xtelefono = "75612841";
            string xdireccion = "Plan 3000";
            string xcorreo = "andrestorrezvaca@gmail.com";
            string xfechanac = "21-08-2001";

            // Usamos los metodos de la clase clsPersona
            xper.Add(xnombre, xtelefono, xdireccion, xcorreo, xfechanac); //Llamando al método Add();
            Console.Write(xper.View());               //Llamando al método Mostrar();
            Console.ReadKey();
        }
    }
}