<?php

class Tyrion extends Lannister {
    public function sleepWith($att){
        if ($att instanceof Jaime)
            print( "Not even if I'm drunk !" . PHP_EOL );
        else if ($att instanceof Sansa)
            print( "Let's do this." . PHP_EOL );
        else if ($att instanceof Cersei)
            print( "Not even if I'm drunk !". PHP_EOL );
    }
}

?>