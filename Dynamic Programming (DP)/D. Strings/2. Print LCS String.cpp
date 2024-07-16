#include<iostream>
#include<string>
#include<vector>
using namespace std;

// String1 : abcde
// String2 : bdgek  
// -----------------------------------------------------
//      a b c d e  |  b d g e k
// -----------------------------------------------
//                       ⬇   ⬇    ⬇   ⬇    ⬇       
//                       b   d    g   e    k  
//                  0    1   2    3   4    5   
//                  _____________________________ 
//             0   | 0   0   0    0   0    0          (zero padded)  
//      ➔  a  1   | 0   0   0    0   0    0 
//      ➔  b  2   | 0 ↖ 1   1    1   1    1
//      ➔  c  3   | 0   1   1    1   1    1
//      ➔  d  4   | 0   1 ↖ 2 ⬅ 2   2   (2) [i-1][j]
//      ➔  e  5   | 0   1   2    2 ↖(3)⬅ 3
//                                 [i][j-1]  
// -------------------------------------------------
// Longest Common Subsequence : { b , d , e } 
//      { [5,4] ➔ e , [4,2] ➔ d , [2,1] ➔ b }
// ----------------------------------------------------------

// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*m) + O(n+m)   -->>  (Tabulation + BackTrack) 
// Space Complexity : O(n1*n2) + O(StringArrayLength)  
// ------------------------------------
string longestCommonSubsequence_Tabulation(string str1, string str2, int n, int m){
    vector<vector<int>> dpArr(n+1, vector<int> (m+1, 0));
    for(int i=0; i<=n; i++)   dpArr[i][0] = 0;
    for(int j=0; j<=m; j++)   dpArr[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1])   dpArr[i][j] = 1 + dpArr[i-1][j-1];
            else    
                dpArr[i][j] = max(dpArr[i-1][j], dpArr[i][j-1]);            
        }
    }
// ------------------------------------
    int length = dpArr[n][m];
    string LCS_String = "";
    for(int i=0; i<length; i++)   LCS_String += '$';

    int strIndex = length-1;
    int i = n, j =m;
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            LCS_String[strIndex] = str1[i-1];
            strIndex--;         // Since inserting characters from back as Looping-Back from dpArr[n][m]
            i--; j--;
        }
        else if(dpArr[i][j-1] > dpArr[i-1][j])   j--;
        else  i--;
    }

    return LCS_String;
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
    vector<vector<int>> dpArr(n1, vector<int> (n2, -1));                   // n1-1 since indexing from (0 to n-1)

    string lcs_String = longestCommonSubsequence_Tabulation(str1, str2, n1, n2);       // n1 since indexing from (1 to n)
    cout<<"Longest Common Subsequence : "<<lcs_String<<endl;

    return 0;
}
