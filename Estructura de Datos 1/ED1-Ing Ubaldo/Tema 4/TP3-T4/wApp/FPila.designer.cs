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
            this.cmdAdd = new System.Windows.Forms.Button();
            this.txtEleme = new System.Windows.Forms.TextBox();
            this.cmdDelete = new System.Windows.Forms.Button();
            this.cmdTope = new System.Windows.Forms.Button();
            this.lblTope = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.flowLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // cmdAdd
            // 
            this.cmdAdd.Location = new System.Drawing.Point(3, 3);
            this.cmdAdd.Name = "cmdAdd";
            this.cmdAdd.Size = new System.Drawing.Size(87, 66);
            this.cmdAdd.TabIndex = 1;
            this.cmdAdd.Text = "Add S1";
            this.cmdAdd.UseVisualStyleBackColor = true;
            this.cmdAdd.Click += new System.EventHandler(this.cmdAdd_Click);
            // 
            // txtEleme
            // 
            this.txtEleme.BackColor = System.Drawing.Color.White;
            this.txtEleme.Location = new System.Drawing.Point(375, 265);
            this.txtEleme.Name = "txtEleme";
            this.txtEleme.Size = new System.Drawing.Size(76, 23);
            this.txtEleme.TabIndex = 2;
            // 
            // cmdDelete
            // 
            this.cmdDelete.Location = new System.Drawing.Point(96, 3);
            this.cmdDelete.Name = "cmdDelete";
            this.cmdDelete.Size = new System.Drawing.Size(87, 66);
            this.cmdDelete.TabIndex = 4;
            this.cmdDelete.Text = "Add S2";
            this.cmdDelete.UseVisualStyleBackColor = true;
            this.cmdDelete.Click += new System.EventHandler(this.cmdDelete_Click);
            // 
            // cmdTope
            // 
            this.cmdTope.Location = new System.Drawing.Point(3, 75);
            this.cmdTope.Name = "cmdTope";
            this.cmdTope.Size = new System.Drawing.Size(87, 66);
            this.cmdTope.TabIndex = 5;
            this.cmdTope.Text = "Delete S1";
            this.cmdTope.UseVisualStyleBackColor = true;
            this.cmdTope.Click += new System.EventHandler(this.cmdTope_Click);
            // 
            // lblTope
            // 
            this.lblTope.AutoSize = true;
            this.lblTope.Font = new System.Drawing.Font("Consolas", 25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTope.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.lblTope.Location = new System.Drawing.Point(328, 9);
            this.lblTope.Name = "lblTope";
            this.lblTope.Size = new System.Drawing.Size(188, 40);
            this.lblTope.TabIndex = 6;
            this.lblTope.Text = "TDA PILA2";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(96, 75);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(87, 66);
            this.button1.TabIndex = 7;
            this.button1.Text = "Delete S2";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Consolas", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label1.Location = new System.Drawing.Point(380, 111);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 32);
            this.label1.TabIndex = 15;
            this.label1.Text = "...";
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.cmdAdd);
            this.flowLayoutPanel1.Controls.Add(this.cmdDelete);
            this.flowLayoutPanel1.Controls.Add(this.cmdTope);
            this.flowLayoutPanel1.Controls.Add(this.button1);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(319, 309);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(188, 149);
            this.flowLayoutPanel1.TabIndex = 16;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label2.Location = new System.Drawing.Point(296, 179);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 20);
            this.label2.TabIndex = 15;
            this.label2.Text = "S1";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label3.Location = new System.Drawing.Point(475, 179);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 20);
            this.label3.TabIndex = 15;
            this.label3.Text = "S2";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label4.Location = new System.Drawing.Point(278, 206);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(58, 20);
            this.label4.TabIndex = 15;
            this.label4.Text = "Top1 =";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label5.Location = new System.Drawing.Point(458, 206);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(58, 20);
            this.label5.TabIndex = 15;
            this.label5.Text = "Top2 =";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label6.Location = new System.Drawing.Point(342, 205);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(21, 20);
            this.label6.TabIndex = 15;
            this.label6.Text = "...";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label7.Location = new System.Drawing.Point(522, 205);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(21, 20);
            this.label7.TabIndex = 15;
            this.label7.Text = "...";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Consolas", 8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.label8.Location = new System.Drawing.Point(383, 249);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(55, 13);
            this.label8.TabIndex = 15;
            this.label8.Text = "Elemento";
            // 
            // FPila
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.ClientSize = new System.Drawing.Size(853, 480);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.lblTope);
            this.Controls.Add(this.txtEleme);
            this.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "FPila";
            this.Text = "FPila";
            this.Load += new System.EventHandler(this.FPila_Load);
            this.flowLayoutPanel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button cmdAdd;
        private System.Windows.Forms.TextBox txtEleme;
        private System.Windows.Forms.Button cmdDelete;
        private System.Windows.Forms.Button cmdTope;
        private System.Windows.Forms.Label lblTope;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
    }
}