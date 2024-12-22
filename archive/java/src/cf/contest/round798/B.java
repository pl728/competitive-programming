package cf.contest.round798;

import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            int[] p = new int[n];
            for(int i = 0; i < n; i++) {
                p[i] = sc.nextInt();
            }
            if(n == 1) {
                System.out.println(-1);
                continue;
            }
            int[] mp = new int[n];

            Queue<Integer> queue = new PriorityQueue<>();
            for (int i = 1; i <= n; i++) {
                queue.add(i);
            }

            for (int i = 0; i < n; i++) {
                int next = queue.remove();
                if (i == n - 1) {
                    mp[i] = next;
                } else {
                    if (next == p[i]) {
                        int next2 = queue.remove();
                        queue.add(next);
                        mp[i] = next2;
                    } else {
                        mp[i] = next;
                    }
                }
            }

            if(mp[n-1] == p[n-1]) {
                int temp = mp[n-1];
                mp[n-1] = mp[n-2];
                mp[n-2] = temp;
            }

            for(int i = 0; i < n; i++) {
                System.out.print(mp[i] + " ");
            }
            System.out.println();
        }
    }
}
