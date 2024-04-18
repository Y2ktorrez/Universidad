
namespace wApp
{
    partial class FCadena
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
            this.label3 = new System.Windows.Forms.Label();
            this.txt = new System.Windows.Forms.TextBox();
            this.boton1 = new System.Windows.Forms.Button();
            this.lbltxt = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.Blue;
            this.label3.Location = new System.Drawing.Point(300, 46);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(110, 19);
            this.label3.TabIndex = 6;
            this.label3.Text = "TAD Cadena";
            // 
            // txt
            // 
            this.txt.Location = new System.Drawing.Point(187, 142);
            this.txt.Name = "txt";
            this.txt.Size = new System.Drawing.Size(374, 20);
            this.txt.TabIndex = 7;
            // 
            // boton1
            // 
            this.boton1.Location = new System.Drawing.Point(79, 142);
            this.boton1.Name = "boton1";
            this.boton1.Size = new System.Drawing.Size(60, 23);
            this.boton1.TabIndex = 8;
            this.boton1.Text = "Cargar";
            this.boton1.UseVisualStyleBackColor = true;
            this.boton1.Click += new System.EventHandler(this.boton1_Click);
            // 
            // lbltxt
            // 
            this.lbltxt.AutoSize = true;
            this.lbltxt.Location = new System.Drawing.Point(184, 201);
            this.lbltxt.Name = "lbltxt";
            this.lbltxt.Size = new System.Drawing.Size(16, 13);
            this.lbltxt.TabIndex = 9;
            this.lbltxt.Text = "...";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(76, 201);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 13);
            this.label1.TabIndex = 10;
            this.label1.Text = "Cadena";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(79, 248);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(60, 23);
            this.button1.TabIndex = 11;
            this.button1.Text = "Invertir";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(184, 258);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(16, 13);
            this.label2.TabIndex = 12;
            this.label2.Text = "...";
            // 
            // FCadena
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lbltxt);
            this.Controls.Add(this.boton1);
            this.Controls.Add(this.txt);
            this.Controls.Add(this.label3);
            this.Name = "FCadena";
            this.Text = "FCadena";
            this.Load += new System.EventHandler(this.FCadena_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txt;
        private System.Windows.Forms.Button boton1;
        private System.Windows.Forms.Label lbltxt;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label2;
    }
}