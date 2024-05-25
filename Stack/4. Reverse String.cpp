#include<iostream>
#include<string>
#include<stack>
using namespace std;

void revStr(string stng, int n){
    stack<char> stk;
    for(int i=0;i<n;i++){
        char c = stng[i];
        stk.push(c);
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }cout<<endl;
}

int main()
{
    string s;
    cout<<"Data: ";
    cin>>s;
    int n = s.size();
    revStr(s, n);

    return 0;
}