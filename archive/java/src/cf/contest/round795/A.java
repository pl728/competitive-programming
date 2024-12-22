package cf.contest.round795;

import java.util.*;

public class A {
    public static void main(String[] args) {
        // [2, 2, 2, 3, 3]
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int oddNum = 0;
            for (int j = 0; j < n; j++) {
                a[j] = sc.nextInt() % 2;
                if(a[j] % 2 == 1) {
                    oddNum++;
                }
            }



            System.out.println(Math.min(oddNum, n - oddNum));
        }
    }
}