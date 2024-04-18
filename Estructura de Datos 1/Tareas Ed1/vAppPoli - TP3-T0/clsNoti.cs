
using System;

namespace vApp
{
    //
    public abstract class clsNoti
    {
        // ATRIBUTOS

        public string _mesaje;

        // DESCRIPTORES DE ACCESO
        public string Mensaje
        {
            get { return _mesaje; }
            set { _mesaje = value; }
        }

        //METODOS
        public abstract string Enviar();
    }


    // Clase Correo
    public class clsCorreo : clsNoti
    {
        string _correo;

        public string Correo
        {
            get { return _correo; }
            set { _correo = value; }
        }

        public clsCorreo()
        {
            this.Correo = "";
        }
        public clsCorreo(string xcorreo)
        {
            this.Correo = xcorreo;
        }

        public override string Enviar()
        {
            string xnoti = "Mensaje : " + this.Mensaje + " enviado por mail a " + Correo;
            return xnoti;
        }
    }

    public class clsSms : clsNoti
    {
        string _telefono;

        public string Telefono
        {
            get { return _telefono; }
            set { _telefono = value; }
        }

        public clsSms()
        {
            this.Telefono = "";
        }
        public clsSms(string xtelefono)
        {
            this.Telefono = xtelefono;
        }

        public override string Enviar()
        {
            string xnoti = "Mensaje : " + this.Mensaje + " enviado por SMS a " + Telefono;
            return xnoti;
        }
    }
    public class clsWsp : clsNoti  //nombre de la clase:Padreclase
    {
        //Constructor
        string _whatsapp;
        //copía
        public string Whatsapp
        {
            get { return _whatsapp; }
            set { _whatsapp = value; }
        }
        //Constructor
        public clsWsp()
        {
            this.Whatsapp = "";
        }
        //Constructor Con Parametros 
        public clsWsp(string xwhatsapp)
        {
            this.Whatsapp = xwhatsapp;  
        }

        public override string Enviar()
        {
            string xnoti = "Mensaje : " + this.Mensaje + " enviado por Whatsapp a " + Whatsapp;
            return xnoti;
        }
    }


}
