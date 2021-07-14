using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
namespace _6593
{
    public partial class Form3 : Form
    {
        SqlConnection connection = new SqlConnection(@"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\AData\Android\Alarms\6593\6593\Database1.mdf;Integrated Security=True");
        public Form3()
        {
            InitializeComponent();
        }

        private void tableBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.tableBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.database1DataSet);

        }

        private void Form3_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet.Table' table. You can move, or remove it, as needed.
            this.tableTableAdapter.Fill(this.database1DataSet.Table);

        }
        

        private void btnsave_Click(object sender, EventArgs e)
        {
            {
                connection.Open();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "insert into [Table](First Name,Email.Telephone,Gender,Grade)values('" + txtfname.Text + "','" + txtemail.Text + "'," + int.Parse(txttp.Text) + ",'" + cmdgender.Text + "','" + cmdgrade.Text + "')";
                connection.Close();
                txtfname.Text = "";
                txtemail.Text = "";
                txttp.Text = "";
                cmdgender.Text = "";
                cmdgrade.Text = "";
                display_data();
                MessageBox.Show("Data Successfully Entered!!", "Approval Message", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
        public void display_data()
        {
            connection.Open();
            SqlCommand cmd = connection.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from [Table]";
            DataTable dta = new DataTable();
            SqlDataAdapter dataadp = new SqlDataAdapter(cmd);
            dataadp.Fill(dta);
            dataGridView1.DataSource = dta;
            connection.Close();
        }

        private void btndisplay_Click(object sender, EventArgs e)
        {
            display_data();
        }

        private void btndelete_Click(object sender, EventArgs e)
        {
            {
                connection.Open();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "delete from [Table] where Email ='" + txtemail.Text + "'";
                connection.Close();
                txtfname.Text = "";
                txtemail.Text = "";
                txttp.Text = "";
                cmdgender.Text = "";
                cmdgrade.Text = "";
                display_data();
                MessageBox.Show("Data Successfully Deleted!!", "Approval Message", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void btnupdate_Click(object sender, EventArgs e)
        {
            {
                connection.Open();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "update [Table] set Email ='" + txtemail.Text + "' where Email='" + txtemail.Text + "'";
                cmd.ExecuteNonQuery();
                connection.Close();
                txtfname.Text = "";
                txtemail.Text = "";
                txttp.Text = "";
                cmdgender.Text = "";
                cmdgrade.Text = "";
                display_data();
                MessageBox.Show("Data Successfully Updated!!", "Approval Message", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void btnsearch_Click(object sender, EventArgs e)
        {
            {
                connection.Open();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "select * from [Table] where Email ='" + txtemail.Text + "'";
                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                dataGridView1.DataSource = dt;
                connection.Close();
                txtfname.Text = "";
                txtemail.Text = "";
                txttp.Text = "";
                cmdgender.Text = "";
                cmdgrade.Text = "";
            }
        }

        private void telephoneLabel_Click(object sender, EventArgs e)
        {

        }

        private void btnexit_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Do You Want To Exit !!", "GoodDay Esoft Student", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            Application.Exit();          
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void genderLabel_Click(object sender, EventArgs e)
        {

        }



    }
}
