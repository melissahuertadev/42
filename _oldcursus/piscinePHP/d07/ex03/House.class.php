<?php

class House {
    public function introduce(){
        print('House ' . $this->getHouseName() . ' of ' . $this->getHouseSeat() . ' : "' . $this->getHouseMotto() . '"' . PHP_EOL);

    }
}
/*
The great Houses of Westeros present themselves in the same way.
But they each have a motto (or heraldry) that is unique.

Write the House Class so that the test1.php (attached) 
produces the following out- put:

$> php -f test1.php
House Stark of Winterfell : "Winter is coming"
House Martell of Sunspear : "Unbowed, Unbent, Unbroken"

... but that the test2.php (also attached) produces a fatal error. 

*/

?>