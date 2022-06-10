package cf.contest.round798;

import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();
            String a = sc.next();
            String b = sc.next();
            StringBuilder c = new StringBuilder();

            Queue<Character> q1 = new PriorityQueue<>();
            Queue<Character> q2 = new PriorityQueue<>();
            for(int i = 0; i < a.length(); i++) {
                q1.add(a.charAt(i));
            }
            for(int i = 0; i < b.length(); i++) {
                q2.add(b.charAt(i));
            }

            int continuousA = 0;
            int continuousB = 0;

            while(!q1.isEmpty() && !q2.isEmpty()) {
                if(continuousA == k) {
                    c.append(q2.remove());
                    continuousB++;
                    continuousA = 0;
                    continue;
                }

                if(continuousB == k) {
                    c.append(q1.remove());
                    continuousA++;
                    continuousB = 0;
                    continue;
                }

                if(q1.peek() < q2.peek()) {
                    c.append(q1.remove());
                    continuousA++;
                    continuousB = 0;
                } else {
                    c.append(q2.remove());
                    continuousB++;
                    continuousA = 0;
                }
            }

            System.out.println(c);
        }
    }
}
