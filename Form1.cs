using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _6593
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void btnsub_Click(object sender, EventArgs e)
        {
            string email = txt1.Text;
            string password = txt2.Text;

            if (email == "Dasabros@gmail.com" && password == "TeenTitans")
            {
                MessageBox.Show("Login Success !!", "Welcome Esoft Student", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Hide();
                Form2 obj = new Form2();
                obj.Show();

            }
            else
            {
                MessageBox.Show("Login Not Success!", "Invalid Email", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
