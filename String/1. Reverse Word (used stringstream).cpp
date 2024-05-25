#include<iostream>
#include<string>
#include <sstream>
#include<stack>
using namespace std;

// --------------------------------------------------------------------------------------------------------------------------------
// A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file.

// Basic methods are:
// 1. clear()- To clear the stream.
// 2. str()- To get and set string object whose content is present in the stream. 
// 3. operator <<- Add a string to the stringstream object. 
// 4. operator >>- Read something from the stringstream object.
// --------------------------------------------------------------------------------------------------------------------------------

// String: the sky is blue
// Reversed Word: blue is sky the

string reverseWords(string s) {
    stack<string> stk;
    stringstream strStream(s);
    string word;

    while (strStream >> word) {         // read words from the string_Stream (or sentence) 
        stk.push(word);                 // push the word read from String_stream (or sentence) to STACK.
    }

    string ans;
    while (!stk.empty()) {
        ans += stk.top();           // In stack words are already stored in reversed order so just pop.
        stk.pop();
        if (!stk.empty()) {
            ans += " "; // Add a space only if there are more words
        }
    }
    return ans;

}


int main()
{
    string s;
    cout<<"String: ";
    getline(cin, s); // Use getline to read the whole line
    
    string ans = reverseWords(s);
    cout << "Reversed Word: "<<ans<<endl;

 return 0;
}

