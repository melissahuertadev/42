#!/usr/bin/php
<?PHP
$my_cntr = 1;

while ($my_cntr <= 1000)
{
    echo "X";
    if ($my_cntr % 94 == 0)
        echo "\n";
    $my_cntr++;
}
echo "\n";

?>