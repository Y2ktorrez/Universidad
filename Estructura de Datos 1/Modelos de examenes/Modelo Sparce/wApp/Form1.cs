/*************************************************************
Institución:    Universidad Gabriel Rene Moreno
Proyecto:       TAD Rectángulo en C# 
Descripción:    Implementar el TAD Rectángulo en C# en un clase Rectangulo.cs 
                Implementar la interfaz para usar las operaciones del TAD Rectangulo (wApp)
Creador:        Andres Torrez Vaca.
Registro:       220153914
Lenguaje:       C#
Aplicación:     Visual Studio 2022 - Windows Aplications
*************************************************************/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using cApp; 

namespace wApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FMatriz a = new FMatriz();
            a.Show();
        }
    }
}
