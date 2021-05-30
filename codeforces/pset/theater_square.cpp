#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall theater_square.cpp -o theater_square

int main()
{
    lli n, m, a;
    cin >> n >> m >> a;
    cout << (lli)ceil((double)n / a) * (lli)ceil((double)m / a);
    return 0;
}