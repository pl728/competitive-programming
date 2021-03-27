#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall reversort_eng2.cpp -o reversort_eng2

int main()
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n, c;
        cin >> n;
        cin >> c;
        int A[n];
        if (c < n - 1 || c > (n * (n + 1)) / 2 - 1)
        {
            cout << "Case #" << a + 1 << ": IMPOSSIBLE"
                 << "\n";
            continue; // skip this one
        }
        // construct sorted starting point
        for (int i = 0; i < n; i++)
        {
            A[i] = i + 1;
        }
        int cost = n - 1;

        // begin reversing starting from the end
        for (int i = n - 2; i >= 0; i--)
        {
            if (cost < c)
            {
                int remaining = c - cost;
                int m = min(remaining, n - i - 1);
                cost += m;
                reverse(A + i, A + i + m + 1);
            }
        }
        // print result
        cout << "Case #" << a + 1 << ": ";
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";

        // cout << "Actual Cost: " << test_answer(A, n) << "\n";
    }

    return 0;
}