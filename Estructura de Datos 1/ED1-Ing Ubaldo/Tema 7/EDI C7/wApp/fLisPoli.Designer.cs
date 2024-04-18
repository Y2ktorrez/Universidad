
namespace wApp
{
    partial class fLisPoli
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
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.Salida1 = new System.Windows.Forms.Label();
            this.Salida2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(12, 108);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(157, 40);
            this.button1.TabIndex = 0;
            this.button1.Text = "Prueba";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Black;
            this.label1.Location = new System.Drawing.Point(210, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(152, 25);
            this.label1.TabIndex = 3;
            this.label1.Text = "TAD Poli-Lista";
            // 
            // Salida1
            // 
            this.Salida1.AutoSize = true;
            this.Salida1.ForeColor = System.Drawing.Color.Crimson;
            this.Salida1.Location = new System.Drawing.Point(222, 108);
            this.Salida1.Name = "Salida1";
            this.Salida1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Salida1.Size = new System.Drawing.Size(72, 17);
            this.Salida1.TabIndex = 4;
            this.Salida1.Text = "................";
            // 
            // Salida2
            // 
            this.Salida2.AutoSize = true;
            this.Salida2.ForeColor = System.Drawing.Color.Crimson;
            this.Salida2.Location = new System.Drawing.Point(222, 178);
            this.Salida2.Name = "Salida2";
            this.Salida2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Salida2.Size = new System.Drawing.Size(72, 17);
            this.Salida2.TabIndex = 5;
            this.Salida2.Text = "................";
            // 
            // fLisPoli
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(776, 456);
            this.Controls.Add(this.Salida2);
            this.Controls.Add(this.Salida1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Name = "fLisPoli";
            this.Text = "fLisPoli";
            this.Load += new System.EventHandler(this.fLisPoli_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label Salida1;
        private System.Windows.Forms.Label Salida2;
    }
}