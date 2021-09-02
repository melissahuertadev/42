<?php

class Targaryen {

	public function resistsFire() {
		return false;
	}
//if you use print instead of return, it would display the function message before. LOL
    public function getBurned(){
		if ($this->resistsFire() == false)
			return('burns alive');
		else
			return('emerges naked but unharmed');
	}

}
?>