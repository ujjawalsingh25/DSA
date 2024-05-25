#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

 void display(unordered_map<char, vector<int>> mpps, unordered_map<char, vector<int>> mppt){
    cout<<"------"<<endl;
    for (auto iter = mppt.begin(); iter != mppt.end(); ++iter) {
        char key = iter->first;
        vector<int> values = iter->second;

        cout << key << " -> ";
                for (int value : values) {
            cout << value << " ";
        }
        cout << endl;
    }
    cout<<"------"<<endl;
 }
 
// String1: add
// String2: egg
// ------
// g -> 1 2
// e -> 0
// ------
// True

// String1: bbbaaaba
// String2: aaabbbba
// ------
// b -> 3 4 5 6
// a -> 0 1 2 7
// ------
// False

bool isIsomorphic(string s, string t) {
    unordered_map<char, vector<int>> mpps; 
    unordered_map<char, vector<int>> mppt;

    for(int i=0;i<s.size();i++) {
        mpps[s[i]].push_back(i);
    }
    for(int i=0;i<t.size();i++){
        mppt[t[i]].push_back(i);
    }
    if(mpps.size() != mppt.size()) return false;
    
    display(mpps, mppt);

    for(int i=0;i<s.size();i++){
        if(mpps[s[i]] != mppt[t[i]])    return false;
    }
   return true;
}

int main()
{
    string s, t;
    cout<<"String1: ";
    cin>>s;
    cout<<"String2: ";
    cin>>t;
    
    if(isIsomorphic(s, t)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}







