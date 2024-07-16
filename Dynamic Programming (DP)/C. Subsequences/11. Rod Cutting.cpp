#include<iostream>
#include<vector>
using namespace std;

// Size : 5
// Price : 2 6 1 8 10
// 14
// ----------------------
// Size : 5
// Price : 2 5 7 8 10
// 12

// ___________________________  Using Recursion  ______________________________
// Time Complexity : >> O(2^n) [Exponential]  (For some index possibilities are more than 2)
// Space Complexity : O(bagWeight)          // The stack space decrease with the decrease in bagweight as it getting fill  
// -----------------------------------------------------
int maxValueWeightCapacity_Recursion(int index, vector<int> &price, int N){
    if(index == 0){
        return N * price[0];
    }

    int notTake = 0 + maxValueWeightCapacity_Recursion(index-1, price, N);
    int take = INT_MIN;
    int rodLength = index+1;
    if(rodLength <= N){
        take = price[index] + maxValueWeightCapacity_Recursion(index, price, N - rodLength);
    }
    return max(take, notTake);
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*bagWeight)
// Space Complexity : O(n*bagWeight) + O(n)   -->> O(n) is the auxiliary stack space   
// ------------------------------------
int maxValueWeightCapacity_Mamoization(int index, vector<int> &price, int N, vector<vector<int>> &dpArr){
    if(index == 0){
        return N * price[0];
    }

    if(dpArr[index][N] != -1)    return dpArr[index][N];
    int notTake = 0 + maxValueWeightCapacity_Mamoization(index-1, price, N, dpArr);
    int take = INT_MIN;
    int rodLength = index+1;
    if(rodLength <= N){
        take = price[index] + maxValueWeightCapacity_Mamoization(index, price, N - rodLength, dpArr);
    }
    return dpArr[index][N] = max(take, notTake);
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*bagWeight)
// Space Complexity : O(n*bagWeight)
// ------------------------------------
int maxValueWeightCapacity_Tabulation(vector<int> &price, int n){
    vector<vector<int>> dpArr(n, vector<int> (n+1, 0));
    for(int N = 0; N <= n; N++){
        dpArr[0][N] = N * price[0];
    }

    for(int index=1; index<n; index++){
        for(int N=0; N <= n; N++){
            int notTake = 0 + dpArr[index-1][N];
            int take = INT_MIN;
            int rodLength = index+1;
            if(rodLength <= N){
                take = price[index] + dpArr[index][N - rodLength];
            }
            dpArr[index][N] = max(take, notTake);
        }
    }
    return dpArr[n-1][n];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*bagWeight)
// Space Complexity : O(bagWeight)
// ------------------------------------
int maxValueWeightCapacity_TabulationOPTM(vector<int> &price, int n){
    vector<int> prev(n+1, 0), current(n+1, 0);
    for(int N = 0; N <= n; N++){
        prev[N] = N * price[0];
    }

    for(int index=1; index<n; index++){
        for(int N=0; N <= n; N++){
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = index+1;
            if(rodLength <= N){
                take = price[index] + current[N - rodLength];
            }
            current[N] = max(take, notTake);
        }
        prev = current;
    }
    return prev[n];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(n*bagWeight)
// Space Complexity : O(bagWeight)
// ------------------------------------
int maxValueWeightCapacity_TabulationOPTM2(vector<int> &price, int n){
    vector<int> prev(n+1, 0);
    for(int N = 0; N <= n; N++){
        prev[N] = N * price[0];
    }

    for(int index=1; index<n; index++){
        for(int N=0; N <= n; N++){
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = index+1;
            if(rodLength <= N){
                take = price[index] + prev[N - rodLength];
            }
            prev[N] = max(take, notTake);
        }
    }
    return prev[n];
}
// __________________________________________________________________________________


int main()
{
    int n, data, bagMaxWeight;
    cout<<"Size : ";
    cin>>n;
    vector<int> price;
    cout<<"Price : ";
    for(int i=0;i<n;i++){
        cin>>data;
        price.push_back(data);
    }

    vector<vector<int>> dpArr(n, vector<int> (n+1, -1));

    int knapsack_Recursion = maxValueWeightCapacity_Recursion(n-1, price, n);
    cout<<knapsack_Recursion<<endl;

    int knapsack_Mamoization = maxValueWeightCapacity_Mamoization(n-1, price, n, dpArr);
    cout<<knapsack_Mamoization<<endl;

    int knapsack_Tabulation = maxValueWeightCapacity_Tabulation(price, n);
    cout<<knapsack_Tabulation<<endl;

    int knapsack_TabulationOPTM = maxValueWeightCapacity_TabulationOPTM(price, n);
    cout<<knapsack_TabulationOPTM<<endl;

    int knapsack_TabulationOPTM2 = maxValueWeightCapacity_TabulationOPTM2(price, n);
    cout<<knapsack_TabulationOPTM2<<endl;

    return 0;
}