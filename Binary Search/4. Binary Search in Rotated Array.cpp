// Binary Search in Rotated Array 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int binary_search_rotated_array(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if (arr[mid] == target)
            return mid;
        else if(arr[low] == arr[mid] && arr[mid] == arr[high]){         // For dublicate data
            low ++;
            high --;
            continue;
        }
        else if(arr[low] <= arr[mid]){           // To check if left side is sorted.
            if(arr[low] <= target && target <= arr[mid])        // Checks if target less than low and also less than mid 
                                                                // means target is in left half
                high = mid - 1;                                 // then simple binary search by decresing high till it reach mid.
            else                                                // or increse low till it reach mid. 
                low = mid + 1;
            }
        else {                                                 // *** Since left is not sorted so right must be.
            if(arr[mid] <= target && target <= arr[high])      // Checks if target greater than low and also greater than mid 
                                                                // means target is in right half
                low = mid + 1;                                 // then simple binary search by decresing high till it reach mid.                          
            else                                               // or increse low till it reach mid. 
                high = mid - 1;                               
            }
    }
    return -1;
}

int main()
{
    int a, n, target;
    vector<int> v;
    cin>>n>>target;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    auto result = binary_search_rotated_array(v, target);
    cout<<result + 1 <<endl;

 return 0;
}