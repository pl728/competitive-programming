#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    bool consec = false;
    unordered_set<char> uset;
    for(int i = 0; i < n; i++) {
        uset.insert(s[i]);
    }
    int numUnique = uset.size();
    if(numUnique == 1 || numUnique == n) {
        cout << "YES\n";
        return;
    }

    unordered_map<char, int> umap;

    for(int i = 0; i < numUnique; i++) {
        umap[s[i]]++;
        if(umap[s[i]] > 1) {
            cout << "NO\n";
            return;
        }
    }
    for(int i = numUnique; i < n; i++) {
        int j = i - numUnique;
        umap[s[j]]--;
        umap[s[i]]++;
        if(umap[s[i]] > 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    return;

}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
}
