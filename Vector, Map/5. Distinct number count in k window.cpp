#include<bits/stdc++.h>
using namespace std;

// Size: 7  
// Window: 4
// 1 2 1 3 4 2 3
// 3 4 4 3

vector<int> countDistinct(vector<int>&arr, int n, int k){
    vector<int> ans;
    unordered_map <int, int> mpp;
    for(int i=0;i<k;i++){
        mpp[arr[i]] += 1;
    }
    ans.push_back(mpp.size());

    for(int i=k;i<n;i++){
        if(mpp[arr[i - k]] == 1){
            mpp.erase(arr[i-k]);
        }    
        else    mpp[arr[i-k]]--;

        mpp[arr[i]] ++;
        ans.push_back(mpp.size());
    }
    return ans;
}


int main()
{
    int n, window, data;
    vector<int> arr;
    cout<<"Size: ";
    cin>>n;
    cout<<"Window: ";
    cin>>window;
    for(int i=0;i<n;i++){
        cin>>data;
        arr.emplace_back(data);
    }

    vector<int> ans = countDistinct (arr, n, window);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
  
  return 0;
}