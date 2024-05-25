#include<bits/stdc++.h>
#include<vector>
using namespace std;

Size n1 & n2: 6 4
Array1 : 2 3 4 5 8 2
Array2 : 1 2 3 4

int remmoveFor_DistinctNumber(vector<int>&arr1, vector<int>&arr2, int n, int m){
    unordered_map <int, int> mppA, mppB;
    int countDigit = 0;
    
    for(int i=0;i<n;i++){
        mppA[arr1[i]] +=1;      // get the freq of arr1 data in the hashmap
    }
    for(int i=0;i<m;i++){
        mppB[arr2[i]] +=1;      // get the freq of arr2 data in the hashmap.
    }

    for(auto iter: mppA){
        if(mppB.find(iter.first) != mppB.end()){
            countDigit += min(iter.second , mppB[iter.first]);      // min of the arr1 (data->freq) or the arr2 (data) should be remove to get the digit count to remove. As digit will be removed fromn both array to get distinct so if arr1 have 2 same digit with arr2 has 1 digit in common then min of digits will be remove (in eg. digit '2' from both will be removed and the rest second digit will become distinct.)
        }
    }

    return countDigit;
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


    int ans = remmoveFor_DistinctNumber(arr1, arr2, n1, n2);
    cout<<"Digit to remove to get distinct number in array: "<< ans <<endl;

    return 0;
}