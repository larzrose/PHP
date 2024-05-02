<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	<h3>ADD USER FORM</h3>
	<form method="post" action="">
	<label>User Name</label>
	<br>
	<input type="text" name="uname">
	<br>
	<label>Password</label>
	<br>
	<input type="password" name="upass">
	<br>
	<label>Type</label>
	<br>
	<select name="utype">
		<option></option>
		<option value="Dummy">Dummy</option>
		<option value="Admin">Admin</option>

		</select>
		<br>
		<input type="submit" name="adduser">
	</form>

</body>
</html>

<?php

	if (isset($_POST['adduser'])){
		$uname = $_POST['uname'];
		$upass = $_POST['upass'];
		$utype = $_POST['utype'];

		include('config.php');

		class InsertData{
 		private $username;
 		private $password;
 		private $usertype;
 		private $conn;

 		public function __construct($uname, $upass, $utype,$connection){
 			$this -> username = $uname;
 			$this -> password = $upass;
 			$this -> usertype = $utype;
 			$this -> conn = $connection;

}
	public function getUname(){
		return $this->username;
	}
	public function getUpass(){
		return $this->password;
	}
	public function getUtype(){
		return $this->usertype;
	}
	public function getData(){

	$sql = "INSERT into users(username,userpass,usertype) VALUES ('$this->username','$this->password','$this->usertype')";
    $con = $this->conn;
    echo "<script>window.alert('User Data Has Been Saved');</script>";
    $result = $con->query($sql);
		
	}
    }
    $InsertData1 = new InsertData ($uname,$upass,$utype,$conn);
	$InsertData1 -> getData();

	}

?>