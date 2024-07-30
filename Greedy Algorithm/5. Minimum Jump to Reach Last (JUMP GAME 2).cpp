#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Size : 8
// Array : 2 3 1 4 1 1 1 2
// ----------------------------------------------
// Minimum Jump to Reach Last : 3
//      2    3  1     4  1  1  1  2
//    |__|  |_____| |_____|         -->> After 3 jumps from 4 it reaches to last.
// ----------------------------------------------

// _____________________________________________________________________
// Time Complexity : O(n^n)     -->> Exponential      
// Space Complexity : O(n) 
// ------------------------------------------------------
int minJumpTo_ReachLast_Recursion(vector<int> &arr, int n, int index, int jumps){
    if(index >= n-1)    return jumps;
    int mini = INT_MAX;
    for(int i=1; i <= arr[index]; i++){
        mini = min(mini, minJumpTo_ReachLast_Recursion(arr, n, index+i, jumps+1));
    }
    return mini;
}
// _______________________________________________________________________________________

// _____________________________________________________________________
// Time Complexity : O(n^2)      
// Space Complexity : O(n^2) 
// ------------------------------------------------------
int minJumpTo_ReachLast_Mamoization(vector<int> &arr, int n, int index, vector<int> &dpArr){
    if(index >= n-1)    return 0;
    int mini = INT_MAX;
    if (dpArr[index] != -1) return dpArr[index];

    for(int i=1; i <= arr[index]; i++){
        int jumps = minJumpTo_ReachLast_Mamoization(arr, n, index + i, dpArr);
        if (jumps != INT_MAX) { // To avoid overflow
            mini = min(mini, jumps + 1);
        }
    }
    return dpArr[index] = mini;
}
// _______________________________________________________________________________________



// _____________________________________________________________________
// Time Complexity : O(n)      
// Space Complexity : O(1) 
// ------------------------------------------------------
int minJumpTo_ReachLast(vector<int> &arr, int n){
    if (n <= 1) return 0; // No jumps needed if array has 1 or no element
    if (arr[0] == 0) return -1; // If the first element is 0, end is not reachable

    int jumps = 1; // At least one jump is needed initially
    int maxReach = arr[0]; // Maximum index reachable with the current jumps
    int steps = arr[0]; // Steps we can still take with the current jumps

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps; // If we have reached the last element

        maxReach = max(maxReach, i + arr[i]); // Update maxReach
        steps--; // Use a step to move from index i to index i+1

        if (steps == 0) { // If no steps are remaining
            jumps++; // Increment jump count
            if (i >= maxReach) return -1; // If the current position is beyond or at maxReach, end is not reachable
            steps = maxReach - i; // Reinitialize steps to the amount of steps to reach maxReach from i
        }
    }

    return -1; // If the end is not reachable
// ---------------------------------------------------------------
//    int jumps = 0, minReach = arr[0], maxReach = arr[0];
//    while(maxReach < n-1){
//        int farthestReach = 0;
//        for(int i = minReach; i < maxReach; i++){
//           farthestReach = max(arr[i] + i, farthestReach);
//        }
//        minReach = maxReach + 1;
//        maxReach = farthestReach;
//        jumps = jumps + 1;
//    } 
//    return jumps;
// ---------------------------------------------------------------
}
// _______________________________________________________________________________________

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
    vector<int> dpArr(n, -1); // Using a 1D array for memoization
    int jumpGame_Recursion = minJumpTo_ReachLast_Recursion(arr, n, 0, 0);
    cout<<"Minimum Jump to Reach Last : "<<jumpGame_Recursion<<endl;

    int jumpGame_Mamoization = minJumpTo_ReachLast_Mamoization(arr, n, 0, dpArr);
    cout<<"Minimum Jump to Reach Last : "<<jumpGame_Mamoization<<endl;

    int jumpGame = minJumpTo_ReachLast(arr, n);
    cout<<"Minimum Jump to Reach Last : "<<jumpGame<<endl;

    return 0;
}