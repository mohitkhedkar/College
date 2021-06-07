<html>
<head>
<h2>Logins</h1>
</head>
<body>
<table border = "2px">
	<th>Sr.no</th>
	<th>Name</th>
	<th>Age</th>
	<th>Country</th>
	<?php
	include_once("dkcon.php"); 
	$sql = mysqli_query($mysqli, "SELECT * FROM usrelogin ORDER BY id DESC");
 while($res = mysqli_fetch_array($sql)) 
 {      
 echo "<tr>";
 echo "<td>".$res['id']."</td>";  
 echo "<td>".$res['name']."</td>";   
 echo "<td>".$res['age']."</td>";   
 echo "<td>".$res['country']."</td>";  
 }
  ?>
</table>
</body>
</html>