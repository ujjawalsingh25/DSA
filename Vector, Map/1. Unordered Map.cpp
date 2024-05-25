#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Size: 3
// a 1
// b 2
// c 3
// c -> 3
// b -> 2
// a -> 1

void display(vector<char> &key , vector<int> &value, int n){
    unordered_map <char, int> mpp;
    for(int i=0;i<n;i++){
        mpp[key[i]] = value[i];
    }

    for(auto iter = mpp.begin(); iter != mpp.end(); iter++){
        cout<<iter->first<<" -> "<<iter->second<<endl;
    }
}

int main()
{
    int value, n;
    vector<int> arr;
    vector<char> ch;
    char key;

    cout<<"Size: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>> key >> value;
        ch.push_back(key);
        arr.push_back(value);
    }
    
    display(ch, arr, n);

    return 0;
}