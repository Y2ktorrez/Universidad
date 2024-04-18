namespace wApp
{
    partial class FPila
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.CmdDrop = new System.Windows.Forms.Button();
            this.cmdAdd = new System.Windows.Forms.Button();
            this.txtEleme = new System.Windows.Forms.TextBox();
            this.lblPila = new System.Windows.Forms.Label();
            this.cmdDelete = new System.Windows.Forms.Button();
            this.lblTope = new System.Windows.Forms.Label();
            this.lblLong = new System.Windows.Forms.Label();
            this.lblRear = new System.Windows.Forms.Label();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button5 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.flowLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // CmdDrop
            // 
            this.CmdDrop.Location = new System.Drawing.Point(3, 67);
            this.CmdDrop.Name = "CmdDrop";
            this.CmdDrop.Size = new System.Drawing.Size(75, 58);
            this.CmdDrop.TabIndex = 0;
            this.CmdDrop.Text = "Destruir";
            this.CmdDrop.UseVisualStyleBackColor = true;
            this.CmdDrop.Click += new System.EventHandler(this.CmdCreaS_Click);
            // 
            // cmdAdd
            // 
            this.cmdAdd.Location = new System.Drawing.Point(3, 3);
            this.cmdAdd.Name = "cmdAdd";
            this.cmdAdd.Size = new System.Drawing.Size(75, 58);
            this.cmdAdd.TabIndex = 1;
            this.cmdAdd.Text = "Adicionar";
            this.cmdAdd.UseVisualStyleBackColor = true;
            this.cmdAdd.Click += new System.EventHandler(this.cmdAdd_Click);
            // 
            // txtEleme
            // 
            this.txtEleme.BackColor = System.Drawing.SystemColors.ControlLight;
            this.txtEleme.Location = new System.Drawing.Point(353, 137);
            this.txtEleme.Name = "txtEleme";
            this.txtEleme.Size = new System.Drawing.Size(53, 20);
            this.txtEleme.TabIndex = 2;
            // 
            // lblPila
            // 
            this.lblPila.AutoSize = true;
            this.lblPila.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPila.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.lblPila.Location = new System.Drawing.Point(513, 142);
            this.lblPila.Name = "lblPila";
            this.lblPila.Size = new System.Drawing.Size(36, 19);
            this.lblPila.TabIndex = 3;
            this.lblPila.Text = "...";
            // 
            // cmdDelete
            // 
            this.cmdDelete.Location = new System.Drawing.Point(84, 3);
            this.cmdDelete.Name = "cmdDelete";
            this.cmdDelete.Size = new System.Drawing.Size(75, 58);
            this.cmdDelete.TabIndex = 4;
            this.cmdDelete.Text = "Borrar";
            this.cmdDelete.UseVisualStyleBackColor = true;
            this.cmdDelete.Click += new System.EventHandler(this.cmdDelete_Click);
            // 
            // lblTope
            // 
            this.lblTope.AutoSize = true;
            this.lblTope.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.lblTope.Location = new System.Drawing.Point(504, 220);
            this.lblTope.Name = "lblTope";
            this.lblTope.Size = new System.Drawing.Size(25, 13);
            this.lblTope.TabIndex = 6;
            this.lblTope.Text = "...";
            // 
            // lblLong
            // 
            this.lblLong.AutoSize = true;
            this.lblLong.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.lblLong.Location = new System.Drawing.Point(504, 185);
            this.lblLong.Name = "lblLong";
            this.lblLong.Size = new System.Drawing.Size(25, 13);
            this.lblLong.TabIndex = 8;
            this.lblLong.Text = "...";
            // 
            // lblRear
            // 
            this.lblRear.AutoSize = true;
            this.lblRear.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.lblRear.Location = new System.Drawing.Point(504, 252);
            this.lblRear.Name = "lblRear";
            this.lblRear.Size = new System.Drawing.Size(25, 13);
            this.lblRear.TabIndex = 10;
            this.lblRear.Text = "...";
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(253, 318);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 58);
            this.button3.TabIndex = 11;
            this.button3.Text = "Promedio";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(172, 318);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 58);
            this.button4.TabIndex = 12;
            this.button4.Text = "Suma";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label1.Location = new System.Drawing.Point(514, 341);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(25, 13);
            this.label1.TabIndex = 13;
            this.label1.Text = "...";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Consolas", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label2.Location = new System.Drawing.Point(398, 337);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(96, 17);
            this.label2.TabIndex = 14;
            this.label2.Text = "Resultado :";
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(84, 67);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 58);
            this.button5.TabIndex = 15;
            this.button5.Text = "Invertir";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label3.Location = new System.Drawing.Point(514, 295);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(25, 13);
            this.label3.TabIndex = 16;
            this.label3.Text = "...";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Consolas", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label4.Location = new System.Drawing.Point(390, 41);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(116, 28);
            this.label4.TabIndex = 17;
            this.label4.Text = "TAD PILA";
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.cmdAdd);
            this.flowLayoutPanel1.Controls.Add(this.cmdDelete);
            this.flowLayoutPanel1.Controls.Add(this.CmdDrop);
            this.flowLayoutPanel1.Controls.Add(this.button5);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(169, 121);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(165, 133);
            this.flowLayoutPanel1.TabIndex = 18;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Consolas", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label5.Location = new System.Drawing.Point(426, 140);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(70, 22);
            this.label5.TabIndex = 19;
            this.label5.Text = "PILA =";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label6.Location = new System.Drawing.Point(439, 220);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(43, 13);
            this.label6.TabIndex = 20;
            this.label6.Text = "Tope :";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label7.Location = new System.Drawing.Point(431, 185);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(67, 13);
            this.label7.TabIndex = 21;
            this.label7.Text = "Longitud :";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label8.Location = new System.Drawing.Point(439, 252);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(43, 13);
            this.label8.TabIndex = 22;
            this.label8.Text = "Rear :";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label10.Location = new System.Drawing.Point(350, 121);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(55, 13);
            this.label10.TabIndex = 24;
            this.label10.Text = "Elemento";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label9.Location = new System.Drawing.Point(398, 295);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(103, 13);
            this.label9.TabIndex = 25;
            this.label9.Text = "Pila Invertida =";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(172, 396);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(156, 58);
            this.button1.TabIndex = 11;
            this.button1.Text = "Validar Expresión";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(353, 421);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(196, 33);
            this.textBox1.TabIndex = 26;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label11.Location = new System.Drawing.Point(427, 469);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(36, 19);
            this.label11.TabIndex = 13;
            this.label11.Text = "...";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label12.Location = new System.Drawing.Point(379, 396);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(127, 13);
            this.label12.TabIndex = 13;
            this.label12.Text = "Expresión Matematica";
            // 
            // FPila
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(1001, 542);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lblRear);
            this.Controls.Add(this.lblLong);
            this.Controls.Add(this.lblTope);
            this.Controls.Add(this.lblPila);
            this.Controls.Add(this.txtEleme);
            this.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "FPila";
            this.Text = "FPila";
            this.Load += new System.EventHandler(this.FPila_Load);
            this.flowLayoutPanel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button CmdDrop;
        private System.Windows.Forms.Button cmdAdd;
        private System.Windows.Forms.TextBox txtEleme;
        private System.Windows.Forms.Label lblPila;
        private System.Windows.Forms.Button cmdDelete;
        private System.Windows.Forms.Label lblTope;
        private System.Windows.Forms.Label lblLong;
        private System.Windows.Forms.Label lblRear;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
    }
}