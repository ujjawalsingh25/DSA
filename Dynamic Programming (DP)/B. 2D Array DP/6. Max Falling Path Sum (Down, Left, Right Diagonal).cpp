#include<iostream>
#include<vector>
using namespace std;

// Size (n): 4
// Size (m): 4
// ----------------------
// 1 2 10 4 25 3 2 1 1 1 20 3 1 4 5 2  
// 1  2   10  4
//      ⬋
// 25  3  2  1 
//      ↘ 
// 1  1  20  3
//       ⬇
// 1  4  5  2
// -------------------------------------
// Travesing from top to bottom with move(↘⬇⬋) -->> 38
// --------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(3^n)     // for each node we explore 3 nodes.
// Space Complexity : O(n) 
// -----------------------------------------------------
int getMaxPathSum_Recursion(vector<vector<int>> &arr, int i, int j){
    if(j<0 || j>=arr[0].size())   return INT_MIN;
    if(i == 0)     return arr[0][j];     

    int upperPath = arr[i][j] + getMaxPathSum_Recursion(arr, i-1, j);
    int leftDiagonal = arr[i][j] + getMaxPathSum_Recursion(arr, i-1, j-1);
    int rightDiagonal = arr[i][j] + getMaxPathSum_Recursion(arr, i-1, j+1);
    return max(upperPath, max(leftDiagonal, rightDiagonal));
}

int maxFalling_PathSum_Recursion(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    int maxi = INT_MIN;
    for(int j=0;j<m;j++){
        maxi = max(maxi, getMaxPathSum_Recursion(arr, n-1, j));
    }
    return maxi;
}
// _______________________________________________________________________________________

// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(n)   (Matrix + RecursionStackSpace)
// ------------------------------------
int getMaxPathSum_Mamoization(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dpArr){
    if(j<0 || j>=arr[0].size())   return INT_MIN;
    if(i == 0)     return arr[0][j];     
    if(dpArr[i][j] != -1)   return dpArr[i][j];

    int upperPath = arr[i][j] + getMaxPathSum_Mamoization(arr, i-1, j, dpArr);
    int leftDiagonal = arr[i][j] + getMaxPathSum_Mamoization(arr, i-1, j-1, dpArr);
    int rightDiagonal = arr[i][j] + getMaxPathSum_Mamoization(arr, i-1, j+1, dpArr);

    return dpArr[i][j] = max(upperPath, max(leftDiagonal, rightDiagonal));
}

int maxFalling_PathSum_Mamoization(vector<vector<int>> &arr, vector<vector<int>> &dpArr){
    int n = arr.size();
    int m = arr[0].size();
    int maxi = INT_MIN;
    for(int j=0;j<m;j++){
        maxi = max(maxi, getMaxPathSum_Mamoization(arr, n-1, j, dpArr));
    }
    return maxi;
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*m) + O(n)          // for taking maximum in each rows addition
// Space Complexity : O(n*m)
// ------------------------------------
int maxFalling_PathSum_Tabulation(vector<vector<int>> &arr, vector<vector<int>> &dpArr){
    int n = arr.size();
    int m = arr[0].size();

    for(int j=0;j<m;j++)  dpArr[0][j] = arr[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int upperPath = arr[i][j] + dpArr[i-1][j];
            
            int leftDiagonal = arr[i][j];
            if(j-1>=0)  leftDiagonal += dpArr[i-1][j-1];
            else leftDiagonal += INT_MIN;

            int rightDiagonal = arr[i][j];
            if(j+1<m)   rightDiagonal +=dpArr[i-1][j+1];
            else rightDiagonal += INT_MIN; 

            dpArr[i][j] = max(upperPath, max(leftDiagonal, rightDiagonal));
        }
    }
    int maxi = INT_MIN;
    for(int j=0;j<m;j++){
        maxi = max(maxi, dpArr[n-1][j]);
    }
    return maxi;
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity : O(n*m) + O(n)          // for taking maximum in each rows addition
// Space Complexity : O(n)
// ------------------------------------
int maxFalling_PathSum_TabulationOPTM(vector<vector<int>> &arr, int n){
    // int n = arr.size();
    int m = arr[0].size();
    vector<int> prev(m,0), current(m,0);

    for(int j=0;j<m;j++)  prev[j] = arr[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int upperPath = arr[i][j] + prev[j];
            
            int leftDiagonal = arr[i][j];
            if(j-1>=0)  leftDiagonal += prev[j-1];
            else leftDiagonal += INT_MIN;

            int rightDiagonal = arr[i][j];
            if(j+1<m)   rightDiagonal += prev[j+1];
            else rightDiagonal += INT_MIN; 

            current[j] = max(upperPath, max(leftDiagonal, rightDiagonal));
        }
        prev = current;
    }
    int maxi = INT_MIN;
    for(int j=0;j<m;j++){
        maxi = max(maxi, prev[j]);
    }
    return maxi;    
}
// __________________________________________________________________________________


int main()
{
    int n, m, data;
    cout<<"Size (n): ";
    cin>>n;
    cout<<"Size (m): ";
    cin>>m;

    vector<int> row;
    vector<vector<int>> arr;
    vector<vector<int>> dpArr(n, vector<int> (m, -1));

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
    cout<<"----------------------"<<endl;

    int minSumRecursion = maxFalling_PathSum_Recursion(arr);
    cout<<"Using Recursion MinSUM in Triangle : "<<minSumRecursion<<endl;

    int minSumMamo = maxFalling_PathSum_Mamoization(arr, dpArr);
    cout<<"Using Mamoization MinSUM in Triangle : "<<minSumMamo<<endl;

    int minSumTabu = maxFalling_PathSum_Tabulation(arr, dpArr);
    cout<<"Using Tabulation MinSUM in Triangle : "<<minSumTabu<<endl;
    
    int minSumTabuOPTM = maxFalling_PathSum_TabulationOPTM(arr, n);
    cout<<"Using TabulationOPTM MinSUM in Triangle : "<<minSumTabuOPTM<<endl;

    return 0;
}