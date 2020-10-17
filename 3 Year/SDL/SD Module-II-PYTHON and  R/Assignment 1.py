# Getting Started with Python (Example Word count exercise)

# Author: Mohit Khedkar.

thislist=input("Enter the String: ")
a=thislist.split()

list=[]
for i in a:
    if i not in list:
        list.append(i)

for i in range(0,len(list)):
    print(list[i],a.count(list[i]))