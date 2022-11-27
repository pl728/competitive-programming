#include <bits/stdc++.h>
#define F(i,a,b) for (int i = a; i < b; i++)
using namespace std;

void solve() {
    ifstream cin ("shell.in");
    ofstream cout ("shell.out");
    int N; cin >> N;
    int shellAt[3];
    F(i,0,3){
        shellAt[i] = i;
    }
    vector<int> ans(3);
    F(i, 0, N) {
        int a,b,g;
        cin >> a >> b >> g;
        a--;b--;g--;
        swap(shellAt[a], shellAt[b]);
        // [0,1,2] -> [1,0,2]
        ans[shellAt[g]]++;
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
}

int main() {
    solve();
}