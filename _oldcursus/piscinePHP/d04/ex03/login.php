<?php
    include 'auth.php';
    session_start(['cookie_lifetime' => 00]);

    $log = $_GET['login'];
    $pwd = $_GET['passwd '];
    $_SESSION['loggued_on_user'] = '';

    if ($log && $pwd && auth($log, $pwd)) {
        $_SESSION['loggued_on_user'] = $log;
        echo "OK\n";
    }
    else {
        $_SESSION['loggued_on_user'] = '';
        echo "ERROR\n";
    }
?>