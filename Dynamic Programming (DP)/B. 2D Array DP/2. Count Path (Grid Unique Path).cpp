#include<iostream>
#include<string>
#include<vector>
using namespace std;


// -----------------------------------------
// Grid Size (n): 3
// Grid Size (m): 7
// Number of unique paths: 28
// _________________________________
// Grid Size (n): 2
// Grid Size (m): 3
// ---------------------------
// []  ➔  ⬇     |    []  __   __     |  [] ➔   __ 
// __  __  []    |    ⬇   ➔   []     |  __ ⬇➔  []
// Number of unique paths: 3
// -----------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O( 2^(m*n) )
// Space Complexity : O((n-1)+(m-1)) (Path-Length)
// -----------------------------------------------------
int countUniquePath_Recursion(int n, int m){
    if(n==0 && m==0)  return 1;         // Starting from last since reached start(0). So there is 1 path. -->> return 1,
    if(n < 0 || m < 0)  return 0;         // No path possible
    int upperPath = countUniquePath_Recursion(n-1, m);
    int leftPath = countUniquePath_Recursion(n, m-1);
    return upperPath + leftPath;
}
// _______________________________________________________________________________________

// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*m)
// Space Complexity : O((n-1)+(m-1)) + O(n*m)   (Path Length + DpArr)
// ------------------------------------
int countUniquePath_Mamoization(int n, int m, vector<vector<int>> &dpArr){
    if(n==0 && m==0)  return 1;         // Starting from last since reached start(0). So there is 1 path. -->> return 1,
    if(n < 0 || m < 0)  return 0;       // No path possible
    if(dpArr[n][m] != -1)   return dpArr[n][m];
    int upperPath = countUniquePath_Mamoization(n-1, m, dpArr);
    int leftPath = countUniquePath_Mamoization(n, m-1, dpArr);
    return dpArr[n][m] = upperPath + leftPath;
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
// ------------------------------------
int countUniquePath_Tabulation(int n, int m){
    int dpArr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)  dpArr[i][j] = 1;   // Starting from last since reached start(0). So there is 1 path. -->> return 1,
            else{
                int upperPath = 0;
                int leftPath = 0;
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
int countUniquePath_TabulationOPTM(int n, int m){
    vector<int> prev(n, 0);      // tempUpper above zero-row to get the storePrev of upperPath of row-zero
    for(int i=0;i<n;i++){
        vector<int> curr(m, 0);      // curr to get the prev m-1 index value in same row.
        for(int j=0;j<m;j++){
            if(i==0 && j==0)  curr[j] = 1;
            else{
                int upperPath = 0;
                int leftPath = 0;
                if(i>0)   upperPath = prev[j];
                if(j>0)   leftPath = curr[j-1];
                curr[j] = upperPath + leftPath;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}
// __________________________________________________________________________________

int main()
{
    int n, m;
    cout<<"Grid Size (n): ";
    cin>>n;
    cout<<"Grid Size (m): ";
    cin>>m;

    vector<vector<int>> dpArr(n, vector<int>(m, -1));

    cout<<"----------------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"[]"<<" ";
        }
        cout<<endl;
    }

    int uniquePathRecursion = countUniquePath_Recursion(n-1, m-1);      // n-1, m-1 because indexing is taken as (0 -> n-1)
    cout<<"Unique paths using Recursion: "<<uniquePathRecursion<< endl;

    int uniquePathMamoization = countUniquePath_Mamoization(n-1, m-1, dpArr);
    cout<<"Unique paths using Mamoization: "<<uniquePathMamoization<< endl;

    int uniquePathTabulation = countUniquePath_Tabulation(n, m);
    cout<<"Unique paths using Tabulation: "<<uniquePathTabulation<< endl;

    int uniquePathTabulationOPTM = countUniquePath_TabulationOPTM(n, m);
    cout<<"Unique paths using TabulationOPTM: "<<uniquePathTabulationOPTM<< endl;


    return 0;
}