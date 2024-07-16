#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// String1 : intention
// String2 : execution
// ---------------------------------------------------------------------------
// Minimum Replace-Insertion-Deletion to Convert String A to String B: 5
//        i n t e n t i o n   |   e x e c u t i o n
//    Replace,  i  ->  e   [e n t e n t i o n]
//    Replace,  n  ->  x   [e x t e n t i o n]
//    Remove,   t  -->>    [e x e n t i o n]
//    Replace,  n  ->  c   [e x e c t i o n]
//    Insert,   u  -->>    [e x e c u t i o n]
// ----------------------------------------------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(2^n1 * 2^n2)         -->> Exponential
// Space Complexity : O(n1+n2) 
// ----------------------------------------------------
int minInsertDelReplace_toConvert_StrAtoB(string str1, string str2, int i, int j){
    if(i < 0)  return j + 1;  // if str1 ends then rest characters of str2 should be inserted & indexing from 0 so j+1
    if(j < 0)  return i + 1;  // if str2 ends then rest characters of str1 should be deleted & since indexing from 0 so i+1

    if(str1[i] ==  str2[j])   return minInsertDelReplace_toConvert_StrAtoB(str1, str2, i-1, j-1);
    return 1 + min(
            minInsertDelReplace_toConvert_StrAtoB(str1, str2, i, j-1),    // INSERTION,  since inserted hypothethically
        min(                  // so i remain at same position and j since now str1 have the char hypotheticalyl so j-1 
            minInsertDelReplace_toConvert_StrAtoB(str1, str2, i-1, j),    // DELETION, since deleted so i-1;
            minInsertDelReplace_toConvert_StrAtoB(str1, str2, i-1, j-1)   //  REPLACE, so both indexes decrease by 1
        )
    );
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) + O(n1+n2)   -->> O(n) is the auxiliary stack space 
// -------------------------------------------
int minInsertDelReplace_toConvert_StrAtoB_Mamo(string str1, string str2, int i, int j, vector<vector<int>> &dpArr){
    if(i < 0)  return j + 1;  // if str1 ends then rest characters of str2 should be inserted & indexing from 0 so j+1
    if(j < 0)  return i + 1;  // if str2 ends then rest characters of str1 should be deleted & since indexing from 0 so i+1

    if(dpArr[i][j] != -1)   return dpArr[i][j];
    if(str1[i] ==  str2[j])   return dpArr[i][j] = minInsertDelReplace_toConvert_StrAtoB_Mamo(str1, str2, i-1, j-1, dpArr);
    return dpArr[i][j] = 1 + min(
            minInsertDelReplace_toConvert_StrAtoB_Mamo(str1, str2, i, j-1, dpArr),    // INSERTION,  since inserted hypothethically
        min(                  // so i remain at same position and j since now str1 have the char hypotheticalyl so j-1 
            minInsertDelReplace_toConvert_StrAtoB_Mamo(str1, str2, i-1, j, dpArr),    // DELETION, since deleted so i-1;
            minInsertDelReplace_toConvert_StrAtoB_Mamo(str1, str2, i-1, j-1, dpArr)   //  REPLACE, so both indexes decrease by 1
        )
    );
}
// --------------- 1 based indexing  ---------------
int minInsertDelReplace_toConvert_StrAtoB_Mamo2(string str1, string str2, int i, int j, vector<vector<int>> &dp){
    if(i == 0)  return j;  // if str1 ends then rest characters of str2 should be inserted & indexing from 0 so j
    if(j == 0)  return i;  // if str2 ends then rest characters of str1 should be deleted & since indexing from 0 so i

    if(dp[i][j] != -1)   return dp[i][j];
    if(str1[i-1] ==  str2[j-1])   return dp[i][j] = minInsertDelReplace_toConvert_StrAtoB_Mamo2(str1, str2, i-1, j-1, dp);
    return dp[i][j] = 1 + min(
            minInsertDelReplace_toConvert_StrAtoB_Mamo2(str1, str2, i, j-1, dp),    // INSERTION,  since inserted hypothethically
        min(                  // so i remain at same position and j since now str1 have the char hypotheticalyl so j-1 
            minInsertDelReplace_toConvert_StrAtoB_Mamo2(str1, str2, i-1, j, dp),    // DELETION, since deleted so i-1;
            minInsertDelReplace_toConvert_StrAtoB_Mamo2(str1, str2, i-1, j-1, dp)   //  REPLACE, so both indexes decrease by 1
        )
    );
}
// __________________________________________________________________________________


// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) 
// ------------------------------------
int minInsertDelReplace_toConvert_StrAtoB_Tabulation(string str1, string str2, int n1, int n2){
    vector<vector<int>> dpArr(n1+1, vector<int> (n2+1, 0));
    for(int i=0; i<=n1; i++)   dpArr[i][0] = i;
    for(int j=0; j<=n2; j++)   dpArr[0][j] = j;

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(str1[i-1] ==  str2[j-1])
                dpArr[i][j] = dpArr[i-1][j-1];
            else 
                dpArr[i][j] = 1 + min( dpArr[i][j-1],  min(dpArr[i-1][j], dpArr[i-1][j-1]) );           
        }
    }
    return dpArr[n1][n2];
}
// __________________________________________________________________________________

// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1) 
// ------------------------------------
int minInsertDelReplace_toConvert_StrAtoB_TabulationOPTM(string str1, string str2, int n1, int n2){
    vector<int> prev(n2+1, 0), current(n2+1, 0);
    for(int j=0; j<=n2; j++)   prev[j] = j;

    for(int i = 1; i <= n1; i++){
        current[0] = i;                 // same for(int i=0; i<=n1; i++)   dpArr[i][0] = i;
        for(int j = 1; j <= n2; j++){
            if(str1[i-1] ==  str2[j-1])
                current[j] = prev[j-1];
            else 
                current[j] = 1 + min( current[j-1],  min(prev[j], prev[j-1]) );            
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
    vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));

    int minInsertDelReplace_Recursion = minInsertDelReplace_toConvert_StrAtoB(str1, str2, n1-1, n2-1);   
    cout<<"Minimum Replace-Insertion-Deletion to Convert String A to String B: "<<minInsertDelReplace_Recursion<<endl;      
                        // n1-1 since indexing from (0 to n-1)

    int minInsertDelReplace_Mamoization = minInsertDelReplace_toConvert_StrAtoB_Mamo(str1, str2, n1-1, n2-1, dpArr);   
    cout<<"Minimum Replace-Insertion-Deletion to Convert String A to String B: "<<minInsertDelReplace_Mamoization<<endl;     
                        // n1-1 since indexing from (0 to n-1)
    int minInsertDelReplace_Mamoization2 = minInsertDelReplace_toConvert_StrAtoB_Mamo2(str1, str2, n1, n2, dp);   
    cout<<"Minimum Replace-Insertion-Deletion to Convert String A to String B: "<<minInsertDelReplace_Mamoization2<<endl;     
                        // n1-1 since indexing from (1 to n)

    int minInsertDelReplace_Tabulation = minInsertDelReplace_toConvert_StrAtoB_Tabulation(str1, str2, n1, n2);    
    cout<<"Minimum Replace-Insertion-Deletion to Convert String A to String B: "<<minInsertDelReplace_Tabulation<<endl;        
                        // n1 since indexing from (1 to n)

    int minInsertDelReplace_TabulationOPTM = minInsertDelReplace_toConvert_StrAtoB_TabulationOPTM(str1, str2, n1, n2);    
    cout<<"Minimum Replace-Insertion-Deletion to Convert String A to String B: "<<minInsertDelReplace_TabulationOPTM<<endl;      
                        // n1 since indexing from (1 to n)

    return 0;
}