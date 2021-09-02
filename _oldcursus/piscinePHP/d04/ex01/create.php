<?php
    $usr = $_POST["login"];
    $pwd = $_POST["passwd"];
    $structure = '../htdocs/private/';
    $file = 'passwd';
    session_start(['cookie_lifetime' => 00]);

    if (!file_exists($structure))
        mkdir($structure, 0777, true);
    if (!file_exists($structure.$file))
        file_put_contents($structure.$file, null);
    
    if($_POST["submit"] == 'OK' && $usr != '' && $pwd != '') {
        $epwd = hash("whirlpool", $pwd);
        //accessing to the info and storing an array
        $uncompressed = unserialize(file_get_contents($structure.$file));   
        $new = true;
        if ($uncompressed)
        {
            foreach ($uncompressed as $key => $value) {
                if ($key = "login" && $value == $usr)
                    //echo "exist\n";
                    $new = false;
            }
        }
        if (!$new) {
            echo "ERROR\n";
        } else {
            //saving the info
            $webinfo = array("login" => $usr, "passwd" => $epwd);
            $compressed = serialize($webinfo)."\n";
            file_put_contents($structure.$file, $compressed);
            echo "OK\n";
        }
    }
    else 
        echo "ERROR\n";
?>