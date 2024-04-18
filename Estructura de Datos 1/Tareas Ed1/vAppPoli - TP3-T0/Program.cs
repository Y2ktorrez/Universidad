using System;

namespace vApp
{
    class Program
    {
        static void Main(string[] args)
        {
            clsNoti[] mensaje = new clsNoti[3];
            mensaje[0] = new clsCorreo("andrestorrezvaca@gmail.com");
            mensaje[1] = new clsSms("75612841");
            mensaje[2] = new clsWsp("75612841");
            for (int i = 0; i < mensaje.Length; i++)
            {
                mensaje[i].Mensaje = " hi ";
                Console.WriteLine(mensaje[i].Enviar());
            }

            Console.ReadKey();
        }
    }
}
