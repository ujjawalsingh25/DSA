#include<iostream>
#include<vector>
using namespace std;

// Size : 5
// Array : 1 2 3 4 5
// ----------------------------------
// Min Difference in Partition of two Subset SUM : 1
// {3, 5} - {1, 2, 4}  = 8 - 7 -->> 1
// ----------------------------------

// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*target) + O(totalSum/2) + O(n)
// Space Complexity : O(n*target)
// ------------------------------------
int minDiff_partitionSubsetSUM_Tabulation(vector<int> &arr, int n){
    int totalSum = 0;
    for(int i=0;i<n;i++)    totalSum += arr[i];

    vector<vector<bool>> dpArr(n, vector<bool>(totalSum+1, 0));
    for(int i=0;i<n;i++)    dpArr[i][0] = true;
    if(arr[0] <= totalSum)  dpArr[0][arr[0]] = true;

    for(int index = 1; index < n; index++){
        for(int target = 1; target <= totalSum; target++){
            bool notTake = dpArr[index-1][target];
            bool take = false;
            if(arr[index] <= target)    take = dpArr[index-1][target - arr[index]];
            dpArr[index][target] = take | notTake; 
        }
    }
    
    int mini = INT_MAX;
    for(int subsetSUM1=0; subsetSUM1<=totalSum/2; subsetSUM1++){  // from totalSum/2 to totalSum it repeats so iterate till half 
        if(dpArr[n-1][subsetSUM1] == true){
            mini = min(mini, abs((totalSum - subsetSUM1) - subsetSUM1));
        }
    }
    return mini;
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*target) + O(totalSum/2) + O(n)
// Space Complexity : O(target)
// ------------------------------------
int minDiff_partitionSubsetSUM_TabulationOPTM(vector<int> &arr, int n){
    int totalSum = 0;
    for(int i=0;i<n;i++)    totalSum += arr[i];

    vector<bool>prev(totalSum+1, 0), current(totalSum+1, 0);
    prev[0] = current[0] = true;
    prev[arr[0]] = true; 

    for(int index = 1; index < n; index++){
        for(int target = 1; target <= totalSum; target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[index] <= target)    take = prev[target - arr[index]];
            current[target] = take | notTake; 
        }
        prev = current;
    }
    
    int mini = INT_MAX;
    for(int subsetSUM1=0; subsetSUM1<=totalSum/2; subsetSUM1++){  // from totalSum/2 to totalSum it repeats so iterate till half 
        if(prev[subsetSUM1] == true){
            mini = min(mini, abs((totalSum - subsetSUM1) - subsetSUM1));
        }
    }
    return mini;
}
// __________________________________________________________________________________


int main()
{
    int n, data;
    vector<int> arr;
    cout<<"Size : ";
    cin>>n;
    cout<<"Array : ";
    for(int i=0;i<n;i++){
        cin>>data;
        arr.push_back(data);
    }

    int minDiff_ofSubsetSum = minDiff_partitionSubsetSUM_Tabulation(arr, n);
    cout<<"Min Difference in Partition of two Subset SUM : "<<minDiff_ofSubsetSum<<endl;

    int minDiff_ofSubsetSumOPTM = minDiff_partitionSubsetSUM_TabulationOPTM(arr, n);
    cout<<"Min Difference in Partition of two Subset SUM : "<<minDiff_ofSubsetSumOPTM<<endl;

    return 0;
}