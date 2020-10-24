// Write C++/Java program to draw a convex polygon and fill it with desired color using Seed fill algorithm. Use mouse interfacing to draw polygon.

// Author: Mohit Khedkar.

#include<iostream>
#include<graphics.h>
using namespace std;

void boundary(int x, int y, int newcol,int edgecol) {
 int current;
 current = getpixel(x, y);
 if(current != edgecol && current != newcol)
  {
  putpixel(x,y,newcol);
 
  boundary(x+1, y, newcol,edgecol);
  boundary(x,y+1, newcol,edgecol);
  boundary(x-1,y, newcol,edgecol);
  boundary(x, y-1, newcol,edgecol);
  }
  
}


void flood(int x, int y, int newcol,int oldcol) { 
 if(getpixel(x, y) == oldcol)
  {
  putpixel(x,y,newcol);
  flood(x+1, y, newcol,oldcol);
  flood(x-1,y, newcol,oldcol);
  flood(x,y+1, newcol,oldcol);
  flood(x, y-1, newcol,oldcol);
  }
  delay(3);
}

int main() {
 int x1,x2,y1,y2,x3,y3,x4,y4;
 int x5,y5,x6,y6;
 
  cout<<"\nEnter co-ordinates of left top corner of rectangle one: ";
  cin>>x1>>y1;
  cout<<"\nEnter co-ordinates of bottom right corner of rectangle one: ";
  cin>>x2>>y2;
  x5=((x2-x1)/2)+x1;
  y5=((y2-y1)/2)+y1;
    
  cout<<"\nEnter co-ordinates of first point for 2nd rectangle:";
  cin>>x3>>y3;
  cout<<"\nEnter co-ordinates of second point for 2nd rectangle:";
  cin>>x4>>y4;
  x6=((x4-x3)/2)+x3;
  y6=((y4-y3)/2)+y3;
 
 int gd=0,gm;
 initgraph(&gd,&gm,NULL);
 
 rectangle(x1,y1,x2,y2);
 rectangle(x3,y3,x4,y4);
 
 boundary(x5,y5,8,15);
 
 flood(x6,y6,10,0);
 
 getch();
 cleardevice();
    closegraph();
 return 0;

}