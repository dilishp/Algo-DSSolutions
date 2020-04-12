namespace DiceRoll
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
            this.lbRollResult = new System.Windows.Forms.ListBox();
            this.rb2Sides = new System.Windows.Forms.RadioButton();
            this.rb3Sides = new System.Windows.Forms.RadioButton();
            this.rb4Sides = new System.Windows.Forms.RadioButton();
            this.rb6Sides = new System.Windows.Forms.RadioButton();
            this.gbRadioButtons = new System.Windows.Forms.GroupBox();
            this.btnRoll = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.lblheading = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutAppToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbRollResult
            // 
            this.lbRollResult.FormattingEnabled = true;
            this.lbRollResult.ItemHeight = 16;
            this.lbRollResult.Location = new System.Drawing.Point(392, 137);
            this.lbRollResult.Name = "lbRollResult";
            this.lbRollResult.Size = new System.Drawing.Size(120, 228);
            this.lbRollResult.TabIndex = 0;
            // 
            // rb2Sides
            // 
            this.rb2Sides.AutoSize = true;
            this.rb2Sides.Location = new System.Drawing.Point(108, 169);
            this.rb2Sides.Name = "rb2Sides";
            this.rb2Sides.Size = new System.Drawing.Size(76, 21);
            this.rb2Sides.TabIndex = 2;
            this.rb2Sides.TabStop = true;
            this.rb2Sides.Text = "2 Sides";
            this.rb2Sides.UseVisualStyleBackColor = true;
            // 
            // rb3Sides
            // 
            this.rb3Sides.AutoSize = true;
            this.rb3Sides.Location = new System.Drawing.Point(108, 219);
            this.rb3Sides.Name = "rb3Sides";
            this.rb3Sides.Size = new System.Drawing.Size(76, 21);
            this.rb3Sides.TabIndex = 3;
            this.rb3Sides.TabStop = true;
            this.rb3Sides.Text = "3 Sides";
            this.rb3Sides.UseVisualStyleBackColor = true;
            // 
            // rb4Sides
            // 
            this.rb4Sides.AutoSize = true;
            this.rb4Sides.Location = new System.Drawing.Point(108, 273);
            this.rb4Sides.Name = "rb4Sides";
            this.rb4Sides.Size = new System.Drawing.Size(76, 21);
            this.rb4Sides.TabIndex = 4;
            this.rb4Sides.TabStop = true;
            this.rb4Sides.Text = "4 Sides";
            this.rb4Sides.UseVisualStyleBackColor = true;
            // 
            // rb6Sides
            // 
            this.rb6Sides.AutoSize = true;
            this.rb6Sides.Location = new System.Drawing.Point(108, 322);
            this.rb6Sides.Name = "rb6Sides";
            this.rb6Sides.Size = new System.Drawing.Size(76, 21);
            this.rb6Sides.TabIndex = 5;
            this.rb6Sides.TabStop = true;
            this.rb6Sides.Text = "6 Sides";
            this.rb6Sides.UseVisualStyleBackColor = true;
            // 
            // gbRadioButtons
            // 
            this.gbRadioButtons.Location = new System.Drawing.Point(67, 132);
            this.gbRadioButtons.Name = "gbRadioButtons";
            this.gbRadioButtons.Size = new System.Drawing.Size(200, 233);
            this.gbRadioButtons.TabIndex = 6;
            this.gbRadioButtons.TabStop = false;
            this.gbRadioButtons.Text = "Customize Dice";
            // 
            // btnRoll
            // 
            this.btnRoll.Location = new System.Drawing.Point(604, 189);
            this.btnRoll.Name = "btnRoll";
            this.btnRoll.Size = new System.Drawing.Size(75, 23);
            this.btnRoll.TabIndex = 7;
            this.btnRoll.Text = "Roll";
            this.btnRoll.UseVisualStyleBackColor = true;
            this.btnRoll.Click += new System.EventHandler(this.btnRoll_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(604, 273);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 8;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // lblheading
            // 
            this.lblheading.AutoSize = true;
            this.lblheading.Font = new System.Drawing.Font("Calibri", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblheading.Location = new System.Drawing.Point(344, 18);
            this.lblheading.Name = "lblheading";
            this.lblheading.Size = new System.Drawing.Size(175, 37);
            this.lblheading.TabIndex = 9;
            this.lblheading.Text = "Roll The Dice";
            // 
            // richTextBox1
            // 
            this.richTextBox1.BackColor = System.Drawing.SystemColors.InfoText;
            this.richTextBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.richTextBox1.ForeColor = System.Drawing.SystemColors.Info;
            this.richTextBox1.Location = new System.Drawing.Point(67, 74);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(612, 25);
            this.richTextBox1.TabIndex = 10;
            this.richTextBox1.Text = "This dice has 6 sides by default.You can roll or customize the dice first";
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(748, 28);
            this.menuStrip1.TabIndex = 11;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(44, 24);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutAppToolStripMenuItem});
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(62, 24);
            this.aboutToolStripMenuItem.Text = "About";
            // 
            // aboutAppToolStripMenuItem
            // 
            this.aboutAppToolStripMenuItem.Name = "aboutAppToolStripMenuItem";
            this.aboutAppToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.aboutAppToolStripMenuItem.Text = "About App";
            this.aboutAppToolStripMenuItem.Click += new System.EventHandler(this.aboutAppToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(748, 448);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.lblheading);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnRoll);
            this.Controls.Add(this.rb6Sides);
            this.Controls.Add(this.rb4Sides);
            this.Controls.Add(this.rb3Sides);
            this.Controls.Add(this.rb2Sides);
            this.Controls.Add(this.lbRollResult);
            this.Controls.Add(this.gbRadioButtons);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox lbRollResult;
        private System.Windows.Forms.RadioButton rb2Sides;
        private System.Windows.Forms.RadioButton rb3Sides;
        private System.Windows.Forms.RadioButton rb4Sides;
        private System.Windows.Forms.RadioButton rb6Sides;
        private System.Windows.Forms.GroupBox gbRadioButtons;
        private System.Windows.Forms.Button btnRoll;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Label lblheading;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutAppToolStripMenuItem;
    }
}

