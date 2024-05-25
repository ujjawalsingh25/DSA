#include<bits/stdc++.h>
using namespace std;

class pntr {
    protected:
        int a, b;
    public:
        pntr(int x) : a(x), b(0) {} 
        void display(){
            cout<<a<<endl;
        }
};
int main()
{
    int a=5;
    int *ptr=&a;
    cout<<"\n-------------"<<endl;
    cout<<" --MEMORY ADDRESS--"<<endl;
    cout<<&a<<endl;   // -> Memory Address of 'a'.
    cout<<ptr<<endl;  // -> Memory block of int size containing the memory address of 'a'.
    cout<<"\n --VALUE CONTAINING IN THE MEMORY ADDRESS--"<<endl;
    cout<<"Value of a :"<<a<<endl;      // Value of 'a' taken from user.
    cout<<"Value of a with pointer:"<<(*ptr)<<endl; // -> Dereferencing Operator 
                        // On '*'on ptr it gives the value within the address of 'a'.
                        // OR, the value containing in address that ptr storing. 

     *ptr=20;
    cout<<"New value of a changed through pointer: "<<a<<"\n"<<endl;

     cout<<"-- (NEW-DELETE) --"<<endl;
     int b=3;
    //cin>>b;
    int *c = new int(b);
    cout<<"Value of b: "<<(*c)<<endl; //Value of 'b' with making new pointer 'c' with 'new' keyboard.
    *c=100;
    b=*c;
    cout<<"New value of b changed through pointer: "<<b<<endl;
    cout<<"- ARRAY -"<<endl;
    int *arr = new int[3];  //-> Allocate memory size to store address of the 3 interger in a memory block 
                            //   & address of first block given to ptr and on increasing the value access the each block. 
    //delete[] arr;
    arr[0]=20;
   // delete[] arr;
    arr[1]=30;
    //delete[] arr;
    *(arr+2)=40;    //-> It takes "arr[2]" as arr have a memory address from arr[0] and it increases to 2, i.e arr[2].
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
    

    cout<<"\n --POINTERS IN OBJECT--"<<endl;
    pntr obj(2);
    pntr *p =&obj;
    pntr *pr = new pntr(5);
    pntr *potr = new pntr(10);
    (*p).display(); //Without using arrow operator " -> ".
    pr->display();  //Using arrow operator " -> ".
    potr->display();  //Using arrow operator " -> ".
    delete p;
    delete pr;
    delete potr;
    cout<<"---------\n"<<endl;

    return 0;
}