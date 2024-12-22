package cf.contest.round797;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int a = 0; a < t; a++) {
            int n = sc.nextInt();
            int[] h = {3, 2, 1};
            // index: 0 > 1 > 2
            for(int i = 6; i < n; i++) {
                if(h[2] < h[1] - 1) {
                    h[2]++;
                } else if (h[1] < h[0] - 1) {
                    h[1]++;
                } else {
                    h[0]++;
                }
            }

            System.out.println(h[1] + " " + h[0] + " " + h[2]);
        }
    }
}