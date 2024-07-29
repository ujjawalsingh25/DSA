#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct jobs {
    int day;
    int deadline;
    int profit;
};          // struct require a semi-colon *******

bool compare(jobs a, jobs b){
    return a.profit > b.profit;     // since jobs contains 3 data so specifying to sort w.r.t 'profit
}

// Size : 8
// Day: 1 2 3 4 5 6 7 8
// Deadline : 4 5 6 6 4 2 2 2
// Profit : 20 60 70 65 25 80 10 22
// -------------------------------------------------------------------------------
// -------- After Sorted ---------------------
// 6 -- 2 -- 80
// 3 -- 6 -- 70
// 4 -- 6 -- 65
// 2 -- 5 -- 60
// 5 -- 4 -- 25
// 8 -- 2 -- 22
// 1 -- 4 -- 20
// 7 -- 2 -- 10
// Maximum Profit Gain on Completing jobs within deadline : 322
// -------------------------------------------
//  __________________________________
// | 0  | 1  | 2  | 3  | 4  | 5  | 6  |        -->> Index 0 to 6
// |____|____|____|____|____|____|____|
// |  ⬇ |  ⬇ |  ⬇ |  ⬇ |  ⬇ | ⬇  | ⬇  |
// |  1 |  8 |  6 |  5 |  2 | 4  | 3  |        -->> Profit alloted according to days
// |  ⬇ |  ⬇ |  ⬇ |  ⬇ |  ⬇ | ⬇  | ⬇  |        -->>    (day 6 can only be done within day 2 so assign index 2 and added profit)
// | 20 | 22 | 70 | 25 | 60 | 65 | 70 | -->> Total Profit = 322
// |____|____|____|____|____|____|____|        
//   Profit(day) = 80(6) + 70(3) + 65(4) + 60(2) + 25(5) + 22(8) + 20(1) 
//   countProfit = 80 + 150 + 215 + 275 + 300 + 322 
// -------------------------------------------------------------------------------


int maxProfit_onCompletingWithinDeadline(vector<jobs> arr, int n, int maxDay) {
    unordered_map<int, int> hashMap;
    sort(arr.begin(), arr.end(), compare);   // since arr contains 3 data so specifying to sort w.r.t 'profit using 'COMPARE function'
    int totalProfit = 0, count = 0;
    for(int i=0;i<maxDay;i++){
        hashMap[i] = -1;
    }
    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline; j>0;j--){
            if(hashMap[j] == -1) {
                hashMap[j] = arr[i].day;
                totalProfit += arr[i].profit;
                count++;
                break;
            }
        }        
    }
    return totalProfit;
}


int main()
{
    int n, data, maxDay;
    cout<<"Size: ";
    cin>>n;
    cout<<"Maximum Day to work: ";
    cin>>maxDay;

    vector<int> dayArr(n), deadlineArr(n), profitArr(n);
    vector<jobs> arr(n);

    cout<<"Day: ";
    for(int i=0;i<n;i++){
        cin>>dayArr[i];
        arr[i].day = dayArr[i];
    }
    cout<<"Deadline: ";
    for(int i=0;i<n;i++){
        cin>>deadlineArr[i];
        arr[i].deadline = deadlineArr[i];
    }
    cout<<"Profit: ";
    for(int i=0;i<n;i++){
        cin>>profitArr[i];
        arr[i].profit = profitArr[i];
    }

    cout<<"------ Input ------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i].day<<" -- "<<arr[i].deadline<<" -- "<<arr[i].profit<<endl;
    }cout<<endl;

    cout<<"-------- After Sorted --------"<<endl;
    sort(arr.begin(), arr.end(), compare);   // since arr contains 3 data so specifying to sort w.r.t 'profit using 'COMPARE function'
    for(int i=0;i<n;i++){
        cout<<arr[i].day<<" -- "<<arr[i].deadline<<" -- "<<arr[i].profit<<endl;
    }
    cout<<"_______________________"<<endl;

    int maxProfit = maxProfit_onCompletingWithinDeadline(arr, n, maxDay);
    cout<<"Maximum Profit Gain on Completing jobs within deadline : "<<maxProfit<<endl;

    return 0;
}