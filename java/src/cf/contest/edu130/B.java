package cf.contest.edu130;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String nq = br.readLine();
        String[] nqArr = nq.split(" ");
        int n = Integer.parseInt(nqArr[0]);
        int q = Integer.parseInt(nqArr[1]);

        Integer[] p = new Integer[n];
        String prices = br.readLine();
        String[] pricesArray = prices.split(" ");

        // n
        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(pricesArray[i]);
        }

        // n log n
        Arrays.sort(p);

        // n
        long[] cumulativePrice = new long[n];
        cumulativePrice[0] = p[0];
        for (int i = 1; i < n; i++) {
            cumulativePrice[i] = cumulativePrice[i - 1] + p[i];
        }

//        System.out.println(Arrays.toString(p));
//        System.out.println(Arrays.toString(cumulativePrice));

        // q
        for (int i = 0; i < q; i++) {
            String xy = br.readLine();
            String[] xyArray = xy.split(" ");
            int x = Integer.parseInt(xyArray[0]);
            int y = Integer.parseInt(xyArray[1]);
            if (x == n) {
                System.out.println(cumulativePrice[y - 1]);
            } else {
                System.out.println(cumulativePrice[n - x + y - 1] - cumulativePrice[n - x - 1]);
            }
        }

    }
}