using System;
using System.Net;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class ClsAgenda
    {

        string[] nombre;
        string[] apellido;
        string[] correo;
        string[] telef;
        string[] dir;
        int N;

        public ClsAgenda()
        {
            nombre = new string[100];
            apellido = new string[100];
            correo = new string[100];
            telef = new string[100];
            dir = new string[100];
            N = 0;
        }

        public void guardar(string n, string a, string c, string t, string d)
        {
            nombre[N] = n;
            apellido[N] = a;
            correo[N] = c;
            telef[N] = t;
            dir[N] = d;
            N++;
        }

        public string getnom(int i)
        {
            return nombre[i];
        }

        public int getN()
        {
            return N;
        }

        public string mostrar()
        {
            string cad = "";

            for (int i = 0; i < N; i++)
            {
                cad = cad + nombre[i] + "  " + apellido[i] + "  " + correo[i] + "  " + telef[i] + "   " + dir[i];
                cad = cad + "\r\n";
            }

            return cad;
        }

        public string Buscar(string nom)
        {
            string result = "";
            for (int i = 0; i < N; i++)
            {
                if (nombre[i] == nom)
                {
                    result = result + "Nombre: " + nombre[i] + "\r\n" + "Apellido: " + apellido[i] + "\r\n" + "Correo: " + correo[i] + "\r\n" + "Telefono: " + telef[i] + "\r\n" + "Direccion: " + dir[i];
                }
            }
            return result;
        }

        public int bucpos(string cad)
        {
            int i = 0;
            bool b = false;
            while (i < N && b == false)
            {
                if (nombre[i] == cad)
                {
                    b = true;
                }
                i++;
            }
            return i;
        }

        public bool existe(string nom)
        {
            bool b = false;
            for (int i = 0; i < N; i++)
            {
                if (nombre[i] == nom)
                {
                    return b = true;
                }
            }
            return b;
        }

        public void eliminar(int a)
        {

            for (int i = a; i < N - 1; i++)
            {
                nombre[i] = nombre[i + 1];
                apellido[i] = apellido[i + 1];
                telef[i] = telef[i + 1];
                dir[i] = dir[i + 1];
                correo[i] = correo[i + 1];
            }
            N--;
        }
    }
}
