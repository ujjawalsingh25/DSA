// String Hashing
// #include<iostream>
// #include<string>

// using namespace std;
// int main(){
// int a = 'a';
// string s;
// cin>>s;
// for(int i=0;i<5;i++){
//     cout<<s[i]<<" "<<endl;
// }
// cout<<a<<endl;
// return 0;
// }

#include<iostream>
#include<string>
using namespace std;

int hashing(string s, char c){
    int hash_arr[26] = {0};
    for(int i = 0; i<=s.size() ;i++){
        hash_arr[s[i] - 'a'] += 1;
    }
    return hash_arr[c-'a'];
}

int main() {
    string s;
    cout << "String: ";
    cin >> s;
    int t;
    char c;
    cout << "Test Cases: ";
    cin >> t;
    while (t--) {
        cout << "Enter char to search: ";
        cin >> c;
        int hash_data = hashing(s, c);
        cout << hash_data << endl;
    }

    return 0;
}