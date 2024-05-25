// #include<iostream>
// using namespace std;

// int main()
// {
//     int n, num,t;
//     cout<<"Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     // int max_array;
//     int hash[13]={0};       // initialize to 0.
//     for(int i=0;i<n;i++){
//         hash[arr[i]] = hash[arr[i]] + 1;
//     }
//     cout<<"Test Case: ";
//     cin>>t;
//     while(t--){
//         cin>>num;
//         cout<<hash[num]<<endl;
//     }   

//   return 0;
// }


// ----------------- Int return function
#include<iostream>
using namespace std;

Size: 5
2 4 2 5 2
Test Cases: 2
Enter number to search: 2
3
Enter number to search: 5 
1

int hashing(int arr[], int n, int num) {
    int hash[13] = {0}; // initialize to 0.
    for (int i = 0; i < n; i++) {
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    return hash[num];
}

int main() {
    int n, num, t;
    cout << "Size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Test Cases: ";
    cin >> t;
    while (t--) {
        cout << "Enter number to search: ";
        cin >> num;
        int h = hashing(arr, n, num);
        cout << h << endl;
    }

    return 0;
}

// -----------------------------Void return function
// #include<iostream>
// using namespace std;

// void hashing(int arr[], int n, int hash_arr[]){ 
//     for(int i=0;i<n;i++){
//         hash_arr[arr[i]] = hash_arr[arr[i]] + 1;
//     }
// }

// int main()
// {
//     int n, num,t;
//     cout<<"Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int hash_arr[13]={0};           // initialize to 0.
//     hashing(arr, n, hash_arr);
//     cout<<"Test Case: ";
//     cin>>t;
//     while(t--){
//         cout << "Enter number to search: ";
//         cin>>num;
//         cout<<hash_arr[num]<<endl;
//     }   

//   return 0;
// }