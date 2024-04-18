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
    public partial class LisPoly : Form
    {
        public LisPoly()
        {
            InitializeComponent();
        }
        clsLisPoly P = new clsLisPoly();
        private void LisPoly_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string cadE = textBox1.Text;
            int numE;
            string cadC = textBox2.Text;
            int numC;
            if((int.TryParse(cadE, out numE)) && (int.TryParse(cadC, out numC)))
            {
                P.Add(numE,numC);
                label6.Text = P.Cant().ToString();
                label7.Text = P.Imprimir();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string cad = textBox1.Text;
            int num;
            if(int.TryParse(cad, out num))
            {
                P.Delete(num);
                label6.Text = P.Cant().ToString();
                label7.Text = P.Imprimir();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }
        }
    }
}
