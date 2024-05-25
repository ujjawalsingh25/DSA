#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include <numeric> 
using namespace std;

// 1 2 3 4 5 6 7 8 9 10   Day : 5
// capacity: 15

double days_count(vector<int> &arr, double capacity){
    double packet_sum = 0.0, last_count = 0.0;             // *** Initialize always with 0.0 ***
    int day = 0,  n = arr.size();
    for(int i=0; i<n;i++){
        packet_sum += arr[i];
        if(packet_sum > capacity){            // In given ques, till 5 sum =15 on adding it increase capacity in if statement
            day++; 
            last_count = packet_sum;                           // where sum value is more than 15 so increase day
            packet_sum = arr[i];         // and we update sum value since it is more than 15 with current index for next day sum
        }                                         // with the current index.
        // cout<<count<<" ";
    }
    if (last_count > capacity) {
        day++;                       // For last iteration if in case sum > capacity then loop ends for last so no further sum 
    }                                //  hence if any packet left it will be counted for next day.
    return day;
    
}

int minimum_capacity(vector<int> &arr, int n, int target_date) {
    int days, mid;
    // int low = 0;
    // int  high = n - 1;
    int low = *max_element(arr.begin(), arr.end());                 // Under #include<algorithm>
    int high = accumulate(arr.begin(), arr.end(), 0);               // Under #include <numeric> 
    while (low <= high) {
        mid = low + (high - low) / 2;
        days = days_count(arr, mid);
        if (days <= target_date) {
            high = mid - 1;
            
        } else
           low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> v;
    int n,data, capacity;
    cout<<"Size: ";
    cin>>n;
    cout<<"Target Date: ";
    cin>>capacity;
    cout<<"Array: ";
    for(int i=0;i<n;i++){
        cin>>data;
        v.push_back(data);
    }
    int min_load = minimum_capacity(v, n, capacity);
    cout<<min_load<<endl;
    // int d = days(v,capacity);
    // cout<<d<<endl;

    return 0;
}