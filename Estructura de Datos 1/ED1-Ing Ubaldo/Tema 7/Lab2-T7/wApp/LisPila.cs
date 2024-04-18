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
    public partial class LisPila : Form
    {
        public LisPila()
        {
            InitializeComponent();
        }
        clsLisPila P = new cApp.clsLisPila();

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string cad = textBox1.Text;
            int num;
            if (int.TryParse(cad, out num))
            {
                P.Add(num);
                label6.Text = P.Cant().ToString();
                label8.Text = P.PrimerEle().ToString();
                label10.Text = P.UltimoEle().ToString();
                label7.Text = P.Imprimir();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            P.Del();
            label6.Text = P.Cant().ToString();
            label8.Text = P.PrimerEle().ToString();
            label10.Text = P.UltimoEle().ToString();
            label7.Text = P.Imprimir();
        }
    }
}
