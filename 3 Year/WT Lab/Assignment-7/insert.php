<?php 
include_once("config.php"); 
$name = $_POST['name']; 
$age = $_POST['age']; 
$city = $_POST['city']; 
$sql = mysqli_query($mysqli, "insert into userdata(name,age,city) values ('$name','$age','$city')");  
if($sql>0) 
{ 
echo(1); 
} 
else 
{ 
echo(0); 
} 
 
?>