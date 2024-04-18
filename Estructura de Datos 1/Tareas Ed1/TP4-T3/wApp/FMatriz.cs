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
    public partial class FMatriz : Form
    {
        public FMatriz()
        {
            InitializeComponent();
        }

        int[,] A ={
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            { 0, 0, 4, 4, 4, 4, 4, 4, 0, 0},
            { 0, 0, 4, 0, 0, 0, 0, 4, 0, 0},
            { 0, 0, 4, 0, 0, 0, 0, 4, 0, 0},
            { 0, 0, 4, 0, 0, 0, 0, 4, 0, 0},
            { 0, 0, 4, 0, 0, 0, 0, 4, 0, 0},
            { 0, 0, 4, 4, 4, 4, 4, 4, 0, 0},
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        };

        clsRect m = new clsRect();

        private void button1_Click(object sender, EventArgs e)
        {
            m.F = 10;
            m.C = 10;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label1.Text = m.MostrarM(A);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            m.CargarSparce(A);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            label2.Text = m.Mostrar();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            label3.Text = m.MostrarF();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            m.MovIzq();
            label3.Text = m.MostrarF();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            m.MovDere();
            label3.Text = m.MostrarF();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            m.MovAbajo();
            label3.Text = m.MostrarF();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            m.MovArriba();
            label3.Text = m.MostrarF();
        }
    }
}
