#include<iostream>
#include<vector>
using namespace std;


// _____________________  Fibo Using Mamoization   ___________________________________________________
// 0 1 1 2 3 5 8 13 21 34
// Fibo till Number : 9
// Fibo using Tabulation: 34
// ---------------------------------
// Time Complexity -> O(n)
// Space Complexity -> O(n) + O(n)  (Recurssion + DP_Array)
// -----------------------------------------------------------------

int fibo_using_Mamoization(vector<int> &dpArr, int n){
    if(n<=1)    return n;
    if(dpArr[n] != -1)  return dpArr[n];
    return dpArr[n] = fibo_using_Mamoization(dpArr, n-1) + fibo_using_Mamoization(dpArr, n-2);
}
// ____________________________________________________________________________________________________


// _____________________  Fibo Using Tabulation   ________________________________________
// 0 1 1 2 3 5 8 13 21 34
// Fibo till Number : 9
// Fibo using Tabulation: 21
// ---------------------------------
// Time Complexity -> O(n)
// Space Complexity -> O(1)
// -----------------------------------------------------
int fibo_using_Tabulation(int n){
    int ans=0;
    int prev = 1, prev2 = 0;
    for(int i=2; i<=n;i++){
        ans = prev + prev2;
        prev2 = prev;
        prev = ans;
    }
    return ans;
}
// _____________________________________________________________________________________________________

int main()
{
    int n;
    cout<<"Fibo till Number : ";
    cin>>n;
    cout<<"------------------"<<endl;

    vector<int> dpArr(n+1, -1);     // vector of size n+1, where each element initialize with value -1 
    int ansMamoization = fibo_using_Mamoization(dpArr, n);
    cout<<"Fibo using Mamoization: "<<ansMamoization<<endl;

    cout<<"------------------"<<endl;    
    int ansTablulation = fibo_using_Tabulation(n);
    cout<<"Fibo using Tabulation: "<<ansTablulation<<endl;

    return 0;
}