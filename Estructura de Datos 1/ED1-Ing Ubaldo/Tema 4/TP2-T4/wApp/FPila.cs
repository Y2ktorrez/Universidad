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
    public partial class FPila : Form
    {
        public FPila()
        {
            InitializeComponent();
        }

        clsPila S = new clsPila();
        clsPila P = new clsPila();
        clsPila R = new clsPila();

        private void FPila_Load(object sender, EventArgs e)
        {

        }

        private void CmdCreaS_Click(object sender, EventArgs e)
        {
            S.Drop();
            lblPila.Text = S.Imprimir();
            lblLong.Text = "";
            lblTope.Text = "";
            txtEleme.Text = "";
            lblRear.Text = "";
        }

        private void cmdAdd_Click(object sender, EventArgs e)
        {
            if (S.Llena()!=true)  {
                S.Add(S,Convert.ToInt32(txtEleme.Text));
                lblPila.Text = S.Imprimir();
                lblLong.Text = Convert.ToString(S.Long());
                lblTope.Text = Convert.ToString(S.Tope());
                lblRear.Text = Convert.ToString(S.Rear(S));
            }
            else
                MessageBox.Show("Pila llena ");

        }

        private void cmdDelete_Click(object sender, EventArgs e)
        {
            if (S.Vacia()!=true)  {
                S.Delete(S);
                lblPila.Text = S.Imprimir();
                lblLong.Text = Convert.ToString(S.Long());
                lblTope.Text = Convert.ToString(S.Tope());
                lblRear.Text = Convert.ToString(S.Rear(S));
            }
            else
                MessageBox.Show("Pila Vacia ");
        }

        private void cmdTope_Click(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label1.Text = Convert.ToString(S.Avg(S));
        }

        private void button4_Click(object sender, EventArgs e)
        {
            label1.Text = Convert.ToString(S.Suma(S));
        }

        private void button5_Click(object sender, EventArgs e)
        {
            P = P.Ivertir(S);
            label3.Text = P.Imprimir();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            label11.Text = R.ValidarExpresion(textBox1.Text).ToString();
        }
    }
}
