#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxDepth_inParentheses(string s){
    stack<char> stk;
    int ans=0;
    int balance = 0; // To keep track of the balance of parentheses

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' ) {
            stk.push(s[i]);
            balance++;
        }
        else if (s[i] == ')' && !stk.empty() && stk.top() == '(') {
            if (balance > 0) {
                ans = max(ans, balance);
            }
            stk.pop();
            balance--;
        }
    }
  return ans;
}

int main()
{
    string s;
    cout<<"String: ";
    cin>>s;

    int ans = maxDepth_inParentheses(s);
    cout<<ans<<endl;

    return 0;
}
