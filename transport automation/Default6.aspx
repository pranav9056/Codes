<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Default6.aspx.cs" Theme="SkinFile" Inherits="Default6" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
   <asp:Table ID="table1" runat="server" Height="300px" Width="1266px">
       <asp:TableRow>
           <asp:TableCell Width="633px" Height="50%">
               <asp:Image  ID="image1" runat="server"  ImageUrl="~/truck1.jpg"/>
              
           </asp:TableCell>
            <asp:TableCell Width="633px" Height="50%">
                &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;
                <asp:Button ID="Button1" Width="50%" height="20%" runat="server"  ForeColor="#99cc00" Font-Bold="true" Text="PLACE ORDER" Font-Size="Larger" OnClick="Button1_Click" />
               
                <asp:MultiView ID="MultiView1" runat="server" ActiveViewIndex="0" Visible="false">
                    <asp:View ID="view1" runat="server">
                        <asp:Table ID="table2" runat="server" Width="633px" Height="50%" >
                            <asp:TableRow>
                                <asp:TableCell>
                                     <asp:Label ID="Label1" runat="server" Text="RECEIVER'S NAME:"></asp:Label>
                                </asp:TableCell>
                                <asp:TableCell>
                                     <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                                </asp:TableCell>
                            </asp:TableRow>
                            <asp:TableRow>
                                <asp:TableCell>
                                    <asp:Label ID="Label2" runat="server" Text="SENDER'S ADDRESS:"></asp:Label>
                                </asp:TableCell>
                                <asp:TableCell>
                                     <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                                </asp:TableCell>
                            </asp:TableRow>
                            <asp:TableRow>
                                <asp:TableCell>
                                    <asp:Label ID="Label3" runat="server" Text="RECEIVER'S ADDRESS:"></asp:Label>
                                </asp:TableCell>
                                <asp:TableCell>
                                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                                </asp:TableCell>
                            </asp:TableRow>
                            <asp:TableRow>
                                <asp:TableCell>
                                     <asp:Label ID="Label4" runat="server" Text="VOLUME:"></asp:Label>
                                </asp:TableCell>
                                <asp:TableCell>
                                     <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
                                </asp:TableCell>
                            </asp:TableRow>
                            <asp:TableRow>
                                <asp:TableCell>
                                    <asp:Label ID="Label5" runat="server" Text="RECEIVER'S NUMBER:"></asp:Label>
                                </asp:TableCell>
                                <asp:TableCell>
                                    <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
                                </asp:TableCell>
                            </asp:TableRow>
                        </asp:Table>
                        <asp:Button  ID="viewbutton1" runat="server" Text="FORWARD CONSIGNMENT" CommandName="NextView" OnClick="viewbutton1_Click"/>
                    </asp:View>
                    <asp:View ID="view2" runat="server">
                        <asp:Label ID="label7" runat="server" Text="SELECT YOUR REGION"></asp:Label>
                        <asp:DropDownList ID="d1" runat="server" AutoPostBack="true" OnSelectedIndexChanged="d1_SelectedIndexChanged">
                            <asp:ListItem Text="North"></asp:ListItem>
                            <asp:ListItem Text="South"></asp:ListItem>
                            <asp:ListItem Text="East"></asp:ListItem>
                            <asp:ListItem Text="West"></asp:ListItem>
                        </asp:DropDownList>
                        <br />
                        <br />
                        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <asp:Label ID="label8" runat="server" Text="SELECT RECEIVER REGION"></asp:Label>
                        <asp:DropDownList ID="d2" runat="server" OnSelectedIndexChanged="d2_SelectedIndexChanged">
                             <asp:ListItem Text="North"></asp:ListItem>
                            <asp:ListItem Text="South"></asp:ListItem>
                            <asp:ListItem Text="East"></asp:ListItem>
                            <asp:ListItem Text="West"></asp:ListItem>
                        </asp:DropDownList>
                        <br />
                        <br />
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;       
                        <asp:Button ID="viewbutton5" runat="server" Text="BACK" CommandName="PrevView" />
                        <b />
                        <br />
                        <br />
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  
                        <asp:Button id="viewbutton2" runat="server" Text="COMPUTE CHARGE AND ALLOT TRUCKS" CommandName="NextView" OnClick="viewbutton2_Click" />
                    </asp:View>
                    <asp:View ID="view3" runat="server">
                        <asp:Label ID="label6" runat="server" Text="TOTAL CHARGE:"> </asp:Label>
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                          &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        
                        <asp:TextBox ID="textbox6" runat="server"></asp:TextBox>
                        <br />
                        <br />
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                          &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                      
                        <asp:Button ID="viewbutton4" runat="server" Text="BACK" CommandName="PrevView" />
                        <br />
                        <br />
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                          &nbsp;&nbsp;&nbsp;&nbsp;
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        
                        <asp:Button  ID="viewbutton3" runat="server" text="PRINT DETAILS" OnClick="viewbutton3_Click" CommandName="NextView"/>
                    </asp:View>
                    <asp:View ID="view4" runat="server">
                       <asp:Table ID="viewtable1" runat="server">
                           <asp:TableRow>
                               <asp:TableCell>
                                   <asp:Label ID="l8" runat="server" Text="ID"></asp:Label>
                                </asp:TableCell>
                               <asp:TableCell>
                                    <asp:TextBox ID="text1" runat="server"></asp:TextBox>
                               </asp:TableCell>
                                  
                               
                           </asp:TableRow>
                           
                           <asp:TableRow>
                               <asp:TableCell>
                                   <asp:Label ID="l7" runat="server" Text="NAME"></asp:Label>
                                   </asp:TableCell>
                               <asp:TableCell>
                                    <asp:TextBox ID="TextBox7" runat="server"></asp:TextBox>
                               </asp:TableCell>
                           </asp:TableRow>

                           <asp:TableRow>
                               <asp:TableCell>
                                   <asp:Label ID="Label9" runat="server" Text="SENDER ADDRESS"></asp:Label>
                                   </asp:TableCell>
                               <asp:TableCell>
                                    <asp:TextBox ID="TextBox8" runat="server"></asp:TextBox>
                               </asp:TableCell>
                           </asp:TableRow>
                           <asp:TableRow>
                               <asp:TableCell>
                                   <asp:Label ID="Label10" runat="server" Text="RECEIVER ADDRESS"></asp:Label>
                                   </asp:TableCell>
                               <asp:TableCell>
                                    <asp:TextBox ID="TextBox9" runat="server"></asp:TextBox>
                               </asp:TableCell>
                           </asp:TableRow>
                           <asp:TableRow>
                               <asp:TableCell>
                                   <asp:Label ID="Label11" runat="server" Text="VOLUME"></asp:Label>
                                   </asp:TableCell>
                               <asp:TableCell>
                                    <asp:TextBox ID="TextBox10" runat="server"></asp:TextBox>
                               </asp:TableCell>
                           </asp:TableRow>
                           <asp:TableRow>
                               <asp:TableCell>
                                   <asp:Label ID="Label12" runat="server" Text="NUMBER"></asp:Label>
                                   </asp:TableCell>
                               <asp:TableCell>
                                    <asp:TextBox ID="TextBox11" runat="server"></asp:TextBox>
                               </asp:TableCell>
                           </asp:TableRow>
                           <asp:TableRow>
                               <asp:TableCell>
                                   <asp:Label ID="Label13" runat="server" Text="DATE"></asp:Label>
                                   </asp:TableCell>
                               <asp:TableCell>
                                    <asp:TextBox ID="TextBox12" runat="server"></asp:TextBox>
                               </asp:TableCell>
                           </asp:TableRow>
                           <asp:TableRow>
                               <asp:TableCell>
                                   <asp:Label ID="Label14" runat="server" Text="CHARGE"></asp:Label>
                                   </asp:TableCell>
                               <asp:TableCell>
                                    <asp:TextBox ID="TextBox13" runat="server"></asp:TextBox>
                               </asp:TableCell>
                               
                           </asp:TableRow>
                           <asp:TableRow>
                               <asp:TableCell>

                                    <asp:Button id="last" runat="server" Text="LOGOUT"  OnClick="last_Click" />
                               </asp:TableCell>
                              
                           </asp:TableRow>
                       </asp:Table>
                    </asp:View>
                </asp:MultiView>
                 <br />
                 <br />
                <br />
                <br />
                <br />
                 &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;
               <asp:Button ID="Button2"  Width="50%" height="20%"  runat="server"  ForeColor="#99cc00" Font-Bold="true" Font-Size="Larger" Text="VIEW ORDER" OnClick="Button1_Click" />
                 </asp:TableCell>
       </asp:TableRow>

   </asp:Table>
</asp:Content>

