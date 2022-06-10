package cf.contest.round797;

import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int a = 0; a < t; a++) {
            int n = sc.nextInt();
            int[] s = new int[n];
            int[] f = new int[n];
            for(int i = 0; i < n; i++) {
                s[i] = sc.nextInt();
            }
            for(int i = 0; i < n; i++) {
                f[i] = sc.nextInt();
            }

            System.out.print(f[0] - s[0] + " ");
            int lastFinish = f[0];
            for(int i = 1; i < n; i++) {
                if(s[i] < lastFinish) {
                    System.out.print(f[i] - lastFinish + " ");
                } else {
                    System.out.print(f[i] - s[i] + " ");
                }

                lastFinish = f[i];
            }

            System.out.println("");
        }
    }
}