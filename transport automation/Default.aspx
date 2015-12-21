<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" Theme="SkinFile" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:Table ID="Table1" runat="server" Width="1266px" Height="503px">
        <asp:TableRow>
             
            <asp:TableCell Width="633px" Height="503px">
                <asp:Image ID="image2" runat="server" ImageUrl="~/team1.jpg" />
                
               
            </asp:TableCell>
            <asp:TableCell Width="633px" Height="503px">
                  <asp:Image ID="Image1" ImageUrl="r1.jpg" runat="server" />
            </asp:TableCell>
            
        </asp:TableRow>
    </asp:Table>
   
   
    <!--<asp:ListBox ID="ListBox1" runat="server" Height="2000%" Width="60%" BackColor="LightYellow" ForeColor="Black" DataTextField="abdbfeu"></asp:ListBox>-->
   
</asp:Content>

