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
    public partial class FCadena : Form
    {
        public FCadena()
        {
            InitializeComponent();
        }
        clsCadena cad = new clsCadena();

        private void FCadena_Load(object sender, EventArgs e)
        {

        }

        private void boton1_Click(object sender, EventArgs e)
        {
            cad.cargar(txt.Text);
            lbltxt.Text = cad.mostrar();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label2.Text = cad.invertir();
        }
    }
}
