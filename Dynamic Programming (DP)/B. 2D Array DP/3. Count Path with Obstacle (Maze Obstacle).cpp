#include<iostream>
#include<string>
#include<vector>
using namespace std;


// -----------------------------------------
// Grid (n) : 3
// Grid (m) : 3
// Data : 0 0 0 0 -1 0 0 0 0
// -----------------
// 0 0 0
// 0 -1 0
// 0 0 0
// Unique MAZEpaths using Recursion: 2
// Unique MAZEpaths using Mamoization: 2
// Unique paths using Tabulation: 2
// Unique paths using TabulationOPTM: 2
// // -----------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O( 2^(m*n) )
// Space Complexity : O((n-1)+(m-1)) (Path-Length)
// -----------------------------------------------------
int countPath_MAZE_Recursion(vector<vector<int>> &arr, int i, int j){
    if(i>=0 && j>=0 && arr[i][j] == -1)    return 0;         // Obsticle -> path not possible
    if(i==0 && j==0)    return 1;       // Starting from last since reached start(0). So there is 1 path. -->> return 1,
    if(i<0 || j<0)     return 0;         // No path possible

    int upperPath = countPath_MAZE_Recursion(arr, i-1, j);
    int leftPath = countPath_MAZE_Recursion(arr, i, j-1);
    return upperPath + leftPath;
}
// _______________________________________________________________________________________

// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*m)
// Space Complexity : O((n-1)+(m-1)) + O(n*m)   (Path Length + DpArr)
// ------------------------------------
int countPath_MAZE_Mamoization(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dpArr){
    if(i>=0 && j>=0 && arr[i][j] == -1)    return 0;      // Obsticle -> path not possible
    if(i==0 && j==0)    return 1;      // Starting from last since reached start(0). So there is 1 path. -->> return 1,
    if(i<0 || j<0)     return 0;       // No path possible
    if(dpArr[i][j] != -1)   return dpArr[i][j];

    int upperPath = countPath_MAZE_Mamoization(arr, i-1, j, dpArr);
    int leftPath = countPath_MAZE_Mamoization(arr, i, j-1, dpArr);
    return dpArr[i][j] = (upperPath + leftPath);
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
// ------------------------------------
int countPath_MAZE_Tabulation(vector<vector<int>> &arr, int n, int m){
    int dpArr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == -1)     dpArr[i][j] = 0;
            else if(i==0 && j==0)  dpArr[i][j] = 1;   // Starting from last since reached start(0). So there is 1 path. -->> return 1,
            else{
                int upperPath = 0, leftPath = 0;
                if(i>0)   upperPath = dpArr[i-1][j];
                if(j>0)   leftPath = dpArr[i][j-1];
                dpArr[i][j] = upperPath + leftPath;
            }
        }
    }
    return dpArr[n-1][m-1];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(N * 4 * 3)
// Space Complexity : O(4)
// ------------------------------------
int countPath_MAZE_TabulationOPTM(vector<vector<int>> &arr, int n, int m){
    vector<int> prev(n, 0);      // tempUpper above zero-row to get the storePrev of upperPath of row-zero
    for(int i=0;i<n;i++){
        vector<int> current(m, 0);      // current to get the prev m-1 index value in same row.
        for(int j=0;j<m;j++){
            if(arr[i][j] == -1)     current[j] = 0;
            else if(i==0 && j==0)  current[j] = 1;   // Starting from last since reached start(0). So there is 1 path. -->> return 1,
            else{
                int upperPath = 0, leftPath = 0;
                if(i>0)   upperPath = prev[j];
                if(j>0)   leftPath = current[j-1];
                current[j] = upperPath + leftPath;
            }
        }
        prev = current;
    }
    return prev[m-1];
}
// __________________________________________________________________________________

int main()
{
    int n, m, data;
    cout<<"Grid (n) : ";
    cin>>n;
    cout<<"Grid (m) : ";
    cin>>m;
    cout<<"Data : ";

    vector<int> row;
    vector<vector<int>> arr;
    vector<vector<int>> dpArr(n, vector<int>(m, -1));

    for(int i=0;i<n;i++){
        row.clear();
        for(int j=0;j<m;j++){
            cin>>data;
            row.emplace_back(data);
        }
        arr.push_back(row);
    }
    cout<<"-----------------"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int mazePathRecursion = countPath_MAZE_Recursion(arr, n-1, m-1);        // n-1, m-1 because indexing is taken as (0 -> n-1)
    cout<<"Unique paths using Recursion: "<<mazePathRecursion<< endl;

    int mazePathMamoization = countPath_MAZE_Mamoization(arr, n-1, m-1, dpArr);
    cout<<"Unique paths using Mamoization: "<<mazePathMamoization<< endl;

    int mazePathTabulation = countPath_MAZE_Tabulation(arr, n, m);
    cout<<"Unique paths using Tabulation: "<<mazePathTabulation<< endl;

    int mazePathTabulationOPTM = countPath_MAZE_TabulationOPTM(arr, n, m);
    cout<<"Unique paths using TabulationOPTM: "<<mazePathTabulationOPTM<< endl;
    
    return 0;
}