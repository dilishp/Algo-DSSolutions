using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PetForm
{

    public partial class Form1 : Form
    {
        Pet pet;
        public Form1()
        {
            InitializeComponent();
            if((rbCat.Checked == true) || (rbCat.Checked == true))
            {
                btnTalk.Enabled = true;
                btnWalk.Enabled = true;
            }
            else
            {
                btnTalk.Enabled = false;
                btnWalk.Enabled = false;
            }
        }

        private void EnableButtons()
        {
            btnTalk.Enabled = true;
            btnWalk.Enabled = true;
        }
        private void rbCat_Click(object sender, EventArgs e)
        {
            EnableButtons();

            if(pet != null)
            {
                if (pet.GetType() != typeof(Cat))
                {
                    txtName.Text = string.Empty;
                    txtType.Text = string.Empty;
                    txtAge.Text = string.Empty;
                }
        
            }
           
            int result;
            if(!int.TryParse(txtAge.Text,out result))
            {
                result = 0;
            }
            pet = new Cat(txtName.Text, txtType.Text, result);
           

        }

        private void rbDog_Click(object sender, EventArgs e)
        {
            EnableButtons();

            if (pet != null)
            {
                if (pet.GetType() != typeof(Dog))
                {
                    txtName.Text = string.Empty;
                    txtType.Text = string.Empty;
                    txtAge.Text = string.Empty;
                }
               
            }

            int result;
            if (!int.TryParse(txtAge.Text, out result))
            {
                result = 0;
            }
            pet = new Dog(txtName.Text, txtType.Text, result);
            
        }

        private void btnTalk_Click(object sender, EventArgs e)
        {
            pet.Talk();
        }

        private void btnWalk_Click(object sender, EventArgs e)
        {
            pet.Walk();
        }
    }
}
