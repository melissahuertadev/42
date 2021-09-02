<?php

class Jaime extends Lannister {
    public function sleepWith($att){
        if ($att instanceof Tyrion)
            print( "Not even if I'm drunk !" . PHP_EOL );
        else if ($att instanceof Sansa)
            print( "Let's do this." . PHP_EOL );
        else if ($att instanceof Cersei)
            print( "With pleasure, but only in a tower in Winterfell, then." . PHP_EOL );
    }
}
/*
-----------------------------------------------
$j->sleepWith($t); Not even if I'm drunk !
$j->sleepWith($s); Let's do this.
$j->sleepWith($c); With pleasure, but only in a tower in Winterfell, then.

-----------------------------------------------
$t->sleepWith($j); Not even if I'm drunk !
$t->sleepWith($s); Let's do this.
$t->sleepWith($c); Not even if I'm drunk !

-->

*/
?>