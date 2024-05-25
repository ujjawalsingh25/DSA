#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 1 10 13 7 6 5 4 3 2 1 0
// Output: 13
//  Inc curve       Decreasing curve
    //      /\
    //    /    \  
    //  /        \   
    //             \
    //               \

int peek_in_sorted(vector<int> & arr){
  int n = arr.size(), mid;
  int low = 1, high = n-2;

    if(n == 1)
        return 0;
    else if(arr[0] > arr[1])
        return 0;
    else if(arr[n-1] > arr[n-2])
        return n-1;

    while(low <= high){
        mid = low + (high - low)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])      // When data is greater from both next & prev then it is peak.
            return mid;
        else if(arr[mid] > arr[mid-1])      // When mid greater than prev data means it is at increasing curve.
            low = mid+1;                    // So peak must be on right half of mid.
        else if(arr[mid] > arr[mid+1])      // When mid greater than next data means it is at decreasing curve.
            high = mid -1;                  // So peak must be on left half of mid.
    }
    return -1;
}


int main()
{
    int n, data;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }
    int element_index = peek_in_sorted(v);
    cout<<element_index<<endl;

    return 0;
}