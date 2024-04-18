namespace wApp
{
    partial class menu
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
            this.TadNatu = new System.Windows.Forms.Button();
            this.TadPila = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.TadGeom = new System.Windows.Forms.Button();
            this.TadPoly = new System.Windows.Forms.Button();
            this.cmdLista = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.cmdCola = new System.Windows.Forms.Button();
            this.cmdColaC = new System.Windows.Forms.Button();
            this.cmdPolyExa = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // TadNatu
            // 
            this.TadNatu.Location = new System.Drawing.Point(12, 60);
            this.TadNatu.Name = "TadNatu";
            this.TadNatu.Size = new System.Drawing.Size(75, 23);
            this.TadNatu.TabIndex = 0;
            this.TadNatu.Text = "TAD Natu";
            this.TadNatu.UseVisualStyleBackColor = true;
            this.TadNatu.Click += new System.EventHandler(this.TadNatu_Click);
            // 
            // TadPila
            // 
            this.TadPila.Location = new System.Drawing.Point(12, 147);
            this.TadPila.Name = "TadPila";
            this.TadPila.Size = new System.Drawing.Size(75, 23);
            this.TadPila.TabIndex = 1;
            this.TadPila.Text = "TAD Pila";
            this.TadPila.UseVisualStyleBackColor = true;
            this.TadPila.Click += new System.EventHandler(this.TadPila_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Blue;
            this.label1.Location = new System.Drawing.Point(130, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 23);
            this.label1.TabIndex = 2;
            this.label1.Text = "Mis TAD";
            // 
            // TadGeom
            // 
            this.TadGeom.Location = new System.Drawing.Point(134, 59);
            this.TadGeom.Name = "TadGeom";
            this.TadGeom.Size = new System.Drawing.Size(75, 23);
            this.TadGeom.TabIndex = 3;
            this.TadGeom.Text = "TAD Geom";
            this.TadGeom.UseVisualStyleBackColor = true;
            this.TadGeom.Click += new System.EventHandler(this.TadGeom_Click);
            // 
            // TadPoly
            // 
            this.TadPoly.Location = new System.Drawing.Point(12, 89);
            this.TadPoly.Name = "TadPoly";
            this.TadPoly.Size = new System.Drawing.Size(75, 23);
            this.TadPoly.TabIndex = 4;
            this.TadPoly.Text = "TAD Poly";
            this.TadPoly.UseVisualStyleBackColor = true;
            this.TadPoly.Click += new System.EventHandler(this.TadPoly_Click);
            // 
            // cmdLista
            // 
            this.cmdLista.Location = new System.Drawing.Point(12, 234);
            this.cmdLista.Name = "cmdLista";
            this.cmdLista.Size = new System.Drawing.Size(75, 23);
            this.cmdLista.TabIndex = 5;
            this.cmdLista.Text = "TAD Lista";
            this.cmdLista.UseVisualStyleBackColor = true;
            this.cmdLista.Click += new System.EventHandler(this.cmdLista_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 118);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 6;
            this.button1.Text = "TAD Sparce";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // cmdCola
            // 
            this.cmdCola.Location = new System.Drawing.Point(12, 176);
            this.cmdCola.Name = "cmdCola";
            this.cmdCola.Size = new System.Drawing.Size(75, 23);
            this.cmdCola.TabIndex = 7;
            this.cmdCola.Text = "TAD Cola";
            this.cmdCola.UseVisualStyleBackColor = true;
            this.cmdCola.Click += new System.EventHandler(this.cmdCola_Click);
            // 
            // cmdColaC
            // 
            this.cmdColaC.Location = new System.Drawing.Point(12, 205);
            this.cmdColaC.Name = "cmdColaC";
            this.cmdColaC.Size = new System.Drawing.Size(75, 23);
            this.cmdColaC.TabIndex = 8;
            this.cmdColaC.Text = "TAD ColaC";
            this.cmdColaC.UseVisualStyleBackColor = true;
            this.cmdColaC.Click += new System.EventHandler(this.cmdColaC_Click);
            // 
            // cmdPolyExa
            // 
            this.cmdPolyExa.Location = new System.Drawing.Point(134, 89);
            this.cmdPolyExa.Name = "cmdPolyExa";
            this.cmdPolyExa.Size = new System.Drawing.Size(84, 23);
            this.cmdPolyExa.TabIndex = 9;
            this.cmdPolyExa.Text = "TAD Poly Exa";
            this.cmdPolyExa.UseVisualStyleBackColor = true;
            this.cmdPolyExa.Click += new System.EventHandler(this.cmdPolyExa_Click);
            // 
            // menu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(368, 327);
            this.Controls.Add(this.cmdPolyExa);
            this.Controls.Add(this.cmdColaC);
            this.Controls.Add(this.cmdCola);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.cmdLista);
            this.Controls.Add(this.TadPoly);
            this.Controls.Add(this.TadGeom);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.TadPila);
            this.Controls.Add(this.TadNatu);
            this.Name = "menu";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.main_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button TadNatu;
        private System.Windows.Forms.Button TadPila;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button TadGeom;
        private System.Windows.Forms.Button TadPoly;
        private System.Windows.Forms.Button cmdLista;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button cmdCola;
        private System.Windows.Forms.Button cmdColaC;
        private System.Windows.Forms.Button cmdPolyExa;
    }
}