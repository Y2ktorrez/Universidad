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
    public partial class fSpar : Form
    {
        public fSpar()
        {
            InitializeComponent();
        }

        int[,] A = {
                     { 1, 2, 3 },
                     { 4, 5, 6 },
                     { 7, 8, 9 },
                   };
        int[,] B = {
                     { 1, 1, 4 },
                     { 3, 2, 1 },
                     { 0, 1, -3 },
                   };
        int[,] C = {
                     { 0, 0, 0 },
                     { 0, 0, 0 },
                     { 0, 0, 0 },
                   };

        clsSpar E = new clsSpar();
        clsSpar F = new clsSpar();
        clsSpar G = new clsSpar();
        clsSpar Sp = new clsSpar();
        clsSpar Mp = new clsSpar();
        clsSpar x = new clsSpar();
        clsSpar y = new clsSpar();
        clsSpar t1 = new clsSpar();
        clsSpar t2 = new clsSpar();

        private void fSpar_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            label1.Text=E.MostraArreglo(A);
        }


        private void button2_Click_1(object sender, EventArgs e)
         {
            // Se define las caracteristicas de la figura inicial
            E.n = 3;       // Fila de la matriz
            E.m = 3;       // Columna la matriz
            G.n = 3;
            G.m = 3;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label2.Text = E.MostrarVector();
        }

        private void cmdProme_Click(object sender, EventArgs e)
        {
            lblPTI.Text = E.Suma().ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //lblPTS.Text = E.SumaTS().ToString();
        }

        private void cmdAtoV_Click(object sender, EventArgs e)
        {
            //E.CargarMatrizToVector(A);
            E = E.Sparce(A);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            G.MatrixSum(A,B,C);
            label3.Text = G.MostraArreglo(C);
            /*G = G.Sparce(C);
            label7.Text = G.MostrarVector();*/         
        }

        private void button5_Click_1(object sender, EventArgs e)
        {
            //F = F.Sparce(B);
            //label5.Text = F.MostrarVector();

        }

        private void button6_Click(object sender, EventArgs e)
        {
            Sp = Sp.SumaMatrizSpar2(E.Sparce(A), F.Sparce(B));
            label8.Text = Sp.MostrarVector();

        }

        private void button7_Click(object sender, EventArgs e)
        {
            Mp = Mp.MultMatrizSpar(E,F);
            label12.Text = Mp.MostrarVector();
        }

        private void button8_Click(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {
            F.n = 3;
            F.m = 3;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            label11.Text = F.MostraArreglo(B);
        }

        private void button11_Click(object sender, EventArgs e)
        {
            F = F.Sparce(B);
        }

        private void button5_Click_2(object sender, EventArgs e)
        {
            label5.Text = F.MostrarVector();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            label7.Text = F.Suma().ToString();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            label14.Text = x.DiagonalPrincipal(E);
        }

        private void button14_Click(object sender, EventArgs e)
        {
            label15.Text = y.DiagonalPrincipal(F);
        }

        private void button15_Click(object sender, EventArgs e)
        {
            t1 = t1.Traspose(E);
            label16.Text = t1.MostrarVector();

        }

        private void button16_Click(object sender, EventArgs e)
        {
            t2 = t2.Traspose(F);
            label17.Text = t2.MostrarVector();
        }
    }
}
