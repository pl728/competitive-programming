package cf.contest.edu130;

import java.io.IOException;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {
    public static void main(String[] args) throws IOException {
        FastReader fastReader = new FastReader();

        int n = fastReader.nextInt();
        int q = fastReader.nextInt();
        Integer[] p = fastReader.nextIntArrayObject(n);

        // n log n
        Arrays.sort(p);

        // n
        long[] cumulativePrice = new long[p.length];
        cumulativePrice[0] = p[0];
        for (int i = 1; i < p.length; i++) {
            cumulativePrice[i] = cumulativePrice[i - 1] + p[i];
        }

        for (int i = 0; i < q; i++) {
            int x = fastReader.nextInt();
            int y = fastReader.nextInt();
            if (x == n) {
                System.out.println(cumulativePrice[y - 1]);
            } else {
                System.out.println(cumulativePrice[n - x + y - 1] - cumulativePrice[n - x - 1]);
            }
        }

    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            this.br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        // int, long, double, String

        public int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        // int array, long array, double array, string array (primitive and object)

        public int[] nextIntArray(int n) {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public Integer[] nextIntArrayObject(int n) {
            Integer[] result = new Integer[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public long[] nextLongArray(int n) {
            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextLong();
            }
            return result;
        }

        public Long[] nextLongArrayObject(int n) {
            Long[] result = new Long[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextLong();
            }
            return result;
        }

        public double[] nextDoubleArray(int n) {
            double[] result = new double[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextDouble();
            }
            return result;
        }

        public Double[] nextDoubleArrayObject(int n) {
            Double[] result = new Double[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextDouble();
            }
            return result;
        }

        String[] nextLineArray(int n) {
            String line = "";
            try {
                line = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return line.split(" ");
        }
    }
}