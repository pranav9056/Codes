using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Web.Configuration;
using System.IO;


public partial class  Default6 : System.Web.UI.Page
{
    int send,receiver,index,conid;
    float volume;
    string query1,present,heading;
    protected void Page_Load(object sender, EventArgs e)
    {
        
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        MultiView1.Visible = true;
        Button2.Visible = false;
        Button1.Visible = false;
    }
    protected void d1_SelectedIndexChanged(object sender, EventArgs e)
    {
        send = d1.SelectedIndex;
    }
    protected void viewbutton1_Click(object sender, EventArgs e)
    {
       
        string s = TextBox4.Text.ToString();
        float.TryParse(s, out volume);
        this.ViewState["volume"] = volume;
        string cid = Request.QueryString["id"];

        string sconn = WebConfigurationManager.ConnectionStrings["table"].ConnectionString;
        SqlConnection conn = new SqlConnection(sconn);
        
        string query = "insert into consignment(";
        query += "name,sender,receiver,volume,number,date,cid)";
        query += "values('";
        query += TextBox1.Text + "','";
        query += TextBox2.Text + "','";
        query += TextBox3.Text + "','";
        query += TextBox4.Text + "','";
        query += TextBox5.Text + "','";
        query += DateTime.Today + "','";
        query += cid;
        query += "')";
        SqlCommand cmd = new SqlCommand(query, conn);

        conn.Open();
        int n = cmd.ExecuteNonQuery();



        string query1="select MAX(Id) as max from consignment";
        SqlCommand cmd1=new SqlCommand(query1,conn);
       
        SqlDataReader reader = cmd1.ExecuteReader();
        reader.Read();
        int id = reader.GetInt32(reader.GetOrdinal("max"));
        this.ViewState["tid"] = id;
        conn.Close();

    }
    protected void viewbutton2_Click(object sender, EventArgs e)
    {
        float charge;
        if (send == 0)
        {
            present="north";
            if (receiver == 0)
            {
                index = 0;
                heading="north";
            }
            else if (receiver == 1)
            {
                index = 2;
                heading="south";
            }
            else if(receiver==2)
            {
                index = 1;
                heading="east";
            }
            else
            {
                index=1;
                heading="west";
            }
        }
        else if (send == 1)
        {
            present="south";
            if (receiver == 1)
            {
                index = 0;
                heading="south";
            }
            else if (receiver == 0)
            {
                heading="north";
                index = 2;
            }
            else if(receiver==2)
            {
                index = 1;
                heading="east";
            }
            else
            {
                index=1;
                heading="west";
            }
        }
        else if (send == 2)
        {
            present="east";
            if (receiver == 2)
            {
                index = 0;
                heading="east";
            }
            else if (receiver == 3)
            {
                index = 2;
                heading="west";
            }
            else if(receiver==1)
            {
                heading="south";
                index = 1;
            }
            else
            {
                index=1;
                heading="north";
            }
        }
        else
        {
            present="west";
            if (receiver == 3)
            {
                index = 0;
                heading="west";
            }
            else if (receiver == 2)
            {
                heading="east";
                index = 2;
            }
            else if(receiver==1)
            {
                index = 1;
                heading="south";
            }
            else
            {
                index=1;
                heading="north";
            }
        }
        index++;
        volume = (float)this.ViewState["volume"];
        charge = volume * index*100;
        textbox6.Text = charge.ToString();
        this.ViewState["charge"] = charge;

        string query2 = "UPDATE truck SET volume=";
        query2 += volume.ToString();
        query2+= " where present='";
        query2 += present + "'";
        
        string sconn = WebConfigurationManager.ConnectionStrings["table"].ConnectionString;
        SqlConnection conn = new SqlConnection(sconn);
        SqlCommand cmd = new SqlCommand(query2, conn);
        conn.Open();
        cmd.ExecuteNonQuery();
        conn.Close();



    }
    protected void d2_SelectedIndexChanged(object sender, EventArgs e)
    {
        receiver = d2.SelectedIndex;
    }
    protected void viewbutton3_Click(object sender, EventArgs e)
    {
        string sconn = WebConfigurationManager.ConnectionStrings["table"].ConnectionString;
        SqlConnection conn = new SqlConnection(sconn);
        string query = "select id,name,sender,receiver,volume,number,date from consignment where id=";
        query += this.ViewState["tid"];
        SqlCommand cmd = new SqlCommand(query, conn);
        conn.Open();
        SqlDataReader reader = cmd.ExecuteReader();
        reader.Read();
        text1.Text = reader["id"].ToString();
        TextBox7.Text = reader["name"].ToString();
        TextBox8.Text = reader["sender"].ToString();
        TextBox9.Text = reader["receiver"].ToString();
        TextBox10.Text = reader["volume"].ToString();
        TextBox11.Text = reader["number"].ToString();
        TextBox12.Text = DateTime.Now.ToString();
        TextBox13.Text = this.ViewState["charge"].ToString();
        string write = TextBox7.Text.ToString() + TextBox8.Text.ToString() + TextBox9.Text.ToString() + TextBox10.Text.ToString() + TextBox11.Text.ToString() + TextBox12.Text.ToString() + TextBox13.Text.ToString();
        StreamWriter w;
        string path = @"C:\Users\Acer\Documents\Visual Studio 2012\Projects\WebSite1\sample.txt";
        w = File.CreateText(path);
        w.Write(write);
        w.Close();

    }
    protected void last_Click(object sender, EventArgs e)
    {
        Server.Transfer("Default2.aspx");

    }
}