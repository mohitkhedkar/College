## Assignment-1: Study of Open Source NOSQL Database: MongoDB (Installation, Basic CRUD operations,Execution)

### Author: Mohit Khedkar.

## Installation Guide:


* [For Windows](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-windows/)

* [For Linux (Ubuntu)](https://docs.mongodb.com/manual/tutorial/install-mongodb-on-ubuntu/)


##### Basic CRUD Operation

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