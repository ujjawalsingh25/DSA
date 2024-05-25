// Map Hash
// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;
// int main()
// {
    
//     map < vector <int>, int> mp;
//     vector<int> v = {1};
//     cout<<mp[v];             // output --> 0 
//   return 0;
// }

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

// 2 3 5 6 1
// Test Cases: 2
// Enter number to search: 3
// 1
// Enter number to search: 4
// 0

int main()
{
    int n, t, num;
    map <int, int> mp;
    cout<<"Size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
        mp[arr[i]] += 1;
    }
    
    cout << "Test Cases: ";
    cin >> t;
    while (t--) {
        cout << "Enter number to search: ";
        cin >> num;
        cout<<mp[num]<<endl;;
    }
  return 0;
}


