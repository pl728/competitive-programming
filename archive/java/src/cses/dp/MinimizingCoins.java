//package cses.dp;

import java.util.Arrays;
import java.util.Scanner;

public class MinimizingCoins {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] c = new int[n];
        for(int a = 0; a < n; a++) {
            c[a] = sc.nextInt();
        }

        System.out.println(f(n, x, c));
    }

    public static long f(int n, int x, int[] coins) {
        long[] dp = new long[x + 1];
        dp[0] = 0;
        for(int i = 1; i <= x; i++) {
            dp[i] = Integer.MAX_VALUE;

            for(int c : coins) {
                if(i - c >= 0) {
                    dp[i] = Math.min(1 + dp[i-c], dp[i]);
                }
            }
        }
        if(dp[x] == Integer.MAX_VALUE) {
            return -1;
        }
        return dp[x];
    }
}
