//Need to modify -- >> Circular
//Need to modify -- >> Circular
//Need to modify -- >> Circular

#include<iostream>
#include<queue>
using namespace std;

class DoubleEnded_Queue
{
    int *arr;
    int front, rear, size;

    public:

        bool isEmpty(){
            if(qfront ==-1)   return true;
            else        return false;
        }

        int front(){
            if(qfront == -1){
                cout<<"Queue is Empty"<<"-->> front"<<endl;
                return -1;
            }
            else    return arr[qfront];
        }

        void enqueue(int data){
            if(qfront == 0 && rear == size-1 || rear == (qfront-1)%(size-1) ){
                cout<<"Queue iS Full"<<endl;
            }
            else if(qfront == -1){    // first element to be push
                qfront = rear = 0;
            }
            else if(qfront != 0 && rear == size-1){    // front moved forward near mid and rear is at end.
                rear = 0;
            }
            else    rear++;         // Front is at first index and rear to move further.

            arr[rear] = data;
        }

        int dequeue(){
            if(qfront == -1){
                cout<<"Queue is Empty"<<"-->> dequeue"<<endl;
                return -1;
            }
            else{
                int popData = arr[qfront];
                arr[qfront] = -1;
                if(qfront == rear){         // Single element is present
                    qfront = rear = -1;
                }
                else if(qfront == size-1){
                    qfront = 0;              // For cyclic nature
                }
                else    qfront++;

              return popData;  
            }
        }
    
        
};

int main()
{
    

}