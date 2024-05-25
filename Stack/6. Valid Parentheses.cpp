
#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Data: { { ( [ ] ) } }
// Valid or Balanced Parentheses

bool isValid_Parentheses(string s){
    int n = s.size();
    stack<char> stk;
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '[' ) {
            stk.push(ch);
        }
        else{
            if(!stk.empty()){
                char peek = stk.top();
                if(ch == ')' && peek == '(' || ch == '}' && peek == '{' || ch == ']' && peek == '[' )
                    stk.pop();
                else return false;
            }
            else return false;
        }  
    }
    if(stk.empty()) return true;
    else    return false;
}

int main()
{
    string s;
    cout<<"Data: ";
    cin>>s;

    if(isValid_Parentheses(s))  cout<<"Valid or Balanced Parentheses"<<endl;
    else  cout<<"Not a Valid or Balanced Parentheses"<<endl;

    return 0;
}