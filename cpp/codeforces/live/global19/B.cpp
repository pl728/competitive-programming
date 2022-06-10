#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// cost = num partitions + sum_i(mex(partition_i))

int best_value(lli a[], int start, int stop) {
    // how to find the best partition of a segment? 
    // generate all possible partitions using recursion 
    int n = stop - start;
    int b[n];

    

}

int mex(lli a[], int start, int stop) {
    unordered_set<int> set;
    for(int i = start; i < stop; i++) {
        set.insert(a[i]);
    }

    for(int i = 0; i < 1000000002; i++) {
        if(set.find(i) == set.end()) {
            return i;
        }
    }
}

int main()
{
    int t; cin >> t;
    for(int v = 0; v < t; v++) {
        int n; cin >> n;
        lli a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int total = 0;
        for(int i = 0; i < n; i++) {
            for(int j = n; j > i; j--) {
                // now find the best partition
                total += best_value(a, i, j);
            }
        }
        cout << total << "\n";
    }
    return 0;
}