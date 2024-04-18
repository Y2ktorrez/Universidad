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
    public partial class fFigu : Form
    {
        public fFigu()
        {
            InitializeComponent();
        }

        int[,] A = { 
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
                   };

        clsFigura F = new clsFigura();

        private void fFigu_Load(object sender, EventArgs e)
        {

        }

        // Mover la figura a la izquierda
        private void cmdMovIzq_Click_1(object sender, EventArgs e)
        {
            F.MovIzq();
            label2.Text = F.DibujaArreglo(F.S);
            lblFSA.Text = F.DibujarFiguraFronS();
        }

        private void cmdMovDer_Click_1(object sender, EventArgs e)
        {
            F.MovDer();
            label2.Text = F.DibujaArreglo(F.S);
            lblFSA.Text = F.DibujarFiguraFronS();
        }

        private void cmdMovUp_Click_1(object sender, EventArgs e)
        {
            F.MovUp();
            label2.Text = F.DibujaArreglo(F.S);
            lblFSA.Text = F.DibujarFiguraFronS();
        }

        private void cmdMovDown_Click_1(object sender, EventArgs e)
        {
            F.MovDown();
            label2.Text = F.DibujaArreglo(F.S);
            lblFSA.Text = F.DibujarFiguraFronS();
        }

        private void cmdAtoSA_Click(object sender, EventArgs e)
        {
            F.PasarAtoS(A);
            label2.Text = F.DibujaArreglo(F.S);
        }

        private void cmdViewA_Click(object sender, EventArgs e)
        {
            label1.Text = F.DibujaArreglo(A);
            label3.Text = "Ayudantiaa ";
        }

        private void cmdViewSA_Click(object sender, EventArgs e)
        {
            label2.Text = F.DibujaArreglo(F.S);
        }

        private void cmdFigura_Click(object sender, EventArgs e)
        {
            lblFSA.Text = F.DibujarFiguraFronS(); 
        }
    }
}
