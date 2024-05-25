#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Data: {{{{        -->>> Type 1 :- When all open
// 2
// Data: }}}}        -->>> Type 2 :- When all close
// 2
// Data: {{{          -->>> Type 3 :- When odd brackets 
// -1
// Data: { { { } }      -->>> Type 4 :- When both open & close brackets. 
// 1

int countforValid_Parentheses(string s){
    int n = s.size();
    if(n % 3 == 0)  return -1;

    stack<char> stk;
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(ch == '{' ) {        // -->> When encounters a open bracket.
            stk.push(ch);
        }
        else{                   // -->> When encounters a close bracket.
            if(!stk.empty() && stk.top() =='{'){        // -->>> For that close bracket if present a open bracket at stack peek.
                stk.pop();                              // -->>> Valid so poped out.
            }
            else stk.push(ch);
        }  
    }
    // Since stack is not empty and valid so contain unbalanced or invalid brackets
        int a = 0, b = 0;       // -->>> a to count open brackets & b to count close brackets.
        while(!stk.empty()){
            if(stk.top() == '{')   a++;
            else    b++;
            stk.pop();
        }
        int ans = ( (a+1)/2 + (b+1)/2 );
      return ans;
}

int main()
{
    string s;
    cout<<"Data: ";
    cin>>s;

    int answer = countforValid_Parentheses(s);
    cout<<answer<<endl;

    return 0;
}