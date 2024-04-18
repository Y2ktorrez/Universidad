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
    public partial class FAgenda : Form
    {
        public FAgenda()
        {
            InitializeComponent();
        }
        ClsAgenda Agn = new ClsAgenda();

        private void FAgenda_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Agn.guardar(textBox1.Text,textBox2.Text,textBox3.Text,textBox4.Text,textBox5.Text);
            label7.Text = Agn.mostrar();
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }
    }
}
