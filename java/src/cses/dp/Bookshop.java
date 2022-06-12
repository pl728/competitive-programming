package cses.dp;

import java.util.Scanner;

public class Bookshop {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] price = new int[n];
        int[] pages = new int[n];
        for (int _i = 0; _i < n; _i++) {
            price[_i] = sc.nextInt();
        }
        for (int _i = 0; _i < n; _i++) {
            pages[_i] = sc.nextInt();
        }

//        int[][] dp = new int[n + 1][x + 1];
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= x; j++) {
//                dp[i][j] = dp[i-1][j];
//                if (j - price[i - 1] >= 0) {
//                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
//                }
//            }
//        }
//
//        System.out.println(dp[n][x]);

        int[] dp = new int[x + 1];
        for(int i = 1; i <= x; i++) {

            for(int j = 0; j < n; j++) {
                if(j - price[j] >= 0) {
                    dp[i] = Math.max(dp[i], dp[j - price[i - 1]] + pages[i - 1]);
                }
            }
        }
        System.out.println(dp[x]);



    }
}
