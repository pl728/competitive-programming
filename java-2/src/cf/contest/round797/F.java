package cf.contest.round797;

import java.util.Arrays;
import java.util.Scanner;

public class F {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int a = 0; a < t; a++) {
            int n = sc.nextInt();
            String s = sc.next();
            int[] p = new int[n];
            long ans = 1;
            for(int i = 0; i < n; i++) {
                p[i] = sc.nextInt() - 1;
            }

            char[] previous = s.toCharArray();
            char[] newString = new char[n];
            for(int i = 0; i < n; i++) {
                newString[i] = previous[p[i]];
            }

            while(!Arrays.equals(s.toCharArray(), newString)) {
                previous = newString.clone();
                for(int i = 0; i < n; i++) {
                    newString[i] = previous[p[i]];
                }

//                System.out.println(Arrays.toString(newString));
                ans++;
            }
            System.out.println(ans);
        }
    }
}