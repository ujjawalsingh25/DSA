#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

void display(unordered_map<char, vector<int>> &mpp){
    for (auto iter = mpp.begin(); iter != mpp.end(); iter++) {
        cout << iter->first << " -> ";
        for (int position : iter->second) {
            cout << position << " ";
        }
        cout << endl;
    }
}

// String: tree
// e -> 2 3
// r -> 1 
// t -> 0
// -------
// eert

string frequencySort(string s) {
    unordered_map<char, vector<int>> mpp;
    string ans;

    for (int i = 0; i < s.size(); i++) {
        mpp[s[i]].push_back(i);
    }
    display(mpp);
    cout << "-------" << endl;

    while (!mpp.empty()) {
        char maxChar = ' ';
        int maxCount = 0;

        for (auto iter = mpp.begin(); iter != mpp.end(); iter++) {
            if (iter->second.size() > maxCount) {
                maxCount = iter->second.size();
                maxChar = iter->first;
            }
        }

        if (maxChar != ' ') {
            ans += string(maxCount, maxChar);
            mpp[maxChar].clear();
            mpp.erase(maxChar);
        }
    }

    return ans;
}

int main() {
    string s;
    cout << "String: ";
    cin >> s;

    string ans = frequencySort(s);
    cout << ans << endl;
}
