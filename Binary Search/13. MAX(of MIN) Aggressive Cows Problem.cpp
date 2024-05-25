#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 6 4 
// 0 3 4 7 10 9   :  3

// 5 2
// 4 2 1 3 6    : 5
// 1 2 3 4 6 

bool count_placed_cows(vector<int> &arr, int mid_as_dist, int cows) {
    int n = arr.size(), distance_between_cows = 0 ;
    int cow_count = 1, position = arr[0];
    for(int i=1; i<n; i++){
        distance_between_cows = arr[i] - position;
        if(distance_between_cows >= mid_as_dist){
            cow_count++;
            position = arr[i];
        }
        if (cow_count >= cows) return true;
    } 
    return false;
}


int max_of_min_distance_between_cows(vector<int> &arr, int cows){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int mid, value, low = 1 , high = arr[n-1];
    while(low<=high){
        mid = low + (high - low)/2;
        if(count_placed_cows(arr,mid,cows) == true)
            low = mid + 1;
        else
            high = mid-1;
    }
    return high;
}

int main()
{
    vector<int> v;
    int data, size, n, cows;
    cout<<"Size: ";
    cin>>n;
    cout<<"Cows: ";
    cin>>cows;
    cout<<"Data : ";
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }
    int distance = max_of_min_distance_between_cows(v, cows);
    cout<<"Distance: "<<distance;

  return 0;
}




//----------------------------------------------Practice----------------
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// // 6 4 
// // 0 3 4 7 10 9   :  3

// int count_placed_cows(vector<int> &arr, int mid_as_dist) {
//     int n = arr.size(), distance_between_cows = 0 ;
//     int cow_count = 1, position = arr[0];
//     for(int i=1; i<n; i++){
//         distance_between_cows = arr[i] - position;
//         if(distance_between_cows >= mid_as_dist){
//             cow_count++;
//             position = arr[i];
//         }
//     } 
//     return cow_count;
// }

// int max_of_min_distance_between_cows(vector<int> &arr, int cows){
//     sort(arr.begin(), arr.end());
//     int n = arr.size();
//     int mid, value, low = 1 , high = arr[n-1];
//     while(low<=high){
//         mid = low + (high - low)/2;
//         value = count_placed_cows(arr,mid);
//         if(cows > value)
//             low = mid + 1;
//         else
//             high = mid-1;
//     }
//     return low;
// }

// int main()
// {
//     vector<int> v;
//     int data, size, n, cows;
//     cout<<"Size: ";
//     cin>>n;
//     cout<<"Cows: ";
//     cin>>cows;
//     cout<<"Data : ";
//     for(int i=0; i<n; i++){
//         cin>>data;
//         v.push_back(data);
//     }
//     int distance = max_of_min_distance_between_cows(v, cows);
//     cout<<"Distance: "<<distance;
//     // int check = count_placed_cows(v , cows);
//     // cout<<check;
//     return 0;
// }