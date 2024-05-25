#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Size n: 5
// 8 9 7 8 6 
// -------
// 6 -> 5
// 7 -> 3
// 9 -> 2
// 8 -> 1
// Maximmum distance b/w same element: 2

int maxDistance(vector<int>&arr, int n){
    unordered_map <int, int> mpp;
    int dist = 0;

    for(int i=0;i<n;i++){
        if(mpp.find(arr[i]) != mpp.end()){       // if same element found before map end.
            dist = i - mpp[arr[i]];             // current index - first occured index(from hashmap).
        }
        else {
            mpp[arr[i]] = i+1;                  // Put the index number to the mapped value for the arr data (as key)
        }
    }
    cout<<"-------"<<endl;
    for(auto iter = mpp.begin(); iter != mpp.end(); iter++){
        cout<<iter->first<<" -> "<<iter->second<<endl;
    }

    return dist;
}

int main()
{
    vector<int> arr;
    int n, data;
    cout<<"Size n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>> data;
        arr.emplace_back(data);
    }
    
    int ans = maxDistance(arr, n);
    cout<<"Maximmum distance b/w same element: "<<ans <<endl;

    return 0;
}