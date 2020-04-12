namespace PetForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txtName = new System.Windows.Forms.TextBox();
            this.txtAge = new System.Windows.Forms.TextBox();
            this.txtType = new System.Windows.Forms.TextBox();
            this.rbCat = new System.Windows.Forms.RadioButton();
            this.rbDog = new System.Windows.Forms.RadioButton();
            this.btnTalk = new System.Windows.Forms.Button();
            this.btnWalk = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(100, 82);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(100, 141);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(33, 17);
            this.label2.TabIndex = 1;
            this.label2.Text = "Age";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(100, 197);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 17);
            this.label3.TabIndex = 2;
            this.label3.Text = "Type";
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(266, 76);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(129, 22);
            this.txtName.TabIndex = 3;
            // 
            // txtAge
            // 
            this.txtAge.Location = new System.Drawing.Point(266, 136);
            this.txtAge.Name = "txtAge";
            this.txtAge.Size = new System.Drawing.Size(129, 22);
            this.txtAge.TabIndex = 4;
            // 
            // txtType
            // 
            this.txtType.Location = new System.Drawing.Point(266, 192);
            this.txtType.Name = "txtType";
            this.txtType.Size = new System.Drawing.Size(129, 22);
            this.txtType.TabIndex = 5;
            // 
            // rbCat
            // 
            this.rbCat.AutoSize = true;
            this.rbCat.Location = new System.Drawing.Point(103, 282);
            this.rbCat.Name = "rbCat";
            this.rbCat.Size = new System.Drawing.Size(50, 21);
            this.rbCat.TabIndex = 6;
            this.rbCat.TabStop = true;
            this.rbCat.Text = "Cat";
            this.rbCat.UseVisualStyleBackColor = true;
            this.rbCat.Click += new System.EventHandler(this.rbCat_Click);
            // 
            // rbDog
            // 
            this.rbDog.AutoSize = true;
            this.rbDog.Location = new System.Drawing.Point(266, 282);
            this.rbDog.Name = "rbDog";
            this.rbDog.Size = new System.Drawing.Size(55, 21);
            this.rbDog.TabIndex = 7;
            this.rbDog.TabStop = true;
            this.rbDog.Text = "Dog";
            this.rbDog.UseVisualStyleBackColor = true;
            this.rbDog.Click += new System.EventHandler(this.rbDog_Click);
            // 
            // btnTalk
            // 
            this.btnTalk.Location = new System.Drawing.Point(567, 82);
            this.btnTalk.Name = "btnTalk";
            this.btnTalk.Size = new System.Drawing.Size(75, 23);
            this.btnTalk.TabIndex = 9;
            this.btnTalk.Text = "Talk";
            this.btnTalk.UseVisualStyleBackColor = true;
            this.btnTalk.Click += new System.EventHandler(this.btnTalk_Click);
            // 
            // btnWalk
            // 
            this.btnWalk.Location = new System.Drawing.Point(567, 164);
            this.btnWalk.Name = "btnWalk";
            this.btnWalk.Size = new System.Drawing.Size(75, 23);
            this.btnWalk.TabIndex = 10;
            this.btnWalk.Text = "Walk";
            this.btnWalk.UseVisualStyleBackColor = true;
            this.btnWalk.Click += new System.EventHandler(this.btnWalk_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnWalk);
            this.Controls.Add(this.btnTalk);
            this.Controls.Add(this.rbDog);
            this.Controls.Add(this.rbCat);
            this.Controls.Add(this.txtType);
            this.Controls.Add(this.txtAge);
            this.Controls.Add(this.txtName);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.TextBox txtAge;
        private System.Windows.Forms.TextBox txtType;
        private System.Windows.Forms.RadioButton rbCat;
        private System.Windows.Forms.RadioButton rbDog;
        private System.Windows.Forms.Button btnTalk;
        private System.Windows.Forms.Button btnWalk;
    }
}

