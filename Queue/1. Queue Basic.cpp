#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> quu;

    quu.push(1);

    if(quu.empty())  cout<<"Queue is empty"<<endl;
    else    cout<<"Queue is not empty"<<endl;
    cout<<quu.front()<<endl;
    quu.pop();

    cout<<"Size: "<<quu.size()<<endl;

    quu.push(2);
    quu.push(3);
    quu.push(4);
    quu.push(5);

    cout<<"Size: "<<quu.size()<<endl;

    if(quu.empty())  cout<<"Queue is empty"<<endl;
    else    cout<<"Queue is not empty"<<endl;

    cout<<"Front Element: "<<quu.front()<<endl;
    quu.pop();
    cout<<"Front Element: "<<quu.front()<<endl;
    quu.pop();
    cout<<"Front Element: "<<quu.front()<<endl;
    quu.pop();
    cout<<"Front Element: "<<quu.front()<<endl;
    quu.pop();
    cout<<"Front Element: "<<quu.front()<<endl;

    return 0;
}