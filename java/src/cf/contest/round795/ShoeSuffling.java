package cf.contest.round795;

import java.util.*;

public class ShoeSuffling {
    public static void main(String[] args) {
        // [2, 2, 2, 3, 3]
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        // a, b, c -> b, c, a  or c, a, b or
        // b/c, a/c/, a/b

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int[] s = new int[n];
            for(int j = 0; j < n; j++) {
                s[j] = sc.nextInt();
            }

            Map<Integer, Integer> shoeSizeCounts = new HashMap<>();

            if(n == 1) {
                System.out.println(-1);
                continue;
            }

            if(s[n-1] != s[n-2]) {
                System.out.println(-1);
                continue;
            } else {
                for(int j = 0; j < n; j++) {
                    shoeSizeCounts.putIfAbsent(s[j], 0);
                    shoeSizeCounts.put(s[j], shoeSizeCounts.get(s[j]) + 1);
                }
            }

            // if there are solo shoe size counts, return
            boolean possible = true;
            for(int k : shoeSizeCounts.keySet()){
                if(shoeSizeCounts.get(k) == 1) {
                    possible = false;
                }
            }
            if(!possible) {
                System.out.println(-1);
                continue;
            }

            int storeFirst = 0;
            for(int j = 1; j < n; j++) {
                if(s[j - 1] == s[j]) {
                    System.out.print(j + 1);;
                } else {
                    System.out.print(storeFirst + 1);;
                    storeFirst = j;
                }

                System.out.print(" ");
            }
            System.out.print(storeFirst + 1);

            System.out.println();


        }
    }
}