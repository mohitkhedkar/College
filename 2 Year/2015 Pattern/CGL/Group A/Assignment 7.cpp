// Write C++/Java program to draw inscribed and Circumscribed circles in the triangle as shown as an example below. (Use any Circle drawing and Line drawing algorithms) 

// Author: Mohit Khedkar.

#include<iostream>
#include<graphics.h>

using namespace std;

class algo {
    float r,x2,y2,x3,y3,dx,dy,len,len1,len2,dx1,dy1,dx2,dy2;
    int i;
    float x,y,ax,ay,cx,cy,a1,a2,a3,b1,b2,b3,c1,d1;
    public:
        void triangle(float x1, float y1) {

            float sx,qx,qy,sy;
            a1=sx=x1;
            b1=sy=y1;
            a2=x2=x1-150;
            b2=y2=y1+260;
            a3=x3=sx+150;
            b3=y3=sy+260;
            dx=x2-x1;
            dy=y2-y1;
            dx1=x3-x2;
            dy1=y3-y2;
            dx2=x3-sx;
            dy2=y3-sy;

                if(abs(dx)>=abs(dy))
                    len=abs(dx);
                else
                    len=abs(dy);
                x=dx/len;
                y=dy/len;

                for(i=1;i<len;i++)
                {
                    putpixel(x1,y1,5);
                    x1=x1+x;
                    y1=y1+y;
                }

                //----------------line 2
                if(abs(dx1)>=abs(dy1))
                    len1=abs(dx1);
                else
                    len1=abs(dy1);
                ax=dx1/len1;
                ay=dy1/len1;

                for(i=1;i<len1;i++)
                {
                    putpixel(x2,y2,6);
                    x2=x2+ax;
                    y2=y2+ay;
                }

                //---------------line 3
                if(dx2>=dy2)
                    len2=abs(dx2);
                else
                    len2=abs(dy2);
                cx=dx2/len2;
                cy=dy2/len2;

                for(i=1;i<len2;i++)
                {
                    putpixel(sx,sy,WHITE);
                    sx=sx+cx;
                    sy=sy+cy;
                }
        }

        void incircle() {
            float mx,my,d;
            c1=(a1+a2+a3)/3;
            d1=(b1+b2+b3)/3;
            //cout<<c1<<d1;
            c1--;
            r=85;
            mx=0;
            my=r;
            d=3-(2*r);

            while(mx<my) {
                putpixel(mx+c1,my+d1,15);
                putpixel(mx+c1,d1-my,2);
                putpixel(c1-mx,my+d1,3);
                putpixel(c1-mx,d1-my,4);
                putpixel(c1+my,d1+mx,5);
                putpixel(my+c1,d1-mx,6);
                putpixel(c1-my,d1+mx,12);
                putpixel(c1-my,d1-mx,8);
                if(d<=0)
                {
                    d=d+(4*mx)+6;
                    mx++;
                }
                else
                {
                    d=d+(4*(mx-my))+10;
                    mx++;
                    my--;
                }
            }
        }

        void circumcircle() {
            float mx,my,d,r1;
            c1=(a1+a2+a3)/3;
            d1=(b1+b2+b3)/3;

            r1=173.33;
            mx=0;
            my=r1;
            d=3-(2*r1);

            while(mx<my)
            {
                putpixel(mx+c1,my+d1,11);
                putpixel(mx+c1,d1-my,12);
                putpixel(c1-mx,my+d1,WHITE);
                putpixel(c1-mx,d1-my,14);
                putpixel(c1+my,d1+mx,9);
                putpixel(my+c1,d1-mx,6);
                putpixel(c1-my,d1+mx,2);
                putpixel(c1-my,d1-mx,4);
                if(d<=0)
                {
                    d=d+(4*mx)+6;
                    mx++;
                }
                else
                {
                    d=d+(4*(mx-my))+10;
                    mx++;
                    my--;
                }
            }
        }
};

int main() {


    int gd,gm;
    float x1,y1;
    gd=DETECT;

    cout<<"Enter top coordinates of triangle";
    cin>>x1>>y1;

    initgraph(&gd,&gm,NULL);

    s.triangle(x1,y1);     //Calling the triangle drwaing function
    s.incircle();
    s.circumcircle();

    getch();
    cleardevice();
    closegraph();

}