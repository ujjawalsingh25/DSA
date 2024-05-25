#include<iostream>
#include<queue>
using namespace std;

class Queue
{
    private:
        int *arr;
        int qfront;
        int rear;
        int size;
    
    public:

        Queue(int size): qfront(0), rear(0), size(size), arr(new int[size]) {}

        bool isEmpty(){
            if(qfront == rear)   return true;
            else        return false;
        }

        int front(){
            if(qfront == rear){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            else    return arr[qfront];
        }

        void enqueue(int data){
            if(rear == size)    cout<<"Queue is Full"<<endl;

            arr[rear] = data;
            rear++;
        }

        int dequeue(){
            if(qfront == rear){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            else{
                int popData = arr[qfront];
                arr[qfront] = -1;
                qfront++;
                if(qfront == rear){
                    qfront = 0;
                    rear = 0;
                }
              return popData;  
            }
        }
};


int main()
{
    Queue quu(5);

    if(quu.isEmpty())  cout<<"Queue is empty"<<endl;
    else    cout<<"Queue is not empty"<<endl;
    cout<<quu.front()<<endl;
    quu.dequeue();

    quu.enqueue(1);
    quu.enqueue(2);
    quu.enqueue(3);
    quu.enqueue(4);
    quu.enqueue(5);

    if(quu.isEmpty())  cout<<"Queue is empty"<<endl;
    else    cout<<"Queue is not empty"<<endl;

    cout<<"Front Element: "<<quu.front()<<endl;
    quu.dequeue();
    cout<<"Front Element: "<<quu.front()<<endl;
    quu.dequeue();
    cout<<"Front Element: "<<quu.front()<<endl;
    quu.dequeue();
    cout<<"Front Element: "<<quu.front()<<endl;
    quu.dequeue();
    cout<<"Front Element: "<<quu.front()<<endl;
    quu.dequeue();
    cout<<"Front Element: "<<quu.front()<<endl;


    return 0;
}