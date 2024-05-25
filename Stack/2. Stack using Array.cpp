#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
        int *arr;
        int top; 
        int size;

    // Stack(int size): size(size), top(-1), arr(new int[size]) {}
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 0){
            top++; 
            arr[top] = element;
        }
        else    cout<<"Stack Overflow"<<endl;
    }

    void pop(){
        if(top >= 0)   top--;
        else    cout<<"Stack Underflow"<<endl;  
    }

    int peek(){
        if(top >= 0)  return arr[top];
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1)  return true;
        else    return false;
    }
};

int main()
{
    Stack st(5);    // -->> Constructor obj(size);
    
    cout<<st.peek()<<endl;
    st.pop();

    st.push(25);
    st.push(31);
    st.push(66);
    st.push(54);
    st.push(34);

    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

    if(st.isEmpty())  cout<<"Stack is empty"<<endl;
    else    cout<<"Stack is not empty"<<endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    if(st.isEmpty())  cout<<"Stack is empty"<<endl;
    else    cout<<"Stack is not empty"<<endl;

   return 0;
}