#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// greedy approach 
// 1010101010111
// length 1 - no minority
// length 2 - no minority
// length 3 - minority when 2/1
// length 4 - minority when 3/1
// length 5 - minority when 4/1, 3/2
// if num_maj - num_min > 0, there is a minority 
//
// is there a case where a you can remove more of a minority in a shorter substring than a longer one?
// 01111100000000000000000000000000000000000000001

int main()
{
    int t;
    cin >> t;
    for(int a = 0; a < t; a++) {
        string s;
        cin >> s;

        int num0, num1, max_minority;
        num0 = 0;
        num1 = 0;
        max_minority = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                num0 += 1;
            } else {
                num1 += 1;
            }

            if(num0 != 0 && num1 != 0) {
                if(max(num0, num1) - min(num0, num1) > 0) {
                    max_minority = max(max_minority, min(num0, num1));
                }
            }
        }
        cout << max_minority << "\n";
    }
    
    return 0;
}