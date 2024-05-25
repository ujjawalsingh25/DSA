#include<iostream>
#include<vector>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void selection_sort(vector<int> &arr, int n){
    int min_index;
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
} 

void bubble_sort(vector<int> &arr, int n){
    bool is_swaped;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                is_swaped = true;
            }
        }
        if (is_swaped == false)
            break;
    }
}

void insertion_sort(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        int j=i;
        // cout<<"runs"<<endl;
        while(j>0 && arr[j-1] > arr[j]){
            // cout<<"i: "<<i<<"  "<<"j: "<<j<<endl;
            // cout<<"arr[i]: "<<arr[i]<<"  "<<"arr[j-1]: "<<arr[j-1]<<"   "<<"arr[j] :"<<" "<<arr[j]<<endl;
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

int main()
{
    int n, data, opt;
    vector<int> v;
    cout<<"Size: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        v.emplace_back(data);
    }

    cout<<"Select Method \n 1. Selection Sort \n 2. Bubble Sort \n 3. Insertion Sort"<<endl;
    cin>>opt;
    switch(opt){
        case 1:
            selection_sort(v, n);
            break;
        case 2:
            bubble_sort(v, n);
            break;
        default:
            insertion_sort(v, n);
            break;
    }
    
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}