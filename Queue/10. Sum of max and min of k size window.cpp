#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

// Size: 7
// Window Size: 4
// Data: 2 5 -1 7 -3 -1 -2
// 18

int Max_Min_SUM(vector<int> &arr, int window){
    deque<int> maxQuu(window), minQuu(window);
    int ans = 0, n=arr.size();

  // First k size window added
    for(int i=0;i<window;i++){
        while(!maxQuu.empty() && arr[maxQuu.back()] <= arr[i]){
            maxQuu.pop_back();
        }
        while(!minQuu.empty() && arr[minQuu.back()] >= arr[i]){
            minQuu.pop_back();
        }
        maxQuu.push_back(i);
        minQuu.push_back(i);
    }

    for(int i=window; i<n; i++){

        ans += arr[maxQuu.front()] + arr[minQuu.front()];
 // Traverse to next window
    //removal of front element
        while(!maxQuu.empty() && i - maxQuu.front() >= window){
            maxQuu.pop_front();
        }
        while(!minQuu.empty() && i - minQuu.front() >= window){
            minQuu.pop_front();
        }
    //addition of new element at back for k size window
        while(!maxQuu.empty() && arr[maxQuu.back()] <= arr[i]){
            maxQuu.pop_back();
        } maxQuu.push_back(i);
        while(!minQuu.empty() && arr[minQuu.back()] >= arr[i]){
            minQuu.pop_back();
        } minQuu.push_back(i);

    }

    ans += arr[maxQuu.front()] + arr[minQuu.front()];
    return ans;

}

int main()
{
    int n, data, window;
    vector<int> arr;
    cout<<"Size: ";
    cin>>n;
    cout<<"Window Size: ";
    cin>>window;
    cout<<"Data: ";
    for(int i=0;i<n;i++){
        cin>>data;
        arr.push_back(data);
    }
    int ans = Max_Min_SUM(arr, window);
    cout<<ans<<endl;
    
  return 0;
}