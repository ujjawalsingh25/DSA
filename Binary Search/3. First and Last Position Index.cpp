// First and Last Position index

/*

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int lb_index, ub_index;
    vector<int> v;
    int n,data, target , result;
    cin>>n>>target;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }
    auto lb = lower_bound(v.begin(), v.end(), target);
    lb_index = (lb - v.begin())+1;
    // cout<<lb_index;

    auto ub = upper_bound(v.begin(), v.end(), target);
    ub_index = (ub - v.begin());
    if(v[lb - v.begin()] != target){
        lb_index = -1;
        ub_index = -1;
    }
    // cout<<ub_index;

    cout<<"First and Last occurance index : "<<lb_index<<" "<<ub_index;

    return 0;
}

// --------------------------------------------------------------------------------------------------------------------------

****** To get the Number of occurance of data we use in the upper code *********
*************************************************
cout<<"Number of occurance of data " <<target<< ": "<< (ub_index - lb_index) + 1;
**************************************************

*/

// --------------------------------------------------------------------------------------------------------------------------


/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int lower_index_pos(vector<int> &arr, int target){
    int n=arr.size(), mid;
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high){
        mid = low + (high-low)/2;       // Should be updated inside loop always.
        if(arr[mid] == target){
            first =mid;
            high = mid-1;
        }
        else if(target > arr[mid])
            low = mid + 1;
        else if(target < arr[mid])
            high = mid - 1;
    }
    return first;
}

int upper_index_pos(vector<int> &arr, int target){
    int n=arr.size(), mid;
    int low = 0, high = n-1;
    int last = -1;
    while(low <= high){
        mid = low + (high-low)/2;       // Should be updated inside loop always.
        if(arr[mid] == target){
            last =mid;
            low = mid + 1;             // 'high value' change to 'high value' from lower bound to upper bound.
        }
        else if(target > arr[mid])
            low = mid + 1;     
        else if(target < arr[mid])
            high = mid - 1;
    }
    return last;
}

int main()
{
    vector<int> v;
    int n,data, target , result;
    cin>>n>>target;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }
    auto lb = lower_index_pos(v, target);
    // cout<<lb+1;
    auto ub = upper_index_pos(v, target);
    // cout<<ub+1;

    cout<<"First and Last occurance index : "<<lb + 1<<" "<<ub + 1;


return 0;
}

*/