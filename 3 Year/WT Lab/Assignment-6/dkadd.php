<html> 
<head> 
 <title>Add Data</title> 
</head> 
 
<body> 
<?php 
include_once("dkcon.php"); 
 $name = $_POST['name']; 
 $age = $_POST['age']; 
 $country =$_POST['country']; 
 $result = mysqli_query($mysqli, "INSERT INTO usrelogin(name,age,country) VALUES('$name','$age','$country')"); 
  echo "<font color='green'>Data added."; 
  echo "<br/><a href='dkshow.php'>View Records</a>"; 
?>
</body>
</html>
