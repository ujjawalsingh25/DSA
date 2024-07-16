#include<iostream>
#include<string>
#include<vector>
using namespace std;

// String1 : acd
// String2 : ced    
// -------------------------------------
// Longest Common Subsequence : 2
//      a c d  |  c e d
//         { c , d}
// -------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(2^n1 * 2^n2)         -->> Exponential
// Space Complexity : O(n1*n2) 
// ----------------------------------------------------
int longestCommonSubsequence_Recursion(string str1, string str2, int index1, int index2){
    if(index1 < 0 || index2 < 0)    return 0;

    if(str1[index1] == str2[index2]) {
        return 1 + longestCommonSubsequence_Recursion(str1, str2, index1 - 1, index2 - 1);
    }
    
    return max(
        longestCommonSubsequence_Recursion(str1, str2, index1 - 1, index2), 
        longestCommonSubsequence_Recursion(str1, str2, index1, index2 - 1)
    );
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) + O(n1+n2)   -->> O(n) is the auxiliary stack space 
// -------------------------------------------
int longestCommonSubsequence_Mamoization(string str1, string str2, int index1, int index2, vector<vector<int>> &dpArr){
    if(index1 < 0 || index2 < 0)    return 0;
    if(dpArr[index1][index2] != -1)    return dpArr[index1][index2];

    if(str1[index1] == str2[index2]) {
        return dpArr[index1][index2] = 1 + longestCommonSubsequence_Mamoization(str1, str2, index1 - 1, index2 - 1, dpArr);
    }
    
    return dpArr[index1][index2] = max(
        longestCommonSubsequence_Mamoization(str1, str2, index1 - 1, index2, dpArr), 
        longestCommonSubsequence_Mamoization(str1, str2, index1, index2 - 1, dpArr)
    );
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) 
// ------------------------------------
int longestCommonSubsequence_Tabulation(string str1, string str2, int n1, int n2){
    vector<vector<int>> dpArr(n1+1, vector<int> (n2+1, 0));
    for(int i=0; i<=n1; i++)   dpArr[i][0] = 0;
    for(int j=0; j<=n2; j++)   dpArr[0][j] = 0;

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i-1] == str2[j-1])   dpArr[i][j] = 1 + dpArr[i-1][j-1];
            else    
                dpArr[i][j] = max(dpArr[i-1][j], dpArr[i][j-1]);            
        }
    }
    return dpArr[n1][n2];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1) 
// ------------------------------------
int longestCommonSubsequence_TabulationOPTM(string str1, string str2, int n1, int n2){
    vector<int> prev(n2+1, 0), current(n2+1, 0);
    for(int j=0; j<=n2; j++)   prev[j] = 0;

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i-1] == str2[j-1])   current[j] = 1 +prev[j-1];
            else    
                current[j] = max(prev[j], current[j-1]);            
        }
        prev = current;
    }
    return prev[n2];    
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

    int lcs_Recursion = longestCommonSubsequence_Recursion(str1, str2, n1-1, n2-1);     // n1-1 since indexing from (0 to n-1)
    cout<<"Longest Common Subsequence : "<<lcs_Recursion<<endl;

    int lcs_Mamoization = longestCommonSubsequence_Mamoization(str1, str2, n1-1, n2-1, dpArr);   
    cout<<"Longest Common Subsequence : "<<lcs_Mamoization<<endl;                        // n1-1 since indexing from (0 to n-1)

    int lcs_Tabulation = longestCommonSubsequence_Tabulation(str1, str2, n1, n2);       // n1 since indexing from (1 to n)
    cout<<"Longest Common Subsequence : "<<lcs_Tabulation<<endl;

    int lcs_TabulationOPTM = longestCommonSubsequence_TabulationOPTM(str1, str2, n1, n2);     // n1 since indexing from (1 to n)
    cout<<"Longest Common Subsequence : "<<lcs_TabulationOPTM<<endl;

    return 0;
}