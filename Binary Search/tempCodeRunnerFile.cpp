#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

void minResistance(vector<int> &arr, int h){
   
}

int banana_eating(vector<int> &arr, int n){
    int n = arr.size();
    int mid, low = 0, high = max(arr.begin(), arr.end());
    while(low <= high){
        mid = low + (high - low)/2;
        min_res = minResistance(arr, mid);
        if(min_res <= hour){
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
    int t,enemy,strength;
    while(t--){
	    cin>>enemy>>strength;
	    for(int i=0; i<enemy;i++){
            cin>>data;
            v.push_back(data);
        }
	    
        int rest = 

    }
    
    // cin>>hour;
    // auto answer = banana_eating(v, hour);
    // cout<<answer<<endl;
    
    return 0;
}


