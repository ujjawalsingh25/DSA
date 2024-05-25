// Lower Bound
// arr[index] >= n

// Upper Bound
// arr[index] > n

// Differnce b/w both bounds are lower bound gives the index number of number having value greater than target or same as target if exist.
//                      but in upper bound it awalys gives the index number of number having value greater than target
// Eg.  arr [] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8}
//          So, Upper_bound for '4' = '5' at index 7 
//          So, Lower_bound for '4' = '4' at index 4(first one)

// -------------------------------------------------------------------------------------------------------------------------------


// Iterative Lower Bound

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int lower_bound(vector<int> &arr, int target){
    int ans, n=arr.size(), mid;
    int low=0; int high = n-1;
    
    while(low<=high){
        mid = low + (high - low)/2;        
        if(arr[mid] >= target){                 // for upper_bound, if(arr[mid] > target) 
            ans = mid;                          // '>=' will be set to '>' only
            high = mid -1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> v;
    int n,data, target , result;
    cin>>n>>target;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }

    result = lower_bound(v, target);
    cout<<"\n"<<result+1<<endl;

    cout<<"----When need to access directly without the whole code"<<endl;
    cout<<"----------lower_bound(arr.begin(), arr.end(), target"<<endl;
    cout<<"------------ Under # include<algorithm> ----------------"<<endl;

    auto answer = lower_bound(v.begin(), v.end(), target);
    cout<< (answer - v.begin() ) + 1;


    return 0;
}

// -------------------------------------------------------------------------------------------------------------------------------


/*

int main()
{
     cout<<"----When need to access directly without the whole code\n
                ----------lower_bound(arr.begin(), arr.end(), target\n
        ------------ Under # include<algorithm> ----------------)"<<endl;

    vector<int> v;
    int n, data, target;
    cin>>n;
    cin>>target;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }

    auto result = lower_bound(v.begin(), v.end(), target);
    cout<< (result - v.begin() ) + 1;

    return 0;
}

*/

// -------------------------------------------------------------------------------------------------------------------------------

/*

// Recursive Lower Bound

#include<iostream>
#include<vector>
using namespace std;

int lower_bound(vector<int> &arr, int low, int high, int target){
   // int ans, n=arr.size();
    if(low <= high){
        
        int mid = low + (high - low)/2;
        if(arr[mid] >= target){                                      // for upper_bound, if(arr[mid] > target) 
         return lower_bound(arr, low, mid - 1, target);             // '>=' will be set to '>' only
        }
        else
             return lower_bound(arr, mid + 1, high, target);
    }
    return low;                    // Return the position (lowest so 'low') for lower bound of targeted data.
}

int main()
{
    vector<int> v;
    int n = v.size();
    int data, target , result;
    cin>>n>>target;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }

    result = lower_bound(v, 0, v.size() - 1, target);       // Size = n-1
    cout<<result+1<<endl;

    return 0;
}

*/