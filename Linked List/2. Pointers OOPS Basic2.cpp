#include<iostream>
using namespace std;

// B: 5
// D: 3

class Base{
    public:
        int b;
       void display(){
            cout<<"B: "<<b<<endl;
        }
};

class Derived : public Base{
    public:
            int d;
             void display(){
                cout<<"B: "<<b<<endl;
                cout<<"D: "<<d<<endl;
            }
};
int main(){
    Base * bptr;
    Base objb;
    Derived objd;
    bptr = &objd; 
/*
    bptr->b = 34; // || (*bptr).b=34;
    // bptr->d= 134; -- error--  base class pointer can't access derived class data
    bptr->display();

    bptr->b = 12; 
    bptr->display();
*/
    Derived * dptr;
    dptr = &objd;
    dptr->b = 5;
    dptr->d = 3;
    dptr->display();
    
    // ----- OR --- Without Pointer
    // Derived obj;
    // obj.b=2;
    // obj.d=9;
    // obj.display();

    return 0;
}