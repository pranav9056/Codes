using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Default7 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Button1.Visible = false;
        Button2.Visible = false;
        GridView1.Visible = true;
        g1.Visible = false;
        image1.Visible = false;
        b1.Visible = true;
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        Button1.Visible = false;
        Button2.Visible = false;
        GridView1.Visible = false;
        g1.Visible = true;
        image1.Visible = false;
        b1.Visible = true;
    }
    protected void b1_Click(object sender, EventArgs e)
    {
        Button1.Visible = true;
        Button2.Visible = true;
        GridView1.Visible = false;
        g1.Visible = false;
        image1.Visible = true;
    }
}