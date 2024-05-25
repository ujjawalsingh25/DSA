#include<iostream>
#include<vector>
using namespace std;

// 2 3 5 7 11    missing_index: 5
// Output : 9

int missing_value(vector<int> &arr, int missing_index){
    int n = arr.size();
    int low=0, high=n-1;
    while(low<=high){
      int mid= low + (high - low)/2;
      int total_missing_no_between_data = arr[mid] - (mid+1);
      if(total_missing_no_between_data < missing_index){
        low = mid+1;
      }
      else
        high = mid-1;
    }
    return missing_index + high + 1;             // ( low = high + 1 )
}

int main()
{
    vector<int> v;
    int n,data, missing_index;
    cout<<"Size: ";
    cin>>n;
    cout<<"Missing Index: ";
    cin>>missing_index;
    cout<<"Array Data: ";
    for(int i=0;i<n;i++){
        cin>>data;
        v.push_back(data);
    }
    int result = missing_value(v, missing_index);
    cout<<"Missing val: "<<result<<endl;

  return 0;
}