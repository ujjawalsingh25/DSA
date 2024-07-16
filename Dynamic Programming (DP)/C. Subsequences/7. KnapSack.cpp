#include<iostream>
#include<vector>
using namespace std;

// Size : 3
// Weight : 3 2 5
// Value : 30 40 60
// Bag Max Capacity : 6
// 70
// ----------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(2^n)
// Space Complexity : O(n) 
// -----------------------------------------------------
int maxValueWeightCapacity_Recursion(int index, int bagWeight, vector<int> &weight, vector<int> &value){
    if(index == 0){
        if(weight[0] <= bagWeight)   return value[0];
        else return 0;
    }

    int notTake = 0 + maxValueWeightCapacity_Recursion(index-1, bagWeight, weight, value);
    int take = INT_MIN;
    if(weight[index] <= bagWeight){
        take = value[index] + maxValueWeightCapacity_Recursion(index - 1, bagWeight - weight[index], weight, value);
    }
    return max(take, notTake);
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*bagWeight)
// Space Complexity : O(n*bagWeight) + O(n)   -->> O(n) is the auxiliary stack space   
// ------------------------------------
int maxValueWeightCapacity_Mamoization(int index, int bagWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dpArr){
    if(index == 0){
        if(weight[0] <= bagWeight)   return value[0];
        else return 0;
    }

    if(dpArr[index][bagWeight] != -1)    return dpArr[index][bagWeight];
    int notTake = 0 + maxValueWeightCapacity_Mamoization(index-1, bagWeight, weight, value, dpArr);
    int take = INT_MIN;
    if(weight[index] <= bagWeight){
        take = value[index] + maxValueWeightCapacity_Mamoization(index - 1, bagWeight - weight[index], weight, value, dpArr);
    }
    return dpArr[index][bagWeight] = max(take, notTake);
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*bagWeight)
// Space Complexity : O(n*bagWeight)
// ------------------------------------
int maxValueWeightCapacity_Tabulation(vector<int> &weight, vector<int> &value, int maxCapacity, int n){
    vector<vector<int>> dpArr(n, vector<int> (maxCapacity + 1, 0));
    for(int bagWeight = weight[0]; bagWeight <= maxCapacity; bagWeight++)     dpArr[0][bagWeight] = value[0];

    for(int index=1; index<n; index++){
        for(int bagWeight=0; bagWeight <= maxCapacity; bagWeight++){
            int notTake = 0 + dpArr[index-1][bagWeight];
            int take = INT_MIN;
            if(weight[index] <= bagWeight){
                take = value[index] + dpArr[index - 1][bagWeight - weight[index] ];
            }
            dpArr[index][bagWeight] = max(take, notTake);
        }
    }
    return dpArr[n-1][maxCapacity];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*bagWeight)
// Space Complexity : O(bagWeight)
// ------------------------------------
int maxValueWeightCapacity_TabulationOPTM(vector<int> &weight, vector<int> &value, int maxCapacity, int n){
    vector<int> prev(maxCapacity+1, 0), current(maxCapacity+1, 0);
    for(int bagWeight = weight[0]; bagWeight <= maxCapacity; bagWeight++)     prev[bagWeight] = value[0];

    for(int index=1; index<n; index++){
        for(int bagWeight=0; bagWeight <= maxCapacity; bagWeight++){
            int notTake = 0 + prev[bagWeight];
            int take = INT_MIN;
            if(weight[index] <= bagWeight){
                take = value[index] + prev[bagWeight - weight[index] ];
            }
            current[bagWeight] = max(take, notTake);
        }
        prev = current;
    }
    return prev[maxCapacity];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*bagWeight)
// Space Complexity : O(bagWeight)
// ------------------------------------
int maxValueWeightCapacity_TabulationOPTM2(vector<int> &weight, vector<int> &value, int maxCapacity, int n){
    vector<int> prev(maxCapacity+1, 0);
    for(int bagWeight = weight[0]; bagWeight <= maxCapacity; bagWeight++)     prev[bagWeight] = value[0];

    for(int index=1; index<n; index++){
        for(int bagWeight=maxCapacity; bagWeight >= 0; bagWeight--){
            int notTake = 0 + prev[bagWeight];
            int take = INT_MIN;
            if(weight[index] <= bagWeight){
                take = value[index] + prev[bagWeight - weight[index] ];
            }
            prev[bagWeight] = max(take, notTake);
        }
    }
    return prev[maxCapacity];
}
// __________________________________________________________________________________


int main()
{
    int n, data, bagMaxWeight;
    cout<<"Size : ";
    cin>>n;
    vector<int> value, weight;
    cout<<"Weight : ";
    for(int i=0;i<n;i++){
        cin>>data;
        weight.push_back(data);
    }
    cout<<"Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        value.push_back(data);
    }
    cout<<"Bag Max Capacity : ";
    cin>>bagMaxWeight;

    vector<vector<int>> dpArr(n, vector<int> (bagMaxWeight+1, -1));

    int knapsack_Recursion = maxValueWeightCapacity_Recursion(n-1, bagMaxWeight, weight, value);
    cout<<knapsack_Recursion<<endl;

    int knapsack_Mamoization = maxValueWeightCapacity_Mamoization(n-1, bagMaxWeight, weight, value, dpArr);
    cout<<knapsack_Mamoization<<endl;

    int knapsack_Tabulation = maxValueWeightCapacity_Tabulation(weight, value, bagMaxWeight, n-1);
    cout<<knapsack_Tabulation<<endl;

    int knapsack_TabulationOPTM = maxValueWeightCapacity_TabulationOPTM(weight, value, bagMaxWeight, n-1);
    cout<<knapsack_TabulationOPTM<<endl;

    int knapsack_TabulationOPTM2 = maxValueWeightCapacity_TabulationOPTM2(weight, value, bagMaxWeight, n-1);
    cout<<knapsack_TabulationOPTM2<<endl;

    return 0;
}