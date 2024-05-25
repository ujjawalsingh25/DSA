#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

// Size: 4
// 0 1 1 0
// 1 1 1 1 
// 1 1 1 1
// 1 1 0 0 
// --------
// Maximum area: 8

// Time Complexity : O(n*m) or O(row * col)
// Space Complexity: O(n) -->>> for sum i.e storing all value of current & upper coloumns in each row.

vector<int> nextSmaller_ElementPOS(vector<int> &arr, int n){
    vector<int> ans;
    stack<int> stk;
    stk.push(-1);
                                             
    for(int i=n-1; i>=0; i--){                  // -->>> Since 0 based inddexing so whenever need to iterate reverse always from n-1  to 0
       int currentElement = arr[i];             
       while(stk.top() != -1 && arr[stk.top()] >= currentElement){
            stk.pop();
       }
       // Now stack top will be the next smallest of current data
        ans.push_back(stk.top());
       stk.push(i);
    }
    reverse(ans.begin(), ans.end());
   return ans;
}

vector<int> prevSmaller_ElementPOS(vector<int> &arr, int n){
    vector<int> ans;
    stack<int> stk;
    stk.push(-1);
                                             
    for(int i=0; i<n; i++){                  // -->>> Just need to iterate of loop from 0 to n.
       int currentElement = arr[i];             
       while(stk.top() != -1 && arr[stk.top()] >= currentElement){
            stk.pop();
       }
       // Now stack top will be the prev smallest of current data
        ans.push_back(stk.top());
       stk.push(i);
    }
    // reverse(ans.begin(), ans.end());
   return ans;
}

int largestRect_in_Histogram(vector<int> &arr){
    int n = arr.size();
    vector<int> nextPOS;
    vector<int> prevPOS;
    int answer = INT_MIN;

    nextPOS = nextSmaller_ElementPOS(arr, n);
    prevPOS = prevSmaller_ElementPOS(arr, n);
    
    for(int i=0;i<n;i++){
        int length = arr[i];
        int width = nextPOS[i] - prevPOS[i] - 1;
        if(nextPOS[i] == -1)   nextPOS[i] = n;

        int area = length * width;
        answer = max(answer, area);
    }
   return answer;    
}

int maxRectangle_inBinary(vector<vector<int>> &arr, int n){

// Step 1: Initialize a vector 'sum' with all zero to store sum of current & upper coloumns in each row.
    vector<int> sum(n,0);
    int area = INT_MIN;

// Step 2: Update the area with added rows & add current and upper columns.
    for(int row=0; row<n; row++){
        for(int col = 0; col<n; col++){
            if(arr[row][col] != 0)
                sum[row] += arr[row][col];   
            else 
                sum[row] = 0;       
        }
      area = max(area, largestRect_in_Histogram(sum));  // -->>> Max of (area because of current sum & prev area).
    }
  
  return area;
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
    }cout<<"--------"<<endl;

    int answer = maxRectangle_inBinary(v, n);
    cout<<"Maximum area: "<<answer<<endl;

    return 0;
}