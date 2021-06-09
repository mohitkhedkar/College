// Group D: Write a Java Program (using OOP features) to implement   paging simulation using Least Recently Used (LRU)

import java.util.*;
class lru {
public static void main(String args[]) {
int n,m,i,j,mn,flag=0,pgfault=0,timestamp=0;
Scanner sc=new Scanner(System.in);
System.out.println("Enter no of pages");
n=sc.nextInt();
System.out.println("enter page nos");
int a[]=new int[n];
for(i=0;i<n;i++)
a[i]=sc.nextInt();
System.out.println("Enter no of frames");
m=sc.nextInt();
int frm[]=new int[m];
int ts[]=new int[m];
for(i=0;i<m;i++){
frm[i]=a[i];
ts[i]=timestamp++;
}
for(;i<n;i++){
for(j=0;j<m;j++){
if(frm[j]==a[i]){
ts[j]=timestamp++;
flag=1;
break;
}
else
flag=0;
}
if(flag==0){
mn=min(ts,m);
frm[mn]=a[i];
ts[mn]=timestamp++;
pgfault++;
}
}
pgfault=pgfault+m;
System.out.println("least recently used(LRU) algorithm");
System.out.println("page fault is:"+pgfault);
System.out.println("page hits are:"+(n-pgfault));
}
static int min(int ts[],int m){
int i,mn=0;
for(i=1;i<m;i++)
if(ts[i]<ts[i-1])
mn=i;
return mn;
}
}
