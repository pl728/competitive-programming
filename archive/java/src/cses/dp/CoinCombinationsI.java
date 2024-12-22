package cses.dp;

import java.util.Scanner;

public class CoinCombinationsI {
    // [2, 3, 5] -> 9
    // dp = [1, 0, 1, 1, 1, 2, 2, 4, 5, 8]
    public static void main(String[] args) {
        int m = 1000000007;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] c = new int[n];

        for(int _i = 0; _i < n; _i++) {
            c[_i] = sc.nextInt();
        }

        long[] dp = new long[x + 1];
        dp[0] = 1;
        for(int i = 1; i <= x; i++) {
            dp[i] = 0;
            for(int coin : c) {
                if(i - coin >= 0) {
                    dp[i] += dp[i - coin];
                }

            }
            dp[i] %= m;
        }

        System.out.println(dp[x]);
    }
}
