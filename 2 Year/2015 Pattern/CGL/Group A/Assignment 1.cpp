// Write C++/Java program to draw line using DDA and Bresenham‘s algorithm. Inherit pixel class and Use function overloading.

// Author: Mohit Khedkar

#include<iostream>
#include<graphics.h>

using namespace std;

class pixel
{
           float dx,dy,x,y;
      
   public:  int x1,y1,x2,y2;
            float c,xa,ya,xb,yb;
            void Drawline(int,int,int,int);
            void Drawline(float,float,float,float);    
};


class point : public pixel
{

            pixel p;
  public:
            void getdata1()
            {
                 cout<<"\n Enter the integer type value x1,y1,x2,y2";
                 cin>>p.x1>>p.y1>>p.x2>>p.y2;
                 Drawline(p.x1,p.y1,p.x2,p.y2);
            }
            void getdata2()
            {
               
                 cout<<"\n Enter the floating type values xa,ya,xb,yb";
                 cin>>p.xa>>p.ya>>p.xb>>p.yb;
                 Drawline(p.xa,p.ya,p.xb,p.yb);
            }
};


void pixel::Drawline(int dx1,int dy1,int dx2,int dy2)
{
  
         // Implementation of DDA Line Drawing Algorithm
     
   
           float steps,xinc,yinc,i;
      
           dx=abs(dx2-dx1);
           dy=abs(dy2-dy1);
   
           if(dx>=dy)
           {
                steps=dx;
           }
           else
           {
                steps=dy;
           }

           xinc=(dx2-dx1)/steps;
           yinc=(dy2-dy1)/steps;

           x=dx1+(0.5*signbit(xinc));
           y=dy1+(0.5*signbit(yinc));

           while(i<=steps)
           {
                 x=x+xinc;
                 y=y+yinc;
                 putpixel(x,y,15);
                 i=i+1;
           }
}

void pixel::Drawline(float bx1,float by1,float bx2,float by2)
{  

          // Implementation of Bresenhams Line Drawing Algorithm
     
           float p,xend;
     
           dx=abs(bx2-bx1);
           dy=abs(by2-by1);

           p=((2*dy)-dx);

           if(bx1>bx2)
           {
                  x=bx2;
                  y=by2;
                  xend=bx1;
           }
           else
           {
                  x=bx1;
                  y=by1;
                  xend=bx2;
           }
    
           putpixel (x,y,15);
    
           while(x<xend)
           {
                  x=x+1;
                 
                  if (p<0)
                  {
                        p=p+2*dy;
                  }
                  else
                  {
                        y=y+1;
                        p=p+2*(dy-dx);
                  }
                 
                  putpixel (x,y,15);          
           }
}


int main()
{
      int gd=DETECT,gm;
      initgraph(&gd,&gm,NULL);
    
      int ch;
      char choice;
          
      point pt;

      do
      {

             cout<<"\n Welcome to Line Drawing";
             cout<<"\n 1. DDA ALGORITHM";
             cout<<"\n 2. BRESENHAMS ALGORITHM";
             cin>>ch;

             switch(ch)
             {
                    case 1:
                              cout<<"\n DDA ALGORITHM";
                              pt.getdata1();
                              break;

                    case 2:
                              cout<<"\n BRESENHAMS ALGORITHM";
                              pt.getdata2();
                              break;
             }
             cout<<"\n Do you want to continue(y\n)";
             cin>>choice;
       }while(choice=='y'|| choice== 'Y');


       delay(50000);
       closegraph();
       return 0;
}
