#!/usr/bin/php
<?php
  if ($argc > 1)
  {
    $my_str = trim($argv[1]);
    $my_str = preg_replace('/\s+/', ' ', $my_str);
    echo $my_str."\n";
  }   
?>

<!--ref: https://www.php.net/manual/en/function.trim.php-->