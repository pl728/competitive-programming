package cses.dp;

import java.util.Arrays;
import java.util.Scanner;

public class GridPaths {
    public static void main(String[] args) {
        int m = 1000000007;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[][] grid = new char[n][n];
        for (int _i = 0; _i < n; _i++) {
            String nextRow = sc.next();
            for (int i = 0; i < n; i++) {
                grid[_i][i] = nextRow.toCharArray()[i];
            }
        }

        int[][] dp = new int[n][n];
        // 00, 10, 01, 02, 11, 20, 03, 12, 21, 30,
        for (int i = 0; i <= 2 * n - 2; i++) {
            for (int j = 0; j <= i; j++) {
                int x = j;
                int y = i - j;
                if (j < n && i - j < n) {
                    if (grid[x][y] == '*') {
                        dp[x][y] = 0;
                    } else if (x == 0 && y == 0) {
                        dp[x][y] = 1;
                    } else {
                        if (x == 0) {
                            dp[x][y] = dp[x][y - 1];
                        } else if (y == 0) {
                            dp[x][y] = dp[x - 1][y];
                        } else {
                            if(dp[x-1][y] != -1) {
                                dp[x][y] += dp[x-1][y] % m;
                            }
                            if(dp[x][y-1] != -1) {
                                dp[x][y] += dp[x][y-1] % m;
                            }

                            dp[x][y] %= m;
                        }
                    }
                }
            }
        }

//        System.out.println(Arrays.deepToString(dp));

        System.out.println(dp[n-1][n-1]);
    }
}
