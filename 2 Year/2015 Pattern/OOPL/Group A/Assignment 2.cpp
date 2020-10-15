// Implement a class Complex which represents the Complex Number data type.
// Implement the following operations:
// 1.Constructor (including a default constructor which creates the complex number 0+0i).
// 2.Overloaded operator+ to add two complex numbers.
// 3.Overloaded operator* to multiply two complex numbers.
// 4.Overloaded << and >> to print and read Complex Numbers. 

// Author: Mohit Khedkar

#include<iostream>
using namespace std;

class complex {

float  real,img;
public:
    complex(float x1,float x2) {
    real=x1;
    img=x2;
}

    complex(){
     real=img=0;
    }

friend istream &operator>>(istream &in,complex &t) {//operator >> overloaded

    in>>t.real>>t.img;
    return in;
}

complex operator+(complex t) { //operator + overloaded

    complex z;
    z.real=this->real+t.real;
    z.img=this->img+t.img;
    return z;
}

complex operator*(complex t) { //operator * overloaded

    complex z;
    z.real=this->real*t.real-this->img*t.img;
    z.img=this->img*t.real+this->real*t.img;
    return z;
}


friend ostream &operator<<(ostream &op,complex &t) { //operator << overloaded
    op<<t.real<<"+i"<<t.img;
    return op;
    }

};

int main(){ 
    
    complex c1,c2(3,5),c3,c4;
    int c;
    char ch;
    do
        {
        cout<<"MENU\n";
        cout<<"1. Addition of two complex no\n";
        cout<<"2. Multiplication of two complex no\n";
        cout<<"Enter your choice :";
        cin>>c;
        switch(c) {
            case 1:
                cout<<"enter real & img  part of complex no. 1\n";
                cin>>c1;
                cout<<"enter real & img  part of complex no. 2\n";
                cin>>c2;
                c3=c1+c2;
                cout<<"addition is : ";
                cout<<c3<<"\n";
            break;

            case 2:
                cout<<"enter real & img  part of complex no. 1\n";
                cin>>c1;
                cout<<"enter real & img  part of complex no. 2\n";
                cin>>c2;
                cout<<"multiplication is :";
                c4=c1*c2;
                cout<<c4<<"\n";
            break;

            }
        
        cout<<"do you want to continue";
        cin>>ch;

    }while(ch=='y'||ch=='Y');

}
