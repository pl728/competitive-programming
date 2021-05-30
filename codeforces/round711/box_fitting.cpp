#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall box_fitting.cpp -o box_fitting

int main()
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        lli W;
        cin >> W;
        multiset<int> ms;

        for (int i = 0; i < n; i++)
        {
            int next;
            cin >> next;
            ms.insert(next);
        }

        // at each step, pick the largest box that will fit in the empty space on the current line
        // we have an array w[n], maximum space on one line W
        // i.e. the maximum element that is smaller than W - current_line
        lli remaining = W;
        lli height = 1;
        while (!ms.empty())
        {
            auto best_fit = prev(ms.upper_bound(remaining));
            if (best_fit == ms.end() || *best_fit > remaining)
            {
                // not inside multset
                remaining = W;
                height++;
            }
            else
            {
                // if exists, guaranteed to be less than or equal to remaining
                remaining -= *best_fit;
                ms.erase(ms.find(*best_fit));
            }
        }
        cout << height << "\n";
    }

    return 0;
}