#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 1 1 2 2 3 3 4 5 5 6 6
// Output : 4 

int single_sorted(vector<int> & arr){
  int n=arr.size(), mid;
  int low=0, high = n-1;
  while (low <= high){
    mid = low + (high - low)/2;
    if(n==1)
        return arr[0];
    else if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1])
        return arr[mid];
    else if( mid % 2 == 1 && arr[mid] == arr[mid-1] || mid % 2 == 0 && arr[mid] == arr[mid+1])
        low = mid+1;   // Data start from 0 so all double data will be from even to odd (Eg. 1 start at 0 'even' & end at 1 'odd').
                       // ALso if mid start at even and its double end at odd means previous data does not have single element.
                // So we check if mid at odd then previous data should be same or if mid is at even then next data should be same.
    else
        high = mid-1;        // If mid at odd or even and previous or next data are not same resp. not at same time both different
                            //  then single element must be in left half from mid.  
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
    int element = single_sorted(v);
    cout<<element<<endl;

    return 0;
}