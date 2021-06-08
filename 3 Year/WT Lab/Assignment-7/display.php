<html> 
<body> 
<a href="index.php">Add New Data</a><br/><br/> 
 <table width='80%' border=2> 
 <tr bgcolor='pink'> 
  <td>Name</td> 
  <td>Age</td> 
  <td>City</td>  
 </tr> 
 <?php  
 include_once("config.php"); 
$result = mysqli_query($mysqli, "SELECT * FROM userdata ORDER BY id DESC"); 
 while($res = mysqli_fetch_array($result)) 
 {    
  echo "<tr>"; 
  echo "<td>".$res['name']."</td>"; 
  echo "<td>".$res['age']."</td>"; 
  echo "<td>".$res['city']."</td>"; 
  echo "</tr>";    
 } 
 ?> 
 </table> 
 </body> 
</html> 