#include <bits/stdc++.h>
#define f(i,b) for (int i = 0; i < b; i++)
using ll = long long;
using namespace std;

const int M = 1e9 + 7;

void solve() {
    vector<int> counts(26, 0);
    string s; cin >> s;
    f(i,s.length()) {
        counts[s[i] - 'A']++;
    }
    int numOdd = 0;
    int oddChar = -1;
    f(i,26) {
        if(counts[i] % 2 == 1) {
            numOdd++;
            oddChar = i;
        }
    }

    if((s.length() % 2 == 1 && numOdd > 1) || ((s.length() % 2 == 0) && numOdd > 0)) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    string result1 = "", middle = "", result2 = "";
    if(oddChar != -1) {
        middle += (char) (oddChar + 65);
        counts[oddChar] -= 1;
    }
    f(i,26) {
        while(counts[i] != 0) {
            result1 += (char) (i + 65);
            counts[i] -= 2;
        }
    }
    for(int i = result1.length() - 1; i >= 0; i--) {
        result2 += result1[i];
    }

    cout << result1 + middle + result2 << endl;
    return;
}

int main() {
    solve();
}