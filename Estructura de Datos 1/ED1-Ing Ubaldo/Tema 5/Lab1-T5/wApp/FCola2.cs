﻿using System;
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
    public partial class FCola2 : Form
    {
        public FCola2()
        {
            InitializeComponent();
        }

        clsCola2 S = new clsCola2();

        private void FPila_Load(object sender, EventArgs e)
        {

        }

        private void cmdAdd_Click(object sender, EventArgs e)
        {
            //
            S.Add(0,Convert.ToInt32(txtEleme.Text));
            label6.Text = S.TopeS(0).ToString();
            label10.Text = S.RearS(0).ToString();
            label1.Text = S.Mostrar();
        }

        private void cmdDelete_Click(object sender, EventArgs e)
        {
            //
            S.Add(1, Convert.ToInt32(txtEleme.Text));
            label7.Text = S.TopeS(1).ToString();
            label12.Text = S.RearS(1).ToString();
            label1.Text = S.Mostrar();
        }

        private void cmdTope_Click(object sender, EventArgs e)
        {
            //
            S.Delete(0);
            label6.Text = S.TopeS(0).ToString();
            label10.Text = S.RearS(0).ToString();
            label1.Text = S.Mostrar();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //
            S.Delete(1);
            label7.Text = S.TopeS(1).ToString();
            label12.Text = S.RearS(1).ToString();
            label1.Text = S.Mostrar();
        }

    }
}
