#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// does there exist a breakpoint "len" in the array such that sorting the two halves doesn't result in a sorted complete array?
// this occurs if the max of the left array is greater than the min of the right array
// iterate through the array, keeping track of the max of the right and left arrays 

int main()
{
    int t;
    cin >> t;

    for(int v = 0; v < t; v++) {
        int n;
        cin >> n;
        lli a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        lli minimum_from_right[n];
        lli min_right = LLONG_MAX;

        for(int i = n - 1; i >= 0; i--) {
            minimum_from_right[i] = min(min_right, a[i]);
            min_right = min(min_right, a[i]);
        }

        bool yes = false;

        lli maximum_left = -1;
        for(int i = 0; i < n; i++) {
            maximum_left = max(maximum_left, a[i]);
            if(maximum_left > minimum_from_right[i]) {
                yes = true;
            }
        }

        if(yes) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        

    }

    return 0;
}