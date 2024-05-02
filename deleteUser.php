<!DOCTYPE html>
<html>
<head>
  <title></title>
</head>
<body>
  <table>
    <thead>
      <tr>
        <th>No</th>
        <th>Username</th>
        <th>Password</th>
        <th>User Type</th>
        <th>Action</th>
      </tr>
    </thead>
 <tbody>
 	<?php
 	include('config.php');

 	$id = $_GET['id'] ?? null;
 	if($id !== null){
 		$sql= "DELETE FROM users WHERE userid=$id";
 		$result = $conn->query($sql);
 		header('location:deleteUser.php');
 		exit;
 	}

 	$sql = "SELECT * FROM users";
 	$result = $conn->query($sql);
 	$x=0;
 	while ($row = $result->fetch_assoc()){
 		$x++;
 		?>
 		<tr>
        <td><?php echo $x; ?></td>
        <td><?php echo $row['username'];?></td>
        <td><?php echo $row['userpass'];?></td>
        <td><?php echo $row['usertype'];?></td>
        <td><a href="deleteUser.php?id=<?php echo $user['userid']?>">Delete</a>></td>

      </tr>
      <?php
 	}
 	?>
 </tbody>
</table>
</body>
</html>