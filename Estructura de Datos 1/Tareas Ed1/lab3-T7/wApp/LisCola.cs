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
    public partial class LisCola : Form
    {
        public LisCola()
        {
            InitializeComponent();
        }
        clsLisCola C = new clsLisCola();

        private void button2_Click(object sender, EventArgs e)
        {
            C.Del();
            label6.Text = C.Cant().ToString();
            label8.Text = C.PrimerEle().ToString();
            label10.Text = C.UltimoEle().ToString();
            label7.Text = C.Imprimir();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string cad = textBox1.Text;
            int num;
            if (int.TryParse(cad, out num))
            {
                C.Add(num);
                label6.Text = C.Cant().ToString();
                label8.Text = C.PrimerEle().ToString();
                label10.Text = C.UltimoEle().ToString();
                label7.Text = C.Imprimir();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }
        }
    }
}
