#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Size : 5
// Array :  4   3  7   1   2
//         p1  p2  p3  p4  p5
// ----------------------------------------------
// Shortest Job First : 4
//     p4   -->    0        // p4 start at time 0
//     p5   -->    1        // p5 start at time 1  
//     p2   -->    3        // p2 start at time 3 -->  3 (p5 take 2 sec and 1 sec waitTIme)
//     p1   -->    6        // p1 start at time 6 -->  6 (p2 take 3 sec and 3 sec waitTIme)
//     p3   -->    10       // p3 start at time 10 --> 10(p1 take 4 sec and 6 sec waitTIme)
//        Total -->> 20 / 5 = 4
// ----------------------------------------------

// _______________________________________________________________________________________
// Time Complexity : O(n*log(n))       -->> O(n) for iterating + Sort n*log(n)
// Space Complexity : O(1) 
// --------------------------------------------------------------
int shortestJobFirst(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    int time = 0, waitTime = 0;
    for(int i=0;i<n;i++){
        waitTime += time;
        time += arr[i];
    }
    return (waitTime / n);
}

int main()
{
    int n, data;
    vector<int> arr;
    cout<<"Size : ";
    cin>>n;
    cout<<"Array : ";
    for(int i=0;i<n;i++){
        cin>>data;
        arr.push_back(data);
    }

    int sjf = shortestJobFirst(arr, n);
    cout<<"Shortest Job First : "<<sjf<<endl;

    return 0;
}