-- Create simple objects and array objects using JSON

-- Author: Mohit Khedkar

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
public class JSON {
public static void main(String[] args)
{
JSONObject obj1 = new JSONObject();
System.out.println("\n ----Object-1 created 
successfully---\n");
System.out.println("\n ----1st record inserted using object1---\n");
obj1 .put( "ID" , new Integer(1));
obj1 .put( "NAME" , "Abhi" );
obj1 .put( "ADDRESS" , "Aurangabad" );
obj1 .put( "AGE" , new Integer(20));
System.out.println("\n ----Record display using object1---\n");
System.out.print(obj1);

-- Creating JSON Array

System.out.println("\n----------------------------------------
---\n");
System.out.println("\n ----JSONArray created 
successfully---\n");
JSONArray A = new JSONArray();
obj1 .put( "COURSE" , A );
A .add( "COMP" );
A .add( "IT" );
A .add( "COMP" );
A .add( "E & TC" );
System.out.print(obj1);
}} 

----------------------------------- OUTPUT ------------------------------------
----Object-1 created successfully---
----1st record inserted using object-1---
----Record display using object-1---
{"ADDRESS":"Aurangabad","ID":1,"NAME":"Abhi","AGE":20}
-------------------------------------------
----JSONArray created successfully---
{"ADDRESS":"Aurangabad","ID":1,"COURSE":
["COMP","IT","COMP","E & TC"],
"NAME":"Abhi","AGE":20
}