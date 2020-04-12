namespace Car
{
    partial class Form1
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
            this.accelerate = new System.Windows.Forms.Button();
            this.brake = new System.Windows.Forms.Button();
            this.SpeedBox = new System.Windows.Forms.TextBox();
            this.CurrentSpeed = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // accelerate
            // 
            this.accelerate.Location = new System.Drawing.Point(151, 271);
            this.accelerate.Name = "accelerate";
            this.accelerate.Size = new System.Drawing.Size(116, 23);
            this.accelerate.TabIndex = 0;
            this.accelerate.Text = "accelerate";
            this.accelerate.UseVisualStyleBackColor = true;
            this.accelerate.Click += new System.EventHandler(this.accelerate_Click);
            // 
            // brake
            // 
            this.brake.Location = new System.Drawing.Point(513, 271);
            this.brake.Name = "brake";
            this.brake.Size = new System.Drawing.Size(75, 23);
            this.brake.TabIndex = 1;
            this.brake.Text = "brake";
            this.brake.UseVisualStyleBackColor = true;
            this.brake.Click += new System.EventHandler(this.brake_Click);
            // 
            // SpeedBox
            // 
            this.SpeedBox.Location = new System.Drawing.Point(236, 94);
            this.SpeedBox.Name = "SpeedBox";
            this.SpeedBox.Size = new System.Drawing.Size(271, 22);
            this.SpeedBox.TabIndex = 2;
            // 
            // CurrentSpeed
            // 
            this.CurrentSpeed.AutoSize = true;
            this.CurrentSpeed.Location = new System.Drawing.Point(128, 99);
            this.CurrentSpeed.Name = "CurrentSpeed";
            this.CurrentSpeed.Size = new System.Drawing.Size(100, 17);
            this.CurrentSpeed.TabIndex = 3;
            this.CurrentSpeed.Text = "Current Speed";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.CurrentSpeed);
            this.Controls.Add(this.SpeedBox);
            this.Controls.Add(this.brake);
            this.Controls.Add(this.accelerate);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button accelerate;
        private System.Windows.Forms.Button brake;
        private System.Windows.Forms.TextBox SpeedBox;
        private System.Windows.Forms.Label CurrentSpeed;
    }
}

