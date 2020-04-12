using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Car
{
    public partial class Form1 : Form
    {
        private int currentSpeed = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void accelerate_Click(object sender, EventArgs e)
        {
            currentSpeed += 5;
            SpeedBox.Text = currentSpeed.ToString();
        }

        private void brake_Click(object sender, EventArgs e)
        {
            currentSpeed -= 5;
            SpeedBox.Text = currentSpeed.ToString();
        }
    }
}
