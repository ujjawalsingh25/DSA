#include<iostream>
#include<string>
#include<vector>
using namespace std;

// String1 : babgbag
// String2 : bag 
// -----------------------------------------------------------------------
// Number of Distinct Subsequence : 5
//             0  1  2  3  4  5  6   |   0  1  2
//             b  a  b  g  b  a  g   |   b  a  g
//     [  {0, 1, 3} , {0, 1, 6} , {0, 5, 6} , {2, 5, g} , {4, 5, 6}  ] 
// -----------------------------------------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(2^n1 * 2^n2)         -->> Exponential
// Space Complexity : O(n1+n2) 
// ----------------------------------------------------
int numberOf_DistinctSubsequence_Recursion(string str1, string str2, int index1, int index2){
    if(index2 < 0)  return 1;  // Start from 'g' in 'bag' and since (index2<0) means before'b', so must got a distinct subsequence
    if(index1 < 0)  return 0;   // in string 1 if index down below without finding all string2 characters so return 0

    if(str1[index1] == str2[index2]){
        return numberOf_DistinctSubsequence_Recursion(str1, str2, index1 - 1, index2 - 1) + 
               numberOf_DistinctSubsequence_Recursion(str1, str2, index1 - 1, index2);
    }
    return numberOf_DistinctSubsequence_Recursion(str1, str2, index1 - 1, index2);
}

// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) + O(n1+n2)   -->> O(n) is the auxiliary stack space 
// -------------------------------------------
int numberOf_DistinctSubsequence_Mamoization(string str1, string str2, int i, int j, vector<vector<int>> &dpArr){
    if(j < 0)  return 1;  // Start from 'g' in 'bag' and since (j<0) means before'b', so must got a distinct subsequence
    if(i < 0)  return 0;   // in string 1 if index down below without finding all string2 characters so return 0

    if(dpArr[i][j] != -1)   return dpArr[i][j];
    if(str1[i] == str2[j]){
        return dpArr[i][j] = numberOf_DistinctSubsequence_Mamoization(str1, str2, i - 1, j - 1, dpArr) + 
               numberOf_DistinctSubsequence_Mamoization(str1, str2, i - 1, j, dpArr);
    }
    return dpArr[i][j] = numberOf_DistinctSubsequence_Mamoization(str1, str2, i - 1, j, dpArr);
}
// ------------  1 Based Indexing
int numberOf_DistinctSubsequence_Mamoization2(string str1, string str2, int i, int j, vector<vector<int>> &dp){
    if(j == 0)  return 1;  // Start from 'g' in 'bag' and since (j<0) means before'b', so must got a distinct subsequence
    if(i == 0)  return 0;   // in string 1 if index down below without finding all string2 characters so return 0

    if(dp[i][j] != -1)   return dp[i][j];
    if(str1[i-1] == str2[j-1]){
        return dp[i][j] = numberOf_DistinctSubsequence_Mamoization2(str1, str2, i - 1, j - 1, dp) + 
               numberOf_DistinctSubsequence_Mamoization2(str1, str2, i - 1, j, dp);
    }
    return dp[i][j] = numberOf_DistinctSubsequence_Mamoization2(str1, str2, i - 1, j, dp);
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) 
// ------------------------------------
int numberOf_DistinctSubsequence_Tabulation(string str1, string str2, int n, int m){
    vector<vector<int>> dpArr(n+1, vector<int> (m+1, 0));
    for(int i=0; i<=n; i++)   dpArr[i][0] = 1;
    for(int j=1; j<=m; j++)   dpArr[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
           if(str1[i-1] == str2[j-1])
                dpArr[i][j] = dpArr[i-1][j-1] + dpArr[i-1][j];
            else
                dpArr[i][j] = dpArr[i-1][j];           
        }
    }
    return dpArr[n][m];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1) 
// ------------------------------------
int numberOf_DistinctSubsequence_TabulationOPTM(string str1, string str2, int n, int m){
    vector<int> prev(m+1, 0), current(m+1, 0);
    prev[0] = current[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
           if(str1[i-1] == str2[j-1])
                current[j] = prev[j-1] + prev[j];
            else
                current[j] = prev[j];           
        }
        prev = current;
    }
    return prev[m];  
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation OPTIMISED2  _____________________
// Time Complexity : 
// Space Complexity : 
// ------------------------------------
int numberOf_DistinctSubsequence_TabulationOPTM2(string str1, string str2, int n, int m){
    vector<int> prev(m+1, 0);
    prev[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){
           if(str1[i-1] == str2[j-1])
                prev[j] = prev[j-1] + prev[j];          
        }
    }
    return prev[m];  
}
// __________________________________________________________________________________


int main()
{
    string str1, str2;
    cout<<"String1 : ";
    cin>>str1;
    cout<<"String2 : ";
    cin>>str2;
    int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dpArr(n1, vector<int> (n2, -1));
    vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));

    int distinctSubSeQ_Recursion = numberOf_DistinctSubsequence_Recursion(str1, str2, n1-1, n2-1);   
    cout<<"Number of Distinct Subsequence : "<<distinctSubSeQ_Recursion<<endl;        // n1-1 since indexing from (0 to n-1)

    int distinctSubSeQ_Mamoization = numberOf_DistinctSubsequence_Mamoization(str1, str2, n1-1, n2-1, dpArr);   
    cout<<"Number of Distinct Subsequence : "<<distinctSubSeQ_Mamoization<<endl;      // n1-1 since indexing from (0 to n-1)
    int distinctSubSeQ_Mamoization2 = numberOf_DistinctSubsequence_Mamoization2(str1, str2, n1, n2, dp);   
    cout<<"Number of Distinct Subsequence : "<<distinctSubSeQ_Mamoization2<<endl;      // n1 since indexing from (1 to n)

    int distinctSubSeQ_Tabulation = numberOf_DistinctSubsequence_Tabulation(str1, str2, n1, n2);    
    cout<<"Number of Distinct Subsequence : "<<distinctSubSeQ_Tabulation<<endl;        // n1 since indexing from (1 to n)

    int distinctSubSeQ_TabulationOPTM = numberOf_DistinctSubsequence_TabulationOPTM(str1, str2, n1, n2);    
    cout<<"Number of Distinct Subsequence : "<<distinctSubSeQ_TabulationOPTM<<endl;      // n1 since indexing from (1 to n)
   
    int distinctSubSeQ_TabulationOPTM2 = numberOf_DistinctSubsequence_TabulationOPTM2(str1, str2, n1, n2);    
    cout<<"Number of Distinct Subsequence : "<<distinctSubSeQ_TabulationOPTM2<<endl;      // n1 since indexing from (1 to n)

    return 0;
}