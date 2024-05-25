// Binary Search

// Iterative Binary Search

#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> &arr, int target){
    int n=arr.size(), mid;
    int low = 0, high = n-1;
    while(low <= high){
        mid = low + (high-low)/2;       // Should be updated inside loop always.
        if(arr[mid] == target)
            return mid;
        else if(target > arr[mid])
            low = mid + 1;
        else if(target < arr[mid])
            high = mid - 1;
    }
    return -1;
}

int main()
{   
    vector<int> v;
    int n = v.size();
    int data, target , result;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }
    cin>>target;
    result = binary_search(v,target);
    cout<<result;

    return 0;
}

/*

// Recursive Binary Search
#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> &arr, int low, int high, int target){
    int mid = low + (high-low)/2;       // Should be updated inside loop always.

    if(low > high)
        return -1;
    else if(arr[mid] == target)
            return mid;
    else if(target > arr[mid])
        return binary_search(arr, mid + 1, high, target);
    else if(target < arr[mid])
       return binary_search(arr, low, mid-1, target);
    return -1;
}

int main()
{   
    vector<int> v;
    int n = v.size();
    int data, target , result;
    cin>>n;
    cin>>target;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }
    result = binary_search(v, 0, v.size(), target);
    cout<<result+1;

    return 0;
}

*/