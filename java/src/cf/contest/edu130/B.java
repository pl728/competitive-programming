package cf.contest.edu130;

import cf.FastReader;

import java.io.IOException;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int q = sc.nextInt();
        Integer[] p = sc.nextIntegerArray(n);

        // n log n
        Arrays.sort(p);

        // n
        long[] cumulativePrice = new long[n];
        cumulativePrice[0] = p[0];
        for (int i = 1; i < n; i++) {
            cumulativePrice[i] = cumulativePrice[i - 1] + p[i];
        }

        for (int i = 0; i < q; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (x == n) {
                System.out.println(cumulativePrice[y - 1]);
            } else {
                System.out.println(cumulativePrice[n - x + y - 1] - cumulativePrice[n - x - 1]);
            }
        }

    }
}