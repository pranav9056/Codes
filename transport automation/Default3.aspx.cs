using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Web.Configuration;

public partial class Default3 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        string sconn = WebConfigurationManager.ConnectionStrings["table"].ConnectionString;
        SqlConnection conn = new SqlConnection(sconn);
        string query = "select * from sign";
        SqlCommand cmd = new SqlCommand(query, conn);
        conn.Open();
        SqlDataReader reader;
        reader = cmd.ExecuteReader();
        int flag=0;
        while (reader.Read())
        {
            if (string.Compare(TextBox1.Text.ToString(), "mango") == 0 && string.Compare(TextBox2.Text.ToString(), "mango") == 0)
            {
                Server.Transfer("Default7.aspx");
            }

            if (string.Compare(reader["name"].ToString(), TextBox1.Text.ToString()) == 0 &&
                string.Compare(reader["pass"].ToString(), TextBox2.Text.ToString()) == 0)
            {
                Label3.Text = "Login successful";
                Label3.Visible = true;
                flag = 1;
                string url = "Default6.aspx?";
                url += reader["id"].ToString();
                Response.Redirect(url);

                break;
            }
        }
        if (flag == 0)
        {
            Label3.Text = "Login unsuccessful";
            Label3.Visible = true;
        }
    }
}