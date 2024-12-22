#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall reversort.cpp -o reversort

int main()
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        int L[n];
        lli total_cost = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> L[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            // get smallest index
            int *smallest = min_element(L + i, L + n);
            int j = distance(L, find(L, L + n, *smallest));
            if (i == j)
            {
                total_cost += 1;
                continue;
            }
            total_cost += j - i + 1;
            // reverse that subsection
            for (int k = i; k < i + ceil((float)((j - i) / 2)) + 1; k++)
            {
                int temp = L[k];
                L[k] = L[j - k + i];
                L[j - k + i] = temp;
            }
            // for (int i = 0; i < n; i++)
            // {
            //     cout << L[i] << " ";
            // }
            // cout << "\n";
        }

        cout << "Case #" << a + 1 << ": " << total_cost << "\n";
    }

    return 0;
}