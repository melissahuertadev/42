#!/usr/bin/php
<?php
    /* format: Day_of_the_week Number_of_day Month Year Hours:Minutes:Seconds
        $string = 'Mardi 12 Novembre 2013 12:02:21';

        /i to make case sensitive
    */

    $pattern = '/(\w+) (\d+) (\w+) (\d+) (\d+):(\d+):(\d+)/i';

        /* 
        format: Day_of_the_week Number_of_day Month Year Hours:Minutes:Seconds

        - The day of the week is complete, full, sometimes with a uppercase at the beginning, and in French.
        - The day’s number is always 1 or 2 characters.
        - The month is expressed in words, sometimes also with a capital letter at the beginning, and always in French.
        - The year consists of 4 digits.
        - Finally, hours, minutes and seconds are all of 2 figures.
        
        There are 4 spaces to separate 5 pieces.
        
        */

        /*
        
        #!/usr/bin/php
<?php
    date_default_timezone_set('Europe/Paris');

    $pattern = '/(\w+) (\d+) (\w+) (\d+) (\d+):(\d+):(\d+)/i';
    $days = array(
        1 => "lundi",
        2 => "mardi",
        3 => "mercredi",
        4 => "jeudi",
        5 => "vendredi",
        6 => "samedi",
        7 => "dimanche");
    $months = array(
        1 => "janvier",
        2 => "février",
        3 => "mars",
        4 => "avril",
        5 => "mai",
        6 => "juin",
        7 => "juillet",
        8 => "août",
        9 => "septembre",
        10 => "octobre",
        11 => "novembre",
        12 => "décembre");

    if (preg_match($pattern, $argv[1]))
    {
        $ip_date = explode(" ", $argv[1]);
        $ip_date[0] = array_search(strtolower($ip_date[0]), array_map('strtolower', $days));
        $ip_date[2] = array_search(strtolower($ip_date[2]), array_map('strtolower', $months));
    }
    else
    {
        echo "Wrong Format\n";
        exit();
    }

    if ($ip_date[0] === false || $ip_date[2] === false)
    {
        echo "Wrong Format\n";
        exit();
    }

    $time_calc = mktime($ip_date[4][0], $ip_date[4][1], $ip_date[4][2], $ip_date[2], $ip_date[1][0], $ip_date[3][0]);
    //hour, min, sec, month, day, year
    // Prints something like: 2006-04-05T
    "Mardi 12 Novembre 2013 "
echo date('c', mktime(1, 2, 3, 4, 5, 2006));

?>
*/ 
?>



