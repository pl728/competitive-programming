package cf.contest.round800;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for (int _i = 0; _i < t; _i++) {
            int ans = 0;
            int n = sc.nextInt();
//            int[] numZero = new int[n + 1];
//            int[] numOne = new int[n + 1];
            String s = sc.nextLine();
//            if (s.charAt(0) == '0') {
//                numZero[1] = 1;
//                numOne[1] = 0;
//            } else {
//                numZero[1] = 0;
//                numOne[1] = 1;
//            }
//            for (int i = 1; i < n; i++) {
//                if (s.charAt(i) == '0') {
//                    numZero[i + 1] = numZero[i] + 1;
//                    numOne[i + 1] = numOne[i];
//                } else {
//                    numOne[i + 1] = numOne[i] + 1;
//                    numZero[i + 1] = numZero[i];
//                }
//            }
            ans += n;
//            System.out.println(Arrays.toString(numOne));
//            System.out.println(Arrays.toString(numZero));

            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if(s.substring(i, j).contains("0") && s.substring(i, j).contains("1")) {
                        ans++;
                    }
                }
            }

            System.out.println(ans);
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
