<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
<form method="post" action="">
	<label>First Name</label>
	<br>
	<input type="text" name="fname">
	<br>
	<label>Last Name</label>
	<br>
	<input type="text" name="lname">
	<br>
	<input type="submit" name="submit">
	<br>
</form>
</body>
</html>
<?php
    if (isset($_POST['submit'])){
    	$fname = $_POST['fname'];
    	$lname = $_POST['lname'];

    	class Person{
    		private $fname;
    		private $lname;

    		public function __construct($fname, $lname){
    			$this -> firstname = $fname;
    			$this -> lastname = $lname;
    		}

    		public function getfname(){
    			return $this ->firstname;
    		}
    		public function getlname(){
    			return $this ->lastname;
    		}
    		public function fullname(){
    			echo "Hi, ".$this->firstname. " ".$this->lastname;
    		}
    	}

    $person1 = new Person($fname,  $lname);
    $person1 -> fullname();
    
    }

?>