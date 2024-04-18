using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using cApp;

namespace wApp
{
    public partial class Figura : Form
    {
        public Figura()
        {
            InitializeComponent();
        }

        int[,] A = {
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
                     { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
                     { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
                     { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
                     { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
                     { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                   };

        clsRectangulo E = new clsRectangulo();
       

        private void fSpar_Load(object sender, EventArgs e)
        {
         
        }
        private void MostrarArreglo()
        {           
            int i,j = 0;
            label1.Text = "";
            for (i = 0;i <= 9;i++)
            {
                label1.Text += "\n";
                for (j = 0; j <= 9; j++)
                    if (A[i, j] != 0)
                        label1.Text += "[" + A[i, j] + "]";
                    else
                        label1.Text += "[_]";

            }
            label1.Text += "\n";
        }
        private void fSpar_Load_1(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {
            E.CreateFigura(A);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            MostrarArreglo();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            label2.Text = E.MostrarS();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button12_Click(object sender, EventArgs e)
        {
            label3.Text = E.Dibujar();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            E.MovIzq();
            label2.Text = E.MostrarS();
            label3.Text = E.Dibujar();
        }

        private void button14_Click(object sender, EventArgs e)
        {
            E.MovDer();
            label2.Text = E.MostrarS();
            label3.Text = E.Dibujar();
        }

        private void button15_Click(object sender, EventArgs e)
        {
            E.MovUp();
            label2.Text = E.MostrarS();
            label3.Text = E.Dibujar();
        }

        private void button16_Click(object sender, EventArgs e)
        {
            E.MovDown();
            label2.Text = E.MostrarS();
            label3.Text = E.Dibujar();
        }

        private void button10_Click(object sender, EventArgs e)
        {

        }
    }
}
