package cf.contest.round797;

import java.util.*;

public class E {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int tests = 0; tests < t; tests++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] a = new int[n];
            int[] mod = new int[n];
            List<int[]> list = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                list.add(new int[]{a[i], a[i] % k});
            }

            list.sort(Comparator.comparingInt(o -> o[1]));

            Arrays.sort(a);

            for(int i = 0; i < n; i++) {

            }
        }
    }
}