#include<iostream>
#include<vector>
using namespace std;

// Size : 6
// Array : 2 3 3 3 4 5
// ----------------------
// {2, 3, 5} , {3, 3, 4}   both Subset sum equals 10 so true
// True
// ----------------------

bool subset_SumTo_TARGET_TabulationOPTM(vector<int> &arr, int k, int n){
    vector<bool>prev(k+1, 0), current(k+1, 0);
    prev[0] = current[0] = true;
    prev[arr[0]] = true;  

    for(int index = 1; index < n; index++){
        for(int target = 1; target <= k; target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[index] <= target)    take = prev[target - arr[index]];
            current[target] = take | notTake; 
        }
        prev = current;
    }
    return prev[k];
}

bool partitionSubsetSUM(vector<int> &arr, int n){
    int totalSum = 0;
    for(int i=0;i<n;i++)    totalSum += arr[i];
    if(totalSum % 2)    return false;
    int target = totalSum/2;

    return subset_SumTo_TARGET_TabulationOPTM(arr, target, n);
}

int main()
{
    int n, data, target;
    vector<int> arr;
    cout<<"Size : ";
    cin>>n;
    cout<<"Array : ";
    for(int i=0;i<n;i++){
        cin>>data;
        arr.emplace_back(data);
    }

    vector<vector<int>> dpArr(n, vector<int>(target+1, -1));

    bool isPartition = partitionSubsetSUM(arr, n);
    if(isPartition)    cout<<"True"<<endl;
    else    cout<<"False"<<endl; 
    return 0;
}