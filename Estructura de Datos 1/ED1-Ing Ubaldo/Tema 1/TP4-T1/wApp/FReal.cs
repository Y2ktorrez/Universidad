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
    public partial class FReal : Form
    {
        public FReal()
        {
            InitializeComponent();
        }
        clsReal R = new cApp.clsReal();

        private void FReal_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            label4.Text = Convert.ToString(R.suma(Convert.ToDouble(textBox1.Text),Convert.ToDouble(textBox2.Text)));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label4.Text = Convert.ToString(R.restar(Convert.ToDouble(textBox1.Text), Convert.ToDouble(textBox2.Text)));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label4.Text = Convert.ToString(R.multiplicacion(Convert.ToDouble(textBox1.Text), Convert.ToDouble(textBox2.Text)));
        }
    }
}
