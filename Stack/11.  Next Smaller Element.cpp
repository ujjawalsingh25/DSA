#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

//  ***************************
// -->>> Since 0 based indexing so whenever need to iterate reverse always from n-1  to 0
// ************************

// Size: 4
// 2 1 4 3
// Next Smaller Elements:
// 1 -1 3 -1

vector<int> nextSmaller_Element(vector<int> &arr, int n){
    vector<int> ans;
    stack<int> stk;
    stk.push(-1);
                                             
    for(int i=n-1; i>=0; i--){                  // -->>> Since 0 based inddexing so whenever need to iterate reverse always from n-1  to 0
       int currentElement = arr[i];             
       while(stk.top() >= currentElement){
            stk.pop();
       }
       // Now stack top will be the next smallest of current data
        ans.push_back(stk.top());
       stk.push(currentElement);
    }
    reverse(ans.begin(), ans.end());
   return ans;
}

int main()
{
    int n, data;
    vector<int> v;
    cout<<"Size: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        v.push_back(data);
    }

    vector<int> ans = nextSmaller_Element(v, n);

    cout << "Next Smaller Elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}