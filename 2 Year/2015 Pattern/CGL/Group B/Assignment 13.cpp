//  Write C++/Java program to implement Cohen-Sutherland line clipping algorithm for given window. Draw line using mouse interfacing to draw polygon.

//  Author: Mohit Khedkar.

#include<iostream>
#include<graphics.h>
using namespace std;

class clipping
{
    float a1,b1,a2,b2;
    float x1,x2,x3,x4,y1,y2,y3,y4;
    float y;

    public:
        clipping()
        {
            a1=100;
            a2=400;
            b1=100;
            b2=400;
        }
        void window()
        {
            rectangle(a1,b1,a2,b2);
        }
        void lget()
        {
            cout<<"\n\t --------------LINE DRAWING---------------";

            cout<<"\n\t Enter the coordinates for (x1,y1): ";
            cin>>x1>>y1;

            cout<<"\n\t Enter the coordinates for (x2,y2)";
            cin>>x2>>y2;
            line(x1,y1,x2,y2);

        }
        void clip()
        {
            if((x1<a1)&&(x1<a2)&&(x2>a1)&&(x2<a2)&&(y1>b1)&&(y1<b2)&&(y2>b1)&&(y2<b2))            //LEFT
            {
                if(x2-x1!=0)
                    y1=valint(a1);
                line(a1,y1,x2,y2);
                outtextxy(150,150,"The left side of line is clipped");
            }
            if((x1>a1)&&(x1<a2)&&(x2>a1)&&(x2>a2)&&(y1>b1)&&(y1<b2)&&(y2>b1)&&(y2<b2))        //RIGHT
            {
                if(x2-x1!=0)
                    y2=valint(a2);
                line(x1,y1,a2,y2);
                outtextxy(150,150,"The right side of line is clipped");
            }
            if((x1>a1)&&(x1<a2)&&(x2>a1)&&(x2<a2)&&(y1<b1)&&(y1<b2)&&(y2>b1)&&(y2<b2))        //TOP
            {
                if(y2-y1!=0)
                    x1=valinta(b1);
                line(x1,b1,x2,y2);
                outtextxy(150,150,"The top side of line is clipped");
            }
            if((x1>a1)&&(x1<a2)&&(x2>a1)&&(x2<a2)&&(y1>b1)&&(y1<b2)&&(y2>b1)&&(y2>b2))        //BOTTOM
            {
                if(y2-y1!=0)
                    x2=valinta(b2);
                line(x1,y1,x2,b2);
                outtextxy(150,150,"The bottom side of line is clipped");
            }
            if((x1>a1)&&(x1<a2)&&(x2>a1)&&(x2<a2)&&(y1>b1)&&(y1<b2)&&(y2>b1)&&(y2<b2))        //INSIDE
            {
                line(x1,y1,x2,y2);
                outtextxy(150,150,"The line is inside the window");
            }
        }

        float valint(float x)
        {
            float m,b;

                m=(y2-y1)/(x2-x1);
                b=y1-(m*x1);
                y=(m*x)+b;

            return y;
        }

        float valinta(float y)
        {
            float m1,b1;

                m1=(x2-x1)/(y2-y1);
                b1=x1-(m1*y1);
                y=(m1*y)+b1;

            return y;
        }
}c;

int main() {
    int gd=0,gm;

    initgraph(&gd,&gm,NULL);

    c.window();
    c.lget();
    delay(3000);
    cleardevice();
    c.window();
    c.clip();

    delay(5000);
    getch();
    cleardevice();
    closegraph();
}