//  Write C++/Java program to generate fractal patterns by using Koch curves.

//  Author: Mohit KHedkar.

#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;

void k_curve(long double,long double,long double,long double,int);
void line1(int,int,int,int);

int main() {
int gd=DETECT,gm;
long double x=0;
long double y=0;
long double l=0;
long double angle=0;
int n=0;
cout<<“Starting point of the line:(x,y):”<<endl;
cout<<“_________________________________”<<endl;
cout<<“Enter the value of x=”<<endl;
cin>>x;
cout<<“Enter the value of y=”<<endl;
cin>>y;
cout<<“Enter the value of line:l:”<<endl;
cin>>l;
cout<<“Angle of the line with x axis:”<<endl;
cin>>angle;
cout<<“Enter the order of curve=n=”<<endl;
cin>>n;
initgraph(&gd,&gm,””);
k_curve(x,y,l,angle,n);
getch();
closegraph();
return 0;
}

void k_curve(long double x,long double y,long double lenght,long double angle,int n_order) {

     if(n_order>0) {
    lenght/=3;
    k_curve(x,y,lenght,angle,(n_order-1));
    x+=(lenght*cosl(angle*(M_PI/180)));
    y+=(lenght*sinl(angle*(M_PI/180)));
    k_curve(x,y,lenght,(angle-60),(n_order-1));
    x+=(lenght*cosl((angle-60)*(M_PI/180)));
    y+=(lenght*sinl((angle-60)*(M_PI/180)));
    k_curve(x,y,lenght,(angle+60),(n_order-1));
    x+=(lenght*cosl((angle+60)*(M_PI/180)));
    y+=(lenght*sinl((angle+60)*(M_PI/180)));
    k_curve(x,y,lenght,angle,(n_order-1));
    }
    else
    line1(x,y,(int)(x+lenght*cosl(angle*(M_PI/180))+0.5),(int)(y+lenght*sinl(angle*(M_PI
    /180))));
}

void line1(int x_1,int y_1, int x_2,int y_2) {
    int color=getcolor();
    int x1=x_1;
    int y1=y_1;
    int x2=x_2;
    int y2=y_2;
    if(x_1>x_2) {
    x1=x_2;
    y1=y_2;
    x2=x_1;
    y2=y_1;
    }
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int inc_dec=((y2>=y1)?1:-1);
        if(dx>dy) {
        int two_dy=(2*dy);
        int two_dy_dx=(2*(dy-dx));
        int p=((2*dy)-dx);
        int x=x1;
        int y=y1;
        putpixel(x,y,color);
        while(x<x2){
            x++;
            if(p<0)
            p+=two_dy;
            else{
            y+=inc_dec;
            p+=two_dy_dx;
            }
            putpixel(x,y,color);
        }
}
else {
    int two_dx=(2*dx);
    int two_dx_dy=(2*(dx-dy));
    int p=((2*dx)-dy);
    int x=x1;
    int y=y1;
    putpixel(x,y,color);
    while(y!=y2) {
            y+=inc_dec;
            if(p<0)
            p+=two_dx;
            else {
                x++;
            p+=two_dx_dy;
        }
        putpixel(x,y,color);
        }
    }
}