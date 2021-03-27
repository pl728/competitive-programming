#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall test_reversort_eng.cpp -o test_reversort_eng

vector<int> generate_sequence(int n, int c)
{
    vector<int> A;
    if (c < n - 1 || c > (n * (n + 1)) / 2 - 1)
    {
        return vector<int>();
    }
    // construct sorted starting point
    for (int i = 0; i < n; i++)
    {
        A.at(i) = i + 1;
    }
    int cost = n - 1;

    // begin reversing starting from the end
    for (int i = n - 2; i >= 0; i--)
    {
        if (cost == c)
        {
            return A;
        }
        else if (cost < c)
        {
            int remaining = c - cost;
            int m = min(remaining, n - i - 1);
            cost += m;
            reverse(A.begin() + i, A.begin() + i + m + 1);
        }
    }
    return A;
}

int test_answer(int L[], int n)
{
    int total_cost = 0;
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
    }
    return total_cost;
}

int main()
{
    for (int N = 2; N <= 7; N++)
    {
        for (int C = 1; C <= 1000; C++)
        {
            vector<int> a = generate_sequence(N, C);
            int *b = &a[0];
            assert(test_answer(b, N) == C);
        }
    }
    cout << "Test Succeded \n";

    return 0;
}