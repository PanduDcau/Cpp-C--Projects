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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {

        }

        private void btn3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Do You Want To Exit !!", "GoodDay Esoft Student", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            Application.Exit();          
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Login Success !!", "Welcome To The Esoft Metro Campus Login", MessageBoxButtons.OK, MessageBoxIcon.Information);
            this.Hide();
            Form3 obj = new Form3();
            obj.Show();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void btn2_Click(object sender, EventArgs e)
        {
            MessageBox.Show(" Please Try Administration Login!!", "Access Denied", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            Application.Exit();   
        }
    }
}
