#include<iostream>
#include<vector>
using namespace std;

// 2 1 3 3 4 6 10 1 6 8 3 7
// t1 t2 t3
// 2  1  3   --> day0
// 3  4  6   --> day1
// 10 1  6   --> day2
// 8  3  7   --> day3
// ----------------------
// Points using Reccursion: 25
// Points using DP Mamoization: 25
// Points using DP Tabulation: 25
// Points using DP Tabulation: 25

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(N * 4) * 3
// Space Complexity : O(N * 4) (Recursion)
// ------------------------------------
int ninjaTrainingPOINTS_Recusion(vector<vector<int>> &arr, int lastTask, int day){
    if(day == 0){
        int maxPoint = 0;
        for(int task = 0; task<3; task++){
            if(task != lastTask)    maxPoint = max(maxPoint, arr[0][task]);
        }
        return maxPoint;
    }
    int maxPoint = 0;
    for(int task=0;task<3;task++){
        if(task != lastTask){
            int point = arr[day][task] + ninjaTrainingPOINTS_Recusion(arr, task, day-1);
            maxPoint = max(maxPoint, point);
        }
    }
    return maxPoint;    
}
// _______________________________________________________________________________________

// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(N * 4) * 3
// Space Complexity : O(N) + O(N * 4) (Recursion + DP)
// ------------------------------------
int ninjaTrainingPOINTS_Mamoization(vector<vector<int>> &arr, int lastTask, int day, vector<vector<int>> &dpArr){
    if(day == 0){
        int maxPoint = 0;
        for(int task = 0; task<3; task++){
            if(task != lastTask)    maxPoint = max(maxPoint, arr[0][task]);
        }
        return maxPoint;
    }
    if(dpArr[day][lastTask] != -1)  return dpArr[day][lastTask];
    int maxPoint = 0;
    for(int task=0;task<3;task++){
        if(task != lastTask){
            int point = arr[day][task] + ninjaTrainingPOINTS_Mamoization(arr, task, day-1, dpArr);
            maxPoint = max(maxPoint, point);
        }
    }
    return dpArr[day][lastTask] = maxPoint;    
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity :  O(N * 4 * 3)
// Space Complexity : O(N * 4)
// ------------------------------------
int ninjaTrainingPOINTS_Tabulation(vector<vector<int>> &arr, int n){
    vector<vector<int>> dpArr(n, vector<int> (4,0));

    dpArr[0][0] = max(arr[0][1], arr[0][2]);
    dpArr[0][1] = max(arr[0][0], arr[0][2]);
    dpArr[0][2] = max(arr[0][0], arr[0][1]);
    dpArr[0][3] = max(arr[0][1], max(arr[0][1], arr[0][2]) );
    
    for(int day=1;day<n;day++){
        for(int lastTask=0; lastTask<4; lastTask++){
            dpArr[day][lastTask] = 0;

            for(int task=0;task<3;task++){
                if(task != lastTask){
                    int point = arr[day][task] + dpArr[day-1][task];
                    dpArr[day][lastTask] = max(dpArr[day][lastTask], point);
                }
            }
        }
    }
    return dpArr[n-1][3];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(N * 4 * 3)
// Space Complexity : O(4)
// ------------------------------------
int ninjaTrainingPOINTS_TabulationOPTM(vector<vector<int>> &arr, int n){
    vector<int> prev(4,0);

    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max(arr[0][1], max(arr[0][1], arr[0][2]) );
    
    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int lastTask=0; lastTask<4; lastTask++){
            temp[lastTask] = 0;

            for(int task=0;task<3;task++){
                if(task != lastTask){
                   temp[lastTask] = max(temp[lastTask], arr[day][task] + prev[task]);
                }
            }
        }
        prev= temp;
    }
    return prev[3];
}
// __________________________________________________________________________________

int main()
{
    int data, days;
    cout<<"Days : ";
    cin>>days;
    vector<int> task;
    vector<vector<int>> arr;
    vector<vector<int>> dpArr(days, vector<int>(4, -1));

    for(int i=0;i<days;i++){
        task.clear();
        for(int j=0;j<3;j++){
            cin>>data;
            task.emplace_back(data);
        }
        arr.emplace_back(task);
    }
    cout<<"----------------------"<<endl;
    for(int i=0;i<days;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------"<<endl;

    int pointsRecursion = ninjaTrainingPOINTS_Recusion(arr, 3, days-1);
    cout<<"Points using Reccursion: "<<pointsRecursion<<endl;

    int pointsDP_Mamoization = ninjaTrainingPOINTS_Mamoization(arr, 3, days-1, dpArr);
    cout<<"Points using DP Mamoization: "<<pointsDP_Mamoization<<endl;

    int pointsDP_Tabulation = ninjaTrainingPOINTS_Tabulation(arr, days);
    cout<<"Points using DP Tabulation: "<<pointsDP_Tabulation<<endl;
    
    int pointsDP_TabulationOPTM = ninjaTrainingPOINTS_TabulationOPTM(arr, days);
    cout<<"Points using DP Tabulation: "<<pointsDP_TabulationOPTM<<endl;

    return 0;
}