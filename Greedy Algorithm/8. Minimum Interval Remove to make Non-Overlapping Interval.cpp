#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct intervals {
    int position, startTime, endTime;
};

bool compare(intervals a, intervals b){
    return a.endTime < b.endTime;
}

// Size: 6
// Interval Start-Time: 0 3 1 5 5 7
// Interval  End-Time : 5 4 2 9 7 9
// -------------------------------------------------------------------------------
// -------- After Sorted --------
// Position -- StartTime -- EndTime
//     3    --     1     --    2
//     2    --     3     --    4
//     1    --     0     --    5
//     5    --     5     --    7
//     4    --     5     --    9
//     6    --     7     --    9
// -------------------------------------------
//  Minimum Interval Remove to make Non-Overlapping Interval: 2
//  Non-Overlapping Intervals : 3 2 5 6 
//  Non-Overlapping Intervals(Pos, StartTime, EndTime)  -->> { [(3), 1 , 2] , [(2), 3, 4] , [(5), 5, 7] , [(6), 8, 9] }
//  Removed Intervals : 1 4
//  Removed Intervals: { [(1), 0, 5] , [(4), 5, 9] }
// -------------------------------------------------------------------------------

// _____________________________________________________________________________________________
// Time Complexity :  O(n*log(n) + n)
// Space Complexity:  O(1) 
// -----------------------------------------------------
pair<int, pair<vector<int>, vector<int>> > RemoveMinInterval_NonOverlappingInterval(vector<intervals> &arr, int n) {
    sort(arr.begin(), arr.end(), compare);   // since arr contains 3 data so sort w.r.t 'endTime' using 'COMPARE function'
    int count=1, lastEndTime=arr[0].endTime;
    vector<int> intervalList = {arr[0].position};
    vector<int> removedIntervals;
    for(int i=1;i<n;i++) {
        if(arr[i].startTime >= lastEndTime) {
            lastEndTime = arr[i].endTime;
            intervalList.push_back(arr[i].position);
            count++;
        }else {
            removedIntervals.push_back(arr[i].position);
        }
    }
    return {n-count, {intervalList, removedIntervals}};
}
// _____________________________________________________________________________________________


int main()
{
    int n;
    cout<<"Size: ";
    cin>>n;
    vector<int> start(n), end(n);
    vector<intervals> arr(n);

    //Position
    for(int i=0;i<n;i++) {
        arr[i].position = i+1;
    }

    cout<<"Interval Start-Time: ";
    for(int i=0;i<n;i++) {
        cin>>start[i];
        arr[i].startTime = start[i];
    }

    cout<<"Interval  End-Time : ";
    for(int i=0;i<n;i++) {
        cin>>end[i];
        arr[i].endTime = end[i];
    }
    cout<<"------ Input ------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i].position<<" -- "<<arr[i].startTime<<" -- "<<arr[i].endTime<<endl;
    }cout<<endl;

    cout<<"-------- After Sorted --------"<<endl;
    cout<<"Position"<<" -- "<<"StartTime"<<" -- "<<"EndTime"<<endl;
    sort(arr.begin(), arr.end(), compare);   // since arr contains 3 data so specifying to sort w.r.t 'profit using 'COMPARE function'
    for(int i=0;i<n;i++){
        cout<<"    "<<arr[i].position<<"    --     "<<arr[i].startTime<<"     --    "<<arr[i].endTime<<endl;
    }
    cout<<"_______________________"<<endl;

    pair<int, pair<vector<int>, vector<int>> > minRemoveInterval = RemoveMinInterval_NonOverlappingInterval(arr, n);
    cout<<"Minimum Interval Remove to make Non-Overlapping Interval: "<<minRemoveInterval.first<<endl;
    cout<<"Non-Overlapping Intervals : ";
    for(auto iterPOS: minRemoveInterval.second.first){
        cout<<iterPOS<<" ";
    }cout<<endl;
    cout<<"Removed Intervals : ";
    for(auto iterPOS: minRemoveInterval.second.second){
        cout<<iterPOS<<" ";
    }cout<<endl;

    return 0;
}