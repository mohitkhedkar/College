function validateForm(){
    var rno = document.getElementById("rno").value;
    var name = document.getElementById("name").value;
    var yoe = document.getElementById("year").value;
    var branch = document.getElementById("branch").value;
    var mobileno = document.getElementById("mobile").value;
    var email = document.getElementById("email").value;
    
    var reg = /^([A-Za-z0-9_\-\.])+\@([A-Za-z0-9_\-\.])+\.([A-Za-z]{2,4})$/;
    
    
    
    if(rno == "" || isNaN(rno)){
       document.getElementById("rollno").innerHTML = "Enter valid roll no!"
       }
    
    if(name == ""){
       document.getElementById("fname").innerHTML = "Name is mandatory!"
       }
    
    if(yoe == "" || yoe!="FE" || yoe!="SE"|| yoe!= "TE"|| yoe!="BE"){
       document.getElementById("yoe").innerHTML = "Only options include FE,SE,TE,BE"
       }
    
    if(branch == ""){
       document.getElementById("boe").innerHTML = "Branch is mandatory!"
       }
    
    if(mobileno == "" || isNaN(mobileno) || mobileno.length > 10|| mobileno.length<10){
       document.getElementById("mno").innerHTML = "Mobile number should be of 10 digits!"
       }
    
    if(email == ""){
       document.getElementById("emailid").innerHTML = "Email Address is required!"
       }
    
    if(reg.test(email) == false){
       alert("Email should contain @ and .com");
       }
    
    else{
        alert("Form submitted!");
    }

}