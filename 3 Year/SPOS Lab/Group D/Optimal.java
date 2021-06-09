// Group D: Write a Java Program (using OOP features) to implement paging simulation using Optimal algorithm

import java.util.*;
class optimal{
public static void main(String args[]){
int n,m,i,j,k,mn,flag=0,pgfault=0;
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
int whn[]=new int[m];
for(i=0;i<m;i++){
frm[i]=a[i];
whn[i]=0;
}
for(;i<n;i++){
for(j=0;j<m;j++){
if(frm[j]==a[i]){
flag=1;
break;
}
else
flag=0;
}
if(flag==0){
for(j=0;j<m;j++){
for(k=i+1;k<n;k++){
if(frm[j]==a[k])
whn[j]=k;
else
whn[j]=0;
}
}
mn=ltr(whn,m);
frm[mn]=a[i];
pgfault++;
}
}
pgfault=pgfault+m;
System.out.println("Optimal algorithm");
System.out.println("page fault is:"+pgfault);
System.out.println("page hits are:"+(n-pgfault));
}
static int ltr(int whn[],int m){
int i,mn=0;
for(i=1;i<m;i++)
if((whn[i] > whn[i-1]) && (whn[i]!=0))
mn=i;
return mn;
}
}
