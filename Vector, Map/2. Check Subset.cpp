#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Size n1 & n2: 5 3
// Array1 : 1 3 5 7 8
// Array2 : 3 4 8
// 8 -> 1
// 7 -> 1
// 5 -> 1
// 3 -> 1
// 1 -> 1
// 4 No

bool checkSubset(vector<int>&arr1, vector<int>&arr2, int n, int m){
    unordered_map <int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr1[i]] += 1;
    }

    for(auto iter = mpp.begin(); iter != mpp.end(); iter++){
        cout<<iter->first<<" -> "<<iter->second<<endl;
    }

    for(int i=0;i<m;i++){
        if(mpp.find(arr2[i]) == mpp.end()) {    //if the element is not found before the end of the map
       
        // if(mpp.find(arr2[i]) != mpp.end()) {    //if the element is found before the end of the map
       
            cout<<arr2[i]<<" ";
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr1, arr2;
    int n1, n2, data1, data2;
    cout<<"Size n1 & n2: ";
    cin>>n1 >> n2;
    cout<<"Array1 : ";
    for(int i=0;i<n1;i++){
        cin>> data1;
        arr1.emplace_back(data1);
    }
    cout<<"Array2 : ";
    for(int i=0;i<n2;i++){
        cin>> data2;
        arr2.emplace_back(data2);
    }

    if (checkSubset(arr1, arr2, n1, n2))  cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}