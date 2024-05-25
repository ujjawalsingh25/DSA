// A person eat banana at a rate of h hour, he has been given a series of banana. 
// Find the minimum time required 'h' within a deadline time to eat all banana. 
// Size: 5
// 1 3 5 7 12
// Maximum Hour: 8
// Output: 5
//  Here is person eat minimum of 5 banana in 1 hr then he can eat all banana also max time less than 8.

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

double cal_hour(vector<int> &arr, double h){
   double total_h = 0.0, n = arr.size();
    for(int i=0;i<n;i++){
    total_h += ceil(arr[i] / h);
    }
   return total_h;
}

int banana_eating(vector<int> &arr, int hour){
    int n = arr.size(), total_time = 0, ans=0;
    int mid, low = 1, high =n-1;
    while(low <= high){
        mid = low + (high - low)/2;
        total_time = cal_hour(arr, mid);
        if(total_time <= hour){
            high = mid -1;
        }
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    vector<int> v;
    double n, data, hour;
    cout<<"Size: ";
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>data;
        v.push_back(data);
    }
    cout<<"Maximum Hour: ";
    cin>>hour;
    auto answer = banana_eating(v, hour);
    cout<<answer<<endl;
    
    return 0;
}


