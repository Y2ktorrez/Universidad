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
    public partial class FColaS : Form
    {
        public FColaS()
        {
            InitializeComponent();
        }

        clsColaS C = new clsColaS();
        private void FCola_Load(object sender, EventArgs e)
        {

        }    
        private void FCola_Load_1(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            string cad1 = textBox2.Text; int valor1;
            string cad2 = textBox1.Text; int valor2;
            if (int.TryParse(cad1,out valor1) && int.TryParse(cad2, out valor2))
            {
                C.Add(valor1,valor2);
                label5.Text = C.Imprimir(valor1);
                label14.Text = C.Frente(valor1).ToString();
                label17.Text = C.Atras(valor1).ToString();
                label18.Text = C.Long(valor1).ToString();
                label7.Text = C.PrintF();
                label9.Text = C.PrintR();
                label11.Text = C.PrintB();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string cad1 = textBox2.Text; int valor1;
            if (int.TryParse(cad1, out valor1))
            {
                C.Delete(valor1);
                label5.Text = C.Imprimir(valor1);
                label14.Text = C.Frente(valor1).ToString();
                label17.Text = C.Atras(valor1).ToString();
                label18.Text = C.Long(valor1).ToString();
                label7.Text = C.PrintF();
                label9.Text = C.PrintR();
                label11.Text = C.PrintB();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string cad = textBox2.Text; int valor;
            if(int.TryParse(cad, out valor))
            {
                C.Drop(valor);
                label14.Text = C.Frente(valor).ToString();
                label17.Text = C.Atras(valor).ToString();
                label18.Text = C.Long(valor).ToString();
                label7.Text = C.PrintF();
                label9.Text = C.PrintR();
                label11.Text = C.PrintB();
                label5.Text = "...";
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            string cad = textBox2.Text; int valor;
            if(int.TryParse(cad, out valor))
            {
                label5.Text = C.Imprimir(valor);
                label14.Text = C.Frente(valor).ToString();
                label17.Text = C.Atras(valor).ToString();
                label18.Text = C.Long(valor).ToString();
                label7.Text = C.PrintF();
                label9.Text = C.PrintR();
                label11.Text = C.PrintB();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }
    }
}
