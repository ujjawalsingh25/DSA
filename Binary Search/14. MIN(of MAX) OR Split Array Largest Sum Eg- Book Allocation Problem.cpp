#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

// 5   4
// 25 46 28 49 24   :  71  

int count_student(vector<int> &arr, int mid_as_pages){
    int n=arr.size();
    int student = 1, pages = 0;
    for(int i=0; i<n;i++){
        if(pages + arr[i] <= mid_as_pages)      // pages + arr[i]
            pages += arr[i];
        else{
            student++;
            pages = arr[i];
        }
    } 
    return student;
}

int min_of_max_pages(vector<int> &arr, int students){
    int n= arr.size() , count =0, mid;
    int low = *max_element(arr.begin(), arr.end());             // Under #include<algorithm>  -- for max element
    int high = accumulate(arr.begin(), arr.end(), 0);           // Under #include <numeric>   -- for sum of all element.
    if (students > n) return -1;
    while(low<=high){
    for(int i=0; i<n;i++){
        mid = low + (high - low)/2;
       count = count_student(arr,mid);
       if(count > students)
            low = mid+1;
        else
            high = mid-1;
        }    
    }
    return low;
}

int main()
{
    vector <int> v;
    int data, n, students;
    cout<<"Size: ";
    cin>>n;
    cout<<"Students: ";
    cin>>students;
    cout<<"Data :";
    for(int i=0;i<n;i++){
        cin>>data;
        v.push_back(data);
    }
    int pages = min_of_max_pages(v, students);
    cout<<"Min of maximum Pages to distribute: "<<pages<<endl;
    // int check = count_student(v, student);
    // cout<<check;

  return 0;    
}