#include<iostream>
#include<vector>
using namespace std;


int maxNonAdjacentSum(vector<int> &arr){
    int n = arr.size();
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

// Size: 3
// Data : 2 3 2  -->> 2 (Will not take first & last as it will be adjacent)
// Maximum Robbed : 3
// --------------------------------------------------------
// Time Complexity : O(n)
// Space Complexity : O(1)
// --------------------------------------------------------
int houseRobber(vector<int> &arr, int n){
    vector<int> temp1, temp2;
    if(n == 1)  return arr[0];
    for(int i=0;i<n;i++){
        if(i != 0)  temp1.push_back(arr[i]);        // Since first and last will came as "ADJACENT" so find maxNonAjacentSum 
        if(i != n-1)  temp2.push_back(arr[i]);          // without first and last seperately and max of them will be ans.
    }
    return max(maxNonAdjacentSum(temp1), maxNonAdjacentSum(temp2));
}
// __________________________________________________________________________________

int main()
{
    int n, data;
    vector<int> arr;
    cout<<"Size: ";
    cin>>n;
    cout<<"Data : ";
    for(int i=0;i<n;i++){
        cin>>data;
        arr.emplace_back(data);
    }
    
    cout<<"-----------------------"<<endl;
    int robb = houseRobber(arr, n);
    cout<<"Maximum Robbed : "<<robb<<endl;

    return 0;
}

