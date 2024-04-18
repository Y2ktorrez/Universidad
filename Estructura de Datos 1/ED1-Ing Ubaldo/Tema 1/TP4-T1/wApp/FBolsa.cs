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
    public partial class FBolsa : Form
    {
        public FBolsa()
        {
            InitializeComponent();
        }
        ClsBolsa Bol = new ClsBolsa();

        private void FBolsa_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Bol.cargar(Convert.ToInt32(textBox2.Text),Convert.ToInt32(textBox1.Text));
            label4.Text = Bol.ToString();
        }
    }
}
