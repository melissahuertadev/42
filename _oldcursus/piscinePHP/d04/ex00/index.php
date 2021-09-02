<?php  
    session_start(['cookie_lifetime' => 00]);
    
    if ($_GET["submit"] == 'OK') {
        $_SESSION["log"] = $_GET["login"];
        $_SESSION["pwd"] = $_GET["passwd"];
    }
?>

<html><body>
<form action="index.php" method="GET">
<!--only change the values if you get OK-->
    Username: <input type="text" name="login" value="<?php echo $_SESSION["log"]?>"/>
    <br />
    Password: <input type="text" name="passwd" value="<?php echo $_SESSION["pwd"]?>"/>
<input type="submit" name="submit" value="OK"/>
</form>
</body></html>