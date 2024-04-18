using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using cApp;

namespace wApp
{
    public partial class FExamen : Form
    {
        public FExamen()
        {
            InitializeComponent();
        }
        clsLista A = new clsLista();
        clsCola B1 = new clsCola();
        clsCola B2 = new clsCola();
        clsPila C1 = new clsPila();
        clsPila C2 = new clsPila();
        private void button1_Click(object sender, EventArgs e)
        {
            A.CargarDesde2Pilas(C1, C2);
            lblmostrar5.Text = A.View();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int x = Convert.ToInt32(txtcola.Text);
            B1.Add(x);
            lblmostrar1.Text = B1.Imprimir();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int x = Convert.ToInt32(txtpila.Text);
            C1.Add(x);
            lblmostrar3.Text = C1.Imprimir();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            int x = Convert.ToInt32(txtcola.Text);
            B2.Add(x);
            lblmostrar2.Text = B2.Imprimir();
        }

        private void button4_Click(object sender, EventArgs e)
        {   
            int x = Convert.ToInt32(txtpila.Text);
            C2.Add(x);
            lblmostrar4.Text = C2.Imprimir();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            A.CargarDesde2Colas(B1, B2);
            lblmostrar5.Text = A.View();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            A.CargarDesdePilayCola(C1, B1);
            lblmostrar5.Text = A.View();
        }
    }
}
