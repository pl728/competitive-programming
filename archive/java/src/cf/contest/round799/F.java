package cf.contest.round799;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class F {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for(int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            Integer[] a = sc.readIntArrayObject(n);
            for(int i = 0; i < n; i++) {
                a[i] = getLastDigit(a[i]);
            }
            boolean ans = false;
            Arrays.sort(a);
//            System.out.println(Arrays.toString(a));
            for(int i = 0; i < n - 2 && !ans; i++) {
                ans = twoSum(a, i + 1, (1000000003 - a[i]) % 10);
            }
            if(ans) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    static boolean twoSum(Integer[] a, int start, int target) {
        // find two numbers that add up to some number that ends in target
        int[] dict = new int[10];
        Arrays.fill(dict, -1);
        for(int i = start; i < a.length; i++) {
            if(dict[(100 + target - a[i]) % 10] != -1) {
                return true;
            }
            dict[a[i] % 10] = i;
        }

        return false;
    }

    static boolean endsIn3(long a) {
        String s = String.valueOf(a);
        return s.charAt(s.length() - 1) == '3';
    }

    static int getLastDigit(int a) {
        String s = String.valueOf(a);
        return Integer.parseInt(String.valueOf(s.charAt(s.length() - 1)));
    }

    static class FastReader {
        /**
         * Uses BufferedReader and StringTokenizer for quick java I/O
         * get next int, long, double, string
         * get int, long, double, string arrays, both primitive and wrapped object when array contains all elements
         * on one line, and we know the array size (n)
         * next: gets next space separated item
         * nextLine: returns entire line as space
         */
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            this.br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public String[] readStringArray(int n) {
            String line = "";
            try {
                line = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return line.split(" ");
        }

        // to parse something else:
        // T x = T.parseT(fastReader.next());
        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readIntArray(int n) {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public Integer[] readIntArrayObject(int n) {
            Integer[] result = new Integer[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public char[] readCharArray(int n) {
            return this.nextLine().toCharArray();
        }

    }
}