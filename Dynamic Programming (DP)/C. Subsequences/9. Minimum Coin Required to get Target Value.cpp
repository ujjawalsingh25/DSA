#include<iostream>
#include<vector>
using namespace std;

// Size : 3
// Array : 1 2 3
// Target : 8
// -------------------------------------
// {2, 3, 3} = 8
// Minimum Coin Required to get Target Value : 3
// -------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : >> O(2^n) [Exponential]  (For some index possibilities are more than 2)
// Space Complexity : >> O(n) 
// -----------------------------------------------------
int minCoinReq_ToTarget_Recursion(vector<int> &arr, int index, int target){
    if(index == 0){
        if(target % arr[0] == 0)    return target / arr[0];     // to get total coin possible for that target
        else return INT_MAX;
    }

    int notTake = 0 + minCoinReq_ToTarget_Recursion(arr, index -1, target);
    int take = INT_MAX;
    if(arr[index] <= target){
        take = 1 + minCoinReq_ToTarget_Recursion(arr, index, target - arr[index]);
    }  
    return min(take, notTake);
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*target)
// Space Complexity : O(n*target) + O(n)   -->> O(n) is the auxiliary stack space   
// ------------------------------------
int minCoinReq_ToTarget_Mamoization(vector<int> &arr, int index, int target, vector<vector<int>> &dpArr){
    if(index == 0){
        if(target % arr[0] == 0)    return target / arr[0];     // to get total coin possible for that target
        else return INT_MAX;
    }

    if(dpArr[index][target] != -1)     return dpArr[index][target];
    int notTake = 0 + minCoinReq_ToTarget_Mamoization(arr, index -1, target, dpArr);
    int take = INT_MAX;
    if(arr[index] <= target){
        take = 1 + minCoinReq_ToTarget_Mamoization(arr, index, target - arr[index], dpArr);
    }  
    return dpArr[index][target] =  min(take, notTake);
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*target)
// Space Complexity : O(n*target)
// ------------------------------------
int minCoinReq_ToTarget_Tabulation(vector<int> &arr, int n, int target){
    vector<vector<int>> dpArr(n, vector<int> (target+1, 0));
    for(int tar=0; tar<=target; tar++){
        if(tar % arr[0] == 0)   dpArr[0][tar] = tar/arr[0];
        else    dpArr[0][tar] = INT_MAX;
    }

    for(int index=1;index<n;index++){
        for(int tar=0;tar<=target;tar++){
            int notTake = 0 + dpArr[index -1][tar];
            int take = INT_MAX;
            if(arr[index] <= tar){
                take = 1 + dpArr[index][tar - arr[index]];
            }  
            dpArr[index][tar] =  min(take, notTake);
        }
    }
    return dpArr[n-1][target];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*target)
// Space Complexity : O(target)
// ------------------------------------
int minCoinReq_ToTarget_TabulationOPTM(vector<int> &arr, int n, int target){
    vector<int> prev(target+1, 0), current(target+1, 0);
    for(int tar=0; tar<=target; tar++){
        if(tar % arr[0] == 0)   prev[tar] = tar/arr[0];
        else    prev[tar] = INT_MAX;
    }

    for(int index=1;index<n;index++){
        for(int tar=0;tar<=target;tar++){
            int notTake = 0 + prev[tar];
            int take = INT_MAX;
            if(arr[index] <= tar){
                take = 1 + current[tar - arr[index]];
            }  
            current[tar] =  min(take, notTake);
        }
        prev = current;
    }
    return prev[target];    
}
// __________________________________________________________________________________


int main()
{
    int n, data, target;
    cout<<"Size : ";
    cin>>n;
    cout<<"Array : ";
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>data;
        arr.push_back(data);
    }

    cout<<"Target : ";
    cin>>target;
    vector<vector<int>> dpArr(n, vector<int> (target+1, -1));

    int minCoinReq_Recursion = minCoinReq_ToTarget_Recursion(arr, n-1, target);
    if(minCoinReq_Recursion >= INT_MAX)    cout<<"-1"<<endl;   
    else    cout<<"Minimum Coin Required to get Target Value : "<<minCoinReq_Recursion<<endl;

    int minCoinReq_Mamoization = minCoinReq_ToTarget_Mamoization(arr, n-1, target, dpArr);
    if(minCoinReq_Mamoization >= INT_MAX)    cout<<"-1"<<endl;   
    else    cout<<"Minimum Coin Required to get Target Value : "<<minCoinReq_Mamoization<<endl;

    int minCoinReq_Tabulation = minCoinReq_ToTarget_Tabulation(arr, n, target);
    if(minCoinReq_Tabulation >= INT_MAX)    cout<<"-1"<<endl;   
    else    cout<<"Minimum Coin Required to get Target Value : "<<minCoinReq_Tabulation<<endl;

    int minCoinReq_TabulationOPTM = minCoinReq_ToTarget_TabulationOPTM(arr, n, target);
    if(minCoinReq_TabulationOPTM >= INT_MAX)    cout<<"-1"<<endl;   
    else    cout<<"Minimum Coin Required to get Target Value : "<<minCoinReq_TabulationOPTM<<endl;


    return 0;
}