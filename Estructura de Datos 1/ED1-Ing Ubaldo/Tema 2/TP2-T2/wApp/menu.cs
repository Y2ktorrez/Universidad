using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace wApp
{
    public partial class menu : Form
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new menu());
          
        }

        public menu()
        {
            InitializeComponent();
        }

        private void main_Load(object sender, EventArgs e)
        {

        }

        private void TadGeom_Click(object sender, EventArgs e)
        {
            //fDibujo forDibujo = new fDibujo();
            //forDibujo.Show();
        }

        private void TadNatu_Click(object sender, EventArgs e)
        {
            fNatu forNatu = new fNatu();
            forNatu.Show();
        }

        private void TadPoly_Click(object sender, EventArgs e)
        {
            FPolyExa forPoly = new FPolyExa();
            forPoly.Show();
        }

        private void TadPila_Click(object sender, EventArgs e)
        {
            //FPila forPila = new FPila();
            //forPila.Show();
        }

        private void cmdLista_Click(object sender, EventArgs e)
        {
            //fSlist forSlist = new fSlist();
            //forSlist.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //FSparce forSparce = new FSparce();
            //forSparce.Show();
        }

        private void cmdCola_Click(object sender, EventArgs e)
        {
            //FCola forCola = new FCola();
            //forCola.Show();
        }

        private void cmdColaC_Click(object sender, EventArgs e)
        {
            //FColaC forColaC = new FColaC();
            //forColaC.Show();
        }

        private void cmdPolyExa_Click(object sender, EventArgs e)
        {
            //FPolyExa forPolyExa = new FPolyExa();
            //forPolyExa.Show();
        }
       
     
    }
}
