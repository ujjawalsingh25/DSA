#include<iostream>
#include<queue>
using namespace std;

int main()
{
    deque<int> quu;         // -->> Double ended queue

    quu.push_front(3);
    quu.push_front(5);
    quu.push_back(34);
    quu.push_back(25);

    cout<<quu.front()<<endl;
    cout<<quu.back()<<endl;

    quu.pop_front();
    quu.pop_back();

    if(quu.empty()) cout<<"Queue is empty"<<endl;
    else    cout<<"Queue is not empty."<<endl;

    cout<<quu.front()<<endl;
    cout<<quu.back()<<endl;
    
    quu.pop_front();
    quu.pop_back();

    if(quu.empty()) cout<<"Queue is empty"<<endl;
    else    cout<<"Queue is not empty."<<endl;

}