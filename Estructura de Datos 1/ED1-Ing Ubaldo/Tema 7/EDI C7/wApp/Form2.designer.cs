namespace Interfaz
{
    partial class Form2
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
            this.pbcociente = new System.Windows.Forms.PictureBox();
            this.label3 = new System.Windows.Forms.Label();
            this.pbresiduo = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pbcociente)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbresiduo)).BeginInit();
            this.SuspendLayout();
            // 
            // pbcociente
            // 
            this.pbcociente.Location = new System.Drawing.Point(128, 37);
            this.pbcociente.Name = "pbcociente";
            this.pbcociente.Size = new System.Drawing.Size(353, 31);
            this.pbcociente.TabIndex = 7;
            this.pbcociente.TabStop = false;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(42, 46);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(80, 20);
            this.label3.TabIndex = 6;
            this.label3.Text = "Cociente";
            // 
            // pbresiduo
            // 
            this.pbresiduo.Location = new System.Drawing.Point(128, 105);
            this.pbresiduo.Name = "pbresiduo";
            this.pbresiduo.Size = new System.Drawing.Size(353, 31);
            this.pbresiduo.TabIndex = 9;
            this.pbresiduo.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(42, 114);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(75, 20);
            this.label1.TabIndex = 8;
            this.label1.Text = "Residuo";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(508, 192);
            this.Controls.Add(this.pbresiduo);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pbcociente);
            this.Controls.Add(this.label3);
            this.Name = "Form2";
            this.Text = "Division";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form2_Paint);
            ((System.ComponentModel.ISupportInitialize)(this.pbcociente)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbresiduo)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pbcociente;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.PictureBox pbresiduo;
        private System.Windows.Forms.Label label1;
    }
}