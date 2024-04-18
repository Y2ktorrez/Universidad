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
    public partial class FConjunto : Form
    {
        public FConjunto()
        {
            InitializeComponent();
        }
        ClsConj conj = new ClsConj();

        private void FConjunto_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            conj.cargar(Convert.ToInt32(textBox1.Text));
            label4.Text = conj.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label5.Text = Convert.ToString(conj.pertenece(Convert.ToInt32(textBox1.Text)));
        }
    }
}
