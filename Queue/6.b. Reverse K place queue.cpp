#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void display(queue<int> & quu){
    int n = quu.size();
    for(int i=0;i<n;i++){
        cout<<quu.front()<<" ";
        quu.pop();
    }
}

// Size: 5
// K Place to reverse: 3
// Data: 1 2 3 4 5
// 3 2 1 4 5

queue<int> reverseK_Queue(queue<int> quu, int k){
    stack<int> stk;
    queue<int> modifiedQuu;

    for(int i=0;i<k;i++){
        int data = quu.front();
        stk.push(data);
        quu.pop();
    }
    while(!stk.empty()){
        int revData = stk.top();
        stk.pop();
        modifiedQuu.push(revData);
    }

    while(!quu.empty()){
        int restData = quu.front();
        modifiedQuu.push(restData);
        quu.pop();
    }
  return modifiedQuu;
}

int main()
{
    int n, k, data;
    queue<int> quu, ans;
    cout<<"Size: ";
    cin>>n;
    cout<<"K Place to reverse: ";
    cin>>k;
    cout<<"Data: ";
    for(int i=0;i<n;i++){
        cin>>data;
        quu.push(data);
    }

    ans = reverseK_Queue(quu, k);
    display(ans);

  return 0;
}
