#include<iostream>
#include<string>
#include<vector>
using namespace std;

// ---------------------------------------------------------------------------
//  String: ( ( * )
//  True : The Parenthesis are balanced and Valid
//  ( ( ) )  -->> '*' changes to ')' 
//  ---------------------------
//  String: ( ( ) * ) * ( )
//  True : The Parenthesis are balanced and Valid
//  ( ( ) '(' ) ' ' ( )  -->>  '*' changes to first '(' then ' ' OR blank 
// ---------------------------------------------------------------------------

// ___________________________  Using Recursion  ______________________________
// Time Complexity : O(3^n)       -->>  For 3 options of changing '*' to '( ' || ' ' || ')' 
// Space Complexity : O(n)      -->> O(n) is the auxiliary stack space
// ----------------------------------------------------
bool validParenthesis_Recursion(string str, int i, int count, int n) { 
    if(count < 0)   return false;
    if(i == n)  return(count == 0);     // if count == 0 return true else false

    if(str[i] == '(' )   return validParenthesis_Recursion(str, i + 1, count + 1, n);
    if(str[i] == ')' )   return validParenthesis_Recursion(str, i + 1, count - 1, n);

    return                  // if not '(' ')' then it will be '*' and if any of 3 condition then return true else false
        validParenthesis_Recursion(str, i+1, count+1, n) ||     // takes the '*' as ' ( '
        validParenthesis_Recursion(str, i+1, count-1, n) ||    // takes the '*' as ' ) '
        validParenthesis_Recursion(str, i+1, count, n);       // takes the '*' as ' ' or blank
}
// _______________________________________________________________________________________

// ___________________________  Using Mamoization  _____________________
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)    
// -------------------------------------------
bool validParenthesis_Mamoization(string str, int i, int count, int n, vector<vector<int>> &dpArr){
    if(count < 0)   return false;
    if(i == n)  return(count == 0);     // if count == 0 return true else false

    if(dpArr[i][count] != -1)   return dpArr[i][count];
    if(str[i] == '(' )   return dpArr[i][count] = validParenthesis_Mamoization(str, i + 1, count + 1, n, dpArr);
    if(str[i] == ')' )   return dpArr[i][count] = validParenthesis_Mamoization(str, i + 1, count - 1, n, dpArr);

    return dpArr[i][count] =          // if not '(' ')' then it will be '*' and if any of 3 condition then return true else false
        validParenthesis_Mamoization(str, i+1, count+1, n, dpArr) ||     // takes the '*' as ' ( '
        validParenthesis_Mamoization(str, i+1, count-1, n, dpArr) ||    // takes the '*' as ' ) '
        validParenthesis_Mamoization(str, i+1, count, n, dpArr);       // takes the '*' as ' ' or blank
}
// __________________________________________________________________________________



// ________________________  Using GREEDY-Algorithm  _____________________
// Time Complexity : O(n)
// Space Complexity : O(1)    
// -------------------------------------------
bool validParenthesis_GREEDY(string str, int n){
    int max = 0 , min = 0;
    for(int i=0;i<n;i++) {
        if(str[i] == '(') {
            min++;
            max++;
        }
        else if(str[i] == ')') {
            min--;
            max++;
        }
        else if(str[i] == '*') {
            min--;                 // since ranges from 0 to 1 so min decrese by 1 and max increase by 1
            max++;
        }
        if(min < 0)  min = 0;
        if(max < 0)   return false;
    }
    if(min == 0)    return true;
    else        return false;
}
// __________________________________________________________________________________


int main()
{
    string str;
    cout<<"String: ";
    cin>>str;
    int n = str.size();
    vector<vector<int>> dpArr(n+1, vector<int> (n+1, -1));

    bool isBalance_Recursion = validParenthesis_Recursion(str, 0, 0, n);     // n1-1 since indexing from (0 to n-1)
    if(isBalance_Recursion)   cout<<"True : The Parenthesis are balanced and Valid"<<endl;
    else     cout<<"False : The Parenthesis are neither Balance nor Valid"<<endl;

    bool isBalance_Mamoization = validParenthesis_Mamoization(str, 0, 0, n, dpArr);   
    if(isBalance_Mamoization)   cout<<"True : The Parenthesis are balanced and Valid"<<endl;   
    else     cout<<"False : The Parenthesis are neither Balance nor Valid"<<endl;            // n1-1 since indexing from (0 to n-1)                

    bool isBalance_Greedy = validParenthesis_GREEDY(str, n);       
    if(isBalance_Greedy)   cout<<"True : The Parenthesis are balanced and Valid"<<endl;   
    else     cout<<"False : The Parenthesis are neither Balance nor Valid"<<endl;     

    return 0;
}