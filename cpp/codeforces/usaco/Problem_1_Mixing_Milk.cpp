#include <bits/stdc++.h>
#define for(i,a,b) for (int i = a; i < b; i++)
using namespace std;

void solve() {
    ifstream cin ("mixmilk.in");
    ofstream cout ("mixmilk.out");

    vector<int> c(3);
    vector<int> m(3);

    for(i,0,3){
        cin >> m[i] >> c[i];
    }
    for(i,0,100) {
        int f = i % 3;
        int t = (i + 1) % 3;
        if(c[f] > m[t] - c[t]) {
            // if can fill
            c[f] -= (m[t] - c[t]);
            c[t] = m[t];
        } else {
            c[t] += c[f];
            c[f] = 0;
        }
    }
    for(i,0,3){
        cout << c[i] << endl;
    }
}

int main() {
    solve();
}