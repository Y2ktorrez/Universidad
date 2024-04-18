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
    public partial class FCola : Form
    {
        public FCola()
        {
            InitializeComponent();
        }

        clsCola Q = new clsCola();
        clsCola P = new clsCola();
        clsCola C = new clsCola();
        private void FCola_Load(object sender, EventArgs e)
        {

        }

        private void CmdCreaS_Click(object sender, EventArgs e)
        {
            P.Drop();
            lblCola.Text = P.Imprimir();
            lblLong.Text = "";
            lblRear.Text = "";
            lblFront.Text = "";
            txtEleme.Text = "";
        }

        private void cmdAdd_Click(object sender, EventArgs e)
        {
            if (!P.Llena())  {
                string cad = txtEleme.Text;
                int valor;
                bool exito = int.TryParse(cad, out valor);
                if (exito)
                {
                    P.Add(valor);
                    lblFront.Text = Convert.ToString(P.Front());
                    lblRear.Text = Convert.ToString(P.Rear());
                    lblLong.Text = Convert.ToString(P.Long());
                    lblCola.Text = P.Imprimir();
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
            if (!P.Vacia())  {
                P.Delete();
                lblFront.Text = Convert.ToString(P.Front());
                lblRear.Text = Convert.ToString(P.Rear());
                lblLong.Text = Convert.ToString(P.Long());
                lblCola.Text = P.Imprimir();
            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void FCola_Load_1(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (!P.Vacia())
            {
                string cad = txtEleme.Text;
                int valor;
                bool exito = int.TryParse(cad, out valor);
                if (exito)
                {
                    P.descola(valor);
                    lblFront.Text = Convert.ToString(P.Front());
                    lblRear.Text = Convert.ToString(P.Rear());
                    lblLong.Text = Convert.ToString(P.Long());
                    lblCola.Text = P.Imprimir();
                }
                else
                {
                    MessageBox.Show("El formato del valor ingresado es incorrecto ");
                }
                
            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            C = C.concatena(P,Q);
            label2.Text = C.Imprimir();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            P = P.duplica(P);
            lblFront.Text = Convert.ToString(P.Front());
            lblRear.Text = Convert.ToString(P.Rear());
            lblLong.Text = Convert.ToString(P.Long());
            lblCola.Text = P.Imprimir();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            C = C.mezcla(P, Q);
            label4.Text = C.Imprimir();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (!Q.Llena())
            {
                string cad = textBox3.Text;
                int valor;
                bool exito = int.TryParse(cad, out valor);
                if (exito)
                {
                    Q.Add(valor);
                    label15.Text = Convert.ToString(Q.Front());
                    label13.Text = Convert.ToString(Q.Rear());
                    label14.Text = Convert.ToString(Q.Long());
                    label11.Text = Q.Imprimir();
                }
                else
                {
                    MessageBox.Show("El formato del valor ingresado es incorrecto ");
                }
            }
            else
                MessageBox.Show("Cola llena ");
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            if (!Q.Vacia())
            {
                Q.Delete();
                label15.Text = Convert.ToString(Q.Front());
                label13.Text = Convert.ToString(Q.Rear());
                label14.Text = Convert.ToString(Q.Long());
                label11.Text = Q.Imprimir();
            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Q.Drop();
            label11.Text = Q.Imprimir();
            label14.Text = "";
            label13.Text = "";
            label15.Text = "";
            textBox3.Text = "";
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (!Q.Vacia())
            {
                string cad = textBox3.Text;
                int valor;
                bool exito = int.TryParse(cad, out valor);
                if (exito)
                {
                    Q.descola(valor);
                    label15.Text = Convert.ToString(Q.Front());
                    label13.Text = Convert.ToString(Q.Rear());
                    label14.Text = Convert.ToString(Q.Long());
                    lblCola.Text = Q.Imprimir();
                }
                else
                {
                    MessageBox.Show("El formato del valor ingresado es incorrecto ");
                }

            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void button5_Click_1(object sender, EventArgs e)
        {
            Q = Q.duplica(Q);
            label15.Text = Convert.ToString(Q.Front());
            label13.Text = Convert.ToString(Q.Rear());
            label14.Text = Convert.ToString(Q.Long());
            label11.Text = Q.Imprimir();
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }
    }
}
