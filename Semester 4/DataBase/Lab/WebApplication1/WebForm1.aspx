<%@ Page Language="vb" AutoEventWireup="false" CodeBehind="WebForm1.aspx.vb" Inherits="WebApplication1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<style>
    h1{font-family:@Malgun 'MS Gothic';
          font-size: 2em;
          color: blue
    }
    body{font-family:@Malgun 'MS Gothic';
         color: purple
    }
    .button2 {color:blue; border:3px solid;border-color:blue;shape-outside:circle();box-shadow:green 0px 0px 3px 3px;border-radius:4px}
    .buttonCSS {color:black; border:3px solid;border-color:blue;shape-outside:circle();box-shadow:green 0px 0px 3px 3px;border-radius:10px;text-align: center;text-decoration: none;display: inline-block}
    #submit {color:red; border: 3px solid;border-color: red;box-shadow:darkred 0px 0px 3px 3px;border-radius:20px;text-align: center;text-decoration: none;display: inline-block}
</style>
<script type="text/javascript">
    function pkrtousd() {
        var pkr = document.getElementById('pkr').value;
        var usd = parseInt(pkr) * 190;
        document.getElementById('output').value = usd
    }
    function usdtopkr() {
        var usd = document.getElementById('usd').value;
        var pkr = parseInt(usd) / 190;
        document.getElementById('output2').value = pkr
        last();
    }
    function last() {
        document.getElementById('TextBox4').value = 'US Dollars';
        document.getElementById('TextBox5').value = 'Mohammad Anas';
    }
    function reset_form() {
        document.forms[0].reset();
    }
</script>
<body>
    <h1>CURRENCY EXCHANGE WEBSITE</h1>
    <br/>
    <br/>
    <form id="myform" runat="server">
        <div>
            Select Currency Medium: <asp:DropDownList ID="select" CssClass ="button2" runat="server">
<asp:ListItem Text="Select" Value="0"></asp:ListItem>
<asp:ListItem Text="US Dollars" Value="USD"></asp:ListItem>
<asp:ListItem Text="AUS Dollars" Value="USD"></asp:ListItem>
<asp:ListItem Text="Indian Rupee" Value="USD"></asp:ListItem>
</asp:DropDownList>
             <br/>
             <br/>
            Please Enter Amount in PKR to convert to selected Medium: <asp:TextBox ID="pkr" CssClass ="button2" runat="server"></asp:TextBox>
             <br/>
             <br/>
            <asp:Button ID="btnSave" CssClass ="buttonCSS" Text="Convert PKR to Selected currency" runat="server" OnClientClick="javascript:pkrtousd();" />
            <br/>
             <br/>
            Converted Amount (from PKR to USD): <asp:TextBox ID="output" CssClass ="button2" runat="server"></asp:TextBox>
             <br/>
             <br/>
            Please Enter amount in selected medium to convert to PKR: <asp:TextBox ID="usd" CssClass ="button2" runat="server"></asp:TextBox>
             <br/>
             <br/>
            <asp:Button ID="button7" CssClass ="buttonCSS" Text="Convert from Selected currency to PKR" runat="server" OnClientClick="javascript:usdtopkr();"/>
            <br/>
             <br/>
            Converted Amount (from USD to PKR): <asp:TextBox ID="output2" CssClass ="button2" runat="server"></asp:TextBox>
             <br/>
             <br/>
            Your previous chosen medium was: <asp:TextBox ID="TextBox4" CssClass ="button2" runat="server"></asp:TextBox>
             <br/>
             <br/>
            Programmed by: <asp:TextBox ID="TextBox5" CssClass ="button2" runat="server"></asp:TextBox>
            <br/>
             <br/>
            <asp:Button ID="submit" Text="RESET" runat="server" OnClientClick="javascript:reset_form()"/>
        </div>
    </form>
</body>
</html>
