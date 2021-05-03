-- Implement aggregation and indexing with suitable example using MongoDB.

-- Author: Mohit Khedkar

> use comp;
switched to db comp
//CREATE COLLECTION WEBSITE
> db.createCollection('website');
{ "ok" : 1 }
//INSERT VALUES IN WEBSITE
> 
db.website.insert({'roll':'1','name':'harsh','amount':1000,'ur
l':'www.yahoo.com'});
WriteResult({ "nInserted" : 1 })
> 
db.website.insert({'roll':'2','name':'jitesh','amount':2000,'u
rl':'www.yahoo.com'});
WriteResult({ "nInserted" : 1 })> 
db.website.insert({'roll':'3','name':'rina','amount':3000,'url
':'www.google.com'});
WriteResult({ "nInserted" : 1 })
> 
db.website.insert({'roll':'4','name':'ash','amount':4000,'url'
:'www.gmail.com'});
WriteResult({ "nInserted" : 1 })
> 
db.website.insert({'roll':'5','name':'ash','amount':1000,'url'
:'www.pvg.com'});WriteResult({ "nInserted" : 1 })
//SUM AGGREGATE
> db.website.aggregate({$group:{_id:"$name","total":
{$sum:"$amount"}}});
{ "_id" : "ash", "total" : 5000 }
{ "_id" : "rina", "total" : 3000 }
{ "_id" : "jitesh", "total" : 2000 }
{ "_id" : "harsh", "total" : 2000 }
//AVG AGGREGATE
> db.website.aggregate({$group:{_id:"$name","total":
{$avg:"$amount"}}});
{ "_id" : "ash", "total" : 2500 }
{ "_id" : "rina", "total" : 3000 }
{ "_id" : "jitesh", "total" : 2000 }
{ "_id" : "harsh", "total" : 1000 }
//MIN AGGREGATION
> db.website.aggregate({$group:{_id:"$name","total":
{$min:"$amount"}}});
{ "_id" : "ash", "total" : 1000 }
{ "_id" : "rina", "total" : 3000 }
{ "_id" : "jitesh", "total" : 2000 }
{ "_id" : "harsh", "total" : 1000 }
//MAX AGGREGATION
> db.website.aggregate({$group:{_id:"$name","total":
{$max:"$amount"}}});{ "_id" : "ash", "total" : 4000 }
{ "_id" : "rina", "total" : 3000 }
{ "_id" : "jitesh", "total" : 2000 }
{ "_id" : "harsh", "total" : 1000 }
//FIRST AGGREGATION
> db.website.aggregate({$group:{_id:"$name","total":
{$first:"$amount"}}});
{ "_id" : "ash", "total" : 4000 }
{ "_id" : "rina", "total" : 3000 }
{ "_id" : "jitesh", "total" : 2000 }
{ "_id" : "harsh", "total" : 1000 }//LAST AGGREGATION
> db.website.aggregate({$group:{_id:"$name","total":
{$last:"$amount"}}});
{ "_id" : "ash", "total" : 1000 }
{ "_id" : "rina", "total" : 3000 }
{ "_id" : "jitesh", "total" : 2000 }
{ "_id" : "harsh", "total" : 1000 }
//PUSH AGGREGATION
> db.website.aggregate({$group:{_id:"$name","total":
{$push:"$amount"}}});
{ "_id" : "ash", "total" : [ 4000, 1000 ] }
{ "_id" : "rina", "total" : [ 3000 ] }
{ "_id" : "jitesh", "total" : [ 2000 ] }
{ "_id" : "harsh", "total" : [ 1000, 1000 ] }
//COUNT AGGREGATION
> db.website.aggregate({$group:{_id:"$name","total":
{$sum:1}}});
{ "_id" : "ash", "total" : 2 }
{ "_id" : "rina", "total" : 1 }
{ "_id" : "jitesh", "total" : 1 }
{ "_id" : "harsh", "total" : 2 }
//ADDTOSET AGGREGATE> db.website.aggregate({$group:{_id:"$name","total":
{$addToSet:"$amount"}}});
{ "_id" : "ash", "total" : [ 1000, 4000 ] }
{ "_id" : "rina", "total" : [ 3000 ] }
{ "_id" : "jitesh", "total" : [ 2000 ] }
{ "_id" : "harsh", "total" : [ 1000 ] }
//INDEXING
> db.createCollection('website1');
{ "ok" : 1 }
> db.website1.insert({'r':1,'name':'harsh'});
WriteResult({ "nInserted" : 1 })
> db.website1.find().pretty()
{ "_id" : ObjectId("5ba3509a444926329738012d"), "roll" : 1, 
"name" : "harsh" }
{ "_id" : ObjectId("5ba35293444926329738012e"), "roll" : 1, 
"name" : "harsh" }
> db.website1.createIndex({'name':1})
{ "numIndexesBefore" : 2, "note" : "all indexes already 
exist", "ok" : 1 }//CREATE INDEXING
> db.website1.createIndex({'name':-1})
{
"createdCollectionAutomatically" : false,
"numIndexesBefore" : 2,
"numIndexesAfter" : 3,
"ok" : 1
}
> db.website1.getIndexses()
2018-09-20T13:28:09.628+0530 TypeError: Property 'getIndexses'
of object om.website is not a
function
> db.website1.getIndexes()
[
{"v" : 1,
"key" : {
"_id" : 1
},
"name" : "_id_",
"ns" : "harsh.website1"
},
{
"v" : 1,
"key" : {
"name" : 1
},
"name" : "name_1",
"ns" : "harsh.website1"
},
{
"v" : 1,
"key" : {
"name" : -1
},
"name" : "name_-1",
"ns" : "harsh.website1"
}
]
> db.website1.createIndex({'name':-1})
{ "numIndexesBefore" : 3, "note" : "all indexes already 
exist", "ok" : 1 }
//DROP INDEX
> db.website.dropIndex({'name':-1})
{ "nIndexesWas" : 3, "ok" : 1 }> 
db.website1.dropIndex({'name':1})
{ "nIndexesWas" : 2, "ok" : 1 }> db.website1.dropIndex({'name':1})
{
"nIndexesWas" : 1,
"ok" : 0,
"errmsg" : "can't find index with key:{ name: 1.0 }"
}
//GET INDEXING
> db.website1.getIndexes()
[
{
"v" : 1,
"key" : {
"_id" : 1
},
"name" : "_id_",
"ns" : "harsh.website1"
}
]
> db.website1.find().pretty()
{ "_id" : ObjectId("5ba3509a444926329738012d"), "roll" : 1, 
"name" : "harsh" }
{ "_id" : ObjectId("5ba35293444926329738012e"), "roll" : 1, 
"name" : "harsh" }
>
> db.website1.createIndex({'name':1})
{
"createdCollectionAutomatically" : false,
"numIndexesBefore" : 1,
"numIndexesAfter" : 2,
"ok" : 1
}
> db.website1.getIndexes()[
{
"v" : 1,
"key" : {
"_id" : 1
},
"name" : "_id_",
"ns" : "harsh.website1"
},
{
"v" : 1,
"key" : {"name" : 1
},
"name" : "name_1",
"ns" : "harsh.website1"
}
]
> db.website1.dropIndex({'name':1})
{ "nIndexesWas" : 2, "ok" : 1 }
> db.website1.getIndexes()
[
{
"v" : 1,
"key" : {
"_id" : 1
},
"name" : "_id_",
"ns" : "harsh.website1"
}
]
> db.website1.createIndex({'name':1,'r':-1})
{"createdCollectionAutomatically" : false,
"numIndexesBefore" : 1,
"numIndexesAfter" : 2,
"ok" : 1
}
> db.website1.getIndexes()
[
{
"v" : 1,
"key" : {
"_id" : 1
},
"name" : "_id_",
"ns" : "harsh.website1"
},
{
"v" : 1,
"key" : {
"name" : 1,
"r" : -1
},
"name" : "name_1_r_-1",
"ns" : "harsh.website1"
}
] (i-search)`db.website1.insert({'roll':1,'name':'harsh'});
'