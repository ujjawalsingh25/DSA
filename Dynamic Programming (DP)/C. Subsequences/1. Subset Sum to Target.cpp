#include<iostream>
#include<vector>
using namespace std;

// Size : 4
// Array : 1 2 3 4
// ----------------------
// Target : 4   -->>  True
// {1,3} , {4}  -->> TRUE
// Target : 12   -->> False
// ----------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(2^n)
// Space Complexity : O(n) 
// -----------------------------------------------------
bool subset_SumTo_TARGET_Recursion(vector<int> &arr, int target, int index){
    if(target == 0)   return true;
    if(index == 0)  return (arr[0] == target);   // recursively reach to first index, if sum equals to target then true else false

    bool notTake = subset_SumTo_TARGET_Recursion(arr, target, index-1);
    bool take = false;
    if(arr[index] <= target)    take = subset_SumTo_TARGET_Recursion(arr, target - arr[index], index-1);

    return take | notTake;          // OR(take, notTake) anyone with true return true else false.
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*target)
// Space Complexity : O(n*target) + O(n)   -->> O(n) is the auxiliary space   
// ------------------------------------
bool subset_SumTo_TARGET_Mamoization(vector<int> &arr, int target, int index, vector<vector<int>> &dpArr){
    if(target == 0)   return true;
    if(index == 0)  return (arr[0] == target);   
    if(dpArr[index][target] != -1)  return dpArr[index][target]; 

    bool notTake = subset_SumTo_TARGET_Mamoization(arr, target, index-1, dpArr);
    bool take = false;
    if(arr[index] <= target)    take = subset_SumTo_TARGET_Mamoization(arr, target - arr[index], index-1, dpArr);

    return dpArr[index][target] = take | notTake;          // OR(take, notTake) anyone with true return true else false.
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*target)
// Space Complexity : O(n*target)
// ------------------------------------
bool subset_SumTo_TARGET_Tabulation(vector<int> &arr, int k, int n){
    vector<vector<bool>> dpArr(n, vector<bool>(k+1, 0));
    for(int i=0;i<n;i++)  dpArr[i][0] = true;
    dpArr[0][arr[0]] = true;  

    for(int index = 1; index < n; index++){
        for(int target = 1; target <= k; target++){
            bool notTake = dpArr[index-1][target];
            bool take = false;
            if(arr[index] <= target)    take = dpArr[index-1][target - arr[index]];
            dpArr[index][target] = take | notTake; 
        }
    }
    return dpArr[n-1][k];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*target)
// Space Complexity : O(target)
// ------------------------------------
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

    bool isPossibleSum_Recursion = subset_SumTo_TARGET_Recursion(arr, target, n);
    if(isPossibleSum_Recursion) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    bool isPossibleSum_Mamo = subset_SumTo_TARGET_Mamoization(arr, target, n-1, dpArr);     // **** should be from n-1
    if(isPossibleSum_Mamo) cout<<"True"<<endl;                                      // n-1 because indexing is taken as (0 -> n-1)
    else cout<<"False"<<endl;
    
    bool isPossibleSum_Tabulation = subset_SumTo_TARGET_Tabulation(arr, target, n);
    if(isPossibleSum_Tabulation) cout<<"True"<<endl;
    // else cout<<"False"<<endl;

    bool isPossibleSum_TabulationOPTM = subset_SumTo_TARGET_TabulationOPTM(arr, target, n);
    if(isPossibleSum_TabulationOPTM) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}