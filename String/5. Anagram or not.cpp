#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std; 

// String1: anagram
// String2: nagaram
// -------
// m -> 1
// r -> 1
// g -> 1
// n -> 1
// a -> 3
// -------
// m -> 0 (So Erased)
// r -> 0 (So Erased)
// g -> 0 (So Erased)
// n -> 0 (So Erased)
// a -> 0 (So Erased)
// --------
// True

bool isAnagram(string s1, string s2) {
    unordered_map<char, int> mppS1; 
    unordered_map<char, int> mppS2;
    for(int i=0;i<s1.size();i++){
        mppS1[s1[i]] += 1;
    } 
    for(int i=0;i<s2.size();i++){
        mppS2[s2[i]] += 1;
    } 

    if(mppS1.size() != mppS2.size())  return false;

    cout<<"-------"<<endl; 
    for(auto iter = mppS1.begin(); iter != mppS1.end(); iter++){
        cout<<iter->first<<" -> "<<iter->second<<endl;
    }  

    for(int i=0;i<s1.size();i++){
        if(mppS1.find(s2[i]) == mppS1.end()){
            cout<<" absent: "<<s2[i];
            // return false;
        }
        else if(mppS1.find(s2[i]) != mppS1.end() && mppS1[s2[i]] > 0){
            mppS1[s2[i]]--;
        }
        if(mppS1[s2[i]] == 0){
            mppS1.erase(s2[i]);
        }
    }

    cout<<"-------"<<endl; 
    for(auto iter = mppS1.begin(); iter != mppS1.end(); iter++){
        cout<<iter->first<<" -> "<<iter->second<<endl;
    }  



    if(mppS1.size() == 0)    return true;
    else  return false; 

}

int main()
{
    string s1, s2;
    cout<<"String1: ";
    cin>>s1;
    cout<<"String2: ";
    cin>>s2;
    
    if(isAnagram(s1,s2)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}







