#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int> & quu){
    int n = quu.size();
    for(int i=0;i<n;i++){
        cout<<quu.front()<<" ";
        quu.pop();
    }
}

queue<int> reverseQueue(queue<int> &quu){
    stack<int> stk;
    while(!quu.empty()){
        int data = quu.front();
        stk.push(data);
        quu.pop();
    }
    while(!stk.empty()){
        int revData = stk.top();
        stk.pop();
        quu.push(revData);
    }
   return quu;
}


int main()
{
    int n, data;
    queue<int> quu, ans;
    cout<<"Size: ";
    cin>>n;
    cout<<"Data: ";
    for(int i=0;i<n;i++){
        cin>>data;
        quu.push(data);
    }

    ans = reverseQueue(quu);
    display(ans);

  return 0;
}
