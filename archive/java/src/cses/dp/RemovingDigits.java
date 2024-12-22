package cses.dp;

import java.util.Arrays;
import java.util.Scanner;

public class RemovingDigits {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dp = new int[n + 1];
        dp[0] = 0;
        if(n == 0) {
            System.out.println(0);
            return;
        }
        if(n < 10) {
            System.out.println(1);
            return;
        }

        for(int i = 1; i < 10; i++) {
            dp[i] = 1;
        }
        for(int i = 10; i <= n; i++) {
            int[] digits = getDigits(i);
            dp[i] = Integer.MAX_VALUE;
            for(int d : digits) {
                dp[i] = Math.min(dp[i], 1 + dp[i-d]);
            }
        }

        System.out.println(dp[n]);
    }

    public static int[] getDigits(int i) {
        char[] digitsChar = String.valueOf(i).toCharArray();
        int[] digits = new int[digitsChar.length];
        for(int j = 0; j < digitsChar.length; j++) {
            digits[j] = Integer.parseInt(String.valueOf(digitsChar[j]));
        }

        return digits;
    }
}
