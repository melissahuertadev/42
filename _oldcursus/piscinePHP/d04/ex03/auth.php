<?php
    $structure = '../htdocs/private/';
    $file = 'passwd';

    function auth($login, $passwd) {
        $combo = unserialize(file_get_contents($structure.$file));
        $validate = 0;

        if ($combo) {
            foreach ($combo as $key => $value) {
                if ($key = "login" && $value = $login)
                    $validate++;
                if ($key = "passwd" && $value = $pwd)
                    $validate++;
            }
        }
        if ($validate == 2)
            return true;
    return false;
    }
?>