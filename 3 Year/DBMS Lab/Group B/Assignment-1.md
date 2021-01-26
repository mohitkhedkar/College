## Assignment-1: Study of Open Source NOSQL Database: MongoDB (Installation, Basic CRUD operations,Execution)

#### Author: Mohit Khedkar.

## Installation Guide:


* [For Windows](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-windows/)

* [For Linux (Ubuntu)](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-ubuntu/)


#### Basic CRUD Operation

* Creating & Inserting Values in new Database 
```bash 
> show dbs
admin   0.000GB
config  0.000GB
local   0.000GB
> use demodb
switched to db demodb
> db.student.insert({"name":"mohit"})
WriteResult({ "nInserted" : 1 })
```

* Showing Database
```bash
> show dbs
admin   0.000GB
config  0.000GB
demodb  0.000GB
local   0.000GB
```

* Drop Database
```bash
> use demodb
switched to db demodb
> db.dropDatabase()
{ "dropped" : "demodb", "ok" : 1 }
> show dbs
admin   0.000GB
config  0.000GB
local   0.000GB
```

* Create Collection
Mongodb can create collections autmotically also.
```bash
> db.createCollection("newCollection")
{ "ok" : 1 }
> show collections
newCollection
student
```

* Drop Collection
```bash
> db.newCollection.drop()
true
> show collections
student
```

* Inserting Document into Collection
```bash
> db.student.insert({"name":"Hemanshu"})
WriteResult({ "nInserted" : 1 })
> db.student.insert({"name":"Rutuja"})
WriteResult({ "nInserted" : 1 })
```

* Retriving Document from Collection
```bash
> db.student.find()
{ "_id" : ObjectId("6010291c3e5b451a6eeb4264"), "name" : "mohit" }
{ "_id" : ObjectId("60102acc3e5b451a6eeb4265"), "name" : "Hemanshu" }
{ "_id" : ObjectId("60102ad53e5b451a6eeb4266"), "name" : "Rutuja" }

// Finding by name
> db.student.find({'name':'mohit'})
{ "_id" : ObjectId("6010291c3e5b451a6eeb4264"), "name" : "mohit" }
```

* Updating Document:
```bash
> db.student.update({'name':'Rutuja'},{$set:{'name':'Sakshi'}})
WriteResult({ "nMatched" : 1, "nUpserted" : 0, "nModified" : 1 })
> db.student.find()
{ "_id" : ObjectId("6010291c3e5b451a6eeb4264"), "name" : "mohit" }
{ "_id" : ObjectId("60102acc3e5b451a6eeb4265"), "name" : "Hemanshu" }
{ "_id" : ObjectId("60102ad53e5b451a6eeb4266"), "name" : "Sakshi" }
```

* Delete Document:
```bash
> db.student.remove({'name':'Sakshi'})
WriteResult({ "nRemoved" : 1 })
> db.student.find()
{ "_id" : ObjectId("6010291c3e5b451a6eeb4264"), "name" : "mohit" }
{ "_id" : ObjectId("60102acc3e5b451a6eeb4265"), "name" : "Hemanshu" }
```

--------- END ---------
------