﻿using System;
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

              
        private void cmdCola_Click(object sender, EventArgs e)
        {
            FColaS forCola = new FColaS();
            forCola.Show();
            MessageBox.Show("Para este ejemplo las Colas son 0-1-2. Tomar en cuenta por favor ");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FColaSC forColaSC = new FColaSC();
            forColaSC.Show();
            MessageBox.Show("Para este ejemplo las Colas son 0-1-2. Tomar en cuenta por favor ");
        }
    }
}