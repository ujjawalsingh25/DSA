#include<iostream>
#include<string>
#include<vector>
#include<algorithm>     // for reverse
using namespace std;

// String : abcaa
// --------------------------------------------------------------
// Minimum Insertion-Deletions to Convert String A to String B : 3
//          a  b  c  d    |    a  n  c   
// 
//  2 Deletion -->>  'b' &&  'c'
//  1 Insertion -->>  'n'
// --------------------------------------------------------------

// _________________________________________________________________________________
//   INSERTION  -->>  String1 Length (n1) - Longest Palindrome Subsequence Length   |  **************
//   DELETTION  -->>  String2 Length (n2) - Longest Palindrome Subsequence Length   |  **************
//       -->> Minimum Insertion-Del to Convert -->> INSERTION + DELETION            |  **************
//                 ==>> [ n1 - length(LCS) ]  +  [ n2 - length(LCS) ]               |  **************
//                    ==>>  n1 + n2  - 2 * length(LCS)                              |  **************
// _________________________________________________________________________________|  **************


// __________  Algorithm  ___________________________________________________
// Minimum Insertion will be                                                 |
//       -->> String Length1 (n1) - Longest Palindrome Subsequence Length    |
// Minimum Deletion will be                                                  |
//       -->> String Length2 (n2) - Longest Palindrome Subsequence Length    |
//                                                                           |
//  The LCS_Size will have the common part so, After [ n1 - len(LCS) ]       |
//  the remaining part will have to deleted and only common reamins          |
//  From [ n2 - len(LCS) ] we get the part that need to be added             |
//  in order to have same strings                                            |
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
// __________________________________________________________________________________

// ___________________________  Using Tabulation of LCS  _____________________
// Time Complexity : O(n1*n2) + O(n1)   -->> O(n1) for reversing  (Longest Palindromic Subsequence)
// Space Complexity : O(n1*n2)                 ( Longest Palindromic Subsequence )
// ------------------------------------
int minInsertionDel_toConvert_StrAtoB(string str1, string str2){
    int n1 = str1.size();
    int n2 = str2.size();
    int LCS_Size = longestCommonSubsequence_Tabulation(str1, str2, n1, n2);

    int Insertion = n1 - LCS_Size;
    int Deletion = n2 - LCS_Size;
    return Insertion + Deletion;
}
// __________________________________________________________________________________


int main()
{
    string str1, str2;
    cout<<"String1 : ";
    cin>>str1;
    cout<<"String2 : ";
    cin>>str2;
    
    int minInsertionDel = minInsertionDel_toConvert_StrAtoB(str1, str2);       
    cout<<"Minimum Insertion-Deletions to Convert String A to String B : "<<minInsertionDel<<endl;

    return 0;
}