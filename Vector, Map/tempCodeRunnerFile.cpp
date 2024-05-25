#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string arr) {
    int dist = 0;
    unordered_map<int, int> mpp;
    int start = 0;  // This variable keeps track of the starting position of the current substring.

    for (int i = 0; i < arr.size(); i++) {
        if (mpp.find(arr[i]) != mpp.end() && mpp[arr[i]] >= start) {
            start = mpp[arr[i]] + 1;
        }
        mpp[arr[i]] = i;
        dist = max(dist, i - start + 1);
    }
    return dist;
}

int main() {
    string s;
    cout << "String : ";
    cin >> s;

    int ans = lengthOfLongestSubstring(s);
    cout << "Maximum distance between the same element: " << ans << endl;

    return 0;
}
