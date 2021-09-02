<?php
class NightsWatch {
    public function recruit($v) {
        if ($v instanceof JonSnow)
            $v->fight();
        else if ($v instanceof SamwellTarly)
            $v->fight();
        else
            return;
    }

    public function fight() {}
}
/*
The Night Watch is the last Wall that protects Westeros from annihilation.
Even if no one seems to remember that part...
The situation is what it is.
The Night Watch is forced to recruit whomever they can attract,
whether the rare ones who see it as an honor, or the criminals who are looking for a way out.
However, there would be no logic in using non fighters in battle!

You need to write the IFighter as well as the NightsWatch Class, so that the
test1.php file (attached) produces the following output:
And naturally, the test2.php (also attached) produces a fatal error.

$> php -f test1.php
* looses his wolf on the enemy, and charges with courage *
* flees, finds a girl, grows a spine, and defends her to the bitter end *
$>
*/

?>