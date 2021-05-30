#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall bit_strings.cpp -o bit_strings

int main()
{

    int n;
    cin >> n;

    lli result = 1;
    // print: 2^n % X
    // X = 10^9 + 7

    for (int i = 0; i < n; i++)
    {
        result *= 2;
        result = result % ((lli)pow(10, 9) + 7);
    }

    cout << result;

    return 0;
}