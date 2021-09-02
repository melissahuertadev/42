<?php
	$a = $_GET["action"];
	$n = $_GET["name"];
	$v = $_GET["value"];
	
	if ($a) {
		//validates info for the action set)
		if ($a == "set" && !empty($n) && !empty($v))
			setcookie($n, $v, time() + (86400 * 30), '/'); // 86400 = 1 day
		if ($a == "get" && isset($_COOKIE[$n]))
			echo $_COOKIE[$n]."\n";
		if ($a == "del") {
			unset($_COOKIE[$n]);
			$res = setcookie($n, '', time() - 3600); //empty value and expiration one hour before
		}
	}

//reference: https://www.pontikis.net/blog/create-cookies-php-javascript
?>
