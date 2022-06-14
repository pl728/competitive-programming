package cf.contest.round799;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class E {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for (int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            int s = sc.nextInt();
            int[] a = sc.readIntArray(n);
            int currentSum = 0;
            for (int num : a) {
                currentSum += num;
            }

            if (currentSum == s) {
                System.out.println(0);
            } else if (currentSum < s) {
                System.out.println(-1);
            } else {
                int ops = 0;
                List<Integer> forward = new ArrayList<>();
                List<Integer> backward = new ArrayList<>();
                int count = 1;
                for (int i = 0; i < n; i++) {
                    if (a[i] == 1) {
                        forward.add(count);
                        count = 1;
                    } else {
                        count++;
                    }
                }

                System.out.println(forward);
            }
        }
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
