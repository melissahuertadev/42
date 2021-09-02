#!/usr/bin/php
<?php
    function ft_split($holy_str)
    {
        $each_word = explode(" ", $holy_str);
        $alph_sorted = array_filter($each_word);
        sort($alph_sorted);
        return ($alph_sorted);
    }

    $answer = ft_split("Hello   World   AAA"); 
    foreach ($answer as $elem)
    {
        echo $elem ."\n";
    }
?>