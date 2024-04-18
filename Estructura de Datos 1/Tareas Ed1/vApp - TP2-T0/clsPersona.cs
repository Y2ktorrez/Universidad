/*
NOMBRE DE LA CLASE: clsPersona
ATRIBUTOS:
    nombre;
    telefono;
    direccion;
    estado;
OPERACIONES
    Add(nomb,telf,direc)        -- Crea un objeto persona con estado=A"
    Baja()                      -- Da de baja al objeto Persona con estado="B"
    View()                      -- Retorna en una cadena los datos del objeto Persona
 */

using System;

namespace vApp
{
    //
    public class clsPersona
    {
        // ATRIBUTOS

        private string _nombre;
        private string _telefono;
        private string _direccion;
        private string _estado;
        private string _correo;
        private string _fec_nac;
        //private DateTime _fec_nac;

        private int _edad;

        // DESCRIPTORES DE ACCESO A LOS ATRIBUTOS
        public string Nombre
        {
            get { return _nombre; }
            set { _nombre = value; }
        }
        public string Telefono
        {
            get { return _telefono; }
            set { _telefono = value; }
        }
        public string Direccion
        {
            get { return _direccion; }
            set { _direccion = value; }
        }

        public string Estado
        {
            get { return _estado; }
            //set { _estado = value; }   -- Este atributo no puede ser modificado externamente
        }

        public string Correo
        {
            get { return _correo; }
            set { _correo = value; }
        }
        public string Fec_nac
        {
            get { return _fec_nac; }
            set { _fec_nac = value; }
        }
        public int Edad
        {
            get { return _edad; }
            set { _edad = value; }
        }

        // CONSTRUCCTORES

        public clsPersona()
        {
            Nombre = "";
            Telefono = "";
            Direccion = "";
            _estado = "";
            Correo = "";
            Fec_nac = "";
            Edad = 0;

        }

        public clsPersona(clsPersona x)
        {
            this.Nombre = x.Nombre;
            this.Telefono = x.Telefono;
            this.Direccion = x.Direccion;
            _estado = x.Estado;
            this.Correo = x.Correo;
            this.Fec_nac = x.Fec_nac;
            this.Edad = x.Edad;
        }

        // OPERACIONES

        //Crea el objeto Persona
        public void Add(string xnombre, string xtelefono, string xdireccion,
                        string xcorreo, string xfec_nac)
        {
            Nombre = xnombre;
            Telefono = xtelefono;
            Direccion = xdireccion;
            _estado = "A";
            Correo = xcorreo;
            Fec_nac = xfec_nac;
        }



        // Da de baja al objeto persona
        public bool Baja()
        {
            if (Estado == "A")
            {
                _estado = "B";
                return true;
            }
            else
            {
                return false;
            }
        }

        public int CalcularEdad()
        {
            string FechaActual = DateTime.Now.ToString("dd-MM-yyyy");
            string[] partesFechaActual = FechaActual.Split('-');
            string[] partesFechaNaci = Fec_nac.Split('-');
            //------------------------------------------------
            int AñoActual = Convert.ToInt32(partesFechaActual[2]);
            int AñoNaci = Convert.ToInt32(partesFechaNaci[2]);
            Edad = AñoActual - AñoNaci;
            Console.WriteLine(Edad);
            return Edad;
        }
        /*
        public int CalcularEdad2(int x, int z, int y)
        {
            now = DateTime.UtcNow.Year; // este muestra el año actual de la computadora xd. (2023)
            x = fec_nac.Year; //año de nacimiento
            y = now - x;
            return y


        }
        */

        public string View()
        {
            string cadena = "";
            cadena = Nombre + " | " + Telefono + " | " + Direccion + " | " + Estado + " | " +
                Correo + " | " + Fec_nac + " | " + CalcularEdad();
            return cadena;
        }
    }
}