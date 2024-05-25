// We need a find minimum number such that if we divide that number with the array
//  then the sum of all ceil values should not exceed threshold target. 

// Size: 4
// Max_Value: 7
// 1 2 5 9
// Output: 3

//  Here any number <= 9 give the sum or max_value 4 which is less than 7 but minimum number is 3 to which if we divide
// the value will be 7. 
// For 2 -> 1+1+3+5 = 10 which is greater than 7 
// For 4 -> 1+1+2+3 = 7 here 4 can be number but check further. 
// For 3 -> 1+1+2+3 = 7 here 3 is the number as minimum to get the max value.
 
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

double divide(vector<int> &arr, double d){
    double div = 0.0, n = arr.size();             // *** Initialize div always with 0.0 ***
    for(int i=0; i<n;i++){
    div += ceil((arr[i]) / d);
    // cout<<div<<" ";
    }
    return div;
}

int minimum_divisor(vector<int> &arr, int n, int target_val){
    int value, mid, low = 0, high =n-1;
    while(low <= high){
        mid = low + (high - low)/2;
        value = divide(arr, mid);
        if(value <= target_val){
            high = mid-1;
        }
        else
            low = mid+1;
    } 
    return mid;
}

int main()
{
    vector<int> v;
    int n,data, max_value;
    cout<<"Size: ";
    cin>>n;
    cout<<"Max_Value: ";
    cin>>max_value;
    for(int i=0;i<n;i++){
        cin>>data;
        v.push_back(data);
    }
    int min_d = minimum_divisor(v, n, max_value);
    cout<<min_d<<endl;

    return 0;
}