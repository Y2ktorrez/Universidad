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
    public partial class FColaSC : Form
    {
        public FColaSC()
        {
            InitializeComponent();
        }
        clsColaS_Circular SC = new cApp.clsColaS_Circular();
        clsColaC C = new cApp.clsColaC();
        private void FColaSC_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string cad1 = textBox2.Text; int valor1;
            string cad2 = textBox1.Text; int valor2;
            if (int.TryParse(cad1, out valor1) && int.TryParse(cad2, out valor2))
            {
                SC.Add(valor1, valor2);
                label5.Text = SC.Imprimir3(valor1);
                label14.Text = SC.Frente(valor1).ToString();
                label17.Text = SC.Atras(valor1).ToString();
                label18.Text = SC.Long(valor1).ToString();
                label7.Text = SC.PrintF();
                label9.Text = SC.PrintR();
                label11.Text = SC.PrintB();
                label10.Text = SC.PrintC();
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
                SC.Delete(valor1);
                label5.Text = SC.Imprimir3(valor1);
                label14.Text = SC.Frente(valor1).ToString();
                label17.Text = SC.Atras(valor1).ToString();
                label18.Text = SC.Long(valor1).ToString();
                label7.Text = SC.PrintF();
                label9.Text = SC.PrintR();
                label11.Text = SC.PrintB();
                label10.Text = SC.PrintC();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            string cad = textBox2.Text; int valor;
            if (int.TryParse(cad, out valor))
            {
                label5.Text = SC.Imprimir3(valor);
                label14.Text = SC.Frente(valor).ToString();
                label17.Text = SC.Atras(valor).ToString();
                label18.Text = SC.Long(valor).ToString();
                label7.Text = SC.PrintF();
                label9.Text = SC.PrintR();
                label11.Text = SC.PrintB();
                label10.Text = SC.PrintC();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }       

        private void button5_Click(object sender, EventArgs e)
        {
            string cad1 = textBox2.Text; int valor1;
            string cad2 = textBox1.Text; int valor2;
            if ((int.TryParse(cad1, out valor1)) && (int.TryParse(cad2, out valor2)))
            {
                SC.descola(valor1,valor2);
                label5.Text = SC.Imprimir3(valor1);
                label14.Text = SC.Frente(valor1).ToString();
                label17.Text = SC.Atras(valor1).ToString();
                label18.Text = SC.Long(valor1).ToString();
                label7.Text = SC.PrintF();
                label9.Text = SC.PrintR();
                label11.Text = SC.PrintB();
                label10.Text = SC.PrintC();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            string cad1 = textBox2.Text; int valor1;
            if (int.TryParse(cad1, out valor1))
            {
                SC.inversa(valor1);
                label5.Text = SC.Imprimir3(valor1);
                label14.Text = SC.Frente(valor1).ToString();
                label17.Text = SC.Atras(valor1).ToString();
                label18.Text = SC.Long(valor1).ToString();
                label7.Text = SC.PrintF();
                label9.Text = SC.PrintR();
                label11.Text = SC.PrintB();
                label10.Text = SC.PrintC();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            string cad1 = textBox2.Text; int valor1;
            if (int.TryParse(cad1, out valor1))
            {
                SC.duplica(valor1);
                label5.Text = SC.Imprimir3(valor1);
                label14.Text = SC.Frente(valor1).ToString();
                label17.Text = SC.Atras(valor1).ToString();
                label18.Text = SC.Long(valor1).ToString();
                label7.Text = SC.PrintF();
                label9.Text = SC.PrintR();
                label11.Text = SC.PrintB();
                label10.Text = SC.PrintC();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            string cad1 = textBox3.Text; int valor1;
            string cad2 = textBox4.Text; int valor2;
            if ((int.TryParse(cad1, out valor1)) && (int.TryParse(cad2, out valor2)))
            {
                C = SC.concatena(SC,valor1, valor2);
                label21.Text = C.Imprimir();
                /*label5.Text = SC.Imprimir3(valor1);
                label14.Text = SC.Frente(valor1).ToString();
                label17.Text = SC.Atras(valor1).ToString();
                label18.Text = SC.Long(valor1).ToString();
                label7.Text = SC.PrintF();
                label9.Text = SC.PrintR();
                label11.Text = SC.PrintB();
                label10.Text = SC.PrintC();*/
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            string cad1 = textBox3.Text; int valor1;
            string cad2 = textBox4.Text; int valor2;
            if ((int.TryParse(cad1, out valor1)) && (int.TryParse(cad2, out valor2)))
            {
                C = SC.mezcla(SC, valor1, valor2);
                label21.Text = C.Imprimir();               
            }
            else
            {
                MessageBox.Show("Ingrese otro valor");
            }
        }
    }
}
