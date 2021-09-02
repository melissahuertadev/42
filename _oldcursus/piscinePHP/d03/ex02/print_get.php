<?php
	$info = ($_GET);

	foreach($info as $key => $value) {
		echo "$key: $value\n";
	}

/*print_r($_GET);
 * curl 'http://e1z3r1p6.42.fr:8080/d03/ex02/print_get.php?gdb=pied2biche&barry=barreamine'
 * 
 * Array
 * (
 * [login] => mmontinet
 * )
 */
?>
