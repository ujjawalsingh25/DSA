#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Size: 6
// kPlace: 2
// Path : 30 10 60 10 60 50
// 30 -> 60 -> 60 -> 50     -->> 40
// ******** Frog jumps at max of 2 (i+1 || i+2)
// Frog Jump for Min Path using Mamoization : 40
// Frog Jump for Min Path using Tabulation: 40
// ___________________________  Using Mamoization  ______________________________
// Time Complexity : O(n) * K
// Space Complexity : O(n) + O(n)  (Recursion + Dp Array)
// ------------------------------------
int find_K_MIN_Path(vector<int> &arr, int ind, int kPlace, vector<int> &dpArr){
    if(ind == 0) return 0;
    int minSteps = INT_MAX;
    for(int i=0;i<kPlace;i++){
        if(ind - i >= 0) {
            int jump = find_K_MIN_Path(arr, ind - i, kPlace, dpArr) + abs(arr[ind] - arr[ind-i]);
            minSteps = min(minSteps, jump);
        }
    }
    
    return minSteps;
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  __________________________________
// Time Complexity : O(n)
// Space Complexity : O(n)
// ------------------------------------
int find_K_MIN_PathTABL(vector<int> &arr, int kPlace, int ind,  vector<int> &dpArr){
    if(ind == 0) return 0;
    dpArr[0] = 0;
    for(int i=0;i<ind;i++){
        int minSteps = INT_MAX;
        for(int j=1;j<kPlace;j++){
            if(ind - i >= 0) {
                int jump = dpArr[i - j] + abs(arr[ind] - arr[ind-i]);
                minSteps = min(minSteps, jump);
            }
        }
        dpArr[i] = minSteps;
    }
    return dpArr[ind-1];
}
// __________________________________________________________________________________


int main()
{
    int n , data, k;
    cout<<"Size: ";
    cin>>n;
    cout<<"KPlace: ";
    cin>>k;
    cout<<"Path : ";

    vector<int> arr;
    vector<int> dpArr(n+1, -1);
    
    for(int i=0;i<n;i++){
        cin>>data;
        arr.emplace_back(data);
    }

    int ans = find_K_MIN_Path(arr, n-1, k, dpArr);              // n-1 because indexing is taken as (0 -> n-1)
    cout<<"Frog Jump for Min Path using Mamoization : "<<ans<<endl;

    int ansTabulation = find_K_MIN_PathTABL(arr, k, n, dpArr);
    cout<<"Frog Jump for Min Path using Tabulation: "<<ansTabulation<<endl;

    return 0;
}