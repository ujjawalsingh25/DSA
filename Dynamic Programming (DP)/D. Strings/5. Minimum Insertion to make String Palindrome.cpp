#include<iostream>
#include<string>
#include<vector>
#include<algorithm>     // for reverse
using namespace std;

// String : abcaa
// --------------------------------------------------------------
// Minimum Insertion to make String Palindrome : 2
//         [  a  b  c  a  a  ]
//  {a , (a) , b , c , (b) , a , a }  -->> 2 insertion ( a , b)
// 
//  if we ONE 'b' after 'c' and ONE 'a' before 'b' 
//  then on minimum of 2 insertion we get Palindrome String
// 
// --------------------------------------------------------------

// _______________________________________________________________________
// {{{(  String Length - Longest Palindrome Subsequence Length  )}}}      |  **************
// _______________________________________________________________________|  **************


// __________  Algorithm  ___________________________________________________
// Minimum Insertion will be                                                 |
//       {{{(  String Length - Longest Palindrome Subsequence Length  )}}}   |
//                                                                           |
//  String_SIZE = 5                                                          |
//  LongestPalindromeSubsequence_SIZE = 3                                    |           
// -->> String_SIZE - LongestPalindromeSubsequence_SIZE                      |
//          -->>  5 - 3 = 2 (Minimum Insertion )                             |
//                                                                           |
//  if we ONE 'b' after 'c' and ONE 'a' before 'b'                           |
//  then on minimum of 2 insertion we get Palindrome String                  |
// __________________________________________________________________________|


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
// -----------------------
// ___________________________  Longest Palindromic Subsequence  _____________________
int longest_Palindromic_Subsequence(string str){
    string str1 = str, str2 = str;
    int n1 = str1.size();

    reverse(str2.begin(), str2.end());

    return longestCommonSubsequence_Tabulation(str1, str2, n1, n1);     // n1 since both of same size indexing from (1 to n)
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation of LCS  _____________________
// Time Complexity : O(n1*n2) + O(n1)   -->> O(n1) for reversing  (Longest Palindromic Subsequence)
// Space Complexity : O(n1*n2)                 ( Longest Palindromic Subsequence )
// ------------------------------------
int minInsertion_toMake_Palindrome(string str){
    int String_Size = str.size();
    int LPS_Size = longest_Palindromic_Subsequence(str);
    
    return String_Size - LPS_Size;
}
// __________________________________________________________________________________


int main()
{
    string str;
    cout<<"String : ";
    cin>>str;
    
    int minInsertion = minInsertion_toMake_Palindrome(str);       
    cout<<"Minimum Insertion to make String Palindrome : "<<minInsertion<<endl;

    return 0;
}