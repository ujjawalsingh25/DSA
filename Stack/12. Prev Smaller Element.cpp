#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

// Size: 4
// 1 2 3 4
// Prev Smaller Elements:
// -1 1 2 3

vector<int> prevSmaller_Element(vector<int> &arr, int n){
    vector<int> ans;
    stack<int> stk;
    stk.push(-1);
                                             
    for(int i=0; i<n; i++){                  // -->>> Just need to iterate of loop from 0 to n.
       int currentElement = arr[i];             
       while(stk.top() >= currentElement){
            stk.pop();
       }
       // Now stack top will be the prev smallest of current data
        ans.push_back(stk.top());
       stk.push(currentElement);
    }
    // reverse(ans.begin(), ans.end());
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

    vector<int> ans = prevSmaller_Element(v, n);

    cout << "Prev Smaller Elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}