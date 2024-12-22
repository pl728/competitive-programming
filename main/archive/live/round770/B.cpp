#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int m = 0; m < t; m++) {
        int n;
        lli x, y;
        cin >> n >> x >> y;
        lli a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        lli alice_start = x;
        lli bob_start = x + 3;

        deque<lli> dq;
        set<lli> toAdd; 
        dq.push_back(y);
        
        // start with y and work backwards in the array. 
        for(int i = n - 1; i >= 0; i--) {
            toAdd.clear();
            while(!dq.empty()) {
                lli next = dq.back();
                dq.pop_back();

                lli xr = (a[i] ^ next);
                // cout << "xr: " << xr << "\n";
                lli add = next - a[i];
                if(xr > -1) {
                    toAdd.insert(xr);
                }
                if(add > - 1) {
                    toAdd.insert(add);
                }
            }

            // add all in toAdd to dq
            // no duplicates or negatives
            for(auto elem : toAdd) {
                dq.push_back(elem);
                // cout << "elems : " << elem << ", ";
            }
            // cout << "\n";
        }

        if(toAdd.find(alice_start) != toAdd.end()) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
    }
    return 0;
}