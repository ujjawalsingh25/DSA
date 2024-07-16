#include<iostream>
#include<vector>
using namespace std;

// Size : 4
// 4 5 1 1 2 4 3 5 2 7
// -------------
// 4
// 5 1
// 1 2 4
// 3 5 2 7
// 9
// -----------------------------------------
// Can iterarte "⬇" either "↘" and can't iterate "⬋" or "⬅"
// -----------------------------------------
//     4
//      ↘
//   5   1
//       ⬇  
//   1   2   4      (1 can't be taken as can't iterate as "⬋" or "⬅")
//        ↘
//  3   5   2    7
// Minimum Sum in Traingle in "DOWN" and "DIAGONAL" movement -->> (4) + (1) + (2) + (2) = 9
// ---------------------------------------------------------------------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O( 2^(m*n) )
// Space Complexity : O(n) 
// -----------------------------------------------------
int triangle_MinSum_Recursion(vector<vector<int>> &arr, int i, int j, int n){
    if(i == n-1)    return arr[n-1][j];
 
    int rightSum = arr[i][j] + triangle_MinSum_Recursion(arr, i+1, j, n);
    int downSum = arr[i][j] + triangle_MinSum_Recursion(arr, i+1, j+1, n);
    return min(rightSum, downSum);
}
// _______________________________________________________________________________________

// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n*m)
// Space Complexity : O((n-1)+(m-1)) + O(n*m)   (Path Length + DpArr)
// ------------------------------------
int triangle_MinSum_Mamoization(vector<vector<int>> &arr, int i, int j, int n, vector<vector<int>> &dpArr){
    if(i == n-1)    return arr[n-1][j];

    if(dpArr[i][j] != -1)   return dpArr[i][j];
    int rightSum = arr[i][j] + triangle_MinSum_Mamoization(arr, i+1, j, n, dpArr);
    int downSum = arr[i][j] + triangle_MinSum_Mamoization(arr, i+1, j+1, n, dpArr);
    
    return dpArr[i][j] = min(rightSum, downSum);
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
// ------------------------------------
int triangle_MinSum_Tabulation(vector<vector<int>> &arr, int n, vector<vector<int>> &dpArr){
    int rightSum=0, downSum=0;
    for(int j=0;j<n;j++){
        dpArr[n-1][j] = arr[n-1][j];        
    }

    for(int i = n-2; i>0 ; i--){
        for(int j=i; j>=0; j--){
            rightSum = arr[i][j] + dpArr[i+1][j];
            downSum = arr[i][j] + dpArr[i+1][j+1];
            dpArr[i][j] = min(rightSum, downSum);
        }
    }
    return dpArr[0][0];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity :  O(N * 4 * 3)
// Space Complexity : O(4)
// ------------------------------------
int triangle_MinSum_TabulationOPTM(vector<vector<int>> &arr, int n){
    int rightSum=0, downSum=0;
    vector<int> frontRow(n,0), current(n,0);

    for(int j=0;j<n;j++){
        frontRow[j] = arr[n-1][j];        // store the below row rather storing the whole dpArr
    }

    for(int i = n-2; i>0; i--){
        for(int j=i; j>=0; j--){
            rightSum = arr[i][j] + frontRow[j];
            downSum = arr[i][j] + frontRow[j+1];
            current[j] = min(rightSum, downSum);
        }
        frontRow = current;
    }
    return frontRow[0];
}
// __________________________________________________________________________________

int main()
{
    int n, m, data;
    cout<<"Size : ";
    cin>>n;

    vector<int> row;
    vector<vector<int>> arr;
    vector<vector<int>> dpArr(n, vector<int> (n, -1));

    for(int i=0;i<n;i++){
        row.clear();
        for(int j=0;j<=i;j++){
            cin>>data;
            row.push_back(data);
        }
        arr.push_back(row);
    }

    cout<<"-------------"<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    int minSumRecursion = triangle_MinSum_Recursion(arr, 0, 0, n);
    cout<<"Using Recursion MinSUM in Triangle : "<<minSumRecursion<<endl;

    int minSumMamo = triangle_MinSum_Mamoization(arr, 0, 0, n, dpArr);
    cout<<"Using Mamoization MinSUM in Triangle : "<<minSumMamo<<endl;

    int minSumTabu = triangle_MinSum_Tabulation(arr, n, dpArr);
    cout<<"Using Tabulation MinSUM in Triangle : "<<minSumTabu<<endl;
    
    int minSumTabuOPTM = triangle_MinSum_TabulationOPTM(arr, n);
    cout<<"Using TabulationOPTM MinSUM in Triangle : "<<minSumTabuOPTM<<endl;

    return 0;
}