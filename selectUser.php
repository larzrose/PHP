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
           
           class SelectUserData{
            private $conn;
            public function __construct($conn){
              $this->conn=$conn;

              if($this->conn->connect_error){
                die("Connection Failed: ".$this->conn->connect_error);
              }
            }
            public function getUser(){
              $sql="SELECT * FROM users";
              $result= $this->conn->query($sql);
              $users=array();

              if ($result->num_rows > 0){
                while($row=$result->fetch_assoc()){
                  $users[]=$row;
                }
              }
              return $users;
            }
           }
           $userData= new SelectUserData($conn);
           $users= $userData->getUser();

           $x=1;
           foreach ($users as $user){
            ?>
             <tr>
        <td><?php echo $x++; ?></td>
        <td><?php echo $user['username'];?></td>
        <td><?php echo $user['userpass'];?></td>
        <td><?php echo $user['usertype'];?></td>
        <td><a href="deleteUser.php?id=<?php echo $user['userid']?>">Delete</a>></td>

      </tr>
      <?php
           }
           ?>
         </tbody>
         </table>
       </body>
       </html>