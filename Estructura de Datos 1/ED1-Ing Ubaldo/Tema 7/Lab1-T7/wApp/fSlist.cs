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
    public partial class fSlist : Form
    {
        public fSlist()
        {
            InitializeComponent();
        }

        clsLista L = new clsLista();

        private void fSlist_Load(object sender, EventArgs e)
        {

        }

        private void cmdAddPrime_Click(object sender, EventArgs e)
        {
            string cad = txtElem.Text;
            int valor;
            if (int.TryParse(cad, out valor))
            {
                L = L.AddPrimero(valor);
                lblPilax.Text = L.View();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }
        }

        private void cmdAddUlti_Click(object sender, EventArgs e)
        {
            string cad = txtElem.Text;
            int valor;
            if (int.TryParse(cad, out valor))
            {
                L = L.AddUltimo(valor);
                lblPilax.Text = L.View();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }
        }

        private void AddAnte_Click(object sender, EventArgs e)
        {
            string cad1 = txtElem.Text;
            int valor1;
            string cad2 = txtElemx.Text;
            int valor2;
            if ((int.TryParse(cad1, out valor1)) && (int.TryParse(cad2, out valor2)))
            {
                L = L.AddAntes(valor1, valor2);
                lblPilax.Text = L.View();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }     
        }

        private void AddDespues_Click(object sender, EventArgs e)
        {
            string cad1 = txtElem.Text;
            int valor1;
            string cad2 = txtElemx.Text;
            int valor2;
            if ((int.TryParse(cad1, out valor1)) && (int.TryParse(cad2, out valor2)))
            {
                L = L.AddDespues(valor1, valor2);
                lblPilax.Text = L.View();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }        
        }

        private void DelNodo_Click(object sender, EventArgs e)
        {
            string cad = txtElemx.Text;
            int valor;
            if (int.TryParse(cad, out valor))
            {
                L = L.Delete(valor);
                lblPilax.Text = L.View();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }
        }

        private void DelUlti_Click(object sender, EventArgs e)
        {
            L=L.DelUltimo();
            lblPilax.Text = L.View();

        }

        private void cmdDelTope_Click(object sender, EventArgs e)
        {
            L.DelPrimero();
            lblPilax.Text = L.View();
        }

        private void cmdView_Click(object sender, EventArgs e)
        {
            lblPilax.Text = L.View();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {
            string cad = txtElemx.Text;
            int valor;
            if(int.TryParse(cad, out valor))
            {
                L = L.Ordenar(valor);
                lblPilax.Text = L.View();
            }
            else
            {
                MessageBox.Show("Ingrese otro valor ");
            }
        }
    }
}
