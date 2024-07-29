#include<iostream>
#include<vector>
using namespace std;

// Size : 8
// Array : 1 2 3 1 1 0 2 5
// False  -->> Can't Jump to Last

// Size : 8
// Array : 1 2 4 1 1 0 2 5
// ----------------------------------------------
// True --> Can Jump to Last
//      1  2  4  1  1  0  2  5
//      0  1  2  3  4  5  6  7
//  maxReached_Index = 0 -> 1 -> 3 -> 6 -> 8    Since can reach upto 8 and arr till 7 so can reach to last 
// ----------------------------------------------

// _____________________________________________________________________
// Time Complexity : O(n)      
// Space Complexity : O(1) 
// ------------------------------------------------------
bool canJumpToLast(vector<int> &arr, int n){
    int maxReached_Index = 0;
    for(int i=0;i<n;i++){
        if(i > maxReached_Index)    return false;
        maxReached_Index = max(maxReached_Index, i+arr[i]);
    }
    return true;
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

    bool jumpGame = canJumpToLast(arr, n);
    if(jumpGame)    cout<<"True --> Can Jump to Last"<<endl;
    else    cout<<"False  -->> Can't Jump to Last"<<endl;

    return 0;
}