package cf.contest.edu130;//package cf.contest;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] a = new int[n];
            int totalEnergy = 0;
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                totalEnergy += a[i];
            }

            if(m < totalEnergy) {
                System.out.println(totalEnergy - m);
            } else {
                System.out.println(0);
            }
        }
    }
}
