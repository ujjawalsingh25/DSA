
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// String1 : ?ay
// String2 : ray            // True  '?' --> r

// String1 : **abcd
// String2 : abcd           // True  '*' '*' --> '' ''

// String1 : ab?d
// String2 : abcc           // False

// String1 : ab*cd
// String2 : abdefcd        // True  '*' --> def
// -------------------------------------
// Longest Common Subsequence : 2
//      a b * c d  |  a b d e f c d
//         "*" -->>  { d, e, f}
// -------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(2^n1 * 2^n2)         -->> Exponential
// Space Complexity : O(n1+n2) 
// ----------------------------------------------------
bool wildcardMatching_Recursion(string pattern, string text, int i, int j){
    if(i < 0 && j < 0)    return true;
    if(i < 0 && j >= 0)    return false;
    if(j<0 && i>=0) {
        for(int ii = 0; ii < i; ii++){
            if(pattern[ii] != '*')   return false;
        }
        return true;
    }
    if(pattern[i] == text[j] || pattern[i] == '?'){
        return wildcardMatching_Recursion(pattern, text, i-1, j-1);
    }
    if(pattern[i] == '*'){
        return wildcardMatching_Recursion(pattern, text, i-1, j)
            | wildcardMatching_Recursion(pattern, text, i, j-1);
    }
    return false;
}
// _______________________________________________________________________________________


// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) + O(n1+n2)   -->> O(n) is the auxiliary stack space   
// ------------------------------------
bool wildcardMatching_Mamoization(string pattern, string text, int i, int j, vector<vector<int>> &dpArr){
    if(i < 0 && j < 0)    return true;
    if(i < 0 && j >= 0)    return false;
    if(j<0 && i>=0) {
        for(int ii = 0; ii < i; ii++){
            if(pattern[ii] != '*')   return false;
        }
        return true;
    }
    if(dpArr[i][j] != -1)   return dpArr[i][j];
    if(pattern[i] == text[j] || pattern[i] == '?'){
        return wildcardMatching_Mamoization(pattern, text, i-1, j-1, dpArr);
    }
    if(pattern[i] == '*'){
        return dpArr[i][j] = wildcardMatching_Mamoization(pattern, text, i-1, j, dpArr)
            | wildcardMatching_Mamoization(pattern, text, i, j-1, dpArr);
    }
    return dpArr[i][j] = false;
}
// -----------------  1 based 
bool wildcardMatching_Mamoization2(string pattern, string text, int i, int j, vector<vector<int>> &dpArr){
    if(i == 0 && j == 0)    return true;
    if(i == 0 && j > 0)    return false;
    if(j == 0 && i > 0) {
        for(int ii = 1; ii < i; ii++){
            if(pattern[ii-1] != '*')   return false;
        }
        return true;
    }
    if(dpArr[i][j] != -1)   return dpArr[i][j];

    if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
        return wildcardMatching_Mamoization2    (pattern, text, i-1, j-1, dpArr);
    }
    if(pattern[i-1] == '*'){
        return dpArr[i][j] = wildcardMatching_Mamoization2  (pattern, text, i-1, j, dpArr)
            | wildcardMatching_Mamoization2 (pattern, text, i, j-1, dpArr);
    }
    return dpArr[i][j] = false;
}
// __________________________________________________________________________________



// ___________________________  Using Tabulation  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) 
// ------------------------------------
int wildcardMatching_Tabulation(string pattern, string text, int n, int m){
    vector<vector<bool>> dpArr(n+1, vector<bool> (m+1, false));
    
    dpArr[0][0] = true;
    for(int j=1; j<=m; j++)   dpArr[0][j] = false;

    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int ii = 1; ii <= i; ii++){
            if(pattern[ii-1] != '*') {
                flag = false;
                break;
            }
        }
        dpArr[i][0] = flag;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                dpArr[i][j] =  dpArr[i-1][j-1];
            }
            else if(pattern[i-1] == '*'){
                dpArr[i][j] =  dpArr[i-1][j] |  dpArr[i][j-1];
            }
            else dpArr[i][j] = false;
        }
    }

    return dpArr[n][m];
}
// __________________________________________________________________________________



// ___________________________  Using Tabulation OPTIMISED  _____________________
// Time Complexity : O(n1*n2)
// Space Complexity : O(n1) 
// ------------------------------------
int wildcardMatching_TabulationOPTM(string pattern, string text, int n, int m){
    vector<bool> prev(m+1, false), current(m+1, false);
    
    prev[0] = true;
    for(int j=1; j<=m; j++)   prev[j] = false;

    for(int i = 1; i <= n; i++){
        // For every row assign the current first
        bool flag = true;
        for(int ii = 1; ii <= i; ii++){
            if(pattern[ii-1] != '*') {
                flag = false;
                break;
            }
        }
        current[0] = flag;

        for(int j = 1; j <= m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                current[j] =  prev[j-1];
            }
            else if(pattern[i-1] == '*'){
                current[j] =  prev[j] |  current[j-1];
            }
            else current[j] = false;
        }
        prev = current;
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

    bool isMatched_Recursion = wildcardMatching_Recursion(str1, str2, n1-1, n2-1);     // n1-1 since indexing from (0 to n-1)
    if(isMatched_Recursion)   cout<<"True"<<endl;
    else   cout<<"False"<<endl;

    bool isMatched_Mamoization = wildcardMatching_Mamoization(str1, str2, n1-1, n2-1, dpArr);   
    if(isMatched_Mamoization)   cout<<"True"<<endl;
    else   cout<<"False"<<endl;                       // n1-1 since indexing from (0 to n-1)
    bool isMatched_Mamoization2 = wildcardMatching_Mamoization2(str1, str2, n1-1, n2-1, dpArr);   
    if(isMatched_Mamoization2)   cout<<"True"<<endl;
    else   cout<<"False"<<endl;                       // n1-1 since indexing from (0 to n-1)

    bool isMatched_Tabulation = wildcardMatching_Tabulation(str1, str2, n1, n2);       // n1 since indexing from (1 to n)
    if(isMatched_Tabulation)   cout<<"True"<<endl;
    else   cout<<"False"<<endl;   

    bool isMatched_TabulationOPTM = wildcardMatching_TabulationOPTM(str1, str2, n1, n2);     // n1 since indexing from (1 to n)
    if(isMatched_TabulationOPTM)   cout<<"True"<<endl;
    else   cout<<"False"<<endl; 

    return 0;
}
