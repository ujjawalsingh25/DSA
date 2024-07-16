#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Size: 6
// Path : 30 10 60 10 60 50
// 30 -> 60 -> 60 -> 50     -->> 40
// ******** Frog jumps at max of 2 (i+1 || i+2)
// Frog Jump for Min Path using Mamoization : 40
// Frog Jump for Min Path using Tabulation: 40
// Frog Jump for Min Path using Tabulation Optimised: 40
// ___________________________  Using Mamoization  ______________________________
// Time Complexity : O(n)
// Space Complexity : O(n) + O(n)  (Recursion + Dp Array)
// ------------------------------------
int findMIN_Path(vector<int> &arr, int n, vector<int> &dpArr){
    if(n == 0) return 0;
    if(dpArr[n] != -1)   return dpArr[n];

    int leftPrev1 = findMIN_Path(arr ,n-1, dpArr) + abs(arr[n] - arr[n-1]);
    int leftPrev2 = INT_MAX;
    if(n > 1)   
        leftPrev2 = findMIN_Path(arr, n-2, dpArr) + abs(arr[n] - arr[n-2]);
    
    return dpArr[n] = min(leftPrev1, leftPrev2);
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  __________________________________
// Time Complexity : O(n)
// Space Complexity : O(n)
// ------------------------------------
int findMIN_PathTABL(vector<int> &arr, int n){
    vector<int> dpArr(n, 0);
    dpArr[0] = 0;
    for(int i=1;i<n;i++){
        int leftPrev1 = dpArr[i-1] + abs(arr[i] - arr[i-1]);
        int leftPrev2 = INT_MAX;
        if(i > 1)   leftPrev2 = dpArr[i-2] + abs(arr[i] - arr[i-2]);

        dpArr[i] = min(leftPrev1, leftPrev2);
    }
    
    return dpArr[n-1];
}
// _______________________  OPTIMISED  _______________________
// Time Complexity : O(n)
// Space Complexity : O(1)
// ------------------------------------
int findMIN_PathTABL_Optmised(vector<int> &arr, int n){
    int prev1 = 0;
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int leftPrev1 = prev1 + abs(arr[i] - arr[i-1]);
        int leftPrev2 = INT_MAX;
        if(i > 1)   leftPrev2 = prev2 + abs(arr[i] - arr[i-2]);

        int current = min(leftPrev1, leftPrev2);
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}
// __________________________________________________________________________________


int main()
{
    int n , data;
    cout<<"Size: ";
    cin>>n;
    cout<<"Path : ";

    vector<int> arr;
    vector<int> dpArr(n+1, -1);
    
    for(int i=0;i<n;i++){
        cin>>data;
        arr.emplace_back(data);
    }

    int ans = findMIN_Path(arr, n-1, dpArr);
    cout<<"Frog Jump for Min Path using Mamoization : "<<ans<<endl;

    int ansTabulation = findMIN_PathTABL(arr, n);
    cout<<"Frog Jump for Min Path using Tabulation: "<<ansTabulation<<endl;
    int ansTabulation2 = findMIN_PathTABL_Optmised(arr, n);
    cout<<"Frog Jump for Min Path using Tabulation Optimised: "<<ansTabulation2<<endl;

    return 0;
}