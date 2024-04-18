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
    public partial class fNatu : Form
    {
        public fNatu()
        {
            InitializeComponent();
        }

        clsNatu N = new clsNatu();

        private void cmdDel_Click(object sender, EventArgs e)
        {
            lblNatu.Text = Convert.ToString(N.Suma(Convert.ToInt32(txtOp1.Text),Convert.ToInt32(txtOp2.Text)));
        }

        private void fNatu_Load(object sender, EventArgs e)
        {

        }

        private void cmdSucc_Click(object sender, EventArgs e)
        {
            lblNatu.Text = Convert.ToString(N.Sucesor(Convert.ToInt32(txtNatu.Text)));
        }

        private void cmdCero_Click(object sender, EventArgs e)
        {
            lblNatu.Text =Convert.ToString(N.EsCero(Convert.ToInt32(txtNatu.Text)));
        }

    }
}
