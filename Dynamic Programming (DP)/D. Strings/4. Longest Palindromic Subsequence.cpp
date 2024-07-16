#include<iostream>
#include<string>
#include<vector>
#include<algorithm>     // for reverse
using namespace std;

// String : bbabcbcab
// --------------------------------------------------
// Longest Palindromic Subsequence : 7
//    b b a b c b c a b  |  b a c b c b a b b
//               { b a b c b a b}
// --------------------------------------------------

// __________  Algorithm  ___________________________________________________
// Reverse the string and find the Longest Common Subsequence (LCS)          |
// between the string str its reverse str.                                   |
// -->> longestCommonSubsequence( str, reverse(str) );                       |
// __________________________________________________________________________|

// _______________________________________________________________________
// {{{(  longestCommonSubsequence( str, reverse(str) )          )}}}      |  **************
// _______________________________________________________________________|  **************

// ___________________________  Longest Common Subsequence Tabulation  _____________________
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

// ___________________________  Using Tabulation of LCS  _____________________
// Time Complexity : O(n1*n2) + O(n1)       -->> O(n1) for reversing
// Space Complexity : O(n1*n2) 
// ------------------------------------
int longest_Palindromic_Subsequence(string str){
    string str1 = str, str2 = str;
    int n1 = str1.size();

    reverse(str2.begin(), str2.end());

    return longestCommonSubsequence_Tabulation(str1, str2, n1, n1);     // n1 since both of same size indexing from (1 to n)
}
// __________________________________________________________________________________


int main()
{
    string str;
    cout<<"String : ";
    cin>>str;
    
    int longestPalindromeLength = longest_Palindromic_Subsequence(str);       
    cout<<"Longest Palindromic Subsequence : "<<longestPalindromeLength<<endl;

    return 0;
}