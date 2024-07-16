#include<iostream>
#include<vector>
using namespace std;

// Size : 5
// Bills : 5 5 5 10 20
// --------------------------------------------------
// True  -->> Saled all Lemonade
//      5   -->> 1,2,3  |
//      10  -->> 1      |   5  -> 1,2   |
//      20  -->> 1      |   10 -> 0     |   5 -> 1
// -----------------------------------------------------

// Size : 5
// Bills : 5 5 10 10 20
// --------------------------------------------------
// False -->> Not Saled all lemonade  (As below 20 can't be returned)
//      5   -->> 1,2    |
//      10  -->> 1,2    |   5  -> 1,0   |
//      20  -->> 1      |   10 -> 2     |   5 -> 0  
// -----------------------------------------------------

// _______________________________________________________________________________________
// Time Complexity : O(n)       
// Space Complexity : O(1) 
// --------------------------------------------------------------
bool lemonadeChange(vector<int> &bills, int n){
    int RsFive = 0, RsTen = 0, RsTwenty = 0;
    for(int i = 0; i < n; i++){

        if(bills[i] == 5)   RsFive = RsFive + 1;
        else if(bills[i] == 10){
            if(RsFive > 0){
                RsTen = RsTen + 1;
                RsFive = RsFive - 1;
            } else return false;
        }   
        else {
            if(RsTen > 0 && RsFive > 0){
                RsTen--;
                RsFive--;
            }
            else if(RsFive >= 3)     RsFive -= 3;
            else return false;
        }
    }
    return true;
}
// _______________________________________________________________________________________

int main()
{
    int n, data;
    vector<int> arr;

    cout<<"Size : ";
    cin>>n;
    cout<<"Bills : ";
    for(int i=0;i<n;i++){
        cin>>data;
        arr.push_back(data);
    }

    bool allSaled = lemonadeChange(arr, n);
    if(allSaled)    
        cout<<"True  -->> Saled all Lemonade";
    else
        cout<<"False -->> Not Saled all lemonade";

    return 0;
}