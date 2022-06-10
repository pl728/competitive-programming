package cses.dp;

import java.util.Scanner;


public class DiceCombinations {
    static int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] dp = new long[n + 1];
        if (n == 0) {
            System.out.println(1);
            return;
        }

        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 7; j++) {
                if (i - j >= 0) {
                    dp[i] += dp[i - j] % MOD;
                }
            }

            dp[i] %= MOD;
        }

        System.out.println(dp[n]);
    }
}
