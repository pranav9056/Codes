<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Default7.aspx.cs" Theme="SkinFile" Inherits="Default7" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    
    <asp:Table ID="table4" runat="server" Height="300px" Width="1266px">
       <asp:TableRow>
           <asp:TableCell Width="633px" Height="50%">
               <asp:Image  ID="image1" runat="server"  ImageUrl="~/truck1.jpg"/>
            </asp:TableCell>

           <asp:TableCell Width="200px">
               <asp:SqlDataSource ID="SQL1" runat="server" ConnectionString="<%$ ConnectionStrings:table %>" SelectCommand="select * from consignment" >

    </asp:SqlDataSource>
    <asp:GridView ID="g1" runat="server" DataSourceID="SQL1" AutoGenerateColumns="true" Visible="false"></asp:GridView>
     <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:table %>" SelectCommand="select * from truck">

    </asp:SqlDataSource>
    <asp:GridView ID="GridView1" runat="server" DataSourceID="SqlDataSource1"  AutoGenerateColumns="true" Visible="false"></asp:GridView>
                <asp:Button ID="b1" runat="server" OnClick="b1_Click" Text="BACK" Visible="false" />
           </asp:TableCell>

           <asp:TableCell Width="433px" Height="50%">
                  <asp:Button ID="Button1" Width="50%" height="20%" runat="server"  ForeColor="#99cc00" Font-Bold="true" Text="TRUCK DETAILS" Font-Size="Larger" OnClick="Button1_Click" />
                  <br />
                  <br />
                  <asp:Button ID="Button2" Width="50%" height="20%" runat="server"  ForeColor="#99cc00" Font-Bold="true" Text="ORDER DETAILS" Font-Size="Larger" OnClick="Button2_Click" />
            </asp:TableCell>

           </asp:TableRow>
        
        </asp:Table>
    
   
</asp:Content>

