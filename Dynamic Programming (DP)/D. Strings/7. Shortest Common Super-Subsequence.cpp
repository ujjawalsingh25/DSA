#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// String1 : brute
// String2 : groot  
// -----------------------------------------------------
//         b r u t e  |  g r o o t                         ↖⬅⬆
// -----------------------------------------------
//                        ⬇    ⬇     ⬇     ⬇     ⬇       
//                        g    r     o     o     t  
//                  0     1    2     3     4     5   
//                  _________________________________
//             0   | 0   (0)   0     0     0     0          (zero padded)  
//      ➔  b  1   | 0  ⬆(0)   0     0     0     0 
//      ➔  r  2   | 0    0 ↖ (1) ⬅ 1     1     1
//      ➔  u  3   | 0    0    1  ⬆ (1) ⬅(1)    1
//      ➔  t  4   | 0    0    1     1     1  ↖ (2) 
//      ➔  e  5   | 0    0    1     1     1  ⬆ (2)  
// -----------------------------------------------------------------------------------------
// Longest Common Subsequence : { e, t, o, u, o, r, b, g }       (Multiple Sol Possible)
//      { [5,5] ➔ e, [4,5] ➔ t, [3,4] ➔ o, [3,3] ➔ u, [2,3] ➔ o, [2,2] ➔ r, [1,1] ➔ b, [0,1] ➔ g  }
//     Reverse  -->> { g  b  r  o  u  o  t  e }    ==>>  Sortest Common SuperSubsequence
// -----------------------------------------------------------------------------------------

// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n*m) + O(n+m)   -->>  (Tabulation + BackTrack) 
// Space Complexity : O(n1*n2) + O(StringArrayLength)  
// ------------------------------------
string shortestCommonSuperSubsequence_Tabulation(string str1, string str2, int n, int m){
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
    string SCSuperSubseq_String = "";
    int i = n, j =m;

    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            SCSuperSubseq_String += str1[i-1];
            i--; j--;
        }
        else if(dpArr[i][j-1] > dpArr[i-1][j]) {
            SCSuperSubseq_String += str2[j-1];
            j--;
        }
        else {
            SCSuperSubseq_String += str1[i-1];
            i--;
        }
    }

    while(i > 0) {
        SCSuperSubseq_String += str1[i-1];
        i--;
    }
    while(j > 0){
        SCSuperSubseq_String += str2[j-1];
        j--;
    }

    reverse(SCSuperSubseq_String.begin(), SCSuperSubseq_String.end());
    return SCSuperSubseq_String;
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

    string lcs_String = shortestCommonSuperSubsequence_Tabulation(str1, str2, n1, n2);       // n1 since indexing from (1 to n)
    cout<<"Shortest Common Super-Subsequence : "<<lcs_String<<endl;

    return 0;
}
