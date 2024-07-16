#include<iostream>
#include<vector>
using namespace std;

// Size : 5
// Array : 1 2 3 4 5
// Target : 5
// ----------------------------------
// {2, 3} , {1, 4}, {5}
// Count Subsets having SUM K : 3  
// ----------------------------------
// Size : 4
// Array : 1 2 2 3
// Target : 3
// ----------------------------------
// {1, 2} , {1, 2}, {3}
// Count Subsets having SUM K : 3
// ----------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(2^n)
// Space Complexity : O(n) 
// -----------------------------------------------------
int countSubsetWith_Sum_K_Recursion(vector<int> &arr, int sum, int index){
    if(sum == 0)   return 1;
    if(index == 0)  return (arr[0] == sum);   // recursively reach to first index, if sum equals to sum then true else false

    int notTake = countSubsetWith_Sum_K_Recursion(arr, sum, index-1);
    int take = 0;
    if(arr[index] <= sum)    take = countSubsetWith_Sum_K_Recursion(arr, sum - arr[index], index-1);

    return take + notTake;          // any recursion (take, notTake) equal sum return 1 else 0.
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*sum)
// Space Complexity : O(n*sum) + O(n)   -->> O(n) is the auxiliary space   
// ------------------------------------
int countSubsetWith_Sum_K_Mamoization(vector<int> &arr, int sum, int index, vector<vector<int>> &dpArr){
    if(sum == 0)   return 1;
    if(index == 0)  return (arr[0] == sum);   
    if(dpArr[index][sum] != -1)  return dpArr[index][sum]; 

    int notTake = countSubsetWith_Sum_K_Mamoization(arr, sum, index-1, dpArr);
    int take = false;
    if(arr[index] <= sum)    take = countSubsetWith_Sum_K_Mamoization(arr, sum - arr[index], index-1, dpArr);

    return dpArr[index][sum] = take + notTake;           // any recursion (take, notTake) equal sum return 1 else 0.
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*sum)
// Space Complexity : O(n*sum)
// ------------------------------------
int countSubsetWith_Sum_K_Tabulation(vector<int> &arr, int target, int n){
    vector<vector<int>> dpArr(n, vector<int>(target+1, 0));
    for(int i=0;i<n;i++)  dpArr[i][0] = 1;
    if(arr[0] <= target)    dpArr[0][arr[0]] = 1;       

    for(int index = 1; index < n; index++){
        for(int sum = 1; sum <= target; sum++){
            int notTake = dpArr[index-1][sum];
            int take = 0;
            if(arr[index] <= sum)    take = dpArr[index-1][sum - arr[index]];
            dpArr[index][sum] = take + notTake; 
        }
    }
    return dpArr[n-1][target];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*sum)
// Space Complexity : O(sum)
// ------------------------------------
int countSubsetWith_Sum_K_TabulationOPTM(vector<int> &arr, int target, int n){
    vector<int>prev(target+1, 0), current(target+1, 0);
    prev[0] = current[0] = 1;
    prev[arr[0]] = 1;  

    for(int index = 1; index < n; index++){
        for(int sum = 1; sum <= target; sum++){
            int notTake = prev[sum];
            int take = 0;
            if(arr[index] <= sum)    take = prev[sum - arr[index]];
            current[sum] = take + notTake; 
        }
        prev = current;
    }
    return prev[target];
}
// __________________________________________________________________________________


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
    cout<<"Target : ";
    cin>>target;
    vector<vector<int>> dpArr(n, vector<int>(target+1, -1));

    int countSubset_Recursion = countSubsetWith_Sum_K_Recursion(arr, target, n-1);  // n-1 because indexing is taken as (0 -> n-1)
    cout<<"Count Subsets having SUM K : "<<countSubset_Recursion<<endl;

    int countSubset_Mamo = countSubsetWith_Sum_K_Mamoization(arr, target, n-1, dpArr);     // **** should be from n-1
    cout<<"Count Subsets having SUM K : "<<countSubset_Mamo<<endl;              // n-1 because indexing is taken as (0 -> n-1)
    
    int countSubset_Tabulation = countSubsetWith_Sum_K_Tabulation(arr, target, n);
    cout<<"Count Subsets having SUM K : "<<countSubset_Tabulation<<endl;

    int countSubset_TabulationOPTM = countSubsetWith_Sum_K_TabulationOPTM(arr, target, n);
   cout<<"Count Subsets having SUM K : "<<countSubset_TabulationOPTM<<endl;

    return 0;
}