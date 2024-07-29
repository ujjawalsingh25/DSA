#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// -------------------------------------------------------------------------------
// Size: 6
// Arrival: 900 945 955 1100 1500 1800
// Departure: 920 1200 1130 1150 1900 2000
// Minimum number of platform require in Railway Station: 3
// -------------------------------------------

// _____________________________________________________________________________________________
// Time Complexity :  O(n^2)
// Space Complexity:  O(1) 
// -----------------------------------------------------
int minPlatformReq_inRailwayStation(vector<int> &arrival, vector<int> &departure, int n) {
    int maxCount = 0, count;
    for(int i=0;i<n;i++) {
        count = 1;
        for(int j=i+1;j<n;j++) {
            // Check if trains i and j overlap
            if ((arrival[i] < departure[j] && departure[i] > arrival[j])) {
                count++;
            }
        }
        maxCount = max(maxCount, count);
    }
    
    return maxCount;
}
// _____________________________________________________________________________________________


// _____________________________________________________________________________________________
// Time Complexity :  O(2(n*logn) + n)
// Space Complexity:  O(1) 
// -----------------------------------------------------
int minPlatformReq_inRailwayStation_2Pointer(vector<int> &arrival, vector<int> &departure, int n) {
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int maxCount = 0, count=0, i=0, j=0;
    while(i < n) {
        if(arrival[i] <= departure[j]) {
            count++;
            i++;
        } else {
            count--;
            j++;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
// _____________________________________________________________________________________________



int main()
{
    int n, data;
    cout<<"Size: ";
    cin>>n;

    vector<int> arrival, departure;
    cout<<"Arrival: ";
    for(int i=0;i<n;i++) {
        cin>>data;
        arrival.push_back(data);
    } 
    cout<<"Departure: ";
    for(int i=0;i<n;i++) {
        cin>>data;
        departure.push_back(data);
    } 

    int minPlatform = minPlatformReq_inRailwayStation(arrival, departure, n);
    cout<<"Minimum number of platform require in Railway Station: "<<minPlatform<<endl;

    int minPlatformOPTM = minPlatformReq_inRailwayStation_2Pointer(arrival, departure, n);
    cout<<"Minimum number of platform require in Railway Station: "<<minPlatformOPTM<<endl;

    return 0;
}