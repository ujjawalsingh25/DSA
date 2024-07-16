#include<iostream>
#include<vector>
using namespace std;

// Size: 4
// Path : 2 1 4 9       -->> 11 (2, 9)
// Using Mamoization : 11
// Using Tabulation : 11
// Using Tabulation Optimised : 11
// ___________________________  Using Mamoization  ______________________________
// Time Complexity : O(n)
// Space Complexity : O(n) + O(n)  (Recursion + Dp Array)
// ------------------------------------
int max_Non_AdjacentSum(vector<int> &arr, int index, vector<int> &dpArr){
    if(index < 0)  return 0;
    if(index == 0)  return arr[index];
    if(dpArr[index] != -1)  return dpArr[index];

    int pickCurrIndex = arr[index] + max_Non_AdjacentSum(arr, index-2, dpArr); 
    int notPickCurrIndex = 0 + max_Non_AdjacentSum(arr, index-1, dpArr);
    dpArr[index] = max(pickCurrIndex, notPickCurrIndex);

    return dpArr[index];
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  __________________________________
// Time Complexity : O(n)
// Space Complexity : O(n)
// ------------------------------------
int max_Non_AdjacentSum_TABL(vector<int> &arr, int n, vector<int> &dpArr){
    dpArr[0] = arr[0];
    dpArr[1] = max(arr[0], arr[1]);
    
    for(int i=2;i<n;i++){
        int pickCurrIndex = arr[i] + dpArr[i - 2];
        int notPickCurrIndex = 0 + dpArr[i-1];

        dpArr[i] = max(pickCurrIndex, notPickCurrIndex);
    }
    return dpArr[n-1];
}
// _______________________  OPTIMISED  _______________________
// Time Complexity : O(n)
// Space Complexity : O(1)
// ------------------------------------
int max_Non_AdjacentSum_TABL_OPT(vector<int> &arr, int n){
    int prev = arr[0];
    int prev2 = 0;
    
    for(int i=1;i<n;i++){
        int pickCurrIndex = arr[i];
        
        if(i > 1)   pickCurrIndex += prev2;
        int notPickCurrIndex = 0 + prev;

        int currentIndex = max(pickCurrIndex, notPickCurrIndex);

        prev2 = prev;
        prev = currentIndex;
    }
    return prev;
}
// __________________________________________________________________________________

int main()
{
    int n, data;
    cout<<"Size: ";
    cin>>n;

    vector<int> arr;
    vector<int> dpArr(n, -1);
    cout<<"Data : ";
    for(int i=0;i<n;i++){
        cin>>data;
        arr.emplace_back(data);
    }
    
    cout<<"-----------------------"<<endl;
    int maxVAl = max_Non_AdjacentSum(arr, n-1, dpArr);      // n-1 because indexing is taken as (0 -> n-1)
    cout<<"Using Mamoization : "<<maxVAl<<endl;

    int maxVAlTAb = max_Non_AdjacentSum_TABL(arr, n, dpArr);
    cout<<"Using Tabulation : "<<maxVAl<<endl;

    int maxVAl_TAbOPTM = max_Non_AdjacentSum_TABL_OPT(arr, n);
    cout<<"Using Tabulation Optimised : "<<maxVAl_TAbOPTM<<endl;

    return 0;
}

