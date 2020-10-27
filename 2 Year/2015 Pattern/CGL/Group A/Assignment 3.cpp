// Write C++/Java program to draw 2-D object and perform following basic transformations.
// 1. Scaling
// 2. Translation
// 3. Rotation
//     Use operator overloading

// Author: Mohit Khedkar.

#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int pi[10];

double b[3][3]={1,0,0,
0,1,0,
0,0,1,
};
int c[1][1];
float a[1][1];
void matmul(float[]);

int main() {
    int op,i,x,y,tx,ty,sx,sy,angle=10,xmax,ymax,xmid,ymid;
    int gd,gm=VGAMAX;
    gd=DETECT;
    float p1[10]={
        50,50,
        100,50,
        100,100,
        50,100,
        50,50,
    };
    cout<<"\n select transformation:=";
    cout<<"\n 1.translation:=";
    cout<<"\n 2.rotation:=";
    cout<<"\n 3.scaling:=";
    cout<<"\n 4.rotation about arbitrary point:=";
    cout<<"\n 5.enter the option:=";
    cin>>op;
    switch(op)     {
    case 1:
        cout<<"\n enter the x translation:=";
        cin>>tx;
        cout<<"\n enter the y translation:="; 
        cin>>ty;
        b[0][0]=1;
        b[0][1]=0;
        b[0][2]=0;
        b[1][0]=0;
        b[1][1]=1;
        b[1][2]=0;
        b[2][0]=tx;
        b[2][1]=ty;
        b[2][2]=1;
    break;
    case 2:
        cout<<"\n enter the rotation angle :";
        cin>>angle;
        b[0][0]=cos(angle*3.142/180);
        b[0][1]=sin(angle*3.142/180);
        b[0][2]=0;
        b[1][0]=-sin(angle*3.142/180);
        b[1][1]=cos(angle*3.142/180);
        b[1][2]=0;
        b[2][0]=0;
        b[2][1]=0;
        b[2][2]=1;
    break;
    case 3:
        cout<<"\n enter the x scaling:";
        cin>>sx;
        cout<<"\n enter y scaling:";
        cin>>sy;
        b[0][0]=sx;
        b[0][1]=0;
        b[0][2]=0;
        b[1][0]=0;
        b[1][1]=sy;
        b[1][2]=0;
        b[2][0]=0;
        b[2][1]=0; 
        b[2][2]=1;
    break;
    case 4:
        cout<<"\n enter x coordinate of arbitatary point :";
        cin>>x;
        cout<<"\n enter x coordinate of arbitatary point:";
        cin>>y;
        cout<<"\n enter the rotation angle:=";
        cin>>angle;
        tx=x;
        ty=y;
        b[0][0]=cos(angle*3.142/180);
        b[0][1]=sin(angle*3.142/180);
        b[0][2]=0;
        b[1][0]=-sin(angle*3.142/180);
        b[1][1]=cos(angle*3.142/180);
        b[1][2]=0;
        b[2][0]=-tx*cos(angle*3.142/180)+ty*sin(angle*3.142/180)+tx;
        b[2][1]=-tx*sin(angle*3.142/180)-ty*cos(angle*3.142/180)+ty;
        b[2][2]=1;
    }

    initgraph(&gd,&gm,NULL); //initialize graphics
    xmax=getmaxx(); //get the maximum y coordinate
    ymax=getmaxy(); //get the maximum x co-ordinate
    xmid=xmax/2; //get the center x coordinate
    ymid=ymax/2; //get the center y coordinate
    setcolor(1);
    line(xmid,0,xmid,ymax); //draw y coordinate
    line(0,ymid,xmax,ymid); //draw x coordinate
    setcolor(4);
    for(i=0;i<8;i=i+2){
        line(p1[i]+xmid,ymid-p1[i+1],xmid+p1[i+2],ymid-p1[i+3]);
    }
    matmul(p1);
    setcolor(15);
    for(i=0;i<8;i=i+2){
     line(xmid+pi[i],ymid-pi[i+1],xmid+pi[i+2],ymid-pi[i+3]);
    }
    getch();
    closegraph();
    return 0;
}

void matmul(float p[10]) {
int i;
    for(i=0;i<9;i=i+2){
    a[0][0]=p[i];
    a[0][1]=p[i+1];
    c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+b[2][0];
    c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+b[2][1];
    pi[i]=c[0][0];
    pi[i+1]=c[0][1];
    }
}
