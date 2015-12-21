using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Web.Configuration;

public partial class Default4 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void c8_ServerValidate(object source, ServerValidateEventArgs args)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        string sconn = "Data Source=(localdb)\\v11.0;Initial Catalog=names;Integrated Security=True";//WebConfigurationManager.ConnectionStrings["table"].ConnectionString;
        SqlConnection conn = new SqlConnection(sconn);
        string query = "insert into sign(";
        //
        query += "name,pass,mail,phone)";
        query +="values('";
       
        query += T1.Text + "','";
        query += T2.Text + "','";
        query += T5.Text + "','";
        query += T6.Text + "')";
        SqlCommand cmd = new SqlCommand(query, conn);
        conn.Open();
        int n = cmd.ExecuteNonQuery();
        conn.Close();
        T1.Text = "";
        T2.Text = "";
        T4.Text = "";
        T5.Text = "";
        T6.Text = "";
        Server.Transfer("Default2.aspx");
    }
}