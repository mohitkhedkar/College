<!DOCTYPE html> 
<html> 
<head> 
<title>PHP Databse Example with Ajax </title> 
<script src="jquery-3.3.1.min.js"></script> 
</head> 
<body> 
<h1> Enter Employee Details </h1> 
<form method="post" action="insert.php"> 
<input type="text" id="name"  placeholder="Enter Name" /> 
<input type="text" id="age"   placeholder="Enter Age" /> 
<input type="text" id="city"  placeholder="Enter City" /> 
<button> Save Data </button> 
</form> 
<p id="result"> 
</p> 

<a href="display.php">Display</a> 
 
<!--jquery and ajax code--> 
<script> 
$("form").submit(function(e){ 
e.preventDefault(); 
 
$.post( 
"insert.php", 
{ 
name: $("#name").val(), 
age: $("#age").val(), 
city: $("#city").val() 
}, 
 
function(result) 
{ 

if(result == 1) 
{ 
 $("#result").html("Data Inserted Successfully..!");
  
} 
else 
{ 
 $("#result").html("Error Occured!"); 
} 
} 
); 
}); 
</script> 
</script> 
</body> 
</html> 