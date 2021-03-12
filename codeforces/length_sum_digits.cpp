#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// to compile:
// g++ -std=c++11 -O2 -Wall _.cpp -o _

int main()
{
    int m, s;
    cin >> m;
    cin >> s;

    int digits[m] = {0};
    digits[0] = 1;
    int sum = 1;
    string min, max;
    // find max first, then reverse is min
    for (int i = m - 1; i > 0; i--)
    {
        if (sum + 9 < s)
        {
            digits[i] += 9;
            sum += 9;
        }
        else
        {
            digits[i] += s - sum;
            sum += s - sum;
            break;
        }
    }
    if (sum + 8 >= s)
    {
        digits[0] += s - sum;
        sum += s - sum;
        for (int i = 0; i < m; i++)
        {
            min.append(to_string(digits[i]));
            max.append(to_string((digits[m - i - 1])));
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << digits[i] << " ";
    }
    cout << "\n";
    cout << min << " " << max;

    return 0;
}