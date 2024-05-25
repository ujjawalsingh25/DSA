#include<iostream>
#include<stack>
using namespace std;

// Size: 3
// Element to insert: 4
// 1 2 3
// Before Insert Peek: 3
// After Insert Peek: 4

void display(stack<int> &stk){
    stack<int> temp = stk;      // Since stk will pe poped so need to store.
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void insertBottom(stack<int> &stk, int element){
    // int n = stk.size();
    if(stk.empty()) {
        stk.push(element);
        return;
    }

    int storeData = stk.top();
    stk.pop();
    insertBottom(stk, element);
    stk.push(storeData);
}

int main()
{
    stack<int> stk;
    int n, element, data;
    cout<<"Size: ";
    cin>>n;
    cout<<"Element to insert: ";
    cin>>element;
    for(int i=0;i<n;i++){
        cin>>data;
        stk.push(data);
    }

    display(stk);

    insertBottom(stk, element);

    cout<<"------"<<endl;
    display(stk);

    // cout<<"Before Insert Peek: "<<stk.top()<<endl;
    // stk.pop();
    // stk.pop();
    // stk.pop();
    // cout<<"After Insert Peek: "<<stk.top()<<endl;

    return 0;
}