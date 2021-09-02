<!--
  

 but will use the session cookie to display the login contained 
 in the ‘loggued_on_user” session variable followed by “\n”.
  If this variable does not exist or contains an empty string, 
  display only “ERROR\n”.


  session_start();
    if ($_SESSION['loggued_on_user'])
        echo $_SESSION['loggued_on_user']."\n";
    else
        echo "ERROR\n";
unset($_COOKIE[$n]);
    --?>