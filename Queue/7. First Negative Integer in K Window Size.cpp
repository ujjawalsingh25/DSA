#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// Size: 5
// Window Size: 2 
// -8 2 3 -6 10
// -8 0 -6 -6

vector<long long> printFirstNegativeInteger( vector<long long int> &arr, long long int n, long long int k) {
    deque<long long int> dqe;
    vector<long long> ans;

// To get the FIRST NEGATIVE INTEGER in first k size window
    for(int i=0;i<k;i++){
        if(arr[i] < 0)  dqe.push_back(i);
    }

// Store the answer of first k sized data
    if(dqe.size() > 0)  ans.emplace_back(arr[dqe.front()]);
    else    ans.emplace_back(0);

// Process the remaining windows
    for(int i=k;i<n;i++){

        //Removal of prev data from the window
        if(!dqe.empty() && i - dqe.front() >= k)    dqe.pop_front();

        // getting the FIRST NEGATIVE INTEGER from this new window.
        if(arr[i] < 0)  dqe.push_back(i);


        //Store the FIRST NEGATIVE INTEGER of new window
        if(dqe.size() > 0)  ans.emplace_back(arr[dqe.front()]);
        else    ans.emplace_back(0);
    }

  return ans;    
 }

int main()
{
    long long int n, data, k;
    vector<long long int> arr, ans;
    cout<<"Size: ";
    cin>>n;
    cout<<"Window Size: ";
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>data;
        arr.push_back(data);
    }

    ans = printFirstNegativeInteger(arr, n, k);
    for(auto iter = ans.begin(); iter != ans.end(); iter++){
        cout<<*(iter)<<" ";
    }
    
  return 0;
}