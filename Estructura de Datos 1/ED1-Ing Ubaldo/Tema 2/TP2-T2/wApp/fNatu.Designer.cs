namespace wApp
{
    partial class fNatu
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
            this.txtNatu = new System.Windows.Forms.TextBox();
            this.cmdSucc = new System.Windows.Forms.Button();
            this.lblNatu = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cmdSum = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.cmdCero = new System.Windows.Forms.Button();
            this.txtOp1 = new System.Windows.Forms.TextBox();
            this.txtOp2 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // txtNatu
            // 
            this.txtNatu.Location = new System.Drawing.Point(81, 137);
            this.txtNatu.Name = "txtNatu";
            this.txtNatu.Size = new System.Drawing.Size(70, 20);
            this.txtNatu.TabIndex = 0;
            // 
            // cmdSucc
            // 
            this.cmdSucc.Location = new System.Drawing.Point(197, 135);
            this.cmdSucc.Name = "cmdSucc";
            this.cmdSucc.Size = new System.Drawing.Size(75, 23);
            this.cmdSucc.TabIndex = 1;
            this.cmdSucc.Text = "Succ";
            this.cmdSucc.UseVisualStyleBackColor = true;
            this.cmdSucc.Click += new System.EventHandler(this.cmdSucc_Click);
            // 
            // lblNatu
            // 
            this.lblNatu.AutoSize = true;
            this.lblNatu.Location = new System.Drawing.Point(357, 144);
            this.lblNatu.Name = "lblNatu";
            this.lblNatu.Size = new System.Drawing.Size(16, 13);
            this.lblNatu.TabIndex = 2;
            this.lblNatu.Text = "...";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.Red;
            this.label2.Location = new System.Drawing.Point(357, 118);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(73, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "Resultado";
            // 
            // cmdSum
            // 
            this.cmdSum.Location = new System.Drawing.Point(197, 196);
            this.cmdSum.Name = "cmdSum";
            this.cmdSum.Size = new System.Drawing.Size(75, 23);
            this.cmdSum.TabIndex = 4;
            this.cmdSum.Text = "Sum";
            this.cmdSum.UseVisualStyleBackColor = true;
            this.cmdSum.Click += new System.EventHandler(this.cmdDel_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.Blue;
            this.label3.Location = new System.Drawing.Point(215, 26);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(88, 19);
            this.label3.TabIndex = 5;
            this.label3.Text = "TAD Natu";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.Blue;
            this.label4.Location = new System.Drawing.Point(78, 67);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(67, 16);
            this.label4.TabIndex = 6;
            this.label4.Text = "Defincion";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.Blue;
            this.label5.Location = new System.Drawing.Point(78, 100);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(88, 16);
            this.label5.TabIndex = 7;
            this.label5.Text = "Operaciones";
            // 
            // cmdCero
            // 
            this.cmdCero.Location = new System.Drawing.Point(197, 164);
            this.cmdCero.Name = "cmdCero";
            this.cmdCero.Size = new System.Drawing.Size(75, 23);
            this.cmdCero.TabIndex = 8;
            this.cmdCero.Text = "EsCero";
            this.cmdCero.UseVisualStyleBackColor = true;
            this.cmdCero.Click += new System.EventHandler(this.cmdCero_Click);
            // 
            // txtOp1
            // 
            this.txtOp1.Location = new System.Drawing.Point(43, 196);
            this.txtOp1.Name = "txtOp1";
            this.txtOp1.Size = new System.Drawing.Size(64, 20);
            this.txtOp1.TabIndex = 9;
            // 
            // txtOp2
            // 
            this.txtOp2.Location = new System.Drawing.Point(131, 196);
            this.txtOp2.Name = "txtOp2";
            this.txtOp2.Size = new System.Drawing.Size(60, 20);
            this.txtOp2.TabIndex = 10;
            // 
            // fNatu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(628, 396);
            this.Controls.Add(this.txtOp2);
            this.Controls.Add(this.txtOp1);
            this.Controls.Add(this.cmdCero);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.cmdSum);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.lblNatu);
            this.Controls.Add(this.cmdSucc);
            this.Controls.Add(this.txtNatu);
            this.Name = "fNatu";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.fNatu_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtNatu;
        private System.Windows.Forms.Button cmdSucc;
        private System.Windows.Forms.Label lblNatu;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button cmdSum;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button cmdCero;
        private System.Windows.Forms.TextBox txtOp1;
        private System.Windows.Forms.TextBox txtOp2;
    }
}