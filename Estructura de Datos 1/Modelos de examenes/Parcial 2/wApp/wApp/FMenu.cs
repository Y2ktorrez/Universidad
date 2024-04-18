using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace wApp
{
    public partial class FMenu : Form
    {
        public FMenu()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FExamen A = new FExamen();
            A.Show();
        }

        private void FMenu_Load(object sender, EventArgs e)
        {

        }
    }
}
