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
    public partial class FPolyExa : Form
    {
        public FPolyExa()
        {
            InitializeComponent();
        }

        clsPoly P = new clsPoly();
        clsPoly Q = new clsPoly();
        clsPoly R = new clsPoly();
        
            
        private void FPolyExa_Load(object sender, EventArgs e)
        {

        }

        private void cmdCero_Click(object sender, EventArgs e)
        {
            //lblNatu.Text =Convert.ToString(N.esCero(Convert.ToInt32(txtNatu.Text)));
        }

       
        private void cmdCrearP_Click(object sender, EventArgs e)
        {

            P.CrearPoly(Convert.ToInt32(txtNatu.Text));
            lblPx.Text = P.ToString();
        }
       
        private void CmdCreaQ_Click(object sender, EventArgs e)
        {
            Q.CrearPoly(Convert.ToInt32(txtNatu.Text));
            lblQx.Text = Q.ToString();
        }

        private void cmdEval_Click(object sender, EventArgs e)
        {
            //;
           
        }

        private void cmdGrado_Click(object sender, EventArgs e)
        {
            label7.Text = Convert.ToString(R.Grado());
        }

        private void CmdTerm_Click(object sender, EventArgs e)
        {
            label8.Text = Convert.ToString(P.NumeroTerminos());
        }

        private void cmdSum_Click(object sender, EventArgs e)
        {
            R = R.Add(P, Q);
            lblCx.Text = Convert.ToString(R);
        }

        private void cmdResta_Click(object sender, EventArgs e)
        {
            //
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int coeficiente = int.Parse(txtOp1.Text);
            int Exponente = int.Parse(txtOp2.Text);
            R = R.SMult(P, coeficiente, Exponente);
            label6.Text = Convert.ToString(R);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            R = R.Mult(P, Q);
            label1.Text = Convert.ToString(R);
        }
    }
}
