#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int minimum_rotated_array(vector<int> &arr){

    // Shortest***************
    //     int low = 0, high = arr.size() - 1;
    //     while (low < high) {
    //         int mid = low + (high - low) / 2;

    //         if (arr[mid] > arr[high])   low = mid + 1;
    //         else    high = mid;
    //     }
    // return arr[low]; 




    int ans = INT_MAX;                        // Initialize the ans with a large number, as need to compare for minimum in line 13,18,24
    int n = arr.size(), low = 0, high = n-1;
    int index = -1;                             // Since index starts from 0 so initialize to -1.
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[low] <= arr[high]){              // If low <= high, then whole array is already sorted. 
            ans = min(ans, arr[low]);
            index = low;                        // to get the index position.
            break;                              // Break as we get the index so to reduce run-time.
        }
        else if(arr[low] <= arr[mid]){     //If low <= mid, so Left half is already sorted, the left one is be the smallest in left half.
            ans = min(ans,arr[low]);            //Since, the left half is sorted so store the minmum of left for futher check in right
            low = mid +1;                       //  Set low to 'mid+1' or low of other half to search the lowest in other half.
            index = low;
        }
        else if(arr[low] >= arr[mid]){     //If low <= mid, so Right half is already sorted.
            high = mid - 1;                 //  Set low to 'mid+1' or low of other half to search the lowest in other half.
            ans = min(ans, arr[mid]);      //Left one of right half is be the smallest in right half.
            index = mid;                   // so store the minmum of left for futher check in right
        }                                  
    }
    return index;
}


int main()
{
    int a, n, target;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    auto result = minimum_rotated_array(v);
    cout<<result <<endl;

 return 0;
}