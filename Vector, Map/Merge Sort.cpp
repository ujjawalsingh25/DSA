#include<iostream>
#include<vector>
using namespace std;

// 2 1 3 4 3
// Space Complexity : O(n)
// Time Complexity : O(n * log N )
// N --> for merge_array
// logN --> for merge_sort

void merge_array(vector<int> &arr, int low, int mid, int high){
    vector <int> temp_arr;
    int left = low, right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp_arr.push_back(arr[left]);
            left++;
        }
        else{
            temp_arr.push_back(arr[right]);
            right++;
        }
    }
     while(left <= mid){
        temp_arr.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp_arr.push_back(arr[right]);
        right++;
    } 
    for(int i=low; i<=high; i++){
        arr[i] = temp_arr[i-low];
    }
}

void merge_sort(vector<int> &arr, int low, int high){
// If you use a while loop condition instead of an if condition, the merge_sort function will continue dividing the array
// indefinitely, leading to a stack overflow. Therefore, it's crucial to keep the if condition to ensure the termination 
// of the recursion when the segment to be sorted is already of size 1 or 0.
// we can also use if as
    //  if(low < high){     
    if(low == high) return;
        int mid = low + (high-low)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge_array(arr,low, mid, high);
    // }
    
}

int main()
{
    vector<int> v;
    int n, data;
    cout<<"Size: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        v.emplace_back(data);
    }
    merge_sort(v, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }

 return 0;
}
