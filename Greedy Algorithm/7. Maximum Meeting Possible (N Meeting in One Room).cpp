#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meeting {
    int position, startTime, endTime;
};

bool compare(meeting a, meeting b){
    return a.endTime < b.endTime;
}

// Size: 6
// Meeting Start-Time: 0 3 1 5 5 8
// Meeting  End-Time : 5 4 2 9 7 9
// -------------------------------------------------------------------------------
// -------- After Sorted ---------------------
// Position -- StartTime -- EndTime
//     3    --     1     --    2
//     2    --     3     --    4
//     1    --     0     --    5
//     5    --     5     --    7
//     4    --     5     --    9
//     6    --     8     --    9
// -------------------------------------------
// Maximum Meeting Possible(N Meeting in One Room): 4
// (Pos, StartTime, EndTime)  -->> { [(3), 1 , 2] , [(2), 3, 4] , [(5), 5, 7] , [(6), 8, 9] }
// -------------------------------------------------------------------------------

// _____________________________________________________________________________________________
// Time Complexity :  O(n*log(n) + n)
// Space Complexity:  O(3n) + O(n) 
// -----------------------------------------------------
pair<int, vector<int>> maxMeetingPossible_nMeetingInOneRoom(vector<meeting> &arr, int n) {
    sort(arr.begin(), arr.end(), compare);   // since arr contains 3 data so specifying to sort w.r.t 'endTime' using 'COMPARE function'
    int count=1, freeTime=arr[0].endTime;
    vector<int> joinedList = {arr[0].position};
    for(int i=0;i<n;i++) {
        if(arr[i].startTime > freeTime) {
            freeTime = arr[i].endTime;
            joinedList.push_back(arr[i].position);
            count++;
        }
    }
    return {count, joinedList};
}
// _____________________________________________________________________________________________


int main()
{
    int n;
    cout<<"Size: ";
    cin>>n;
    vector<int> start(n), end(n);
    vector<meeting> arr(n);

    //Position
    for(int i=0;i<n;i++) {
        arr[i].position = i+1;
    }

    cout<<"Meeting Start-Time: ";
    for(int i=0;i<n;i++) {
        cin>>start[i];
        arr[i].startTime = start[i];
    }

    cout<<"Meeting  End-Time : ";
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

    pair<int, vector<int> > maxMeetings = maxMeetingPossible_nMeetingInOneRoom(arr, n);
    cout<<"Maximum Meeting Possible(N Meeting in One Room): "<<maxMeetings.first<<endl;
    cout<<"Meeting Joined : ";
    for(auto iterPOS: maxMeetings.second){
        cout<<iterPOS<<" ";
    }cout<<endl;

    return 0;
}