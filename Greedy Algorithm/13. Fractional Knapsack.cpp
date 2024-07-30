#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct items {
    int value, weight;
};
bool comparator(items a, items b) {
    if( (a.value/a.weight) >= (b.value/b.weight) )   return true;
    else  return false;
}

// ----------------------------------------------------------------------------------------
//            Size: 4
//  Maximum Weight: 90
//           Value: 100 60 100 200
//          Weight: 20 10 50 50
// ---------------------------------------------------
// 
// -------- After Sorted --------
//   Value --  Weight
//     60  --   10
//    100  --   20
//    200  --   50
//    100  --   50
// ------------------------------------
//   Fractional Knapsack: 380
// ----------------------------------------------------
//   [ (60, 10) , (100, 20) , (200, 50) , (100, 50) ]  
//                                       (100, 50) --> (100/50) * 10(current->maxWeight) 
//   totalValue =  0 -> 60 -> 160 -> 360 -> 380 { (100/50) * 10(current->maxWeight) }
//   maxWeight =  90 -> 80 ->  60 ->  10 -> 10
// ---------------------------------------------------------------------------------------


// _____________________________________________________________________________________________
//  Time Complexity :  O(n + n*log(n) )      -->  n*log(n) for sort and (n) for loop
//  Space Complexity:  O(1) 
// -----------------------------------------------------
double fractionalKnapsack(vector<items> &arr, int maxWeight, int n) {
    sort(arr.begin(), arr.end(), comparator); // since arr contains 3 data so specifying to sort w.r.t 'profit using 'COMPARE function'
    double totalValue = 0;
    for(int i=0;i<n;i++) {
        if(arr[i].weight <= maxWeight) {
            totalValue += arr[i].value;
            maxWeight = maxWeight - arr[i].weight;
        } else {
            totalValue += (arr[i].value / arr[i].weight) * maxWeight;
            break;
        }
    }
    return totalValue;
}
// _____________________________________________________________________________________________


int main()
{
    int n, maxWeight;
    cout<<"Size: ";
    cin>>n;
    cout<<"Maximum Weight: ";
    cin>>maxWeight;
    vector<int> valueArr(n), weightArr(n);
    vector<items> arr(n);

    cout<<"Value: ";
    for(int i=0;i<n;i++) {
        cin>>valueArr[i];
        arr[i].value = valueArr[i];
    }

    cout<<"Weight: ";
    for(int i=0;i<n;i++) {
        cin>>weightArr[i];
        arr[i].weight = weightArr[i];
    }
    // cout<<"------ Input ------"<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].value<<" -- "<<arr[i].weight<<endl;
    // }cout<<endl;

    cout<<"-------- After Sorted --------"<<endl;
    cout<<"Value"<<" -- "<<"Weight"<<endl;
    sort(arr.begin(), arr.end(), comparator);// since arr contains 3 data so specifying to sort w.r.t 'profit using 'COMPARE function'
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i].value<<"  --   "<<arr[i].weight<<endl;
    }
    cout<<"_______________________"<<endl;

    double maxValueTaken = fractionalKnapsack(arr, maxWeight, n);
    cout<<"Fractional Knapsack: "<<maxValueTaken<<endl;

    return 0;
}