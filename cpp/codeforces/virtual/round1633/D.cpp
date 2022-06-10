#include <bits/stdc++.h>
#define lli long long int
#define COUT(...) std::cout << __VA_ARGS__ << std::endl
using namespace std;

map<pair<int, int>, int> dp;

int min_steps(int a) {
    // minimum number of steps to convert from 1 to a with the given operation (a_i + floor(a_i / x))
    // hint: use bfs

    set<int> seen;
    queue<pair<int, int>> q;    // first element is element, second element is depth
    q.push({1, 0});
    while(!q.empty()) {
        pair<int, int> next = q.front();
        q.pop();
        // COUT(next.first);

        if(next.first == a) {
            return next.second;
        }
        seen.insert(next.first);
        for(int i = 1; i <= next.first; i++) {
            int x = next.first + int(floor(float(next.first) / float(i)));
            if(seen.find(x) == seen.end()) {
                // if haven't seen the element yet, search it
                q.push({x, next.second + 1});
            }
        }
    }
}

int max_coins(int n, int w[], int c[], int k) {
    if(dp.find( {n, k} ) != dp.end()) {
        return dp[{n, k}];
    }
    if(n < 0 || k < 0) {
        // no more items to include or no more capacity
        return 0;
    } else if(w[n] > k) {
        // we cant include the item
        return max_coins(n - 1, w, c, k);

    } else {
        // we could include the item
        // include, not include
        int ans = max(c[n] + max_coins(n - 1, w, c, k - w[n]), max_coins(n - 1, w, c, k));
        dp[{n, k}] = ans;
        return ans;
    }
}

int main()
{
    int t;
    cin >> t;    
    for(int abc = 0; abc < t; abc++) {
        int n, k;
        cin >> n >> k;
        int a[n] = {1};
        int b[n], c[n];
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }

        int w[n];
        for(int i = 0; i < n; i++) {
            w[i] = min_steps(b[i]);
        }

        k = min(k, 12 * n);

        cout << max_coins(n - 1, w, c, k) << "\n";
        dp.clear();
    }   
    
    return 0;
}