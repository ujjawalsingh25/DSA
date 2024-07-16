#include<iostream>
#include<string>
#include<vector>
using namespace std;

// String1 : abcjklp
// String2 : acjkp   
// -------------------------------------
// Longest Common Subsequence : 3
//    a b c j k l p  |  a c j k p
//         { c , j , k }
// -------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(2^n1 * 2^n2)         -->> Exponential
// Space Complexity : O(n1*n2) 
// ----------------------------------------------------
int longestCommonSubstring_Recursion(string str1, string str2, int index1, int index2, int &maxLCS_len){
    if(index1 < 0 || index2 < 0)    return 0;

    int length = 0;
    if(str1[index1] == str2[index2]) {
        length = 1 + longestCommonSubstring_Recursion(str1, str2, index1 - 1, index2 - 1, maxLCS_len);
        maxLCS_len = max(maxLCS_len, length);
    }
    longestCommonSubstring_Recursion(str1, str2, index1 - 1, index2, maxLCS_len); 
    longestCommonSubstring_Recursion(str1, str2, index1, index2 - 1, maxLCS_len);

    return length;
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) + O(n1+n2)   -->> O(n) is the auxiliary stack space 
// -------------------------------------------
int longestCommonSubstring_Mamoization(string str1, string str2, int index1, int index2, int& maxLCS_len, vector<vector<int>> &dpArr){
    if(index1 < 0 || index2 < 0)    return 0;
    if(dpArr[index1][index2] != -1)    return dpArr[index1][index2];

    int length = 0;
    if(str1[index1] == str2[index2]) {
        length = 1 + longestCommonSubstring_Mamoization(str1, str2, index1 - 1, index2 - 1, maxLCS_len, dpArr);
        maxLCS_len = max(maxLCS_len, length);
    } else{
        longestCommonSubstring_Mamoization(str1, str2, index1 - 1, index2, maxLCS_len, dpArr); 
        longestCommonSubstring_Mamoization(str1, str2, index1, index2 - 1, maxLCS_len, dpArr);
    }
    return dpArr[index1][index2] = length;
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) 
// ------------------------------------
int longestCommonSubstring_Tabulation(string str1, string str2, int n1, int n2){
    vector<vector<int>> dpArr(n1+1, vector<int> (n2+1, 0));
    for(int i=0; i<=n1; i++)   dpArr[i][0] = 0;
    for(int j=0; j<=n2; j++)   dpArr[0][j] = 0;
    int lcs = 0;

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i-1] == str2[j-1]) {
                dpArr[i][j] = 1 + dpArr[i-1][j-1];
                lcs = max(lcs, dpArr[i][j]);
            }
            else    
                dpArr[i][j] = 0;            
        }
    }
    return lcs;
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1) 
// ------------------------------------
int longestCommonSubstring_TabulationOPTM(string str1, string str2, int n1, int n2){
    vector<int> prev(n2+1, 0), current(n2+1, 0);
    int lcs = 0;
    for(int j=0; j<=n2; j++)   prev[j] = 0;
    
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i-1] == str2[j-1]) {
                current[j] = 1 +prev[j-1];
                lcs = max(lcs, current[j]);
            }
            else    
                current[j] = 0;            
        }
        prev = current;
    }
    return lcs;    
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

    int lcs_Recursion = 0;                               // n1-1 since indexing from (0 to n-1)
    longestCommonSubstring_Recursion(str1, str2, n1 - 1, n2 - 1, lcs_Recursion);
    cout << "Longest Common Substring (Recursion) : " << lcs_Recursion << endl;

    int lcs_Mamoization = 0;                                  // n1-1 since indexing from (0 to n-1)
    longestCommonSubstring_Mamoization(str1, str2, n1 - 1, n2 - 1, lcs_Mamoization, dpArr);
    cout << "Longest Common Substring (Memoization) : " << lcs_Mamoization << endl;

    int lcs_Tabulation = longestCommonSubstring_Tabulation(str1, str2, n1, n2);       // n1 since indexing from (1 to n)
    cout<<"Longest Common Substring (Tabulation) : "<<lcs_Tabulation<<endl;

    int lcs_TabulationOPTM = longestCommonSubstring_TabulationOPTM(str1, str2, n1, n2);     // n1 since indexing from (1 to n)
    cout<<"Longest Common Substring (TabulationOPTM) : "<<lcs_TabulationOPTM<<endl;

    return 0;
}