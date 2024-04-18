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
            label1.Text = Convert.ToString(Q.CeldasLibres());

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
                    label1.Text = Convert.ToString(Q.CeldasLibres());
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
                label1.Text = Convert.ToString(Q.CeldasLibres());
            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void FCola_Load_1(object sender, EventArgs e)
        {

        }
        private void button2_Click_1(object sender, EventArgs e)
        {
            if((Q.Long() + P.Long()) > clsColaC.MAX)
            {
                MessageBox.Show("No se puede mezclar las Colas Circulares Q y P porque excede la capacidad de la Cola Circular que es: " + clsColaC.MAX);
            }
            else
            {
                C = C.mezcla(Q, P);
                label20.Text = C.Imprimir();
                label28.Text = Convert.ToString(C.Frente());
                label26.Text = Convert.ToString(C.Atras());
                label27.Text = Convert.ToString(C.Long());
                label29.Text = Convert.ToString(C.CeldasLibres());
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (Q.Vacia() != true)
            {
                string cad = txtEleme.Text;
                //string cad1 = InputBox("");
                int valor;
                bool exito = int.TryParse(cad, out valor);
                if (exito)
                {
                    if(valor > Q.Long())
                    {
                        MessageBox.Show("No puede borrar "+ valor+" elementos porque en la Cola Circular Q solo hay "+ Q.Long()+" elementos");
                    }
                    else
                    {
                        Q.descola((valor));
                        lblCola.Text = Q.Imprimir();
                        lblFront.Text = Convert.ToString(Q.Frente());
                        lblRear.Text = Convert.ToString(Q.Atras());
                        lblLong.Text = Convert.ToString(Q.Long());
                        label1.Text = Convert.ToString(Q.CeldasLibres());
                    }
                }
                else
                {
                    MessageBox.Show("El formato del valor ingresado es incorrecto ");
                }
            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            Q = Q.inversa(Q);
            lblCola.Text = Q.Imprimir();
            lblFront.Text = Convert.ToString(Q.Frente());
            lblRear.Text = Convert.ToString(Q.Atras());
            lblLong.Text = Convert.ToString(Q.Long());
            label1.Text = Convert.ToString(Q.CeldasLibres());
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if((Q.Long() * 2) > clsColaC.MAX)
            {
                MessageBox.Show("No se puede duplicar la Cola Circular porque excede la capacidad de la Cola Circular que es: "+ clsColaC.MAX);
            }
            else
            {
                Q = Q.duplica(Q);
                lblCola.Text = Q.Imprimir();
                lblFront.Text = Convert.ToString(Q.Frente());
                lblRear.Text = Convert.ToString(Q.Atras());
                lblLong.Text = Convert.ToString(Q.Long());
                label1.Text = Convert.ToString(Q.CeldasLibres());
            }      
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (P.Llena() != true)
            {
                string cad = textBox1.Text;
                int valor;
                bool exito = int.TryParse(cad, out valor);
                if (exito)
                {
                    P.Add((valor));
                    //lblCola.Text = Q.Imprimir();
                    label9.Text = P.Imprimir();
                    label17.Text = Convert.ToString(P.Frente());
                    label15.Text = Convert.ToString(P.Atras());
                    label16.Text = Convert.ToString(P.Long());
                    label18.Text = Convert.ToString(P.CeldasLibres());
                }
                else
                {
                    MessageBox.Show("El formato del valor ingresado es incorrecto ");
                }
            }
            else
                MessageBox.Show("Cola llena ");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (P.Vacia() != true)
            {
                P.Delete();
                label9.Text = P.Imprimir();
                label17.Text = Convert.ToString(P.Frente());
                label15.Text = Convert.ToString(P.Atras());
                label16.Text = Convert.ToString(P.Long());
                label18.Text = Convert.ToString(P.CeldasLibres());
            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            P.Drop();
            label9.Text = P.Imprimir();
            label17.Text = "";
            label15.Text = "";
            label16.Text = "";
            label18.Text = Convert.ToString(P.CeldasLibres());
            textBox1.Text = "";          
        }

        private void button9_Click(object sender, EventArgs e)
        {
            P = P.inversa(P);
            label9.Text = P.Imprimir();
            label17.Text = Convert.ToString(P.Frente());
            label15.Text = Convert.ToString(P.Atras());
            label16.Text = Convert.ToString(P.Long());
            label18.Text = Convert.ToString(P.CeldasLibres());
        }

        private void button10_Click(object sender, EventArgs e)
        {
            if ((P.Long() * 2) > clsColaC.MAX)
            {
                MessageBox.Show("No se puede duplicar la Cola Circular porque excede la capacidad de la Cola Circular que es: " + clsColaC.MAX);
            }
            else
            {
                P = P.duplica(P);
                label9.Text = P.Imprimir();
                label17.Text = Convert.ToString(P.Frente());
                label15.Text = Convert.ToString(P.Atras());
                label16.Text = Convert.ToString(P.Long());
                label18.Text = Convert.ToString(P.CeldasLibres());
            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (P.Vacia() != true)
            {
                string cad = textBox1.Text;
                //string cad1 = InputBox("");
                int valor;
                bool exito = int.TryParse(cad, out valor);
                if (exito)
                {
                    if (valor > P.Long())
                    {
                        MessageBox.Show("No puede borrar " + valor + " elementos porque en la Cola Circular P solo hay " + Q.Long() + " elementos");
                    }
                    else
                    {
                        P.descola((valor));
                        label9.Text = P.Imprimir();
                        label17.Text = Convert.ToString(P.Frente());
                        label15.Text = Convert.ToString(P.Atras());
                        label16.Text = Convert.ToString(P.Long());
                        label18.Text = Convert.ToString(P.CeldasLibres());
                    }
                }
                else
                {
                    MessageBox.Show("El formato del valor ingresado es incorrecto ");
                }
            }
            else
                MessageBox.Show("Cola Vacia ");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if ((Q.Long() + P.Long()) > clsColaC.MAX)
            {
                MessageBox.Show("No se puede concatenar las Colas Circulares Q y P porque excede la capacidad de la Cola Circular que es: " + clsColaC.MAX);
            }
            else
            {
                C = C.concatena(Q, P);
                label20.Text = C.Imprimir();
                label28.Text = Convert.ToString(C.Frente());
                label26.Text = Convert.ToString(C.Atras());
                label27.Text = Convert.ToString(C.Long());
                label29.Text = Convert.ToString(C.CeldasLibres());
            }            
        }
    }
}
