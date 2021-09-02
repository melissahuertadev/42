<?php
    $usr = $_POST["login"];
    $n_pwd = $_POST["newpw"];
    $pwd = $_POST["oldpw"];
    $structure = '../htdocs/private/';
    $file = 'passwd';
    session_start(['cookie_lifetime' => 00]);

    if($_POST["submit"] == 'OK' && $usr != '' && $pwd != '' &&  $n_pwd == '') {
        $epwd = hash("whirlpool", $n_pwd);
        $uncompressed = unserialize(file_get_contents($structure.$file));  

        $exist = false;
        $correct_passw = false;
        if ($uncompressed)
        {
            //checking the user exists and old password is equal to the saved passwd
            foreach ($uncompressed as $key => $value) {
                if ($key = "login" && $value = $usr)
                    $exist = true;
                if ($key = "passwd" && $value = $pwd)
                    $correct_passw = true;
            }
        }

        //if the user exist and the old pass is the stored one, update the passw
        if ($exist || $correct_passw)
        {
            $webinfo = array("login" => $usr, "passwd" => $epwd);
            $compressed = serialize($webinfo)."\n";
            file_put_contents($structure.$file, $compressed);
            echo "OK\n";  
        }          
    }
    else 
        echo "ERROR\n";

?>

<!---  file_put_contents(), 
serialize(),-->