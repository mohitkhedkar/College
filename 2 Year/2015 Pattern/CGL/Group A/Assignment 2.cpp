// Write C++/Java program to draw circle using Bresenham‘s algorithm. Inherit pixel class.

// Author: Mohit Khedkar.

#include<iostream>
#include<graphics.h>

using namespace std;

class pixel
{
      
  public:
          float x1,y1,r;
          void brecircle(float x1,float y1,float r);
    
};


class point : public pixel
{

          pixel p;

  public:
          void Drawcircle()
          {
                cout<<"Enter the starting co-ordinates of a center:";
             cin>>p.x1>>p.y1;
             cout<<"Enter the value of radius:";
             cin>>p.r; 
                brecircle(p.x1,p.y1,p.r);
          }
};


void pixel::brecircle(float x1,float y1,float r)
{
       
          float x,y,p;
       x=0;
       y=r;
       p=3-(2*r);
       while(x<=y)
       {
           putpixel(x1+x,y1+y,WHITE);
           putpixel(x1-x,y1+y,WHITE);
           putpixel(x1+x,y1-y,WHITE);
           putpixel(x1-x,y1-y,WHITE);
           putpixel(x1+y,y1+x,WHITE);
           putpixel(x1+y,y1-x,WHITE);
           putpixel(x1-y,y1+x,WHITE);
           putpixel(x1-y,y1-x,WHITE);
           x=x+1;
           if(p<0)
           {
                p=p+4*(x)+6;
           }
           else
           {
                p=p+4*(x-y)+10;
                y=y-1;
           }
           delay(20);
      }
}


int main()
{
         int gd=DETECT,gm;
         initgraph(&gd,&gm,NULL);
    
         point pt;

         pt.Drawcircle();
   
         delay(50000);
         closegraph();
         return 0;
}