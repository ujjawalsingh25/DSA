#include<iostream>
#include<vector>
using namespace std;

// Size : 3
// Array : 1 2 3
// Target : 4
// -------------------------------------
// {1, 1, 1, 1} , {2, 1, 1} , {2, 2} , {3, 1} = 4
// Possible ways to get Target Value (Coin Exchange) : 4
// -------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : >> O(2^n) [Exponential]  (For some index possibilities are more than 2)
// Space Complexity : >> O(n) 
// -----------------------------------------------------
int PossibleWays_toGetTarget_Recursion(vector<int> &arr, int index, int target){
    if(index == 0){
        return  (target % arr[0] == 0);     // to get total coin possible for that target at that index
    }

    int notTake = PossibleWays_toGetTarget_Recursion(arr, index -1, target);
    int take = 0;
    if(arr[index] <= target){
        take = PossibleWays_toGetTarget_Recursion(arr, index, target - arr[index]);
    }  
    return take + notTake;
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*target)
// Space Complexity : O(n*target) + O(n)   -->> O(n) is the auxiliary stack space   
// ------------------------------------
int PossibleWays_toGetTarget_Mamoization(vector<int> &arr, int index, int target, vector<vector<int>> &dpArr){
    if(index == 0)    return (target % arr[0] == 0);

    if(dpArr[index][target] != -1)     return dpArr[index][target];
    int notTake = PossibleWays_toGetTarget_Mamoization(arr, index -1, target, dpArr);
    int take = 0;
    if(arr[index] <= target){
        take = PossibleWays_toGetTarget_Mamoization(arr, index, target - arr[index], dpArr);
    }  
    return dpArr[index][target] =  take + notTake;
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*target)
// Space Complexity : O(n*target)
// ------------------------------------
int PossibleWays_toGetTarget_Tabulation(vector<int> &arr, int n, int target){
    vector<vector<int>> dpArr(n, vector<int> (target+1, 0));

    for(int tar=0; tar<=target; tar++){
        dpArr[0][tar] = (target % arr[0] == 0);
    }

    for(int index=1;index<n;index++){
        for(int tar=0;tar<=target;tar++){
            int notTake = dpArr[index -1][tar];
            int take = 0;
            if(arr[index] <= tar){
                take = dpArr[index][tar - arr[index]];
            }  
            dpArr[index][tar] =  take + notTake;
        }
    }
    return dpArr[n-1][target];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*target)
// Space Complexity : O(target)
// ------------------------------------
int PossibleWays_toGetTarget_TabulationOPTM(vector<int> &arr, int n, int target){
    vector<int> prev(target+1, 0), current(target+1, 0);
    for(int tar=0; tar<=target; tar++){
        prev[tar] = (target % arr[0] == 0);
    }

    for(int index=1;index<n;index++){
        for(int tar=0;tar<=target;tar++){
            int notTake = prev[tar];
            int take = 0;
            if(arr[index] <= tar){
                take = current[tar - arr[index]];
            }  
            current[tar] =  take + notTake;
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

    int WaysToChangeCoin_Recursion = PossibleWays_toGetTarget_Recursion(arr, n-1, target);
    cout<<"Possible ways to get Target Value (Coin Exchange): "<<WaysToChangeCoin_Recursion<<endl;

    int WaysToChangeCoin_Mamoization = PossibleWays_toGetTarget_Mamoization(arr, n-1, target, dpArr);
    cout<<"Possible ways to get Target Value (Coin Exchange): "<<WaysToChangeCoin_Mamoization<<endl;

    int WaysToChangeCoin_Tabulation = PossibleWays_toGetTarget_Tabulation(arr, n, target);
    cout<<"Possible ways to get Target Value (Coin Exchange): "<<WaysToChangeCoin_Tabulation<<endl;

    int WaysToChangeCoin_TabulationOPTM = PossibleWays_toGetTarget_TabulationOPTM(arr, n, target);
    cout<<"Possible ways to get Target Value (Coin Exchange): "<<WaysToChangeCoin_TabulationOPTM<<endl;


    return 0;
}