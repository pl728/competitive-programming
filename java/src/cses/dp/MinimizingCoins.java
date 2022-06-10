package cses.dp;

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

    public static int f(int n, int x, int[] coins) {
        int[] dp = new int[x + 1];
        dp[0] = 0;
        int minimum = Integer.MAX_VALUE;
        for(int i = 1; i <= x; i++) {
            for(int c : coins) {
                if(i - c >= 0 && dp[i-c] != Integer.MAX_VALUE) {
                    minimum = Math.min(1 + dp[i-c], minimum);
                }
            }
            dp[i] = minimum;
        }
        System.out.println(Arrays.toString(dp));
        if(dp[x] == Integer.MAX_VALUE) {
            return -1;
        }
        return dp[x];
    }
}
