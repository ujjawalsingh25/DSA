#include<iostream>
#include<stack>
using namespace std;

// Size: 3
// 1 2 3
// Before rev Peek: 3
// After rev Peek: 1

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

void display(stack<int> &stk){
    stack<int> temp = stk;      // Since stk will pe poped so need to store.
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void revStack(stack<int> &stk){
    if(stk.empty()){
        return;
    }
    int storeData = stk.top();
    stk.pop();
    revStack(stk);
    insertBottom(stk, storeData);
    
}

int main()
{
    stack<int> stk;
    int n, element, data;
    cout<<"Size: ";
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>data;
        stk.push(data);
    }

    display(stk);
    revStack(stk);
    cout<<"After rev Peek "<<endl;
    display(stk);

    return 0;
}