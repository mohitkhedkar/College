// Write C++/Java program for line drawing using DDA or Bresenhams algorithm with patterns such as solid, dotted, dashed, dash dot and thick

// Author: Mohit Khedkar.

#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
using namespace std;

int xmax,ymax,xmid,ymid;

class Line {
    public:
    int x1,x2,y1,y2,ch;

        void bss(int x1,int y1,int x2,int y2) {

         int dx,dy,x,y,s1,s2,ex,e,i,flag=0,temp;
            
         dx=abs(x2-x1);
         dy=abs(y2-y1);
         x=x1;
         y=y1;
         putpixel(x+xmid,ymid-y,15);
            
        if(x2>x1) {
            s1=1;
        }
        if(x2==x1) {
            s1=0;
        }
        if(x2<x1) {
            s1=-1;
        }
        if(y2>y1) {
            s2=1;
        }
        if(y2==y1) {
            s2=0;
        }
        if(y2<y1) {
            s2=-1;
        }
        if(dy>dx) {
            temp=dx;
            dx=dy;
            dy=temp;
            ex=1;
        }
        else {
            ex=0;
        }

            e=2*dy-dx;
                i=1;            

        do {
            while(e>0) {
                if(ex==1)
                    x=x+s1;
                else
                    y=y+s2;
                
                        e=e-2*dx;
            }
            while(e<0) {
                    
            if(ex==1)
                y=y+s2;
            else
                x=x+s1;
            
                    e=e+2*dy;

            }

            switch(ch) {
                    
                case 1:
                     putpixel(x+xmid,ymid-y,15);
                break;
                
                case 2:
                    if(flag==0) {
                        putpixel(x+xmid,ymid-y,15);
                        delay(1000);
                    }                            
                    if(i%5==0) {
                        if(flag==1)
                        flag=0;
                        else
                        flag=1;
                    }
                break;

                case 3:
                        if(flag==0) {
                                putpixel(x+xmid,ymid-y,15);
                                delay(100);
                        }
                            
                    if(i%5==0) {
                                    
                        if(flag==1)
                        flag=0;
                        else
                        flag=1;
                    }
                        if(i%3==0) {
                                putpixel(x+xmid,ymid-y,15);    
                                delay(1000);
                        }
                        
                 break;
            
                case 4:
                        if(flag==0) {
                                delay(1000);
                        }
                        else {
                            if(i%3==0)
                                    {
                                putpixel(x+xmid,ymid-y,15);
                                delay(1000);
                            }
                        }
                 break;
          
                case 5:
                        putpixel(x+xmid,ymid-y,15);
                 break;

                    }
                    i=i+1;
                    delay(50);
                }while(i<=dx);
    }
};

int main() {

int gd=DETECT,gm;
int x1,y1,x2,y2,thick,wx,wy,i;
Line B;
cout<<"Enter two end points of line\n";
cin>>x1>>y1;
cin>>x2>>y2;

while(1) {
    cout<<"\nEnter the Style\n";
    cout<<"1.Simple\n";
    cout<<"2.Dash\n";
    cout<<"3.Dash Dot\n";
    cout<<"4.Dot\n";
    cout<<"5.Thick\n";
    cout<<"6.Exit\n";
    cout<<"Enter your Style\n";
    cin>>B.ch;

    if(B.ch==5) {

        cout<<"Enter The Thickness of line: ";
        cin>>thick;
    }

    initgraph(&gd,&gm,NULL);
    xmax=getmaxx();
    ymax=getmaxy();
    xmid=xmax/2;
    ymid=ymax/2;

    if(B.ch<=4) {

        B.bss(x1,y1,x2,y2);
        delay(300);

    }
    else {
        B.bss(x1,y1,x2,y2);
        delay(300);

        if((y2-y1)/(x2-x1)<1) {
            wy=(thick-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*fabs(x2-x1));
            for(i=0;i<wy;i++) {
                B.bss(x1,y1-i,x2,y2-i);
                delay(300);
                B.bss(x1,y1+i,x2,y2+i);
                delay(300);
            }
        }
        else
            wx=(thick-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*fabs(y2-y1));
            for(i=0;i<wx;i++) {
                B.bss(x1-i,y1,x2-i,y2);
                delay(300);
                B.bss(x1+i,y1,x2+i,y2);
                delay(300);
            }
    }


            if(B.ch==6) {
            cout<<"Exiting....";
            exit(1);
            }
        closegraph();
        }
    return 0;

}