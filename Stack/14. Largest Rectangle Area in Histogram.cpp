#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

// Size: 6
// 2 1 5 6 2 3
// 10

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

int main()
{
    int n, data;
    vector<int> heights;
    cout<<"Size: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        heights.push_back(data);
    }

    int answer = largestRect_in_Histogram(heights);
    cout<<answer<<endl;

    return 0;
}