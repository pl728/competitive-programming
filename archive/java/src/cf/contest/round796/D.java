//package cf.contest.round796;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for(int _i = 0; _i < t; _i++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] a = sc.readIntArray(n);
            if(k < n) {
                // find maximum subarray
                long extra = ((long) k * (k - 1)) / 2;
                System.out.println(maxSubArray(a, k) + extra);
            } else {
                System.out.println(sumArray(a) + n*(long) k - ((long) n * (n + 1) / 2));
            }
        }
    }

    public static long sumArray(int[] a) {
        long sum = 0;
        for(int i = 0; i < a.length; i++) {
            sum += a[i];
        }

        return sum;
    }

    public static long maxSubArray(int[] a, int k) {
        long currentSum = 0;
        int i = 0;
        while(i < k) {
            currentSum += a[i];
            i++;
        }
        long maxSum = currentSum;

        int j = 0;
        while(i < a.length) {
            currentSum -= a[j];
            currentSum += a[i];
            maxSum = Math.max(maxSum, currentSum);
            i++;
            j++;
        }
        return maxSum;
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

        public String[] readStringArrayLine(int n) {
            String line = "";
            try {
                line = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return line.split(" ");
        }

        public String[] readStringArrayLines(int n) {
            String[] result = new String[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.next();
            }
            return result;
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
