#include<iostream>
#include<stack>
using namespace std;

// Size: 5
// Data: 5 3 8 2 4
// 2 2 3 3 5 -1

class min_optimisedStack{
    protected:
    stack<int> stk;
    int minVal = INT_MAX;

    public:
    void push(int data){
        if(stk.empty()){
            stk.push(data);
            minVal = data;
        }
        else{
            if(data < minVal){
                stk.push(2*data - minVal);
                minVal = data;
            }
            else    stk.push(data);
        }
    }
        
    int pop(){
        if(stk.empty())  return -1;
        int currentData = stk.top();
        stk.pop();
        if(currentData > minVal)    return currentData;     // -->>> If mini is still the minimum just pop the data.

        else {                              // -->>> After prev data poped the new top data is less than mini.
            int prevMin_Val = minVal;
            int currentMin_Val = 2*minVal - currentData;
            minVal = currentMin_Val;
            return prevMin_Val;

        }
    }

    int peek(){
       if(stk.empty())    return -1;
       int currentMin_Val = stk.top();
       if(currentMin_Val > minVal)  return currentMin_Val;
       else return minVal;
    }

    bool isEmpty() {
        return stk.empty();
    }

    int get_min(){
        if(stk.empty())  return -1;
        return minVal;
    }
};

int main()
{
    int n, data;
    min_optimisedStack stk;
    cout<<"Size: ";
    cin>>n;
    cout<<"Data: ";
    for(int i=0;i<n;i++){
        cin>>data;
        stk.push(data);
    }  cout<<"--------"<<endl;
    // stk.push(5);
    // stk.push(3);
    // stk.push(8);
    // stk.push(2);
    // stk.push(4);

    // cout<<"Data in Stack: ";
    // for(int i=0;i<n;i++){
    //     cout<<stk.peek()<<" ";
    //     stk.pop();
    // }cout<<endl;

    for(int i=0;i<n+1;i++){
        cout<<stk.get_min()<<" ";
        stk.pop();
    }
    // cout<<stk.get_min()<<" ";
    // stk.pop();
    // cout<<stk.get_min()<<endl;
    // stk.pop();
    // cout<<stk.get_min()<<endl;
    // stk.pop();
    // cout<<stk.get_min()<<endl;
    // stk.pop();
    // cout<<stk.get_min()<<endl;
    // stk.pop();
    // cout<<stk.get_min()<<endl;
  
    return 0;    
}