#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// -------------------------------------------------------------------------------
//   Size: 5
//   [ StartTime, EndTime ] : [ 1, 2 ], [ 3, 4 ], [ 5, 7 ], [ 8, 10 ], [ 12, 16 ]
// -------------------------------------------
// Maximum Meeting Possible(N Meeting in One Room): 4
// (StartTime, EndTime)  -->> { [1, 2] , [3, 4], [5, 7], [8, 10], [12, 16] }
//                                              |_______________|
// (StartTime, EndTime)  -->> { [1, 2] , [3, 4],  [  5 , 10   ],   [12, 16] }
//          
// (StartTime, EndTime)  -->> { [1, 3] , [6, 9] }
// [ New-Interval ] : [2 5]
// (StartTime, EndTime)  -->> { [1, 5] ,  [6, 9] }
//          
// (StartTime, EndTime)  -->> { [1, 2] , [3, 4] , [8, 9] }
// [ New-Interval ] : [6, 7]
// (StartTime, EndTime)  -->> { [1, 2] , [3, 4] , [6, 7] , [8, 9] }
// -------------------------------------------------------------------------------

// _____________________________________________________________________________________________
// Time Complexity :  O(n)
// Space Complexity:  O(n) 
// -----------------------------------------------------
int insertInterval_toMakeNonOverlapping(int arr[][2], int newInterval[2], int n, int intervalList[][2]) {
    int i = 0, k=0;    
    //left side of the required insertion position
    while(i < n && arr[i][1] < newInterval[0]) {
        intervalList[k][0] = arr[i][0];
        intervalList[k][1] = arr[i][1];
        i++;   k++;
    }

    // expanding the time in case of overlapping
    while(i < n && arr[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], arr[i][0]);
        newInterval[1] = max(newInterval[1], arr[i][1]);
        i++;
    }

    // Insert the merged new interval
    intervalList[k][0] = newInterval[0];
    intervalList[k][1] = newInterval[1];
    k++;

    // right side of the required insertion position
    while(i < n) {
        intervalList[k][0] = arr[i][0];
        intervalList[k][1] = arr[i][1];
        i++;   k++;
    }
    return k;
}
// _____________________________________________________________________________________________


int main()
{
    int n;
    cout<<"Size: ";
    cin>>n;
    int arr[n][2];
    int newInterval[2];
    int intervalList[n + 1][2]; // one added as it need to add one more interval

    cout<<"[Interval StartTime, EndTime] : ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"------ Input ------"<<endl;
    cout<<"[ StartTime, EndTime ] : ";
    for(int i=0;i<n;i++){
        cout<<"[ "<<arr[i][0]<<", "<<arr[i][1]<<" ]"<<", ";
    }cout<<endl;

    cout<<"[ New-Interval ] : ";
    cin>>newInterval[0]>>newInterval[1];
    cout<<endl<<"_______________________"<<endl;

    int intervalIter = insertInterval_toMakeNonOverlapping(arr, newInterval, n, intervalList);    
    cout<<"New Interval [ StartTime, EndTime ] : ";
    for(int i=0; i<intervalIter; i++){
        cout<<"[ "<<intervalList[i][0]<<", "<<intervalList[i][1]<<" ]"<<", ";
    };

    return 0;
}