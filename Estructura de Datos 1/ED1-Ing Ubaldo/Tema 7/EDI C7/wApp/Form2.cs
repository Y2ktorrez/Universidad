using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Interfaz
{
    public partial class Form2 : Form
    {
        Negocio.Polinomio cociente, residuo;

        public Form2(Negocio.Polinomio Cociente, Negocio.Polinomio Residuo)
        {
            cociente = new Negocio.Polinomio(Cociente);
            residuo = new Negocio.Polinomio(Residuo);
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        private void Form2_Paint(object sender, PaintEventArgs e)
        {
            pbcociente.Refresh();
            pbresiduo.Refresh();
            Graphics uno = pbcociente.CreateGraphics(), dos = pbresiduo.CreateGraphics();
            cociente.pintar(ref uno);
            residuo.pintar(ref dos);
        }
    }
}
