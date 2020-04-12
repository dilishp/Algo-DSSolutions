using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DiceRoll
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnRoll_Click(object sender, EventArgs e)
        {
            RollDice rollDice = null;
            if (rb2Sides.Checked || rb3Sides.Checked || rb4Sides.Checked || rb6Sides.Checked)
            {
                int noofSides = 0;
                if(rb2Sides.Checked)
                {
                    noofSides = 2;
                }
                else if(rb3Sides.Checked)
                {
                    noofSides = 3;
                }
                else if(rb4Sides.Checked)
                {
                    noofSides = 4;
                }
                else if(rb6Sides.Checked)
                {
                    noofSides = 6;
                }
               rollDice = new RollDice(noofSides);
            }
            else
            {
                rollDice = new RollDice();
            }
            lbRollResult.Items.Add(rollDice.Roll());
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            rb2Sides.Checked = false;
            rb3Sides.Checked = false;
            rb4Sides.Checked = false;
            rb6Sides.Checked = false;
            lbRollResult.Items.Clear();
        }

        private void aboutAppToolStripMenuItem_Click(object sender, EventArgs e)
        {

            MessageBoxButtons boxButtons = MessageBoxButtons.OK;    
            MessageBox.Show("Dice Magic Version 1.0 \nProgrammer : Louie Lumberjack","Dice Magic", boxButtons,MessageBoxIcon.Information);
        }
    }
}
