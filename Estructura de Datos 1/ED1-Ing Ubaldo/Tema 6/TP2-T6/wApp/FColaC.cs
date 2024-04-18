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
    public partial class FColaC : Form
    {
        public FColaC()
        {
            InitializeComponent();
        }

        clsColaC Q = new clsColaC();
        clsColaC P = new clsColaC();
        clsColaC C = new clsColaC();
        private void FCola_Load(object sender, EventArgs e)
        {

        }

        private void CmdCreaS_Click(object sender, EventArgs e)
        {
            Q.Drop();
            lblCola.Text = Q.Imprimir();
            lblLong.Text = "";
            lblRear.Text = "";
            txtEleme.Text = "";
            lblFront.Text = "";
        }

        private void cmdAdd_Click(object sender, EventArgs e)
        {
            if (Q.Llena()!=true)  {
                string cad = txtEleme.Text;
                int valor;
                bool exito = int.TryParse(cad, out valor);
                if (exito)
                {
                    Q.Add((valor));
                    //lblCola.Text = Q.Imprimir();
                    lblCola.Text = Q.Imprimir();
                    lblFront.Text = Convert.ToString(Q.Frente());
                    lblRear.Text = Convert.ToString(Q.Atras());
                    lblLong.Text = Convert.ToString(Q.Long());
                }
                else
                {
                    MessageBox.Show("El formato del valor ingresado es incorrecto ");
                }
            }
            else
                MessageBox.Show("Cola llena ");

        }

        private void cmdDelete_Click(object sender, EventArgs e)
        {
            if (Q.Vacia()!=true)  {
                Q.Delete();
                lblCola.Text = Q.Imprimir();
                lblFront.Text = Convert.ToString(Q.Frente());
                lblRear.Text = Convert.ToString(Q.Atras());
                lblLong.Text = Convert.ToString(Q.Long());
            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void FCola_Load_1(object sender, EventArgs e)
        {

        }
        private void button2_Click_1(object sender, EventArgs e)
        {
            label1.Text = Convert.ToString(Q.CeldasLibres());
        }

        private void button3_Click(object sender, EventArgs e)
        {
            
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
