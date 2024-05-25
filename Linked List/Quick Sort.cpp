#include<iostream>
#include<vector>
using namespace std;

// 5 2 4 1 3 7 6

void swap(int &x, int &y){
    int temp =x;
    x = y;
    y = temp;
}

int pivot_position(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if(i < j){
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[low], arr[j]);
  return j;
}

void quick_sort(vector<int> &arr, int low, int high){
    if(low < high){
       int pivot_index = pivot_position(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }

}

int main()
{
    vector<int> arr;
    int n, data;
    cout<<"Size : "; 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        arr.emplace_back(data);
    }
    quick_sort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
  return 0;  
}