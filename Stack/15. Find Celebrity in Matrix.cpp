#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Everyone knows celebrity
// Celebrity knows Nobody./
//    a b c 
// d  0 1 0             // Let 'a,b,c,d,e,f' are person and (1 means d knows b) for (0 means d don't know a or c).
// e  0 0 0
// f  0 1 0

// Size: 3
// 0 1 0
// 0 0 0
// 0 1 0
// Celebrity found at: 1

bool knows(vector<vector<int>> &arr, int a, int b){
    if(arr[a][b] == 1)  return true;
    else    return false;
}

int find_Celebrity(vector<vector<int>> &arr, int n){

// Step 1: Push all element in the stack.
    stack<int> stk;
    for(int i=0;i<n;i++){
        stk.push(i);
    }

// Step 2: Get two elements from stack and compare them if they knows.
    while(stk.size() > 1){
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();

        if(knows(arr, a, b))    stk.push(b);        // -->>> Since if 'a' knows 'b' so 'a' must not be celebrity whilw 'b' can.
        else    stk.push(a);
    }
    int ans = stk.top();        // -->>> The single element that left in the stack have potential to be celebrity.

// Step 3: The single element that left in the stack have potential to be celebrity so check all eligibility
    // Row Check if it knows everyone
    bool checkRow = false;
    int zeroCount = 0;
    for(int i=0;i<n;i++){
        if(arr[ans][i] == 0)  zeroCount++;          // -->>> The element knows Nobody.
    }
    if(zeroCount == n)   checkRow = true;

    // Col Check if it knows everyone
    bool checkCol = false;
    int onesCount = 0;
    for(int i=0;i<n;i++){
        if(arr[i][ans] == 1)  onesCount++;          // -->>> The element knows Nobody.
    }
    if(onesCount == n-1)    checkCol = true;

// Step 4: If all satisfy return ans.
    if(checkRow == true && checkCol == true)    return ans;
    else    return -1;
}

int main(){
    vector<vector<int>> v;
    int n, col;
    cout<<"Size: ";
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            cin>>col;
            row.emplace_back(col);
        }
        v.emplace_back(row);
    }

    int answer = find_Celebrity(v, n);
    if (answer != -1) {
        cout << "Celebrity found at: " << answer << endl;
    } else {
        cout << "No celebrity found." << endl;
    }

    return 0;
}