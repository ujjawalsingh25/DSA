
#include<iostream>
#include<string>
#include<stack>
using namespace std;

long long recursionFindOdd(long long num){
    if(num % 2 != 0)    return num;
    if(num == 0) return -1;
    
    return recursionFindOdd(num/10);
}

string largest_OddNumber(string s) {
    long long num = stoll(s);
    long long recvNum = recursionFindOdd(num); 
    if (recvNum == -1 ) return "";
    string ans = to_string(recvNum);

return ans;
}

// string largest_OddNumber(string s) {
//     int n=s.size();
//     while (i >= 0 && (s[i] - '0') % 2 == 0) {
//         i--;
//     }
//     if (i < 0)  return "";

//     return s.substr(0, i + 1);
// }


int main()
{
    string s;
    cout<<"String: ";
    cin>>s;

    string ans = largest_OddNumber(s);
    cout << "Largest Odd Number: "<<ans<<endl;

 return 0;
}

