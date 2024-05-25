#include<iostream>
#include<stack>
using namespace std;

// Size: 5
// 4 2 6 1 3
// Before Sort Peek: 3
// After Sort Peek: 6
// Peek: 4
// Peek: 3
// Peek: 2
// Peek: 1

void insertSorted(stack<int> &stk, int prevStore){
    if(stk.empty() || (!stk.empty() && stk.top() < prevStore) ) {
        stk.push(prevStore);
        return;
    }

    int newData = stk.top();
    stk.pop();
    insertSorted(stk, prevStore);
    stk.push(newData);
}

void sortStack(stack<int> &stk){
    if(stk.empty()) return;

    int storeData = stk.top();
    stk.pop();
    sortStack(stk);
    insertSorted(stk, storeData);
    
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

    cout<<"Before Sort Peek: "<<stk.top()<<endl;
    sortStack(stk);
    cout<<"After Sort Peek: "<<stk.top()<<endl;
    stk.pop();
    cout<<"Peek: "<<stk.top()<<endl;
    stk.pop();
    cout<<"Peek: "<<stk.top()<<endl;
    stk.pop();
    cout<<"Peek: "<<stk.top()<<endl;
    stk.pop();
    cout<<"Peek: "<<stk.top()<<endl;

    return 0;
}