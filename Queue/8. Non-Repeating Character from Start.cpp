#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

// String: aabbc
// a#b#c

string nonRepeating_Character(string s){
    unordered_map<char, int> mpp;
    queue<char> quu;
    string ans;

    for(int i=0;i<s.size();i++){
        char ch = s[i];
        mpp[ch]++;
        quu.push(ch);
        while(!quu.empty()){
            if(mpp[ch] > 1) quu.pop();
            else{
                ans.push_back(quu.front());
                break;
            }
        }
        if(quu.empty()){
            ans.push_back('#');
        }
    }
  return ans;  
}


int main()
{
    string s;
    cout<<"String: ";
    cin>>s;

    string ans = nonRepeating_Character(s);
    cout<<ans;

  return 0;  
}