#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// 7 7 7 7 13 11 12 7
// Consecutive flowers : 3             
// No. of bouqets : 2
// Output : 12

int bouqets_from_harvest_days(vector<int> &arr, int mid_as_days, int consecutive_flowers){
    int n= arr.size(), count=0, no_of_bouquet=0;
    for(int i=0;i<n;i++){
        if(arr[i] <= mid_as_days)
            count++;
        else{
            no_of_bouquet += floor(count/consecutive_flowers);
            count=0;
        }
    }
    no_of_bouquet += floor(count/consecutive_flowers);
    return no_of_bouquet;
}

int min_days_for_given_no_of_bouqets(vector<int> &arr, int consecutive_flowers, int no_of_bouqets){
    int bouqets_count=0, n = arr.size();
    int low = *min_element(arr.begin(), arr.end());                 // Under #include<algorithm>
    int high = *max_element(arr.begin(), arr.end()); 
	if (no_of_bouqets > n) return -1;
	if(consecutive_flowers * no_of_bouqets > n) return -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        bouqets_count = bouqets_from_harvest_days(arr,mid,consecutive_flowers);
        if(bouqets_count >= no_of_bouqets)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}

int main()
{
    vector<int> v;
    int n,data, max_value, bouqets, consecutive;
    cout<<"Size: ";
    cin>>n;
    cout<<"Consecutive Flowers: ";
    cin>>consecutive;
    cout<<"No of Bouqets: ";
    cin>>bouqets;
    for(int i=0;i<n;i++){
        cin>>data;
        v.push_back(data);
    }
    int min_d = min_days_for_given_no_of_bouqets(v, consecutive, bouqets);
    cout<<min_d<<endl;

    return 0;
}