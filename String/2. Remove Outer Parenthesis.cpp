#include<iostream>
#include<string>
#include<stack>
using namespace std;

// Input: s = "(()())(())"
// Output: "()()()"
// Input: ((()))
// Ouput: (())

string removeOuterParentheses(string s) {
    stack<char> stk;
    string ans;
    int n = s.size();
    int balance = 0; // To keep track of the balance of parentheses

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' ) {
            if (balance > 0) {
                ans += '(';
            }
            stk.push(s[i]);
            balance++;
        } else if (s[i] == ')' && !stk.empty() && stk.top() == '(') {
            stk.pop();
            balance--;
            if (balance > 0) {
                ans += ')';
            }
        }
    }
    return ans;
}


int main()
{
    string s;
    cout<<"String: ";
    cin>>s;

    string ans = removeOuterParentheses(s);
    cout << "Removed Outer Parenthesis: "<<ans<<endl;

 return 0;
}

