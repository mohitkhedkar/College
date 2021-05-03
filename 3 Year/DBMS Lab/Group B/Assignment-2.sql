-- Design and Develop MongoDB Queries using CRUD operations. (Use CRUD operations, SAVE method, logical operators)

-- Author: Mohit Khedkar 

> use mohit;
switched to db mohit
> db.createCollection('Student');
{ "ok" : 1 }
> db.Student.insert({'Rno':'1','Name':'Piyush','Class':'TE 
COMP'});
WriteResult({ "nInserted" : 1 })
> db.Student.insert({'Rno':'2','Name':'mohit','Class':'TE 
COMP'});
WriteResult({ "nInserted" : 1 })> db.Student.insert({'Rno':'3','Name':'Ashley','Class':'TE 
COMP'});
WriteResult({ "nInserted" : 1 })
> db.Student.insert({'Rno':'4','Name':'Hitesh','Class':'TE 
COMP'});
WriteResult({ "nInserted" : 1 })
> db.Student.insert({'Rno':'5','Name':'Pratik','Class':'TE 
COMP'});
WriteResult({ "nInserted" : 1 })
> db.Student.insert({'Rno':'6','Name':'Pratik','Class':'TE 
COMP'});
WriteResult({ "nInserted" : 1 })
> db.Student.find();
{ "_id" : ObjectId("5ba1d618f5bbacd4ad81568d"), "Rno" : "1", 
"Name" : "Piyush", "Class" : "TE COMP" }
{ "_id" : ObjectId("5ba1d625f5bbacd4ad81568e"), "Rno" : "2", 
"Name" : "mohit", "Class" : "TE COMP" }
{ "_id" : ObjectId("5ba1d63af5bbacd4ad81568f"), "Rno" : "3", 
"Name" : "Ashley", "Class" : "TE COMP" }
{ "_id" : ObjectId("5ba1d647f5bbacd4ad815690"), "Rno" : "4", 
"Name" : "Hitesh", "Class" : "TE COMP" }
{ "_id" : ObjectId("5ba1d65ef5bbacd4ad815691"), "Rno" : "5", 
"Name" : "Pratik", "Class" : "TE COMP" }
{ "_id" : ObjectId("5ba1d66df5bbacd4ad815692"), "Rno" : "6", 
"Name" : "Pratik", "Class" : "TE COMP" }
> db.Student.find().pretty();
{
"_id" : ObjectId("5ba1d618f5bbacd4ad81568d"),
"Rno" : "1",
"Name" : "Piyush",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d625f5bbacd4ad81568e"),
"Rno" : "2","Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d66df5bbacd4ad815692"),
"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.update({'Name':'Hitesh'},{$set:
{'Name':'Henry'}});
WriteResult({ "nMatched" : 1, "nUpserted" : 0, "nModified" : 1
})
> db.Student.find().pretty();{
"_id" : ObjectId("5b8fad4ef00832a0a50b5036"),
"Rno" : "1",
"Name" : "Piyush",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad62f00832a0a50b5037"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad70f00832a0a50b5038"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad7ff00832a0a50b5039"),
"Rno" : "4",
"Name" : "Henry",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad8df00832a0a50b503a"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fada4f00832a0a50b503b"),"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.remove({'ADD':'MP'});
WriteResult({ "nRemoved" : 1 })
> db.Student.find().pretty();
{
"_id" : ObjectId("5b8fad62f00832a0a50b5037"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad70f00832a0a50b5038"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad7ff00832a0a50b5039"),
"Rno" : "4",
"Name" : "Henry",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad8df00832a0a50b503a"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
{"_id" : ObjectId("5b8fada4f00832a0a50b503b"),
"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> 
db.Student.save({_id:ObjectId("5b8fad4ef00832a0a50b5036"),"RNO
":"1","NAME":"PIYUSH","CLASS":"TE COMP","ADD":"MP"});
WriteResult({ "nMatched" : 1, "nUpserted" : 0, "nModified" : 1
})
> db.Student.find().pretty();
{
"_id" : ObjectId("5b8fad4ef00832a0a50b5036"),
"RNO" : "1",
"NAME" : "PIYUSH",
"CLASS" : "TE COMP",
"ADD" : "MP"
}
{
"_id" : ObjectId("5b8fad62f00832a0a50b5037"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad70f00832a0a50b5038"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad7ff00832a0a50b5039"),
"Rno" : "4","Name" : "Henry",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fad8df00832a0a50b503a"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5b8fada4f00832a0a50b503b"),
"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find({$and:[{"Name":"Piyush"},{"Rno":"2"}]});
> db.Student.find({$and:[{"Name":"Piyush"},
{"Rno":"1"}]}).pretty();
{
"_id" : ObjectId("5ba1d618f5bbacd4ad81568d"),
"Rno" : "1",
"Name" : "Piyush",
"Class" : "TE COMP"
}
> db.Student.find({$and:[{"Name":"Piyush"},
{"Rno":"2"}]}).pretty();
> db.Student.find({$or:[{"Name":"Piyush"},
{"Rno":"2"}]}).pretty();
{
"_id" : ObjectId("5ba1d618f5bbacd4ad81568d"),
"Rno" : "1",
"Name" : "Piyush","Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d625f5bbacd4ad81568e"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
> db.Student.find({$or:[{"Name":"Piyush"},{"Class":"TE 
COMP"}]}).pretty();
{
"_id" : ObjectId("5ba1d618f5bbacd4ad81568d"),
"Rno" : "1",
"Name" : "Piyush",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d625f5bbacd4ad81568e"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh","Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d66df5bbacd4ad815692"),
"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find({$nor:[{"Name":"Piyush"},{"Class":"TE 
COMP"}]}).pretty();
> db.Student.find({$nor:[{"Name":"Piyush"},
{"Rno":"2"}]}).pretty();
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d66df5bbacd4ad815692"),
"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
db.Student.find( {"Rno": { $not:{$lt:"3"}}}).pretty();
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d66df5bbacd4ad815692"),
"Rno" : "6","Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $eq:"5"}}).pretty();
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $ne:"5"}}).pretty();
{
"_id" : ObjectId("5ba1d618f5bbacd4ad81568d"),
"Rno" : "1",
"Name" : "Piyush",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d625f5bbacd4ad81568e"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4","Name" : "Hitesh",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d66df5bbacd4ad815692"),
"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $gt:"5"}}).pretty();
{
"_id" : ObjectId("5ba1d66df5bbacd4ad815692"),
"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $gte:"5"}}).pretty();
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d66df5bbacd4ad815692"),
"Rno" : "6",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $lt:"5"}}).pretty();
{
"_id" : ObjectId("5ba1d618f5bbacd4ad81568d"),"Rno" : "1",
"Name" : "Piyush",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d625f5bbacd4ad81568e"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $lte:"5"}}).pretty();
{
"_id" : ObjectId("5ba1d618f5bbacd4ad81568d"),
"Rno" : "1",
"Name" : "Piyush",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d625f5bbacd4ad81568e"),
"Rno" : "2","Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $lt:"5",$gt:"2"}}).pretty();
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh","Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $lte:"5",$gte:"2"}}).pretty();
{
"_id" : ObjectId("5ba1d625f5bbacd4ad81568e"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $lte:"5",$gt:"2"}}).pretty();
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley","Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d65ef5bbacd4ad815691"),
"Rno" : "5",
"Name" : "Pratik",
"Class" : "TE COMP"
}
> db.Student.find( {"Rno": { $lt:"5",$gte:"2"}}).pretty();
{
"_id" : ObjectId("5ba1d625f5bbacd4ad81568e"),
"Rno" : "2",
"Name" : "mohit",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d63af5bbacd4ad81568f"),
"Rno" : "3",
"Name" : "Ashley",
"Class" : "TE COMP"
}
{
"_id" : ObjectId("5ba1d647f5bbacd4ad815690"),
"Rno" : "4",
"Name" : "Hitesh",
"Class" : "TE COMP"
}
